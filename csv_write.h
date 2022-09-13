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
        int temp;
        string int2str; 
    public:
        void populate_file(string temp, string vessel, vector<string> pat_file, vector<float> pat_num){
            fstream fout;
            newFilename = temp + '_' + vessel;        
            fout.open(newFilename.append(".csv"), ios::out | ios::app); //funny fix to other problem, REMOVE ASAP
            fout << newFilename << ", " << vessel << "\n";
            for(int i = 0; (i < pat_file.size()) &&(i < pat_num.size()); i++){
                fout << pat_file[i] << ", " <<pat_num[i] << "\n";
            }
            cout << "creation of " << newFilename << " was successful" << endl;
        }
    
};

#endif