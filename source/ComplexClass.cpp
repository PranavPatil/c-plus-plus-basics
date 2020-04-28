/*=========================================================================*/
/*        ASSIGNMENT NO ::  6               SUBJECT : OOPL                 */
/*        DATE OF COMPLETION : 20-2-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  1: WRITE A CLASS DATE WITH DATA MEMBERS DD,MM,YY  */
/*                          AND MEMBER FUNCTIONS READ AND WRITE THE DATE   */
/*                       2: WRITE A CLASS PERSON FRIEND OF DATE CLASS WITH */
/*                          DATA MEM NAME,BIRTH DATE,& FUNCTNS READ,WRITE  */
/*                       3: WRITE CLASS EMPLOYEE DERIVED FROM PERSON CLASS,*/
/*                          DATA MEM COMPANY,SALARY,DEPT,FUNS READ,WRITE   */
/*                       4: WRITE CLASS STUDENT DERIVED FROM PERSON CLASS, */
/*                          DATA MEM PERCENT,BRANCH,& FUNCTIONS READ,WRITE */
/*                       5: WRITE A CLASS EMPOY_STUDENT DERIVED FROM BOTH  */
/*                          CLASS STUDENT AND EMPLOYEE                     */
/*=========================================================================*/
#include<iostream.h>
#include<stdio.h>
#include<process.h>
#include<conio.h>

/*-------------------------------------------------------------------------*/
/*                  DECLARATION   OF   CLASS   DATE                        */
/*-------------------------------------------------------------------------*/

 class date                       // DECLARATION OF CLASS
 {
   protected :                    // DECLARATION OF PROTECTED MEMBERS
	      int day,mon,year;

   public :                       // DECLARATION OF PUBLIC MEMBERS

	      void read_date();  // DECLARATION OF MEMBER FUNCTIONS
	      void write_date();
 };

/*-------------------------------------------------------------------------*/
/*                  DECLARATION   OF   CLASS   PERSON                      */
/*-------------------------------------------------------------------------*/

 class person
 {
   protected :
	      char name[20];
	      date d;
   public :
	      void p_input();
	      void p_display();
 };

/*-------------------------------------------------------------------------*/
/*           FUNCTION  : READ_DATE()                                       */
/*           CLASS     : DATE                                              */
/*           PURPOSE   : TO ACCEPT THE BIRTH DATE                          */
/*-------------------------------------------------------------------------*/

 void date :: read_date()
 {
   cout<<"\n\n\n\t\tENTER THE BIRTH DATE : "<<"\n";
   cout<<"\n\n\n\t\tENTER THE DATE : ";
   cin>>day;
   cout<<"\n\n\n\t\tENTER THE MONTH : ";
   cin>>mon;
   cout<<"\n\n\n\t\tENTER THE YEAR : ";
   cin>>year;
 }

/*-------------------------------------------------------------------------*/
/*           FUNCTION  : WRITE_DATE()                                      */
/*           CLASS     : DATE                                              */
/*           PURPOSE   : TO DISPLAY THE BIRTH DATE                         */
/*-------------------------------------------------------------------------*/

 void date :: write_date()
 {
  if(mon==4||mon==6||mon==9||mon==11)
  {
   if(day<31)
   {
     cout<<"\n\n\n\t    DATE	MONTH	     YEAR";
     cout<<"\n\n\n\t      "<<day<<"\t\t  "<<mon<<"\t\t\b\b"<<year;
   }
   else
     cout<<"\n\n\n\n\t\tENTER PROPER DATE !!!";
  }
  else
  {
    if(mon==1||mon==3||mon==5||mon==7||mon==8||mon==10||mon==12)
    {
     if(day<32)
     {
       cout<<"\n\n\n\t    DATE	MONTH	     YEAR";
       cout<<"\n\n\n\t      "<<day<<"\t\t  "<<mon<<"\t\t\b\b"<<year;
     }
     else
       cout<<"\n\n\n\n\t\tENTER PROPER DATE  !!!";
    }
    else
    {
     if(mon==2)
     {
       if(day<29)
       {
	 cout<<"\n\n\n\t    DATE	MONTH	     YEAR";
	 cout<<"\n\n\n\t      "<<day<<"\t\t  "<<mon<<"\t\t\b\b"<<year;
       }
       else
	 cout<<"\n\n\n\n\t\tENTER PROPER DATE  !!!";
     }
    }
    if(year%4 == 0)
    {
      cout<<"\n\n\n\n\t   THIS YEAR IS A LEAP YEAR !!";
      cout<<"\n\n\n\t   MONTH FEBRUARY OF THIS YEAR HAS 29 DAYS !!";
    }
  }
 }

/*-------------------------------------------------------------------------*/
/*                  DECLARATION   OF   CLASS  STUDENT                      */
/*-------------------------------------------------------------------------*/

 class student : public virtual person
 {
   char branch[15];
   float per;
   int dls,im,co,ppm,ade,sum;
   public:
   void s_input();
   void s_display();
 };

/*-------------------------------------------------------------------------*/
/*           FUNCTION  : P_INPUT()                                         */
/*           CLASS     : PERSON                                            */
/*           PURPOSE   : TO ACCEPT DATA OF THE PERSON                      */
/*-------------------------------------------------------------------------*/

 void person :: p_input()
 {
   cout<<"\n\n\n\n\t\tENTER NAME OF PERSON :: ";
   cin>>name;
   d.read_date();
 }

/*-------------------------------------------------------------------------*/
/*           FUNCTION  : P_DISPLAY()                                       */
/*           CLASS     : PERSON                                            */
/*           PURPOSE   : TO DISPLAY PERSONAL DATA                          */
/*-------------------------------------------------------------------------*/

 void person :: p_display()
 {
   cout<<"\n\n\n\t  NAME OF THE PERSON IS -> "<<name<<"\n";
   cout<<"\n\n\n\t  BIRTH DATE IS :: "<<"\n";
   d.write_date();
 }

/*-------------------------------------------------------------------------*/
/*           FUNCTION  : S_INPUT()                                         */
/*           CLASS     : STUDENT                                           */
/*           PURPOSE   : TO ACCEPT STUDENT RECORD                          */
/*-------------------------------------------------------------------------*/

 void student :: s_input()
 {
  p_input();
  sum=0;
  cout<<"\n\n\n\t\tENTER BRANCH OF STUDENT : ";
  cin>>branch;
  cout<<"\n\n\n\t\tENTER MARKS OF 5 SUBJECTS : ";
  cout<<"\n\n\n\t\t  D L S  :: ";
  cin>>dls;
  cout<<"\n\n\n\t\t  I M    :: ";
  cin>>im;
  cout<<"\n\n\n\t\t  C O    :: ";
  cin>>co;
  cout<<"\n\n\n\t\t  A D E  :: ";
  cin>>ade;
  cout<<"\n\n\n\t\t  P P M  :: ";
  cin>>ppm;
  sum=dls+im+co+ade+ppm;
  per=sum/5;
 }

/*-------------------------------------------------------------------------*/
/*           FUNCTION  : S_DISPLAY()                                       */
/*           CLASS     : STUDENT                                           */
/*           PURPOSE   : TO DISPLAY STUDENT RECORD                         */
/*-------------------------------------------------------------------------*/

 void student :: s_display()
 {
   p_display();
   cout<<"\n\n\n\n\t  BRANCH OF STUDENT :: "<<branch<<"\n";
   cout<<"\n\n\n\t  PERCENTAGE OF STUDENT :: "<<per<<"\n";
 }

/*-------------------------------------------------------------------------*/
/*                 DECLARATION   OF   CLASS   EMPLOYEE                     */
/*-------------------------------------------------------------------------*/

 class employee : public virtual person
 {
  protected :
	      char co_name[30],department[15],designation[20];
	      char salary[10];

  public :
	 void  emp_input();
	 void  emp_display();
 };

/*-------------------------------------------------------------------------*/
/*           FUNCTION  : EMP_INPUT()                                       */
/*           CLASS     : EMPLOYEE                                          */
/*           PURPOSE   : TO ACCEPT EMPLOYEE'S RECORD                       */
/*-------------------------------------------------------------------------*/

 void employee :: emp_input()
 {
   cout<<"\n\n\n\t\tENTER NAME OF COMPANY : ";
   cin>>co_name;
   cout<<"\n\n\n\t\tENTER DESIGNATION OF EMPLOYEE : ";
   cin>>designation;
   cout<<"\n\n\n\t\tENTER DEPARTMENT OF EMPLOYEE : ";
   cin>>department;
   cout<<"\n\n\n\t\tENTER SALARY OF EMPLOYEE : ";
   cin>>salary;
 }

/*-------------------------------------------------------------------------*/
/*           FUNCTION  : EMP_DISPLAY()                                     */
/*           CLASS     : EMPLOYEE                                          */
/*           PURPOSE   : TO DISPLAY EMPLOYEE'S RECORD                      */
/*-------------------------------------------------------------------------*/

 void employee :: emp_display()
 {
   cout<<"\n\n\n\n\t  INFORMATION OF EMPLOYEE IS AS FOLLOWS :: "<<"\n";
   cout<<"\n\n\n\t  COMPANY NAME  :  "<<co_name;
   cout<<"\n\n\n\t  DESIGNATION   :  "<<designation;
   cout<<"\n\n\n\t  DEPARTMENT    :  "<<department;
   cout<<"\n\n\n\t  SALARY        :  "<<salary<<"\n";
 }

/*-------------------------------------------------------------------------*/
/*              DECLARATION   OF   CLASS   STUDENT_EMPLOYEE                */
/*-------------------------------------------------------------------------*/

 class student_employee : public student,public employee
 {
  public:
	  void stu_emp_input()
	  {
	    s_input();
	    emp_input();
	  }
	  void stu_emp_display()
	  {
	    s_display();
	    emp_display();
	  }
 };

/*------------------------------------------------------------------------*/
/*                ***** START OF MAIN FUNCTION *****                      */
/*------------------------------------------------------------------------*/

 int main(void)
 {
   int ch;
   do
   {
    clrscr();
    cout<<"\n\n\n\t============================================";
    cout<<"\n\n\n\t    PROGRAM TO MANIPULATE PERSONAL DATA \n";
    cout<<"\n\n\t============================================";
    cout<<"\n\n\n\t     ************* MENU *************";
    cout<<"\n\n\n\t============================================";
    cout<<"\n\n\n\t\t1 : STUDENT";
    cout<<"\n\n\t\t2 : EMPLOYEE";
    cout<<"\n\n\t\t3 : STUDENT AND EMPLOYEE";
    cout<<"\n\n\t\t4 : NONE OF THE ABOVE";
    cout<<"\n\n\t\t5 : EXIT";
    cout<<"\n\n\n\t\tENTER YOUR CHOICE : ";
    cin>>ch;
    switch(ch)
    {
      case 1:
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t         RECORD FOR STUDENT ";
	      cout<<"\n\n\n\t===============================================";
	      student s;
	      s.s_input();
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t     DISPLAYING THE RECORD  ";
	      cout<<"\n\n\n\t===============================================";
	      s.s_display();
	      getch();
	      break;
      case 2:
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t           RECORD FOR EMPLOYEE  ";
	      cout<<"\n\n\n\t===============================================";
	      employee e;
	      e.p_input();
	      e.emp_input();
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t     DISPLAYING THE RECORD  ";
	      cout<<"\n\n\n\t===============================================";
	      e.p_display();
	      e.emp_display();
	      getch();
	      break;
      case 3:
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t   RECORD FOR BOTH STUDENT AND EMPLOYEE  ";
	      cout<<"\n\n\n\t===============================================";
	      student_employee stu_emp;
	      stu_emp.stu_emp_input();
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t     DISPLAYING THE RECORD  ";
	      cout<<"\n\n\n\t===============================================";
	      stu_emp.stu_emp_display();
	      getch();
	      break;
      case 4:
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t        RECORD FOR ORDINARY PERSON  ";
	      cout<<"\n\n\n\t===============================================";
	      person p;
	      p.p_input();
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t     DISPLAYING THE RECORD  ";
	      cout<<"\n\n\n\t===============================================";
	      p.p_display();
	      getch();
	      break;
      case 5:
	      exit(0);
	      break;
    }
   }while(ch!=5);
   getch();
   return 0;
 }

/*=========================================================================*/
/*                END        OF        THE       PROGRAM                   */
/*=========================================================================*/
