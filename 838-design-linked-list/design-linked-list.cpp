class MyLinkedList {
private:
    class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int val) {
            this->val = val;
            this->next = NULL;
        }
    };

    ListNode* head;
    int size;

public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    int get(int index) {
        if(index < 0 || index >= size) return -1;

        ListNode* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }

        return temp->val;
    }

    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
        size++;
    }

    void addAtTail(int val) {
        ListNode* node = new ListNode(val);

        if(head == NULL){
            head = node;
        } else {
            ListNode* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = node;
        }

        size++;
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;

        if(index == 0){
            addAtHead(val);
            return;
        }

        ListNode* temp = head;
        for(int i = 0; i < index - 1; i++){
            temp = temp->next;
        }

        ListNode* node = new ListNode(val);
        node->next = temp->next;
        temp->next = node;

        size++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;

        if(index == 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        } else {
            ListNode* curr = head;
            for(int i = 0; i < index - 1; i++){
                curr = curr->next;
            }

            ListNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }

        size--;
    }
};