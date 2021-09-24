//sub_set sum memoization+recursion
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int sub_sum(vector<int> arr,int sum,int n)
{
    if(dp[n][sum]!=-1)return dp[n][sum];
    if(sum==0 && n>=0)return 1;
    if(n==0)return 0;
    if(arr[n-1]<=sum)return dp[n][sum]=sub_sum(arr,sum-arr[n-1],n-1) | sub_sum(arr,sum,n-1);
    else return dp[n][sum]=sub_sum(arr,sum,n-1);
}
signed main()
{
    dp.clear();
    int n,sum;
    cin>>n>>sum;
    for(int i=0;i<=n;i++){
        dp.push_back(vector<int>(sum+1,-1));
    }
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<sub_sum(arr,sum,n)<<endl;
}