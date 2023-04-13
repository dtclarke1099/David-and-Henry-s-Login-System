#include <iostream>
#include <fstream>
using namespace std;



void login();
void registration();
void forgot();



int main() {
    int c; //"c" for choice;
    cout << "             David & Henry's Login Service               ";
    cout << "\n__________________      Menu      _______________________\n";
    cout << " Press 1 to LOGIN              " << endl;
    cout << " Press 2 to REGISTER           " << endl;
    cout << " Press 3 to RESET PASSWORD     " << endl;
    cout << " Press 4 to EXIT               " << endl;
    cout << " Please enter your choice: ";
    cin>>c;
    cout<<endl;



    switch(c)
    {
        case 1:
            login();
            break;



        case 2:
            registration();
            break;



        case 3:
            forgot();
            break;



        case 4:
            cout<<" \nThank you for choosing David and Henry's Login Service\n";
            terminate();



        default:
            system("cls"); //clear screen
            cout<<" \nInvalid Input: Please select from the options suggested above "<<endl;
    }
}
void login() //when the user is already included in the system
{
    int loginAttempt = 0;
    while (loginAttempt < 5) {
        int count;
        string userId, password, id, pass;
        cout << " Please enter the username and password : " << endl;
        cout << " USERNAME ";
        cin >> userId;
        cout << " PASSWORD ";
        cin >> password;



        ifstream input("record.txt"); //ifstream class used to check the file -class - allows you to read the file



        while (input >> id >> pass) {
            if (id == userId && pass == password) {
                count = 1;
                system("cls");
            }
        }
        input.close();
        if (count == 1) {
            cout << userId << "\nYour LOGIN was successful!\n";
            main();
        } else {
            cout << "\nLOGIN FAILED -  Please check your username & password\n";
            loginAttempt++;
        }
    }
    if (loginAttempt == 5) {
        cout << "\nToo many login attempts - Goodbye\n";
        terminate();



    }
}



void registration() //for when you want to add someone to the system
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout<<" \nEnter the username: ";
    cin>>ruserId;
    cout<<" \nEnter the password: ";
    cin>>rpassword;



    ofstream f1("record.txt", ios::app); //ofstream allows us to write in the record.txt file -class - edit
    //ios::app is used to NOT discard contents of the file -
    //allows us to reference this file even after we close the program
    //ios just describes the opneing of a file and the suffix descibes
    //what the action is
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<" \nYour REGISTRATION is successful!\n";
    main();
}



void forgot() //for when you forgot your password
{
    int option;
    system("cls");
    cout<<" Forgot Password?\n";
    cout<<" Press 1 to search ID by Username: \n";
    cout<<" Press 2 to return to main menu: \n";
    cout<<" Enter decision: ";
    cin>>option;
    switch(option)
    {
        case 1:
        {
            int count = 0;
            string suserId, sId, spass;
            cout<<" Enter your username: ";
            cin>>suserId;



            ifstream f2("record.txt");
            while(f2>>sId>>spass)
            {
                if(sId==suserId)
                {
                    count = 1;
                }
            }
            f2.close();
            if(count==1){
                cout<<" Your account is registered! ";
                cout<<" Your password is: "<<spass;
                main();
            }
            else{
                cout<<" Your account is not found";
                main();
            }
            break;
        }
        case 2:
        {
            main();
        }
        default:
            cout<<" Invalid option. Please re-enter choice";
            forgot();
    }
}
}