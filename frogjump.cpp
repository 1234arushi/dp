//tabulation
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    //tabulation method:
    vector<int>dp (n, 0);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1)
        {
            ss=dp[i-2]+abs(heights[i]-heights[i-2]);

        }
        dp[i]=min(fs,ss);
        
    }
    return dp[n-1];

    // Write your code here.
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//memoization
#include <bits/stdc++.h>
int solve(int indx,vector<int>heights,vector<int>&dp)
{
    if(indx==0)
    {
        return 0;
    }
    if(dp[indx]!=-1)
    {
        return dp[indx];
    }
    int left=solve(indx-1,heights,dp)+abs(heights[indx]-heights[indx-1]);
    int right=INT_MAX;
    if(indx > 1)
    {
        right=solve(indx-2,heights,dp)+abs(heights[indx]-heights[indx-2]);

    }
    
    return dp[indx]=min(left,right);
} 
int frogJump(int n, vector<int> &heights)
{
    //memoized solution:
    vector<int>dp(n+1,-1);
    return solve(n-1,heights,dp);

    // Write your code here.
}
