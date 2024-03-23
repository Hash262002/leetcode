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
    ListNode* reverse(ListNode* head){
        ListNode* ans=head;
        ListNode* prev=NULL;
        while(ans!=NULL){
            ListNode* temp=ans->next;
            ans->next=prev;
            prev=ans;
            ans=temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp->next=reverse(temp->next);
            temp=temp->next;
        }
        
    }
};