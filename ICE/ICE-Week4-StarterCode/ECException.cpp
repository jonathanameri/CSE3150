#include <string>
#include <iostream>
using namespace std;

void foo(int n){
    if(n<0)
    {
    throw string("NEGATIVE");
    }
    if(n==0)
    {
        throw string("ZERO");
    }
}

string bar (int n){
    try{
       foo(n); 
    }
    catch(string ex){
        return ex;
    }
    return "OK";
}

// int main(){
//     string res = bar(-4);
//     cout <<  res << endl;;
//     return 0;
// }