#include <iostream>
#include <deque>
#include <bits/stdc++.h>
#include <regex>
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

    void InterptmyMath()
    {

        if(myMathStr[0] == '+' || myMathStr[0] == '-' || myMathStr[0] == '*' ||myMathStr[0] == '/' || myMathStr[0] == '^'
        || myMathStr[myMathStr.length()-1] == '+' || myMathStr[myMathStr.length()-1] == '-' ||
        myMathStr[myMathStr.length()-1] == '*' ||myMathStr[myMathStr.length()-1] == '/' || myMathStr[myMathStr.length()-1] == '^'){
                \
            //Enter name Function
            return;

        }


        int tempPowerIndex=0;
        int tempMUltiIndex=0;
        int tempDivideIndex=0;
        int tempADDIndex=0;
        int tempMinutsIndex=0;


        do{


            if(tempPowerIndex!=0 && string::npos != tempPowerIndex){
                PowerIndecies.push_back(tempPowerIndex);
            }


            if(tempMUltiIndex!=0 && string::npos != tempMUltiIndex){

                MultiplayIndecies.push_back(tempMUltiIndex);
            }

            if(tempDivideIndex!=0 && string::npos != tempDivideIndex){

                DivisionIndecies.push_back(tempDivideIndex);


            }
            if(tempADDIndex!=0 && string::npos != tempADDIndex){

                AdditionIndecies.push_back(tempADDIndex);


            }
            if(tempMinutsIndex!=0 && string::npos != tempMinutsIndex){

                SubstractIndecies.push_back(tempMinutsIndex);


            }



            tempPowerIndex = myMathStr.find('^',tempPowerIndex+1);
            tempMUltiIndex = myMathStr.find('*',tempMUltiIndex+1);
            tempDivideIndex = myMathStr.find('/',tempDivideIndex+1);
            tempADDIndex = myMathStr.find('+',tempADDIndex+1);
            tempMinutsIndex = myMathStr.find('-',tempMinutsIndex+1);





        } while (string::npos != tempPowerIndex || string::npos != tempMUltiIndex || string::npos != tempDivideIndex ||
                string::npos != tempADDIndex || string::npos != tempMinutsIndex );




    }





    void FetchOperatorSides(int mainIndex){
string LHS,RHS;
int arr[5];
        arr[0]= myMathStr.find('^',mainIndex+1);
        arr[1] = myMathStr.find('*',mainIndex+1);
        arr[2]  = myMathStr.find('/',mainIndex+1);
        arr[3]  = myMathStr.find('+',mainIndex+1);
        arr[4] = myMathStr.find('-',mainIndex+1);

            int minIndex=1000000;
            for(int i=1; i<5; i++){
                if(arr[i] !=string ::npos&& arr[i]< minIndex)
                    minIndex = arr[i];

            }

            if (minIndex == 1000000){
                RHS = myMathStr.substr(mainIndex + 1,myMathStr.length()-(mainIndex+1));

            }
            else {

                RHS = myMathStr.substr(mainIndex + 1, minIndex - mainIndex - 1);

            }

        //LHS reversed the array and did the same operations to reduce effort in catching the LHS equation
            string reverseStr =myMathStr;

            for(int i=0; i< reverseStr.length()/2; i++){
                swap(reverseStr[i], reverseStr[reverseStr.length()-i-1]);
            }


        arr[0]= reverseStr.find('^',mainIndex+1);
        arr[1] = reverseStr.find('*',mainIndex+1);
        arr[2]  = reverseStr.find('/',mainIndex+1);
        arr[3]  = reverseStr.find('+',mainIndex+1);
        arr[4] = reverseStr.find('-',mainIndex+1);

        int minIndexLHS=1000000;
        for(int i=1; i<5; i++){
            if(arr[i] !=string ::npos&& arr[i]< minIndexLHS)
                minIndexLHS = arr[i];

        }

    int newMainIndex= reverseStr.length()-mainIndex-1;
        if (minIndexLHS == 1000000){

            LHS = reverseStr.substr(newMainIndex + 1,reverseStr.length()-(newMainIndex+1));
        }
        else {

            LHS = reverseStr.substr(newMainIndex + 1, minIndexLHS - newMainIndex - 1);

        }

        for(int i=0; i<LHS.length()/2; i++){
            swap(LHS[i], LHS[LHS.length()-i-1]);
        }

int leftPos = (minIndexLHS == 1000000) ? minIndexLHS : reverseStr.length()-minIndexLHS-1;

        CalcPortion(LHS,RHS,leftPos,minIndex);

    }



    bool CalcPortion(string LHS, string RHS,int leftPos, int rightPos){
        bool acceptedfourmela  = true;
        double myLHS,myRHS;
        //unfortunately switch statemtns are only available for integers and chars, so yeah get ready for the ultimate:
        // if else if else if else if else if else......
        cout <<LHS<<endl;
        regex cosRegex("cos\\(\\s*\\d+\\s*\\)");




    }

    void MainOperation(){

        myMathStr= "cos(2)^cos(2)*aaa";
        transform(myMathStr.begin(), myMathStr.end(), myMathStr.begin(), ::tolower);
        InterptmyMath();
        //for(int i=0; i<PowerIndecies.size(); i++){
        FetchOperatorSides(PowerIndecies[0]);
        //}

    }

};


#endif //SOLVE_MY_MATH_EXAM_MATHINTERPTER_H
