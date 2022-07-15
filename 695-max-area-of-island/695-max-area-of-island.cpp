class Solution {
public:

    int recur(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis){
        //base
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)
            return 0;
        
        if(grid[i][j]==1 && vis[i][j]==0){
            vis[i][j]=1;  
            return 1 + recur(grid,i+1,j,vis) + recur(grid,i,j+1,vis) + recur(grid, i-1,j,vis) + recur(grid,i,j-1,vis);
        }
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi =0;
        vector<vector<bool>> vis(55,vector<bool>(55,0));
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;  i<m; i++){
            for(int j=0; j<n; j++){
                cout<<i<<j<<" ";
                maxi = max(maxi, recur(grid,i,j,vis));                    
            }
        }
        return maxi;
    }
};