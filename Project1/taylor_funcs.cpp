#include "taylor_funcs.h"
#include <iostream>
#include <math.h>
#include "consts.h"



#define PI 3.14159265358979323846264338327950288419716939937510



DOUBLE tagTaylor::sin(DOUBLE x)
{

    DOUBLE result = 0.0;
    DOUBLE member;
    DOUBLE numerator = x;
    DOUBLE denominator = 1.0;

    for (auto i = 0u;; i++) {

        member = numerator / denominator;
        result += member;

        numerator *= (-1.0) * x*x;
        denominator *= (2.0*i + 2) * (2.0*i + 3.0);

        if (fabs(member) < Eps) {
            return round(result);
        }

    }

}

DOUBLE tagTaylor::cos(DOUBLE x)
{

    DOUBLE result = 0.0;
    DOUBLE member;
    DOUBLE numerator = 1.0;
    DOUBLE denominator = 1.0;

    for (auto i = 1u;; i++) {

        member = numerator / denominator;
        result += member;

        numerator *= (-1.0) * x * x;
        denominator *= (2.0*i) * (2.0*i - 1.0);

        if (fabs(member) < Eps) {
            return round(result);
        }

    }

}

DOUBLE tagTaylor::ln(DOUBLE x)
{

#ifdef TAYLOR_LN_FORM_1

    if (x < 0.0) {
        throw "negative arguement in ln function";
    }
    if (x > 2.0) {
        throw "arguement must be less then 2 (or incorrect calculations using series ln(1+x))";
    }

    // original series made for (1+x) arguement
    x -= 1;

    DOUBLE result = 0.0;
    DOUBLE member;
    DOUBLE numerator = x;
    DOUBLE denominator = 1.0;

    for (auto i = 2u;; i++) {

        member = numerator / denominator;
        result += member;

        numerator *= (-1.0) * x;
        denominator = i;

        if (fabs(member) < Eps) {
            return result;
        }

    }

#endif // TAYLOR_LN_FORM_1
#ifdef TAYLOR_LN_FORM_2

    if (x < 0.0) {
        throw "negative arguement in ln function";
    }
    if (x < 2.76) {
        throw "arguement must be bigger then E (or incorrect calculations using series ln((1+x)/(x-1)))";
    }
    if (x == 1.0) {
        return 0.0;
    }

    // original series made for (1+x)/(1-x) arguement
    x = (x + 1) / (x - 1);

    DOUBLE result = 0;
    DOUBLE member;
    DOUBLE numerator = x;
    DOUBLE denominator = 1;

    for (auto i = 1u; i < MAX_UINT_VALUE ; i++) {

        member = numerator / denominator;
        result += member;

        numerator *= x*x;
        denominator = 2.0*i + 1;

        std::cout << member << "\t" << std::fixed << result*2 << std::endl;

        if (fabs(member) < Eps) {
            return result*2;
        }

    }

#endif // TAYLOR_LN_FORM_2
#ifdef TAYLOR_LN_FORM_3

    if (x < 0.0) {
        throw "negative arguement in ln function";
    }
    if (x == 1.0) {
        return 0.0;
    }

    // original series made for (x)/(x-1) arguement
    x = x / (x - 1);

    DOUBLE result = 0.0;
    DOUBLE member;
    DOUBLE denominator = 1;

    for (auto i = 1u; i < MAX_UINT_VALUE; i++) {

        denominator *= x;

        member = 1.0 / (i * denominator);
        result += member;

        if (fabs(member) < Eps) {
            return round(result);
        }

    }

#endif

}

DOUBLE tagTaylor::sh(DOUBLE x)
{

    DOUBLE result = 0.0;
    DOUBLE member;
    DOUBLE numerator = x;
    DOUBLE denominator = 1.0;

    for (auto i = 1u;; i++) {

        member = numerator / denominator;
        result += member;

        numerator *= x*x;
        denominator *= (2.0*i + 1) * (2.0*i);

        if (fabs(member) < Eps) {
            return round(result);
        }

    }

}

DOUBLE tagTaylor::round(DOUBLE a) {
    return floor(a * extFuncs::degree(10.0, EdigitCount)) / extFuncs::degree(10.0, EdigitCount);
}

INT extFuncs::factorial(INT x) {

    if (x < 0) {
        throw "negative argument in factorial function";
    }

    if (x == 0) {
        return 1;
    }

    return x * factorial(x - 1);
}

DOUBLE extFuncs::degree(DOUBLE x, INT n) {

    if (n < 0) {
        throw "negative degree in degree function";
    }

    DOUBLE result = 1;
    for (auto i = 0; i < n; i++) {
        result *= x;
    }

    return result;
}

DOUBLE extFuncs::degree(INT x, INT n) {

    if (n < 0) {
        throw "negative degree in degree function";
    }

    DOUBLE result = 1;
    for (auto i = 0; i < n; i++) {
        result *= x;
    }

    return result;
}

SHORT extFuncs::negOneDeg(INT n) {
    if (n % 2) {
        return -1;
    }
    return 1;
}

USHORT extFuncs::DigitAfterPoINT(DOUBLE number) {

    DOUBLE fractpart = number - (INT)number;
    USHORT count = 0u;

    while (fractpart - (INT)fractpart != 0.0) {
        fractpart *= 10;
        count++;
    }

    return count;
}

DOUBLE extFuncs::Grad2Rad(DOUBLE phi) {
    return phi * PI / 180.0;
}

tagTaylor::tagTaylor(DOUBLE a) {
    Eps = a;
    EdigitCount = extFuncs::DigitAfterPoINT(Eps);
}


void tagTaylor::setAccuracy(DOUBLE a) {
    Eps = a;
    EdigitCount = extFuncs::DigitAfterPoINT(Eps);
}
Accuracy tagTaylor::getAccuracy() {
    return { Eps, EdigitCount };
}
