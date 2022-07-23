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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
            return NULL;
        queue<ListNode*> less;
        queue<ListNode*> greater;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val<x)
                less.push(temp);
            else
                greater.push(temp);
            temp=temp->next;
        }
        ListNode* headnew = NULL;
        if(less.size()>0){
            headnew = less.front();
            less.pop();
            ListNode* prev = headnew;
            ListNode* curr = NULL;
            while(!less.empty()){
                curr = less.front();
                less.pop();
                curr->next = NULL;
                prev->next = curr;
                prev = curr;
            }
            while(!greater.empty()){
                curr = greater.front();
                greater.pop();
                curr-> next = NULL;
                prev -> next = curr;
                prev = curr;
            } 
        }
        else{
            headnew = greater.front();
            greater.pop();
            ListNode* prev = headnew;
            ListNode* curr = NULL;
            while(!greater.empty()){
                curr = greater.front();
                greater.pop();
                curr-> next = NULL;
                prev -> next = curr;
                prev = curr;
            }
        }
        return headnew;

    }
};