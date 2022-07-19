class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal={{1}};
        for(int row=1; row<numRows; row++){
            vector<int> block (row+1,0);
            block[0] = 1;
            block[block.size()-1]=1;
            for(int i=1; i<block.size()-1; i++){
                block[i] = pascal[row-1][i-1] + pascal[row-1][i];
            }
            pascal.push_back(block);
        }

        return pascal;
    }
};