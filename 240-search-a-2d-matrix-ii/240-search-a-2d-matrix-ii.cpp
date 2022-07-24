class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int low,mid,high;
        for(int i=0;i<m;i++){
            if(n==1 && matrix[i][0]==target)return true; //change
            else{
                if(matrix[i][0]<=target && matrix[i][n-1]>=target){
                int low=0;
                int high=n-1;
                while(low<=high){
                    mid = (high - low) / 2 + low; //change
                    if(matrix[i][mid]==target){
                        return true;
                    }
                    else if(matrix[i][mid]<target)low=mid+1;
                    else if(matrix[i][mid]>target)high=mid-1; //change
                }
            }
            }
        }
        return false;
    }
};