#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void reg();
int login();
int valid(char username[30]); // checks if username has aready been used while registering
int valid1(char username[30],char password[30]);//username and password while logging in
int check_logins();//to check how many times the tourist has logged in
void addsite();//this function is used when offficial chooses to add site
void officer();// this function runs when any officer logs in
void writesite();// officer writes the sites added by the user into a file where a list is prepared
void showpalces();//to show palces to the to the tourists where they could posssibly visit
void askreviews();//to ask reviews from the tourist in general or about the place they visited from among the suggested sites
void sitereview();//to get review of a particular site among the suggested ones
void record_data();//to record the datas from the tourists
void update(char file_path[30] ,char object[30]);//to update data for anaysis
void showstats();//to show stas
void showuser();//to view user:





char filepath[40],sitetype[40];//this is to store the title of file and type of the site to be recommended


char username[30];
char logininfo_path[30]="users\\logininfo.txt";
char userinfolog_path[30]="users\\userinfo.txt";
char national_path[40]="site\\national.txt";
char adventurous_path[50]="site\\adventurous.txt";
char biological_path[50]="site\\biological.txt";
char cultural_path[40]="site\\cultural.txt";
char trekking_path[40]="site\\trekking.txt";
char generalrev_path[40]="reviews\\generalreviews.txt";

char touristdata_path[40]="users\\touristdata.txt";
char gender_path[40]="users\\gender.txt";
char country_path[40]="users\\country.txt";
char age_path[40]="users\\age.txt";

struct user
{
    char name[30],password[30],type[30];
};
struct site
{
    int site_no;
    char site_name[30],filetitle[50];
};
struct user_data
{
    char username1[30],full_name[30],country[30],gender[30];
    int age,stay_days;
};

struct data_analysis
{
    char flag[30];
    int value;
};


int main()
{
    system("cls");

    char c;
    printf("\n\t\t\t**     ** ******  ****** ****** *******     **      **  ******  ******    *     **   ");
    printf("\n\t\t\t **   **    **    **       **     **        ** **   **  **      **  **    **    **   ");
    printf("\n\t\t\t  ** **     **      **     **     **        **  **  **  ******  ******   ****   **   ");
    printf("\n\t\t\t   * *      **       **    **     **        **    ****  **      **      ******  **    ");
    printf("\n\t\t\t    *     ******  ****** ******   **        **      **  ******  **     **    ** ******  \n\n");
    printf("\n\t\t\t                    ********  ********   ********  ********    ");
    printf("\n\t\t\t                         **   **    **         **  **    **   ");
    printf("\n\t\t\t                    ********  **    **   ********  **    **   ");
    printf("\n\t\t\t                    **        **    **   **        **    **   ");
    printf("\n\t\t\t                    ********  ********   ********  ********   ");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\Developers:\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\tUjjwal Poudel\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\tPrabin Bohara\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\tSajjan Acharya\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\tAnuj Rayamajhi\n");
    printf("\n\n\n\n\n\t\tCopyright@ 2020. All rights reserved. ");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t  press Enter to proceed");
    int times,n1;
    XYZ:
    fflush(stdin);
    c=getch();
    if(c==13)
    {
        system("cls");
        printf("\n\t\t\t\t\tYOU ARE HEARTILY WELCOME TO NEPAL!!! ");
        printf("\n\n\n\t\t\tPRESS: \n\n\t\t\t\t[1] TO LOGIN \n\t\t\t\t[2] TO REGISTER");
        int check=0;
        XY:
        c=getch();
        if(c=='1')
        {
            n1=login();// login function returns 1 for tourist and 2 for officials if successfully logged in
            if(n1==1)
            {
                times=check_logins(username)-1;
                if(times!=2)
                {
                    while(1)
                    {
                        if(times==1 && check==0)
                        {
                            check++;
                            record_data();

                        }
                        showpalces();
                        printf("\n\n\n\tPress : \n\t[1] to continue viewing other sites\n\t[2] to return exit and return to HOME page.");
                        oo:
                        c=getch();
                        if(c=='1')
                            continue;
                        else if(c=='2')
                            main();
                        else
                            goto oo;
                    }
                }
                else if(times==2)
                {
                    askreviews();
                }
            }
            if(n1==2)
            {
                officer();
            }
        }

        else if(c=='2')
            reg();
        else
            goto XY;
    }

}
//----------------------------------user defined functions for login  and registration begins here----------------------------------------------------------------------
int login(void)
{
    system("cls");
    printf("\n\t\t\t\t\tLOGIN PAGE ");
    int j,i=0;
    char password1[30],password[30],ch;
    printf("\n\n\n\t\t\t\tUSERNAME: ");
    gets(username);//made username global variable cause it is needed in most cases
    NN:
    j=0;
    printf("\n\t\t\t\tPASSWORD: ");
    while(1)
    {
        ch=getch();
        if(ch!=13 && ch!=32)//masking the password
        {
            password1[j]=ch;
            if(ch!=8) //backspace
                printf("*");
            if(ch==8 && j>=1) // backspace functioning in password
            {
                system("cls");
                printf("\n\t\t\t\t\tLOGIN PAGE ");
                printf("\n\n\n\t\t\t\tUSERNAME: %s\n",username);
                printf("\n\t\t\t\tPASSWORD: ");
                for(i=0;i<j-1;i++)
                    printf("*");
                password1[j-1]='\0';
                j=j-2;
            }
            j++;
        }
        if(ch==13)
        {
            password1[j]='\0';
            break;
        }
    }
    strcpy(password,password1);
    int smth=valid1(username,password);//returns 0 if not registered 1 if passwords don't match 2 if passwords match and
    //user is a tourist and 3 if passwords match and user is a official
    if(smth==0)
    {
        printf("\n\n\nSORRY user you haven't registered.\n\nPress any key to continue with registration");
        ch=getch();
        reg();
    }
    if(smth==1)
    {

       printf("\nPASSWORD DIDN'T MATCH. Press any key to retype the password:\n");
       ch=getch();
       system("cls");
        printf("\n\t\t\t\t\tLOGIN PAGE ");
        printf("\n\n\n\t\t\t\tUSERNAME: %s\n",username);
        goto NN;
    }
    if(smth==2)
    {
        return 1;// to know that the user is tourist
    }
    if(smth==3)
    {
        return 2;// to know if the user is official
    }


}

//------------------------------------------------------------------------------------------------------
void reg(void)
{
    regg:
    system("cls");
    printf("\n\t\t\t\tREGISTRATION PAGE ");
    FILE *fptr;
    fptr=fopen(userinfolog_path,"a+");
    if(fptr==NULL)
    {
        printf("The file couldn't be created");
        exit(1);
    }
    struct user u;
    char username[30],password1[30],password2[30],ch;
    int i=0,j=0,k;
    XX:
    printf("\n\n\t\t\tUSERNAME: ");
    fflush(stdin);
    gets(username);
    if(valid(username)==1)
    {
        strcpy(u.name,username);
    }
    else
    {
        printf("\nThe user name ALREADY EXISTS.Please try another one: \n");
        printf("Press any key to continue: ");
        ch=getch();
        system("cls");
        printf("\n\t\t\t\tREGISTRATION PAGE ");
        goto XX;
    }
        printf("\t\t\tPASSWORD: ");
        fflush(stdin);
    while(1)
    {
        ch=getch();
        if(ch!=13 && ch!=32)
        {
            password1[j]=ch;
            if(ch!=8) //backspace
                printf("*");
            if(ch==8 && j>=1) // backspace functioning in password
            {
                system("cls");
                printf("\n\t\t\t\tREGISTRATION PAGE ");
                printf("\n\n\t\t\tUSERNAME: %s\n",username);
                printf("\t\t\tPASSWORD: ");
                for(i=0;i<j-1;i++)
                    printf("*");
                password1[j-1]='\0';
                j=j-2;
            }
            j++;
        }
        if(ch==13)
        {
            password1[j]='\0';
            break;
        }
    }
    printf("\n\t\t\tRE-ENTER PASSWORD : ");
    int n=j;
    j=0;
     while(1)
    {
        ch=getch();
        if(ch!=13 && ch!=32)
        {
            password2[j]=ch;
            if(ch!=8) //backspace
                printf("*");
            if(ch==8 && j>=1) // backspace functioning in password
            {
                system("cls");
                printf("\n\t\t\t\tREGISTRATION PAGE ");
                printf("\n\n\t\t\tUSERNAME: %s\n",username);
                printf("\t\t\tPASSWORD: ");
                for(i=0;i<n;i++)
                    printf("*");
                printf("\n\t\t\tRE-ENTER PASSWORD : ");
                for(i=0;i<j-1;i++)
                    printf("*");
                password2[j-1]='\0';
                j=j-2;
            }
            j++;
        }
        if(ch==13)
        {
            password2[j]='\0';
            break;
        }
    }
    if(strcmp(password1,password2)==0)
    {
        strcpy(u.password,password2);
    }
    else
    {
        printf("Passwords didn't match. Press any key to try again");
        ch=getch();
        system("cls");
        goto regg;
    }
    printf("\n\t\t\tPRESS: \n\t\t\t\t[1] for TOURIST ACCOUNT \n\t\t\t\t[2] for OFFICIAL ACCOUNT.");
    kk:
    ch=getch();
    if(ch=='1')
        strcpy(u.type,"Tourist");
    else if(ch=='2')
    {
        char ident[5];
        printf("\n\t\t\tIDENTIFICATION CODE : ");
        gets(ident);
        if(strcmp(ident,"admin")==0)
        {
            strcpy(u.type,"Official");
        }
        else
        {
            printf("Sorry the identification code was incorrect. Please press any key to continue RE-REGESTERING");
            getch();
            goto regg;

        }

    }
    else
        goto kk;
// writing the structure
    fwrite(&u,sizeof(struct user),1,fptr);
    fclose(fptr);
    printf("\n\nTHANK YOU for registering\n\nPRESS H to go to the HOME page");
    cc:
    ch=getch();
    if(ch=='h')
    {
        system("cls");
        main();
    }
    else
        goto cc;

}
//-------------------------------------------------------------------------------------------------------------------
int valid(char username[30])//checks if the user name provided by the user already exists
 {
    int j=0,k=0;
    FILE *fptr;
    fptr=fopen(userinfolog_path,"ab+");
    if(fptr==NULL)
    {
        printf("The file couldn't be created");
        exit(1);
    }
    struct user u;
    while(!feof(fptr))
    {
        fread(&u,sizeof(struct user),1,fptr);
        if(strcmp(u.name,username)==0)
        {
            k=k+1;
        }

    }
    fclose(fptr);
    if(k==0)
        return 1;
    else
        return 0;

}

//--------------------------------------------------------------------------------

int valid1(char username[30],char password[30])//checks if username and password provided are in the file or not
//returns 1 if wrong password returns 2 if tourist and 3 if official and 0 if both user name and password are not in the file
{
    int j=0,k=0,a;
    FILE *fptr;
    fptr=fopen(userinfolog_path,"ab+");
    if(fptr==NULL)
    {
        printf("The file couldn't be created");
        exit(1);
    }
    struct user u;
    while(!feof(fptr))
    {
        fread(&u,sizeof(struct user),1,fptr);
        fscanf(fptr,"%d",&a);
        if(strcmp(u.name,username)==0)
            break;
    }

     if(strcmp(u.name,username)==0)
    {
        k=k+1;

    }
    if(k==1)
    {
        if(strcmp(u.password,password)==0)
        {
            k=k+1;
        }

    }

    fclose(fptr);
    if(k==1)
    {
        return 1;
    }
    else if(k==2)
    {
        if(strcmp(u.type,"Tourist")==0)
        {
            FILE *fptr;
            fptr=fopen(logininfo_path,"a+");//this is to write the name of the tourist who logged in in order to know the no. of times he logged in
            if(fptr==NULL)
            {
                printf("The file couldn't be created");
                exit(1);
            }
            fwrite(&u.name,30,1,fptr);
            strcpy(username,u.name);
            fclose(fptr);
            return 2;
        }
        else
            return 3;
    }
    else
        return 0;
}

//-------------------------------------------checking the no. of logins----------------------------------------------
int check_logins()//idk what is wrong with this function but it returns 1 value extra
{
    FILE *fptr;
    fptr=fopen(logininfo_path,"ab+");
    if(fptr==NULL)
    {
        printf("The file couldn't be created");
        exit(1);
    }
    int a=0;
    char s[30];

    while(!feof(fptr))
    {
        fread(&s,30,1,fptr);
        if(strcmp(s,username)==0)
        {
            a=a+1;
        }
    }
    return a;
}
//---------------the user defined portion for login and registration ends here------------------------------------------------------

//--------------------------this is user defined portion of officials----------------------------------------------
void officer()
{
    system("cls");
    char ch;
    printf("\t\t\t\tWELCOME OFFICER!!");
    printf("\n\n\t\t\tPRESS : \n \n\t\t\t[1] to ADD SITE.\n\t\t\t[2] to VIEW STATS.\n\t\t\t[3] to view general reviews");
    printf("\n\t\t\t[4] to show all tourists");
    printf("\n\t\t\t[5] to exit to home page");
    XX:
    ch=getch();
    switch(ch)
    {
    case '1':
        addsite();
        break;
    case '2':
        showstats();
        break;
    case '3':
        {
            system("cls");
            char *read=malloc(400);
            printf("\n\t\t\t\tGENERAL REVIEWS\n\n");
            FILE *fptr;
            fptr=fopen(generalrev_path,"r");
            if(fptr==NULL)
            {
                printf("The general review folder couldn't be opened");
                exit(1);
            }
            while(fgets(read,400,fptr)!=NULL)
            {
                puts(read);
            }
            free(read);
            printf("\n\n Press any key to return to provious page : ");
            ch=getch();
            officer();
            break;
        }

    case '4':
        showuser();
        break;
    case '5':
        system("cls");
        main();
        break;
    default:
        goto XX;
    }
}

//------------------------------------------------------this is function to add site to a category-------------------------------
void addsite()
{
    char ch1;
    int next_siteno=0,present;
    system("cls");
    printf("\t\t\t\tSITES ADDITION PAGE");
    printf("\n\n\n\t\tCHOOSE THE CATEGORY TO WHICH THE SITE BELONGS\n");
    printf("\n\t\tPRESS : \n\n\t\t[1] for CULTURAL AND RELIGIOUS\n\t\t[2] for TREKKING AND HIKING \n\t\t[3] for BIOLOGICAL\n");
    printf("\t\t[4] for ADVENTUROUS\n\t\t[5] for NATIONAL");
    pp:
    ch1=getch();

    //getting file name and TITILE as the data is input by the user
    switch(ch1)
    {
    case '1':
            strcpy(filepath,cultural_path);
            strcpy(sitetype,"CULTURAL AND RELIGIOUS");
            break;
    case '2':
        strcpy(filepath,trekking_path);
        strcpy(sitetype,"TREKKING AND HIKING");
        break;
    case '3':
        strcpy(filepath,biological_path);
        strcpy(sitetype,"BIOLOGICAL");
        break;
    case '4':
        strcpy(filepath,adventurous_path);
        strcpy(sitetype,"ADVENTUROUS");
        break;
    case '5':
        strcpy(sitetype,"NATIONAL");
        strcpy(filepath,national_path);
        break;
    default:
        goto pp;
    }
    system("cls");
    printf("\t\t\t\t%s",sitetype);
    printf("\n\n\nPRESS V to view the exiting sites under this category:");
    YY:
    ch1=getch();

    if(ch1=='v')
    {
        printf("\n\n");
        FILE *fptr;
        fptr=fopen(filepath,"r");
        if(fptr==NULL)
        {
            fclose(fptr);
            present=0;
        }
        struct site st;
        if(present!=0)
        {
            while(fread(&st,sizeof(struct site),1,fptr))
            {

                printf("\n%d %s",st.site_no,st.site_name);

            }
            fclose(fptr);
            next_siteno=st.site_no+1;
            printf("\n\nPress any key to continue adding a new site");
            getch();
            writesite(next_siteno);
            printf("\nPress any key to go to home page:");
            ch1=getch();
            officer();
        }
        else
        {
            printf("No site has been added. Let's add the first one\n");
            printf("\nPress any key to continue");
            ch1=getch();
            writesite(1);
            printf("\nPress any key to go to home page:");
            ch1=getch();
            officer();
        }
    }
    else
    {
        goto YY;
    }

}

void writesite(int a)
{
    char ch;
    struct site s;
    mm:
    system("cls");
    printf("\t\t\t\tPAGE OF WRITING %s SITE\n\n",sitetype);
    printf("SITE NAME : ");
    fflush(stdin);
    gets(s.site_name);
    s.site_no=a;
    printf("\nYou are requested to include the text file(i.e. filetitle.txt)of the site.\nThe path to the file must be similar to %s ",filepath);
    printf("\n\nType the path of the included file : ");
    fflush(stdin);
    gets(s.filetitle);
    FILE *fptr;
    fptr=fopen(s.filetitle,"r");
    if(fptr==NULL)// checking if the file was added or not
    {
        printf("The site file wasn't added. PLEASE press a character and retry: ");
        ch=getch();
        goto mm;
    }
    fclose(fptr);
    fptr=fopen(filepath,"ab+");
    if(fptr==NULL)
    {
        printf("The file counldn't be created:");
        exit(1);
    }
    fwrite(&s,sizeof(struct site),1,fptr);
    fclose(fptr);
    printf("\n\nNew site was added SUCCESSFULLY");

}
//-----------------------------the official portion of user defined function ends here----------------------------

//-------------------------------the function to show user the places ---------------------------------------------------
void showpalces()
{
    system("cls");
    char ch1;
    printf("\t\t\t\tRECOMMENDATION PAGE");
     printf("\n\n\t\tCHOOSE THE CATEGORY OF YOUR INTEREST:\n");
    printf("\n\t\t\tPRESS: \n\n\t\t\t[1] for CULTURAL AND RELIGIOUS\n\t\t\t[2] for TREKKING AND HIKING \n\t\t\t[3] for BIOLOGICAL\n");
    printf("\t\t\t[4] for ADVENTUROUS\n\t\t\t[5] for NATIONAL");
    pp:
    ch1=getch();

    //getting file name and TITILE as the data is input by the user
    switch(ch1)
    {
    case '1':
            strcpy(filepath,cultural_path);
            strcpy(sitetype,"CULTURAL AND RELIGIOUS");
            break;
    case '2':
        strcpy(filepath,trekking_path);
        strcpy(sitetype,"TREKKING AND HIKING");
        break;
    case '3':
        strcpy(filepath,biological_path);
        strcpy(sitetype,"BIOLOGICAL");
        break;
    case '4':
        strcpy(filepath,adventurous_path);
        strcpy(sitetype,"ADVENTUROUS");
        break;
    case '5':
        strcpy(sitetype,"NATIONAL");
        strcpy(filepath,national_path);
        break;
    default:
        goto pp;
    }
    system("cls");
    printf("\t\t\t\t%s",sitetype);
    FILE *fptr;
    fptr=fopen(filepath,"ab+");
    if(fptr==NULL)
    {
        printf("File was not found. ");
        exit(1);

    }
    struct site st;
    printf("\n\n\tThe sites available for brief information are: \n");
    while(fread(&st,sizeof(struct site),1,fptr))//this reads the file until the end of file
    {

        printf("\n\t\t%d %s",st.site_no,st.site_name);

    }
    rewind(fptr);
    printf("\n\n\tType the number of the site you're interested in: ");
    int no;
    scanf("%d",&no);
    system("cls");
    printf("\n");
    no=no-1;
    fseek(fptr,no*sizeof(struct site),SEEK_SET);
    fread(&st,sizeof(struct site),1,fptr);
    fclose(fptr);
    fptr=fopen(st.filetitle,"r");
    if(fptr==NULL)
    {
        printf("The site list has not been created.");
        exit(1);
    }

    while (ch1!=EOF)
    {
        ch1 = fgetc(fptr);
        printf("%c",ch1);

    }
    fclose(fptr);
}
//-----------------------------------------------------review asking----------------------------------

void askreviews()
{
    system("cls");
    char *review=malloc(400*sizeof(char));
    printf("\n\t\t\t\t\tREVIEWING PAGE");
    printf("\n\n\tTHANK YOU %s FOR VISITING NEPAL",username);
    char ch,ch1;
    printf("\n\n\tPRESS : \n\t[1] To leave a general review\n\t[2] To leave a review on the site we suggested you");
    XX:
    ch=getch();
    switch(ch)
    {
        case '1':
        {
            system("cls");
            printf("\n\t\t\t\tGENERAL REVIEWING PAGE\n\n");
            FILE *fptr;
            fptr=fopen(generalrev_path,"a");
            if(fptr==NULL)
            {
                printf("The review file couldn't be created");
                exit(1);
            }
            printf("\nType your review below : \n");
            fflush(stdin);
            gets(review);
            fprintf(fptr,"%s\n%s\n\n",username,review);
            printf("\n\nThank you for your valuable review.");
            fclose(fptr);
            printf("\n\nPress\n1 to leave a review on the site we suggested you\n2 to exit to HOME PAGE");
            YY:
            ch1=getch();
            switch(ch1)
            {
            case '1':
                {
                    while(1)
                    {
                        sitereview();
                        system("cls");
                        printf("\n\nType\n Y to review more sites\nN to exit to home page");
                        kk:
                        ch1=getch();
                        if(ch1=='y')
                        {
                            continue;
                        }
                        else if(ch1=='n')
                        {
                            main();
                        }
                        else
                            goto kk;
                    }

                }
            case '2':
                {

                    while(1)
                    {
                        sitereview();
                        system("cls");
                        printf("\n\nType\n Y to review more sites\nN to exit to home page");
                        k1:
                        ch1=getch();
                        if(ch1=='y')
                        {
                            continue;
                        }
                        else if(ch1=='n')
                        {
                            main();
                        }
                        else
                            goto k1;
                    }
                }
            default:
                goto YY;
            }
        }
        case '2':
            sitereview();
        default:
            goto XX;
    }
}

//----------------------this function is to review a particular site which can be viewed by other tourists-------------------------
void sitereview()
{
    system("cls");
    char ch,ch1;
    struct site st;
    printf("\n\t\t\t\tSITE REVIEWING PAGE");
    char *review=malloc(400*sizeof(char));
    printf("\n\n\t\tCHOOSE THE CATEGORY TO WHICH THE SITE BELONGS\n");
    printf("\n\t\tPRESS\n\n\t\t\t[1] for CULTURAL AND RELIGIOUS\n\t\t\t[2] for TREKKING AND HIKING \n\t\t\t[3] for BIOLOGICAL\n");
    printf("\t\t\t[4] for ADVENTUROUS\n\t\t\t[5] for NATIONAL");
    pp:
    ch1=getch();

    //getting file name and TITILE as the data is input by the user
    switch(ch1)
    {
    case '1':
            strcpy(filepath,cultural_path);
            strcpy(sitetype,"CULTURAL AND RELIGIOUS");
            break;
    case '2':
        strcpy(filepath,trekking_path);
        strcpy(sitetype,"TREKKING AND HIKING");
        break;
    case '3':
        strcpy(filepath,biological_path);
        strcpy(sitetype,"BIOLOGICAL");
        break;
    case '4':
        strcpy(filepath,adventurous_path);
        strcpy(sitetype,"ADVENTUROUS");
        break;
    case '5':
        strcpy(sitetype,"NATIONAL");
        strcpy(filepath,national_path);
        break;
    default:
        goto pp;
    }
    system("cls");
    FILE *fptr;
    fptr=fopen(filepath,"ab+");
    if(fptr==NULL)
    {
        printf("The file with sites list under this category wasn't created");
        exit(1);
    }

    printf("\n\nThe sites available reviewing are: \n\n");
    while(fread(&st,sizeof(struct site),1,fptr))
    {

        printf("\n%d %s",st.site_no,st.site_name);

    }
    rewind(fptr);
    printf("\n\nType the number of the site you'd like to review: ");
    int no;
    scanf("%d",&no);
    system("cls");
    printf("\n");
    no=no-1;
    fseek(fptr,no*sizeof(struct site),SEEK_SET);
    fread(&st,sizeof(struct site),1,fptr);
    fclose(fptr);
    fptr=fopen(st.filetitle,"ab+");
    if(fptr==NULL)
    {
        printf("The list has not been created.");
        getch();
        exit(1);
    }
    printf("\nType your review on %s:\n\n",st.site_name);
    fflush(stdin);
    gets(review);
    fprintf(fptr,"\nReview by %s : \n%s",username,review);
    free(review);
    printf("\n\nThank you for your review. ");
    printf("\n\n\tPress : \n\t\t[1] To continue reviewing\n\t\t[2] To exit ");
    ll:
    ch1=getch();
    if(ch1=='1')
    {
        askreviews();
    }
    else if(ch1=='2')
    {
        main();
    }
    else
    {
        goto ll;
    }
    askreviews();
    fclose(fptr);
}

//-------------------------------------------------------------------data analysis portion--------------------------------

void record_data()
{
    system("cls");
    printf("\n\t\t\t\t\tDATA ENTRY SECTION");
    struct user_data u;
    strcpy(u.username1,username);
    printf("\n\n\t\t\tFull name : ");
    fflush(stdin);
    gets(u.full_name);
    printf("\t\t\tAge(in numbers) : ");
    scanf("%d",&u.age);
    printf("\t\t\tCountry : ");
    fflush(stdin);
    gets(u.country);
    strcpy(u.country,strlwr(u.country));
    printf("\t\t\tGender(male/female) : ");
    fflush(stdin);
    gets(u.gender);
    strcpy(u.gender,strlwr(u.gender));
     printf("\t\t\tDays to stay : ");
    scanf("%d",&u.stay_days);
    //writing these datas to a file name touristdata.txt;
    FILE *fptr;
    fptr=fopen(touristdata_path,"a+");
    if(fptr==NULL)
    {
        printf("The tourist data file was not created");
        exit(1);
    }
    fwrite(&u,sizeof(struct user_data),1,fptr);
    fclose(fptr);
    update(gender_path,u.gender);
    update(country_path,u.country);
    if(u.age<12)
    {
        update(age_path,"Children");
    }
    if(u.age>=12&&u.age<17)
    {
        update(age_path,"Teens");
    }
    if(u.age>=17 && u.age<65 )
    {
        update(age_path,"Adults");
    }
    if(u.age>=65)
    {
        update(age_path,"Elders");
    }
    printf("\n\nPress any key to continue");
    getch();

}
//-----------------------------------update the data---------------------------------------------
void update(char file_path[40] ,char object[30])
 {
     int status=0;
     FILE *fp1;
     FILE *fp2;
     struct data_analysis d;
     fp1=fopen(file_path,"r");
     fp2=fopen("users\\temp_file.txt","w");
      while(fread(&d,sizeof(struct data_analysis),1,fp1))
      {
        if(strcmp(d.flag,object)==0)
        {
            d.value=d.value+1;
            status=1;
        }
        fwrite(&d,sizeof(struct data_analysis),1,fp2);
      }

      if(status==0)
      {
          struct data_analysis dd;
          strcpy(dd.flag,object);
          dd.value=1;
          fwrite(&dd,sizeof(struct data_analysis),1,fp2);
      }
      fclose(fp1);
      fclose(fp2);
      remove(file_path);
      int a=rename("users\\temp_file.txt",file_path);
      if(a!=0)
      {
          printf("The database couldn't be updated");
      }
      struct data_analysis dd;


 }//end of update function:

 //-------------------------------------show the stats-------------------------------------------
 void showstats()
 {
     system("cls");
     char ch;
     system("cls");
     printf("\n\t\t\t\tSTATISTICS");
     struct data_analysis a;

     printf("\n\n\nGENDER WISE tourist data analysis");
        float total=0;
        printf("\n\nS.N.\t\t\t\tGENDER\t\t\t\tNO. OF TOURISTS\t\t\tPERCENTAGE");
        FILE *fptr;
        fptr=fopen(gender_path,"r");
        if(fptr==NULL)
        {
            printf("The gender file couldn't be created");
            exit(1);
        }
        int i=0;
        while(fread(&a,sizeof(struct data_analysis),1,fptr))
        {
            total+=a.value;
        }
        rewind(fptr);

        while(fread(&a,sizeof(struct data_analysis),1,fptr))
        {
            i++;
            printf("\n%d\t\t\t\t%s\t\t\t\t%d\t\t\t\t%f %",i,a.flag,a.value,(a.value*100)/total);
        }
        fclose(fptr);


    printf("\n\n\nAGE GROUP WISE tourist data analysis");
        total=0;
        printf("\n\nS.N.\t\t\t\tAGE GROUP\t\t\tNO. OF TOURISTS\t\t\tPERCENTAGE");
        fptr=fopen(age_path,"r");
        if(fptr==NULL)
        {
            printf("The age file couldn't be created");
            exit(1);
        }
        while(fread(&a,sizeof(struct data_analysis),1,fptr))
        {
            total+=a.value;
        }
        i=0;
        rewind(fptr);
        while(fread(&a,sizeof(struct data_analysis),1,fptr))
        {
            i++;
            fflush(stdin);
            printf("\n%d\t\t\t\t%s\t\t\t\t%d\t\t\t\t%f%",i,a.flag,a.value,(a.value*100)/total);
        }
        fclose(fptr);

    printf("\n\n\nCOUNTRY WISE tourist data analysis");
        total=0;
        printf("\n\nS.N\t\t\t\tCOUNTRY\t\t\t\tNO. OF TOURISTS\t\t\tPERCENTAGE");
        fptr=fopen(country_path,"r");
        if(fptr==NULL)
        {
            printf("\nThe country file couldn't be created");
            exit(1);
        }
        while(fread(&a,sizeof(struct data_analysis),1,fptr))
        {
            total+=a.value;
        }
        i=0;
        rewind(fptr);
        while(fread(&a,sizeof(struct data_analysis),1,fptr))
        {
            i++;
            printf("\n%d\t\t\t\t%s\t\t\t\t%d\t\t\t\t%f%",i,a.flag,a.value,(a.value*100)/total);
        }
        fclose(fptr);

        printf("\n\nPress any key to return to previous page");
        getch();
        officer();
 }


 void showuser()
 {
   FILE *fptr;
   struct user_data u;
    fptr=fopen(touristdata_path,"r+");
    if(fptr==NULL)
    {
        printf("The tourist data file is not found.");
        exit(1);
    }
    system("cls");
    printf("\n\n\tFull name\t\tAge\t\tCountry\t\tGender\t\tDays of stay\n\n");
    while(fread(&u,sizeof(struct user_data),1,fptr))
    {
     printf("\t%s\t\t%d\t\t%s\t\t%s\t\t%d\n",u.full_name,u.age,u.country,u.gender,u.stay_days);
    }
      fclose(fptr);
            printf("\n\nPress any key to return to previous page");
        getch();
        officer();


 }


