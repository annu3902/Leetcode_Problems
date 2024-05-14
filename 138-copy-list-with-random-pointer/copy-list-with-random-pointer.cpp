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
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* copyRandomList(Node* head) {
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        // 1. Clone a linked list
        Node* temp = head;
        while(temp!=NULL){
            int data = temp->val;
            insertAtTail(cloneHead, cloneTail, data);
            temp=temp->next;
        }

        // 2. join the random pointers from the originalList to cloneList

        // i. Creating a map from originalPtr to ClonePtr
        unordered_map<Node*, Node*> mpp;

        Node* originalPtr = head;
        Node* clonePtr = cloneHead;

        while(originalPtr!=NULL){
            mpp[originalPtr] = clonePtr;
            originalPtr=originalPtr->next;
            clonePtr = clonePtr->next;
        }

        // ii. Copying the random pointers
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode != NULL){
            cloneNode->random = mpp[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};