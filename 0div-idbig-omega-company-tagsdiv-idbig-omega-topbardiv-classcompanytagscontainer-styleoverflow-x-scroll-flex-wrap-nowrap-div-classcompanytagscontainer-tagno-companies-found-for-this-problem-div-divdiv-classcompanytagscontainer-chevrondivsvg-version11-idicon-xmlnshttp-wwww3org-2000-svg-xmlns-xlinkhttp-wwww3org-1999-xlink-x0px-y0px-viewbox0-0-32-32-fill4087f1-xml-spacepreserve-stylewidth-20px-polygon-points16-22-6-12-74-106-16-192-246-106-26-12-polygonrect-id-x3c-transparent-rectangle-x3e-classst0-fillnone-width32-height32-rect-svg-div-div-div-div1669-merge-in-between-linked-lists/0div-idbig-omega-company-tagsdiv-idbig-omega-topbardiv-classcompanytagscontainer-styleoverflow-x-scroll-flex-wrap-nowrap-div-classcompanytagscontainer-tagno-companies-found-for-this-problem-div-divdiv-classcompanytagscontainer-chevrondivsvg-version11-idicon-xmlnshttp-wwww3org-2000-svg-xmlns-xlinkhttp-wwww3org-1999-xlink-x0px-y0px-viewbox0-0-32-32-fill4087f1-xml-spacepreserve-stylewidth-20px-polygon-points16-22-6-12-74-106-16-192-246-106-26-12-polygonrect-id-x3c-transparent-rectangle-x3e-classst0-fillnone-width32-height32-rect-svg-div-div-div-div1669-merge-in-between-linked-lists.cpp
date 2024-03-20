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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int temp_a=a,temp_b=b;
        ListNode* temp1=list1;ListNode* temp2=list2;
        ListNode* ptr1=NULL;ListNode* ptr2=NULL;
        ListNode* prev=NULL;
        while(temp_a!=0){
            prev=temp1;
            temp1=temp1->next;
            temp_a--;
        }
        ptr1=prev;
        temp_b-=a;
        while(temp_b!=0){
            temp1=temp1->next;
            temp_b--;
        }
        ptr2=temp1;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        ptr1->next=list2;
        temp2->next=ptr2->next;
        ptr2->next=NULL;
        return list1;
    }
};