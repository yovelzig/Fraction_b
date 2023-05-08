
#pragma once

/**
 * Header file for the Complex class.
 * 
 * @author Ofir Pele
 * @since 2017
 */


#include <iostream>
namespace ariel{
class Fraction {

private:
    int numA;
    int numB;
    void reduce();

public:

  
     Fraction(int num1,int num2);
     Fraction();
     explicit Fraction(float numa);
    // Logical NOT
    // bool operator!() const {
    //     return _re==0 && _im==0;
    // }
    int getNumerator()const;
    int getDenominator()const;
    Fraction operator-(const Fraction& other);
    //----------------------------------------
    // binary operators
    //----------------------------------------

    Fraction operator+(const Fraction& other);
    Fraction operator*(const Fraction& other);
    Fraction operator/(const Fraction& other);
    bool operator==(const Fraction& other) const;
    // bool operator!=(const Fraction& other);
    bool operator>(const Fraction& other)const;
    bool operator>=(const Fraction& other)const;
    bool operator<(const Fraction& other)const;
    bool operator<=(const Fraction& other)const;
    Fraction &operator++();
    Fraction operator++(int);
    Fraction &operator--( );
    Fraction operator--(int);

    //-------------------------------------
    // friend global binary operators
    //-------------------------------------
    friend Fraction operator- (const Fraction& numa, float numc2);
    friend Fraction operator- (float numc2, const Fraction& numa);    
    friend Fraction operator+ (const Fraction& numa, float numc2);
    friend Fraction operator+ (float numc2,const Fraction& numa);
    friend Fraction operator* (const Fraction& numa, float numc2);
    friend Fraction operator* (float numc2,const Fraction& numa); 
    friend Fraction operator/ (const Fraction& numa, float numc2);
    friend Fraction operator/ (float numc2,const Fraction& numa);
    friend bool operator==(const Fraction& numa, float numc2);
    friend bool operator==(float numc2, const Fraction& numa);
    friend bool operator>(const Fraction& numa, float numc2);
    friend bool operator>(float numc2, const Fraction& numa);
    friend bool operator>=(const Fraction& numa, float numc2);
    friend bool operator>=(float numc2, const Fraction& numa);
    friend bool operator<(const Fraction& numa, float numc2);
    friend bool operator<(float numc2, const Fraction& numa);
    friend bool operator<=(const Fraction& numa, float numc2);
    friend bool operator<=(float numc2, const Fraction& numa);
    friend std::ostream& operator<< (std::ostream& osnum, const Fraction& numc);
    friend std::istream& operator>> (std::istream& osnum , Fraction& numc);
    //-------------------------------------
};
}