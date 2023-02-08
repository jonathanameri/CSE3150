#include <iostream>
#include <string>
using namespace std;

extern void TrimString(string* x);

int main(){
    string x = "abcdefg";
    TrimString(&x);
    cout <<x << endl;
}