class Solution {
public:
    
    // bool compare()
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans(people.size(), vector<int>(2,-1));
        sort(people.begin(), people.end());
        // for(auto i : people){
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }
        int last=0;
        for(int i=0; i<people.size(); i++){
            int j = 0,count=0;
                while(count<people[i][1]){
                    if(ans[j][1]==-1 || ans[j][0]>=people[i][0])
                        count++;
                    j++;
                }
                while(ans[j][1]!=-1)
                    j++;
                ans[j]=people[i];
            // int j = people[i][1];
            // if(last==0){
            //     ans[j]=people[i];
            // }
            // else{
            //     while(ans[j][1]!=-1){
            //         last++;             
            //     }
            //     int k
            // }


        }
        return ans;
    }
};