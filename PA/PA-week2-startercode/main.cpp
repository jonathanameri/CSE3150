#include <iostream>
#include <string>
#include <cstdio>
#include <ctype.h>
using namespace std;



extern std::string ECLongestPrefix(int numStrings, const std::string arrayStrings[]);
extern bool IsValidPalindrome(const string &strInput);

// void test(string arr[]){
//     string res = ECLongestPrefix(arr->size)
// }

int main(){
    string arr[3] = {"racecar", "racingcar", "racist"};
    // string res = ECLongestPrefix(3, arr);
    bool res = IsValidPalindrome(" ");
    // res = isalnum('2');
    cout << res << endl;
}