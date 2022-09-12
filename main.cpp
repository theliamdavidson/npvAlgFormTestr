#include "csv_read.h"
#include "csv_write.h"
#include "cap.h"
using namespace std;

int cont = 1;
char usrRequest(){
    char temp;
    cout << "enter menu options: ";
    cin >> temp;
    return temp;
}

int main(){
    Write w;
    Read r;
    Cap c; // debug / testing purposes. will create fake files & patients for me
    string U_A;
    string username = "RodriguezRay.csv";
    while(cont){
        char option = usrRequest();
        switch(option){
            case('r'):
                //read
                cout << "enter in the name of the patient (lastname first) " << endl;
                //cin >> username; //replace hardcode with username after testing
                r.File_O(username);
                U_A = r.find_data("Upper Aorta");
                cout << U_A << endl;
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