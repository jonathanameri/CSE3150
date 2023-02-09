//
//  RemoveDupPointers.cpp
//  
//
//  Created by Yufeng Wu on 1/18/21.
//
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//
void RemoveDupPointers(vector<string *> &arrayPtrs)
{
    // arrayPtrs: STL vector of pointers to strings
    // remove pointers that are pointed to identical strings in the array
    // Your code goes here...
    vector<string> strings;
    vector<int> needRemove;
    // vector<string *> newVector;
    for(int i = 0; i < arrayPtrs.size(); i++){
        string curString = *arrayPtrs[i];
        // cout<< i << endl;
        if(std::count(strings.begin(),strings.end(), curString)){
            needRemove.push_back(i);
        }
        strings.push_back(curString);
        // newVector.push_back(arrayPtrs[i]);
    }
    // cout << "first loop done" << endl;
    // int removed = 0;
    for(int i = 0; i < needRemove.size(); i++){
        // cout << i << endl;
        arrayPtrs.erase(arrayPtrs.begin()+needRemove[i] - i);

    }
    // arrayPtrs = newVector;
    
}

