#include <stdio.h>
#include <stdlib.h>

struct vehicle_details
{
    char mnfctr[20];
    int mnfctr_year;
    char vname[20];
    char modelname[20];
    int vehicle_nmbr;
};
int main()
{
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
    printf(" Enter 2 to View Entrie(s) ");
    printf("\n Enter 3 to Search Entry\t||\t");
    printf(" Enter 4 to Edit Entry \n\n");
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
        break;
    default:
        printf("OOPS....WRONG CHOICE\n");
        getch();
        system("cls");
        main();
    }
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
        printf("ENTER MANUFACTURER          : ");
        scanf("%s",vehicles[i].mnfctr);

        printf("ENTER MANUFACTURING YEAR    : ");
        scanf("%d",&vehicles[i].mnfctr_year);

        printf("ENTER VEHICLE NAME          : ");
        scanf("%s",vehicles[i].vname);

        printf("ENTER MODEL NAME            : ");
        scanf("%s",vehicles[i].modelname);

        printf("ENTER VEHICLE NUMBER        : ");
        scanf("%d",&vehicles[i].vehicle_nmbr);

        printf("--------------------------------------------\n");

        fprintf(fptr,"MANUFACTURER          : %s  \n",vehicles[i].mnfctr);
        fprintf(fptr,"MANUFACTURING YEAR    : %i  \n",vehicles[i].mnfctr_year);
        fprintf(fptr,"VEHICLE NAME          : %s  \n",vehicles[i].vname);
        fprintf(fptr,"MODEL NAME            : %s  \n",vehicles[i].modelname);
        fprintf(fptr,"VEHICLE NUMBER        : %i  \n\n",vehicles[i].vehicle_nmbr);
    }
    printf("\n %i ENTRIE(S) ADDED.....",n);

    fclose(fptr);
    getch();
    system("cls");
    display_menu();
    choices();
}
void full_displ()
{
    char reader;

    FILE *fptr;

    fptr = fopen("database.txt","r");

    if (fptr == NULL)
    {
        printf("NO ENTRIES AVAILABLE....");
        exit(1);
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
    getch();
    system("cls");
    display_menu();
    choices();
}
