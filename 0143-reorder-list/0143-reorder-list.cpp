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
    void reorderList(ListNode* head) {
        //3 steps..
        // find the mid first
        // reverse the second half
        // reordered them


        // step1
if(head==NULL||head->next==NULL){
    return;
}
        ListNode* fast=head;
        ListNode * slow=head;

        while(fast!=NULL&& fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode *curr=slow->next;

        slow->next=NULL; // cutting the line  matlab secondhalf bada todeko

        // aba reverse mar;


        ListNode * newhead=NULL;

        while(curr!=NULL){
            ListNode * next=curr->next;

            curr->next=newhead;// connection jordai chum

            newhead=curr;//pointer move gardai chum

            curr=next;

        }


        ListNode * first=head;
        ListNode * second=newhead;

        while(second!=NULL){
            ListNode* next1=first-> next;

            ListNode* next2=second->next;

            first->next=second;
            second->next=next1;
            first=next1;
            second=next2;

        }



        
    }
};