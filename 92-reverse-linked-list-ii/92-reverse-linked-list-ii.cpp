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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode;
        dummy -> next = head;
        auto prev = dummy;
        auto curr = head;
        int counter = left-1;
        while(counter){
            prev = prev -> next;
            curr = curr -> next;
            counter--;
        }
        auto first = prev;
        prev = NULL;
         counter = right-left +1;
        
        while(counter){
            auto curr1 = curr;
            auto prev1 = prev;
            prev = curr;
            curr = curr->next;
            curr1 -> next = prev1; 
            counter--;
        }
        first->next->next = curr;
        first->next = prev;
        return dummy -> next;
            
    }
};