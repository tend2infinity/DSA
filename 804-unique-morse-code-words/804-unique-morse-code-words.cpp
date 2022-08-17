class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> V {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set <string> S;
        for(int i=0; i<words.size(); i++){
            string str="";
            for(int j=0; j<words[i].size(); j++){
                str = str + V[words[i][j] - 'a'];
            }
            S.insert(str);
        }
        return S.size();
    }
};