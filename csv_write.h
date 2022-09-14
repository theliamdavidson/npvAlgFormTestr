#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;

#ifndef CSV_WRITE_H
#define CSV_WRITE_H
class Write{
    // rewrite imminent 
    // old code from the csv project
    private:
        string newFilename;
        string int2str; 
        int countr = 0;
    public:
        void populate_file(string pat_name, vector<string> vessel_list, vector<string> result_var_list, vector<float> pat_nums){
            fstream fout;
            newFilename = pat_name + "_results.csv";        
            fout.open(newFilename, ios::out | ios::app); 
            fout << newFilename << "\n";
            // rethink
            for(int i = 0; i < vessel_list.size(); i++){
                for(int j = 0; j < result_var_list.size(); j++){
                fout << vessel_list[i] << ',' << result_var_list[j] << ',' << to_string(pat_nums[j]) << "\n";
                }
            }
            cout << "creation of " << newFilename << " was successful" << endl;
        }
    
};

#endif