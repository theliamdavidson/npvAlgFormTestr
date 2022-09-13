#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

#ifndef TESTS_H
#define TESTS_H
class Tests{
    string vessel_name;
    int count;
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
    vector<string> varlist = {"PI_1", "PI_2", "VF_1", "VF_2",
            "AR_ratio_1" , "AR_ratio_2", "AR_ratio_3", "AR_ratio_4",
            "Upper_ratio", "High_PI", "Low_PI", "High_VF", "Low_VF",
            "L_ratio_High_PI", "L_ratio_Low_PI", "L_ratio_High_VF", 
            "L_ratio_Low_VF", "High_PI_Deficit", "Low_PI_Deficit", 
            "High_VF_Deficit", "Low_VF_Deficit", "deficit_total", 
            "carotid_1", "carotid_percent", "bvg_hi_pi", "bvg_low_pi",
            "bvg_hi_vf", "bvg_low_vf", "bvg_total", "bvg_percent_total",
            "nvi_post_carotid", "nvi_post_bvg1", "nvi_post_bvg2", 
            "nvi_non", "h_val_low_aor", "swelling_val", "antero_swelling_val"}; 
    vector<float> resultlist;
    //as this is just an experiment, lazy code is below
    //will split these up into individual modules 4 each test
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
            resultlist.push_back(round(PI_1*100) / 100);     
            resultlist.push_back(round(PI_2*100) / 100);            
            resultlist.push_back(round(VF_1*100) / 100);           
            resultlist.push_back(round(VF_2*100) / 100);            

            AR_ratio_1 = sqrt(PI_1 * VF_1);
            AR_ratio_2 = VF_1 * .25;
            AR_ratio_3 = sqrt(PI_2 * AR_ratio_2);
            AR_ratio_4 = AR_ratio_3 / AR_ratio_1;
            Upper_ratio = (1 - AR_ratio_4) + 1; 

            resultlist.push_back(round(AR_ratio_1*100) / 100);            
            resultlist.push_back(round(AR_ratio_2*100) / 100);            
            resultlist.push_back(round(AR_ratio_3*100) / 100);            
            resultlist.push_back(round(AR_ratio_4*100) / 100);            
            resultlist.push_back(round(Upper_ratio*100) / 100);            
            
            // inquire about the order of operations of the upper ratio/sqrt op
            High_PI = sqrt((PI_1 * Upper_ratio)/sqrt(PI_2*VF_1*AR_ratio_3*Upper_ratio));
            Low_PI = sqrt(PI_2 * AR_ratio_4/sqrt(PI_1*VF_1*AR_ratio_3*AR_ratio_4));
            High_VF = sqrt(VF_1 * Upper_ratio/sqrt(PI_2*PI_1*AR_ratio_3*Upper_ratio));
            Low_VF = sqrt(AR_ratio_3 * AR_ratio_4/sqrt(PI_2*PI_1*VF_1*AR_ratio_4));
            
            resultlist.push_back(round(High_PI*100) / 100);            
            resultlist.push_back(round(Low_PI*100) / 100);  
            resultlist.push_back(round(High_VF*100) / 100);
            resultlist.push_back(round(Low_VF*100) / 100);            

            L_ratio_High_PI = (8-abs(9-PI_1))*High_PI;
            L_ratio_Low_PI = (8-abs(8-PI_2))*Low_PI;
            L_ratio_High_VF = (8-abs(8-VF_1))*High_VF;
            L_ratio_Low_VF = (3-abs(AR_ratio_3-VF_2))*Low_VF;

            resultlist.push_back(round(L_ratio_High_PI*100) / 100);            
            resultlist.push_back(round(L_ratio_Low_PI*100) / 100);            
            resultlist.push_back(round(L_ratio_High_VF*100) / 100);            
            resultlist.push_back(round(L_ratio_Low_VF*100) / 100);            

            High_PI_Deficit =  (100*(8-L_ratio_High_PI))/(L_ratio_High_PI*L_ratio_High_PI);
            Low_PI_Deficit = (100*(3.5-L_ratio_Low_PI))/(L_ratio_Low_PI * L_ratio_Low_PI);
            High_VF_Deficit = (100*(5 - L_ratio_High_VF))/(L_ratio_High_VF * L_ratio_High_VF);
            Low_VF_Deficit = (100*(1 - L_ratio_Low_VF))/(L_ratio_Low_VF * L_ratio_Low_VF);
            deficit_total = High_PI_Deficit + Low_PI_Deficit + High_VF_Deficit + Low_VF_Deficit;

            resultlist.push_back(round(High_PI_Deficit*100) / 100);            
            resultlist.push_back(round(Low_PI_Deficit*100) / 100);            
            resultlist.push_back(round(High_VF_Deficit*100) / 100);            
            resultlist.push_back(round(Low_VF_Deficit*100) / 100);            
            resultlist.push_back(round(deficit_total*100) / 100);
            

            carotid_1 = abs(300 - carotid);
            carotid_percent = (300 - carotid_1)/300;

            resultlist.push_back(round(carotid_1*100) / 100);            
            resultlist.push_back(round(carotid_percent*100) / 100);            

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
            
            resultlist.push_back(round(bvg_hi_pi*100) / 100);            
            resultlist.push_back(round(bvg_low_pi*100) / 100);            
            resultlist.push_back(round(bvg_hi_vf*100) / 100);            
            resultlist.push_back(round(bvg_low_vf*100) / 100);            

            bvg_total = bvg_hi_pi + bvg_low_pi + bvg_hi_vf + bvg_low_vf;
            bvg_percent_total = bvg_total / 400;

            resultlist.push_back(round(bvg_total*100) / 100);            
            resultlist.push_back(round(bvg_percent_total*100) / 100);            

            nvi_post_carotid = nvi_init_val * carotid_percent;
            nvi_post_bvg1 = bvg_percent_total * nvi_post_carotid;
            nvi_post_bvg2 = nvi_post_carotid - nvi_post_bvg1;

            resultlist.push_back(round(nvi_post_carotid*100) / 100);            
            resultlist.push_back(round(nvi_post_bvg1*100) / 100);            
            resultlist.push_back(round(nvi_post_bvg2*100) / 100);            

            nvi_non = deficit_total / 4;
            if(nvi_post_bvg2 > 50){
                h_val_low_aor = nvi_post_bvg2 - 50;
            }
            else{
                h_val_low_aor = 50 - nvi_post_bvg2;
            }

            resultlist.push_back(round(nvi_non*100) / 100);            
            resultlist.push_back(round(h_val_low_aor*100) / 100);            

            swelling_val = abs(1200 - (VF_1 * 25));
            antero_swelling_val = swelling_val / 800;

            resultlist.push_back(round(swelling_val*100) / 100);            
            resultlist.push_back(round(antero_swelling_val*100) / 100);            
        }
};
#endif