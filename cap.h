#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>


using namespace std;

#ifndef CAP_H
#define CAP_H
class Cap{

    private:
        vector<string> fname = {"Liam", "Nicole", "Ryan", "Jack", "Robert", "Barbra",  "Alfred", "Ray", "Jane"};
        vector<string> lname = {"Davidson", "Rodriguez", "Smith", "Doe", "Brown", "Johnson", "Gaimon", "Nieves", "Wu"};
        
        int temp;
        string int2str; 
    public:
    vector<string> create = {"Right_subclavian","Right_Brachial", "Right_Proximal_Radial",
                                "Right_Proximal_Ulnar","Right_Distal_Radial","Right_Distal_Ulnar",
                                "Right_1st","Right_2nd","Right_3rd","Right_4th","Left_subclavian",
                                "Left_Brachial","Left_Proximal_Radial","Left_Proximal_Ulnar",
                                "Left_Distal_radial", "Left_Distal_Ulnar","Left_1st",
                                "Left_2nd","Left_3rd","Left_4th","Right_u_Sciatic",
                                "Right_M_Sciatic","Right_L_sciatic","Right_Proximal_Pero",
                                "Right_Inter_Pero", "Right_Low_Pero","Right_Proximal_tib",
                                "Right_inter_tib", "Right_low_tib", "Right_Calc", "Right_Med_arch",
                                "Right_Lat_arch", "Right_MT_cutaneous", "Right_1ST", "Right_2ND",
                                "Right_3RD", "Right_4th", "Left_u_Sciatic", "Left_M_Sciatic",
                                "Left_L_sciatic", "Left_Proximal_Pero", "Left_Inter_Pero",
                                "Left_Low_Pero", "Left_Proximal_tib", "Left_inter_tib",
                                "Left_low_tib", "Left_Calc", "Left_Med_arch", "Left_Lat_arch",
                                "Left_MT_cutaneous", "Left_1ST", "Left_2ND", "Left_3RD",
                                "Left_4th", "Right_Interm_ulnar","Right_Interm_Radial",
                                "Left_Interm_Ulnar", "Left_Interm_Radial", "Left_EI",
                                "Lower_Aorta", "Upper_Aorta", "Right_EI", "Intermim_Aorta",
                                "Intermed_LEI", "Intermed_REI", "Lower_LEI", "Lower_REI"};
        
        vector<string> created_file; 
        void populate_file(){
            string pLName = lname[(rand() % 10)];
            string pFNAME = fname[(rand() % 10)];
            string newFilename = pLName + pFNAME + ".csv";
            created_file.push_back(newFilename);
            fstream fout;        
            fout.open(newFilename, ios::out | ios::app);
            // Anterograde pulsatility index, Anterograde volume flow, Retrograde volume flow, Retrograde pulsatility index
            temp = rand() % 101 + 100;
            int2str = to_string(temp);
            fout << pLName << ',' << pFNAME << ',' << int2str << "\n";
            for(int i = 0; i < 67; i++){
                temp = rand() % 10000000 + 10000000;
                int2str = to_string(temp);
                fout << create[i] << ',' << int2str[0] << int2str[1] <<',' << int2str[2] << int2str[3] << ',' << int2str[4] << int2str[5] <<',' << int2str[6] << int2str[7] << "\n";
            }
            cout << "creation of " << newFilename << " was successful" << endl;
        }
    
};

#endif