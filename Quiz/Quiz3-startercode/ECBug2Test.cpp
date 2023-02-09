#include <iostream>
#include <string>
using namespace std;


extern string ECTernary(int x);


int main(){
    string res;
    res = ECTernary(0);
    cout << res <<endl;
    res = ECTernary(1);
    cout << res <<endl;
    res= ECTernary(2);
    cout << res <<endl;
    return 0;
}