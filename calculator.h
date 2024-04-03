#pragma once

#include <stack>

struct tip_i_znachenie {
    char type;
    double value;
};

class divide_by_zero_handler {
public:
    static double safe_divide(double numerator, double denominator);
};

class tan_exist {
public:
    static double safe_tan(double x);
};

class ctg_exist {
public:
    static double safe_ctg(double x);
};

class ln_exist {
public:
    static double safe_ln(double x);
};

double Sin(double x);
double Cos(double x);
double factorial(int n);
bool maths(std::stack<tip_i_znachenie>& Stack_numbers, std::stack<tip_i_znachenie>& Stack_operations, tip_i_znachenie& item);
int priority(char ch);
