#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;

#ifndef CSV_WRITE_H
#define CSV_WRITE_H
class Write{
    private:
        string newFilename;
        vector<string> tosend;
        int countr = 0;
        void print_file(vector<string> to_print, string file_name){
            fstream fout;
            fout.open(file_name, ios::out | ios::app);
            fout << newFilename << "\n";
            for(int i = 0; i < to_print.size(); i++){
                fout << to_print[i] << "\n";
            }
            cout << "creation of " << newFilename << " was successful" << endl;
        }
    public:
        void populate_file(string pat_name, vector<string> vessel_list, vector<string> result_var_list, vector<float> pat_nums, char testype){ 
            switch(testype){
                case('f'):{
                    newFilename = pat_name + "_results.csv";        
                    // loops the vessel list so that it places the exact vessel in the first column, but iterates through the result and numbs
                    for(int i = 0; i < vessel_list.size(); i++){
                        for(int j = 0; j < result_var_list.size(); j++){
                            tosend.push_back(vessel_list[i] + ',' + result_var_list[j] + ',' + to_string(pat_nums[j]));
                        }
                    }
                    break;
                }
                case('b'):{
                    newFilename = pat_name + "_BVG_results.csv";  
                    int vessel_count = 0;      
                    // this format only prints the nvi_post_bvg values
                    // so the vessel count is only delayed by 2
                    for(int j = 0; j < pat_nums.size(); j++){
                        if(((j+1) % 32) == 0){
                            tosend.push_back(vessel_list[vessel_count] + ',' + result_var_list[31] + ',' + to_string(pat_nums[j]));
                            j++;
                            vessel_count++;
                            tosend.push_back(vessel_list[vessel_count] + ',' + result_var_list[32] + ',' + to_string(pat_nums[j]));
                            j++;
                            vessel_count++;
                        }
                        if(vessel_count == vessel_list.size()){
                            break;
                        }
                        
                    }
                    
                    break;
                }
                default:{
                    newFilename = "critical_error.csv";
                    tosend.push_back("unknown failure in file creation");
                    cout << "-1";
                }
            }
            print_file(tosend, newFilename);
        }
    
};

#endif