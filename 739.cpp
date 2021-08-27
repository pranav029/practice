// #include<bits/stdc++.h>
// #define ll long long int
// #define loop(i,n,a) for(int i=a;i<n;i++)
// using namespace std;
// int arr[1001];
// void solve()
// {
//     int k;
//     cin>>k;
//     cout<<arr[k-1]<<endl;
// }
// int main()
// {
//     int T,n=1;
//     arr[0]=1;
//     int i=2,k=1;
//     while(k<1001)
//     {
//     	if(i%3!=0 && i%10!=3)arr[k++]=i;
//     	i++;
//     }
//     cin>>T;
//     // for(int i=0;i<1001;i++)cout<<arr[i]<<endl;
//     while(T>0)
//     {
//         solve();
//         T--;
//     }
// }


// #include<bits/stdc++.h>
// #define ll long long int
// #define loop(i,n,a) for(int i=a;i<n;i++)
// using namespace std;
// void solve()
// {
//     int a,b,c;
//     cin>>a>>b>>c;
//     if(abs(a-b)==1 || a>2*abs(a-b) || b>2*abs(a-b) || c>2*abs(a-b)){
//     	cout<<"-1"<<endl;
//     	return;
//     }
//    if(c>abs(a-b))cout<<c-abs(a-b)<<endl;
//    else cout<<c+abs(a-b)<<endl;
// }
// int main()
// {
//     int T;
//     cin>>T;
//     while(T>0)
//     {
//         solve();
//         T--;
//     }
// }


#include<bits/stdc++.h>
#define ll long long int
#define bajrangbali printf("Jai Hanumaan\n");
#define loop(i,n,a) for(int i=a;i<n;i++)
using namespace std;
void solve()
{
    ll k;
    cin>>k;
    ll n=1;
    while(k>(n*n))n++;
    ll m=((n-1)*(n-1))+1;
       for(int i=1;i<=n;i++){
    	if(m==k){
    		cout<<i<<" "<<n<<endl;
    		return;
    	}
    	m++;
    }

    for(int i=n-1;i>0;i--){
    	if(m==k){
    		cout<<n<<" "<<i<<endl;
    		return;
    	}
    	m++;
    }
    
}
int main()
{
    bajrangbali
    int T;
    cin>>T;
    while(T--)solve();
}

// #include<bits/stdc++.h>
// #define ll long long int
// #define loop(i,n,a) for(int i=a;i<n;i++)
// using namespace std;
// void solve()
// {
//     ll a,b;
//     cin>>a>>b;
//     int i=1;
//     while(a>=(i*i))i++;
//     i--;
//     cout<<i*b*1ll<<endl;
// }
// int main()
// {
//     int T;
//     cin>>T;
//     while(T>0)
//     {
//         solve();
//         T--;
//     }
// }