/*=========================================================================*/
/*        ASSIGNMENT NO ::  2               SUBJECT : OOPL                 */
/*        DATE OF COMPLETION : 25-2-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  WRITE A CLASS TO HANDLE TWO DIMENSIONAL ARRAY     */
/*                       WITH DATA MEMBERS IS DYNAMICALLY GROWING TWO      */
/*                       DIMENSIONAL ARRAY AND MEMBER FUNCTIONS TRANSPOSE, */
/*                       INVERSE ,MULTIPLICATION ,SYMMETRIC CHECK ,SKEW    */
/*                       CHECK OR FOR THE MAGIC SQUARE                     */
/*=========================================================================*/

#include<process.h>
#include<iostream.h>
#include<conio.h>

/*-------------------------------------------------------------------------*/
/*                    DECLARATION   OF   CLASS                             */
/*-------------------------------------------------------------------------*/

class matrix
{
  float **p;                         // DECLARATION OF PRIVATE MEMBERS
  int d1,d2;

  public:                              // DECLARATION OF PUBLIC MEMBERS

    matrix() { }                       // DECLARATION OF CONSTRUCTER
    matrix(int x,int y);
    matrix copy();
    void get_element(int i,int j,float value)
    { p[i][j] = value; }
    float &put_element(int i,int j)
    {  return p[i][j]; }
    void enter(matrix,int ,int);       // DECLARATION OF MEMBER FUNCTIONS
    void display(matrix);
    friend matrix add(matrix,matrix,int,int);
    friend matrix multiply(matrix,matrix,int ,int,int);
    friend matrix transpose(matrix,int ,int);
    void symmetric(matrix,int,int);
    void skew(matrix,int,int);
    matrix inverse();
};

int check(matrix &m);

/*  ================== DECLARATION OF CONSTRUCTOR =======================  */

matrix :: matrix(int x,int y)
{
  d1 = x;
  d2 = y;
  p = new float *[d1];
  for(int i=0;i<d1;i++)
    p[i] = new float[d2];
}

matrix matrix :: copy()
{
  matrix TEMP(d1,d2);
  int value,i;
  for(i = 0 ; i < d1 ; i++)
  {
    for(int j = 0 ; j < d2 ; j++)
    {
      value = put_element(i,j);
      TEMP.get_element(i,j,value);
    }
  }
  return(TEMP);
}

/*------------------------------------------------------------------------*/
/*                ***** START OF MAIN FUNCTION *****                      */
/*------------------------------------------------------------------------*/

int main(void)
{
  int m,n,o,p,ch,flag;
  clrscr();
  cout<<"\n\n\nPLEASE INPUT THE NO OF ROWS AND COLUMNS OF THE MATRIX : ";
  cin>>m>>n;
  matrix M(m,n),G(n,m),A(m,n);
  cout<<"\n\n\nPLEASE INPUT THE NO OF ROWS AND COLUMNS OF THE MATRIX : ";
  cin>>o>>p;
  matrix N(o,p),H(m,p),V(p,o);
  do
  {
    clrscr();
    cout<<"\n\t============================================";
    cout<<"\n\n\n\t  ************* MENU *************";
    cout<<"\n\n\n\t============================================";
    cout<<"\n\n\n\t\t1: ENTER";
    cout<<"\n\n\t\t2: DISPLAY";
    cout<<"\n\n\t\t3: ADDITION";
    cout<<"\n\n\t\t4: MULTIPLY";
    cout<<"\n\n\t\t5: INVERSE";
    cout<<"\n\n\t\t6: TRANSPOSE";
    cout<<"\n\n\t\t7: SYMMETRIC";
    cout<<"\n\n\t\t8: SKEW";
    cout<<"\n\n\t\t9: EXIT";
    cout<<"\n\n\n\t\tENTER YOUR CHOICE : ";
    cin>>ch;
    switch(ch)
    {
      case 1:
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t   ENTER THE MATRICES  ";
	      cout<<"\n\n\n\t===============================================";
	      M.enter(M,m,n);
	      N.enter (N,o,p);
	      break;
      case 2:
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t   DISPLAYING THE MATRICES  ";
	      cout<<"\n\n\n\t===============================================";
	      cout<<"\n\n\n\n\t  MATRIX A : \n";
	      M.display(M);
	      cout<<"\n\n\n\n\t  MATRIX B : \n";
	      N.display(N);
	      getch();
	      break;
      case 3:
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t   ADDITION OF MATRICES  ";
	      cout<<"\n\n\n\t===============================================";
	      cout<<"\n\n\n\n\t  ADDITION OF MATRICES : \n\n\n";
	      if(m==o && n==p)
	       A = add(M,N,m,n);
	      else
		cout<<"\n\n\n\t\tADDITION IS NOT POSSIBLE !!";
	      getch();
	      break;
      case 4:
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t   MULTIPLICATION OF MATRICES  ";
	      cout<<"\n\n\n\t===============================================";
	      if(n==o)
		H = multiply(M,N,m,n,p);
	      else
		cout<<"\n\n\n\t\tMULTIPLICATION IS NOT POSSIBLE !!";
	      getch();
	      break;
      case 5:
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t   INVERSE OF MATRICES  ";
	      cout<<"\n\n\n\t===============================================";
	      if(m == n)
	      {
		matrix inv(m,n),tem(m,n);
		tem = M.copy();
		inv = tem.inverse();
		int k = check(inv);
		if(k == 1)
		{
		  cout << endl << endl;
		  cout << "\n\n\n\n\t INVERSE OF MATRIX :: \n\n";
		  inv.display(inv);
		}
		else
		{
		 cout << endl << endl;
		 cout << "\n\n\n\t DETERMINANT OF MATRIX IS 0 ";
		 cout << "\n\n\n\t HENCE ,INVERSE DOES NOT EXIT'S !!";
		}
	      }
	      else
	      {
		cout << endl << endl ;
		cout << "\n\n\n\t MATRIX IS NOT A SQUARE MATRIX ";
		cout << "\n\n\n\t HENCE ,INVERSE DOES NOT EXIT'S !! ";
	      }
	      getch();
	      break;
      case 6:
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t   TRANSPOSE OF MATRICES  ";
	      cout<<"\n\n\n\t===============================================";
	      cout<<"\n\n\n\n\t  TRANSPOSE OF MATRIX 1:\n\n";
	      G=transpose(M,m,n);
	      G.display(G);
	      cout<<"\n\n\n\n\t  TRANSPOSE OF MATRIX 2:\n\n";
	      V=transpose(N,p,o);
	      V.display(V);
	      getch();
	      break;
      case 7:
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\t\t   SYMMETRIC MATRICES  ";
	      cout<<"\n\n\n\t===============================================";
	      cout<<"\n\n\n\n\t  MATRIX 1 =  ";
	      M.symmetric(M,m,n);
	      cout<<"\n\n\n\n\t  MATRIX 2 =  ";
	      N.symmetric(N,o,p);
	      getch();
	      break;
      case 8:
	      clrscr();
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\t   SKEW MATRICES  ";
	      cout<<"\n\n\t===============================================";
	      cout<<"\n\n\n\n\t  MATRIX 1 =  ";
	      M.skew(M,m,n);
	      cout<<"\n\n\n\n\t  MATRIX 2 =  ";
	      N.skew(N,o,p);
	      getch();
	      break;
      case 9:
	      exit(0);
	      break;
    }
  }while(ch!=7);
  getch();
  return 0;
}
/*-------------------------------------------------------------------------*/
/*                 ****  END OF MAIN FUNCTION  ****                        */
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/*                 ******** START OF FUNCTION ENTER() ********            */
/*-------------------------------------------------------------------------*/

void matrix :: enter(matrix A,int m,int n)
{
  int i,j;
  float value;
  d1=m,d2=n;
  cout<<"\n\n\n\n\t  ENTER THE ELEMENTS OF MATRIX ROW BY ROW : ";
  for(j=0;j<d2;j++)
    for(i=0;i<d1;i++)
    {
      cin>>value;
      A.get_element(i,j,value);
    }
  cout<<"\n\n\n\n";
}

/*-------------------------------------------------------------------------*/
/*           FUNCTION  :  DISPLAY()                                        */
/*           PURPOSE   : TO DISPLAY THE STRING                             */
/*           PARAMETERS : OBJECT OF CLASS MATRIX                           */
/*-------------------------------------------------------------------------*/

void matrix :: display(matrix s)
{
  int i,j;
  float value;
  for(j=0;j<d2;j++)
  {
    cout<<"\n\n\t\t\t\b";
    for(i=0;i<d1;i++)
    {
      cout<<s.put_element(i,j);
      cout<<"\t\b";
    }
  }
}

/*-------------------------------------------------------------------------*/
/*           FUNCTION  :  ADD()                                            */
/*           PURPOSE   : TO ADD THE TWO MATRICES                           */
/*           PARAMETERS : OBJECT Z,X OF CLASS MATRIX ,INTEGER M ,N         */
/*           RETURN TYPE : OBJECT OF CLASS MATRIX                          */
/*-------------------------------------------------------------------------*/

matrix add(matrix z,matrix x,int m,int n)
{
  int i,j;
  float value;
  matrix AD(m,n);
  for(j=0;j<n;j++)
  {
   for(i=0;i<m;i++)
   {
    value = z.put_element(i,j) + x.put_element(i,j);
    AD.get_element(i,j,value);
   }
  }
  cout<<"\n\n\t  ADDITION OF MATRIX 1 AND 2 IS AS FOLLOWS\n\n";
  cout<<"\n\n\t  MATRIX  = \n\n\n\n";
  AD.display(AD);
  return(AD);
}

/*-------------------------------------------------------------------------*/
/*           FUNCTION  : MULTIPLY()                                        */
/*           PURPOSE   : TO MULTIPLY THE TWO MATRICES                      */
/*           PARAMETERS : OBJECT Q,W OF CLASS MATRIX ,INTEGER M ,N ,P      */
/*           RETURN TYPE : OBJECT OF CLASS MATRIX                          */
/*-------------------------------------------------------------------------*/

matrix multiply(matrix q,matrix w,int m,int n,int p)
{
  int i,j,k;
  float value;
  matrix H(m,p);
  for(j=0;j<m;j++)
  {
    cout<<"\n\n";
    for(i=0;i<m;i++)
    {
     value=0;
     for(k=0;k<n;k++)
     {
       value = value + (q.put_element(i,k))*(w.put_element(k,j));
       H.get_element(i,j,value);
     }
    }
  }
  cout<<"\n\n\t  MULTIPLICATION OF MATRIX 1 AND 2 IS AS FOLLOWS\n\n";
  cout<<"\n\n\t  MATRIX 3 = \n\n\n\n";
  H.display(H);
  return(H);
}

/*-------------------------------------------------------------------------*/
/*           FUNCTION  : TRANSPOSE()                                       */
/*           PURPOSE   : TO FIND THE TRANSPOSE OF THE MATRIX               */
/*           PARAMETERS : OBJECT S OF CLASS MATRIX ,INTEGER M ,N           */
/*           RETURN TYPE : OBJECT OF CLASS MATRIX                          */
/*-------------------------------------------------------------------------*/

 matrix transpose(matrix s,int m,int n)
{
    int i,j;
    float value;
    matrix B(n,m);
    cout<<"\n\n\t  TRANSPOSE OF MATRIX 1 =  \n\n\n";
    for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
      {
	value = s.put_element(j,i);
	B.get_element(i,j,value);
      }
    }
    cout<<"\n\n";
    getch();
    return(B);
}

/*-------------------------------------------------------------------------*/
/*           FUNCTION  : SYMMETRIC()                                       */
/*           PURPOSE   : TO FIND WHETHER THE MATRIX IS SYMMETRIC           */
/*           PARAMETERS : OBJECT D OF CLASS MATRIX , INTEGER M ,N          */
/*-------------------------------------------------------------------------*/

void matrix :: symmetric(matrix D,int m,int n)
{
  int i=0,j=0,flag=0;  float value;
  do
  {
   for(j=0;j<n;j++)
   {
    if(i<j)
    {
     if(D.put_element(i,j)!=D.put_element(j,i))
	flag=1;
    }
   }
   i++;
  }while(i<m  && flag==0);
  if(flag==1)
   cout<<"\n\n\n\t  MATRIX IS NON-SYMMETRIC !!";
  if(flag==0)
   cout<<"\n\n\n\t  MATRIX IS SYMMETRIC !!";
}

/*-------------------------------------------------------------------------*/
/*           FUNCTION  :  SKEW()                                           */
/*           PURPOSE   : TO FIND WHETHER THE MATRIX IS A SKEW MATRIX       */
/*           PARAMETERS : OBJECT D OF CLASS MATRIX , INTEGER M , N         */
/*-------------------------------------------------------------------------*/

void matrix :: skew(matrix D,int m,int n)
{
  int i=0,j=0,flag=0;  float value;
  do
  {
   for(j=0;j<n;j++)
   {
    if(i!=j)
    {
     if(D.put_element(i,j)!=-(D.put_element(j,i)))
	flag=1;
    }
   }
   i++;
  }while(i<m  && flag==0);
  if(flag==0)
   cout<<"\n\n\n\t  MATRIX IS SKEW MATRIX !!";
  if(flag==1)
   cout<<"\n\n\n\t  MATRIX IS NOT A SKEW MATRIX !!";
}

/*-------------------------------------------------------------------------*/
/*           FUNCTION  : INVERSE()                                         */
/*           PURPOSE   : TO FIND THE INVERSE OF THE MATRIX                 */
/*           PARAMETERS : OBJECT Q OF CLASS MATRIX ,INTEGER M ,N           */
/*           RETURN TYPE : OBJECT OF CLASS MATRIX                          */
/*-------------------------------------------------------------------------*/

matrix matrix :: inverse()
{
  int flag = 0;
  float value;
  matrix M(d1 , d2);

  for(int i = 0 ; i < d1 ; i++)  // CONVERTING RESULT MATRIX INTO UNIT MATRIX
  {
    for(int  j = 0 ; j < d2 ; j++)
    {
      if(j == i)
      {
	M.get_element(i,j,1);
      }
      else
	M.get_element(i,j,0);
    }
  }

  for(i = 0 ; i < d1 && flag != 1; i++)
  {
    if(put_element(i,i) == 0)     // CHECKING IF THE DIAGONAL ELEMENT IS 0
    {
      for(int j = i+1 ; j <d1 ; j++)
      {
	if(put_element(j,i) != 0)
	       break;
      }

      if(j == d1)   // CHECKING IF ALL OTHER COLUMN MEMBERS ARE 0
	flag = 1;

      else
      {           // SWAPING WITH ROW HAVING NON - ZERO TERM
	for(int a = 0 ; a < d2 ; a++)
	{
	       float tem = put_element(i,a);
	       value = put_element(j,a);
	       get_element(i,a,value);
	       get_element(j,a,tem);
	}
      }
    }

    float v = put_element(i,i);               // FINDING INVERSE
    for(int l = 0 ; l < d2 && flag != 1; l++)
    {
      value =  put_element(i,l) / v;
      get_element(i,l,value);
      value = M.put_element(i,l) / v;
      M.get_element(i,l,value);
    }

    for(int j = 0 ; j < d1 && flag != 1; j++)
    {
      float u = put_element(j,i);
      for(int k = 0 ; k < d2 ; k++)
      {
	if(j == i)
	  continue;
	else
	{
	  value = put_element(j,k) - (u * put_element(i,k));
	  get_element(j,k,value);
	  value = M.put_element(j,k) - (u * M.put_element(i,k));
	  M.get_element(j,k,value);
	}
      }
    }
  }

  if(flag == 1)
  {
    M.get_element(0,0,-9999);
  }
  return M;
}

/*-------------------------------------------------------------------------*/
/*           FUNCTION  :  SKEW()                                           */
/*           PURPOSE   : TO CHECK WHETHER THE INVERSE IS VALID             */
/*           PARAMETERS : OBJECT D OF CLASS MATRIX , INTEGER M , N         */
/*-------------------------------------------------------------------------*/

     int check(matrix &m)
     {
       if(m.put_element(0,0) != -9999)
	 return(1);
       else
	 return(0);
     }

/*-------------------------------------------------------------------------*/
/*         *+*+*+*+*+*+*+*+  END OF THE PROGRAM  *+*+*++*+*+*+*+*+         */
/*-------------------------------------------------------------------------*/
