// Created by Y. Wu, Feb 1, 2023
// You need to implement a function called ECCheckVec, which takes two parameters, (i) a vector of integers, and (ii) an integer maxSz. ECCheckVec would return true if the length of the vector is smaller or equal to maxSz. Otherwise, it returns false. 
// This function is very simple. The key, however, is defining the function properly so that it is efficient. If you didn't define it in an efficient way, you may fail the run-time check!
// Check provided test file: ECCheckVecTest.cpp for example use
// Now define and implement ECCheckVec here...

#include <vector>
using namespace std;

bool ECCheckVec(vector<int> &v, int maxSz)
{
    if (v.size() <= maxSz)
    {
        return true;
    }
    return false;
}