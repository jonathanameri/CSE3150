// Code for modeling a university's various units: department, office,
// college, etc

// Generic interface. 

#include <vector>

class ECUnit
{
public:
	virtual double GetBudget() const = 0;
  virtual ~ECUnit() {}
};

// Department
class ECDepartment : public ECUnit
{
public:
	ECDepartment(int b)  : b(b) {}
	double GetBudget() const { return b; }

private:
  double b;
};

// Office
class ECOffice : public ECUnit
{
public:
  ECOffice(int b) : b(b) {}
  double GetBudget() const { return b; }

private:
  double b;
};

// Composite
class ECCompositeUnit : public ECUnit
{
public:
  ECCompositeUnit()  {}
  ~ECCompositeUnit() {
    //do we need to free???
    for (auto x : listUnits){
      delete x;
    }
    
  }
  
  double GetBudget() const 
  { 
    double sum = 0.0;
    for(auto x : listUnits){
      sum += x->GetBudget();
    }
    return sum;
  }
  void AddChild(ECUnit *pUnit)
  {
    listUnits.push_back(pUnit);
  }

private:
  // your code here
  std::vector<ECUnit *> listUnits;
};

