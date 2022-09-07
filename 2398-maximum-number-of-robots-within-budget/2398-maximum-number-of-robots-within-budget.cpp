class Solution {
public:
    
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        long long int i=0;
        long long int j=0;
        long long int robot_count = 0;
        multiset<long long int> S;
        long long currentRunCost=0;
        long long currentMaxCharge=0;
        while(i<=j && i<runningCosts.size() && j<runningCosts.size()){
            currentRunCost += runningCosts[j];
            S.insert(chargeTimes[j]);
            currentMaxCharge = *S.rbegin();
            long long totalRunCost = (j-i+1)*currentRunCost;
            long long total = currentMaxCharge + totalRunCost;
            if( total >budget){
                currentRunCost -= runningCosts[i];
                S.erase(S.find(chargeTimes[i]));
                i++;
            }
            else{
                robot_count = max(robot_count,j-i+1);
            }  
            j++;
        }
        return robot_count;
    }
};