class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i=k-1;
        int j= cardPoints.size();
        int sum=0;
        for(int ptr=0;ptr<=i;ptr++){
            sum+= cardPoints[ptr];
        }
        int maxi=sum;
        while(k>0){
            i--;
            j--;
            sum = sum - cardPoints[i+1] + cardPoints[j];
            maxi = max(maxi,sum);
            k--;
        }
        return maxi;

    }
};