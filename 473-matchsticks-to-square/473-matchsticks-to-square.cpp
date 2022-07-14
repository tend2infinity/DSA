class Solution {
public:
    bool recur(vector<int>& matchsticks, vector<bool>& visited, int index, int k, int sum,      int curr){
        if(k==1)
            return true;

        if(index >= matchsticks.size()){
           return false;
        }

        if(curr==sum){
            return recur(matchsticks,visited,0,k-1,sum,0);            
        }
        
        for(int i=index; i<matchsticks.size(); i++){
            if(!visited[i] && curr + matchsticks[i]<=sum ){
                visited[i] = true;
                if (recur(matchsticks,visited,i+1,k,sum,curr+matchsticks[i]))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.rbegin(),matchsticks.rend());
        int sum = 0;
        int maxi =0;
        for(int i=0; i<matchsticks.size(); i++){
            sum +=matchsticks[i];
        }  
        // to find if we can divide this particular array into 4 subsets having subset sum              equal to sum calculated above
        int n = matchsticks.size();
        vector<bool> visited (n,false);
        if( sum%4==0 ) {
            int target = sum/4;
            return recur(matchsticks,visited,0,4,target,0);
        }
        return false;      
    }
};