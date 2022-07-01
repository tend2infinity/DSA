class Solution {
public:
    static bool compare(vector<int>v1, vector<int>v2){
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int units=0;
        for(int i=0; i<boxTypes.size(); i++){
            if(boxTypes[i][0]<=truckSize){
                units += boxTypes[i][1]*boxTypes[i][0] ;
                truckSize -= boxTypes[i][0];     
            }
            else {
                while(truckSize){
                    units += boxTypes[i][1];
                    truckSize--;
                }
            }

        }
        return units;

    }
};