/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// step1
void Insertinbetween(Node *head){
    Node*temp=head;
    while(temp!=NULL){
        Node* copy=new Node(temp->val);
        Node * nextel=temp->next;
        temp->next=copy;
        copy->next=nextel;

        temp=temp->next->next;


    }
}

void Connectrandom(Node * head){
    Node *temp=head;

    while(temp!=NULL){
        Node * copyel=temp->next;
        if(temp->random){
            copyel->random=temp->random->next;
        }else{
            copyel->random=NULL;
        }

        temp=temp->next->next;

    }
}

Node * Connectnextpointer(Node* head){
    Node* temp=head;

    Node * dummy=new Node(0);
    Node* curr=dummy;

    while(temp!=NULL){
        Node* el=temp->next;

        curr->next=el;
        curr=curr->next;

        temp->next=el->next;

        temp=temp->next;

    }
    return dummy->next;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Insertinbetween(head);
         Connectrandom(head);
         return  Connectnextpointer(head);
    }
};