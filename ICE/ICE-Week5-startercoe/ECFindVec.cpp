#include <vector>
using namespace std;

bool ECFind(const vector<int> &listVecs, int x)
{
  for( auto i : listVecs){
    if (i == x) return true;
  }
  return false;
}

