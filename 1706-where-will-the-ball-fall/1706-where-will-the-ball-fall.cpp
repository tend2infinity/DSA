class Solution {
public:
        int solve(int i, int j, vector<vector<int>>& grid, int m, int n){

        // base condition: if ball passed all rows then, 
        // ball is out at jth column
        if(i == m) return j;
        
        
        /* At a time a ball can move only left or right, not both
		    so even though we have two choices, only one choise can be executed,
			so the recursive structure is not exponential but rather linear -> O(M)*/
        
        // ball can move right if current board and next board are towards right
        if(grid[i][j] == 1 && j + 1 < n && grid[i][j + 1] == 1){
            return solve(i + 1, j + 1, grid, m, n);
        }
        
        // ball can move left if current board and previous board is towards left
        if(grid[i][j] == -1 && j - 1 >= 0 && grid[i][j - 1] == -1){
            return solve(i + 1, j - 1, grid, m, n);
        }
        
        // if ball couldn't move left or right, then its trapped
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // stores the answer 
        vector<int> fall(n);
        
		// Find the status of each ball -> O(N)
        for(int i = 0; i < n; i++){
            fall[i] = solve(0, i, grid, m, n);
        }
        
        return fall;
    }
    
};