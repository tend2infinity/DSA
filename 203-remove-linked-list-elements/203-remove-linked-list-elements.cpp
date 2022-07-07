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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        if(curr -> next == NULL && curr->val == val)
            return NULL;
        while(curr!=NULL && curr->next!=NULL){
            prev = curr;
            curr = curr-> next;
            while(curr!=NULL && curr->val == val){
                prev -> next = curr-> next;
                curr = curr->next;
            }
        }
        if(head->val == val)
            head = head->next;
        
        return head;
    }
};