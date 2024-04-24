#include <iostream>
#include <deque>
#include <bits/stdc++.h>
#include <regex>
#include <cmath>
using namespace std;

#ifndef SOLVE_MY_MATH_EXAM_MATHINTERPTER_H
#define SOLVE_MY_MATH_EXAM_MATHINTERPTER_H


class MathInterpter {
private:
    deque<int> PowerIndecies;
    deque<int> MultiplayIndecies;
    deque<int> DivisionIndecies;
    deque<int> AdditionIndecies;
    deque<int> SubstractIndecies;
    string myMathStr;

public:
    enum Opert{power,multiplication,division,addition,substraction};

    void InterptmyMath();





    bool FetchOperatorSides(int mainIndex, int typeOfOperation);



    bool CalcPortion(string LHS, string RHS,int leftPos, int rightPos, int typeOfOperation );

    bool checkEquationRegex(string portion, double &output);


    /*void updateIndecies(string oldStr){

        if(oldStr.length()<myMathStr.length()){
            long int difference = myMathStr.length()-oldStr.length();

            for(int i=0; i<PowerIndecies.size(); i++){
                PowerIndecies[i]= PowerIndecies[i] + difference;
            }

            for(int i=0; i<MultiplayIndecies.size(); i++){
                MultiplayIndecies[i]= MultiplayIndecies[i] + difference;
            }
            for(int i=0; i<DivisionIndecies.size(); i++){
                DivisionIndecies[i]= DivisionIndecies[i] + difference;
            }
            for(int i=0; i<AdditionIndecies.size(); i++){
                AdditionIndecies[i]= AdditionIndecies[i] + difference;
            }
            for(int i=0; i<SubstractIndecies.size(); i++){
                SubstractIndecies[i]= SubstractIndecies[i] + difference;
            }

        }
        else if(oldStr.length()>myMathStr.length()){
            long int difference = oldStr.length()-myMathStr.length();
            for(int i=0; i<PowerIndecies.size(); i++){
                PowerIndecies[i]= PowerIndecies[i] - difference;
            }

            for(int i=0; i<MultiplayIndecies.size(); i++){
                MultiplayIndecies[i]= MultiplayIndecies[i] - difference;
            }
            for(int i=0; i<DivisionIndecies.size(); i++){
                DivisionIndecies[i]= DivisionIndecies[i] - difference;
            }
            for(int i=0; i<AdditionIndecies.size(); i++){
                AdditionIndecies[i]= AdditionIndecies[i] - difference;
            }
            for(int i=0; i<SubstractIndecies.size(); i++){
                SubstractIndecies[i]= SubstractIndecies[i] - difference;
            }

        }

    }
*/
    double MainOperation(double &output);





  void UserUI();

};


#endif //SOLVE_MY_MATH_EXAM_MATHINTERPTER_H
