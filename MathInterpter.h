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





    void FetchOperatorSides(int mainIndex, int typeOfOperation){
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

        CalcPortion(LHS,RHS,leftPos,minIndex, typeOfOperation);

    }



    bool CalcPortion(string LHS, string RHS,int leftPos, int rightPos, int typeOfOperation ){
        bool acceptedfourmela  = true;
        double myLHS,myRHS;

      bool LHSValid =  checkEquationRegex(LHS, myLHS);
      bool RHSValid = checkEquationRegex(RHS, myRHS);

        cout << myLHS <<" "<<myRHS<<endl;
        if(!LHSValid || !RHSValid){
            return false;
        }
        switch (typeOfOperation) {
            case Opert::power: {
                   long double output = pow(myLHS, myRHS) ;
                   string insertInString = to_string(output);
            }
                break;
            case Opert::multiplication: {
                long double output = myLHS * myRHS ;
                string insertInString = to_string(output);

            }
                break;
            case Opert::division: {
                long double output = myLHS / myRHS ;
                string insertInString = to_string(output);

            }
                break;
            case Opert::addition: {
                long double output = myLHS + myRHS ;
                string insertInString = to_string(output);

            }
                break;
            case Opert::substraction: {
                long double output = myLHS - myRHS ;
                string insertInString = to_string(output);

            }
                break;
            defualt: return false;

        }



        return true;
    }

    bool checkEquationRegex(string portion, double &output){
        //unfortunately switch statemtns are only available for integers and chars, so yeah get ready for the ultimate:
        // if else if else if else if else if else......
        regex numOnlyRegex("^[0-9]+$");
        regex sinRegex("sin\\(.*\\)");
        regex cosRegex("cos\\(.*\\)");
        regex tanRegex("tan\\(.*\\)");



        if(regex_match(portion, numOnlyRegex)){
            output = stod(portion);
            return true;
        }

        else if(regex_match(portion, sinRegex)){
            regex sinNum("sin\\(\\s*\\d+\\s*\\)");
            if(regex_match(portion, sinNum)){
                output = stod(portion.substr(4,portion.length()-5));
                output= sin(output * (M_PI/180));
                return true;
            }
        }

        else if(regex_match(portion, cosRegex)){
            regex cosNum("cos\\(\\s*\\d+\\s*\\)");
            if(regex_match(portion, cosNum)){
                output = stod(portion.substr(4,portion.length()-5));
                output= cos(output * (M_PI/180));
                return true;
            }
        }

        else if(regex_match(portion, tanRegex)){
            regex tanNum("tan\\(\\s*\\d+\\s*\\)");
            if(regex_match(portion, tanNum)){
                output = stod(portion.substr(4,portion.length()-5));
                output= tan(output * (M_PI/180));
                return true;
            }
        }

        else {
            return false;
        }
        return false;
    }

    void MainOperation(){

        myMathStr= "sin(2)^tan(2)*aaa";
        transform(myMathStr.begin(), myMathStr.end(), myMathStr.begin(), ::tolower);
        InterptmyMath();
        //for(int i=0; i<PowerIndecies.size(); i++){
        FetchOperatorSides(PowerIndecies[0], Opert::power);
        //}

    }

};


#endif //SOLVE_MY_MATH_EXAM_MATHINTERPTER_H
