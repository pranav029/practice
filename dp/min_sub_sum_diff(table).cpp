//minimum subset sum difference tabulation
#include<bits/stdc++.h>
using namespace std;
signed main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int i=0;i<sum+1;i++)dp[0][i]=0;
    for(int i=0;i<n+1;i++)dp[i][0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j-arr[i-1]] | dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }
    vector<int> ans;
    for(int i=0;i<sum+1;i++)if(dp[n][i])ans.push_back(i);
    int mini=INT_MAX;
    for(int i=0;i<ans.size()/2;i++)mini=min(mini,sum-2*ans[i]);
    cout<<mini<<endl;
}