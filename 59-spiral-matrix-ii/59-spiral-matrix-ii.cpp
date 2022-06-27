class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int direction=1;
        int top =0, left=0, bottom=n-1, right=n-1;
        int value=1;
        while(top<=bottom && left<=right){
            if(direction ==1){
                for(int j=left; j<=right; j++){
                    matrix[top][j]= value;
                    value++;
                }
                top++;
                direction=2;
            }
            else if(direction ==2){
                for(int i=top; i<=bottom; i++){
                    matrix[i][right]= value;
                    value++;
                }
                right--;
                direction=3;
            }
            else if(direction ==3){
                for(int j=right; j>=left; j--){
                    matrix[bottom][j] = value;
                    value++;
                }
                bottom--;
                direction=4;
            }
            else if(direction ==4){
                for(int i=bottom; i>=top; i--){
                    matrix[i][left] = value;
                    value++;
                }
                left++;
                direction=1;
            }
              
        }
        return matrix;
    }
};