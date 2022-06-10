#include<bits/stdc++.h>
class Solution {
public:
    //part of approach 3
    int less_or_equal
        (int mid, vector<int>& nums){
        int less=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=mid)
                less++;
        }
        cout<<"less ="<<less<<" ";
        return less;   
    }
        
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        //approach 1
//         vector<bool> freq(n,0);
//         for(int i=0; i<n; i++){
//             if(freq[nums[i]]!=1)
//                 freq[nums[i]]=1;
//             else{
//                 return nums[i];
//             }
                
//         }
        
        // approach 2
        // for(int i=0; i<n; i++){
        //     if(nums[abs(nums[i])]>0)
        //         nums[abs(nums[i])] = -nums[abs(nums[i])];
        //     else
        //         return abs(nums[i]);
        // }
        
        //approach 3
//         int low=1;
//         int high = nums.size();
//         int dup=-1;
//         while(low<=high){
//             int mid = low+ (high-low)/2;
//             cout<<mid<<endl;
//             if(less_or_equal(mid,nums)>mid)
//             {
//                 dup=mid;
//                 high=mid-1;         
//             }
//             else
//                 low=mid+1;
//         }
        
//         return dup;
        
        
        //approach 4
        //  int duplicate=0;
        // int maxi=0;
        // for(int i=0;i<nums.size(); i++)
        //     maxi=max(maxi,nums[i]);
        // int max_set_bits=0;
        // while(maxi){
        //     max_set_bits++;
        //     maxi=maxi/2;
        // }
        // for(int bit=0; bit<max_set_bits; bit++){
        //     int mask=1<<bit;
        //     int base_count=0;
        //     int num_count=0;
        //     for(int i=0; i<nums.size(); i++){
        //         if(mask&i)
        //             base_count++;
        //         if(mask&nums[i])
        //             num_count++;
        //     }
        //     if(num_count>base_count)
        //         duplicate=duplicate | mask; 
        // }
        // return duplicate;
        
        
        
        //approach 5
        int turtle=nums[0];
        int hare= nums[0];
        do{
            turtle=nums[turtle];
            hare=nums[nums[hare]];
        } while(turtle!=hare);
        
        turtle=nums[0];
        while(turtle!=hare) {
            turtle=nums[turtle];
            hare=nums[hare];
        }
        return turtle;
    }
};