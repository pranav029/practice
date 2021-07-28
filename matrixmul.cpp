#include<iostream>
using namespace std;

int main()
{
        cout<<"Pranavmani Tripathi\nBTECH/60077/19\n";
    int n;
    cout<<"Enter number of rows of matrix:"<<endl;
    cin>>n;
    int mat1[n][n],mat2[n][n];
    cout<<"Enter elements of matrix 1:"<<endl;
     for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
          cin>>mat1[i][j];
      }
    }
     cout<<"Enter elements of matrix 2:"<<endl;

     for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
          cin>>mat2[i][j];
      }
    }
    int mat3[n][n];
     for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
          mat3[i][j]=0;
          for(int k=-0;k<n;k++)
          {
            mat3[i][j]+=mat1[i][k]*mat2[k][j];
          }
      }
    }
   cout<<endl;
   cout<<"The new matrix is:"<<endl;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
          cout<<mat3[i][j]<<" ";
      }
      cout<<endl;
    }
}