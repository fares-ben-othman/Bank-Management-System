#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
 FILE *file;
 void Menu(){
  printf("\n\t\t\t CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
  printf("\n \t\t\t\t WELCOME TO THE MAIN MENU ");
  printf("\n\n 1-Create new account");
  printf("\n 2-Update information of existing account");
  printf("\n 3-For transactions");
  printf("\n 4-Check the details of existing account");
  printf("\n 5-Removing existing account");
  printf("\n 6-View customer's informations");
  printf("\n 7-view list of customers");
  printf("\n 8-Exit");
  printf("\n\n\n    Enter your choice:");
 }
 void miniMenu(){
    printf("\n 1-deposit money");
    printf("\n 2-withrdraw money");
    printf("\n\n\n    Enter your choice:");  
}    
 int getNewAccountNumber(){
   int i=1; char chainei[20];
   while (1){
   char fileName [20]="AccountNbr";
   sprintf(chainei,"%d", i);
   strcat(fileName,chainei);
   strcat(fileName,".txt");
   FILE *file =fopen(fileName,"r");
   if (file == NULL) {return(i);
   break;}
   fclose(file);
   i+=1;
 }
 }
 int new_acc() {
    system("cls");
    char name[20], date[10], CIN[8], address[20], phone[8], amount[10], option[25];char nama[25];
	  int choice;
     char fileName[20]="AccountNbr";
     int i = getNewAccountNumber() ;
     char chainei[100];
     sprintf(chainei,"%d", i);
     strcat(fileName,chainei);
     strcat(fileName,".txt");
     FILE *file = fopen(fileName, "a");
     printf("Type the account name: \n");
     scanf("%s",nama);
     fprintf(file, "%s ",nama);
     printf("Type the customer's date of birth: \n");
     scanf("%s", date);
     fprintf(file, "%s ",date);
     printf("Type the customer's id: \n");
     scanf("%s",CIN);
     fprintf(file, "%s ",CIN);
     printf("Type the customer's address: \n");
     scanf("%s", address);
     fprintf(file, "%s ",address);
     printf("Type the customer's phone number: \n");
     scanf("%s",phone);
     fprintf(file, "%s ",phone);
     printf("Enter the amount of money to deposit (TND) : \n");
     scanf("%s", amount);
     fprintf(file, "%s ",amount);
     printf("Choose a type: \n 1-current \n 2-Saving \n 3-fixed for 1 year \n 4-fixed for 2 years \n 5-fixed for 3 years\n");
     scanf("%d",&choice);
     switch (choice) {
        case 1: strcpy(option, "current"); break;
        case 2: strcpy(option, "saving"); break;
        case 3: strcpy(option, "fixed for 1 year"); break;
        case 4: strcpy(option, "fixed for 2 years"); break;
        case 5: strcpy(option, "fixed for 3 years"); break;
        default: strcpy(option, "unknown"); break;
    }
    fprintf(file, "%s ",option);
    time_t t= time(NULL);
    struct tm temps = *localtime(&t);
    int année =temps.tm_year+1900;
    int mois =temps.tm_mon +1;
    int jour= temps.tm_mday;
    int heure=temps.tm_hour;
    int minutes=temps.tm_min;
    char date_of_deposite[200];
    sprintf(date_of_deposite," %d-%02d-%02d %02d:%02d", temps.tm_year + 1900, temps.tm_mon + 1, temps.tm_mday, temps.tm_hour, temps.tm_min);
    fprintf(file,"%s",date_of_deposite);
    printf("Your account number is %d",i);
    fclose(file);
    return 0;
} 
 void view_list() {
   printf("type the account number :");
   int accountNumber;
   scanf("%d", &accountNumber);
   char fileName[20]="AccountNbr";
   char strAccountNumber[20];
   sprintf(strAccountNumber,"%d", accountNumber);
   strcat(fileName,strAccountNumber);
   strcat(fileName,".txt");
   FILE *file = fopen(fileName,"r");
   if (file == NULL)
   {
    printf("this account does not exist");}
    else {
      char data [255];
      fgets(data,255,file);
      char name[25];char date[10];char CIN[8]; char address[30];char phone[20];char amount[10];char option[20];
      sscanf(data,"%s %s %s %s %s %s %s ",name,date,CIN,address,phone,amount,option);
      sscanf(data,"%s",name);
      fclose(file);
      printf("\nthe customer's name is %s ",name);
      printf("\nthe customer's address is %s",address);
      printf("\nthe customer's phone number is %s",phone);
    }
   }
 void see() {
   printf("type the account number :");
   int accountNumber;
   scanf("%d", &accountNumber);
   char fileName[20]="AccountNbr";
   char strAccountNumber[20];
   sprintf(strAccountNumber,"%d", accountNumber);
   strcat(fileName,strAccountNumber);
   strcat(fileName,".txt");
   FILE *file = fopen(fileName,"r");
   if (file == NULL)
   {
    printf("this account does not exist");}
    else {
      char data [255];
      fgets(data,255,file);
      char nom[25];char CIN[8];char address[30];char phone[20];char amount[10];char option[20];
      char date_of_deposit[20];char hour_of_deposit[8];char date[15];
      sscanf(data,"%s",nom);
      printf("\nthe customer's name is %s",nom);
      sscanf(data," %s %s %s %s %s %s %s %s %s ",nom,date,CIN,address,phone,amount,option,date_of_deposit,hour_of_deposit);
      fclose(file);
      char année[6];
        for (int i=7;i<11;i++){
          année[i-7]=date[i];
        }
      int x=atoi(année);/* atoi pour convertir la chaine en entier*/
      time_t t= time(NULL);
      struct tm temps = *localtime(&t);
      int year =temps.tm_year+1900;
      int age;
      age =year-x-2000;
      printf("\nthe customer's date of birth is %s",date);
      printf("\nthe customer's citizenship number is %s",CIN);
      printf("\nthe customer's age is %d",age);
      printf("\nthe customer's address is %s",address);
      printf("\nthe customer's phone number is %s",phone);
      printf("\nthe type of account is %s",option);
      printf("\nthe amount deposited are %s",amount);
      printf("\nthe date of deposit is %s %s",date_of_deposit,hour_of_deposit);
    }
   
}
 void edit(){
   int accountNumber;
   printf("\nthe account number:");
   scanf("%d",&accountNumber);
   char fileName [20]="AccountNbr";
   char strAccountnumber[20];
   sprintf(strAccountnumber,"%d", accountNumber);
   strcat(fileName,strAccountnumber);
   strcat(fileName,".txt");
   FILE *file1 = fopen(fileName,"r");
   if (file1 == NULL)
   {
    printf("\nthis account does not exist");}
    else {
      printf("\ntype the new address :");
      char address2[30];
      scanf("%s",address2);
      printf("\ntype the new phone number :");
      char phone2[20];
      scanf("%s",phone2);
      char data [255];
      fgets(data,sizeof(data),file1);
      char nom[25];char CIN[8];char address[30];char phone[20];char amount[10];char option[20];
      char date_of_deposit[20];char hour_of_deposit[8];char date[15];char nama[25];
      sscanf(data," %s %s %s %s %s %s %s %s %s ",nama,date,CIN,address,phone,amount,option,date_of_deposit,hour_of_deposit);
      fclose(file1); 
    FILE *file3 = fopen(fileName,"w");
    fprintf(file3,"%s",nama);
    fprintf(file3," %s %s ",date,CIN);
    fprintf(file3,"%s %s %s ",address2,phone2,amount);
    fprintf(file3,"%s %s %s\n",option,date_of_deposit,hour_of_deposit);
    fclose(file3);};
      }
 void deposite(char fileName[]) {
  printf("\n Enter the amount of money to deposit (TND) : ");
  char STRamount2[10];
  scanf("%s",STRamount2);
  FILE *file1 = fopen(fileName,"r");
  char data [255];
      fgets(data,sizeof(data),file1);
      char nom[25];char CIN[8];char address[30];char phone[20];char STRamount1[10];char option[20];
      char date_of_deposit[20];char hour_of_deposit[8];char date[15];char nama[25];
      sscanf(data," %s %s %s %s %s %s %s %s %s ",nama,date,CIN,address,phone,STRamount1,option,date_of_deposit,hour_of_deposit);
      fclose(file1); 
      int amount1 =atoi(STRamount1);
      int amount2 =atoi(STRamount2);
      int amount= amount1+amount2;
      time_t t1= time(NULL);
      struct tm temps = *localtime(&t1);
      int année =temps.tm_year+1900;
      int mois =temps.tm_mon +1;
      int jour= temps.tm_mday;
      int heure=temps.tm_hour;
      int minutes=temps.tm_min; 
      char date_of_deposite2[200];
      sprintf(date_of_deposite2," %d-%02d-%02d %02d:%02d", temps.tm_year + 1900, temps.tm_mon + 1, temps.tm_mday, temps.tm_hour, temps.tm_min);
      FILE *file3 = fopen(fileName,"w");
      printf("%s %s\n",option,date_of_deposite2);
      fprintf(file3,"%s",nama);
      fprintf(file3," %s %s ",date,CIN);
      fprintf(file3,"%s %s %d ",address,phone,amount);
      fprintf(file3,"%s %s\n",option,date_of_deposite2);
      fclose(file3);}
 void withdraw(char fileName[]){
   printf("\n Enter the amount of money to withdraw (TND) : ");
  char STRamount2[10];
  scanf("%s",STRamount2);
  FILE *file1 = fopen(fileName,"r");
  char data [255];
      fgets(data,sizeof(data),file1);
      char nom[25];char CIN[8];char address[30];char phone[20];char STRamount1[10];char option[20];
      char date_of_deposit[20];char hour_of_deposit[8];char date[15];char nama[25];
      sscanf(data," %s %s %s %s %s %s %s %s %s ",nama,date,CIN,address,phone,STRamount1,option,date_of_deposit,hour_of_deposit);
      fclose(file1); 
      int amount1 =atoi(STRamount1);
      int amount2 =atoi(STRamount2);
      int amount= amount1-amount2;
      time_t t1= time(NULL);
      struct tm temps = *localtime(&t1);
      int année =temps.tm_year+1900;
      int mois =temps.tm_mon +1;
      int jour= temps.tm_mday;
      int heure=temps.tm_hour;
      int minutes=temps.tm_min; 
      char date_of_deposite2[200];
      sprintf(date_of_deposite2," %d-%02d-%02d %02d:%02d", temps.tm_year + 1900, temps.tm_mon + 1, temps.tm_mday, temps.tm_hour, temps.tm_min);
      FILE *file3 = fopen(fileName,"w");
      printf("%s %s\n",option,date_of_deposite2);
      fprintf(file3,"%s",nama);
      fprintf(file3," %s %s ",date,CIN);
      fprintf(file3,"%s %s %d ",address,phone,amount);
      fprintf(file3,"%s %s\n",option,date_of_deposite2);
      fclose(file3);}
 void transact() {
   int accountNumber;
   printf("\nthe account number:");
   scanf("%d",&accountNumber);
   char fileName [20]="AccountNbr";
   char strAccountnumber[20];
   sprintf(strAccountnumber,"%d", accountNumber);
   strcat(fileName,strAccountnumber);
   strcat(fileName,".txt");
    miniMenu :
    miniMenu();
    int choice;
    scanf("%d",&choice); 
    switch (choice)
    { 
    case 1:
      deposite(fileName);
      break;
    case 2:
      withdraw(fileName);
      break;
    default:
      printf("please enter a valid choice !");
      goto miniMenu ;
      break;
    }
}
 void erase() {
   printf("type the account number :");
   int accountNumber;
   scanf("%d", &accountNumber);
   char fileName[20]="AccountNbr";
   char strAccountNumber[20];
   sprintf(strAccountNumber,"%d", accountNumber);
   strcat(fileName,strAccountNumber);
   strcat(fileName,".txt");
   int r =remove(fileName);
 }
 void list_of_customers(){
  printf("\t\t\tCustomers list :\n\n");
  for (int i = 1; i < 100; i++)
  {char fileName[20]="AccountNbr";
  char nom[25];char CIN[8];char address[30];char phone[20];char amount[10];char option[20];
  char date_of_deposit[20];char hour_of_deposit[8];char date[15];char nama[25];
  char chainei[100];char data [255];
   sprintf(chainei,"%d", i);
     strcat(fileName,chainei);
     strcat(fileName,".txt");
     FILE *file = fopen(fileName, "r");
     if (file!=NULL)
     {
      fgets(data,sizeof(data),file);
     sscanf(data," %s %s %s %s %s %s %s %s %s ",nama,date,CIN,address,phone,amount,option,date_of_deposit,hour_of_deposit);
     printf("%d ",i);
     printf("%s\n",data);
     fclose(file);
  }
  }
 }
 int main(){
  Menu :
   Menu();
   int choice;
   scanf("%d",&choice);
   switch (choice)
   {
    case 1:
      new_acc() ; 
      goto Menu ; 
    case 2:
      edit() ; 
      goto Menu ; 
    case 3:
      transact() ; 
      goto Menu ; 
    case 4:
      see() ;
     goto Menu ;  
    case 5:
      erase() ;
     goto Menu ;  
    case 6:
      view_list() ;  
    goto Menu ;
    case 7:
      list_of_customers()  ;
      goto Menu ;
    case 8:
      return 0;  
  default:
     printf("please enter a valid choice !");
     goto Menu;
  }
  return 0;
}