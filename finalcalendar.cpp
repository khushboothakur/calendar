#include<iostream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;

class calendar
{
	string month[12];
	int year;
	int index;
	int count;
	string usermonth;
	int days[12];
	int arr[42];
	public:
		void set_count(){count=0;
		}
		void get_month();
		int get_index(int x,string y);
		void set_calen(int t,int cindex);
		void show_calen(int a);
		void gotoxy(int x,int y);
};

void calendar::get_month()
{
	month[0] = "january";month[1] = "february";month[2] = "march";month[3] = "april";
	month[4] = "may";month[5] = "june";month[6] = "july";month[7] = "august";month[8] = "september";month[9] = "october";month[10] = "november";
	month[11] = "december";
}

int calendar::get_index(int x,string y)
{
	year = x;
	//strcpy(usermonth,y);
	usermonth = y;
	int i;
	int z;
	for(i=0;i<12;i++)
	{
	     if(month[i] == usermonth)
	     {
	     	return i;
		 }
	}
}


void calendar::set_calen(int t,int cindex)
{
	year=t;
	int a = 1990,count = 0,i,j=0,k=0;
	int leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	while(a<=year)
	{
		if(a%4 == 0)
		{
			leap[1]=29;
		}
		else
		{
			leap[1]=28;
		}
		for(i=0;i<12;i++)
		{
					//char arr[42];
				j=0;
				
						while(count>0)
						{
							arr[j] = 0;
							count--;
							j++;
						}
						
						for(k=1;k<=leap[i];k++)
						{
							arr[j] = k;
							j++;
						}
						
						int b=42-j;
						count = 0;
						for(k=0;k<b;k++)
						{
							arr[j] = 0;
							j++;
							count++;
						}
						
						if(count>7)
						{
							count=count-7;
							count = 7-count;
						}
						else
						{
							count=7-count;
						}
		
			if(a == year && i == cindex)
			{
				break;
			}
		}
		a++;
	}
	
}

void calendar::show_calen(int a)	
{
	cout<<"\n"<<month[a]<<"\t"<<year<<"\n";
	cout<<"Mo\tTu\tWe\tTh\tFr\tSa\tSu\n";
	int i,j,k=0;
	for(i=0;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			cout<<arr[k]<<"\t";
			k++;
		}
		cout<<"\n";
	}
}

void calendar::gotoxy(int x,int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main()
{
	int a,index;
	string b;
	int key;
	char another = 'y';
	cout<<"Enter the year and month:\n";
	cin>>a;
	cin>>b;
	calendar c;
	c.set_count();
	c.get_month();
	index = c.get_index(a,b);
	while(another == 'y')
	{
		system("cls");
	    c.set_calen(a,index);
	    c.gotoxy(50,10);
	    c.show_calen(index);
	    cout<<"Do you want change the month and year(Y/N)";
	    fflush(stdin);
	    another = getche();
	    if(another=='y')
	    {
	    	cout<<"\npress 1:Next year,same month\n";
		    cout<<"press 2:previous year,same month\n";
		    cout<<"press 3:same year,next month\n";
		    cout<<"press 4:same year,previous month\n";
		    cout<<"Enter your choice\n";
		    cin>>key;
		    if(key==1)
		    {
		    	a = a+1;
		    }
		   else if(key==2)
		   {
		    	a = a-1;
	    	}
	     	else if(key==3)
		   {
		   	  if(index==11)
		   	  {
		   	  	index=0;
		   	  	a=a+1;
		      }
		      else
		      {
			     index = index+1;
			 }
		   }
		  else
		  {
		  	     if(index==0)
		  	     {
		  	     	index=11;
		  	     	a=a-1;
				 }
				 else
				 {
		    	    index = index-1;
		    	}
		  }
	   }
   }
	
}
