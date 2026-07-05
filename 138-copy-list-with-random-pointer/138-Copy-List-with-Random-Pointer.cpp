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

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL)
        return NULL;
        // insert new nodes in between nodes
        Node* curr = head;
        while(curr){
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp; 
            curr = curr->next->next; 
        }
        // adding random pointer in new Nodes
        curr = head;
        
        while(curr && curr->next ){
            if(curr->random == NULL){
                curr->next->random = NULL;
            }
            else{
                curr->next->random = curr->random->next;
            }  
            curr = curr->next->next;
        }

        // separating the nodes 
        curr = head;
        Node* newHead = head->next;
        Node* newCurr = curr->next;

        while(curr && newCurr){
            curr->next =curr->next == NULL ? NULL:curr->next->next; 

            newCurr->next =newCurr->next == NULL ? NULL:newCurr->next->next;

            curr = curr->next;
            newCurr = newCurr->next;


        }

        return newHead;
    }
};