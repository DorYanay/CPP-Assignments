#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <math.h>
#include <numeric>
#pragma once

namespace ariel
{
};

class Fraction
{
private:
    int denominator;
    int numerator;

public:
    // getters
    int getNumerator() const;
    int getDenominator() const;
    Fraction(int numerator, int denominator);
    Fraction(float);
    Fraction();
    int compareTo(const Fraction &) const;
    void reduce();
    // Fraction with Fraction
    Fraction operator+(const Fraction &other);
    Fraction operator-(const Fraction &other);
    Fraction operator*(const Fraction &other);
    Fraction operator/(const Fraction &other);

    // Fraction with float
    Fraction operator+(float);
    Fraction operator-(float);
    Fraction operator*(float);
    Fraction operator/(float);

    // float with fraction
    friend Fraction operator+(float, const Fraction &other);
    friend Fraction operator-(float, const Fraction &other);
    friend Fraction operator*(float, const Fraction &other);
    friend Fraction operator/(float, const Fraction &other);
    //  Increment Prefix
    Fraction &operator++();
    Fraction &operator--();

    // Increment Postfix
    Fraction operator++(int);
    Fraction operator--(int);
    // Comparators Fractions
    bool operator==(const Fraction &other) const;
    bool operator>(const Fraction &other) const;
    bool operator>=(const Fraction &other) const;
    bool operator<(const Fraction &other) const;
    bool operator<=(const Fraction &other) const;

    // Comparators Float to Fraction.
    friend bool operator==(float, const Fraction &other2);
    friend bool operator>(float, const Fraction &other2);
    friend bool operator>=(float, const Fraction &other2);
    friend bool operator<(float, const Fraction &other2);
    friend bool operator<=(float, const Fraction &other2);

    // Comparators Fraction to Float.
    bool operator==(float);
    bool operator>(float);
    bool operator>=(float);
    bool operator<(float);
    bool operator<=(float);

    // I/O
    friend std::ostream &operator<<(std::ostream &output, const Fraction &frac);
    friend std::istream &operator>>(std::istream &input, Fraction &frac);
};
