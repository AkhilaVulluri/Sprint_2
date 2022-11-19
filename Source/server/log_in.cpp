#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include "Logger.h"
#include "header.h"
using namespace std;

void welcomeScreen ()
{


  cout << "\n\n\n\n";
  cout << "\t\t\t================================================\n";
  cout << "\t\t\t||                  WELCOME TO                ||\n";
  cout << "\t\t\t||                                            ||\n";
  
  cout << "\t\t\t||                                            ||\n";
  cout << "\t\t\t||                    PROJECT                 ||\n";
  cout << "\t\t\t================================================\n\n\n";
  
  
     // declaration of varabiles
     
       string name;
       char gender;
       int age;
       
    //reading user name
    
    cout << "\n Enter User Name  :  ";
    getline (cin,name);

     cout<< "\n Enter User Age :";
     cin>> age;
    if(age >18)
    {
    Logger :: Info("valid age");
    }
    else
    {
    Logger :: Error("invalid input");
    }
    
     //Reading gender from user

     cout << "\n Enter gender (M/m or F/f ): ";
     cin >> gender;
       
	if(gender =='m' || gender=='M' || gender=='f' || gender=='F'){

	    Logger :: Info("Login successful");
	}
	else{
		Logger :: Error("invalid input");
	}

}
