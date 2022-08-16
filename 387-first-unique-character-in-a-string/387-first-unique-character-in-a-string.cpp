class Solution {
public:
    int firstUniqChar(string s) {
        int index=1e8;
        unordered_map<char,pair<int,int>>M;
        for(int i=0; i<s.size(); i++){
            M[s[i]].first++;
            M[s[i]].second=i;
        }
        for(int i=0; i<s.size(); i++){
            if(M[s[i]].first==1){
                index = min(index,M[s[i]].second);
            }   
        }
        if(index==1e8)
            return -1;
        else
            return index;
    }
};