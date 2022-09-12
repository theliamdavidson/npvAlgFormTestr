#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

#ifndef CSV_READ_H
#define CSV_READ_H
class Read{
    public:
        string line, word;
        vector<vector<string>> content;
        vector<string> row;
        void print_func(){
            for(int i=0;i<content.size();i++){
                for(int j=0;j<content[i].size();j++){
                    cout<<content[i][j]<<" ";
                }
                cout<<"\n";
            }
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
            print_func();
        }        
};
#endif