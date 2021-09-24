//equal sum partition with Memoization
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int subset_sum(vector<int> arr,int n,int sum)
{
    if(dp[n][sum]!=-1)return dp[n][sum];
    if(sum==0 && n>=0)return 1;
    if(n==0)return 0;
    if(arr[n-1]<=sum)
        return dp[n][sum]=subset_sum(arr,n-1,sum-arr[n-1]) | subset_sum(arr,n-1,sum);
    else return dp[n][sum]=subset_sum(arr,n-1,sum);
}
int partition(vector<int> arr){
    int sum=0;
    for(int i=0;i<arr.size();i++)sum+=arr[i];
    for(int i=0;i<=arr.size();i++)dp.push_back(vector<int>(sum+1,-1));
    if(sum&1)return 0;
    return subset_sum(arr,arr.size(),sum/2);
}
signed main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<partition(arr)<<endl;
}