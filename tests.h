#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#ifndef TESTS_H
#define TESTS_H
class Tests{
    string test;
    float PI_1, PI_2, VF_1, VF_2;
    float AR_ratio_1 , AR_ratio_2, AR_ratio_3, AR_ratio_4;
    float Upper_ratio, High_PI, Low_PI, High_VF, Low_VF;
    float L_ratio_High_PI, L_ratio_Low_PI, L_ratio_High_VF, L_ratio_Low_VF;
    float High_PI_Deficit, Low_PI_Deficit, High_VF_Deficit, Low_VF_Deficit;
    float true_value, deficit_total;
    public:
        void genTest(string vessel_data){
            stringstream s(vessel_data);
            cout << "decoding U Aorta data" << endl;
            string word;
            while (s >> word){

            }
        }
};
#endif