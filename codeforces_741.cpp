//jai bajrangbali
#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ll long long int
#define loop(i,n,a) for(int i=a;i<n;i++)
using namespace std;
void solve()
{
    int k;
    cin>>k;
    string n;
    cin>>n;
    string ans="";
    	char c;
    	int flag=0;
    	for(int i=0;i<n.size();i++)
    	{
    		if(n[i]=='4' || n[i]=='6' || n[i]=='8' || n[i]=='9' || n[i]=='1'){
    			c=n[i];
    			ans+=c;
    			flag=1;
    			break;
    		}
    	}
    	if(!flag){
    		for(int i=0;i<n.size();i++){
    			int t=n[i]-'0';
    			for(int j=i+1;j<k;j++){
    				int lo=(t*10)+(n[j]-'0');
    			if(lo%3==0 || lo%5==0 || lo%7==0 || lo%9==0 || lo%2==0){
    				ans=to_string(lo);
    				break;
    				}
    			}
    		}
    	}
    cout<<ans.size()<<"\n"<<ans<<"\n";
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