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
    ListNode* reverseList(ListNode* head) {
        ListNode * newhead=NULL; // introducinf the new null pointer
        ListNode* curr=head;

        while(curr!=NULL){
            ListNode* next=curr->next; // saving the next node
            curr->next=newhead;// pointing backward;;
            newhead=curr; //changing the head
            curr=next; 


        }

        return newhead;
    }
};