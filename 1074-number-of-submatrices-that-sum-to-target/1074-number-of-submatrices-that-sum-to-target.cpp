class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        vector<vector<int>> prefix(matrix.size(), vector<int>(matrix[0].size(),0));
        
        for(int i=0; i<matrix.size(); i++){
            prefix[i][0] = matrix[i][0];
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                prefix[i][j]= prefix[i][j-1] + matrix[i][j];
            }
        }
        int sum=0;
        unordered_map<int,int> M;
        
        for(int col1=0; col1<matrix[0].size(); col1++){
            for(int col2=col1; col2<matrix[0].size(); col2++){
                int runningSum = 0;
                M={{0,1}};
                for(int row=0; row<matrix.size(); row++){
                    runningSum += prefix[row][col2] - (col1? prefix[row][col1-1] : 0);
                    if(M[runningSum-target]>0)
                        sum+= M[runningSum-target];
                    M[runningSum]++;
                }
            }
        }
        
        return sum;
    }
};