/*=========================================================================*/
/*        ASSIGNMENT NO : 4                 SUBJECT : OOP                  */
/*        DATE OF COMPLETION : 8-2-03       CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  MODIFY THE CLASS COMPLEX IN ASSIGNMENT NO 1 TO    */
/*                       TACKLE OPERATOR OVERLOADING                       */
/*=========================================================================*/
#include<iostream.h>
#include<conio.h>
#include<process.h>
class nos                    // DECLARATION OF A CLASS
{
  float  im,re;              // DECLARATION OF PRIVATE VARIABLES

  public:
	  nos() {    };       // DECLARATION OF CONSTRUCTOR
	  nos(int,int);       // DECLARATION OF  COPY CONSTRUCTOR
	  friend ostream & operator << (ostream &,nos &);
	  nos nos :: operator+(nos A);
	  nos nos :: operator-(nos S);   // DECLARATION OF OPERATOR'S
	  nos nos :: operator*(nos M);
	  nos nos:: operator/(nos D);
};

/*-------------------------------------------------------------------------*/
/*           CONSTRUCTOR : COPY CONSTRUCTOR         			   */
/*           PURPOSE    :  TO INITIALISE THE COMPLEX NUMBER                */
/*-------------------------------------------------------------------------*/

nos :: nos(int x,int y)        // FUNCTION TO GET THE DATA
{
  re = x;
  im = y;
}

/*-------------------------------------------------------------------------*/
/*           OPERATOR   :  +()          				   */
/*           PURPOSE    :  TO ADD TWO COMPLEX NUMBERS                      */
/*           PARAMETERS :  OBJECT A OF CLASS NOS                           */
/*           RETURN TYPE : OBJECT AD OF CLASS NOS                          */
/*-------------------------------------------------------------------------*/

nos  nos ::  operator+(nos A)            // FUNCTION TO ADD TWO COMPLEX NOS
{
  nos AD;
  AD.re = re + A.re;
  AD.im = im + A.im;
  return(AD);
}

/*-------------------------------------------------------------------------*/
/*           OPERATOR   :  -()          				   */
/*           PURPOSE    :  TO SUBTRACT TWO COMPLEX NUMBERS                 */
/*           PARAMETERS :  OBJECT S OF CLASS NOS                           */
/*           RETURN TYPE : OBJECT SU OF CLASS NOS                          */
/*-------------------------------------------------------------------------*/

nos nos :: operator-(nos S)            // FUNCTION TO SUBTRACT TWO COMPLEX NOS
{
  nos SU;
  SU.re=re-S.re;
  SU.im=im-S.im;
  return(SU);
}

/*-------------------------------------------------------------------------*/
/*           OPERATOR   :  *()          				   */
/*           PURPOSE    :  TO MULTIPLY THE COMPLEX NUMBERS                 */
/*           PARAMETERS :  OBJECT M OF CLASS NOS                           */
/*           RETURN TYPE : OBJECT MU OF CLASS NOS                          */
/*-------------------------------------------------------------------------*/

nos nos :: operator*(nos M)          // FUNCTION TO MULTIPLY TWO COMPLEX NOS
{
  nos MU;
  MU.re=(re * M.re) - (im * M.im);
  MU.im=(im * M.re) + (re * M.im);
  return(MU);
}

/*-------------------------------------------------------------------------*/
/*           OPERATOR   :  /()          				   */
/*           PURPOSE    :  TO DIVIDE THE COMPLEX NUMBERS                   */
/*           PARAMETERS :  OBJECT D OF CLASS NOS                           */
/*           RETURN TYPE : OBJECT DI OF CLASS NOS                          */
/*-------------------------------------------------------------------------*/

nos nos:: operator/(nos D)             // FUNCTION TO DIVIDE TWO COMPLEX NOS
{
  float i1,i2,i3,r1,r2;
  i1 = ((re * D.re) - (im * (-D.im)));
  i2 = ((im * D.re) + (re * (-D.im)));
  r1 = (D.re * D.re) + (D.im * D.im);
  i3=i1/r1;
  r2=i2/r1;
  nos DI(i3,r2);
  return(DI);
}

/*-------------------------------------------------------------------------*/
/*           OPERATOR   :  <<()          				   */
/*           PURPOSE    :  TO DISPLAY THE COMPLEX NO                       */
/*           PARAMETERS :  OBJECT CLASS NOS , OSTREAM &                    */
/*           RETURN TYPE : OSTREAM &                                       */
/*-------------------------------------------------------------------------*/

ostream & operator << (ostream &dout,nos &c)
{
  dout<<c.re<<"  +  "<<c.im<<"i";
  return(dout);
}

/*-------------------------------------------------------------------------*/
/*           FUNCTION   :  LINE()          				   */
/*           PURPOSE    :  TO DISPLAY A LINE                               */
/*-------------------------------------------------------------------------*/

void line();
void line()
{
  cout<<"\n\t===========================================================\n";
}

/*=========================================================================*/
/*	              START OF THE MAIN FUNCTION                           */
/*=========================================================================*/

int  main(void)              // START OF MAIN FUNCTION
{
  char ch;
  do                         // START OF DO-WHILE LOOP
  {
    clrscr();
    line();
    cout<<"\n\n\t\t             MENU     \n\n";
    line();
    cout<<"\n\n\n\n\t\t   1 : ACCEPT";
    cout<<"\n\n\t\t   2 : DISPLAY";
    cout<<"\n\n\t\t   3 : ADDITION";
    cout<<"\n\n\t\t   4 : SUBTRACTION";
    cout<<"\n\n\t\t   5 : MULTIPLICATION";
    cout<<"\n\n\t\t   6 : DIVISION";
    cout<<"\n\n\t\t   7 : EXIT";
    cout<<"\n\n\n\t\t   ENTER YOUR CHOICE :: ";
    cin>>ch;
    switch(ch)             // START OF SWITCH CASE
    {
      case '1' :
		 clrscr();
		 int real,imag;
		 line();
		 cout<<"\n\n\t\tOPERATION : TO ACCEPT THE COMPLEX NUMBERS \n\n";
		 line();
		 cout<<"\n\n\n\n\n\t    PLEASE ENTER FIRST COMPLEX NO : ";
		 cin>>real>>imag;
		 nos C1(real,imag);
		 cout<<"\n\n\n\n\t    PLEASE ENTER SECOND COMPLEX NO : ";
		 cin>>real>>imag;
		 nos C2(real,imag);
		 getch();
		 break;
      case '2' :
		 clrscr();
		 line();
		 cout<<"\n\n\t\tOPERATION : DISPLAYING THE COMPLEX NOS \n\n";
		 line();
		 cout<<"\n\n\n\n\t    THE TWO COMPLEX NOS!!\n\n\n\n";
		 cout<<"\t    FIRST COMPLEX NO :: "<<C1<<"\n\n\n\n";
		 cout<<"\t    SECOND COMPLEX NO :: "<<C2<<"\n";
		 getch();
		 break;
      case '3' :
		 clrscr();
		 nos ADD;
		 line();
		 cout<<"\n\n\t\tOPERATION : ADDITION OF COMPLEX NOS \n\n";
		 line();
		 cout<<"\n\n\n\t    THE TWO COMPLEX NOS!!\n\n\n";
		 cout<<"\t    FIRST COMPLEX NO :: "<<C1<<"\n\n\n";
		 cout<<"\t    SECOND COMPLEX NO :: "<<C2<<"\n";
		 ADD = C1 + C2;
		 cout<<"\n\n\n\t    ADDITION OF TWO COMPLEX NOS  ::  "<<ADD;
		 getch();
		 break;
      case '4' :
		 clrscr();
		 nos SUB;
		 line();
		 cout<<"\n\n\t\tOPERATION : SUBTRACTION OF COMPLEX NOS \n\n";
		 line();
		 cout<<"\n\n\n\t    THE TWO COMPLEX NOS!!\n\n\n";
		 cout<<"\t    FIRST COMPLEX NO :: "<<C1<<"\n\n\n";
		 cout<<"\t    SECOND COMPLEX NO :: "<<C2<<"\n\n\n\n";
		 SUB = C1 - C2;
		 cout<<"\t    SUBTRACTION OF TWO COMPLEX NOS  ::  "<<SUB;
		 getch();
		 break;
      case '5' :
		 clrscr();
		 nos MUL;
		 line();
		 cout<<"\n\n\t\tOPERATION : MULTIPLICATION OF COMPLEX NOS\n\n";
		 line();
		 cout<<"\n\n\n\t    THE TWO COMPLEX NOS!!\n\n\n";
		 cout<<"\t    FIRST COMPLEX NO :: "<<C1<<"\n\n\n";
		 cout<<"\t    SECOND COMPLEX NO :: "<<C2<<"\n\n\n\n";
		 MUL = C1 * C2;
		 cout<<"\t    MULTIPLICATION OF TWO COMPLEX NOS  ::  "<<MUL;
		 getch();
		 break;
      case '6' :
		 clrscr();
		 nos DIV;
		 line();
		 cout<<"\n\n\t\tOPERATION : DIVISION OF COMPLEX NOS\n\n";
		 line();
		 cout<<"\n\n\n\t    THE TWO COMPLEX NOS!!\n\n\n";
		 cout<<"\t    FIRST COMPLEX NO :: "<<C1<<"\n\n\n";
		 cout<<"\t    SECOND COMPLEX NO :: "<<C2<<"\n\n\n\n";
		 DIV = C1 / C2;
		 cout<<"\t    DIVISION OF TWO COMPLEX NOS  ::  "<<DIV;
		 getch();
		 break;
      case '7' :
		 exit(0);     // EXIT FROM THE MAIN
		 break;
    }
  }while(ch != '7');
  getch();
  return(0);                            // RETURNING (0) TO THE MAIN
}
/*=========================================================================*/
/*            END      OF       THE      MAIN       PROGRAM                */
/*=========================================================================*/
