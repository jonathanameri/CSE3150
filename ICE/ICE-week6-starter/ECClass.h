#ifndef _EC_CLASS_H
#define _EC_CLASS_H

#include "ECStudent.h"
#include <vector>
#include <string>

// Class for class
class ECClass
{
public:
  ECClass();
  void AddStudent( const ECStudent &s);
  double GetAveMedian() const;
  // get the n-th ranked student. n=0: top student, n=1: second highest and so on
  // return empty string if student with this rank doesn't exist
  std::string GetRankedStudentName(int n) const;

private:
  std::vector<ECStudent> listStu;
};


#endif

