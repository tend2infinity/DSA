class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res = {{rStart, cStart}};
        int rowMov = 0, colMov = 1, tmp;
        for (int n = 0; res.size() < rows * cols; n++) {
            for (int i = 0; i < n / 2 + 1; i++) {
                rStart += rowMov, cStart += colMov;
                if (0 <= rStart && rStart < rows && 0 <= cStart && cStart < cols)
                    res.push_back({rStart, cStart});
            }
            tmp = rowMov, rowMov = colMov, colMov = -tmp;
        }
        return res;
    }
};