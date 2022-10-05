#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<dos.h>
#include<fstream.h>
#include<ctype.h>
#include<string.h>
//GLOBAL VARIABLE
int i=0;
//GLOBAL FUNTIONS
void startup();
void exportrecordfile();
class travelagency
{
 private:
 char name[50],destination[30],add[80],flag,trans[30];
 float price;
 int not1,not2,top2;
 int fare;
 public:
 int toggle;
 void reserve();
 void displayreservations();
 void showtransportrec();
 void deltransportrec();
 void searchtransportrec();
 void transfertransportdata();
 void edittransportdata();
 void transfertransportdata1();
 void assignprice();
}user,user1[44];


int main()
{
     clrscr();
     startup();                       //FUNTION TO DISPLAY INTRODUCTION SCREEN
     clrscr();
     int select;
     do
     {
         cout<<"\n\n";
         cout<<"\t\tM A V E R I C K ' S  T R A V E L  A G E N C Y \n\n";
         cout<<"\t\t    E - R E S E R V A T I O N  S Y S T E M    \n\n\n";
         cout<<"\t\t\t1. Make a Reservation\n";
         cout<<"\t\t\t2. View Reservations\n";
         cout<<"\t\t\t3. Edit a Reservation\n";
         cout<<"\t\t\t4. Search for a Reservation\n";
         cout<<"\t\t\t5. Delete a Reservation\n";
         cout<<"\t\t\t6. View Bus Schedule\n";
         cout<<"\t\t\t0. Exit\n\n";
         cout<<"\t\t\tSelect an option: ";
         cin>>select;
         switch(select)
         {
                       case 1:
                            exportrecordfile();
                            i++;
                            break;
                       case 2:
                            user.showtransportrec();
                            //query();
                            break;
                       case 3:
                            user.edittransportdata();
                            break;
                       case 4:
                            user.searchtransportrec();
                            break;
                       case 5:
                            user.deltransportrec();
                            break;
                       case 6:

                            break;
                       default:
                               cout<<"Invalid Input";
                               break;
         }
     }
     while(select!=0);
     return 0;
}

//TRANSPORTATION RESERVATIONS

//FUNTION USED TO RESERVE TRANSPORTATION.

void travelagency::reserve()
{
clrscr();
 flag='N';
 while(flag!='Y')
 {
 clrscr();
 assignprice();


   clrscr();
   gotoxy(15,2);cout<<"PLEASE FILL IN THE DETAILS ...";
   gotoxy(25,5);cout<<"TRANSPORT RESERVATION FORM";
   gotoxy(5,8);cout<<"Name: ";
   gotoxy(5,10);cout<<"Address: ";
   gotoxy(5,12);cout<<"Destination: ";
   gotoxy(30,12);cout<<"Mode of Transport: ";
   gotoxy(5,14);cout<<"Type of Tickets to be Reserved(1/0)" ;
   gotoxy(10,16);cout<<"Executive: ";
   gotoxy(30,16);cout<<"Economy: ";
   gotoxy(10,22);cout<<"Is the information correct(y/n)?? ";
   gotoxy(10,8);gets(name);
   gotoxy(13,10);gets(add);
   gotoxy(19,12);gets(destination);
   gotoxy(50,12);gets(trans);
   gotoxy(22,16);cin>>not1;
   gotoxy(40,16);cin>>not2;
   gotoxy(45,22);cin>>flag;
 flag=toupper(flag);
}
displayreservations();
}

//FUNTION USED TOASSIGN PRICE ACCORDING TO DESTINATION.

void travelagency::assignprice()
{
clrscr();
int dest;
  gotoxy(20,2);cout<<"SELECT DESTINATION: ";
  gotoxy(5,5);cout<<"1. Jaipur";
  gotoxy(5,7);cout<<"2. Nainital";
  gotoxy(5,9);cout<<"3. Chandigarh";
  gotoxy(5,23);cout<<"Enter (1-3) to Reserve: ";
  gotoxy(45,23);cin>>dest;
switch(dest)
{
 case 1:
      fare=500;
      break;
 case 2:
      fare=500;
      break;
 case 3:
      fare=400;
      break;
}
}

//FUNTION USED TO SHOW TRANSPORT RESERVATION.

void travelagency::displayreservations()
{
 price=(fare*not1)+((fare/2)*not2);
 if(toggle==1)
 {
 clrscr();
 for(int h=25;h<50;h++)
 {
 gotoxy(20,8);cout<<"Please wait while we make the Reservation";
 gotoxy(h,10);cout<<"Û";

 }
 toggle=0;
 }
 clrscr();
 gotoxy(25,5);cout<<"Transport   Reservation  ";
 gotoxy(24,6);cout<<"-----------------------";
 gotoxy(15,8);cout<<"Name:"<<strupr(name);
 gotoxy(15,10);cout<<"Address:"<<strupr(add);
 gotoxy(15,12);cout<<"Mode of transportation:    "<<trans
		   <<"   Destination:"<<destination;
 gotoxy(15,14);cout<<"No. of EXECUTIVE class tickets reserved: "<<not1;
 gotoxy(15,16);cout<<"No. of ECONOMY   class tickets reserved: "<<not2;
 gotoxy(15,20);cout<<"Your Reservations have been done Please pay the Amount!!!";
 gotoxy(25,22);cout<<"Amount: Rs."<<price;
 getch();
}

//FUNTION USED TO SHOW ALL TRANSPORT RECORDS.
void travelagency::showtransportrec()
{
fstream file1;
file1.open("transport.dat",ios::binary|ios::in);
 while(file1.read((char*)&user,sizeof (user)))
 user.displayreservations();;
file1.close();
}

//FUNTION USED TO DELETE A  TRANSPORT RECORDS.

void travelagency::deltransportrec()
{
clrscr();
  char delname[20];
  gotoxy(20,5);cout<<"Enter name to delete record for...";
  gotoxy(30,7);gets(delname);
  strupr(delname);
    fstream  file2,file3;
    int dele=0;
    file2.open("transport.dat",ios::binary | ios::in);
    file3.open("temp3.dat",ios::binary | ios::out );
       while(file2.read ((char*)&user,sizeof (user)))
       {
       if ((strcmp(name,delname))!=0)
       file3.write((char*)&user,sizeof (user));
       else
       dele++;
       }
       if(dele!=0)
       cout<<endl<<"                    ...Deleted...";
       else
       cout<<endl<<"                  Record not found..";
       getch();
       file2.close();
       file3.close();
       transfertransportdata();
}

//FUNTION USED TO TRANSFER UNDELETED TRANSPORT RECORDS.
void travelagency::transfertransportdata()
{
fstream oldfile1,newfile1;
oldfile1.open("temp3.dat",ios::binary | ios::in);
newfile1.open("transport.dat",ios::binary | ios::out);
     while(oldfile1.read((char*)&user,sizeof(user)))
     newfile1.write((char*)&user,sizeof (user));
oldfile1.close();
newfile1.close();
}


//FUNTION USED TO SEARCH FOR A TRANSPORT RECORDS.

void travelagency::searchtransportrec()
{
clrscr();
 char sename[20];
 gotoxy(20,5);cout<<"Enter Name to search for..";
 gotoxy(25,7);gets(sename);
 strupr(sename);
    fstream file4;
    file4.open("transport.dat",ios::binary | ios::in);
    int serch=0;
       while(file4.read((char*)&user,sizeof (user)))
       {
	if(strcmp(name,sename)==0)
	{
	serch++;
	user.displayreservations();;
	}
       }
       if(serch==0)
       cout<<"                       No Record Exists";
       file4.close();
       getch();
}
//FUNTION USED TO EDIT TRANSPORT RECORD.

void travelagency::edittransportdata()
{
clrscr();
  char edname[30];
  int ede1=0;
  gotoxy(20,5);cout<<"Enter Name to Edit Record for...";
  gotoxy(25,7);gets(edname);
  strupr(edname);
  fstream file5,file6;
  file5.open("transport.dat",ios::binary | ios::in) ;
  file6.open("temp2.dat",ios::binary | ios::out ) ;
   while(file5.read((char*)&user,sizeof(user)))
  {
   if (strcmp (edname,name)==0)
   {
    reserve();
    ede1++;
   }
   file6.write((char*)&user,sizeof (user));
  }
if(ede1==0)
{
gotoxy(25,17);cout<<"RECORD DOESNT EXIST!!!!";
}
getch();
file5.close();
file6.close();

transfertransportdata1();                       //TO TRANSFER EDITED TRANSPORT RECORD
}

//FUNTION USED TO TRASFER EDITED TRANSPORT RECORDS.
void travelagency::transfertransportdata1()
{
fstream oldfile3,newfile3;
oldfile3.open("temp2.dat",ios::binary | ios::in);
newfile3.open("transport.dat",ios::binary | ios::out);
  while(oldfile3.read((char*)&user,sizeof(user)))
  newfile3.write((char*)&user,sizeof (user));
oldfile3.close();
newfile3.close();
}

//FUNTION USED TO MAKE TRANSPORT RECORD.
void exportrecordfile()
{
       fstream file;
       file.open("transport.dat",ios::binary | ios::out |ios::app);
       user1[i].toggle=1;
       user1[i].reserve();
       file.write((char*)&user1[i],sizeof (user1[i]));
       file.close();
}

//FUNTION USED TO DISPLAY INTRODUCTION SCREEN
void startup()
{
clrscr();
textcolor(GREEN );
for(int j=0;j<10;j++)
{
clrscr();
gotoxy(j,6); cputs("        ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
gotoxy(j,7); cputs("            ÜÜÜÜÜÜÜ ÜÜÜÜÜÜ ÜÜÜÜÜÜ");
gotoxy(j,8); cputs("               Û    Û    Û Û    Û");
gotoxy(j,9); cputs("               Û    ÛÜÜÜÛ  ÛÜÜÜÜÛ");
gotoxy(j,10);cputs("               Û    Û Û    Û    Û");
gotoxy(j,11);cputs("               Û    Û  ÛÛ  Û    Û");

gotoxy(51-j,6); cputs("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ \n\r");
gotoxy(51-j,7); cputs(" Ü    Ü ÜÜÜÜÜÜ Ü   \n\r");
gotoxy(51-j,8); cputs(" Û    Û Û      Û    \n\r");
gotoxy(51-j,9); cputs(" Û    Û ÛÜÜÜ   Û    \n\r");
gotoxy(51-j,10);cputs("  Û  Û  Û      Û    \n\r");
gotoxy(51-j,11);cputs("   ÛÛ   ÛÛÛÛÛÛ ÛÛÛÛ \n\r\n\n");

gotoxy(j,12);cputs("                          ÜÜÜÜÜÜÜ Ü    Ü");
gotoxy(j,13);cputs("                             Û    ÛÛ   Û");
gotoxy(j,14);cputs("                             Û    Û Û  Û");
gotoxy(j,15);cputs("                             Û    Û  Û Û");
gotoxy(j,16);cputs("                          ÜÜÜÛÜÜÜ Û   ÛÛ");
gotoxy(j,17);cputs("                     ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");

gotoxy(58-j,12);cputs(" ÜÜÜÜÜÜ ÜÜÜÜÜÜÜ ÜÜÜÜÜÜ \n\r");
gotoxy(58-j,13);cputs(" Û    Û    Û    Û    Û \n\r");
gotoxy(58-j,14);cputs(" Û    Û    Û    ÛÜÜÜÜÛ \n\r");
gotoxy(58-j,15);cputs(" Û    Û    Û    Û    Û \n\r");
gotoxy(58-j,16);cputs(" ÛÜÜÜÜÛ ÜÜÜÛÜÜÜ Û    Û \n\r");
gotoxy(58-j,17);cputs("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ \n\r");


}
gotoxy(25,25);
cout<<"press any key to continue...";
getch();
}
