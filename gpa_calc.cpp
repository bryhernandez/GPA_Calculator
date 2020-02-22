#include <iostream>
#include <string>
using namespace std;

  const int SIZE = 12;
  const string GRADES[SIZE] = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"};
  const double GRADEPOINTS[SIZE] = {4.0, 3.67, 3.33, 3.0, 2.67, 2.33, 2.0, 1.67, 1.33, 1, 0.67, 0};
  double getGradePoints(string grade){
    for (int i = 0; i < SIZE; i++) { 
      if(GRADES[i] == grade) 
        return GRADEPOINTS[i]; 
    }
    return 0;
  }

  class GpaCalculator { 
  public:
    GpaCalculator();
    GpaCalculator(int courseCount);
    void addCourse(int credits, string grade);
    int getCourseCount() const { return myCourseCount; }
    double getTotalGradePoints() const; 
    int getTotalCredits() const; 
    double getGpa() const { return getTotalGradePoints()/getTotalCredits(); } 
    ~GpaCalculator();
  private:
    int myCourseCount;
    int myCoursesEntered = 0; 
    int * myCredits;
    double * myGradePoints;
};

GpaCalculator::GpaCalculator(){
  myCourseCount = 0;
}

GpaCalculator::GpaCalculator(int courseCount){
  myCourseCount = courseCount;

  myCredits = new int[myCourseCount];
  myGradePoints = new double[myCourseCount];
}

void GpaCalculator::addCourse(int credits, string grade){
  myCredits[myCoursesEntered] = credits;
  myGradePoints[myCoursesEntered] = getGradePoints(grade);
  ++myCoursesEntered;
}

int GpaCalculator::getTotalCredits() const{
  int sum = 0;

  for(int i = 0; i < myCourseCount; i++)
    sum += myCredits[i];

  return sum;
}

double GpaCalculator::getTotalGradePoints() const{
  double sum = 0;

  for(int i = 0; i < myCourseCount; i++)
    sum += (myGradePoints[i]*myCredits[i]);

  return sum;
}

GpaCalculator::~GpaCalculator(){
  delete [] myCredits;
  delete [] myGradePoints;
}

int main() {
  cout << "Enter number of courses: ";
  int num;
  cin >> num;

  GpaCalculator a(num);

  for(int i = 0; i < num; i++){
    cout << "Enter number of credits for course " << i+1 << ": ";
    int credits;
    cin >> credits;

    cout << "Enter grade for course " << i+1 << ": ";
    string grade;
    cin >> grade;

    cout << endl;

    a.addCourse(credits, grade);
  }
  
  cout << "You earned " << a.getTotalGradePoints() << " grade points over " << a.getTotalCredits() << " credits" << endl;

  cout << "Your GPA is: " << a.getGpa() << endl << endl;

  cout << "Deleting credit dynamic array" << endl
  << "Deleting grade points dynamic array";

  
}
