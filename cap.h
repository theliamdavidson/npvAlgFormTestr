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
        vector<string> create = {"Right subclavian", "Right Brachial", "Right Proximal Radial",
                                "Right Proximal Ulnar", "Right Distal Radial","Right Distal Ulnar",
                                "Right 1st", "Right 2nd", "Right 3rd", "Right 4th", "Left subclavian",
                                "Left Brachial", "Left Proximal Radial", "Left Proximal Ulnar",
                                "Left Distal radial" , "Left Distal Ulnar", "Left 1st",
                                "Left 2nd", "Left 3rd", "Left 4th", "Right u Sciatic",
                                "Right M Sciatic", "Right L sciatic", "Right Proximal Pero",
                                "Right Inter Pero", "Right Low Pero", "Right Proximal tib",
                                "Right inter tib", "Right low tib", "Right Calc", "Right Med arch",
                                "Right Lat arch", "Right MT cutaneous", "Right 1ST", "Right 2ND",
                                "Right 3RD", "Right 4th", "Left u Sciatic", "Left M Sciatic",
                                "Left L sciatic", "Left Proximal Pero", "Left Inter Pero",
                                "Left Low Pero", "Left Proximal tib", "Left inter tib",
                                "Left low tib", "Left Calc", "Left Med arch", "Left Lat arch",
                                "Left MT cutaneous", "Left 1ST", "Left 2ND", "Left 3RD",
                                "Left 4th", "Right Interm ulnar","Right Interm Radial",
                                "Left Interm Ulnar", "Left Interm Radial", "Left EI",
                                "Lower Aorta", "Upper Aorta", "Right EI", "Intermim Aorta",
                                "Intermed LEI", "Intermed REI", "Lower LEI", "Lower REI"};
        
        int temp;
        string int2str; 
    public:
        vector<string> created_file; 
        void populate_file(){
            string pLName = lname[rand() % 10];
            string pFNAME = fname[rand() % 10];
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