#include "taylor_funcs.h"
#include <iostream>

double tagTaylor::sin(DOUBLE x)
{

    DOUBLE result = 0;
    DOUBLE member;
    DOUBLE numerator = x;
    DOUBLE denominator = 1;

    for (auto i = 0;; i++) {

        member = numerator / denominator;
        result += member;

        numerator *= (-1) * x*x;
        denominator *= (2*i + 2) * (2*i + 3);

        if (fabs(member) < Eps) {
            return result;
        }

    }

}

double tagTaylor::cos(DOUBLE x)
{

    DOUBLE result = 0;
    DOUBLE member;
    DOUBLE numerator = 1;
    DOUBLE denominator = 1;

    for (auto i = 1;; i++) {

        member = numerator / denominator;
        result += member;

        numerator *= (-1) * x * x;
        denominator *= (2*i) * (2*i - 1);

        if (fabs(member) < Eps) {
            return result;
        }

    }

}

double tagTaylor::ln(DOUBLE x)
{

    if (x < 0) {
        throw "negative arguement in ln function";
    }

    // original series made for (1+x) arguement
    x -= 1;

    DOUBLE result = 0;
    DOUBLE member;
    DOUBLE numerator = x;
    DOUBLE denominator = 1;

    for (auto i = 2;; i++) {

        member = numerator / denominator;
        result += member;

        //std::cout << "mem: " << member << "\nres:" << result << "\n";

        numerator *= (-1) * x;
        denominator *= i;

        if (fabs(member) < Eps) {
            return result;
        }

    }

}

double tagTaylor::sh(DOUBLE x)
{

    DOUBLE result = 0;
    DOUBLE member;
    DOUBLE numerator = x;
    DOUBLE denominator = 1;

    for (auto i = 1;; i++) {

        member = numerator / denominator;
        result += member;

        numerator *= x * x;
        denominator *= (2 * i + 1) * (2 * i);

        if (fabs(member) < Eps) {
            return result;
        }

    }

}

int extFuncs::factorial(int x) {

    if (x < 0) {
        throw "negative argument in factorial function";
    }

    if (x == 0) {
        return 1;
    }

    return x * factorial(x - 1);
}

double extFuncs::degree(double x, int n) {

    if (n < 0) {
        throw "negative degree in degree function";
    }

    double result = 1;
    for (auto i = 0; i < n; i++) {
        result *= x;
    }

    return result;
}

double extFuncs::degree(int x, int n) {

    if (n < 0) {
        throw "negative degree in degree function";
    }

    double result = 1;
    for (auto i = 0; i < n; i++) {
        result *= x;
    }

    return result;
}

short int extFuncs::negOneDeg(int n) {
    if (n % 2) {
        return -1;
    }
    return 1;
}

tagTaylor::tagTaylor(DOUBLE a) {
    this->Eps = a;
}


void tagTaylor::setAccuracy(DOUBLE a) {
    this->Eps = a;
}
DOUBLE tagTaylor::getAccuracy()
{
    return Eps;
}
