#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//functions
void display_menu();
int choices();
void add();
void full_displ();
void delete_ent();
void edit();

//structure containing all details for vehicle sales
struct vehicle_details
{
    char mnfctr[20];
    unsigned int mnfctr_year;
    char vname[20];
    char modelname[20];
    unsigned int vehicle_nmbr;
    char buyer_name[30];
    char buyer_contact[10];
    char buyer_address[100];
    char drive_sys[4];
    unsigned int engine_cc;
}vehicles[7];

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
    printf("\t\t\t\t  ||\t3. EDIT RECORD  \t||\n");
    printf("\t\t\t\t  ||\t4. DELETE RECORD\t||\n");
    printf("\t\t\t\t  ||\t5. EXIT MANAGER \t||\n");
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
        edit();
        break;
    case 4:
        delete_ent();
        break;
    case 5:
        system("cls");
        printf("\n\t\t\t\t\t EXITING");
        Sleep(1000);
        exit(EXIT_SUCCESS);
    default:
        printf("OOPS....WRONG CHOICE\n");
        break;
        getch();
        system("cls");
    }
    return 0;
}
void add()
{
    int i;

    printf("\t\t\t||  ADD ENTRY  ||\n\n");
    printf("HOW MANY ENTRIES DO YOU WANT TO ADD? : ");
    scanf("%i",&n);

    if (n<=0)
    {
        printf("PLEASE ENTER VALID NUMBER....");
        return 0;
    }

    system("cls");

    FILE *fptr;

    fptr = fopen("database.txt","a+");

    for(i=0;i<n;i++)
    {
        printf("\t\tVEHICLE %d\n\n",i+1);
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

        printf("ENTER BUYER NAME            : ");
        scanf("%s",vehicles[i].buyer_name);

        printf("ENTER BUYER CONTACT         : ");
        scanf("%s",vehicles[i].buyer_contact);

        printf("--------------------------------------------\n");

        //writing to file database.txt with file handler fptr
        fprintf(fptr,"--------------------------------------------\n");
        fprintf(fptr,"MANUFACTURER          : %s\n",vehicles[i].mnfctr);
        fprintf(fptr,"MANUFACTURING YEAR    : %u\n",vehicles[i].mnfctr_year);
        fprintf(fptr,"VEHICLE NAME          : %s\n",vehicles[i].vname);
        fprintf(fptr,"MODEL NAME            : %s\n",vehicles[i].modelname);
        fprintf(fptr,"VEHICLE NUMBER        : %u\n",vehicles[i].vehicle_nmbr);
        fprintf(fptr,"BUYER NAME            : %s\n",vehicles[i].buyer_name);
        fprintf(fptr,"BUYER CONTACT         : %s\n",vehicles[i].buyer_contact);
        fprintf(fptr,"--------------------------------------------\n");

    }
    printf("\n %i ENTRIE(S) ADDED.....",n);

    fclose(fptr);

    getch();
    system("cls");
    //main();
}
void full_displ()
{
    system("cls");
    char reader,str[60];

    FILE *fptr;

    fptr = fopen("database.txt","r");

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
    system("cls");
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
        fptr = fopen("database.txt","w");
        printf("ALL ENTRIES DELETED....\n");
        fclose(fptr);
    }
    getch();
    system("cls");
}
void edit()
{
    system("cls");
    puts("\t\t\tEDITOR");

    printf("YOUR ENTRIES ARE : \n\n");

    for(int i=0;i<n;i++)
    {
        printf("ENTRY %d\n",i+1);
        printf("1. MANUFACTURER          : %s\n",vehicles[i].mnfctr);
        printf("2. MANUFACTURING YEAR    : %u\n",vehicles[i].mnfctr_year);
        printf("3. VEHICLE NAME          : %s\n",vehicles[i].vname);
        printf("4. MODEL NAME            : %s\n",vehicles[i].modelname);
        printf("5. VEHICLE NUMBER        : %u\n",vehicles[i].vehicle_nmbr);
        printf("6. BUYER NAME            : %s\n",vehicles[i].buyer_name);
        printf("7. BUYER CONTACT         : %s\n",vehicles[i].buyer_contact);
    }
    printf("WHAT DO YOU WANT TO EDIT : ");
    scanf("%i",&editor);

    switch(editor)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        printf("ENTER ACCORDING TO NUMBER.....\n");
    }
    getch();
    system("cls");
}
