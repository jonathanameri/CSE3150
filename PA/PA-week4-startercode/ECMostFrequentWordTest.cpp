#include <string>
#include <iostream>
using namespace std;

extern string ECMostFrequentWord(const string &strText);

template<class T>
void ASSERT_EQ(T x, T y)
{
  if( x == y )
  {
    cout << "Test passed: equal: " << x << "  " << y << endl;
  }
  else
  {
    cout << "Test FAILED: equal: " << x << "  " << y << endl;
  }
}

int main()
{
  string text1 = "I have bad dreams that have bad feelings";
  ASSERT_EQ( ECMostFrequentWord(text1), string("bad"));

  string text2 = "how can I find the most frequent word, in an string, how?can I find how!how-string";
  ASSERT_EQ( ECMostFrequentWord(text2), string("how"));
}

