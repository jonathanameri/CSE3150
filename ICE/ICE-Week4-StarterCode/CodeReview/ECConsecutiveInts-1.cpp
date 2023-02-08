//
//  ECConsecutiveInts.cpp
//  
//
//  Created by Yufeng Wu on 1/15/23.
//
//

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

// Test whether strInput is a string composed of consecutive and increasing integers (in decimal formats)
// Return true if yes and false otherwise (return false if there are unexpected characters)
// For example, 1234578 would return false, while 1213141516 would return true (12 13 14 15 16)
// You may assume the integers is at most 999999 and there is no any seperators between numbers
// You may also assume integers are all non-negatives

// Tip: try to use library functions instead of writing a lot of code yourself
// functions in C++ string you may find useful:
// substr: extract a substring from a string
// stoi:  convert string to integer (be careful about how to handle exception)
// and so on..

bool ECConsecutiveInts(const string &strInput) {
    int p0 = 0;
    int length = 0;
    int correct_check = 1;

    cout << "String: " << strInput << " length: " << strInput.length() << "\n";

    if (strInput.length() <= 1) {
      return false;
    }

    for (int i = 0; i < strInput.length(); i++) {
      if (not isdigit(strInput[i])) {
        return false;
      }
    }

    int x = 0;

    while (true) {
      correct_check = 1;

      //Find a match
      while (length <= (strInput.length() / 2) + 1) {
        length += 1;
        x = 0;

        int temp = stoi(strInput.substr(p0-x, length));

        string s1 = to_string(temp+1);

        if (temp == 9) {
          int c = 1;
          int n_temp = stoi(strInput.substr(p0-x+c, 1));
          cout << "n_temp " << n_temp << "\n";

          while (n_temp == 9) {
            c += 1;
            n_temp = stoi(strInput.substr(p0-x+c, 1));
          }

          c -= 1;

          if ((length+c) > 6) {
            return false;
          }

          temp = temp = stoi(strInput.substr(p0-x, length+c));
          length += c-1;
        }

        else if (s1.length() > length) {
          length = s1.length();
          x = 1;
        }

        int next = stoi(strInput.substr(p0+length-x, length));
        
        cout << "\nmatching: " << temp << " " << next << " length: " << length << "\n";

        if (next == temp+1 || length > 6) {
          if (length >= (strInput.length() / 2) + 1) {
            return (next == temp+1);
          }

          cout << "true\n";
          break;
        }
      }

      //cout << "\nlength: " << length << "\n";

      if ((length >= (strInput.length() / 2) + 1) || length > 6) {
        cout << "Too long\n";
        break;
      }

      int temp_length = length;
      int n1, n2, t_length = 0;

      //See if this length works
      for (int i = 0; i < strInput.length() - length; i += length) {
        //cout << i << " " << (i+length) << " ";
        n1 = stoi(strInput.substr(i-x, length));
        //x = 0;

        string s2 = to_string(n1+1);

        if (s2.length() > length) {
          length = s2.length();
          x += 1;
        }

        cout << "\n" << n1 << " length: " << length << "\n";

        n2 = stoi(strInput.substr(i+length-x, length));

        cout << "\nChecking: " << n1 << " and " << n2 << " length: " << length << "\n";

        if (n1+1 != n2) {
          correct_check = 0;
          t_length += length;
          break;
        }

        t_length += length;
      }

      length = temp_length;

      if (correct_check == 1) {
        if (t_length+length != strInput.length()) {
          cout << "Not long enough " << t_length << "\n";
          return false;
        }
        cout << "\nend (true)\n";
        return true;
      }

  }

  cout << "\nend (false)\n";
  return false;
}


/*int main() {
  cout << ECConsecutiveInts("99100") << "\n";
  return 0;
}*/
