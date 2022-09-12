#include "csv_read.h"
#include "csv_write.h"

using namespace std;

int cont = 1;
char usrRequest(){
    char temp;
    cout << "enter menu options: ";
    cin >> temp;
    return temp;
}
int MainMenu(char option){
    switch(option){
        case('r'):
            //read
            cout << 'r' << endl;
            return(0);   
        case('w'):
            // write, will propably block funtionality 
            // until patient is confirmed existing
            cout << 'w'<< endl;
            return(1);
        case('c'):
            //CreateAPatient
            cout << 'c'<< endl;
            return(2);
        case('x'):
            char chkr;
            cout << "are you sure? ";
            cin >> chkr;
            if(chkr == 'y'){
                cout << "exiting";
                cont = 0;
                return 100;
            }
        default:
            cout << "Option does not exist, please try again"<< endl;
            return(-1);
        
    }
}
int main(){
    
    while(cont){
        int usrChoice = MainMenu(usrRequest());
    }
   
 
}