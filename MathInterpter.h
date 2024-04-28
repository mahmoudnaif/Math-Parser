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


void updateIndecies(string oldStr);


    double MainOperation(double &output);





  void UserUI();

};


#endif //SOLVE_MY_MATH_EXAM_MATHINTERPTER_H
