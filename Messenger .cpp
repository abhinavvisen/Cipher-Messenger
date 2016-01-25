#include<iostream>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include <fstream>
#include<stdlib.h>
using namespace std;
void file_update(char name[100],char password[100]);

struct inbox
	{
		char msg[100];
		char sender[100];
	};
	struct outbox
	{
		char msg1[100];
	};
struct node
{
	char name[100];
	node *link;
	int count,p,beg,count_sent;
	node()
	{
		count=0;
		beg=0;
		p=0;
		count_sent=0;
	}
	inbox msgs[100];
	outbox sentmsgs[100];
	char password[100];
};
class list
{
	public:
	node *front;
	node obj;
	public:
	list()
	{
		front =NULL;
		obj.count=0;
		obj.beg=0;
	}
	void addUser(char [],char []);
	void showUsers();
	int check(char [],char []);
	int check_rec(char []);
	void recieve_sent(char mssg[100]);
	void update_inbox(char inbox_message[100],char [],char[]);
	void showInbox(char []);
	void pop(char []);
	void dequeue(char []);
	void search(char[],char[]);
	void store_sent(char[],char[]);
	void show_sent(char[]);
	int checkunique(char []);
	void sort_users();
	char users[100][100];


};
void list::sort_users()
{
	system("cls");
	int k=0;
	node *trav;
	trav=front;
	char temp[100];
	while(trav!=NULL)
	{
		strcpy(users[k++],trav->name);
		trav=trav->link;
	}
	if(k==0)
	{
		cout<<"\nNo registered users yet\n";
	}
	else
	{
	for(int i=0;i<k-1;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			if(strcmpi(users[i],users[j])>0)
			{
				strcpy(temp,users[i]);
				strcpy(users[i],users[j]);
				strcpy(users[j],temp);
			}

		}
	}
	cout<<"\nUsers in alphebetical order are:\n";
	cout<<"-----------------------------------\n";
	for(int x=0;x<k;x++)
	{
		cout<<x+1<<" "<<users[x]<<endl;
	}
}
}
int list::checkunique(char namex[100])
{
		node *trav;
		trav=front;
		int f=0;
		while(trav!=NULL)
		{
			if(strcmp(trav->name,namex)==0)
			f=1;
			trav=trav->link;
		}
		if(f==0)
		return 1;
		else
		return 0;

}
void list::show_sent(char xname[100])
{
	node *trav;
	trav=front;
	int f=0;
	while(trav!=NULL)
	{
		if(strcmp(trav->name,xname)==0)
		{
			if(trav->count_sent!=0)
			{
		   	   for(int j=0;j<trav->count_sent;j++)
			    {
				  if(f=0)
				   {
					cout<<"\nYour sent messages are:\n";
					f++;
			       }
				cout<<j+1<<". "<<trav->sentmsgs[j].msg1<<endl;
				}
			}
			else if(trav->count_sent==0)
				{
					cout<<"\nEmpty";
				}
		}
			trav=trav->link;

		}
	}
void list::showInbox(char name[100])
{
	system("cls");
	node *trav;
	trav=front;
	int k=1,f=0;
	while(trav!=NULL)
	{

		if(strcmp(trav->name,name)==0)
		{
			cout<<"\n\nYOUR INBOX\n";
		cout<<"-----------------\n";
			if(trav->count-trav->beg>0)
			{
			for(int i=trav->beg;i<trav->count;i++)
				{
					if(f=0)
					{

					f++;
					}

					cout<<k++<<". "<<trav->msgs[i].msg<<"  from  --->  "<<trav->msgs[i].sender<<endl;
				}
			}
			else if(trav->count-trav->beg==0)
			{
				system("cls");
				cout<<"Your inbox is empty";


			}
		}
		trav=trav->link;
	}

	}


void list::addUser(char name1[100],char password1[100])
{
	node *temp;
	temp=new node;
	strcpy(temp->name,name1);
	strcpy(temp->password,password1);
	if(front==NULL)
	{
		temp->link=NULL;
		front=temp;
	}
	else
	{
		temp->link=front;
		front=temp;
	}
	//cout<<"\n\nUser added and pasword created\n\n";
}
void list::showUsers()
{

	int k=1;
	node *trav;
	trav=front;
	if(front==NULL)
	{
		cout<<"\nNo users registered yet\n";
	}
	else
	{
	cout<<"\nRegistered users\n";
	cout<<"------------------\n";
	while(trav!=NULL)
	{
		cout<<k++<<"."<<trav->name<<endl;
		trav=trav->link;
	}
	cout<<endl<<endl;
	}
}
int list::check_rec(char a[100])
{
	node *trav;
	int f=0;
	trav=front;
	while(trav!=NULL)
	{
		if(strcmp(a,trav->name)==0)
		{
			f=1;
			break;
		}
		trav=trav->link;
	}
	if(f==1)
	return 1;
	else
	return 0;
}
void list::pop(char name[100])
{
	system("cls");
	node *trav;
	trav=front;
	while(trav!=NULL)
	{
		if(strcmp(trav->name,name)==0)
		{
			if((trav->count-trav->beg)==0)
			{
				cout<<"No messages";
				break;
			}
			else
			{
				trav->count--;
				cout<<"\nLatest message deleted\n";
				break;
			}
		}
		trav=trav->link;
	}
}
void list::dequeue(char name[100])
{
	system("cls");
	node *trav;
	trav=front;
	while(trav!=NULL)
	{
		if(strcmp(trav->name,name)==0)
		{
			if((trav->count-trav->beg)==0)
			{
				cout<<"No messages";
				break;
			}
			else
			{
				trav->beg++;
				cout<<"\nOldest message deleted\n";
				break;
			}
		}
		trav=trav->link;
	}
}
int list::check(char a[100],char b[100])
{
	node *trav;
	int f=0;
	trav=front;
	while(trav!=NULL)
	{
		if(strcmp(a,trav->name)==0)
		{
			if(strcmp(b,trav->password)==0)
			{
				f=1;
				return 1;
				break;
			}
	    }
		trav=trav->link;
		if(f==1)
		break;
	}
	if(f==0)
	return 0;
	else
	return 1;
}
void list::search(char sname[100],char lname[100])
{
	system("cls");
	node *trav;
	trav=front;
	int k=1,f=0;

	while(trav!=NULL)
	{
		if(strcmp(trav->name,lname)==0)
		{
			for(int i=trav->beg;i<trav->count;i++)
				{
					if(strcmp((trav->msgs[i].sender),sname)==0)
					{
					cout<<"\n\nYour inbox messages from "<<sname<<" are:\n";
					f=1;
					cout<<k++<<". "<<trav->msgs[i].msg<<endl;
				   }
			}
		}
		trav=trav->link;
	}
	if(f==0)
	cout<<"\nYou dont have any messages from "<<sname<<endl;
}

void list::store_sent(char message[100],char user[100])
{
	node *trav;
	trav=front;
	while(trav!=NULL)
	{
		if(strcmp(trav->name,user)==0)
		{
			strcpy(trav->sentmsgs[trav->count_sent].msg1,message);
			break;
		}
		trav=trav->link;
	}
	trav->count_sent++;
}
void list::update_inbox(char inbox_message[100],char rec_name[100],char rec[100])
{
	node *trav;
	trav=front;
	int k=0;
	while(trav!=NULL)
	{
		if(strcmp(trav->name,rec_name)==0)
		{
			strcpy(trav->msgs[trav->count].msg,inbox_message);
			strcpy(trav->msgs[trav->count].sender,rec);
			trav->count++;
			break;
		}
		trav=trav->link;
	}
	system("cls");
	cout<<"\nMessage sent to "<<rec_name;
}
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
	list obj;
	int ch,ch_inbox,i;
	char ch2,ch3;
	HANDLE  hConsole;
	int records=0;
	int k,p=0,q=0,b=0,count=0,count1=0,msg_n=0,counts=0,check_special=0,check_number=0;

	char para[100][100],namei[100],passwordi[100],group_users[100][100],users_to_be_sent[100][100],group_message[100],input[100];


	fstream file;
	int ki=0;
	file.open("users.txt",ios::in);

	if (file.good()) {



	        // Read throuthe file and load into array

	        while (!file.eof() && (ki < 100)) {

	            file.getline(para[ki],100);

	            ki++;

			}
	 }
	file.close();

	for(int t=1;t<=ki-2;t++)
	{
		count=0;
		count1=0;
		for(int u=0;para[t][u]!='$';u++)
		{
			namei[count++]=para[t][u];
		}
		namei[count]='\0';
		for(int v=count+1;v<(strlen(para[t]));v++)
		{
			passwordi[count1++]=para[t][v];
		}
		passwordi[count1]='\0';
		obj.addUser(namei,passwordi);
		//cout<<"\nName: "<<namei;
		//cout<<"\nPassword: "<<passwordi;
	}

	char name[100],password[100],login_name[100],login_password[100],message[100],rec_name[100],date[100],search_name[100],cpassword[100];
	do
	{

	system("cls");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//Box begins
	gotoxy(30,1);
	cout<<(char)218;
	for(int i=0;i<20;i++)
	{
		cout<<(char)196;
	}
	gotoxy(50,1);
	cout<<(char)191;
	for(int i=2;i<5;i++)
	{
		gotoxy(30,i);
		cout<<(char)179;
	}
	gotoxy(30,4);
	cout<<(char)192;
	for(int i=0;i<20;i++)
	{
		cout<<(char)196;
	}
	gotoxy(50,4);
	cout<<(char)217;
	for(int i=3;i>=2;i--)
	{
		gotoxy(50,i);
		cout<<(char)179;
	}
	gotoxy(38,2);
	cout<<"CIPHER";
	gotoxy(37,3);
	cout<<"MESSENGER";



	//box Ends

	cout<<"\n\n\nEnter your choice\n-------------------\n1. Sign Up\n2. Diplay existing users\n3. Log in\n4. Display users alphabetically\n5. Exit\nChoice: ";
	cin>>ch;
	if(ch==1)
	{
	system("cls");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//Box begins
	gotoxy(30,1);
	cout<<(char)218;
	for(int i=0;i<20;i++)
	{
		cout<<(char)196;
	}
	gotoxy(50,1);
	cout<<(char)191;
	for(int i=2;i<5;i++)
	{
		gotoxy(30,i);
		cout<<(char)179;
	}
	gotoxy(30,4);
	cout<<(char)192;
	for(int i=0;i<20;i++)
	{
		cout<<(char)196;
	}
	gotoxy(50,4);
	cout<<(char)217;
	for(int i=3;i>=2;i--)
	{
		gotoxy(50,i);
		cout<<(char)179;
	}
	gotoxy(34,2);
	cout<<"---SIGN UP---";
	//gotoxy(37,3);
	//cout<<"SERVICE";
	//box Ends
	again:
		check_special=0;
		check_number=0;

	cout<<"\n\n\n\nEnter your name: ";
	cin>>input;
		for(int i=0;i<strlen(input);i++)
		{
			if(input[i]=='.'||input[i]==','||input[i]=='!'||input[i]=='@'||input[i]=='#'||input[i]=='$'||input[i]=='%'||input[i]=='^'||input[i]=='&'||input[i]=='*'||input[i]=='('||input[i]==')'||input[i]=='_'||input[i]=='-'||input[i]=='+'||input[i]=='=')
			{
			check_special=1;
			break;
			}
			else if(input[0]=='1'||input[0]=='2'||input[0]=='3'||input[0]=='4'||input[0]=='5'||input[0]=='6'||input[0]=='7'||input[0]=='8'||input[0]=='9')
			{
			check_number=1;
			break;
			}
		}
		//cout<<check_special;
		if(check_special==1)
		{
		cout<<"\nSpecial characters are not allowed in a user name\n";
		goto again;
		}
		else if(check_number==1)
		{
		cout<<"\nUsername cannot start with a number\n";
		goto again;
		}
		else if(check_special==0&&check_number==0)
		strcpy(name,input);

	cout<<"Create a new password: ";
	int z=0;
		while((ch2=getch())!=13)
		{
			password[z]=ch2;
			cout<<"*";
			z++;
		}
		password[z]='\0';

	cout<<"\nConfirm password: ";
	int t=0;
	while((ch2=getch())!=13)
	{
			cpassword[t]=ch2;
			cout<<"*";
			t++;

	}
	cpassword[t]='\0';
	if(strcmp(password,cpassword)==0)
	{
		if(obj.checkunique(name)==1)
		{
		obj.addUser(name,password);
		file_update(name,password);
		records++;
		system("cls");
		cout<<"\n\n\nNEW USER CREATED!!!\n";

		}
		else
		{
		system("cls");
		cout<<"\n\nThe username is not unique\n\n";
		}

	}
	else
    {
	cout<<"\nPasswords dont match\n";
	}
}
	else if(ch==2)
			{
				system("cls");
				obj.showUsers();
			}
		else if(ch==3)
			{
				system("cls");

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//Box begins
	gotoxy(30,1);
	cout<<(char)218;
	for(int i=0;i<20;i++)
	{
		cout<<(char)196;
	}
	gotoxy(50,1);
	cout<<(char)191;
	for(int i=2;i<5;i++)
	{
		gotoxy(30,i);
		cout<<(char)179;
	}
	gotoxy(30,4);
	cout<<(char)192;
	for(int i=0;i<20;i++)
	{
		cout<<(char)196;
	}
	gotoxy(50,4);
	cout<<(char)217;
	for(int i=3;i>=2;i--)
	{
		gotoxy(50,i);
		cout<<(char)179;
	}
	gotoxy(36,2);
	cout<<"--LOG IN--";
	//gotoxy(37,3);
	//cout<<"SERVICE";
	//box Ends

				if(obj.front==NULL)
					{
							cout<<"\nNo registered users yet\n";
					}
				else
					{
							cout<<"\n\n\n\nEnter your name: ";
							cin>>login_name;
							cout<<"Enter password: ";
							int y=0;
							while((ch2=getch())!=13)
							{
									login_password[y]=ch2;
									cout<<"*";
									y++;
							}
							login_password[y]='\0';
							if(obj.check(login_name,login_password)==1)
								{
									system("cls");
									do{
											home:
											cout<<"\n\nWelcome "<<login_name<<"!!!"<<endl;
											cout<<"------------------\n";
											cout<<"1. Inbox\n2. Sent Messages\n3. Send new message\n4. Show Contacts \n5. Send group message\n6. Logout\n\nChoice: ";

											cin>>ch_inbox;
											if(ch_inbox==1)
		      									{
		      										system("cls");

														cout<<"("<<login_name<<")"<<" INBOX\n";
														cout<<"-------------\n";
														cout<<"\n1. View all\n2. Delete newest\n3. Delete oldest\n4. Search by sender username\n5. Go to Home\n\nChoice: ";
														cin>>ch;
														if(ch==1)
														obj.showInbox(login_name);
														else if(ch==2)
														obj.pop(login_name);
											   			else if(ch==3)
														obj.dequeue(login_name);
														else if(ch==4)
															{
																	cout<<"Enter username: ";
																	cin>>search_name;
																	obj.search(search_name,login_name);
															}
														else if(ch==5)
															{
																goto home;
															}

											    }
											else if(ch_inbox==2)
												{

														system("cls");
														cout<<"\nSENT MESSAGES\n";
														cout<<"-----------------";
														obj.show_sent(login_name);
												}
											else if(ch_inbox==3)
												{
														system("cls");
														cout<<"\nSend Message";
														cout<<"\n---------------\n";
														cout<<"Recepient's username: ";
														cin>>rec_name;
														if(obj.check_rec(rec_name)==1)
																{
																		cout<<"\nEnter your message: ";
																		cin.ignore();
																		cin.getline(message,100);
																		obj.update_inbox(message,rec_name,login_name);
																		obj.store_sent(message,login_name);
			    												}
														else
																		cout<<"\n No such username exists\n";
												}
											else if(ch_inbox==4)
												{
														obj.showUsers();
												}
												else if(ch_inbox==5)
												{
													system("cls");
													cout<<"\n GROUP MESSAGE\n";
													cout<<"-------------------";
													cout<<"\nEnter the number of users whom you want to send the message: ";
													cin>>msg_n;
													for(int f=0;f<msg_n;f++)
													{
														cout<<"User "<<f+1<<": ";
														cin>>group_users[f];
														if(obj.check_rec(group_users[f])!=1)
														{
															cout<<"\n"<<group_users[f]<<" is not a registered user\n";
															f--;
														}
														else
														{
															strcpy(users_to_be_sent[counts++],group_users[f]);
														}
													}
													cout<<"Enter the message you want to send: ";
													cin.ignore();
													cin.getline(group_message,100);
													for(int g=0;g<counts;g++)
													{
														obj.update_inbox(group_message,users_to_be_sent[g],login_name);
													}

												}
		 							}while(ch_inbox!=6);
								}
									else
										{
													system("cls");
													cout<<"\nUser doesn't exist or incorrect password";
													cout<<"\a";
										}
					}
			}
			else if(ch==4)
			obj.sort_users();
	}while(ch!=5);
}
void file_update(char name[100],char password[100])
{
	fstream filestr;
	filestr.open ("users.txt", fstream::in | fstream::out | fstream::app);
 // ofstream myfile ("example.txt");
  	filestr<<name<<"$"<<password<<"\n";
    filestr.close();
}








