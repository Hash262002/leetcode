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
    ListNode* reverseList(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp=head;
        ListNode* reverse=reverseList(temp);
        ListNode* ans=reverse;
        int a=0,next=0;
        ListNode* temp2=NULL;
        while(reverse!=NULL){
            temp2=reverse;
            reverse->val=reverse->val*2+next;
            a=reverse->val;
            
            reverse->val%=10;
            next=a/10;
            reverse=reverse->next;
        }
        while(next!=0){
            temp2->next=new ListNode(next%10);
            temp2=temp2->next;
            next/=10;
        }
        ListNode* ans2=reverseList(ans);
        return ans2;
    }
};