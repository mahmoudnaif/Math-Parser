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
         PowerIndecies.clear();
         MultiplayIndecies.clear();
         DivisionIndecies.clear();
         AdditionIndecies.clear();
         SubstractIndecies.clear();



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

        int newMainIndex= reverseStr.length()-mainIndex-1;
        arr[0]= reverseStr.find('^',newMainIndex+1);
        arr[1] = reverseStr.find('*',newMainIndex+1);
        arr[2]  = reverseStr.find('/',newMainIndex+1);
        arr[3]  = reverseStr.find('+',newMainIndex+1);
        arr[4] = reverseStr.find('-',newMainIndex+1);


        int minIndexLHS=1000000;
        for(int i=1; i<5; i++) {
            if (arr[i] != string::npos && arr[i] < minIndexLHS) {
                minIndexLHS = arr[i];
            }



        }


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


        if(!LHSValid || !RHSValid){

            return false;
        }
        string insertInString;
        switch (typeOfOperation) {
            case Opert::power: {
                   long double output = pow(myLHS, myRHS) ;

                    insertInString = to_string(output);
            }
                break;
            case Opert::multiplication: {
                long double output = myLHS * myRHS ;
                 insertInString = to_string(output);

            }
                break;
            case Opert::division: {
                long double output = myLHS / myRHS ;
                 insertInString = to_string(output);

            }
                break;
            case Opert::addition: {
                long double output = myLHS + myRHS ;
                 insertInString = to_string(output);

            }
                break;
            case Opert::substraction: {
                long double output = myLHS - myRHS ;
                 insertInString = to_string(output);

            }
                break;

            defualt: return false;

        }

        string oldStr=myMathStr;

        if(leftPos==1000000 && rightPos==1000000 ){

            myMathStr= insertInString;

        }
        else if(leftPos==1000000 && rightPos!=1000000){
           string tempStr=insertInString;
            for(int i=rightPos; i<myMathStr.length(); i++ ){
                tempStr+= myMathStr[i];
            }

            myMathStr=tempStr;


        }

        else if(rightPos==1000000 && leftPos!=1000000){

            myMathStr = myMathStr.substr(0,leftPos+1)+insertInString;



        }

        else {
            string firstportion= myMathStr.substr(0,leftPos+1);
            string secondportion=myMathStr.substr(rightPos,myMathStr.length()-rightPos);
            myMathStr = firstportion+ insertInString +secondportion;

        };
        InterptmyMath();









        return true;
    }

    bool checkEquationRegex(string portion, double &output){
        //unfortunately switch statemtns are only available for integers and chars, so yeah get ready for the ultimate:
        // if else if else if else if else if else......
        regex numOnlyRegex("(?:\\d+\\.?\\d*|\\.\\d+)");
        regex sinRegex("sin\\(.*\\)");
        regex cosRegex("cos\\(.*\\)");
        regex tanRegex("tan\\(.*\\)");



        if(regex_match(portion, numOnlyRegex)){
            output = stod(portion);
            return true;
        }

        else if(regex_match(portion, sinRegex)){
            regex sinNum("sin\\(\\s*(?:\\d+(?:\\.\\d+)?\\s*(?:/\\s*\\d+(?:\\.\\d+)?)?|\\d*(?:\\.\\d+)?\\s*/\\s*\\d+(?:\\.\\d+)?)\\s*\\)");
            if(regex_match(portion, sinNum)){
                output = stod(portion.substr(4,portion.length()-5));
                output= sin(output * (M_PI/180));
                return true;
            }
        }

        else if(regex_match(portion, cosRegex)){
            regex cosNum("cos\\(\\s*(?:\\d+(?:\\.\\d+)?\\s*(?:/\\s*\\d+(?:\\.\\d+)?)?|\\d*(?:\\.\\d+)?\\s*/\\s*\\d+(?:\\.\\d+)?)\\s*\\)");
            if(regex_match(portion, cosNum)){
                output = stod(portion.substr(4,portion.length()-5));
                output= cos(output * (M_PI/180));
                return true;
            }
        }

        else if(regex_match(portion, tanRegex)){
            regex tanNum("tan\\(\\s*(?:\\d+(?:\\.\\d+)?\\s*(?:/\\s*\\d+(?:\\.\\d+)?)?|\\d*(?:\\.\\d+)?\\s*/\\s*\\d+(?:\\.\\d+)?)\\s*\\)");
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
    void MainOperation(){

        myMathStr= "cos(3)*cos(2)";
        transform(myMathStr.begin(), myMathStr.end(), myMathStr.begin(), ::tolower);
        InterptmyMath();
        unsigned int powerNum = PowerIndecies.size();
        unsigned int multNum = MultiplayIndecies.size();
        unsigned int divNum = DivisionIndecies.size();
        unsigned int addNum = AdditionIndecies.size();
        unsigned int subNum = SubstractIndecies.size();


        for(int i=0; i<powerNum; i++){
       FetchOperatorSides(PowerIndecies[0], Opert::power);
            InterptmyMath();

        }
        for(int i=0; i<multNum; i++){
            FetchOperatorSides(MultiplayIndecies[0], Opert::multiplication);
            InterptmyMath();
        }

        for(int i=0; i<divNum; i++){
            FetchOperatorSides(DivisionIndecies[0], Opert::division);
            InterptmyMath();
        }
        for(int i=0; i<addNum; i++){
            FetchOperatorSides(AdditionIndecies[0], Opert::addition);
            InterptmyMath();
        }
        for(int i=0; i<subNum; i++){
            FetchOperatorSides(SubstractIndecies[0], Opert::substraction);
            InterptmyMath();
        }
        cout <<myMathStr;
    }

};


#endif //SOLVE_MY_MATH_EXAM_MATHINTERPTER_H
