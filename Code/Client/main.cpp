//Header Files
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
#include"header.h"
using namespace std;

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

//Function to check the possible winning conditions
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
	{
        return 1;
    }
    else if (square[4] == square[5] && square[5] == square[6])
	{
        return 1;
    }   
    else if (square[7] == square[8] && square[8] == square[9])
    {
        return 1;
    }   
    else if (square[1] == square[4] && square[4] == square[7])
    {
        return 1;
    }   
        
    else if (square[2] == square[5] && square[5] == square[8])
    {
        return 1;
    }   
        
    else if (square[3] == square[6] && square[6] == square[9])
    {
        return 1;
    }   
        
    else if (square[1] == square[5] && square[5] == square[9])
    {
        return 1;
    }   
        
    else if (square[3] == square[5] && square[5] == square[7])
    {
        return 1;
    }   
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')
	{
        return 0;
	}
    else
	{
        return  - 1;
	}
}

//Display of Game Board
void board()
{

    cout<<"\t\t\t\t\n\n\t          Tic Tac Toe\n\n";

    cout<<"            CLIENT (X)  -  SERVER (O)\n\n\n";


    cout<<"\t\t    |     |     \n";
    cout<<"\t\t "<< square[1]<<"  | "<<square[2]<<"   |  "<<square[3] <<"\n";

    cout<<"\t\t____|_____|______\n";
    cout<<"\t\t    |     |     \n";

    cout<<"\t\t "<< square[4]<<"  | "<<square[5]<<"   |  "<<square[6] <<"\n";

    cout<<"\t\t____|_____|_____\n";
    cout<<"\t\t    |     |     \n";

    cout<<"\t\t "<<square[7]<<"  | "<<square[8]<<"   |  "<<square[9] <<"\n";

    cout<<"\t\t    |     |     \n";
}

//Main Function
int main()
{
	welcomeScreen();
	sleep(3);
	instruction();
	cout<<"THE GAME WILL START IN '3' SEC\n";
	sleep(1);
	cout<<"3\n";
	sleep(1);
	cout<<"2\n";
	sleep(1);
	cout<<"1\n";
		
		FILE *filep;
		filep=fopen("score.txt","aopen+");
		fclose(filep);
		//int player=1;
		//char symbol;
		int ccleintid;
		//char str[100];
		//int clientid;
		int msgbyte,cho;
		int choice,aopen,schoice;
		int icount;
		char mark;
		stringstream ss;
		
	   //Selection of options to proceed into the game 
	   
		cout<<"\n\nType 1 to start the game:-\nType 2 to view leader board:-\nType 3 to exit:-\n";
		cin>>schoice;
		
		// Display of Leaderboard
		if(schoice==2)
		{
		leader:
			cout<<"\n\n";
			cout<<"\tLEADERBOARD\n\n";
			char cfile;
			filep=fopen("score.txt","r");
			cout<<"\n";
			while((cfile=getc(filep))!=EOF)
			{
				cout<<cfile;
			}
			cout<<"\n";
			fclose(filep);
			cout<<"\n\nPress 1 to Play Again:- ";
			cout<<"\n\nPress 2 to see the Leaderboard";
			cout<<"\n\nPress 3 to Exit:-";
			cout<<"\n";
			cin>>cho;
			if(cho==1)
			{
				goto jump;
			}
			else if(cho==2)
			{
				goto leader;
			}
			else if(cho==3)
			{
				goto jump2;
			}
			else 
			{
				getchar();
			}
			
		}
		
		//Condition to exit the game
		if(schoice==3)
		{
		jump2:
			cout<<"Exit\n";
			cout<<"THANK U FOR PLAYING THE GAME \n";
			cout<<"HAVE A NICE DAY..........!!!!!\n";
			close(ccleintid);
			return 0;
		}
		
		//Condition to iterate the game
		if(schoice==1)
		{
			int port;
			port=6999;
			jump:
				ccleintid=socket(AF_INET,SOCK_STREAM,0);
				if(ccleintid==-1)
				{
					cout<<"IN SOCKET CREATION IN CLIENT SIDE FAILURE\n";
					exit(0);
				}
				cout<<"IN SOCKET CREATION IN CLIENT SIDE SUCCESSFUL\n";
				port+=1;
				struct sockaddr_in csadd;
				csadd.sin_family=AF_INET;
				csadd.sin_port=htons(port);
				csadd.sin_addr.s_addr=inet_addr("10.0.2.15");
				int c=connect(ccleintid,(struct sockaddr*)&csadd,sizeof(csadd));
				if(c==0)
				{
					cout<<"CONNECTION ESTABLISHMENT SUCCESSFUL\n";
				}
				if(c==(-1))
				{
					cout<<"CONNECTION ESTABLISHMENT UNSUCCESSFUL\n";
					exit(0);
				}
			
				icount = -1;
				while(icount!=1)
				{		
					board();
					cout<<"CLIENT Please Enter Your Choice\n";
					cin>>choice;
					if(!(choice>=1 && choice<=9))
					{

					   cout<<"Invalid move \n";
						cout<<"please enter a valid choice between 1-9\n";
					   cin>>choice;
					}
					
					mark='X';
					if (choice == 1 && square[1] == '1')
					{
						square[1] = mark;
					}	
					else if (choice == 2 && square[2] == '2')
					{
						square[2] = mark;
					}
						
					else if (choice == 3 && square[3] == '3')
					{
						square[3] = mark;
					}
						
					else if (choice == 4 && square[4] == '4')
					{
						square[4] = mark;
					}
						
					else if (choice == 5 && square[5] == '5')
					{
						square[5] = mark;
					}
						
					else if (choice == 6 && square[6] == '6')
					{
						square[6] = mark;
					}
						
					else if (choice == 7 && square[7] == '7')
					{
						square[7] = mark;
					}
						
					else if (choice == 8 && square[8] == '8')
					{
						square[8] = mark;
					}
						
					else if (choice == 9 && square[9] == '9')
					{
						square[9] = mark;
					}
						
					
					msgbyte=send(ccleintid,&choice,sizeof(choice),0);
					board();

				
					msgbyte=recv(ccleintid,&choice,sizeof(choice),0);
					
					filep=fopen("score.txt","aopen+");
					if(choice==10)
					{
						cout<<"You win";
						square[1] = '1';
						square[2] = '2';
						square[3] = '3';
						square[4] = '4';
						square[5] = '5';
						square[6] = '6';
						square[7] = '7';
						square[8] = '8';
						square[9] = '9';
						close(ccleintid);
						cout<<"\n";
						fprintf(filep,"\t\nClient\n");
						cout<<"\n";
						getchar();
						fclose(filep);
						cout<<"\n\nPress 1 to Play Again:- ";
						cout<<"\n\nPress 2 to see the Leaderboard";
						cout<<"\n\nPress 3 to Exit:-";
						cout<<"\n";
						cin>>cho;
						if(cho==1)
						{
							goto jump;
						}
						else if(cho==2)
						{
							goto leader;
						}
						else if(cho==3)
						{
							goto jump2;
						}
						else 
						{
							getchar();
						}
						break;
						
					}
					mark='O';
					if (choice == 1 && square[1] == '1')
						{
							square[1] = mark;
						}
						
						else if (choice == 2 && square[2] == '2')
						{
							square[2] = mark;
						}
						
						else if (choice == 3 && square[3] == '3')
						{
							square[3] = mark;
						}
						
						else if (choice == 4 && square[4] == '4')
						{
							square[4] = mark;
						}
						
						else if (choice == 5 && square[5] == '5')
						{
							square[5] = mark;
						}
						
						else if (choice == 6 && square[6] == '6')
						{
							square[6] = mark;
						}
						
						else if (choice == 7 && square[7] == '7')
						{
							square[7] = mark;
						}
							
						else if (choice == 8 && square[8] == '8')
						{
							square[8] = mark;
						}
						
						else if(choice == 9 && square[9] == '9')
						{
							square[9] = mark;
						}
						


					board();
					icount = checkwin();
					cout<<"\n\n"<<icount;
					filep=fopen("score.txt","aopen+");
					if(icount==1)
					{	board();
						int flag=11;
						cout<<"server win";
						square[1] = '1';
						square[2] = '2';
						square[3] = '3';
						square[4] = '4';
						square[5] = '5';
						square[6] = '6';
						square[7] = '7';
						square[8] = '8';
						square[9] = '9';
						close(ccleintid);
						cout<<"\n";
						fprintf(filep,"\t\nServer\n");
						cout<<"\n";
						getchar();
						fclose(filep);
						msgbyte=send(ccleintid,&flag,sizeof(flag),0);
						cout<<"\n\nPress 1 to Play Again:- ";
						cout<<"\n\nPress 2 to see the Leaderboard";
						cout<<"\n\nPress 3 to Exit:-";
						cout<<"\n";
						cin>>cho;
						if(cho==1)
						{
							goto jump;
						}
						else if(cho==2)
						{
							goto leader;
						}
						else if(cho==3)
						{
							goto jump2;
						}
						else 
						{
							getchar();
						}
						break;
						
					}
					
				
				}
				
		}  
	close(ccleintid);
	return 0;
}
