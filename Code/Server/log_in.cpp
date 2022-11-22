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
  cout << "\t\t\t===================================================\n";
  cout << "\t\t\t||                  WELCOME TO                    ||\n";
  cout << "\t\t\t||                                                ||\n";
  cout << "\t\t\t|| Encrypted and concurrent socket implementation ||\n";
  cout<<  "\t\t\t||    using gaming application (TIC-TAC-TOE GAME  ||\n";
  cout<<  "\t\t\t||          -USING-CLIENT-SERVER-SOCKET)          ||\n";
  cout << "\t\t\t||                                                ||\n";
  cout << "\t\t\t||                    PROJECT                     ||\n";
  cout << "\t\t\t===================================================\n\n\n";

  
  
  
          // declaration of varabiles
     
       string name;
       char gender;
       int age;
       
    //reading user name
    
    cout << "\n Enter User Name  :  ";
    getline (cin,name);


      lable1:
     cout<< "\n Enter User Age :";
     cin>> age;
    if(age >18)
    {
    Logger::Info(__FILE__,__LINE__,"VALID SUCCESSFULLY");
    }
    else
    {
    Logger::Error(__FILE__,__LINE__,"ERROR");
    goto lable1;
    }
    
     //Reading gender from user
       lable2:
     cout << "\n Enter gender (M/m or F/f ): ";
     cin >> gender;
       
	if(gender =='m' || gender=='M' || gender=='f' || gender=='F'){

		Logger::Info(__FILE__,__LINE__,"VALID SUCCESSFULLY");
	}
	else{
		Logger::Error(__FILE__,__LINE__,"ERROR");
		goto lable2;
	}

}
