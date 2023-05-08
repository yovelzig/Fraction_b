#include <iostream>
#include <algorithm>
#include "Fraction.hpp"
const int MAX_INT = 2147483647;
const int MIN_INT = -2147483648;
using namespace std;
namespace ariel{

     Fraction::Fraction(int num1,int num2){
        if (num2 == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        if(num2 < 0){
            num1 =-num1;
            num2 = -num2;
        }
        // else if (num1 > 0 && num2 < 0)
        // {
        //     num1 *= -1;
        //     num2 *= -1;
        // }
        
        this->numA = num1;
        this->numB = num2;
        this->reduce();
     };  
    Fraction::Fraction(float numa) {
    int curr = static_cast<int>(numa * 1000);
    numA = curr;
    numB = 1000;
    reduce();
}
     Fraction::Fraction(){
        this->numA = 0;
        this->numB = 1;
     };
    int Fraction:: getNumerator()const{
        return this->numA;
    }
    int Fraction:: getDenominator()const{
        return this->numB;
    }
    Fraction Fraction:: operator-(const Fraction& other){
           long long num = static_cast<long long>(this->getNumerator()) * static_cast<long long>(other.numB) -
                        static_cast<long long>(other.numA) * static_cast<long long>(this->getDenominator());
        // check if there is an overflow
        if (num > MAX_INT || num < MIN_INT)
        {
            throw std::overflow_error("number is too large");
        }
        int nom = ((this->numA)*other.numB) - ((this->numB) * other.numA);
        int den = (this->numB)* other.numB;
        return Fraction(nom,den);
        }
        
    //----------------------------------------
    // binary operators
    //----------------------------------------

    Fraction Fraction:: operator+(const Fraction& other){
            long long num = static_cast<long long>(this->getNumerator()) * static_cast<long long>(other.numB) +
                        static_cast<long long>(other.numA) * static_cast<long long>(this->getDenominator());
        // check if there is an overflow
        if (num > MAX_INT || num < MIN_INT)
        {
            throw std::overflow_error("number is too large");
        }
           int nom = ((this->numA)*other.numB) + ((this->numB) * other.numA);
        int den = (this->numB)* other.numB;
        return Fraction(nom,den);
        }
    Fraction Fraction:: operator*(const Fraction& other){
        long long num = static_cast<long long>(this->getNumerator()) * static_cast<long long>(other.numA);
        long long denom = static_cast<long long>(other.numB) * static_cast<long long>(this->getDenominator());
        // check if there is an overflow
        if (num > MAX_INT || num < MIN_INT || denom > MAX_INT || denom < MIN_INT )
        {
            throw std::overflow_error("number is too large");
        }
        int nom = (this->numA)*(other.numA);
        int den = (this->numB)* other.numB;
        return Fraction(nom,den);
        }
    Fraction Fraction:: operator/(const Fraction& other){
        if(other.numA == 0){
            throw std::runtime_error("denominator connot be a zero") ;
        }
        long long num = static_cast<long long>(this->getNumerator()) * static_cast<long long>(other.numB) ;
         long long denom = static_cast<long long>(other.numA) * static_cast<long long>(this->getDenominator());
        // check if there is an overflow
        if (num > MAX_INT || num < MIN_INT || denom > MAX_INT || denom < MIN_INT )
        {
            throw std::overflow_error("number is too large");
        }
        int nom = ((this->numA)*other.numB) ;
        int den = (this->numB)* other.numA;
        return Fraction(nom,den);
        }
    bool Fraction:: operator==(const Fraction& other)const{
        if (this->numA == other.numA && this->numA == 0)
        {
            return true;
        }
        
        if (this->numA != other.numA || this->numB != other.numB)
        {
            return false;
        }      
        return true;
        }    
        // bool Fraction:: operator==(const Fraction& curr,const Fraction& other){
        // if (curr->numA == other.numA && curr->numB == other.numB)
        // {
        //     return true;
        // }      
        // return false;
        // }
    // bool Fraction::operator!=(const Fraction& other){return true;};
    bool Fraction::operator>(const Fraction& other)const{
        int nom = ((this->numA)*other.numB) ;
        int den = (this->numB)* other.numA;
        return nom > den;
        }
    bool Fraction::operator>=(const Fraction& other)const{
        int nom = ((this->numA)*other.numB) ;
        int den = (this->numB)* other.numA;
        return nom >= den;
        }
    bool Fraction::operator<(const Fraction& other)const{
        int nom = ((this->numA)*other.numB) ;
        int den = (this->numB)* other.numA;
        return nom < den;
        }
    bool Fraction::operator<=(const Fraction& other)const{
           int nom = ((this->numA)*other.numB) ;
        int den = (this->numB)* other.numA;
        return nom <= den;
        }
    Fraction& Fraction:: operator++(){
        numA = numA + numB;
        return *this;
        }
    Fraction Fraction:: operator++(int){
        Fraction temp(numA, numB);
        numA += numB;
        reduce();
        return temp;
        }
    Fraction& Fraction:: operator--( ){
        numA = numA - numB;
        return *this;
        }
    Fraction Fraction:: operator--(int){
        Fraction temp(numA, numB);
        numA -= numB;
        reduce();
        return temp;
    }
    //-------------------------------------
    // friend global binary operators
    //-------------------------------------
    Fraction operator- (const Fraction& numa, float numc2){
        int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        int nom = ((numa.numA)*curr.numB) - ((numa.numB) * curr.numA);
        int den = (numa.numB)* curr.numB;
        // Fraction afterOp = numa-curr;
        return Fraction(nom,den);
        }
    Fraction operator- (float numc2,const Fraction& numa){
        int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        Fraction afterOp = curr - numa;
        return afterOp;
        }
    Fraction operator+ (const Fraction& numa, float numc2){
        int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        Fraction afterOp = curr + numa;
        return afterOp;
        }
    Fraction operator+ (float numc2, const Fraction& numa){
        return (numa + numc2);
        }
    Fraction operator* (const Fraction& numa, float numc2){
        int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        Fraction afterOp = curr * numa;
        return afterOp;
        }
    Fraction operator* (float numc2, const Fraction& numa){
        return (numa*numc2);
        }
    Fraction operator/ (const Fraction& numa, float numc2){
        if(numc2 == 0){
            throw std::runtime_error("denominator connot be a zero") ;
        }
        int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        int nom = ((numa.numA)*curr.numB) ;
        int den = (numa.numB)* curr.numA;
        return Fraction(nom,den);
        // Fraction afterOp = numa / curr;
        // return afterOp;
        }
    Fraction operator/ (float numc2,const Fraction& numa){
        if(numa.numA == 0){
            throw std::runtime_error("denominator connot be a zero") ;
        }
         int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        Fraction afterOp = curr / numa;
        return afterOp;
        }
    bool operator==(const Fraction& numa, float numc2){
         int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        return ( curr == numa);
        }
    bool operator==(float numc2, const Fraction& numa){
        return (numa == numc2);
        }
    // bool operator!=(const Fraction& numa, float numc2){return true;};
    // bool operator!=(float numc2, const Fraction& numa){return true;};
    bool operator>(const Fraction& numa, float numc2){
         int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        int nom = ((numa.numA)*curr.numB);
        int den = (numa.numB)* curr.numA;
        return (nom > den);
        }
    bool operator>(float numc2, const Fraction& numa){
        int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        return ( curr > numa);
        }
    bool operator>=(const Fraction& numa, float numc2){
         int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        int nom = ((numa.numA)*curr.numB) ;
        int den = (numa.numB)* curr.numA;
        return (nom >= den);
        }
    bool operator>=(float numc2, const Fraction& numa){
        int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        return ( curr >= numa);
        }
    bool operator<(const Fraction& numa, float numc2){
         int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        int nom = ((numa.numA)*curr.numB) ;
        int den = (numa.numB)* curr.numA;
        return (nom < den);
        }
    bool operator<(float numc2, const Fraction& numa){
        int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        return (curr < numa );
        }
    bool operator<=(const Fraction& numa, float numc2){
        int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        int nom = ((numa.numA)*curr.numB) ;
        int den = (numa.numB)* curr.numA;
        return (nom <= den);
        }
    bool operator<=(float numc2, const Fraction& numa){
        int biggrThen = (int) (numc2*1000);
        Fraction curr(biggrThen,1000);
        return (curr <= numa );
        }
    void Fraction::reduce(){
        int a = this->numA;
        int b = this->numB;
        if (a < 0)
        {
            a = -a;
        }
        if (b < 0)
        {
            b = -b;
        }
        
        if (b < a)
        {
            int temp = b;
            b = a ;
            a = temp;
        }        
      while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    this->numA/=a;
    this->numB/=a;
    }
       // friend Fraction operator+ (const Fraction& c1, const Fraction& c2);
    // friend bool operator==(const Fraction& c1, const Fraction& c2);
    // friend bool operator!=(const Fraction& c1, const Fraction& c2);

   
    //----------------------------------
    // friend global IO operators
    //----------------------------------
    std::ostream& operator<< (std::ostream& osnum, const Fraction& numc){
      return (osnum << numc.getNumerator() << '/' << numc.getDenominator() );
        //return osnum;
    }
    std::istream& operator>> (std::istream& osnum , Fraction& numc){
        int num = 0, denom = 1;
        int sign = 1;
        bool in_num = true;
         // Check for negative sign
        char c = osnum.peek();
        if (c == '-')
        {
            sign = -1;
            osnum.ignore(1);
        } 
        // Read the numerator
        if (!(osnum >> num))
        {
            // Failed to read numerator
            throw std::runtime_error("Failed to read numerator");
        }
        // Read the denominator
        if (!(osnum >> denom))
        {
            // Failed to read denominator
            throw std::runtime_error("Failed to read denominator");
        }

        if (denom == 0)
        {
            // Denominator cannot be zero
            throw std::runtime_error("Denominator cannot be zero");
        }
        if (denom < 0)
        {
            sign = -sign;
            denom = -denom;
        }
        

        numc.numA = (num * sign);
        numc.numB = denom;

        return osnum;
   
      }
}
 