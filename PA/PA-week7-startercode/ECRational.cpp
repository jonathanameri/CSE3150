//
//  ECRational.cpp
//  
//
//  Created by Yufeng Wu on 1/7/23.
//

#include "ECRational.h"

template<class T>
ECRational<T>::ECRational(const T &numeratorIn, const T &denominatorIn){
    numerator = numeratorIn;
    denominator = denominatorIn;
}

template<class T>
const T &ECRational<T>:: GetNumerator() const{
    return numerator;
}

template<class T>
const T &ECRational<T>:: GetDenominator() const{
    return denominator;
}

template<class T>
ECRational<T>::ECRational(const ECRational &rhs){
    numerator = rhs.GetNumerator();
    denominator = rhs.GetDenominator();
}

template<class T>
ECRational<T> &ECRational<T>::operator=(const ECRational &rhs){
    numerator = rhs.GetNumerator();
    denominator = rhs.GetDenominator();
    return *this;
}

template<class T>
ECRational<T> ECRational<T>::operator+(const ECRational &rhs) const{

    T newDenominator = this->denominator * rhs.denominator;
    T newNumerator = this->numerator*rhs.denominator + rhs.numerator*this->denominator;

    ECRational n(newNumerator, newDenominator);
    return n;
}

template<class T>
ECRational<T> ECRational<T>::operator-(const ECRational &rhs) const{
    T newDenominator = this->denominator * rhs.denominator;
    T newNumerator = this->numerator*rhs.denominator - rhs.numerator*this->denominator;

    ECRational n(newNumerator, newDenominator);
    return n;
}

template<class T>
ECRational<T> ECRational<T>::operator*(const ECRational &rhs) const{
    T newDenominator = this->denominator * rhs.denominator;
    T newNumerator = this->numerator * rhs.numerator;

    ECRational n(newNumerator, newDenominator);
    return n;
}

template<class T>
ECRational<T> ECRational<T>::operator/(const ECRational &rhs) const{
    T newNumerator = this->numerator * rhs.denominator;
    T newDenominator = this->denominator * rhs.numerator;

    ECRational n(newNumerator, newDenominator);
    return n;
}
