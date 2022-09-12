#include "csv_read.h"
#include "csv_write.h"

using namespace std;

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
            cout << 'r';
            return(0);
        case('c'):
            //CreateAPatient
            cout << 'c';
            return(1);
        case('w'):
            // write, will propably block funtionality 
            // until patient is confirmed existing
            cout << 'w';
            return(2);
        default:
            cout << "Option does not exist, please try again";
            return(-1);
        
    }
}
int main(){
    int usrChoice = MainMenu(usrRequest());
   
 
}