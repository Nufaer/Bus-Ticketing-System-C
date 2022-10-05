</p>
<p><%@ LANGUAGE=”C++” %><%<br />
//			This is made by Vipin Panicker.<br />
//			E-Mail: itsvipin@hotmail.com<br />
#include “conio.h”<br />
#include “stdio.h”<br />
#include “iostream.h”<br />
#include “string.h”<br />
#include “graphics.h”<br />
#include “stdlib.h”<br />
#include “dos.h”<br />
static int p=0;<br />
class a<br />
{<br />
		char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],<br />
		seat[8][4][10];<br />
	public:<br />
		void install();<br />
		void allotment();<br />
		void empty();<br />
		void show();<br />
		void avail();<br />
		void position(int i);<br />
}bus[10];//here we declare the number of buses we can have.<br />
void vline(char ch)<br />
{<br />
	for (int i=80;i>0;i–)//Here i’s value will depend on your computer.<br />
		cout<<ch;
}
void a::install()
{
	cout<<"Enter bus no: ";
	cin>>bus[p].busn;<br />
	cout<<"\n Enter Driver's name: ";
	cin>>bus[p].driver;<br />
	cout<<"\n Arrival time: ";
	cin>>bus[p].arrival;<br />
	cout<<"\n Departure: ";
	cin>>bus[p].depart;<br />
	cout<<"\n From: \t\t\t";
	cin>>bus[p].from;<br />
	cout<<"\n To: \t\t\t";
	cin>>bus[p].to;<br />
	bus[p].empty();<br />
	p++;<br />
}<br />
void a::allotment()<br />
{<br />
	int seat;<br />
	char number[5];<br />
	top:<br />
	cout<<"Bus no: ";
	cin>>number;<br />
	int n;<br />
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p)
	{
		cout<<"\n Seat number: ";
		cin>>seat;<br />
		if (seat>32)<br />
			{<br />
				cout<<"\n There are only 32 seats available in this bus.";
			}
		else
			{
			if (strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
				{
					cout<<"Enter passanger's name: ";
					cin>>bus[n].seat[seat/4][(seat%4)-1];<br />
					break;<br />
				}<br />
			else<br />
				cout<<"The seat no. is already reserved.\n";
			}
	}
	if (n>p)<br />
	{<br />
		cout<<"Enter correct bus no.\n";
		goto top;
	}
}
void a::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"Empty");
		}
	}
}
void a::show()
{
	int n;
	char number[5];
	cout<<"Enter bus no: ";
	cin>>number;<br />
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
			break;
	}
	while (n<=p)
	{
		vline('*');
		cout<<" Bus no: \t"<<bus[n].busn
		<<"\n Driver: \t"<<bus[n].driver<<"\t\t Arrival time:\t"
		<<bus[n].arrival<<"\t Departure time:\t"<<bus[n].depart
		<<"\n From:\t\t"<<bus[n].from<<"\t\t To: \t\t\t"<<
		bus[n].to<<"\n";
		vline('*');
		bus[0].position(n);
		int a=1;
		for (int i=0;i<8;i++)
		{
			for(int j=0;j<4;j++)
			{
				a++;
				if(strcmp(bus[n].seat[i][j],"Empty")!=0)
					cout<<"\n The seat no "<<a-1<<" is reserved for "<<bus[n].seat[i][j]<<" .";
			}
		}break;
	}	if(n>p)<br />
			cout<<"enter correct bus no.";
}
void a::position(int l)
{
	int s=0,p=0;
	for(int i=0;i<8;i++)
	{
		cout<<"\n";
		for(int j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[l].seat[i][j],"Empty")==0)
				{
					cout.width(5);
					cout.fill(' ');
					cout<<s<<".";
					cout.width(10);
					cout.fill(' ');
					cout<<bus[l].seat[i][j];
					p++;
				}
			else
				{
					cout.width(5);
					cout.fill(' ');
					cout<<s<<".";
					cout.width(10);
					cout.fill(' ');
					cout<<bus[l].seat[i][j];
				}
		}
	}
		cout<<"\n\n There are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
}
void a::avail()
{
	for(int n=0;n<p;n++)
	{
		vline('*');
		cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time:\t"<<bus[n].arrival<<"\tDeparture Time: \t"<<bus[n].depart<<"\n From: \t\t"<<bus[n].from<<"\t\t To: \t\t\t"<<bus[n].to<<"\n";
		vline('*');
		vline('_');
	}
}
void main()
{
	clrscr();
	int w;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"d:\\tc\\bgi");//enter the path of ur c compiler where u installed it.
	setbkcolor(GREEN);
	while(1)
	{
		cout<<"\n\n\n\n";
		cout<<"\t\t\t 1.Install\n\t\t\t 2.Reservation\n\t\t\t 3.Show \n\t\t\t 4.Buses Available. \n\t\t\t 5.Exit";
		cout<<"\n\t\t\t Enter your choice:-> “;<br />
		cin>>w;<br />
		switch(w)<br />
		{<br />
			case 1:<br />
			bus[p].install();<br />
			break;<br />
			case 2:<br />
			bus[p].allotment();<br />
			break;<br />
			case 3:<br />
			bus[0].show();<br />
			break;<br />
			case 4:<br />
			bus[0].avail();<br />
			break;<br />
			case 5:<br />
			exit(0);<br />
		}<br />
	}<br />
}<br />

