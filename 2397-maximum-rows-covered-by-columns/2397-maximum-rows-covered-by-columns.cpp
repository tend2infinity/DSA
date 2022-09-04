class Solution {
public:
    int maxi = -1e8;
    void recur(vector<vector<int>>& mat, int cols, int index, vector<int>& vis, int m, int n){
        //base
        if(index==n || cols==0){
            int count = 0;
            for(int row=0; row<m ; row++){
                bool cover= true;
                for(int col=0; col<n; col++){
                    if(mat[row][col] == 1 && vis[col] ==0){
                        cover= false;
                        break;
                    }
                }
                if(cover)
                    count++;
            }
            maxi = max(maxi,count);
            return;
        }
        
        //take
        vis[index] = 1;
        recur(mat,cols-1,index+1,vis,m,n);
        vis[index] = 0;
        
        //notTake
        recur(mat,cols,index+1,vis,m,n);
        
        return;
    }
        
        
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> vis(n+1,0);
        recur(mat,cols,0,vis,m,n);
        return maxi;
    }
};