#include "calculator.h"
#include <cmath>

const double p = acos(-1);

double Sin(double x)
{
    return (round(sin(x) * 100000000) / 100000000);
}

double Cos(double x)
{
    return (round(cos(x) * 100000000) / 100000000);
}

double ctg(double x)
{
    double a = Cos(x);
    double b = Sin(x);
    return (a / b);
}

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}


double divide_by_zero_handler::safe_divide(double numerator, double denominator) {
    // Реализация функции safe_divide()
}

double tan_exist::safe_tan(double x) {
    if (Cos(x) == 0)
    {
        throw "тангенса не существует";
    }
    else
    {
        return Sin(x) / Cos(x);
    }
}

double ctg_exist::safe_ctg(double x) {
    if (Sin(x) == 0)
    {
        throw "котангенса не существует";
    }
    else
    {
        return Cos(x) / Sin(x);
    }
}

double ln_exist::safe_ln(double x) {
    if (x <= 0)
    {
        throw "натурального логарифма не существует";
    }
    else
    {
        return log(x);
    }
}

bool maths(std::stack<tip_i_znachenie>& Stack_numbers, std::stack<tip_i_znachenie>& Stack_operations, tip_i_znachenie& item) 
{
    double a, b, c;
    a = Stack_numbers.top().value;
    Stack_numbers.pop();
    switch (Stack_operations.top().type)
    {
    case '+':
        b = Stack_numbers.top().value;
        Stack_numbers.pop();
        c = a + b;
        item.type = '0';
        item.value = c;
        Stack_numbers.push(item);
        Stack_operations.pop();
        break;

    case '-':
        b = Stack_numbers.top().value;
        Stack_numbers.pop();
        c = b - a;
        item.type = '0';
        item.value = c;
        Stack_numbers.push(item);
        Stack_operations.pop();
        break;

    case '*':
        b = Stack_numbers.top().value;
        Stack_numbers.pop();
        c = a * b;
        item.type = '0';
        item.value = c;
        Stack_numbers.push(item);
        Stack_operations.pop();
        break;

    case '^':
        b = Stack_numbers.top().value;
        Stack_numbers.pop();
        c = pow(b, a);
        item.type = '0';
        item.value = c;
        Stack_numbers.push(item);
        Stack_operations.pop();
        break;

    case '/':
        b = Stack_numbers.top().value;
        Stack_numbers.pop();
        c = divide_by_zero_handler::safe_divide(b, a);
        item.type = '0';
        item.value = c;
        Stack_numbers.push(item);
        Stack_operations.pop();
        break;

    case '!':
        c = factorial(a);
        item.type = '0';
        item.value = c;
        Stack_numbers.push(item);
        Stack_operations.pop();
        break;

    case 's':
        c = Sin(a);
        if (c == -0)
        {
            c = 0;
        }
        item.type = '0';
        item.value = c;
        Stack_numbers.push(item);
        Stack_operations.pop();
        break;

    case 'c':
        c = Cos(a);
        if (c == -0)
        {
            c = 0;
        }
        item.type = '0';
        item.value = c;
        Stack_numbers.push(item);
        Stack_operations.pop();
        break;

    case 't':
        Stack_numbers.top();
        c = tan_exist::safe_tan(a);
        if (c==-0)
        {
            c=0;
        }
        item.type = '0';
        item.value = c;
        Stack_numbers.push(item);
        Stack_operations.pop();
        break;

    case 'g':
        Stack_numbers.top();
        c = ctg_exist::safe_ctg(a);
        item.type = '0';
        item.value = c;
        Stack_numbers.push(item);
        Stack_operations.pop();
        break;

    case 'e':
        c = exp(a);
        item.type = '0';
        item.value = c;
        Stack_numbers.push(item);
        Stack_operations.pop();
        break;

    case 'l':
        Stack_numbers.top();
        c = ln_exist::safe_ln(a);
        item.type = '0';
        item.value = c;
        Stack_numbers.push(item);
        Stack_operations.pop();
        break;

    case 'L':
        b = Stack_numbers.top().value;
        if (a <= 0 || b == 1 || b <= 0)
        {
            throw "логарфима не существует";
        }
        else
        {
            Stack_numbers.pop();
            c = log(a) / log(b);
            item.type = '0';
            item.value = c;
            Stack_numbers.push(item);
            Stack_operations.pop();
            break;
        }
    }
    return true;
}

int priority(char ch) 
{
    if (ch == 's' || ch == 'c' || ch == 't' || ch == 'g' || ch == 'e' || ch == 'l' || ch == 'L')
    {
        return 4;
    }
    if (ch == '^')
    {
        return 3;
    }
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
