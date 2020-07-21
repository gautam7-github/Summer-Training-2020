#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

//functions
void display_menu();
int choices();
void add();
void full_displ();
void delete_ent();
void exitprog();
//structure containing all details for vehicle sales
struct vehicle_details
{
    //vehicle details
    char mnfctr[20];
    unsigned int mnfctr_year;
    char vname[20];
    char modelname[20];
    unsigned int vehicle_nmbr;
    unsigned int engine_cc;
    char drive_sys[5];
    //buyer details
    char buyer_name[30];
    char buyer_contact[11];
    char buyer_address[100];
}vehicles[8];

int n;

int main()
{
    system("COLOR 2");
    while(1)
    {
        system("cls");
        display_menu();
        choices();
    }
    return EXIT_SUCCESS;
}
void display_menu()
{
    printf("\t\t\t\t\t");
    printf(" |------------|\n");
    printf("\t\t\t\t\t");
    printf(" | TNA MOTORS |\n");
    printf("\t\t\t\t\t");
    printf(" |  BATHINDA  |\n");
    printf("\t\t\t\t\t");
    printf(" |------------|\n");

    printf("\t\t\t\t");
    printf("      | DATABASE MANAGER |\n");
}
int choices()
{
    int choice;

    printf("\n\n\n");
    printf("\t\t\t\t-----------------------------------\n");
    printf("\t\t\t\t  ||\t1. ADD ENTRY    \t||\n");
    printf("\t\t\t\t  ||\t2. VIEW RECORD  \t||\n");
    printf("\t\t\t\t  ||\t3. DELETE RECORD\t||\n");
    printf("\t\t\t\t  ||\t4. EXIT MANAGER \t||\n");
    printf("\t\t\t\t-----------------------------------\n");
    printf(" ENTER YOUR DESIRED CHOICE: ");
    scanf("%i",&choice);

    switch(choice)
    {
    case 1:
        add();
        break;
    case 2:
        full_displ();
        break;
    case 3:
        delete_ent();
        break;
    case 4:
        exitprog();
        break;
    default:
        printf(" OOPS....WRONG CHOICE\n");
        printf("PRESS ENTER TO RETRY....\n");
        getch();
        system("cls");
    }
    return 0;
}
void add()
{
    int i;

    time_t now;
    time(&now);

    printf("\t\t\t||  ADD ENTRY  ||\n\n");
    printf("HOW MANY ENTRIES DO YOU WANT TO ADD? : ");
    scanf("%i",&n);

    if (n<=0)
    {
        printf("PLEASE ENTER VALID NUMBER....");
    }
    else
    {
        if(n>7)
        {
            printf("NUMBER OF ENTRIES IS MORE THAN 7\n");
            printf("YOU WILL NOT BE ABLE TO USE EDIT OPTION\n");
            printf("CONFIRM BY PRESSING y : ");
            Sleep(2000);
            char a = getch();

            if(a == 'y')
            {
                struct vehicle_details vehicles[n];
            }
            else
            {
                exit(0);
            }
        }
    }
    system("cls");

    FILE *fptr;

    fptr = fopen("database-short.txt","a+");

    printf("\t\t\t|||  MAIN MENU --> ADD ENTRY  |||\n");
    for(i=0;i<n;i++)
    {
        printf("\t____________________________\n");
        printf("\t\tVEHICLE %d\n\n",i+1);
        printf("DATE & TIME : %s\n",ctime(&now));
        printf("VEHICLE DETAILS\n\n");
        printf("ENTER MANUFACTURER          : ");
        scanf("%s",vehicles[i].mnfctr);

        printf("ENTER MANUFACTURING YEAR    : ");
        scanf("%u",&vehicles[i].mnfctr_year);

        printf("ENTER VEHICLE NAME          : ");
        scanf("%s",vehicles[i].vname);

        printf("ENTER MODEL NAME            : ");
        scanf("%s",vehicles[i].modelname);

        printf("ENTER VEHICLE NUMBER        : ");
        scanf("%u",&vehicles[i].vehicle_nmbr);

        printf("ENTER ENGINE POWER IN CC    : ");
        scanf("%u",&vehicles[i].engine_cc);

        printf("ENTER TRANSMISSION STYLE    : ");
        scanf("%s",&vehicles[i].drive_sys);

        printf("\nBUYER DETAILS\n");

        printf("ENTER BUYER NAME            : ");
        scanf("%s",vehicles[i].buyer_name);

        printf("ENTER BUYER CONTACT         : ");
        scanf("%s",vehicles[i].buyer_contact);
        fflush(stdin);

        printf("ENTER BUYER ADDRESS         : ");
        fgets(vehicles[i].buyer_address, 100, stdin);


        printf("--------------------------------------------\n");

        //writing to file database-short.txt with file handler fptr
        fprintf(fptr,"--------------------------------------------\n");
        fprintf(fptr,"%s\n",ctime(&now));
        fprintf(fptr,"VEHICLE DETAILS\n");
        fprintf(fptr,"MANUFACTURER          : %s\n",vehicles[i].mnfctr);
        fprintf(fptr,"MANUFACTURING YEAR    : %u\n",vehicles[i].mnfctr_year);
        fprintf(fptr,"VEHICLE NAME          : %s\n",vehicles[i].vname);
        fprintf(fptr,"MODEL NAME            : %s\n",vehicles[i].modelname);
        fprintf(fptr,"VEHICLE NUMBER        : %u\n",vehicles[i].vehicle_nmbr);
        fprintf(fptr,"ENGINE CC             : %u\n",vehicles[i].engine_cc);
        fprintf(fptr,"BUYER DETAILS\n");
        fprintf(fptr,"BUYER NAME            : %s\n",vehicles[i].buyer_name);
        fprintf(fptr,"BUYER CONTACT         : %s\n",vehicles[i].buyer_contact);
        fprintf(fptr,"BUYER ADDRESS         : %s\n",vehicles[i].buyer_address);
        fprintf(fptr,"--------------------------------------------\n");

    }
    fflush(stdin);
    printf("\n %i ENTRIE(S) ADDED.....",n);

    fclose(fptr);

    getch();
    system("cls");
}
void full_displ()
{
    system("cls");
    char reader,str[60];

    printf("\n\t\t\t|||  MAIN MENU --> VIEW ALL ENTRIES  |||\n\n");
    printf(" READING FILE......\n\n");
    Sleep(1000);
    FILE *fptr;
    fptr = fopen("database-short.txt","r");

    if (fptr == NULL)
    {
        printf(" FILE ERROR....");
        Sleep(2000);
        printf(" CONTACT IT DEPARTMENT....");
        exit(1);
    }
    else
    {
        if (fgets(str,60,fptr)==NULL)
        {
            printf(" NO ENTRIES AVAILABLE.....");
            getch();
            system("cls");
            main();
        }
        else
        {
            while(!feof(fptr))
            {
                reader = fgetc(fptr);
                printf("%c",reader);
            }
        fclose(fptr);
        }
    }
    getch();
    system("cls");
}
void delete_ent()
{
    char pass[10];
    char defapass[6] = "12345";
    printf("ENTER PASSWORD: ");
    scanf("%s",pass);

    if ((strcmp(defapass,pass))!=0)
    {
        printf("WRONG PASSWORD....\n");
    }
    else
    {
        FILE *fptr;
        fptr = fopen("database-short.txt","w");
        printf("ALL ENTRIES DELETED....\n");
        fclose(fptr);
    }
    getch();
    system("cls");
}
void exitprog()
{
    printf("ARE YOU SURE ? ");
    printf("y/n\n");
    char c = getche();
    if(c == 'y')
    {
        printf("\t\t\t\t\tGOODBYE.....");
        exit(EXIT_SUCCESS);
    }
    else if(c != 'n')
    {
        printf("RETRY\n");
        Sleep(1000);
        exitprog();
    }
    else
    {
        printf("\nGOOD CHOICE.....");
        Sleep(1000);
    }
}
