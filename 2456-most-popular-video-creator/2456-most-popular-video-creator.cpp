class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,long long int> M;
        vector<vector<string>> ans;
        long long int maxi = 0;
        for(int i=0; i<creators.size(); i++){
            M[creators[i]]+=views[i];
            if(M[creators[i]]>maxi)
                maxi = M[creators[i]];
        }
        // cout<<maxi<<endl;
        map< string,pair<int,string> >N;
        set<string> S;
        for(int i=0; i<creators.size(); i++){
            if(views[i] > N[creators[i]].first ){
                N[creators[i]].first = views[i];
                N[creators[i]].second = ids[i];
            }
            else if (views[i] == N[creators[i]].first && N[creators[i]].second > ids[i] || views[i] == N[creators[i]].first && views[i]==0){
                N[creators[i]].first = views[i];
                N[creators[i]].second = ids[i];
            }
        }
        // cout<<N["alice"].first<<" "<<N["alice"].second;
        
        for(auto x: M){
            vector<string> v;
            if(x.second == maxi){
                // cout<<x.first<<endl;
                v.push_back(x.first);
                v.push_back( N[x.first].second );
            }
            if(v.size()!=0) ans.push_back(v);
        }
        

        return ans;
        
    }
};