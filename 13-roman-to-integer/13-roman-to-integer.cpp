class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char,int> M;
        M['I']=1;
        M['V']=5;
        M['X']=10;
        M['L']=50;
        M['C']=100;
        M['D']=500;
        M['M']=1000;
        int sum=0;
        for(int i=s.size()-1; i>=0; i--){
            if(i>0){
                if(s[i]=='V' && s[i-1]=='I'){
                    sum+=4;
                    i--;
                }
                else if(s[i]=='X' && s[i-1]=='I'){
                    sum+=9;
                    i--;
                }
                else if(s[i]=='L' && s[i-1]=='X'){
                    sum+=40;
                    i--;
                }
                else if (s[i]=='C' && s[i-1]=='X'){
                    sum+=90;
                    i--;
                }
                else if(s[i]=='D' && s[i-1]=='C'){
                    sum+=400;
                    i--;
                }
                else if(s[i]=='M' && s[i-1]=='C'){
                    sum+=900;
                    i--;
                } 
                else{
                    sum+=M[s[i]];
                }
            }
            else
                sum+=M[s[i]];
            

            
        }
        return sum;
    }
};