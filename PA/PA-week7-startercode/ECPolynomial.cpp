//
//  ECPolynomial.cpp
//  
//
//  Created by Yufeng Wu on 9/17/22.
//

#include "ECPolynomial.h"
#include <iostream>
#include <string>
using namespace std;

ECPolynomial::ECPolynomial(const std::vector<double> &listCoeffsIn){
    for (long unsigned int i = 0; i < listCoeffsIn.size(); i++) {
        listCoeffs.push_back(listCoeffsIn[i]);
    }
}
    
    // Copy constructor
ECPolynomial::ECPolynomial(const ECPolynomial &rhs){
    listCoeffs.clear();
    for (long unsigned int i = 0; i < rhs.listCoeffs.size(); i++) {
        listCoeffs.push_back(rhs.listCoeffs[i]);
    }
}


ECPolynomial::ECPolynomial(const int size){
        vector<double> listCoeffs2(size);
        listCoeffs = listCoeffs2;
    }
    
    // Get the degree. Example: if polynomial=1+x+3x^3, degree=3
int ECPolynomial :: GetDegree() const{
    if (listCoeffs.size() == 0) {
        return 0;
    }
    return listCoeffs.size() - 1;
}

double ECPolynomial ::GetCoeff(int i) const{
    if (i < 0 || i >= listCoeffs.size()) {
        return 0;
    }
    return listCoeffs[i];
}

void ECPolynomial ::SetCoeffAt(int i, double val){
    if (i < 0 || i >= listCoeffs.size()) {
        return;
    }
    listCoeffs[i] = val;
}


ECPolynomial ECPolynomial::Scale(double factor){
    ECPolynomial n(*this);
    for (long unsigned int i = 0; i < listCoeffs.size(); i++) {
        n.listCoeffs[i] *= factor;
    }
    return n; 
}

// Add a polynomial to the current polynomial (and return the result). Example: (1+2x) + (2x+3x^2) = 1+4x+3x^2
ECPolynomial ECPolynomial::operator+(const ECPolynomial &rhs) const{
    ECPolynomial n(*this);
    int howFar = min(n.listCoeffs.size(), rhs.listCoeffs.size());
    int k = 0;
    for (long unsigned int i = 0; i < howFar; i++) {
        n.listCoeffs[i] += rhs.listCoeffs[i];
        k++;
    }
    if (n.listCoeffs.size() < rhs.listCoeffs.size()) {
        for (long unsigned int i = k; i < rhs.listCoeffs.size(); i++) {
            n.listCoeffs.push_back(rhs.listCoeffs[i]);
        }
    }
    return n;
}
    
    // Multiply a polynomial by another polynomail and return the result. Example: (1+2x)*(1-x^2) = 1 + 2x - x^2 -2x^3
ECPolynomial ECPolynomial::operator*(const ECPolynomial &rhs) const{
    ECPolynomial n(*this);
    n.listCoeffs.clear();
    // cout<<"here"<<endl;
    int maxDegree = this->GetDegree() + rhs.GetDegree() + 1;
    // cout<<"here2 maxDegree = " << maxDegree <<endl;
    vector<double> arr(maxDegree);
    // cout<<"here3"<<endl;
    for(long unsigned int i = 0; i < maxDegree; i++){
        arr[i] = 0;
    }
    // cout<<"Max degree: "<<maxDegree<<endl;

    //FINISH HERE
    for (int i = 0; i <= this->GetDegree(); i++){
        for(int j = 0; j <= rhs.GetDegree(); j++){
            int degree = i + j;
            arr[degree] += this->listCoeffs[i]*rhs.listCoeffs[j];
        }
    }
    n.listCoeffs = arr;
    return n;
}
    
    // Divide a polynomial by another, and return the quotient (and save the remainder to the passed in parameter called remainder)
    // Example: if we divide x^3-2x^2-4 by x-3, then quotient = x^2+x+3 and remainder is 5
    // For now, assume rhs (denominator) is zero
ECPolynomial ECPolynomial::operator/(const ECPolynomial &rhs) const{
    cout<<"This: ";
    this->Dump();
    cout<<"rhs: ";
    rhs.Dump();

    ECPolynomial n(*this);
    ECPolynomial n2(*this);
    int diviserDeg = rhs.GetDegree();
    int thisDeg = this->GetDegree();
    cout<<"diviserDeg: "<< diviserDeg << " thisDeg: " << thisDeg << endl;

    if(diviserDeg > thisDeg){
        n.listCoeffs.clear();
        // cout<< "dividng by wrong degree result: " << n.listCoeffs.size()<<endl;
        return n;
    }
    
    double newCoeff = this->listCoeffs[thisDeg]/rhs.listCoeffs[diviserDeg];
    cout<<"newCoeff: "<< newCoeff << endl;
    int newDeg = thisDeg - diviserDeg;
    cout<<"newDeg: "<< newDeg << endl;

    n.listCoeffs.clear();
    for(int i = 0; i < newDeg; i++){
        n.listCoeffs.push_back(0);
    }
    n.listCoeffs.push_back(newCoeff);

    cout<<"n: ";
    n.Dump();
    
    n.Scale(-1);

    cout<<"n scaled by -1: ";
    n.Dump();
    ECPolynomial n3 =  (n)*(rhs);
    cout<<"n3: ";
    n3.Dump();

    return n3;


    //initialize quotient vector and dividend polynomial object
    // check for 0
    // divide dividend by divisor by iterating through coeffiecients of divident in reverse order
    // loop through dividend coefficients in reverse

}

    // related operator: remainder
ECPolynomial ECPolynomial::operator%(const ECPolynomial &rhs) const{

}

void ECPolynomial::Dump() const{
    if (listCoeffs.size() == 0) {
        cout << "0" << endl;
        return;
    }
    cout << listCoeffs[0];
    for (int i = 1; i < listCoeffs.size(); i++) {
        int degree = i;
        if (degree == 1){
            if (listCoeffs[i] == 1){
                cout << "+x";
            }
            else if (listCoeffs[i] == -1){
                cout << "-x";
            }
            else if (listCoeffs[i] > 0){
                cout << "+" << listCoeffs[i] << "x";
            }
            else if (listCoeffs[i] < 0){
                cout << listCoeffs[i] << "x";
            }
        }
        else if(listCoeffs[i] > 0){
            if(listCoeffs[i] != 1){
                cout << "+" << listCoeffs[i] << "x^" << i;
            }
            else{
                cout << "+x^" << i;
            }
        }
        else if (listCoeffs[i] < 0){
            if(listCoeffs[i] != -1){
                cout << listCoeffs[i] << "x^" << i;
            }
            else{
                cout << "-x^" << i;
            }
        }
    }
    cout << endl;
}