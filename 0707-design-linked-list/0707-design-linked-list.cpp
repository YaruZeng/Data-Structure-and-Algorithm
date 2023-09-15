class MyLinkedList {
public:
    struct LinkNode {
        int val;
        LinkNode* next;
        LinkNode(int val): val(val), next(nullptr){}
    };
    
    MyLinkedList() {
        _dummyHead = new LinkNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index > _size - 1) return -1;
        LinkNode* cur = _dummyHead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkNode* newNode = new LinkNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkNode* newNode = new LinkNode(val);
        
        LinkNode* cur = _dummyHead;
        while(cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > _size) return;
        
        LinkNode* newNode = new LinkNode(val);
        LinkNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index > _size - 1) return;
        LinkNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        LinkNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        temp = nullptr; // make sure temp is not assigned a random value
        _size--;
    }
    
private:
    LinkNode* _dummyHead;
    int _size;
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