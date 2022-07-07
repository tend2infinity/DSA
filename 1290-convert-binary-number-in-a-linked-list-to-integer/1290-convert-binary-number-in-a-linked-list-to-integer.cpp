/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* curr = head;
        vector<int> ans;
        while(curr!=NULL){
            ans.push_back(curr->val);
            curr=curr->next;
        }
        int size = ans.size()-1;
        int sum=0;
        for(int i=0; i<ans.size(); i++){
            sum += ans[i]*pow(2,size);
            size--;
        }
        return sum;
    }
};