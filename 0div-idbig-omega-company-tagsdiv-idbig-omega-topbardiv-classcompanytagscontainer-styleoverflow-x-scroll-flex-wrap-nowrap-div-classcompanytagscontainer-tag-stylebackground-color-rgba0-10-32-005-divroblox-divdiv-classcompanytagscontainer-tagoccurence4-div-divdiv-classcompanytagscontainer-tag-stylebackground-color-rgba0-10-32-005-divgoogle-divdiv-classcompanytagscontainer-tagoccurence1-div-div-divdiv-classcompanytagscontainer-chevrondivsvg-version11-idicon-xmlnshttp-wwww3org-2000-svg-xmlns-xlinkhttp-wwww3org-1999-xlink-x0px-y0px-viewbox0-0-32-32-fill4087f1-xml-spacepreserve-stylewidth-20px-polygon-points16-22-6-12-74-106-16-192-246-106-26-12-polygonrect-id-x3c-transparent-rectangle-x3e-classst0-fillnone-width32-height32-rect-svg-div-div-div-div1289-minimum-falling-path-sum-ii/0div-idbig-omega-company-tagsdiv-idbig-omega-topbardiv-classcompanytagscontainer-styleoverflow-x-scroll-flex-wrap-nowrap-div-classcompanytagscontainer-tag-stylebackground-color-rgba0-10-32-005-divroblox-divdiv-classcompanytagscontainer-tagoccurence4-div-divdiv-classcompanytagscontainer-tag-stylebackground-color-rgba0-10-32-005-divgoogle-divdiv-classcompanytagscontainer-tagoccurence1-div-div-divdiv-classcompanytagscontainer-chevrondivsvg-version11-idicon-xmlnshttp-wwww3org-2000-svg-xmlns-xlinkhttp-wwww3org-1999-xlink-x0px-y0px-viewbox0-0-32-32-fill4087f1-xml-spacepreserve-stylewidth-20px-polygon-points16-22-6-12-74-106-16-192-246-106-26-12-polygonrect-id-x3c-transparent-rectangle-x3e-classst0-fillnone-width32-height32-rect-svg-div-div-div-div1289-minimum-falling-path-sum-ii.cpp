class Solution {
public:
    int memo(int index,int prev,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(index==grid.size())return 0;
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        int ans=INT_MAX;
        for(int i=0;i<grid[0].size();i++){
            if(i!=prev){
                ans=min(ans,grid[index][i]+memo(index+1,i,grid,dp));
            }
        }
        return dp[index][prev+1]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(202,vector<int>(202,-1));
        return memo(0,-1,grid,dp);
    }
};