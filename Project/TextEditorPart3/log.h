#ifndef log_H
#define log_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// #include "Document.h"


using namespace std;


void logxy(string s){
    string filename = "log.txt";
    vector<string> current;
    string line;
    ifstream myfile1 (filename);
    if (myfile1.is_open())
    {

        while ( getline (myfile1,line) )
        {
            current.push_back(line);
        }
        myfile1.close();
    }

    ofstream myfile2;
    myfile2.open (filename);
    for(int i = 0; i < current.size(); i++){
        myfile2 << current[i] << endl;
    }
    myfile2 << s << endl;

    myfile2.close();
}


#endif