// Login-Registration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <iomanip>

using namespace std;



bool IsLoggedIn();

int main()
{
    int choice;

    cout << "[ + ] Welcome User!\n[ + ] Let's start by choosing one of the following options: \n\t\t 1. Create Account \n\t\t 2. Log In \n\t\t 3. Exit\n\t\t Choice:"; cin >> choice;

    if (choice == 1)
    {
        string username, password;

        cout << "Select a username: "; cin >> username;
        cout << "Input your password: "; cin >> password;

        ofstream file;
        file.open("data\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        cout << "Account created successfully! Welcome " << username << "!\nGlad to have you as a member!" << endl;
        cout << "You must now log in. Sending you to main page!\n";
        main();
    }
    else if (choice == 2)
    {
        bool status = IsLoggedIn();

        if (!status)
        {
            cout << "Credentials not valid! Please try again!" << endl;
            Sleep(5);
            main();
        }
        else
        {
            cout << "Successful login! Welcome!" << endl;
            system("PAUSE");
            main();
        }
    }
    else if (choice == 3)
    {
        cout << "Thank you! Have a great day!" << endl;
        return 0;
    }
    else
    {
        cout << "Please choose one of the options!\n";
        Sleep(500);
        system("CLS");
        main();
    }

}

bool IsLoggedIn()
{
    string username, password, usernameComparison, passwordComparison;
    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream read("data\\" + username + ".txt");
    getline(read, usernameComparison);
    getline(read, passwordComparison);

    if ((username == usernameComparison) && (password == passwordComparison))
    {
        return true;
    }
    else
    {
        return false;
    }
}


