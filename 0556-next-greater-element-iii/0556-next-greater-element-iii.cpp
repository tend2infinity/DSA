class Solution {
public:
    int nextGreaterElement(int n) {
        string S="";
        S = to_string(n);
        bool flag=false;
        for(int i=S.size()-2; i>=0; i--){
            if(S[i]<S[i+1]){
                flag=true;
                char mini = 'z';
                int min_index= int(1e9);
                for(int j=i+1; j<S.size(); j++){
                    if(S[j]>S[i] && S[j]<mini){
                        mini = S[j];
                        min_index = j;
                    }
                }
                char temp;
                temp = S[i];
                S[i] = S[min_index];
                S[min_index] = temp;
                sort(S.begin()+i+1,S.end());
                break;
            }
        }
        if(flag == false || stoll(S)>INT_MAX)
            return -1;
        return stoi(S);

    }
};