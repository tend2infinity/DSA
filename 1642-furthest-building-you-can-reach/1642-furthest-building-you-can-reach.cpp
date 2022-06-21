class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int > pq; // minHeap
        int i=0;
        int n = heights.size();
        int jump_size;
        while(i<n-1 && ladders>0)
        {
            jump_size = heights[i+1] - heights[i];
            if(jump_size>0){
                pq.push(-jump_size);
                ladders--;
            }
            i++;
        }
        while(i<n-1){
            jump_size = heights[i+1] - heights[i];
            if(jump_size > 0){
                if(!pq.empty() && -pq.top() < jump_size ){
                    bricks += pq.top();
                    pq.pop();
                    pq.push(-jump_size);
                } 
                else bricks -= jump_size;
            }
            if(bricks<0)
                return i;
            i++;
        }
        return i;
    }
};