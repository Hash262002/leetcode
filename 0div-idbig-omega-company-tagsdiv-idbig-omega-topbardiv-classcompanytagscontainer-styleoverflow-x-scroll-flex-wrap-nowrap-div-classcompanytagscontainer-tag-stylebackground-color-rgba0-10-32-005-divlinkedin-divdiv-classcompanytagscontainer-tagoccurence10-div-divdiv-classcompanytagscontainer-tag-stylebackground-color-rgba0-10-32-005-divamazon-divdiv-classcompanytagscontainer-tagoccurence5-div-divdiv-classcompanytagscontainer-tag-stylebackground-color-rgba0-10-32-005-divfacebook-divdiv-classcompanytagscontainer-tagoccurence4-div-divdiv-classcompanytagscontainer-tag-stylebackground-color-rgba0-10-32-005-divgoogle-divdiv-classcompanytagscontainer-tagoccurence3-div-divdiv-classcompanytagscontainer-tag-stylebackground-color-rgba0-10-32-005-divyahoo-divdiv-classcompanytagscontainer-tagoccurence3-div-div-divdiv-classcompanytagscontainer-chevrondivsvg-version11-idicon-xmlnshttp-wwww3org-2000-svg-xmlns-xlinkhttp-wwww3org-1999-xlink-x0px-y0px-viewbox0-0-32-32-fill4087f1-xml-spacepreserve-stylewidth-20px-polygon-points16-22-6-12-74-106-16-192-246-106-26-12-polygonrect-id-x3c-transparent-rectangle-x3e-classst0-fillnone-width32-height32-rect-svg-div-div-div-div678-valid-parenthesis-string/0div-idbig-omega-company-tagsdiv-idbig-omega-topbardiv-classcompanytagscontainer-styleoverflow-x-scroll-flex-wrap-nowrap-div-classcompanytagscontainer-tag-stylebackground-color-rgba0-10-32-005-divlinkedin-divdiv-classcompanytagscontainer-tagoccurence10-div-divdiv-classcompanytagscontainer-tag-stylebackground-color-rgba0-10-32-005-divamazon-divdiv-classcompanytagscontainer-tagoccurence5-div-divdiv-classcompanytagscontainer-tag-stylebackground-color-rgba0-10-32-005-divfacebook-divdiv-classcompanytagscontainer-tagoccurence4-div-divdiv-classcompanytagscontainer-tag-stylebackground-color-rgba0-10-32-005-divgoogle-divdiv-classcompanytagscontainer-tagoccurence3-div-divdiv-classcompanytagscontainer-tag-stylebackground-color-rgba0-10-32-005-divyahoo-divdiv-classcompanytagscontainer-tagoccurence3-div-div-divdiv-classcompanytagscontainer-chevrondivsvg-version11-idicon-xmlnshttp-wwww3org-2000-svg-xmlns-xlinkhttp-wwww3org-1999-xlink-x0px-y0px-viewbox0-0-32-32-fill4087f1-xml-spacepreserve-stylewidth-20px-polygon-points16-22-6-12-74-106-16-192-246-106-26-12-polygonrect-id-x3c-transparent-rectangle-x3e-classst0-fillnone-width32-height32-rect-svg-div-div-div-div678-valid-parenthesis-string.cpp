class Solution {
public:
    bool memo(int index,int total,string s,vector<vector<int>>&dp){
        if(index==s.size()){
            return total==0;
        }
        if(total<0)return false;
        if(dp[index][total]!=-1)return dp[index][total];
        if(s[index]=='('){
            return dp[index][total]=memo(index+1,total+1,s,dp);
        }
        else if(s[index]==')'){
            return dp[index][total]=memo(index+1,total-1,s,dp);
        }
        return dp[index][total]=memo(index+1,total+1,s,dp)||memo(index+1,total-1,s,dp)||memo(index+1,total,s,dp);
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return memo(0,0,s,dp);
        
    }
};