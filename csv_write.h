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
        void populate_file(string newFilename, vector<string> pat_file){
            fstream fout;        
            fout.open(newFilename, ios::out | ios::app);
            for(int i = 0; i < pat_file.size(); i++){
                fout << "blank for now" << ',' << int2str[0] << int2str[1] <<',' << int2str[2] << int2str[3] << ',' << int2str[4] << int2str[5] <<',' << int2str[6] << int2str[7] << "\n";
            }
            cout << "creation of " << newFilename << " was successful" << endl;
        }
    
};

#endif