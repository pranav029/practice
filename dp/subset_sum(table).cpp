//sub_set sum tabulation
#include<bits/stdc++.h>
using namespace std;
signed main()
{
    int n,sum;
    cin>>n>>sum;
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int i=0;i<sum+1;i++)dp[0][i]=0;
    for(int i=0;i<n+1;i++)dp[i][0]=1;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]] | dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][sum]<<endl;
}