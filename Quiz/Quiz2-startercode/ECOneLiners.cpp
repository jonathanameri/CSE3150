// implement several simple functions using a SINGLE line of code
// Note: you need to provide function definition

// (1) Take two strings as parameters and return its concatnation
// e.g., ECConcat("ab", "cde") would return a string("abcde")
#include <string>
using namespace std;
string ECConcat(string a, string b){
    return (a + b);
}

// (2) ECConsString(char ch, int num) would return a string with ch repeating num number of times. e.g., ECConsString('a', 3) would return a string("aaa")
string ECConsString(char ch, int num){
    string res;
    for(int i = 0; i < num; i++){
        res += ch;
    }
    return (res);
}


// (3) ECSubstring(const string &str, int pos, int len) would return a string that is a substring of str that starts at pos and length of this substring is len; you may assume the substring of str as specified is long enough. e.g. ECSubstring("abcd", 1, 2) would return string("bc")
string ECSubstring(const string &str, int pos, int len){
    return str.substr(pos,len);
}
