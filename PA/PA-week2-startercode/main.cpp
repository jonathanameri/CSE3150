#include <iostream>
#include <string>
using namespace std;

extern std::string ECLongestPrefix(int numStrings, const std::string arrayStrings[]);
extern bool IsValidPalindrome(const string &strInput);

// void test(string arr[]){
//     string res = ECLongestPrefix(arr->size)
// }

int main(){
    string arr[3] = {"racecar", "racingcar", "racist"};
    // string res = ECLongestPrefix(3, arr);
    bool res = IsValidPalindrome("A man, a plan, a canal  Panama");
    cout << res << endl;
}