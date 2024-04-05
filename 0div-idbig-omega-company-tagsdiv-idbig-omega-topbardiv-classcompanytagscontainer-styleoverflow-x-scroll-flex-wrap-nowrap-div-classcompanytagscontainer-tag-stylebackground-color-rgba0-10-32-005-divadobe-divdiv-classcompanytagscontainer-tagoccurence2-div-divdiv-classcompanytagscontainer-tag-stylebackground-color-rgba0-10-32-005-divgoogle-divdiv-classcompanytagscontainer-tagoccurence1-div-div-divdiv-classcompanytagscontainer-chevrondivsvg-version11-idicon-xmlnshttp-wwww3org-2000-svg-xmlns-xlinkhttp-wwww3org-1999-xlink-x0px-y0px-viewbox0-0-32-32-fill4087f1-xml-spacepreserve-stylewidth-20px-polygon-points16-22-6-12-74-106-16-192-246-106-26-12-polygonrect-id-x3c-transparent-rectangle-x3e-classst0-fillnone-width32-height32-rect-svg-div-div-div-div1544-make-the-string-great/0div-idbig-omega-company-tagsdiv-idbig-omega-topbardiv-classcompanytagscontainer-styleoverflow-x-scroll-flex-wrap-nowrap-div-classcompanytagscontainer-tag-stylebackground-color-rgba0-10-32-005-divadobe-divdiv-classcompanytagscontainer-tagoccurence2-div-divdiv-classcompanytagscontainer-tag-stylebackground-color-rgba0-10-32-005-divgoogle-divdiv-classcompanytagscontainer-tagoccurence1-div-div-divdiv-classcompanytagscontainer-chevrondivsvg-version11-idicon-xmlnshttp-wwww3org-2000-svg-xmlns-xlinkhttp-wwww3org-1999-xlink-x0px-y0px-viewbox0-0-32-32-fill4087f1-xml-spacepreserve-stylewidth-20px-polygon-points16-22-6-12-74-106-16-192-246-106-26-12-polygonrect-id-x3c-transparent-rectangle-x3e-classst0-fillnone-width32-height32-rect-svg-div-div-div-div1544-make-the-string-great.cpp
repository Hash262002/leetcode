class Solution {
public:
    string makeGood(string s) {
        string ans="";
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            st.push(s[i]);
            if(st.size()>=2)
            {
                char a=st.top();
                st.pop();
                char b=st.top();
                st.pop();
                if(!(a-'a'==b-'A' || a-'A'==b-'a')){
                    st.push(b);
                    st.push(a);
                }
            }
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }   
};