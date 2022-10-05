#include<stdio.h>
#include<string.h>
struct passenger{
    char seat[5];
    char name[20];
    char address[30];
    char phone[15];
};
int newfile(int i){
    int j,s;
    char x[10][100];
    freopen("passenger.txt","w",stdout);
    for(i=0;i<15;i++){
        for(j=1;j<=4;j++){
            printf("%c%d\nNot Reserved \nNot Reserved \n00\n",'A'+i,j);
        }
    }
    return 0;
}
int memory(struct passenger p[60]){
        int i;
        freopen("passenger.txt","r",stdin);
        for(i=0;i<60;i++){
            gets(p[i].seat);
            gets(p[i].name);
            gets(p[i].address);
            gets(p[i].phone);
        }
        return 0;
}
int main(){
    char t[5],choice[5];
    struct passenger p[60];
    int i,j;
    printf("Welcome to Nufaer Bus Resevation Softwer!");
    printf("\n Do you want to continue your existing file?");
    printf("\n  type 0123 to create a new file");
    printf("\n   or Press any key to continue to your existing file\n");
    scanf("%s",choice);
    if(choice==0123){
        j=newfile(i);
    }
    else{
        i=memory(p);
    }
    //freopen("new.txt","r",stdin);
    //freopen("passenger.txt","w",stdout);
    //printf("Enter the Seat number for Reservation:");
    scanf("%s",t);
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
