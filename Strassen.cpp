
#include<iostream>
#include<math.h>
using namespace std;

int** new_mat(int r,int c)
{
    int **a= new int *[r];
    for(int i=0;i<r;i++)
     a[i]=new int [c];
     return a;
}
int** padding(int **a,int n,int r,int c)
{
    int **arr=new_mat(n,n);
    for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
          arr[i][j]=0;
     }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            arr[i][j]=a[i][j];
        }
    }
    return arr;
}
int** split(int **a,int n,int r,int c)
{
    int **d=new int *[n/2];
    for(int i=0;i<n/2;i++)
     d[i]=new int[n/2];
     for(int i=0;i<n/2;i++)
     {
         for(int j=0;j<n/2;j++)
           d[i][j]=a[r+i][c+j];
     }
     return d;
}

int** merge(int **a,int **C,int n,int r,int c)
{
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
           C[r+i][c+j]=a[i][j];
     }
     return C;
}

int **add(int **a,int **b,int n)
{
    int **c=new_mat(n,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
         c[i][j]=a[i][j]+b[i][j];
    }
    return c;
}

int **sub(int **a,int **b,int n)
{
    int **c=new_mat(n,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
         c[i][j]=a[i][j]-b[i][j];
    }
    return c;
}

void print(int **a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
          cout<<a[i][j]<<" ";

          cout<<endl;
    }
}

int**  strassen(int **a,int **b,int n)
{
   if(n<=1)
   {
          int **c=new_mat(1,1);
          c[0][0]=a[0][0]*b[0][0];
        return c;  
   }
   else
   {
       int **m1=split(a,n,0,0);
       int **m2=split(a,n,0,n/2);
       int **m3=split(a,n,n/2,0);
       int **m4=split(a,n,n/2,n/2);
       int **h1=split(b,n,0,0);
       int **h2=split(b,n,0,n/2);
       int **h3=split(b,n,n/2,0);
       int **h4=split(b,n,n/2,n/2);

       int **c1=new_mat(n/2,n/2);
       int **c2=new_mat(n/2,n/2);
       int **c3=new_mat(n/2,n/2);
       int **c4=new_mat(n/2,n/2);


       int **p1=new_mat(n/2,n/2);
       int **p2=new_mat(n/2,n/2);
       int **p3=new_mat(n/2,n/2);
       int **p4=new_mat(n/2,n/2);
       int **p5=new_mat(n/2,n/2);
       int **p6=new_mat(n/2,n/2);
       int **p7=new_mat(n/2,n/2);

       int **C=new_mat(n,n);


       p1=strassen(m1,sub(h2,h4,n/2),n/2);
       p2=strassen(add(m1,m2,n/2),h4,n/2);
       p3=strassen(add(m3,m4,n/2),h1,n/2);
       p4=strassen(m4,sub(h3,h1,n/2),n/2);
       p5=strassen(add(m1,m4,n/2),add(h1,h4,n/2),n/2);
       p6=strassen(sub(m2,m4,n/2),add(h3,h4,n/2),n/2);
       p7=strassen(sub(m1,m3,n/2),add(h1,h2,n/2),n/2);

       c1=add(sub(add(p5,p4,n/2),p2,n/2),p6,n/2);
       C=merge(c1,C,n/2,0,0);
       c2=add(p1,p2,n/2);
       C=merge(c2,C,n/2,0,n/2);
       c3=add(p3,p4,n/2);
       C=merge(c3,C,n/2,n/2,0);
       c4=sub(sub(add(p1,p5,n/2),p3,n/2),p7,n/2);
       C=merge(c4,C,n/2,n/2,n/2);

       return C;

   }
}
int next2n(int m)
{
    int j=2;
    for(int i=1;j<m;i++)
       j=(int)pow(2,i);
    return j;   
}
int max(int a,int b,int c)
{
    if(a>b) return a>c?a:c;
    else return b>c?b:c;
}
int **multiply(int **a,int **b,int r1,int r2,int c1,int c2)
{
    int m=max(r1,c1,c2);
    m=next2n(m);
    int **x=padding(a,m,r1,c1);
    int **y=padding(b,m,r2,c2);
    int **C=strassen(x,y,m);
    int **ret=new_mat(r1,c2);
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
         ret[i][j]=C[i][j];
    }
    return ret;
}
int main()
{
    cout<<"Pranavmani Tripathi\nBTECH/60077/19\n";
    int r1,c1,r2,c2;
    cout<<"Enter row and coloumn of first matrix:\n";
    cin>>r1>>c1;
    cout<<"Enter row and coloumn of second matrix:\n";
    cin>>r2>>c2;
    int **a=new_mat(r1,c1);
    int **b=new_mat(r2,c2);
    
    cout<<"Enter first matrix:\n";
    for(int i=0;i<r1;i++)
      {
          for(int j=0;j<c1;j++)
           cin>>a[i][j];
      } 
    cout<<"Enter second matrix:\n";
    for(int i=0;i<r2;i++)
      {
          for(int j=0;j<c2;j++)
             cin>>b[i][j];
      } 
    int **C=multiply(a,b,r1,r2,c1,c2);
     cout<<"\n";
    for(int i=0;i<r1;i++)
      {
          for(int j=0;j<c2;j++)
         cout<<C[i][j]<<" ";

         cout<<endl;
      } 
}


