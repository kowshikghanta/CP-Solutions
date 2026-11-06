class MyLinkedList {
public:
    typedef struct node {
        int val;
        struct node* next;
    } Node;

    Node *head, *tail;
    int size;

    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if (size <= index) {
            return -1;
        }
        Node* temp = head;
        while (index != 0) {
            temp = temp -> next;
            index--;
        }

        return temp -> val;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node{val, NULL};
        temp -> next = head;
        head = temp;
        size++;
        if (size == 1) {
            tail = head;
        }
    }
    
    void addAtTail(int val) {
        Node* temp = new Node{val, NULL};

        if (size == 0) {
            head = tail = temp;
        } else {
            tail -> next = temp;
            tail = temp;
        }

        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (size < index) {
            return;
        } else if (size == index) {
            addAtTail(val);
            return;
        } else if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;
        while (index != 1) {
            temp = temp -> next;
            index--;
        }

        Node* temp2 = new Node{val, NULL};
        temp2 -> next = temp -> next;
        temp -> next = temp2;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (size <= index) {
            return;
        }
        if (index == 0) {
            Node* temp = head;
            head = head -> next;
            delete(temp);
            size--;
            return;
        }
        Node* temp = head;
        while (index != 1) {
            index--;
            temp = temp -> next;
        }
        Node* temp2 = temp -> next;
        temp -> next = temp2 -> next;
        delete(temp2);
        size--;
        if (temp -> next == NULL) {
            tail = temp;
        }
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */