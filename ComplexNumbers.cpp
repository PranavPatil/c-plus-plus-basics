/*=========================================================================*/
/*        ASSIGNMENT NO : 1                 SUBJECT : OOP
/*        DATE OF COMPLETION : 10-2-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  WRITE A CLASS COMPLEX WITH DATA MEMBERS AS REAL   */
/*                       AND IMAGINARY NUMBERS AND MEMBER FUNCTIONS AS     */
/*                       READ, PRINT, ADD, SUBTRACT, MULTIPLY AND DIVIDE   */
/*=========================================================================*/
#include<iostream.h>
#include<conio.h>
#include<process.h>
class nos                    // DECLARATION OF A CLASS
{
  float  im1,im2,re1,re2;    // DECLARATION OF PRIVATE VARIABLES

  public:
	void getdata();      // DECLARATION OF PUBLIC FUNCTIONS
	void display();
	void add();
	void sub();
	void multi();
	void div();
	void line();
};

void nos :: getdata()        // FUNCTION TO GET THE DATA
{
  line();
  cout<<"\n        PROGRAM TO PERFORM OPERATIONS ON COMPLEX NOS !!\n";
  cout<<"\n        PROGRAMMER : PRANAV PATIL                      \n";
  cout<<"\n        ROLL NO    : 2955  SE IT                       \n";
  line();
  cout<<"\n\n  PLEASE ENTER FIRST COMPLEX NO : ";
  cin>>re1>>im1;
  cout<<"\n\n  PLEASE ENTER SECOND COMPLEX NO : ";
  cin>>re2>>im2;
}

void nos :: display()        // FUNCTION TO DISPLAY THE COMPLEX NOS
{
  cout<<"  THE TWO COMPLEX NOS!!\n\n\n";
  cout<<"  FIRST COMPLEX NO :: "<<re1<<" + "<<im1<<"i\n\n\n";
  cout<<"  SECOND COMPLEX NO :: "<<re2<<" + "<<im2<<"i\n";

}

void nos :: add()            // FUNCTION TO ADD TWO COMPLEX NOS
{
  line();
  cout<<"\n      OPERATION : ADDITION OF COMPLEX NOS                 \n";
  line();
  cout<<"\n\n";
  float im3,re3;
  display();
  cout<<"\n\n  ADDITION OF TWO COMPLEX NOS  ::  ";
  re3=re1+re2;
  im3=im1+im2;
  cout<<re3<<" + "<<im3<<"i\n\n\n";
}

void nos :: sub()            // FUNCTION TO SUBTRACT TWO COMPLEX NOS
{
  line();
  cout<<"\n      OPERATION : SUBTRACTION OF COMPLEX NOS                 \n";
  line();
  cout<<"\n\n";
  float im3,re3;
  display();
  cout<<"\n\n  SUBTRACTION OF TWO COMPLEX NOS  ::  ";
  re3=re1-re2;
  im3=im1-im2;
  cout<<re3<<" + "<<im3<<"i\n\n\n";
}

void nos :: multi()          // FUNCTION TO MULTIPLY TWO COMPLEX NOS
{
  line();
  cout<<"\n      OPERATION : MULTIPLICATION OF COMPLEX NOS                 \n";
  line();
  cout<<"\n\n";
  float im3,re3;
  display();
  cout<<"\n\n  MULTIPLICATION OF TWO COMPLEX NOS  ::  ";
  re3=(re1*re2)-(im1*im2);
  im3=(im1*re2)+(re1*im2);
  cout<<re3<<" + "<<im3<<"i\n\n\n";
}

void nos:: div()             // FUNCTION TO DIVIDE TWO COMPLEX NOS
{
  line();
  cout<<"\n      OPERATION : DIVISION OF COMPLEX NOS                 \n";
  line();
  cout<<"\n\n";
  float im3,re3,i1,i2,i3,r1,r2;
  display();
  cout<<"\n\n  DIVISION OF TWO COMPLEX NOS  ::  ";
  i1=((re1*re2)-(im1*(-im2)));
  i2=((im1*re2)+(re1*(-im2)));
  r1=(re2*re2)+(im2*im2);
  i3=i1/r1;
  r2=i2/r1;
  cout<<i3<<" + "<<r2<<"i";
}

void nos:: line()            // FUNCTION TO PRINT A LINE
{
  cout<<"\n===========================================================\n";
}

int  main(void)              // START OF MAIN FUNCTION
{
  clrscr();                  // CLEARING THE SCREEN
  nos c;                     // DECLARATION OF OBJECT C BELONGING TO CLASS NOS
  c.getdata();               // CALLING OBJECT FUNCTION TO ACCESS DATA
  c.line();
  clrscr();
  c.line();                  // CALLING OBJECT TO PRINT LINE
  cout<<"\n\n";
  c.display();               // CALLING OBJECT FUNCTION TO DISPLAY THE NOS
  c.line();
  getch();
  int ch;
  do                         // START OF DO-WHILE LOOP
  {
   do
   {
	 clrscr();
	 c.line();
	 cout<<"\n                   MENU     \n";    // DISPLAYING MENU
	 c.line();
	 cout<<"\n\n       1 : ADDITION";
	 cout<<"\n\n       2 : SUBTRACTION";
	 cout<<"\n\n       3 : MULTIPLICATION";
	 cout<<"\n\n       4 : DIVISION";
	 cout<<"\n\n       5 : CONTINUE";
	 cout<<"\n\n       6 : EXIT";
	 cout<<"\n\n\n       ENTER YOUR CHOICE :: ";
	 cin>>ch;
	 switch(ch)          // START OF SWITCH CASE
	 {
	  case 1 :
			   clrscr();
			   c.add();      // CALLING OBJECT TO ADD TWO NOS
			   getch();
			   break;
	  case 2 :
			   clrscr();
			   c.sub();      // CALLING OBJECT TO SUBTRACT TWO NOS
			   getch();
			   break;
	  case 3 :
			   clrscr();
			   c.multi();    // CALLING OBJECT TO MULTIPLY TWO NOS
			   getch();
			   break;
	  case 4 :
			   clrscr();
			   c.div();      // CALLING OBJECT TO DIVIDE TWO NOS
			   getch();
			   break;
	  case 5 :
			   clrscr();
			   c.getdata();
			   c.line();
			   cout<<"\n";
			   c.display();
			   cout<<"\b\b\b\b\b\b";
			   c.line();
			   break;
	  case 6 :
			   exit(0);      // EXIT FROM THE MAIN
			   getch();
			   break;
	 }
   }while(0<ch<6);
  }while(ch!=6);
   getch();
   return(0);                            // RETURNING (0) TO THE MAIN
}
/*=========================================================================*/
/*            END      OF       THE      MAIN       PROGRAM                */
/*=========================================================================*/
