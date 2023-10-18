#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

struct Phone
{
    char name[50];
    char address[50];
    char father_name[50];
    char mother_name[50];
    long int phone_number;
    char gender[10];
    char Email[100];
    char citizen_number[50];

};

void menu();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void gt(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8 && c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void start()
{
    menu();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void back()
{
    start();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add()
{
        system("cls");
        FILE *f;
        struct Phone p;
        f=fopen("project","ab+");
        printf("\nname: ");
        gt(p.name);
        printf("\naddress: ");
        gt(p.address);
        printf("\nfather's name: ");
        gt(p.father_name);
        printf("\nmother's name: ");
        gt(p.mother_name);
        printf("\nphone number:");
        scanf("%ld",&p.phone_number);
        printf("gender:");
        gt(p.gender);
        printf("\nEmail address:");
         gt(p.Email);
        printf("\ncitizenship number:");
        gt(p.citizen_number);
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\nrecord saved");

fclose(f);

    printf("\n\nEnter any key");

     getch();
    system("cls");
    menu();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void listrecord()
{
    struct Phone p;
    FILE *f;
f=fopen("project","rb");
if(f==NULL)
{
printf("\nfile opening error in listing :");

exit(1);
}
while(fread(&p,sizeof(p),1,f)==1)
{
     printf("\n\n\nYour record is\n\n ");
        printf("\nName=%s\nAddress=%s\nFather name=%s\nMother name=%s\nMobile no=%ld\nGender=%s\nE-mail=%s\nCitizen number=%s",
               p.name,p.address,p.father_name,p.mother_name,p.phone_number,p.gender,p.Email,p.citizen_number);

     getch();
     system("cls");
}
fclose(f);
 printf("\nEnter any key");
 getch();
    system("cls");
menu();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void modifyrecord()
{
    int c;
    FILE *f;
    int flag=0;
    struct Phone p,s;
    char  name[50];
    f=fopen("project","rb+");
    if(f==NULL)
        {

            printf("CONTACT'S DATA NOT ADDED YET.");
            exit(1);


        }
    else
    {
        system("cls");
        printf("\nEnter contact's name to modify:\n");
            gt(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



                    printf("\nname:");
                    gt(s.name);
                    printf("\nthe address:");
                    gt(s.address);
                    printf("\nfathers name:");
                    gt(s.father_name);
                    printf("\nmothers name:");
                    gt(s.mother_name);
                    printf("\nphone number:");
                    scanf("%ld",&s.phone_number);
                    printf("\ngender:");
                    gt(s.gender);
                    printf("\nEmail:");
                    gt(s.Email);
                    printf("\ncitizen number:\n");
                    gt(s.citizen_number);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\nYour data ID modified");

            }
            else
            {
                    printf(" \nData not found");

            }
            fclose(f);
    }
     printf("\nEnter any key");
     getch();
    system("cls");
    menu();

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void delet()
{
    struct Phone p;
    FILE *f,*ft;
    int flag;
    char name[100];
    f=fopen("project","rb");
    if(f==NULL)
        {

            printf("CONTACT'S DATA NOT ADDED YET.");

        }
    else
    {
        ft=fopen("temp", "wb+");
        if(ft==NULL)

            printf("file opening error");
        else

        {


        printf("Enter Contact's name:");
        gt(name);

        fflush(stdin);
        while(fread(&p,sizeof(p),1,f)==1)
        {
            if(strcmp(p.name,name)!=0)
                fwrite(&p,sizeof(p),1,ft);
            if(strcmp(p.name,name)==0)
                flag=1;
        }
    fclose(f);
    fclose(ft);
    if(flag!=1)
    {
        printf("NO CONTACTS RECORD TO DELETE.");
        remove("temp.txt");
    }
        else
        {
            remove("project");
            rename("temp.txt","project");
            printf("RECORD DELETED SUCCESSFULLY.");

        }
    }
}
 printf("\nEnter any key");

     getch();
    system("cls");
menu();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void search()
{
    struct Phone p;
FILE *f;
char name[100];

f=fopen("project","rb");
if(f==NULL)
{
    printf("\nerror in opening\a\a\a\a");
    exit(1);

}
printf("\nEnter name of person to search\n");
gt(name);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nName:%s\naddress:%s\nFather name:%s\nMother name:%s\nMobile no:%ld\ngender:%s\nE-mail:%s\nCitizen no:%s",p.name,p.address,p.father_name,
               p.mother_name,p.phone_number,p.gender,p.Email,p.citizen_number);
    }
        else
        printf("file not found");

}
 fclose(f);
  printf("\nEnter any key");

     getch();
    system("cls");
menu();
}


int main()

{
    system("color 6");
    start();
    return 0;
}


void menu()
{
    system("cls");
printf("****PHONEBOOK MENU****\n");


printf("\n\nEnter your choice number");
printf("\n\n1. Add Contacts   \n\n2. List of Contacts   \n\n3. Exit  \n\n4. Modify Contacts \n\n5. Search  Contacts\n\n6. Remove Contacts");

switch(getch())
{
    case '1':
             add();
    break;
    case '2': listrecord();
    break;
    case '3': exit(0);
    break;
    case '4': modifyrecord();
    break;
    case '5': search();
    break;
    case '6': delet();
    break;
    default:
                system("cls");
                printf("\nEnter a number from 1 to 6 only");
                printf("\n Enter any key");
                getch();

menu();
}
}



