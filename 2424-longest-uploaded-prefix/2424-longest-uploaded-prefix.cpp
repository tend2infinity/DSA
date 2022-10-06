class LUPrefix {
public:
    vector<bool> prefix;
    int i=0;
    LUPrefix(int n) {
        prefix.resize(n+1);
    }
    
    void upload(int d) {
        // auto x = find(stream.begin(),stream.end(),d);
        // stream.erase(x);
        prefix[d-1] = 1;
    }
    
    int longest() {
        while(prefix[i]==1){
            i++;
        }
        return i;    
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */