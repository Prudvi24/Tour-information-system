#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>

using namespace std;

void reg();
void login();
void logout();
void ava();
void view();
void rem();

string user="prince",pass="password";

int log=0;

int main()
{
	cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|                                                                                                             |"<<endl;
	cout<<"|                                                                                                             |"<<endl;
	cout<<"|                                        TOUR INFORMATION SYSTEM                                              |"<<endl;
	cout<<"|                                                                                                             |"<<endl;
	cout<<"|                                                                                                             |"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
	
	
menu: 
     cout<<"Press any key to continue..."<<endl;
	  getchar();
	  int a,b;
	
    cout<<"------------------------------------------------MAIN MENU------------------------------------------------------"<<endl;
    cout<<"|                                                                                                             |"<<endl;
    cout<<"|                                         1.Registration for the tour                                         |"<<endl;
    cout<<"|                                         2.Avaliable tours                                                   |"<<endl;
    cout<<"|                                         3.view tour information                                             |"<<endl;
    if(log==0)
    cout<<"|                                         4.Login                                                             |"<<endl;
    else
    cout<<"|                                         4.Logout                                                            |"<<endl;
    cout<<"|                                         5.Remove a tour                                                     |"<<endl;
    cout<<"|                                         6.Exit                                                              |"<<endl;
    cout<<"|                                                                                                             |"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
    
back:
	cout<<"Enter any one of the option"<<endl;
	cin>>a;
    switch(a)
    {
    	case 1:
    		cout<<"----------------------------Registration for the tour------------------------------------------------"<<endl;
    		if(log==1)
    		reg();
    		else
    		cout<<"Please login to continue..."<<endl;
    		getchar();
    		goto menu;
    		break;
			
		case 2:
		     cout<<"------------------------------------Avalaiable tours-----------------------------------------------------"<<endl;
			 ava();
			 getchar();
			 goto menu;
			 break;
			 
		case 3:
	     	cout<<"-----------------------------------------View tours---------------------------------------------------------"<<endl;
		     view();
			 getchar();
			 goto menu;
			 break;
			 
		case 4:
			cout<<"----------------------------------------Login portal---------------------------------------------------------"<<endl;
			    if(log==0)
			     login();
			    else
			    logout();
			    getchar();
			    goto menu;
			    break;
			    
		case 5:
			   cout<<"----------------------------------Remove a tour----------------------------------------------------------"<<endl;
			   if(log==0)
			   login();
			   else
			   rem();
			   getchar();
			   goto menu;
			    
		case 6:
			cout<<" "<<endl;
			exit(0);
			
		default: 
		cout<<"Invalid input....try again"<<endl;
		goto back;
	}
    
    return 0;
}

void reg()
{
	char name[50],sub[50],attr[50],mode[50];
	int n,i,day,night,fair;
	
	cout<<"Enter the name of the tour"<<endl;
	cin>>name;
	 ofstream b;
	 b.open("tour.txt",ios::out|ios::app);
	 b<<name<<endl;
	 b.close();
	 
	 ofstream a;
	 a.open(name);
	 a<<"Name of the tour: "<<name<<endl;
	 cout<<"Enter no.of sub tours"<<endl;
	 cin>>n;
	 cout<<"Sub tours: "<<endl;
	 
	 for(i=0;i<n;i++)
	 {
	 	cout<<"Enter "<<i+1<<" place: ";
	 	cin>>sub;
	 	cout<<endl;
	 	a<<sub<<endl;
	 }
	 a<<endl;
	 
	 cout<<"Enter number of days of tour: ";
	 cin>>day;
	 a<<"Number of days of tour: ";
	 a<<day<<endl;
	 cout<<endl;
	 a<<endl;
	 
	 cout<<"Enter number of nights of tours: ";
	 cin>>night;
	 a<<"Number of night of tour: ";
	 a<<night<<endl;
	 cout<<endl;
	 a<<endl;
	 
	 cout<<"Numer of special attraction: ";
	 cin>>n;
	 
	 a<<"special attractions: ";
	 
	 for(i=0;i<n;i++)
	 {
	 	cout<<"Enter "<<i+1<<" attraction: ";
	 	cin>>attr;
	 	cout<<endl;
	 	a<<attr<<endl;
	 }
	 a<<endl;
	 
	 cout<<"Enter mode of journey: ";
	 cin>>mode;
	 
	 a<<"Mode of journey: "<<mode<<endl;
	 a<<endl;
	 
	 cout<<"Enter the total fair: ";
	 cin>>fair;
	 
	 a<<"Total Fair: "<<fair<<endl;
     
     a.close();
}

void login()
{
	string uenter,penter;
	
	cout<<"Enter the username: ";
	cin>>uenter;
	
	cout<<"Enter the password: ";
	cin>>penter;
	
	if(uenter==user&&penter==pass)
	{
		log=1;
		cout<<"Successfully logged_In"<<endl;
	}
	else
	{
		cout<<"Re-enter your username and password"<<endl;
		
	}
}

void logout()
{
	log=0;
	cout<<"Successfully logged_out"<<endl;
}

void ava()
{
	string line;
	ifstream b;
	b.open("tour.txt");
	while(getline(b,line))
	{
		cout<<line<<endl;
	}
	b.close();
}

void view()
{
	ifstream c;
	char name[20];
	cout<<"Enter name of tour: ";
	cin>>name;
	c.open(name);
	string line;
	while(!c.eof())
	{
		getline(c,line);
		cout<<line<<endl;
	}
	c.close();
}

void rem()
{
	fstream a;
	char name[20];
	cout<<"Enter the tour that should be removed: ";
	cin>>name;
	ofstream b;
	remove(name);
}

