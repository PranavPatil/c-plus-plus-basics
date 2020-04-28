/*=========================================================================*/
/*        ASSIGNMENT NO ::  3               SUBJECT : OOPL                 */
/*        DATE OF COMPLETION : 20-2-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  WRITE A CLASS TO HANDLE CHRACTER ARRAY WITH DATA  */
/*                       MEMBERS IS ARRAY AND MEMBER FUNCTIONS ARE READ    */
/*                       DISPLAY,CONCAT,SUBSTRING,EQUAL AND ALSO USE       */
/*                       CONSTRUCTORS LIKE STRING S1,S2("ab") & DESTRUCTOR */
/*=========================================================================*/
#include<iostream.h>
#include<process.h>
#include<conio.h>

class string                       // DECLARATION OF CLASS
{
  char *str;                      // DECLARATION OF PRIVATE MEMBERS
  int len;

  public :                          // DECLARATION OF PUBLIC MEMBERS

  string();                         // DECLARATION OF CONSTRUCTER
  string(int x);                    // DECLARATION OF COPY CONSTRUCTER
  ~string() {  };                   // DECLARATION OF DESTRUCTOR
  void accept();
  void display();
  int length();                    // DECLARATION OF MEMBER FUNCTIONS
  char* reverse();
  void compare(string);
  void copy(string);
  void palindrome();
  void concatinate(int ,string);
  void substring(string);
  int lengthst(char *s);
  char* copyst(char *str,char *s);
};

string :: string(int x)             // DEFINITION OF COPY CONSTRUCTER
{
  len = x;
  str = new char[len+1];
}

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
   char no,*st;         /* DECLARATION OF VARIABLES */
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
    cout<<"\n\n\n\n\t        1: ACCEPT STRING               ";
    cout<<"\n\n\t        2: DISPLAY STRING               ";
    cout<<"\n\n\t        3: LENGTH OF STRING               ";
    cout<<"\n\n\t        4: REVERSE THE STRING                      ";
    cout<<"\n\n\t        5: COPY STRINGS                      ";
    cout<<"\n\n\t        6: CONCATINATE BOTH STRINGS 	 ";
    cout<<"\n\n\t        7: COMPARE BOTH STRINGS  	 ";
    cout<<"\n\n\t        8: PALINDROME CHECK            ";
    cout<<"\n\n\t        9: DETECTION OF SUBSTRING          ";
    cout<<"\n\n\t        0: EXIT                       ";
    cout<<"\n\n\t        ENTER YOUR CHOICE :  ";
    cin>>no;
/*-------------------------------------------------------------------------*/
/*              **** START OF SWITCH CASE ****                             */
/*-------------------------------------------------------------------------*/
    switch(no)
    {
      case '1':
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
      case '2':
		clrscr();
		cout<<"\t====================================================";
		cout<<"\n\n\n\t\t   DISPLAYING THE STRINGS  !!\n\n\n\t";
		cout<<"====================================================";
		cout<<"\n\n\n\n\t     STRING 1 = ";
		A.display();
		cout<<"\n\n\n\n\t     STRING 2 = ";
		B.display();
		getch();
		break;
      case '3':
		clrscr();
		cout<<"\t==================================================";
		cout<<"\n\n\n\t\t   DETECTION LENGTH OF STRINGS !!\n\n\n\t";
		cout<<"==================================================";
		ln = A.length();
		cout<<"\n\n\n\n\t    LENGTH OF STRING  ";
		A.display();
		cout<<"  : "<<ln;
		ln = B.length();               // CALLING FUNCTION  length()
		cout<<"\n\n\n\n\t    LENGTH OF STRING  ";
		B.display();
		cout<<"  : "<<ln;
		getch();
		break;
      case '4':
		clrscr();
		cout<<"\t==================================================\n";
		cout<<"\n\n\t      OPERATION TO REVERSE THE STRINGS !!\n\n";
		cout<<"\n\t==================================================";
		cout<<"\n\n\n\n\t   REVERSE OF STRING  ";
		A.display();
		st = A.reverse();       /* CALLING FUNCTION  reverse() */
		cout<<"  : "<<st;
		cout<<"\n\n\n\n\t   REVERSE OF STRING  ";
		B.display();
		st = B.reverse();       /* CALLING FUNCTION  reverse() */
		cout<<"  : "<<st;
		getch();
		break;
      case '5':
		clrscr();
		A.copy(B);          /* CALLING FUNCTION  copy() */
		getch();
		break;
      case '6':
		clrscr();
		l = B.length();
		A.concatinate(l,B); /* CALLING FUNCTION concatinate() */
		getch();
		break;
      case '7':
		clrscr();
		A.compare(B);       /* CALLING FUNCTION  compare() */
		getch();
		break;
      case '8':
		clrscr();
		cout<<"\n\t=================================================";
		cout<<"\n\n\t      **** DETECTION OF PALINDROME !! ****\n";
		cout<<"\n\t=================================================";
		cout<<"\n\n\n\n\t\tSTRING 1 = ";
		A.palindrome();    /* CALLING FUNCTION  palindrome() */
		cout<<"\n\n\n\n\t\tSTRING 2 = ";
		B.palindrome();
		getch();
		break;
      case '9':
		int no;
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
		 cin>>no;
		 switch(no)
		 {
		   case 1:
			     A.substring(B);/* CALLING FUNCTION substring() */
			     break;
		   case 2:
			     B.substring(A);/* CALLING FUNCTION substring() */
			     break;
		   case 3:
			     break;
		 }
		}while(no!= 3);
		break;
      case '0':
		exit(0);
    }
   }while(no!='0');
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
/*           FUNCTION  :  display()                                        */
/*           PURPOSE   : TO DISPLAY THE STRING                             */
/*-------------------------------------------------------------------------*/

 void string :: display()
 {
    cout<<"\" ";
    cout<<str;
    cout<<" \"";
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
/*=========================END OF FUNCTION length()========================*/

/*-------------------------------------------------------------------------*/
/*           FUNCTION   :  reverse()                                       */
/*           PURPOSE    :  TO REVERSE THE STRING                           */
/*-------------------------------------------------------------------------*/
 char* string :: reverse()
 {
   int i,j=0,len,count=0;
   char *st;
   len = length();
   st = new char[len+1];
   for(i=0;str[i]!='\0';i++)
   {
      count=count+1;
   }
   for(i=count-1;i>=0;i--)
   {
     st[j] = str[i];
     j++;
   }
   st[j] = '\0';
   return(st);
 }
/*=========================END OF FUNCTION reverse()=======================*/

/*-------------------------------------------------------------------------*/
/*           FUNCTION    :  copy()                                         */
/*           PURPOSE     :  TO COPY ONE STRING INTO ANOTHER                */
/*-------------------------------------------------------------------------*/
 void string :: copy(string B)
 {
   int i,no;
   do
   {
    clrscr();
    cout<<"\n\t========================================================";
    cout<<"\n\n\n\t\t  ***  OPERATION TO COPY STRINGS !!  **\n";
    cout<<"\n\n\t========================================================";
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
	      cout<<"\n\n\n\t     ORIGINAL STRING 1 :\" "<<str<<"  \"";
	      cout<<"\n\n\n\t     COPY OF STRING 1 TO STRING 2 IS :\" ";
	      for(i=0;str[i] !='\0';i++)
	      {
		str[i]=B.str[i];
	      }
	      str[i]='\0';
	      cout<<str;
	      getch();
	      break;
      case 2:
	      cout<<"\n\n\n";
	      cout<<"\n\n\n\t     ORIGINAL STRING 2 :\" "<<B.str<<"  \"";
	      cout<<"\n\n\n\t     COPY OF STRING 2 TO STRING 1 IS :\" ";
	      for(i=0;B.str[i] !='\0';i++)
	      {
		B.str[i]=str[i];
	      }
	      B.str[i]='\0';
	      cout<<B.str;
	      getch();
	      break;
      case 3:
	      break;
    }
   }while(no!=3);
 }
/*=========================END OF FUNCTION copy()==========================*/

/*-------------------------------------------------------------------------*/
/*           FUNCTION    :  concatinate()                                  */
/*           PURPOSE     :  TO CONCATINATE BOH STRINGS                     */
/*-------------------------------------------------------------------------*/
 void string :: concatinate(int l2,string B)
 {
   int i,j,l1;
   string C;
   cout<<"\n\n\t";
   cout<<"===========================================================";
   cout<<"\n\n\t      OPERATION TO PERFORM CONCATINATION OF STRING !!";
   cout<<"\n\n\t===========================================================";
   cout<<"\n\n\n\t  CONCATINATION OF STRING 1 AND STRING 2 IS :";
   l1 =  length();
   C.str = new char[l1+l2+1];
   for(i=0;str[i] !='\0';i++)
   {
     C.str[i]=str[i];
   }
   for(j=0;B.str[j] !='\0';j++)
   {
     C.str[i+j]=B.str[j];
   }
   C.str[i+j]='\0';
   cout<<"  "<<C.str<<"\n";
 }
/*=========================END OF FUNCTION concatinate()===================*/

/*-------------------------------------------------------------------------*/
/*           FUNCTION    :  compare() 				           */
/*           PURPOSE     :  TO COMPARE BOTH THE STRINGS                    */
/*-------------------------------------------------------------------------*/
 void string :: compare(string B)
 {
   int i,j;
   cout<<"\t================================================================";
   cout<<"\n\n\n\t    COMRARISION BETWEEN STRING 1 AND STRING 2 IS !!\n\n\n\t";
   cout<<"================================================================";
   cout<<"\n\n\n\n\t   STRING 1 = \" ";
   cout<<str;
   cout<<" \"";
   cout<<"\n\n\n\n\t   STRING 2 = \" ";
   cout<<B.str;
   cout<<" \"";
   i=0;
   j=0;
   while(str[i]==B.str[j] && str[i]!='\0' && B.str[j]!='\0')
   {
     i++;
     j++;
   }
   if(str[i]=='\0' && B.str[j]=='\0')
   cout<<"\n\n\n\n\n\t\t*** STRINGS ARE EQUAL ***\n\n";
   else
   cout<<"\n\n\n\n\n\t\t*** STRINGS ARE NOT EQUAL ***\n\n";
 }
/*=========================END OF FUNCTION compare()=======================*/

/*-------------------------------------------------------------------------*/
/*           FUNCTION    :   palindrome()                                  */
/*           PURPOSE     :   TO CHECK WHETHER THE STRING IS PALINDROME     */
/*-------------------------------------------------------------------------*/

 void string :: palindrome()
 {
   int i,j,k,h,flag;
   char *temp;
   temp = reverse();

   for(i=0;str[i]!='\0';i++)
   {
     if(str[i]==temp[i])
       flag = 1;
     else
       flag = 0;
   }
   if(flag==1)
   cout<<" PALLINDROME";
   if(flag==0)
   cout<<" NOT A PALLINDROME";
 }

/*=========================END OF FUNCTION palindrome()====================*/

/*-------------------------------------------------------------------------*/
/*           FUNCTION    :   substring()                                   */
/*           PURPOSE     :   TO DETECT A SUBSTRING FROM ANOTHER STRING     */
/*-------------------------------------------------------------------------*/
 void string :: substring(string C)
 {
   int i=0,j=0,no,flag=0;

   while(str[i]!='\0'&& C.str[j]!='\0')
   {
     if(C.str[j]==str[i])
     {
       i++;
       j++;
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
   {
     cout<<"\n\n\n\n\t\t#### SUBSTRING  ABSENT !! ####";
   }
   if(flag==0)
   {
     cout<<"\n\n\n\n\t\t#### SUBSTRING  PRESENT !! ####";
   }
   getch();
 }
/*======================END OF FUNCTION substring()========================*/

/*-------------------------------------------------------------------------*/
/*         *+*+*+*+*+*+*+*+  END OF THE PROGRAM  *+*+*++*+*+*+*+*+         */
/*-------------------------------------------------------------------------*/
