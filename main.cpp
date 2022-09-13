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
void vessel_caller(){
    string U_A;
    U_A = r.find_data("Upper Aorta");
    cout << U_A << endl;
    t.converter(U_A);
    t.num_crunch();
}

int main(){  
    string username = "RodriguezRay.csv";
    while(cont){
        char option = usrRequest();
        switch(option){
            case('r'):
                //read
                cout << "enter in the name of the patient (lastname first) " << endl;
                //cin >> username; //replace hardcode with username after testing
                r.File_O(username);     
                vessel_caller();
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
                vessel_caller();
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