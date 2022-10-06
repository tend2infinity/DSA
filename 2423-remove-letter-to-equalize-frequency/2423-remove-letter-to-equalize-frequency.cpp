class Solution {
public:
    bool equalFrequency(string word) {
        map<int,int>M;
        for(auto x:word){
            M[x-'a']++;            
        }

        bool res_2=false;
        for(int i=0; i<26; i++){
            if(M[i]==0)
                continue;
            int new_count = M[i]-1;
            bool result = true;
            for(int j=0;j<26;j++){
                if(i==j || M[j]==0)
                    continue;
                if(new_count==0){
                    new_count = M[j];
                    continue;
                }
                if(M[j]!=new_count){
                    cout<<M[j]<<" "<<new_count<<endl;
                    result = false;
                    break;                    
                }
            }
            if(result==true){
                res_2=true;
                break;
            }
            continue;                
        }
        if(res_2==true)
            return true;
        return false;   
        
    }
};