#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

#ifndef TESTS_H
#define TESTS_H
class Tests{
    string vessel_name;
    vector<string> varlist = {"PI_1", "PI_2", "VF_1", "VF_2",
            "AR_ratio_1 , AR_ratio_2, AR_ratio_3, AR_ratio_4",
            "Upper_ratio", "High_PI", "Low_PI", "High_VF", "Low_VF",
            "L_ratio_High_PI", "L_ratio_Low_PI", "L_ratio_High_VF", 
            "L_ratio_Low_VF", "High_PI_Deficit", "Low_PI_Deficit", 
            "High_VF_Deficit", "Low_VF_Deficit", "deficit_total", 
            "carotid_1", "carotid_percent", "bvg_hi_pi", "bvg_low_pi",
            "bvg_hi_vf", "bvg_low_vf", "bvg_total", "bvg_percent_total",
            "nvi_post_carotid", "nvi_post_bvg1", "nvi_post_bvg2", 
            "nvi_non", "h_val_low_aor", "swelling_val", "antero_swelling_val"}; 
    vector<string> pat_var;
    int count = 0;
    float PI_1, PI_2, VF_1, VF_2;
    float AR_ratio_1 , AR_ratio_2, AR_ratio_3, AR_ratio_4;
    float Upper_ratio, High_PI, Low_PI, High_VF, Low_VF;
    float L_ratio_High_PI, L_ratio_Low_PI, L_ratio_High_VF, L_ratio_Low_VF;
    float High_PI_Deficit, Low_PI_Deficit, High_VF_Deficit, Low_VF_Deficit;
    float deficit_total, carotid_1, carotid_percent;
    float carotid = 304; // i assume he keeps this visible so he can change it??
    float bvg_hi_pi, bvg_low_pi, bvg_hi_vf, bvg_low_vf, bvg_total, bvg_percent_total;
    float nvi_post_carotid, nvi_post_bvg1, nvi_post_bvg2, nvi_non, h_val_low_aor;
    float swelling_val, antero_swelling_val;
    float nvi_init_val = 125;
    public:
    //as this is just an experiment, lazy code is below
    //will split these up into individual modules 4 each test
        float round(float var){
            // 37.66666 * 100 =3766.66
            // 3766.66 + .5 =3767.16    for rounding off value
            // then type cast to int so value is 3767
            // then divided by 100 so the value converted into 37.67
            float value = (int)(var * 100 + .5);
            return (float)value / 100;
        }
        void converter(string vessel_data){
            stringstream s(vessel_data);
            cout << "decoding U Aorta data" << endl;
            vector<string> test;
            string word;
            while (s >> word){
                test.push_back(word);
            }
            PI_1 = stof(test[1])*2; // i dont think we require the originals
            PI_2 = stof(test[3])*2; // anywhere, but it would be best to keep
            VF_1 = stof(test[2])/25;// this in mind
            VF_2 = stof(test[4])/25;
            vessel_name = test[0];
        }
        void num_crunch(){
            pat_var.push_back(varlist[count] + to_string(PI_1));
            count++;
            pat_var.push_back(varlist[count] + to_string(PI_2));
            count++;
            pat_var.push_back(varlist[count] + to_string(VF_1));
            count++;
            pat_var.push_back(varlist[count] + to_string(VF_2));
            count++;

            AR_ratio_1 = sqrt(PI_1 * VF_1);
            AR_ratio_2 = VF_1 * .25;
            AR_ratio_3 = sqrt(PI_2 * AR_ratio_2);
            AR_ratio_4 = AR_ratio_3 / AR_ratio_2;
            Upper_ratio = (1 - AR_ratio_4) + 1; 

            pat_var.push_back(varlist[count] + to_string(AR_ratio_1));
            count++;
            pat_var.push_back(varlist[count] + to_string(AR_ratio_2));
            count++;
            pat_var.push_back(varlist[count] + to_string(AR_ratio_3));
            count++;
            pat_var.push_back(varlist[count] + to_string(AR_ratio_4));
            count++;
            pat_var.push_back(varlist[count] + to_string(Upper_ratio));
            count++;
            
            // inquire about the order of operations of the upper ratio/sqrt op
            High_PI = sqrt(PI_1 * Upper_ratio/sqrt(PI_1*VF_1*AR_ratio_3*Upper_ratio));
            Low_PI = sqrt(PI_2 * AR_ratio_4/sqrt(PI_1*VF_1*AR_ratio_3*AR_ratio_4));
            High_VF = sqrt(VF_1 * Upper_ratio/sqrt(PI_2*PI_1*AR_ratio_3*AR_ratio_4));
            Low_VF = sqrt(AR_ratio_3 * AR_ratio_4/sqrt(PI_2*PI_1*VF_1*AR_ratio_4));
            
            pat_var.push_back(varlist[count] + to_string(High_PI));
            count++;
            pat_var.push_back(varlist[count] + to_string(Low_PI));
            count++;
            pat_var.push_back(varlist[count] + to_string(High_VF));
            count++;
            pat_var.push_back(varlist[count] + to_string(Low_VF));
            count++;

            L_ratio_High_PI = abs(9-PI_1);
            L_ratio_Low_PI = abs(8-PI_2);
            L_ratio_High_VF = abs(8-VF_1);
            L_ratio_Low_VF = abs(AR_ratio_3-VF_2);

            pat_var.push_back(varlist[count] + to_string(L_ratio_High_PI));
            count++;
            pat_var.push_back(varlist[count] + to_string(L_ratio_Low_PI));
            count++;
            pat_var.push_back(varlist[count] + to_string(L_ratio_High_VF));
            count++;
            pat_var.push_back(varlist[count] + to_string(L_ratio_Low_VF));
            count++;

            High_PI_Deficit = L_ratio_High_PI * 100;
            Low_PI_Deficit = L_ratio_Low_PI * 100;
            High_VF_Deficit = L_ratio_High_VF * 100;
            Low_VF_Deficit = L_ratio_Low_VF * 100;
            deficit_total = High_PI_Deficit + Low_PI_Deficit + High_VF_Deficit + Low_VF_Deficit;

            pat_var.push_back(varlist[count] + to_string(High_PI_Deficit));
            count++;
            pat_var.push_back(varlist[count] + to_string(Low_PI_Deficit));
            count++;
            pat_var.push_back(varlist[count] + to_string(High_VF_Deficit));
            count++;
            pat_var.push_back(varlist[count] + to_string(Low_VF_Deficit));
            count++;
            pat_var.push_back(varlist[count] + to_string(deficit_total));
            count++;

            carotid_1 = abs(300 - carotid);
            carotid_percent = (300 - carotid_1)/300;

            pat_var.push_back(varlist[count] + to_string(carotid_1));
            count++;
            pat_var.push_back(varlist[count] + to_string(carotid_percent));
            count++;

            if(High_PI_Deficit > 99){
                bvg_hi_pi = 100;
            }
            else{
                bvg_hi_pi = High_PI_Deficit;
            }
            if(Low_PI_Deficit > 99){
                bvg_low_pi = 100;
            }
            else{
                bvg_low_pi = Low_PI_Deficit;
            }
            if(High_VF_Deficit > 99){
                bvg_hi_vf = 100;
            }
            else{
                bvg_hi_vf = High_VF_Deficit;
            }
            if(Low_VF_Deficit > 99){
                bvg_low_vf = 100;
            }
            else{
                bvg_low_vf = Low_VF_Deficit;
            }
            
            pat_var.push_back(varlist[count] + to_string(bvg_hi_pi));
            count++;
            pat_var.push_back(varlist[count] + to_string(bvg_low_pi));
            count++;
            pat_var.push_back(varlist[count] + to_string(bvg_hi_vf));
            count++;
            pat_var.push_back(varlist[count] + to_string(bvg_low_vf));
            count++;

            bvg_total = bvg_hi_pi + bvg_low_pi + bvg_hi_vf + bvg_low_vf;
            bvg_percent_total = (400-bvg_total) / 400;

            pat_var.push_back(varlist[count] + to_string(bvg_total));
            count++;
            pat_var.push_back(varlist[count] + to_string(bvg_percent_total));
            count++;

            nvi_post_carotid = nvi_init_val * carotid_percent;
            nvi_post_bvg1 = bvg_percent_total * nvi_post_carotid;
            nvi_post_bvg2 = nvi_post_carotid - nvi_post_bvg1;

            pat_var.push_back(varlist[count] + to_string(nvi_post_carotid));
            count++;
            pat_var.push_back(varlist[count] + to_string(nvi_post_bvg1));
            count++;
            pat_var.push_back(varlist[count] + to_string(nvi_post_bvg2));
            count++;

            nvi_non = deficit_total / 4;
            if(nvi_post_bvg2 > 50){
                h_val_low_aor = nvi_post_bvg2 - 50;
            }
            else{
                h_val_low_aor = 50 - nvi_post_bvg2;
            }

            pat_var.push_back(varlist[count] + to_string(nvi_non));
            count++;
            pat_var.push_back(varlist[count] + to_string(h_val_low_aor));
            count++;

            swelling_val = abs(1200 - (VF_1 * 25));
            antero_swelling_val = swelling_val / 800;

            pat_var.push_back(varlist[count] + to_string(swelling_val));
            count++;
            pat_var.push_back(varlist[count] + to_string(antero_swelling_val));
            count++;

            cout << PI_1 << ' '<< VF_1 << ' ' << PI_2 << ' '<< VF_2 << endl;
            cout << bvg_percent_total << endl;  //this one broke
            cout << round(nvi_post_carotid) << endl;
            
        }
};
#endif