#include<stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
using namespace std;

struct BusDetail
{
int busNumber;
string busName;
string driverName;
string departure;
string arrival;
string sourceRoot;
string destinationRoot;
};

class Bus
{
private:
BusDetail *busDetail;
int size;
int currentBus;

public:
Bus(int s)
{
currentBus = -1;
size = s;
busDetail = new BusDetail[size];
}

int searchBusByNumber(int busNumber)
{
for(int i = 0;i <= currentBus;i++)
{
if(busDetail[i].busNumber == busNumber)
{
return i;
}
}
return -1;
}

void addNewBus(BusDetail newBus)
{
if(currentBus < size-1)
{
while(searchBusByNumber(newBus.busNumber) != -1)
{
cout << “This bus number already exist” << endl << “Please re-enter bus number: “; cin >> newBus.busNumber;
}

currentBus++;
busDetail[currentBus].busNumber = newBus.busNumber;
busDetail[currentBus].busName = newBus.busName;
busDetail[currentBus].driverName = newBus.driverName;
busDetail[currentBus].departure = newBus.departure;
busDetail[currentBus].arrival = newBus.arrival;
busDetail[currentBus].sourceRoot = newBus.sourceRoot;
busDetail[currentBus].destinationRoot = newBus.destinationRoot;

}

else
{
cout << “buses are full” << endl;
}
}

void displayAllBuses()
{
if(currentBus != -1)
{
for(int i = 0;i <= currentBus;i++)
{
cout << “Bus number: ” << busDetail[i].busNumber << endl;
cout << “Bus name: ” << busDetail[i].busName << endl;
cout << “Driver name: ” << busDetail[i].driverName << endl;
cout << “Bus departure time: ” << busDetail[i].departure << endl;
cout << “Bus arrival time: ” << busDetail[i].arrival << endl;
cout << “Source root: ” << busDetail[i].sourceRoot << endl;
cout << “Destination: ” << busDetail[i].destinationRoot << endl << endl;
}
}
else
{
cout << “Not bus found” << endl;
}

}

void deleteBus(int busNumber){
int index = searchBusByNumber(busNumber);

if(index != -1)
{

for(int i = index;i < currentBus;i++){
busDetail[i] = busDetail[i+1];
}
currentBus–;
cout << “Bus successfully deleted” << endl;
}

else
{

cout << “Cannot delete because bus not found” << endl;
}
}

void updateBus(BusDetail obj){

int index = searchBusByNumber(obj.busNumber);
if(index != -1)
{
busDetail[index] = obj;

cout << “Record updated” << endl;
}
else
{
cout << “Record not updated” << endl;
}
}
};

void getInputFromUser(Bus &bus, string inputType)
{
int busNumber;

if(inputType == “delete”)
{
cout << “Enter bus number that you want to delete: “; cin >> busNumber;
bus.deleteBus(busNumber);
}
else if(inputType == “search”)
{
cout << “Enter bus number that you want to search: “; cin >> busNumber;

if(bus.searchBusByNumber(busNumber) == -1)
{
cout << “Bus not found” << endl;
}
else
{
cout << “Bus found” << endl;
}
}
else if(inputType == “display”)
{
bus.displayAllBuses();
}
else
{
BusDetail busDetail;

cout << “Enter bus name: “; cin >> busDetail.busName;

cout << “Enter driver name: “; cin >> busDetail.driverName;

cout << “Enter departure time hint (02:20pm): “; cin >> busDetail.departure;

cout << “Enter arrival time hint (02:20pm): “; cin >> busDetail.arrival;

cout << “Enter source root: “; cin >> busDetail.sourceRoot;

cout << “Enter destination root: “; cin >> busDetail.destinationRoot;

if(inputType == “add”)
{
cout << “Enter bus number: “; cin >> busDetail.busNumber;

bus.addNewBus(busDetail);
}
else
{
cout << “Enter bus number that you want to update: “; cin >> busDetail.busNumber;
bus.updateBus(busDetail);
}
}
}

void mainMenu()
{
int choice = -1;
int size;
int busNumber;

cout << “Enter total number of buses you want to add: “; cin >> size;

Bus bus(size);

while(choice != 0)
{
system(“cls”);
cout << “\n\n\t\t\t______________________”;
cout << “\n\n\t\t\tBUS RESERVATION SYSTEM”;
cout << “\n\n\t\t\t______________________\n”;
cout << “\n\n\t1. To addNewBus”;
cout << “\n\t\t2. ToShowBuses”;
cout << “\n\t\t3. To.searchBusByNumber(int busNumber)”;
cout << “\n\t\t4. To delete any bus”;
cout << “\n\t\t5. To update”;
cout << “\n\t\t0. To Exit”;
cout << “\n\n\n\tEnter your choice as(1/2/3/4/5):-\t”; cin >> choice;

switch(choice)
{

case 1 :
getInputFromUser(bus,”add”);
break;

case 2:
getInputFromUser(bus,”display”);
break;

case 3:
getInputFromUser(bus,”search”);
// bus.searchBusByNumber();
break;

case 4:
getInputFromUser(bus,”delete”);
break;

case 5:
getInputFromUser(bus,”update”);
break;

case 6: //exit(0);
cout<<“exit program “;

}

cout << “Press any key to continue…….. “;
getch();
}
}

int main()
{
mainMenu();
return 0;
}
