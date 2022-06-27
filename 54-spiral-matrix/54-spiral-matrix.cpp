class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res;
        int direction=1;
        int top =0, left=0, bottom=n-1, right=m-1;
        while(top<=bottom && left<=right){
            if(direction ==1){
                for(int j=left; j<=right; j++){
                    res.push_back(matrix[top][j]);
                }
                top++;
                direction=2;
            }
            else if(direction ==2){
                for(int i=top; i<=bottom; i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
                direction=3;
            }
            else if(direction ==3){
                for(int j=right; j>=left; j--){
                    res.push_back(matrix[bottom][j]);
                }
                bottom--;
                direction=4;
            }
            else if(direction ==4){
                for(int i=bottom; i>=top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
                direction=1;
            }
              
        }
        return res;
    }
};