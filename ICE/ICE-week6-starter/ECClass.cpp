#include "ECClass.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Class for class
ECClass ::ECClass()
{
}

void ECClass ::AddStudent(const ECStudent &s)
{
  // your code
  listStu.push_back(s);
}

double ECClass ::GetAveMedian() const
{
  // your code
  vector<double> listScores;
  for (auto x : listStu)
  {
    listScores.push_back(x.GetAve());
  }
  sort(listScores.begin(), listScores.end());
  return listScores[listScores.size() / 2];
}

std::string ECClass ::GetRankedStudentName(int n) const
{
  // your code
  if (listStu.size() <= n)
  {
    return "";
  }

  vector<pair<double, string>> listScores;
  for (auto x : listStu)
  {
    pair<double, string> pp(-1 * x.GetAve(), x.GetName());
    listScores.push_back(pp);
  }
  std::sort(listScores.begin(), listScores.end());
  return listScores[n].second;
}