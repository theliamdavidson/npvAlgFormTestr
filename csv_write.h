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
            for(int i = 0; i < 12; i++){
                if((i%37) == 0){
                    countr++;
                }
                fout << vessel_list[countr] << ", " << result_var_list[i] << ", " <<pat_nums[i] << "\n";
            }
            cout << "creation of " << newFilename << " was successful" << endl;
        }
    
};

#endif