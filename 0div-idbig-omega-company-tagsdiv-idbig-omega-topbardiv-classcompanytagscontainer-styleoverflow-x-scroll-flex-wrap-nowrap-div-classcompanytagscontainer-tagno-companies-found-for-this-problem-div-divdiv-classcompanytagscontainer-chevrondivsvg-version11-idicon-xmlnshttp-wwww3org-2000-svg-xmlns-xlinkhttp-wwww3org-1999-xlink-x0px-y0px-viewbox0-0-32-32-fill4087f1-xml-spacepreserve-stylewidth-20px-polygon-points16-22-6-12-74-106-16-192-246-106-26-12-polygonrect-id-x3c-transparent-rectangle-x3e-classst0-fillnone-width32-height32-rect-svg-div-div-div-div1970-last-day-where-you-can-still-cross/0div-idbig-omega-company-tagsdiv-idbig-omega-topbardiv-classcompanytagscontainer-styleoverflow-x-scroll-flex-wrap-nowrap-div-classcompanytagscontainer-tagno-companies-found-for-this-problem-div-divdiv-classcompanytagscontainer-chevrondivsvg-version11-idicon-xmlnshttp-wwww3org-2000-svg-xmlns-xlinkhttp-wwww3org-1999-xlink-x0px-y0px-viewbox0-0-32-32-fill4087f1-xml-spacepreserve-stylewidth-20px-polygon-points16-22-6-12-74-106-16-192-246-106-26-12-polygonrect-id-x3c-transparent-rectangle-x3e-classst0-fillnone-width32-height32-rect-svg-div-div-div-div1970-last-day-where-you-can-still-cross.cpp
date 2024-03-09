class Solution {
public:
    
    bool isPossible(vector<vector<int>>grid,int row,int col,vector<vector<int>>cells,int n){
        // vector<vector<int>>grid(row,vector<int>(col,1));
        int delrow[4]={0,1,0,-1};
        int delcol[4]={1,0,-1,0};
        for(int i=0;i<=n;i++){
            grid[cells[i][0]-1][cells[i][1]-1]=0;
        }
        // vector<vector<int>>vis(row,vector<int>(col,0));
        queue<pair<int,int>>q;
        for(int i=0;i<col;i++){
            if(grid[0][i]==1){
                q.push({0,i});
            
            }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==row-1){
                return true;
            }
            // cout<<x<<" "<<y<<endl;
            for(int i=0;i<4;i++){
                int newx=x+delrow[i];
                int newy=y+delcol[i];
                if(newx>=0 && newx<row && newy>=0 && newy<col && grid[newx][newy]==1){
                    grid[newx][newy]=0;
                    q.push({newx,newy});
                }
            }
        }
        return false;
        
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>>grid(row,vector<int>(col,1));
        // vector<vector<int>>vis(row,vector<int>(col,0));
        int n=cells.size();
        int low=0,high=n-1;
        int mid=(low+high)/2;
        int ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(isPossible(grid,row,col,cells,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans+1;
    }
};