#include "csv_read.h"
#include "csv_write.h"

using namespace std;

int main(){
    char menuOption;
    cout << "enter menu options: ";
    cin >> menuOption;
    switch(menuOption){
        case('r'):
            //read
            cout << 'r';
            break;
        case('c'):
            //CreateAPatient
            cout << 'c';
            break;
        case('w'):
            // write, will propably block funtionality 
            // until patient is confirmed existing
            cout << 'w';
            break;
        default:
            cout << "Option does not exist, please try again";
            break;
        
    }
}