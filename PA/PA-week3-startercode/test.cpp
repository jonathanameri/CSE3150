#include <iostream>
#include <vector>
#include <string>


using namespace std;
extern void RemoveDupPointers(vector<string *> &arrayPtrs);

int main(){
    string s1 = "abc";
    string s2 = "bcd";
    string s3 = "abc";
    vector<string*> v;
    v.push_back(&s1);
    v.push_back(&s2);
    v.push_back(&s3);
    v.push_back(&s1);
    v.push_back(&s1);
    v.push_back(&s1);

    for(int i = 0; i < v.size(); i ++){
        cout << *v[i] << " ";
    }
    cout << endl;


    RemoveDupPointers(v);

    for(int i = 0; i < v.size(); i ++){
        cout << *v[i] << " ";
    }
    cout << endl;

    return 0;
}