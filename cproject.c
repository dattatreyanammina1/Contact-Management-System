#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
#include <dos.h>
struct contact
{
    long ph;
    char name[20], add[20], email[30];
}list;
    char query[20], name[20];
    FILE *fp, *ft;
    int i, n, ch,a,l, found;
void main()
{
    main:
    system("cls");
    printf("\n\t ** Welcome to Contact Management System **");
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1]Press 1 to Add a new Contact\n\t\t[2]Press 2 to  List all Contacts\n\t\t[3]Press 3 to Search for contact\n\t\t[4]Press 4 to Edit a Contact\n\t\t[5]Press 5 to Delete a Contact\n\t\t[6]Press 6 to Exit from Menu\n\t\t=================\n\t\t");
    printf("Enter the choice:");
    scanf("%d", &ch);
switch (ch)
   {
    case (6):
                printf("\n\n\t\tAre you sure you want to exit?");
                break;
    case (1):
                system("cls");
                fp = fopen("contact.dll", "a");
        for (;;)
        {       fflush(stdin);
                printf("(If want to exit use and spae and enter)\nName:");            scanf("%c", &list.name);
                if (stricmp(list.name, "")==0 || stricmp(list.name, " ")==0)
                break;
                fflush(stdin);
                printf("Phone Number:");
                scanf("%ld", &list.ph);
                fflush(stdin);
                printf("Address:");
                scanf("%c",&list.add);
                fflush(stdin);
                printf("Email address:");
                gets(list.email);
                printf("\n");
                fwrite(&list, sizeof(list), 1, fp);
        }       fclose(fp);
                break;
    case(2):
                system("cls");
                printf("\n\t\t============================\n\t\t\tLIST OF CONTACTS\n\t\t===========================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n====================================\n\n");
        for (i = 97; i <= 122; i++)
           {
                fp = fopen("contact.dll", "r");
                fflush(stdin);
                found = 0;
        while (fread(&list, sizeof(list), 1, fp) == 1)
            {
              if (list.name[0] == i || list.name[0] == i - 32)
                {
                printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n", list.name,list.ph, list.add, list.email);
                found++;
                }
            }
                if (found != 0)
            {   printf("======================================= [%c]-(%d)\n\n", i - 32, found);
                getch();
            }
                fclose(fp);
            }
                break;
    case(3):
                system("cls");
        do{
                found = 0;
                printf("\n\n\tCONTACT SEARCH\n\t===========================\n\tName of contact to search: ");
                fflush(stdin);
                scanf("%c[^\n]", &query);
                l = strlen(query);
                fp = fopen("contact.dll", "r");
                system("cls");
                printf("\n\nSearch result for '%s' \n===============================================\n", query);
        while (fread(&list, sizeof(list), 1, fp) == 1)
            {
        for (i = 0; i <= l; i++)
                name[i] = list.name[i];
                name[l] = '\0';
                if (stricmp(name, query) == 0)
                  {
                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n", list.name, list.ph, list.add, list.email);
                    found = found + 1;
                    if(found % 4 == 0)
                    {
                        printf("Press any key to continue!");
                        getch();                    }
                  }
            }   if (found == 0)
                printf("\nNo match found!");
                else
                printf("\n%d match(s) found!", found);
                fclose(fp);
                printf("\n Try again?\n\n\t[1] No\t\t[2] To Exit\n\t");
                scanf("%d", &ch);
          } while (ch == 1);
                break;
    case (4):
        system("cls");
        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        printf("Edit contact\n \nEnter the name of contact to edit:");
        scanf("%c",&list.  name);
        while(fread(&list,sizeof(list),1,fp)==1){
            if(stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);}
        printf("\n\n..::Editing '%s'\n\n",name);
        printf("..::Name(Use identical):");
        scanf("%[^\n]",&list.name);
        fflush(stdin);
        printf("..::Phone:");
        scanf("%ld",&list.ph);
        fflush(stdin);
        printf("..::address:");
        scanf("%[^\n]",&list.add);
        fflush(stdin);
        printf("..::email address:");
        gets(list.email);
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;
    case (5):
                system("cls");
                fflush(stdin);
                printf("\n\n\tDELETE A CONTACT\n\t==========================\n\tEnter the name of contact to delete:");
                scanf("%c[^\n]", &name);
                fp = fopen("contact.dll", "r");
                ft = fopen("temp.dat", "w");
        while (fread(&list, sizeof(list), 1, fp) != 0)
                if (stricmp(name, list.name) != 0)
                fwrite(&list, sizeof(list), 1, ft);
                fclose(fp);
                fclose(ft);
                remove("contact.dll");
                rename("temp.dat", "contact.dll");
                printf("Deleted Successfully");
                break;
     default:
                printf("Invalid choice");
                break;}
                printf("\n\n\nEnter the Choice:\n\n\t[1]-For Main Menu\t\t[0]-TO Exit\n");
                scanf("%d", &a);
switch (a)
    {
        case (1):
                goto main;
        case (0):
                break;
    default:
                printf("*INVALID CHOICE*");
                break;
    }
}