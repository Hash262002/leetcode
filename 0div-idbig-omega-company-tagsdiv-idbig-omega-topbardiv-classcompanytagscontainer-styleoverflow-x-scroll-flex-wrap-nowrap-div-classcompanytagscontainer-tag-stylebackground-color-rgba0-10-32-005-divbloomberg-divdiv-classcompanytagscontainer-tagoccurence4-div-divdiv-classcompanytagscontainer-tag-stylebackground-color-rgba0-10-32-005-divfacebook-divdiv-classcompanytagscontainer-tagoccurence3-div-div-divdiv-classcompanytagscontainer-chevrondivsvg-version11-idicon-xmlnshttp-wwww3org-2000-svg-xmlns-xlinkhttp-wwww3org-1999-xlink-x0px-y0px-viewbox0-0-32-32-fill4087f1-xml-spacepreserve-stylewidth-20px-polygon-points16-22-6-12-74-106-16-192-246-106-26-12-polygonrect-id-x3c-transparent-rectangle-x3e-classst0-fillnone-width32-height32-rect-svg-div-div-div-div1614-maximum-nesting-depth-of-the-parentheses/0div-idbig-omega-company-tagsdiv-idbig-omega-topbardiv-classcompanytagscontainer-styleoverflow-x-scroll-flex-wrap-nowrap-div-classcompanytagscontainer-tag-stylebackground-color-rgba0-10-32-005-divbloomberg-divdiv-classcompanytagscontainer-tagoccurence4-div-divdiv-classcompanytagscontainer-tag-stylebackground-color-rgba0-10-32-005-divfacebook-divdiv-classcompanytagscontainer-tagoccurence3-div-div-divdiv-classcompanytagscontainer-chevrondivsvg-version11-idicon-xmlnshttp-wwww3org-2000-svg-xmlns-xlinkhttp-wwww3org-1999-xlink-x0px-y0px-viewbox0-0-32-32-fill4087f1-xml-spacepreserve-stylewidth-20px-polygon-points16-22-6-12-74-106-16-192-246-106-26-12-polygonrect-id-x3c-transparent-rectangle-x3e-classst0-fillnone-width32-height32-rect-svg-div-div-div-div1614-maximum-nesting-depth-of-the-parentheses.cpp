class Solution {
public:
    int maxDepth(string s) {
        int ans=INT_MIN;
        int temp=0;
        int temp1=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')temp++;
            else if(s[i]==')')temp--;
            temp1=max(temp1,temp);
            if(temp==0)ans=max(ans,temp1);
        }
        return ans;
    }
};