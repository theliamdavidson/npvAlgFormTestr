#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

#ifndef CSV_READ_H
#define CSV_READ_H
class Read{
    public:
        string line, word;
        vector<vector<string>> content;
        vector<string> row;
        void print_func(){
            
        }
        string find_data(string vessel){
            string temp;
            int rqlen = vessel.length();
            for(int i=0;i<content.size();i++){
                string tempstr;
                for(int j=0;j<(content[i].size() && rqlen );j++){
                    tempstr.append(content[i][j]);
                }
                if(tempstr == vessel){
                    for(int j=0;j<content[i].size();j++){
                        temp.append(content[i][j] + ",");
                    }
                    return temp;
                }
            }
            return "not found";
        }
        void File_O(string filename){
            fstream file (filename, ios::in);

            if(file.is_open()){
                while(getline(file, line)){
                    //ensure row does not have pre-existing data
                    row.clear();
                    // split input into words
                    stringstream str(line);
                    while(getline(str, word, ','))
                    row.push_back(word);
                    content.push_back(row);
                }       
            }
            else{
                cout<<"Could not open the file\n";
            }
        }        
};
#endif