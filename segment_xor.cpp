#include<bits/stdc++.h>
#define ll long long int
#define loop(i,n,a) for(int i=a;i<n;i++)
using namespace std;
const int size=1e5;
int seg[size];
void built(int s,int e,int nd,int arr[])
{
	if(s==e){
		seg[nd]=arr[s];
		return;
	}
    int mid=(s+e)/2;
    built(s,mid,2*nd+1,arr);
    built(mid+1,e,2*nd+2,arr);
    seg[nd]=seg[2*nd+1]^seg[2*nd+2];
}
int st,ed;
int xr(int s,int e,int nd,int l,int r,int k,int max)
{
	if(s>=l && r>=e)return seg[nd];
	if(l>e|| r<s)return 0;
	int mid=(s+e)/2;
	int store=xr(s,mid,2*nd+1,l,r,k,max)^xr(mid+1,e,2*nd+2,l,r,k,max);
	if(store==max && e-s==k-1){
		st=s;
		ed=e;
	}
	return store;
}
void solve()
{
    int arr[]={1,2,3,4,5,6,7,8};
    built(0,7,0,arr);
    loop(i,10,0)cout<<seg[i]<<" ";
    // cout<<endl<<(1^2^3^4^5^6^7^8);
    cout<<endl<<(2^3^4)<<" "<<xr(0,7,0,0,7,2,15)<<endl;
    loop(i,ed+1,st)cout<<arr[i]<<" ";
}
signed main()
{
    int T;
    cin>>T;
    while(T>0)
    {
        solve();
        T--;
    }
}