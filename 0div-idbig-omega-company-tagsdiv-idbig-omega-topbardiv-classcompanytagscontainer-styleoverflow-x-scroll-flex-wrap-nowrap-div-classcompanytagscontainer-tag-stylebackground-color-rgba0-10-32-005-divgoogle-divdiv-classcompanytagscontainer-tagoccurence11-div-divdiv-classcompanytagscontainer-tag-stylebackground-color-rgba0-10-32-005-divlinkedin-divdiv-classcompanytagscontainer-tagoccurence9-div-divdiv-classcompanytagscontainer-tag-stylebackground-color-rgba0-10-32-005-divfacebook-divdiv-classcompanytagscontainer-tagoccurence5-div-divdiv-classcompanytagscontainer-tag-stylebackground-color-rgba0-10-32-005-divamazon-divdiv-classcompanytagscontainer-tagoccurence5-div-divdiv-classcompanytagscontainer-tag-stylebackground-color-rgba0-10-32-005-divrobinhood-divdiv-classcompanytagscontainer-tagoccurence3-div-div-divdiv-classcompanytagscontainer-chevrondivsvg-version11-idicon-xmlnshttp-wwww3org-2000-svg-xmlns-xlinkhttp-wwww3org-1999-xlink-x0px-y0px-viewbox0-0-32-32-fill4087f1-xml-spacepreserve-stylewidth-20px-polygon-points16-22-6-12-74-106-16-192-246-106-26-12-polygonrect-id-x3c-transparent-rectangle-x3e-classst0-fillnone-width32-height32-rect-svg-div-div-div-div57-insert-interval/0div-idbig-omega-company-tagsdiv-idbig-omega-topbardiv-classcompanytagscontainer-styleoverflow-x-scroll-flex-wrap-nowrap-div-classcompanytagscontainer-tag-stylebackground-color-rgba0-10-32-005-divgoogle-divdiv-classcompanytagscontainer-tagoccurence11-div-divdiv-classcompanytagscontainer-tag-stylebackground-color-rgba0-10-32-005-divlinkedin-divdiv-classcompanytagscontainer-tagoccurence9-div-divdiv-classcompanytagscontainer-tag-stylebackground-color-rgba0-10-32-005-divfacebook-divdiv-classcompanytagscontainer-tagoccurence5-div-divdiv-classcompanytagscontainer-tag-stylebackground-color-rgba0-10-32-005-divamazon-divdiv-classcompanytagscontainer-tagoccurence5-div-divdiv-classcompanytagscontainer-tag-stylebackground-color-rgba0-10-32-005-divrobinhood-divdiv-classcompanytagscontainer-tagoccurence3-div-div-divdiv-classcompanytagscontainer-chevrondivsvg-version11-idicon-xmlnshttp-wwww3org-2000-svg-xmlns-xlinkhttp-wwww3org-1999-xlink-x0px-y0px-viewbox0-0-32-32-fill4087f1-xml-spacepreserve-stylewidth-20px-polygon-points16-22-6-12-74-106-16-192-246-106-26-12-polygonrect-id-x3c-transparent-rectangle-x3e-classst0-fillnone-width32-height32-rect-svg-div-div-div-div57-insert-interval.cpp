class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        int index1=n,index2=n;
        for(int i=0;i<n;i++){
            if(intervals[i][0]<=newInterval[0] && intervals[i][1]>=newInterval[0])index1=i;
            if(intervals[i][0]<=newInterval[1] && intervals[i][1]>=newInterval[1])index2=i;
        }
        cout<<index1<<" "<<index2<<endl;
        if(index1==index2 && index1!=n)return intervals;

        if(index1!=n && index2!=n){
            vector<vector<int>>ans;
            for(int i=0;i<index1;i++){
                ans.push_back(intervals[i]);
            }
            vector<int>temp;
            temp.push_back(intervals[index1][0]);
            temp.push_back(intervals[index2][1]);
            ans.push_back(temp);
            for(int i=index2+1;i<n;i++){
                ans.push_back(intervals[i]);
            }
            return ans;
        }
        else if(index1!=n){
            vector<vector<int>>ans;
            cout<<index1<<endl;
            for(int i=0;i<index1;i++){
                ans.push_back(intervals[i]);
            }
            vector<int>temp;
            temp.push_back(intervals[index1][0]);
            temp.push_back(newInterval[1]);
            ans.push_back(temp);
            for(int i=index1;i<n;i++){
                if(intervals[i][0]>newInterval[1]){
                    ans.push_back(intervals[i]);
                }
            }
            return ans;
        }
        else if(index2!=n){
            vector<vector<int>>ans;
            for(int i=0;i<n;i++){
                if(intervals[i][1]<newInterval[0]){
                    ans.push_back(intervals[i]);
                }
            }
            vector<int>temp;
            temp.push_back(newInterval[0]);
            temp.push_back(intervals[index2][1]);
            ans.push_back(temp);
            for(int i=index2+1;i<n;i++){
                ans.push_back(intervals[i]);
            }
            return ans;
        }
        else{
            vector<vector<int>>ans;
            for(int i=0;i<n;i++){
                if(intervals[i][1]<newInterval[0]){
                    ans.push_back(intervals[i]);
                }
            }
            ans.push_back(newInterval);
            for(int i=0;i<n;i++){
                if(intervals[i][0]>newInterval[1]){
                    ans.push_back(intervals[i]);
                }
            }
            return ans;
        }
        return {{}};
    }
};