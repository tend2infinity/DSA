// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
	public:
	long long int dp[4][4][27];
	long long recur(int N, vector<vector<int>>& grid, int i, int j){
	    //base
	    if(i>3||j>2 || i<0 || j<0)
	        return 0;
        if(i==3 && (j==0 || j==2))
            return 0;
        if(N<1)
            return 0;
        if(N==1)
            return 1;
        if(dp[i][j][N]!= -1)
            return dp[i][j][N];
        

        while(N){
            return dp[i][j][N] = recur(N-1,grid,i,j) + recur(N-1,grid,i-1,j) + recur(N-1,grid,i,j-1) + recur(N-1,grid,i+1,j) + recur(N-1,grid,i,j+1);
        }
	    	        
	    

	}
	
	long long getCount(int N)
	{
	    memset(dp,-1,sizeof(dp));
        vector<vector<int>> grid{{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        long long int sum =0;
        for(int i=0; i<=3; i++){
            for(int j=0; j<=2; j++){
                if(i==3 &&(j==0 || j==2))
                    continue;
                sum +=recur(N,grid,i,j);
            }
        }
        return sum ; 
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends