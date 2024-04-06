class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int n=s.size();
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='('){
                flag++;
            }
            else if(s[i]==')'){
                flag--;
                
            }
            if(flag>=0){
                ans+=s[i];
            }
            else flag=0;
        }
        string final_ans;
        for(int i=ans.size()-1;i>=0;i--){
            if(flag>0 && ans[i]=='('){
                flag--;
                continue;
            }
            final_ans+=ans[i];
        }
        reverse(final_ans.begin(),final_ans.end());
        return final_ans;
    }
};