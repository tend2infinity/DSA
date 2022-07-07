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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL && curr-> next != NULL){
            prev = curr;
            curr = curr-> next;
            while(curr!=NULL && prev->val == curr->val ){
                prev->next = curr->next;
                curr = curr->next;
            }
        }
        return head;
    }
};