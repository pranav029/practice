//segment tree implementation
#include<bits/stdc++.h>
#define ll long long int
#define loop(i,n,a) for(int i=a;i<n;i++)
using namespace std;
const int n=1e+5;
int seg[n*4];
void built(int s,int e,int nd,int arr[])
{
	if(s==e){
		seg[nd]=arr[s];
		return;
	}
	int mid=(s+e)/2;
	built(s,mid,2*nd+1,arr);
	built(mid+1,e,2*nd+2,arr);
	seg[nd]=seg[2*nd+1]+seg[2*nd+2];
}
int get_sum(int s,int e,int srt,int end,int nd)
{
	if(s>=srt && e<=end)return seg[nd];
	if(s>end || e<srt)return 0;
	int mid=(s+e)/2;
	return get_sum(s,mid,srt,end,2*nd+1)+get_sum(mid+1,e,srt,end,2*nd+2);
}
void solve()
{
    int arr[]={1,2,3,4,5,6,7};
    for(auto x:arr)cout<<x<<" ";
	built(0,6,0,arr);
	cout<<endl;
    loop(i,20,0)cout<<seg[i]<<" ";
    cout<<endl;
    cout<<"sum of range 1 to 3 : "<<get_sum(0,6,0,2,0);

}
int main()
{
    int T;
    cin>>T;
    while(T>0)
    {
        solve();
        T--;
    }
}