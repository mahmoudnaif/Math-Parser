#include <iostream>
#include <deque>
#include <bits/stdc++.h>
#include <regex>
#include <cmath>
#include <numeric>
using namespace std;

#ifndef SOLVE_MY_MATH_EXAM_MATHINTERPTER_H
#define SOLVE_MY_MATH_EXAM_MATHINTERPTER_H

struct LastAns {
    bool exists;
    double lastans;
};

class MathInterpter {
private:
    deque<int> PowerIndecies;
    deque<int> MultiplayIndecies;
    deque<int> DivisionIndecies;
    deque<int> AdditionIndecies;
    deque<int> SubstractIndecies;
    string myMathStr;
   LastAns last_ans_ = {false,0};
public:
    enum Opert{power,multiplication,division,addition,substraction};

    void InterptmyMath();





    bool FetchOperatorSides(int mainIndex, int typeOfOperation);



    bool CalcPortion(string LHS, string RHS,int leftPos, int rightPos, int typeOfOperation );

    bool checkEquationRegex(string portion, double &output);

    bool returnNum(string portion,double &output);

    void updateIndecies(string oldStr);


    double MainOperation(double &output);




  void TestArea() {

          // Start timepoint
          auto start = std::chrono::high_resolution_clock::now();
            double output;
            myMathStr = "cos(5)+cos(sin(3))- 5 + 5/4 *3*3*1*1/10*9*(4+3)*1*1*1*1*1*10";
            MainOperation(output);
            cout <<output;

          auto end = std::chrono::high_resolution_clock::now();

          std::chrono::duration<double> duration = end - start;


          std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;


  }
  void UserUI();

};


#endif //SOLVE_MY_MATH_EXAM_MATHINTERPTER_H
