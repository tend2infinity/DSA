class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26); // maintain frequency of every character
        
        for(char ch : word) {
            freq[ch - 'a'] += 1;
        }
        
        int mx_freq = 0, mn_freq = word.size(), cnt_mx = 0, cnt_mn = 0;
        
        for(int i = 0; i < 26; ++i) {
            mx_freq = max(mx_freq, freq[i]);                  // maintain max frequency
            if(freq[i] > 0) mn_freq = min(mn_freq, freq[i]);  // maintain min frequency
        }
        
        for(int i = 0; i < 26; ++i) {
            if(freq[i] == mx_freq)
                ++cnt_mx;         // increment count of characters with max frequency
            else if(freq[i] == mn_freq)
                ++cnt_mn;        // increment count of characters with min frequency
            else if(freq[i] > 0) 
                return false;   // distinct frequencies is greater than 2
        }
        
        if(mx_freq == mn_freq)
            return cnt_mx == 1 || mx_freq == 1;
        
        if(cnt_mn == 1 && mn_freq == 1)
            return true;
        
        if(mx_freq != mn_freq + 1 || cnt_mx != 1)
            return false;
        
        return true;
    }
};