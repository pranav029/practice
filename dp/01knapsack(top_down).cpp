#include<bits/stdc++.h>
#define loop(i,n,a) for(int i=a;i<n;i++)
using namespace std;
signed main()
{
    int n,w;
    cin>>n>>w;
    vector<int> wt(n),val(n);
    loop(i,n,0)cin>>wt[i];
    loop(i,n,0)cin>>val[i];
    int dp[n+1][w+1];
    loop(i,w+1,0)dp[0][i]=0;
    loop(i,n+1,0)dp[i][0]=0;
    loop(i,n+1,1){
        loop(j,w+1,1){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][w]<<endl;
}