#ifndef _EC_STUDENT_H
#define _EC_STUDENT_H

#include <string>

// Student class
class ECStudent
{
public:
  ECStudent(const std::string &nameIn) {???} 
  double GetMT() const { ??? }
  void SetMT(double s) { ??? }
  double GetFinal() const { ??? }
  void SetFinal(double s) { ??? }
  double GetHW() const { ??? }
  void SetHW(double s) { ??? }
  std::string GetName() const { ??? }
  // ave score: 20% HW, 30% Midterm, 50% Final
  double GetAve() const { ??? }

private:
  // ???
};


#endif
