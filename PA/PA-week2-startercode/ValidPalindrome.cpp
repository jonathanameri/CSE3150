//
//  ValidPalindrome.cpp
//  
//
//  Created by Yufeng Wu on 1/18/21.
//
//

#include <iostream>
#include <cstdio>

using namespace std;

// Function to test if the input string is a valid palindrome
// Note: only consider alphanumeric symbols and ignore cases
bool IsValidPalindrome(const string &strInput)
{
    int n = strInput.size();
    if (n == 0){
        return true;
    }
    int i = 0;
    while(i < n){
        while(!isalnum(strInput[i])){
            i++;
        }
        while(!isalnum(strInput[n-1])){
            n--;
        }
        if (i >= n) break;
        if (tolower(strInput[i]) != tolower(strInput[n-1])) return false;
        i++;
        n--;
    }
    return true;

}

