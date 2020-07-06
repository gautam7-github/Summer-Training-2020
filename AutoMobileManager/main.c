#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//functions
void display_menu();
int choices();
void add();
void full_displ();
void delete();

struct vehicle_details
{
    char mnfctr[20];
    int mnfctr_year;
    char vname[20];
    char modelname[20];
    unsigned int vehicle_nmbr;
    char buyer_name[30];
    int buyer_contact[10];
    char buyer_address[100];

};
int main()
{
    system("COLOR 2");
    display_menu();
    choices();
    return EXIT_SUCCESS;
}
void display_menu()
{
    printf("\t\t\t");
    printf(" |------------|\n");
    printf("\t\t\t");
    printf(" | TNA MOTORS |\n");
    printf("\t\t\t");
    printf(" |  BATHINDA  |\n");
    printf("\t\t\t");
    printf(" |------------|\n");
}
int choices()
{

    int choice;
    printf("\n Enter 1 to Add Entry\t\t||\t");
    printf(" Enter 2 to View Full Record ");
    printf("\n Enter 3 to Search Entry\t||\t");
    printf(" Enter 4 to Delete All \n");
    printf(" Enter 5 to Exit Program    \t||\n\n");
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
        break;
    case 4:
        delete();
        break;
    case 5:
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
    int i,n;
    printf("HOW MANY ENTRIES DO YOU WANT TO ADD? : ");
    scanf("%i",&n);

    struct vehicle_details vehicles[n];

    FILE *fptr;

    fptr = fopen("database.txt","a+");

    for(i=0;i<n;i++)
    {
        printf("\t\tVEHICLE %d\n\n",i+1);
        printf("ENTER MANUFACTURER          : ");
        scanf("%s",vehicles[i].mnfctr);

        printf("ENTER MANUFACTURING YEAR    : ");
        scanf("%d",&vehicles[i].mnfctr_year);

        printf("ENTER VEHICLE NAME          : ");
        scanf("%s",vehicles[i].vname);

        printf("ENTER MODEL NAME            : ");
        scanf("%s",vehicles[i].modelname);

        printf("ENTER VEHICLE NUMBER        : ");
        scanf("%ud",&vehicles[i].vehicle_nmbr);

        printf("ENTER BUYER NAME            : ");
        scanf("%s",vehicles[i].buyer_name);

        printf("ENTER BUYER CONTACT         : ");
        for(int k=0;k<10;k++)
        {
            scanf("%i",&vehicles[i].buyer_contact[k]);
        }

        printf("--------------------------------------------\n");

        fprintf(fptr,"\tVEHICLE %i\n",i+1);
        fprintf(fptr,"MANUFACTURER          : %s  \n",vehicles[i].mnfctr);
        fprintf(fptr,"MANUFACTURING YEAR    : %i  \n",vehicles[i].mnfctr_year);
        fprintf(fptr,"VEHICLE NAME          : %s  \n",vehicles[i].vname);
        fprintf(fptr,"MODEL NAME            : %s  \n",vehicles[i].modelname);
        fprintf(fptr,"VEHICLE NUMBER        : %ud \n",vehicles[i].vehicle_nmbr);
        fprintf(fptr,"BUYER NAME            : %s  \n",vehicles[i].buyer_name);
        fprintf(fptr,"BUYER CONTACT         : ");
        for(int k=0;k<10;k++)
           {
               fprintf(fptr,"%d",vehicles[i].buyer_contact[k]);
           }
        fprintf(fptr,"\n\n");

    }
    printf("\n %i ENTRIE(S) ADDED.....",n);

    fclose(fptr);

    getch();
    system("cls");
    main();
}
void full_displ()
{
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
    display_menu();
    choices();
}
void delete()
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
        fptr = fopen("database.txt","w");
        printf("ALL ENTRIES DELETED....\n");
        fclose(fptr);
    }
    getch();
    system("cls");
    display_menu();
    choices();
}
