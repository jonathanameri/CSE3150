#include <vector>
#include <map>
#include <iostream>
using namespace std;
#include "LargeImageDoc.cpp"

int main()
{ 
std::map<int,std::string>  listImages;
for(int i=10; i<=1000000; i+= 10)
{
  std::string str= std::to_string(i);
  listImages[i] = str;
}

LargeImageDoc imageDoc(listImages);
// now show document
for(int i=1; i<1000; ++i)
{
  imageDoc.Show(i);
}
}
