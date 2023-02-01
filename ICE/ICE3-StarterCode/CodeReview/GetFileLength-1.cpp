#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Your code goes here
    int count = 0;
    // open file
    ifstream f(argv[1]);
    if (f.is_open()) 
    // your code here
    {
        char c;
        while(f.get(c)){
            switch(c){
                case EOF:
                    break;
                case '\n':
                    continue;
                default:
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
    // note: when you read from file, if you reach the end of the file, f.eof() will be true
}

