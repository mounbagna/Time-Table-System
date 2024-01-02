#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


void createTimeTable(FILE *fp);
void postpone(FILE * fp);
void addCourse(FILE * fp);
FILE * deleteCourse(FILE * fp);
void modifycourse(FILE * fp);
void displayListOfCourses(FILE * fp);
void searchCourse(FILE *fp);
void printChar(char ch,int n);


typedef struct
{
    int hour;
    int minute;
}time;


typedef struct
{
    char coursename[100];
    char lecturername[100];
    int coursecode;
    char day[100];
    time t;
}courseinfo;


int main()
{
 FILE * fp;
 courseinfo s;
int option,choice;
char another;

if((fp=fopen("timeTableInfo.txt","rb+"))==NULL)
{
    if((fp=fopen("timeTableInfo.txt","wb+"))==NULL)
       {
           printf("can't open file");
           return 0;
       }
}
printf("\n\n\n\tWELCOME TO THE TIME TABLE MANAGEMENT SYSTEM\n\n\n\t");
printf("\n\n\n\tSELECT AN OPTION\n\n\n\t");
printf("1.ADMIN\n\n\t2.TEACHER\n\n\t3.STUDENT\n\n\t");
printf("I am...");
scanf("%d",&choice);

if(choice==1)
{
  char username[15];
    char password[12];


    printf("Enter your username:\n");
    scanf("%s",&username);

    printf("Enter the password:\n");
    scanf("%s",&password);

    if(strcmp(username,"admin")==0){
        if(strcmp(password,"123")==0){

        printf("\nWelcome admin!");

while(1)
{
    printChar('-',64);
    printf("\n\n\t\t\t1. CREATE TIMETABLE");
    printf("\n\n\t\t\t2. ADD course");
    printf("\n\n\t\t\t3. DELETE course");
    printf("\n\n\t\t\t4. MODIFY COURSE");
    printf("\n\n\t\t\t5. DISPLAY course schedule");
    printf("\n\n\t\t\t0. EXIT");

    printf("\n\n\t\tEnter Your Option :--> ");
    scanf("%d",&option);

    switch(option)
    {
        case 0: return 1;
                break;
        case 1: createTimeTable(fp);
                break;
        case 2: addCourse(fp);
                break;
        case 3: fp=deleteCourse(fp);
                break;
        case 4: modifycourse(fp);
                break;
        case 5: displayListOfCourses(fp);
                break;

        default: printf("\n\t\tYou Pressed wrong key");
                  printf("\n\t\tProgram terminated");
                  getch();
                  exit(0);

    }
}
}
}
else
{
    printf("Intruder...");
    exit(0);
}
}
else if(choice==2)
{
  char username[15];
    char password[12];


    printf("Enter your username:\n");
    scanf("%s",&username);

    printf("Enter the password:\n");
    scanf("%s",&password);

    if(strcmp(username,"teacher")==0){
        if(strcmp(password,"123")==0){

        printf("\nWelcome Teacher!");
        while(1)
            {
    printf("\n\n\t\t\t1. POSTPONE course");
    printf("\n\n\t\t\t2. SEARCH course");
    printf("\n\n\t\t\t3. DISPLAY course schedule");
    printf("\n\n\t\t\t0. EXIT");


        printf("\n\n\t\tEnter Your Option :--> ");
    scanf("%d",&option);
    switch(option)
    {
        case 1: postpone(fp);
                break;
        case 2: searchCourse(fp);
                break;
        case 3: displayListOfCourses(fp);
                break;
        default: printf("\n\t\tYou Pressed wrong key");
                  printf("\n\t\tProgram terminated");
                  getch();
                  exit(0);
    }
        }
}
}
else
{
    printf("Intruder...");
    exit(0);
}
}
else if(choice==3)
{
  while(1){
    printf("\n\n\t\t\t1. SEARCH course");
    printf("\n\n\t\t\t2. DISPLAY course schedule");
    printf("\n\n\t\t\t0. EXIT");

    printf("\n\n\t\tEnter Your Option :--> ");
    scanf("%d",&option);
    switch(option)
    {
        case 1: searchCourse(fp);
                break;
        case 2: displayListOfCourses(fp);
                break;
        default: printf("\n\t\tYou Pressed wrong key");
                  printf("\n\t\tProgram terminated");
                  getch();
                  exit(0);
}
}
}
return 0;
}

//----printing character at n times ------

void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

// ==========CREATE TIME TABLE==========================
void createTimeTable(FILE * fp)
{
char another='y';
courseinfo s;
fseek(fp,0,SEEK_SET);
while(another=='y'||another=='Y')
{
    printf("\n\n\t\tEnter the day:\n\t");
    fflush(stdin);
    fgets(s.day,100,stdin);


    printf("\n\n\t\tEnter the subjects of %s:\n\t",s.day);
    printf("\n\n\t\tEnter the name of the course:\n\t");
    fflush(stdin);
    fgets(s.coursename,100,stdin);


    printf("\n\n\t\tEnter course code:\n\t");
    scanf("%d",&s.coursecode);
    fwrite(&s,sizeof(s),1,fp);

    printf("\n\n\t\tEnter course time from beginning to end \t");
    printf("\nBeginning\n");
    scanf("%d %d",&s.t.hour,&s.t.minute);
    printf("End\n");
    scanf("%d %d",&s.t.hour,&s.t.minute);


    printf("\n\n\t\tEnter lecturer's name\t");
    fflush(stdin);
    fgets(s.lecturername,100,stdin);

    printf("\n\n\t\tWant to enter another course info (Y/N)\t");
    fflush(stdin);
    another=getchar();
}
}
// ==========ADDING NEW COURSES==========================

void addCourse(FILE * fp)
{
courseinfo s;
fseek(fp,0,SEEK_END);

    printf("\n\n\t\tEnter the day\t");
    fflush(stdin);
    fgets(s.day,100,stdin);

    printf("\n\n\t\tEnter the name of the course\t");
    fflush(stdin);
    fgets(s.coursename,100,stdin);

    printf("\n\n\t\tEnter course code \t");
    scanf("%d",&s.coursecode);
    fwrite(&s,sizeof(s),1,fp);

    printf("\n\n\t\tEnter lecturer's name\t");
    fflush(stdin);
    fgets(s.lecturername,100,stdin);

    printf("\n\n\t\tEnter time from start to end\t");
    printf("\n\n\t\tstarting time\t");
    scanf("%d %d",&s.t.hour,&s.t.minute);
    printf("\n\n\t\tending time\t");
    scanf("%d %d",&s.t.hour,&s.t.minute);

}
//===================DELETING A COURSE FROM SCHEDULE============
FILE * deleteCourse(FILE * fp)
{
courseinfo s;
int flag=0,tempCode,siz=sizeof(s);
FILE *ft;

if((ft=fopen("temp.txt","w+"))==NULL)
{
    printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
    system("pause");
     return fp;
}

printf("\n\n\tEnter course code to be Deleted:\t");
fflush(stdin);
scanf("%d",&tempCode);
rewind(fp);
while((fread(&s,siz,1,fp))==1)
{
    if(s.coursecode==tempCode)
    { flag=1;
    printf("\n\tcourse Deleted for");
    printf("\n\n\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",s.coursename,s.lecturername,s.coursecode);
    continue;
    }
    fwrite(&s,siz,1,ft);
}
fclose(fp);
fclose(ft);
remove("timeTableInfo.txt");
rename("temp.txt","timeTableInfo.txt");

if((fp=fopen("timeTableInfo.txt","r+"))==NULL)
{
    printf("ERROR");
    return  NULL;
}

if(flag==0) printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");
printChar('-',65);
printf("\n\t");
system("pause");
return fp;
}

//===========MODIFY A RECORD ===========================
void modifycourse(FILE * fp)
{
courseinfo s;
int i,flag=0,tempRoll,siz=sizeof(s);
printf("\n\n\tEnter course code to MODIFY: ");
scanf("%d",&tempRoll);
rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
    if(s.coursecode==tempRoll)
        {flag=1;
        break;
        }
}

if(flag==1)

    {
    fseek(fp,-siz,SEEK_CUR);
    printf("\n\n\t\tRECORD FOUND");
    printf("\n\n\t\tEnter New Data for the Record");
    printf("\n\n\t\tEnter day\t");
    fflush(stdin);
    fgets(s.day,100,stdin);
    s.day[strlen(s.day)-1]='\0';

    printf("\n\n\t\tEnter Name of course\t");
    fflush(stdin);
    fgets(s.coursename,100,stdin);

    printf("\n\n\t\tEnter lecturer's name\t");
    fflush(stdin);
    fgets(s.lecturername,100,stdin);

    printf("\n\n\t\tEnter course code \t");
    scanf("%d",&s.coursecode);

    printf("\n\n\t\tEnter course time from beginning to end \t");
    printf("\nBeginning\n");
    scanf("%d %d",&s.t.hour,&s.t.minute);
    printf("End\n");
    scanf("%d %d",&s.t.hour,&s.t.minute);

    fwrite(&s,sizeof(s),1,fp);
}

else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

printf("\n\n\t");
system("pause");
}

//====================SEARCH A COURSE=================
void searchCourse(FILE *fp)
{
int tempCode,flag,siz;
courseinfo s;
char another='y';

siz=sizeof(s);

while(another=='y'||another=='Y')
{
printf("\n\n\tEnter the course code to search:\t");
scanf("%d",&tempCode);
fflush(stdin);

rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
    if(s.coursecode==tempCode)
        {
        flag=1;
        break;
        }
}

if(flag==1)
    {
        printf("\n\t\tDAY OF COURSE : %s",s.day);
    printf("\n\t\tCOURSE NAME : %s",s.coursename);
        printf("\n\n\t\tCOURSE CODE : %d",s.coursecode);
        printf("\n\t\tLECTURER's NAME : %s",s.lecturername);
        printf("\n\t\tTIME : %d:%d-%d:%d%d:%d",s.t.hour,s.t.minute,s.t.hour,s.t.minute,s.t.hour,s.t.minute);
}
else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");
printf("\n\n\t\tWant to enter another search (Y/N)");
fflush(stdin);
another=getchar();
}
}

//====================DISPLAY THE LIST =================
void displayListOfCourses(FILE * fp)
{
    courseinfo s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\n\t\tDAY OF COURSE : %s",s.day);
        printf("\n\n\t\tCOURSE NAME : %s",s.coursename);
        printf("\n\n\t\tCOURSE CODE : %d",s.coursecode);
        printf("\n\t\tLECTURER's NAME : %s",s.lecturername);
        printf("\n\t\tSTARTING TIME: %d:%d\n\t\tENDING TIME: %d:%d\n\n",s.t.hour,s.t.minute,s.t.hour,s.t.minute);
        printChar('-',65);
    }

    printf("\n\n\n\t");
    printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

//===========POSTPONE===========================
void postpone(FILE * fp)
{
courseinfo s;
int flag=0,tempRoll,siz=sizeof(s);
char day[20];

printf("\n\n\tEnter current day of the course to be postponded: ");
fflush(stdin);
gets(day);

printf("\n\n\tEnter course code to be postponded: ");
fflush(stdin);
scanf("%d",&tempRoll);

rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
        if(s.coursecode==tempRoll)
        {
        flag=1;
        break;
        }
}

if(flag==1)
    {
    fseek(fp,-siz,SEEK_CUR);
    printf("\n\n\t\tCOURSE TO BE POSPONDED FOUND");
    printf("\n\n\t\tEnter New informations for the Record");
    printf("\n\n\t\tEnter new day\t");
    fflush(stdin);
    fgets(s.day,100,stdin);

    printf("\n\n\t\tEnter course new time from beginning to end \t");
    printf("\nBeginning\n");
    scanf("%d %d",&s.t.hour,&s.t.minute);
    printf("End\n");
    scanf("%d %d",&s.t.hour,&s.t.minute);

    fwrite(&s,sizeof(s),1,fp);
}
else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");
printf("\n\n\t");
system("pause");
}
