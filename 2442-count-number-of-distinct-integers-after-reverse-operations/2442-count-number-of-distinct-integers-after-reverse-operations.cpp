class Solution {
public:
    void reverseStr(string& str)
    {
        int n = str.length();

        // Swap character starting from two
        // corners
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }
    int countDistinctIntegers(vector<int>& nums) {
         unordered_set<int> seen;
        for (int num : nums) {
            seen.insert(num);
            string str = to_string(num);
            reverseStr(str);
            seen.insert(stoi(str));
        }
        return seen.size();
    }
};