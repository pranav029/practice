//equal sum partition with Tabulation
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
signed main()
{
    dp.clear();
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(!(sum&1)){
         for(int i=0;i<=arr.size();i++)dp.push_back(vector<int>((sum/2)+1));
         for(int i=0;i<(sum/2)+1;i++)dp[0][i]=0;
         for(int i=0;i<n+1;i++)dp[i][0]=1;
         for(int i=1;i<n+1;i++){
            for(int j=1;j<(sum/2)+1;j++){
                if(arr[i-1]<=j)
                 dp[i][j]=dp[i-1][j-arr[i-1]] | dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
         }
         cout<<dp[n][sum/2]<<endl;
    }else cout<<0<<endl;
}