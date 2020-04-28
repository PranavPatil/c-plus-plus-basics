/*=========================================================================*/
/*        ASSIGNMENT NO ::  5               SUBJECT : OOPL                 */
/*        DATE OF COMPLETION : 20-2-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  MODIFY THE CLASS STRING IN ASSIGNMENT NUMBER 2 TO */
/*                       TACKLE OPERATOR OVERLOADING AND WRITE A MAIN      */
/*                       PROGRAM TO SORT ARRAY OF STRINGS                  */
/*=========================================================================*/
#include<iostream.h>
#include<process.h>
#include<conio.h>

/*-------------------------------------------------------------------------*/
/*                    DECLARATION   OF   CLASS  STRING                     */
/*-------------------------------------------------------------------------*/

class string
{
  char *str;                        // DECLARATION OF PRIVATE MEMBERS
  int len;

  public :                          // DECLARATION OF PUBLIC MEMBERS

  string();                         // DECLARATION OF CONSTRUCTER
  string(int x);                    // DECLARATION OF COPY CONSTRUCTER
  void accept();
  int length();                     // DECLARATION OF MEMBER FUNCTIONS
  void substring(string);
  int lengthst(char *s);
  char* copyst(char *str,char *s);
  string operator+(string B);       // DECLARATION OF OVERLOADED OPERATOR'S
  string operator=(string s);
  int operator==(string s);
  string operator-();
  int operator >(string s2);
  friend ostream & operator << (ostream &,string &);
};

/*-------------------------------------------------------------------------*/
/*           CONSTRUCTOR : COPY CONSTRUCTOR         			   */
/*           PURPOSE    :  TO CREATE AND INITIALISE THE STRING             */
/*-------------------------------------------------------------------------*/

string :: string(int x)             // DEFINITION OF COPY CONSTRUCTER
{
  len = x;
  str = new char[len+1];
}

/*-------------------------------------------------------------------------*/
/*           CONSTRUCTOR : EMPTY CONSTRUCTOR         		           */
/*           PURPOSE    :  TO CREATE AN EMPTY STRING                       */
/*-------------------------------------------------------------------------*/

string :: string()                  //DEFINITION OF CONSTRUCTER
{
  len = 0;
  str = new char[len+1];
}

 int main(void)
/*------------------------------------------------------------------------*/
/*                ***** START OF MAIN FUNCTION *****                      */
/*------------------------------------------------------------------------*/
 {
   char an,*st;         /* DECLARATION OF VARIABLES */
   int l,ln;
   string A,B;

/*------------------------------------------------------------------------*/
/*                   **** DISPLAYING THE MENU ****                             */
/*------------------------------------------------------------------------*/
 do{
    clrscr();
    cout<<"\n\n\n\t";
    cout<<"=========================================================";
    cout<<"\n\n\t                ****   MENU   ****                \n\n\t";
    cout<<"=========================================================";
    cout<<"\n\n\n\n\t        0 : ACCEPT STRING               ";
    cout<<"\n\n\t        1 : DISPLAY STRING               ";
    cout<<"\n\n\t        2 : LENGTH OF STRING               ";
    cout<<"\n\n\t        3 : REVERSE THE STRING                      ";
    cout<<"\n\n\t        4 : COPY STRINGS                      ";
    cout<<"\n\n\t        5 : CONCATINATE BOTH STRINGS 	 ";
    cout<<"\n\n\t        6 : COMPARE BOTH STRINGS  	 ";
    cout<<"\n\n\t        7 : PALINDROME CHECK            ";
    cout<<"\n\n\t        8 : DETECTION OF SUBSTRING          ";
    cout<<"\n\n\t        9 : SORTING OF STRING'S      ";
    cout<<"\n\n\t        * : EXIT                       ";
    cout<<"\n\n\t        ENTER YOUR CHOICE :  ";
    cin>>an;
/*-------------------------------------------------------------------------*/
/*              **** START OF SWITCH CASE ****                             */
/*-------------------------------------------------------------------------*/
    switch(an)
    {
      case '0':
		clrscr();
		cout<<"\t====================================================";
		cout<<"\n\n\n\t\t   ENTRY OF THE STRINGS  !!\n\n\n\t";
		cout<<"====================================================";
		cout<<"\n\n\n\n";
		cout<<"\n\n\n\t   ENTER THE TWO STRINGS AS FOLLOWS !!";
		cout<<"\n\n\n\n\n\t   ENTER THE CHARACTERS FOR STRING 1 :  ";
		A.accept();
		cout<<"\n\n\n\t   ENTER THE CHARACTERS FOR STRING 2 :  ";
		B.accept();
		getch();
		break;
      case '1':
		clrscr();
		cout<<"\t====================================================";
		cout<<"\n\n\n\t\t   DISPLAYING THE STRINGS  !!\n\n\n\t";
		cout<<"====================================================";
		cout<<"\n\n\n\n\t     STRING 1 =  "<<A;
		cout<<"\n\n\n\n\t     STRING 2 =  "<<B;
		getch();
		break;
      case '2':
		clrscr();
		cout<<"\t==================================================";
		cout<<"\n\n\n\t\t   DETECTION LENGTH OF STRINGS !!\n\n\n\t";
		cout<<"==================================================";
		ln = A.length();
		cout<<"\n\n\n\n\t    LENGTH OF STRING  "<<A<<"  :  "<<ln;
		ln = B.length();
		cout<<"\n\n\n\n\t    LENGTH OF STRING  "<<B<<"  :  "<<ln;
		getch();
		break;
      case '3':
		clrscr();
		cout<<"\t==================================================\n";
		cout<<"\n\n\t      OPERATION TO REVERSE THE STRINGS !!\n\n";
		cout<<"\n\t==================================================";
		cout<<"\n\n\n\n\t   REVERSE OF STRING  "<<A<<" =  ";
		string AR(A.length());
		AR = -A;           /* CALLING FUNCTION  reverse() */
		cout<<AR;
		cout<<"\n\n\n\n\t   REVERSE OF STRING  "<<B<<" =  ";
		string BR(B.length());
		BR = -B;         /* CALLING FUNCTION  reverse() */
		cout<<BR;
		getch();
		break;
      case '4':
		int i,no;
		do
		{
		 clrscr();
		 cout<<"\n\t================================================";
		 cout<<"\n\n\n\t    ***  OPERATION TO COPY STRINGS !!  **\n\n";
		 cout<<"\n\t================================================";
		 cout<<"\n\n\n\t\t     ****  MENU  ****        ";
		 cout<<"\n\n\n\t     1: COPY OF STRING 1 TO STRING 2 ";
		 cout<<"\n\n\n\t     2: COPY OF STRING 2 TO STRING 1 ";
		 cout<<"\n\n\n\t     3: EXIT ";
		 cout<<"\n\n\n\n\t     ENTER YOUR CHOICE :  ";
		 cin>>no;
		 switch(no)
		 {
		   case 1:
		   cout<<"\n\n\n";
		   cout<<"\n\n\n\t     ORIGINAL STRING 1 :  "<<A;
		   cout<<"\n\n\n\t     COPY OF STRING 1 TO STRING 2 IS :  ";
		   A = B;
		   cout<<A;
		   getch();
		   break;

		   case 2:
		   cout<<"\n\n\n";
		   cout<<"\n\n\n\t     ORIGINAL STRING 2 :  "<<B;
		   cout<<"\n\n\n\t     COPY OF STRING 2 TO STRING 1 IS :  ";
		   B = A;
		   cout<<B;
		   getch();
		   break;

		   case 3:
		   break;
		 }
		}while(no != 3);
		break;
      case '5':
		clrscr();
		int le;
		cout<<"\n\n\t";
		cout<<"================================================";
		cout<<"\n\n\tOPERATION TO PERFORM CONCATINATION OF STRING ";
		cout<<"\n\n\t================================================";
		cout<<"\n\n\n\t  CONCATINATION OF STRING 1 AND STRING 2 IS :";
		le = A.length() + B.length();
		string CON(le);
		CON = A+B;
		cout<<CON;
		getch();
		break;
      case '6':
		clrscr();
		int fl=0;
		cout<<"\t================================================================";
		cout<<"\n\n\n\t    COMRARISION BETWEEN STRING 1 AND STRING 2 IS !!\n\n\n\t";
		cout<<"================================================================";
		cout<<"\n\n\n\n\t   STRING 1 =  "<<A;
		cout<<"\n\n\n\n\t   STRING 2 =  "<<B;
		fl = (A == B);
		if (fl==1)
		cout<<"\n\n\n\n\n\t\t*** STRINGS ARE EQUAL ***\n\n";
		else
		cout<<"\n\n\n\n\n\t\t*** STRINGS ARE NOT EQUAL ***\n\n";
		getch();
		break;
      case '7':
		clrscr();
		int flag=0;
		cout<<"\n\t=================================================";
		cout<<"\n\n\t      **** DETECTION OF PALINDROME !! ****\n";
		cout<<"\n\t=================================================";
		cout<<"\n\n\n\n\t\tSTRING 1 = ";
		flag = (A == (-A));
		if (flag==1)
		  cout<<" PALLINDROME";
		else if(flag==0)
		  cout<<" NOT A PALLINDROME";
		flag = 0;
		cout<<"\n\n\n\n\t\tSTRING 2 = ";
		flag = (B == (-B));
		if (flag==1)
		  cout<<" PALLINDROME";
		else if(flag==0)
		  cout<<" NOT A PALLINDROME";
		getch();
		break;
      case '8':
		int no1;
		do
		{
		 clrscr();
		 cout<<"\n\t====================================================";
		 cout<<"\n\n\t          DETECTION OF SUBSTRING !!";
		 cout<<"\n\n\t====================================================";
		 cout<<"\n\n\n\t           *** MENU ***           \n\n";
		 cout<<"\n\n\n\t  1: FIND SUBSTRING 2 IN STRING 1 ";
		 cout<<"\n\n\n\t  2: FIND SUBSTRING 1 IN STRING 2 ";
		 cout<<"\n\n\n\t  3: EXIT ";
		 cout<<"\n\n\n\t  ENTER YOUR CHOICE :  ";
		 cin>>no1;
		 switch(no1)
		 {
		   case 1:
			     A.substring(B);
			     break;
		   case 2:
			     B.substring(A);
			     break;
		   case 3:
			     break;
		 }
		}while(no1!= 3);
		break;
      case '9':
		string D[10],G1;
		int n,j;
		flag = 0;
		clrscr();
		cout<<"\t==================================================\n";
		cout<<"\n\n\t      OPERATION TO SORT THE STRINGS !!\n\n";
		cout<<"\n\t==================================================";
		cout<<"\n\n\n\n\t   ENTER NO OF STRINGS  :  ";
		cin>>n;
		if(n<=0 || n>10)
		{
		  cout<<"\n\n\n\n\t\t INVALID INPUT  !!";
		  break;
		}
		for(i=0;i<n;i++)
		{
		  cout<<"\n\n\n\t   ENTER THE STRING NO "<<i+1<<" :  ";
		  D[i].accept();
		}
		for(i=n-1;i>=0;i--)
		{
		  flag=0;
		  for(j=0;j<i;j++)
		  {
		    if(D[j+1] > D[j])
		    {
		     flag=1;
		     G1=D[j];
		     D[j]=D[j+1];
		     D[j+1]=G1;
		    }
		  }
		  if(flag==0)
		    break;
		}
		cout<<"\n\n\n\t   SORTED STRINGS  : \n\n";
		for(i=0;i<n;i++)
		  cout<<"\n\n\t\t\t"<<D[i];
		getch();
		break;
      case '*':
		exit(0);
    }
   }while(an!='*');
   return(0);
}

/*-------------------------------------------------------------------------*/
/*                 ****  END OF MAIN FUNCTION  ****                        */
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/*                 ******** START OF FUNCTION accept() ********            */
/*-------------------------------------------------------------------------*/

 void string :: accept()
 {
    char  *s;
    s = new char[30];
    cin>>s;                                   /* ACCEPTING STRING */
    len = lengthst(s);
    str = new char[len+1];
    str = copyst(str,s);
 }

/*-------------------------------------------------------------------------*/
/*           FUNCTION  : lengthg()                                         */
/*           PURPOSE   : TO FIND THE LENGTH OF STRING                      */
/*-------------------------------------------------------------------------*/

 int string :: lengthst(char *s)
 {
  int i,j;
  for(i=0;s[i] !='\0';i++)
    s[i];
  s[i]='\0';
  return(i);
 }

/*-------------------------------------------------------------------------*/
/*           FUNCTION   :  copyg()                                         */
/*           PURPOSE    :  TO COPY A STRING                                */
/*-------------------------------------------------------------------------*/

 char* string :: copyst(char *str,char *s)
 {
   int i,m;
   m = lengthst(s);
   for(i=0;i<m+1;i++)
     str[i]=s[i];
   str[i]='\0';
   return(str);
 }

/*-------------------------------------------------------------------------*/
/*           OPERATOR   :  =()          				   */
/*           PURPOSE    :  TO COPY A STRING FROM ANOTHER                   */
/*           PARAMETERS :  OBJECT B OF CLASS STRING                        */
/*           RETURN TYPE : OBJECT INVOKED OF CLASS NOS                     */
/*-------------------------------------------------------------------------*/

 string string :: operator=(string B)
 {
   int i;
   for(i=0;B.str[i] !='\0';i++)
   {
     str[i]=B.str[i];
   }
   str[i]='\0';
   return(*this);
 }

/*-------------------------------------------------------------------------*/
/*           OPERATOR   :  ==()          				   */
/*           PURPOSE    :  TO COMPARE TWO STRING'S FOR EQUALITY            */
/*           PARAMETERS :  OBJECT B OF CLASS STRING                        */
/*           RETURN TYPE : INTEGER FLAG                                    */
/*-------------------------------------------------------------------------*/

 int string :: operator==(string B)
 {
   int i=0,j=0,flag;
   while(str[i]==B.str[j] && str[i]!='\0' && B.str[j]!='\0')
   {
     i++,j++;
   }
   if(str[i]=='\0' && B.str[j]=='\0')
     flag = 1;
   else
     flag = 0;
   return(flag);
 }

/*-------------------------------------------------------------------------*/
/*           FUNCTION   :  length()                                        */
/*           PURPOSE    :  TO FIND THE LENGTH OF THE OBJECT STRING         */
/*-------------------------------------------------------------------------*/

 int string :: length()
 {  int i,j;
    for(i=0;str[i] !='\0';i++)
    {
       str[i];
    }
    str[i]='\0';
    return(i);
 }

/*-------------------------------------------------------------------------*/
/*           OPERATOR   :  -()          				   */
/*           PURPOSE    :  TO REVERSE THE SRING                            */
/*           PARAMETERS :  VOID                                            */
/*           RETURN TYPE : OBJECT S OF CLASS STRING                        */
/*-------------------------------------------------------------------------*/

 string string  :: operator-()
 {
   int i,j=0,len=0,count=0;
   len = length();
   string S(len);
   for(i=0;str[i]!='\0';i++)
   {
      count=count+1;
   }
   for(i=count-1;i>=0;i--)
   {
     S.str[j] = str[i];
     j++;
   }
   S.str[j] = '\0';
   return(S);
 }

/*-------------------------------------------------------------------------*/
/*           OPERATOR   :  +()          				   */
/*           PURPOSE    :  TO CONCATINATE BOH STRINGS       	           */
/*           PARAMETERS :  OBJECT B OF CLASS STRING                        */
/*           RETURN TYPE : OBJECT INVOKED OF CLASS STRING                  */
/*-------------------------------------------------------------------------*/

 string string :: operator+(string B)
 {
   int i,j,l1,l2;
   l1 =  length();
   l2 =  B.length();
   string C(l1+l2);
   for(i=0;str[i] !='\0';i++)
   {
     C.str[i]=str[i];
   }
   for(j=0;B.str[j] !='\0';j++)
   {
     C.str[i+j]=B.str[j];
   }
   C.str[i+j]='\0';
   return(C);
 }

/*-------------------------------------------------------------------------*/
/*           OPERATOR   :  >()          				   */
/*           PURPOSE    :  TO COMPARE BOTH THE STRINGS       	           */
/*           PARAMETERS :  OBJECT S2 OF CLASS STRING                       */
/*           RETURN TYPE : INEGER  			                   */
/*-------------------------------------------------------------------------*/

 int string::operator >(string s2)
 {
   int   i=0,j=0,k,k1,flag=0;
   while(str[i] != '\0' && s2.str[i] != '\0' && flag==0)
   {
     k = str[i];
     j = s2.str[i];
     if(k != j)
     {
       flag = 1;
       if(k<j)
	 k1=1;
       else
	 k1=0;
       break;
     }
     else if(k==j)
     {
       if(str[i+1] == '\0')
       { flag = 1;
	 k1 = 1; }
       else if(s2.str[i+1] == '\0')
       { flag = 1;
	 k1 = 0;  }
       i++;
     }
   }
   return(k1);
 }

/*-------------------------------------------------------------------------*/
/*           OPERATOR   :  =()          				   */
/*           PURPOSE    :  TO COPY A STRING                                */
/*-------------------------------------------------------------------------*/

 ostream & operator << (ostream &dout,string &b)
 {
    dout<<"\" ";
    for(int i=0;b.str[i] != '\0';i++)
       dout<<b.str[i];
    dout<<" \"";
    return(dout);
 }

/*-------------------------------------------------------------------------*/
/*           FUNCTION    :   substring()                                   */
/*           PURPOSE     :   TO DETECT A SUBSTRING FROM ANOTHER STRING     */
/*-------------------------------------------------------------------------*/

 void string :: substring(string C)
 {
   int i=0,j=0,flag=0;

   while(str[i]!='\0'&& C.str[j]!='\0')
   {
     if(C.str[j]==str[i])
     {
       i++,j++;
       flag=0;
     }
     else
     {
       if(C.str[j]!=str[i])
       {
	 i++;
	 flag=1;
       }
     }
   }
   if(flag==1)
     cout<<"\n\n\n\n\t\t#### SUBSTRING  ABSENT !! ####";
   if(flag==0)
     cout<<"\n\n\n\n\t\t#### SUBSTRING  PRESENT !! ####";
   getch();
 }

/*-------------------------------------------------------------------------*/
/*         *+*+*+*+*+*+*+*+  END OF THE PROGRAM  *+*+*++*+*+*+*+*+         */
/*-------------------------------------------------------------------------*/
