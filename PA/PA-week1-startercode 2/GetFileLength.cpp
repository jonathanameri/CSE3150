// Usage: ./GetFileLength  <file to calculate length>
// Read a file as given as the first parameter, count the length of the file and output it
// Here, length of a line is the number of characters in the line (i.e., ignoring special characters like newline)
// Length of the file is the sum of the lengths of all lines
// If no file or bad file is provided, just quit
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Your code goes here	
    if (argc != 2){
        cout << "Wrong number of arguments" << endl;
        return -1;
    }
    // open file
    ifstream f(argv[1]);

    if (f.is_open()) {
        int length = 0;
        string curLine;
        while(getline(f, curLine, '\n')){
            length += curLine.length();
        }
        cout << length << endl;
        return 0;
    }
    else{
        cout << "Bad file" << endl;
        return -1;
    }
    // your code here

    // note: when you read from file, if you reach the end of the file, f.eof() will be true
}
