//minimum subset sum difference memoization+recursioin
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
vector<vector<int>> dp;
int range;
int mini_part(vector<int> arr,int n,int sum)
{
    if(dp[n][sum]!=-1)return dp[n][sum];
    if(sum<0)return INT_MAX;
    if(n==0)return abs(range-2*sum);
    return dp[n][sum]=min(mini_part(arr,n-1,sum-arr[n-1]),mini_part(arr,n-1,sum));
}
signed main()
{
    auto start = chrono::high_resolution_clock::now();
    dp.clear();
    int n;
    cin>>n;
    vector<int> arr(n);
    range=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        range+=arr[i];
    }
    for(int i=0;i<n+1;i++)dp.push_back(vector<int>(range+1,-1));
    int ans=mini_part(arr,n,range);
    //just to track execution time
    auto end = chrono::high_resolution_clock::now();
    double time_taken = 
    chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout<<time_taken<<setprecision(11)<<endl;

    cout<<ans<<endl;
}