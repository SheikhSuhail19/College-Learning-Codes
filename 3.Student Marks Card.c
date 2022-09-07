#include<conio.h>
#include<stdio.h>
#include<process.h>
struct student
{
 int rollno;
 char name[50];
 int phy_marks,chem_marks,math_marks,eng_marks,cs_marks;
 float percentage;
 char grade;
 int std;
}st;
 FILE *fptr;
void write_student()
   {
    fptr=fopen("student.dat","ab");
    printf("\nPlease Enter The Details of Student \n");
    printf("\nEnter The Roll Number of Student ");
    scanf("%d",&st.rollno);
    fflush(stdin);
    printf("\n\nEnter The Name of Student ");
    gets(st.name);
    printf("\nEnter The Marks in Physics out of 100 : ");
    scanf("%d",&st.phy_marks);
    printf("\nEnter The marks in Chemistry out of 100 : ");
    scanf("%d",&st.chem_marks);
    printf("\nEnter The marks in Maths out of 100 : ");
    scanf("%d",&st.math_marks);
    printf("\nEnter The marks in English out of 100 : ");
    scanf("%d",&st.eng_marks);
    printf("\nEnter The marks in Computer Science out of 100 : ");
    scanf("%d",&st.cs_marks);
    st.percentage=(st.phy_marks+st.chem_marks+st.math_marks+st.eng_marks+st.cs_marks)/5.0;
    if(st.percentage>=90)
       st.grade='A';
    else if(st.percentage>=80 &&st.percentage<90)
      st.grade='B';
    else if(st.percentage>=70 &&st.percentage<79)
      st.grade='C';
    else if(st.percentage>=50 &&st.percentage<69)
      st.grade='D';
    else if(st.percentage>=33 &&st.percentage<49)
      st.grade='E';
    else
     st.grade='F';
    fwrite(&st,sizeof(st),1,fptr);
    fclose(fptr);
    printf("\n\nNew Student Record Has Been Created ");
    getch();
}



void display_all()
{
    clrscr();
    printf("\n\n\n\t\t*DISPLAY ALL RECORD !!!*\n\n");
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
      printf("\nRoll Number of Student : %d",st.rollno);
      printf("\nName of Student : %s",st.name);
      printf("\nMarks in Physics : %d",st.phy_marks);
      printf("\nMarks in Chemistry : %d",st.chem_marks);
      printf("\nMarks in Maths : %d",st.math_marks);
      printf("\nMarks in English : %d",st.eng_marks);
      printf("\nMarks in Computer Science : %d",st.cs_marks);
      printf("\nPercentage of Student is  : %.2f",st.percentage);
      printf("\nGrade of Student is : %c",st.grade);
      printf("\n\n====================================\n");
      getch();
    }
    fclose(fptr);
    getch();
}



void display_sp(int n)
{
    int flag=0;
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
     if(st.rollno==n)
        {
         clrscr();
            printf("\nRoll number of Student : %d",st.rollno);
            printf("\nName of Student : %s",st.name);
            printf("\nMarks in Physics : %d",st.phy_marks);
            printf("\nMarks in Chemistry : %d",st.chem_marks);
            printf("\nMarks in Maths : %d",st.math_marks);
            printf("\nMarks in English : %d",st.eng_marks);
            printf("\nMarks in Computer Science : %d",st.cs_marks);
            printf("\nPercentage of Student is  : %.2f",st.percentage);
            printf("\nGrade of Student is : %c",st.grade);
         flag=1;
        }
    }
    fclose(fptr);
if(flag==0)
 printf("\n\nRecord Does Not Exist");
    getch();
}



void modify_student()
{
    int no,found=0;
    clrscr();
    printf("\n\n\tInorder  To  Modify ");
    printf("\n\n\tPlease Enter The Roll Number of Student");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb+");
    while((fread(&st,sizeof(st),1,fptr))>0 && found==0)
    {
    if(st.rollno==no)
           {
            printf("\nRoll Number of Student : %d",st.rollno);
            printf("\nName of Student : %s",st.name);
            printf("\nMarks in Physics : %d",st.phy_marks);
            printf("\nMarks in Chemistry : %d",st.chem_marks);
            printf("\nMarks in Maths : %d",st.math_marks);
            printf("\nMarks in English : %d",st.eng_marks);
            printf("\nMarks in Computer Science : %d",st.cs_marks);
            printf("\nPercentage of student is  : %.2f",st.percentage);
            printf("\nGrade of student is : %c",st.grade);
            printf("\nPlease Enter The New Details of Student \n");
            printf("\nEnter The Roll Number of Student ");
            scanf("%d",&st.rollno);
            fflush(stdin);
            printf("\n\nEnter The Name of student ");
            gets(st.name);
            printf("\nEnter The marks in Physics out of 100 : ");
            scanf("%d",&st.phy_marks);
            printf("\nEnter The marks in Chemistry out of 100 : ");
            scanf("%d",&st.chem_marks);
            printf("\nEnter The marks in Maths out of 100 : ");
            scanf("%d",&st.math_marks);
            printf("\nEnter The marks in English out of 100 : ");
            scanf("%d",&st.eng_marks);
            printf("\nEnter The marks in Computer Science out of 100 : ");
            scanf("%d",&st.cs_marks);
            st.percentage=(st.phy_marks+st.chem_marks+st.math_marks+st.eng_marks+st.cs_marks)/5.0;
            if(st.percentage>=90)
               st.grade='A';
            else if(st.percentage>=80 &&st.percentage<90)
               st.grade='B';
            else if(st.percentage>=70 &&st.percentage<79)
               st.grade='C';
            else if(st.percentage>=50 &&st.percentage<69)
               st.grade='D';
            else if(st.percentage>=33 &&st.percentage<49)
               st.grade='E';
            else
               st.grade='F';
            fseek(fptr,-(long)sizeof(st),1);
            fwrite(&st,sizeof(st),1,fptr);
            printf("\n\n\t Record Updated");
            found=1;
           }
         }
    fclose(fptr);
    if(found==0)
    printf("\n\n Record Not Found ");
    getch();
}





void delete_student()
   {
    int no;
    FILE *fptr2;
    clrscr();
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The Roll Number of Student You Want To Delete");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb");

    fptr2=fopen("Temp.dat","wb");
    rewind(fptr);
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
       if(st.rollno!=no)
       {
      fwrite(&st,sizeof(st),1,fptr2);
       }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("student.dat");
    rename("Temp.dat","student.dat");
    printf("\n\n\tRecord Deleted ...");
    getch();
}



    void class_result()
    {
     clrscr();
     fptr=fopen("student.dat","rb");
     if(fptr==NULL)
     {
       printf("ERROR!!! FILE COULD NOT BE OPENED\n\n\n Go To Entry Menu to Create File");
       printf("\n\n\n Program is closing ....");
       getch();
       exit(0);
     }

     printf("\n\n\t\t*ALL STUDENTS RESULT* \n\n");
      printf("====================================================\n");
      printf("R.No.  Name       P   C   M   E   CS  %age   Grade\n");
      printf("====================================================\n");

      while((fread(&st,sizeof(st),1,fptr))>0)
     {
       printf("%-6d %-10s %-3d %-3d %-3d %-3d %-3d %-3.2f  %-1c\n",st.rollno,st.name,st.p_marks,st.c_marks,st.m_marks,st.e_marks,st.cs_marks,st.per,st.grade);
     }
     fclose(fptr);
     getch();
}



   void result()
   {
    int ans,rno;
    char ch;
    clrscr();
    printf("\n\n\nRESULT MENU");
    printf("\n\n\n1. Class Result\n\n2. Student Report Card\n\n3.Back to Main Menu");
    printf("\n\n\nEnter Choice (1/2/3) ");
    scanf("%d",&ans);
    switch(ans)
    {
     case 1 : class_result();break;
     case 2 : {
        do{
        char ans;
        clrscr();
        printf("\n\nEnter Roll Number of Student : ");
        scanf("%d",&rno);
        display_sp(rno);
        printf("\n\nDo You Want to See More Result (Y/N)?");
        scanf("%c",&ans);
        }while(ans=='y'||ans=='Y');
        break;
           }
     case 3: break;
     default:  printf("\a");
    }
 }


void intro()
{
 clrscr();
 gotoxy(35,11);
 printf("STUDENT");
 gotoxy(33,14);
 printf("REPORT CARD");
 gotoxy(35,17);
 printf("PROJECT");
 printf("\n\n\n\n\n\nMADE BY : Sheikh Suhail Khursheed");
 printf("\n\nCOLLEGE : Noida Institute of Engineering and Technology");
 getch();
}

void entry_menu()
{
    char ch2;
   clrscr();
  printf("\n\n\n\tENTRY MENU");
  printf("\n\n\t1.CREATE STUDENT RECORD");
  printf("\n\n\t2.DISPLAY ALL STUDENTS RECORDS");
  printf("\n\n\t3.SEARCH STUDENT RECORD ");
  printf("\n\n\t4.MODIFY STUDENT RECORD");
  printf("\n\n\t5.DELETE STUDENT RECORD");
  printf("\n\n\t6.BACK TO MAIN MENU");
  printf("\n\n\tPlease Enter Your Choice (1-6) ");
  ch2=getche();
  switch(ch2)
  {
    case '1': clrscr();
          write_student();
          break;
    case '2': display_all();break;
    case '3':  {
           int num;
           clrscr();
           printf("\n\n\tPlease Enter The roll number ");
           scanf("%d",&num);
           display_sp(num);
           }
           break;
      case '4': modify_student();break;
      case '5': delete_student();break;
      case '6': break;
      default:printf("\a");entry_menu();
   }
}
void main()
{
  char ch;
  intro();
  do
    {
      clrscr();
      printf("\n\n\n\tMAIN MENU");
      printf("\n\n\t01. RESULT MENU");
      printf("\n\n\t02. ENTRY/EDIT MENU");
      printf("\n\n\t03. EXIT");
      printf("\n\n\tPlease Select Your Option (1-3) ");
      ch=getche();
      switch(ch)
      {
         case '1': clrscr();
               result();
               break;
          case '2': entry_menu();
                break;
          case '3':exit(0);
          default :printf("\a");
    }
    }while(ch!='3');
}