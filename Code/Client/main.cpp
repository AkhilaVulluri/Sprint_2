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
#define MAX 10
#define BACKLOG 5
#define INDEX_0 '0'
#define INDEX_1 '1'
#define INDEX_2 '2'
#define INDEX_3 '3'
#define INDEX_4 '4'
#define INDEX_5 '5'
#define INDEX_6 '6'
#define INDEX_7 '7'
#define INDEX_8 '8'
#define INDEX_9 '9'
using namespace std;

char square[MAX] = { INDEX_0, INDEX_1, INDEX_2, INDEX_3, INDEX_4, INDEX_5, INDEX_6, INDEX_7, INDEX_8, INDEX_9 };

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
		int client_file_descriptor;
		//char str[100];
		//int clientid;
		int msgbyte,Inner_choice;
		int choice,aopen,Main_choice;
		int icount;
		char mark;
		stringstream ss;
		
	   //Selection of options to proceed into the game 
	   
		cout<<"\n\nType 1 to start the game:-\nType 2 to view leader board:-\nType 3 to exit:-\n";
		cin>>Main_choice;
		
		// Display of Leaderboard
		if(Main_choice==2)
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
			cin>>Inner_choice;
			if(Inner_choice==1)
			{
				goto jump;
			}
			else if(Inner_choice==2)
			{
				goto leader;
			}
			else if(Inner_choice==3)
			{
				goto jump2;
			}
			else 
			{
				getchar();
			}
			
		}
		
		//Condition to exit the game
		if(Main_choice==3)
		{
		jump2:
			cout<<"Exit\n";
			cout<<"THANK U FOR PLAYING THE GAME \n";
			cout<<"HAVE A NICE DAY..........!!!!!\n";
			close(client_file_descriptor);
			return 0;
		}
		
		//Condition to iterate the game
		if(Main_choice==1)
		{
			int port;
			port=6999;
			jump:
				client_file_descriptor=socket(AF_INET,SOCK_STREAM,0);
				if(client_file_descriptor==-1)
				{
					cout<<"IN SOCKET CREATION IN CLIENT SIDE FAILURE\n";
					exit(0);
				}
				cout<<"IN SOCKET CREATION IN CLIENT SIDE SUCCESSFUL\n";
				port+=1;
				struct sockaddr_in client_sock_address;
				client_sock_address.sin_family=AF_INET;
				client_sock_address.sin_port=htons(port);
				client_sock_address.sin_addr.s_addr=inet_addr("10.0.2.15");
				int connect_file_descriptor=connect(client_file_descriptor,(struct sockaddr*)&client_sock_address,sizeof(client_sock_address));
				if(connect_file_descriptor==0)
				{
					cout<<"CONNECTION ESTABLISHMENT SUCCESSFUL\n";
				}
				if(connect_file_descriptor==(-1))
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
						
					
					msgbyte=send(client_file_descriptor,&choice,sizeof(choice),0);
					board();

				
					msgbyte=recv(client_file_descriptor,&choice,sizeof(choice),0);
					
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
						close(client_file_descriptor);
						cout<<"\n";
						fprintf(filep,"\t\nClient\n");
						cout<<"\n";
						getchar();
						fclose(filep);
						cout<<"\n\nPress 1 to Play Again:- ";
						cout<<"\n\nPress 2 to see the Leaderboard";
						cout<<"\n\nPress 3 to Exit:-";
						cout<<"\n";
						cin>>Inner_choice;
						if(Inner_choice==1)
						{
							goto jump;
						}
						else if(Inner_choice==2)
						{
							goto leader;
						}
						else if(Inner_choice==3)
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
						close(client_file_descriptor);
						cout<<"\n";
						fprintf(filep,"\t\nServer\n");
						cout<<"\n";
						getchar();
						fclose(filep);
						msgbyte=send(client_file_descriptor,&flag,sizeof(flag),0);
						cout<<"\n\nPress 1 to Play Again:- ";
						cout<<"\n\nPress 2 to see the Leaderboard";
						cout<<"\n\nPress 3 to Exit:-";
						cout<<"\n";
						cin>>Inner_choice;
						if(Inner_choice==1)
						{
							goto jump;
						}
						else if(Inner_choice==2)
						{
							goto leader;
						}
						else if(Inner_choice==3)
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
	close(client_file_descriptor);
	return 0;
}
