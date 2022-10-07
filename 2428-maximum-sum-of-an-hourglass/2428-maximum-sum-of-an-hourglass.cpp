class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int sum=0;
        // sum=grid[0][0]+grid[0][1]+grid[0][2]+grid[1][1]+grid[2][0]+grid[2][1]+grid[2][2]; 
        for(int i=0; i<grid.size()-2; i++){
            for(int j=0; j<grid[0].size()-2; j++){
                int currSum=0;
                for(int a=0;a<=2;a++){
                    for(int b=0;b<=2;b++){
                        if((a==1 && b==0) || (a==1 && b==2))
                            continue;
                        currSum+= grid[a+i][b+j];
                    }
                }
                sum = max(sum,currSum);
            }
        }
        return sum;
    }
};