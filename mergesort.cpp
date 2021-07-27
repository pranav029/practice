#include<iostream>
using namespace std;

void merge(int *arr,int l,int m,int h)
{
    m=(h-l)/2;
    int i=l,j=m+1,t=l;
    int *temp= new int[h-l+1];
    for(int k=0;k<=(h-l);k++)
    {
        temp[k]=arr[i++];
    }
    i=0;
    while(i<=m && j<=(h-l))
    {
        if(temp[i]<temp[j])
        {
            arr[t]=temp[i];
            i++;
        }
        else{
            arr[t]=temp[j];
            j++;
        }
        t++;
    }

            while(i<=m && j>(h-l))
            {
                arr[t]=temp[i];
                t++;
                i++;
            }
        
            while(j<=(h-l) && i>m)
            {
                arr[t]=temp[j];
                j++;
                t++;
            }
}
void mergeSort(int *arr,int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

int main()
{
     cout<<"Pranavmani Tripathi\nBTECH/60077/19\n";
    int n;
     cout<<"Enter size of array:";
     cin>>n;
    int *arr= new int[n];
     cout<<"Enter array elements"<<endl;
     for(int i=0;i<n;i++)
      cin>>arr[i];
    cout<<"Before sorting:"<<endl;
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
      cout<<endl<<"After sorting"<<endl;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
}