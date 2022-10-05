#include<stdio.h>
#include<string.h>
struct passenger{
    char seat[5];
    char name[20];
    char address[30];
    char phone[15];
};
struct passenger p[60];
void newfile(){
    int j,s,i;
    char x[10][100];
    freopen("passenger.txt","w",stdout);
    for(i=0;i<15;i++){
        for(j=1;j<=4;j++){
            printf("%c%d\nNot Reserved \nNot Reserved \n00\n",'A'+i,j);
        }
    }
}
void memory(){
        int i;
        freopen("passenger.txt","r",stdin);
        for(i=0;i<60;i++){
            gets(p[i].seat);
            gets(p[i].name);
            gets(p[i].address);
            gets(p[i].phone);
        }
}
int main(){
    char t[5];
    int fflush(FILE *stream);
    int i,j,choice;
    printf("Welcome to Nufaer Bus Resevation Softwer!");
    printf("\n Do you want to continue your existing file?");
    printf("\n  type 123 to create a new file");
    printf("\n   or Press any key to continue to your existing file\n");
    scanf("%d",&choice);
    if(choice==123){
        newfile();
    }
    memory();
    //freopen("new.txt","r",stdin);
    //freopen("passenger.txt","w",stdout);
    printf("Enter the Seat number for Reservation:");
    scanf("%s",&t);
    getchar();
    fflush(stdout);
    fflush(stdin);
    gets(t[0]);
    printf("%s",&t);
    for(i=0;i<60;i++){
        if(t==p[i].seat){
            if(p[i].phone!=00){
                printf("Sorry, This Seat is already booked!");
            }
            else{
                gets(p[i].name);
                gets(p[i].address);
                gets(p[i].phone);
            }
        }
    }
    for(i=0;i<60;i++){
        printf("%s\n",p[i].seat);
        printf("%s\n",p[i].name);
        printf("%s\n",p[i].address);
        printf("%s\n",p[i].phone);
    }

    return 0;
}
