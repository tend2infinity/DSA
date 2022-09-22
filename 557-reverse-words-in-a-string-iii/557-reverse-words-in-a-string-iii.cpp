class Solution {
public:
    string reverseWords(string s) {
        string word="";
        string dup="";
        for(int i=0; i<s.size(); i++){
            if(i==s.size()-1){
                word+=s[i];
                reverse(word.begin(),word.end());
                for(auto a:word){
                    dup.push_back(a);
                }
            }
            if(s[i]==' '){
                reverse(word.begin(),word.end());
                for(auto a:word){
                    dup.push_back(a);
                }
                dup.push_back(' ');
                word="";
            }else{
               word+=s[i]; 
            }
        }
        return dup;
    }
};