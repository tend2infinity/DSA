class Solution {
public:
    void reverseString(string& S){
        for(int i=0; i<S.size()/2; i++){
            swap(S[i],S[S.size()-1-i]);
        }
    }
    bool sumOfNumberAndReverse(int num) {
        string S;
        int rev;
        for(int i=num/2; i<=num; i++){
            S = to_string(i);
            reverseString(S);
            rev = stoi(S);
            if(i + rev == num)
                return true;
            S.clear();
        }
        return false;
    }
};