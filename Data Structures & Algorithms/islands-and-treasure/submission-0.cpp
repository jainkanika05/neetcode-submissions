class Solution {
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int rown=row+dir[i][0];
                int coln=col+dir[i][1];
                if (rown < 0 || rown >= n || coln < 0 || coln >= m || grid[rown][coln] != INT_MAX) {
                    continue;
                }
                grid[rown][coln]=grid[row][col]+1;
                q.push({rown,coln});
            }
        }
    }
};
