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
