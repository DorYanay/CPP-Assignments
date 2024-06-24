#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <math.h>
#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace ariel;
Fraction::Fraction(int num, int deno)
{
    if (num > 0 && deno > 0)
    {
        this->numerator = num;
        this->denominator = deno;
        reduce();
    }
    else if (num > 0 && deno < 0)
    {
        this->numerator = (-1) * num;
        this->denominator = (-1) * deno;
        reduce();
    }
    else if (num > 0 && deno == 0)
    {
        throw std::invalid_argument("denominator cannot be 0");
    }
    else if (num < 0 && deno < 0)
    {
        this->numerator = (-1) * num;
        this->denominator = (-1) * deno;
        reduce();
    }
    else if (num < 0 && deno > 0)
    {
        this->numerator = num;
        this->denominator = deno;
        reduce();
    }
    else if (num < 0 && deno == 0)
    {
        throw std::invalid_argument("denominator cannot be 0");
    }
    else if (num == 0 && deno != 0)
    {
        this->numerator = 0;
        this->denominator = 1;
    }
}
Fraction::Fraction(float flo)
{
    if (flo == 0)
    {
        this->numerator = 0;
        this->denominator = 1;
    }
    this->numerator = (int)(flo * 1000);
    this->denominator = 1000;
    reduce();
}
Fraction::Fraction()
{
    this->numerator = 1;
    this->denominator = 1;
}
int Fraction::getNumerator() const
{
    return this->numerator;
}

int Fraction::getDenominator() const
{
    return this->denominator;
}
int Fraction::compareTo(const Fraction &other) const
{

    int lcm1 = std::lcm(denominator, other.denominator);
    int new_num1 = numerator * (lcm1 / denominator);
    int new_num2 = other.numerator * (lcm1 / other.denominator);

    // Compare the numerators of the equivalent fractions
    if (new_num1 > new_num2)
    {
        return 1;
    }
    else if (new_num1 < new_num2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void Fraction::reduce()
{
    int gcdVal = std::gcd(numerator, denominator);
    numerator /= gcdVal;
    denominator /= gcdVal;
}
// Fractions
Fraction Fraction::operator+(const Fraction &other)
{
    long long num1 = (long long)numerator * (long long)other.denominator;
    long long num2 = (long long)other.numerator * (long long)denominator;
    long long deno = (long long)denominator * (long long)other.denominator;

    if ((num1 + num2) > INT_MAX || (num1 + num2) < INT_MIN || deno > INT_MAX || deno < INT_MIN)
    {
        throw std::overflow_error("Overflow error: addition will cause overflow");
    }
    return Fraction((int)(num1 + num2), (int)deno);
}
Fraction Fraction::operator-(const Fraction &other)
{
    long long num1 = (long long)numerator * (long long)other.denominator;
    long long num2 = (long long)other.numerator * (long long)denominator;
    long long deno = (long long)denominator * (long long)other.denominator;

    if ((num1 - num2) > INT_MAX || (num1 - num2) < INT_MIN || deno > INT_MAX || deno < INT_MIN)
    {
        throw std::overflow_error("Overflow error: subtraction will cause overflow");
    }
    return Fraction((int)(num1 - num2), (int)deno);
}
Fraction Fraction::operator*(const Fraction &other)
{
    long long num = (long long)numerator * (long long)other.numerator;
    long long deno = (long long)denominator * (long long)other.denominator;
    if (num > INT_MAX || deno > INT_MAX || num < INT_MIN || deno < INT_MIN)
    {
        throw std::overflow_error("Overflow error: the result of the multiplication will cause overflow");
    }
    return Fraction((int)num, (int)deno);
}
Fraction Fraction::operator/(const Fraction &other)
{
    if (other.numerator == 0)
    {
        throw std::runtime_error("cant divide by zero");
    }

    long long num = (long long)numerator * (long long)other.denominator;
    long long deno = (long long)denominator * (long long)other.numerator;
    if (num > INT_MAX || deno > INT_MAX || num < INT_MIN || deno < INT_MIN)
    {
        throw std::overflow_error("Overflow error: the result of the multiplication will cause overflow");
    }
    return Fraction((int)num, (int)deno);
}
// Fractions and floats
Fraction Fraction::operator+(const float flo)
{
    Fraction frac = Fraction(flo);
    Fraction result = *this + frac;
    return result;
}
Fraction Fraction::operator-(const float flo)
{
    Fraction frac = Fraction(flo);
    Fraction result = *this - frac;
    return result;
}
Fraction Fraction::operator*(const float flo)
{
    Fraction frac = Fraction(flo);
    Fraction result = *this * frac;
    return result;
}
Fraction Fraction::operator/(const float flo)
{
    if (flo == 0)
    {
        throw std::runtime_error("cant divide by zero");
    }
    Fraction frac = Fraction(flo);
    Fraction result = *this / frac;
    return result;
}

// floats and Fractions
Fraction operator+(const float flo, const Fraction &other)
{
    Fraction frac = Fraction(flo);
    Fraction result = frac + other;
    return result;
}
Fraction operator-(const float flo, const Fraction &other)
{
    Fraction frac = Fraction(flo);
    Fraction result = frac - other;
    return result;
}
Fraction operator*(const float flo, const Fraction &other)
{
    Fraction frac = Fraction(flo);
    Fraction result = frac * other;
    return result;
}
Fraction operator/(const float flo, const Fraction &other)
{
    Fraction frac = Fraction(flo);
    if (other.numerator == 0)
    {
        throw std::invalid_argument("cant divide by 0");
    }
    Fraction result = frac / other;
    return result;
}

//  Increment Prefix
Fraction &Fraction::operator++()
{
    this->numerator += this->denominator;
    if (this->numerator > INT_MAX)
    {
        throw std::overflow_error("> INX_MAX");
    }
    return *this;
}
Fraction &Fraction::operator--()
{
    this->numerator -= this->denominator;
    if (this->numerator < INT_MIN)
    {
        throw std::overflow_error("< INT_MIN");
    }
    return *this;
}

// Increment Postfix
Fraction Fraction::operator++(int num)
{
    Fraction temp = *this;
    this->numerator += this->denominator;
    return temp;
}
Fraction Fraction::operator--(int num)
{
    Fraction temp = *this;
    this->numerator -= this->denominator;
    return temp;
}
// Comparators Fractions
bool Fraction::operator==(const Fraction &other) const
{
    // float result1 = (float)(this->numerator) / (float)(this->denominator);
    // float result2 = (float)(other.numerator) / (float)(other.denominator);
    // float reg = roundf(result1 * 1000.0f) / 1000.0f;
    // float oth = roundf(result2 * 1000.0f) / 1000.0f;

    if (compareTo(other) == 0)
    {
        return true;
    }
    // else if (reg == oth)
    // {
    //     return true;
    // }
    return false;
}
bool Fraction::operator>(const Fraction &other) const
{
    // float result1 = (float)(this->numerator) / (float)(this->denominator);
    // float result2 = (float)(other.numerator) / (float)(other.denominator);
    // float reg = roundf(result1 * 1000.0f) / 1000.0f;
    // float oth = roundf(result2 * 1000.0f) / 1000.0f;

    if (compareTo(other) == 1)
    {
        return true;
    }
    // else if (reg > oth)
    // {
    //     return true;
    // }
    return false;
}
bool Fraction::operator>=(const Fraction &other) const
{
    // float result1 = (float)(this->numerator) / (float)(this->denominator);
    // float result2 = (float)(other.numerator) / (float)(other.denominator);
    // float reg = roundf(result1 * 1000.0f) / 1000.0f;
    // float oth = roundf(result2 * 1000.0f) / 1000.0f;
    if (compareTo(other) == 1)
    {
        return true;
    }
    else if (compareTo(other) == 0)
    {
        return true;
    }
    // else if (reg == oth)
    // {
    //     return true;
    // }
    // else if (reg > oth)
    // {
    //     return true;
    // }
    return false;
}
bool Fraction::operator<(const Fraction &other) const
{
    // float result1 = (float)(this->numerator) / (float)(this->denominator);
    // float result2 = (float)(other.numerator) / (float)(other.denominator);
    // float reg = roundf(result1 * 1000.0f) / 1000.0f;
    // float oth = roundf(result2 * 1000.0f) / 1000.0f;
    if (compareTo(other) == -1)
    {
        return true;
    }
    // else if (reg < oth)
    // {
    //     return true;
    // }
    return false;
}
bool Fraction::operator<=(const Fraction &other) const
{
    // float result1 = (float)(this->numerator) / (float)(this->denominator);
    // float result2 = (float)(other.numerator) / (float)(other.denominator);
    // float reg = roundf(result1 * 1000.0f) / 1000.0f;
    // float oth = roundf(result2 * 1000.0f) / 1000.0f;
    if (compareTo(other) == -1)
    {
        return true;
    }
    else if (compareTo(other) == 0)
    {
        return true;
    }
    // else if (reg == oth)
    // {
    //     return true;
    // }
    // else if (reg < oth)
    // {
    //     return true;
    // }
    return false;
}

// Comparators Float to Fraction.
bool operator==(const float flo, const Fraction &other2)
{
    Fraction frac = Fraction(flo);
    if (frac == other2)
    {
        return true;
    }

    return false;
}
bool operator>(const float flo, const Fraction &other2)
{
    Fraction frac = Fraction(flo);
    if (frac > other2)
    {
        return true;
    }

    return false;
}
bool operator>=(const float flo, const Fraction &other2)
{
    Fraction frac = Fraction(flo);
    if (frac >= other2)
    {
        return true;
    }

    return false;
}
bool operator<(const float flo, const Fraction &other2)
{
    Fraction frac = Fraction(flo);
    if (frac < other2)
    {
        return true;
    }

    return false;
}
bool operator<=(const float flo, const Fraction &other2)
{
    Fraction frac = Fraction(flo);
    if (frac <= other2)
    {
        return true;
    }

    return false;
}

// Comparators Fraction to Float.
bool Fraction::operator==(float flo)
{
    Fraction frac = Fraction(flo);
    if (compareTo(frac) == 0)
    {
        return true;
    }
    return false;
}
bool Fraction::operator>(float flo)
{
    Fraction frac = Fraction(flo);
    if (compareTo(frac) == 1)
    {
        return true;
    }
    return false;
}
bool Fraction::operator>=(float flo)
{
    Fraction frac = Fraction(flo);
    if (compareTo(frac) == 0)
    {
        return true;
    }
    else if (compareTo(frac) == 1)
    {
        return true;
    }
    return false;
}
bool Fraction::operator<(float flo)
{
    Fraction frac = Fraction(flo);
    if (compareTo(frac) == -1)
    {
        return true;
    }
    return false;
}
bool Fraction::operator<=(float flo)
{
    Fraction frac = Fraction(flo);
    if (compareTo(frac) == 0)
    {
        return true;
    }
    else if (compareTo(frac) == -1)
    {
        return true;
    }
    return false;
}

// I/O
std::ostream &operator<<(std::ostream &output, const Fraction &c)
{

    output << c.numerator << "/" << c.denominator;
    return output;
}
std::istream &operator>>(std::istream &input, Fraction &c)
{

    int num;
    if (input >> num)
    {

        if (input >> c.denominator)
        {
            if (c.denominator < 0 && num < 0)
            {
                c.denominator = c.denominator * (-1);
                c.numerator = num * (-1);
            }
            else if (num > 0 && c.denominator < 0)
            {
                c.denominator = c.denominator * (-1);
                c.numerator = num * (-1);
            }
            else
            {
                c.numerator = num;
            }
            // Both numerator and denominator have been read
        }
        else
        {
            // Only one number has been read
            throw std::runtime_error("Invalid input: Expected two integers separated by space");
        }
    }
    else
    {
        throw std::runtime_error("Invalid input: Expected a number");
    }

    if (c.denominator == 0)
    {
        throw std::runtime_error("Denominator can't be zero");
    }

    c.reduce();
    return input;
}