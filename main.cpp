#include "csv_read.h"
#include "csv_write.h"
#include "cap.h"
#include "tests.h"
using namespace std;

int cont = 1;
Write w;
Read r;
Tests t;
Cap c; // debug / testing purposes. will create stand-in files for me
char usrRequest(){
    char temp;
    cout << "enter menu options: ";
    cin >> temp;
    return temp;
}
void vessel_caller(string username){
    vector<float> vessel_results;
    vector<float> temp;
        
    for(int count = 0; count < c.create.size(); count++){ //count < 3; count++){//
        //temp.clear();
        temp = t.converter(r.find_data(c.create[count]));
        for(int i = 0; i<temp.size(); i++)
            vessel_results.push_back(temp[i]);
    }    
    cout << "c.create.size " << c.create.size() << endl;
    cout << "vessel_results " << vessel_results.size() << endl;
    cout << "both "<< c.create.size() + vessel_results.size() << endl;
    //          patient name -vessel list         -patient numbers
    w.populate_file(username, c.create, t.varlist, vessel_results);
}   //                                  tests list

int main(){  
    string username = "RodriguezRay";
    cout << "enter in the name of the patient (lastname first) " << endl;
    //cin >> username; //replace hardcode with username after testing
    string temp = username;
    r.File_O(temp.append(".csv"));   
    while(cont){
        char option = usrRequest();
        switch(option){
            case('r'):
                //read
                cout << "enter in the name of the patient (lastname first) " << endl;
                cin >> username; //replace hardcode with username after testing
                r.File_O(username.append(".csv"));     
                break;   
            case('w'):
                // write, will propably block funtionality 
                // until patient is confirmed existing
                cout << 'w'<< endl;
                break;
            case('c'):
                //CreateAPatient
                cout << 'c'<< endl;
                c.populate_file();
                break;
            case('t'):
                cout << 't' <<endl;
                vessel_caller(username);
                break;
            case('x'):
                /*
                char chkr;
                cout << "are you sure? ";
                cin >> chkr;
                if(chkr == 'y'){
                    cout << "exiting";
                    cont = 0;                   
                }
                */
                cont = 0;
                break;
            default:
                cout << "Option does not exist, please try again"<< endl;
                break;
            
        }
    }
   
 
}