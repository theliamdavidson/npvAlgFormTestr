#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
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
    float deficit_total, carotid_1, carotid_percent;
    float carotid = 304; // i assume he keeps this visible so he can change it??
    public:
    //as this is just an experiment, lazy code is below
    //will split these up into individual modules 4 each test
        void converter(string vessel_data){
            stringstream s(vessel_data);
            cout << "decoding U Aorta data" << endl;
            vector<string> test;
            while (s.good()){
                string word;
                getline(s, word, ',');
                test.push_back(word);
            }
            PI_1 = stof(test[1])*2; // i dont think we require the originals
            PI_2 = stof(test[3])*2; // anywhere, but it would be best to keep
            VF_1 = stof(test[2])/25;// this in mind
            VF_2 = stof(test[4])/25;
            
        }
        void num_crunch(){
            AR_ratio_1 = sqrt(PI_1 * VF_1);
            AR_ratio_2 = VF_1 * .25;
            AR_ratio_3 = sqrt(PI_2 * AR_ratio_2);
            AR_ratio_4 = AR_ratio_3 / AR_ratio_2;
            Upper_ratio = (1 - AR_ratio_4) + 1; 
            
            // inquire about the order of operations of the upper ratio/sqrt op
            High_PI = sqrt(PI_1 * Upper_ratio/sqrt(PI_1*VF_1*AR_ratio_3*Upper_ratio));
            Low_PI = sqrt(PI_2 * AR_ratio_4/sqrt(PI_1*VF_1*AR_ratio_3*AR_ratio_4));
            High_VF = sqrt(VF_1 * Upper_ratio/sqrt(PI_2*PI_1*AR_ratio_3*AR_ratio_4));
            Low_VF = sqrt(AR_ratio_3 * AR_ratio_4/sqrt(PI_2*PI_1*VF_1*AR_ratio_4));
           
            L_ratio_High_PI = abs(9-PI_1);
            L_ratio_Low_PI = abs(8-PI_2);
            L_ratio_High_VF = abs(8-VF_1);
            L_ratio_Low_VF = abs(AR_ratio_3-VF_2);

            High_PI_Deficit = L_ratio_High_PI * 100;
            Low_PI_Deficit = L_ratio_Low_PI * 100;
            High_VF_Deficit = L_ratio_High_VF * 100;
            Low_VF_Deficit = L_ratio_Low_VF * 100;
            deficit_total = High_PI_Deficit + Low_PI_Deficit + High_VF_Deficit + Low_VF_Deficit;

            carotid_1 = abs(300 - carotid);
            carotid_percent = (300 - carotid_1)/300;
        }
};
#endif