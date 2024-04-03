#include <iostream>
#include <stack>
#include "calculator.h"

int main()
{
    char ch;
    double value;
    bool flag = 1;
    stack<tip_i_znachenie> Stack_numbers;
    stack<tip_i_znachenie> Stack_operations;
    tip_i_znachenie item;
    try
    {
        while (1)
        {
            ch = cin.peek();
            if (ch == '\n')
            {
                break;
            }
            if (ch == ' ')
            {
                cin.ignore();
                continue;
            }
            if (ch == 's' || ch == 'c' || ch == 't' || ch == 'e' || ch == 'l')
            {
                char func[3];
                for (int i = 0; i < 3; i++)
                {
                    ch = cin.peek();
                    func[i] = ch;
                    cin.ignore();
                }
                if (func[0] == 's' && func[1] == 'i' && func[2] == 'n')
                {
                    item.type = 's';
                    item.value = 0;
                    Stack_operations.push(item);
                    continue;
                }
                if (func[0] == 'c' && func[1] == 'o' && func[2] == 's')
                {
                    item.type = 'c';
                    item.value = 0;
                    Stack_operations.push(item);
                    continue;
                }
                if (func[0] == 't' && func[1] == 'a' && func[2] == 'n')
                {
                    item.type = 't';
                    item.value = 0;
                    Stack_operations.push(item);
                    continue;
                }
                if (func[0] == 'c' && func[1] == 't' && func[2] == 'g')
                {
                    item.type = 'g';
                    item.value = 0;
                    Stack_operations.push(item);
                    continue;
                }
                if (func[0] == 'e' && func[1] == 'x' && func[2] == 'p')
                {
                    item.type = 'e';
                    item.value = 0;
                    Stack_operations.push(item);
                    continue;
                }
                if (func[0] == 'l' && func[1] == 'n' && func[2] == 'e')
                {
                    item.type = 'l';
                    item.value = 0;
                    Stack_operations.push(item);
                    continue;
                }
                if (func[0] == 'l' && func[1] == 'o' && func[2] == 'g')
                {
                    item.type = 'L';
                    item.value = 0;
                    Stack_operations.push(item);
                    continue;
                }
            }

            if (ch == 'p') // если прочитано число число пи
            {
                item.type = '0';
                item.value = p;
                Stack_numbers.push(item);
                flag = 0;
                cin.ignore();
                continue;
            }
            if (ch >= '0' && ch <= '9' || ch == '-' && flag == 1) // если прочитано число
            {
                cin >> value;
                item.type = '0';
                item.value = value;
                Stack_numbers.push(item);
                flag = 0;
                continue;
            }
            if (ch == '+' || ch == '-' && flag == 0 || ch == '*' || ch == '/' || ch == '^' || ch == '!') // если прочитана операция
            {
                if (Stack_operations.size() == 0) // если стек с операциями пуст
                {
                    item.type = ch;
                    item.value = 0;
                    Stack_operations.push(item);
                    cin.ignore();
                    continue;
                }
                if (Stack_operations.size() != 0 && priority(ch) > priority(Stack_operations.top().type)) // если стек с операциями НЕ пуст, но приоритет текущ операции выше верхней в стеке с операциями.
                {
                    item.type = ch;
                    item.value = 0;
                    Stack_operations.push(item);
                    cin.ignore();
                    continue;
                }
                if (Stack_operations.size() != 0 && priority(ch) <= priority(Stack_operations.top().type))
                {
                    if (maths(Stack_numbers, Stack_operations, item) == false)
                    {
                        return 0;
                    }
                    continue;
                }
            }
            if (ch == '(')
            {
                flag = 1;
                item.type = ch;
                item.value = 0;
                Stack_operations.push(item);
                cin.ignore();
                continue;
            }
            if (ch == ')')
            {
                while (Stack_operations.top().type != '(')
                {
                    if (maths(Stack_numbers, Stack_operations, item) == false)
                    {
                        return 0;
                    }
                    else
                    {
                        continue;
                    }
                }
                Stack_operations.pop();
                cin.ignore();
                continue;
            }
            else
            {
                throw "неверно введено выражение\n";
            }
        }
        while (Stack_operations.size() != 0)
        {
            if (maths(Stack_numbers, Stack_operations, item) == false)
            {
                return 0;
            }
            else
            {
                continue;
            }
        }
        cout << "Ответ: " << Stack_numbers.top().value << endl;
    }

    catch (const char* message) 
    {
        cout << "Ошибка: " << message << endl;
        return 1;
    }
}
