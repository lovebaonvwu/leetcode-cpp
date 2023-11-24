struct MyListNode {
  int val;
  MyListNode* next;
  MyListNode(int val) : val{val}, next{nullptr} {}
};

class MyLinkedList {
  MyListNode* head;
  MyListNode* tail;
  int size;

 public:
  /** Initialize your data structure here. */
  MyLinkedList() : head{nullptr}, tail{nullptr}, size{0} {}

  /** Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1. */
  int get(int index) {
    if (size <= index || index < 0) {
      return -1;
    }

    MyListNode* cur = head;

    while (index != 0) {
      cur = cur->next;
      --index;
    }

    return cur->val;
  }

  /** Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    if (size == 0) {
      head = new MyListNode(val);
      tail = head;
    } else {
      MyListNode* node = new MyListNode(val);
      node->next = head;
      head = node;
    }

    ++size;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    if (size == 0) {
      head = new MyListNode(val);
      tail = head;
    } else {
      MyListNode* node = new MyListNode(val);
      tail->next = node;
      tail = tail->next;
    }

    ++size;
  }

  /** Add a node of value val before the index-th node in the linked list. If
   * index equals to the length of linked list, the node will be appended to the
   * end of linked list. If index is greater than the length, the node will not
   * be inserted. */
  void addAtIndex(int index, int val) {
    if (size < index) {
      return;
    }

    if (size == index) {
      addAtTail(val);
      return;
    }

    if (index <= 0) {
      addAtHead(val);
      return;
    }

    MyListNode* cur = head;
    MyListNode* prev = nullptr;

    while (index != 0) {
      prev = cur;
      cur = cur->next;
      --index;
    }

    MyListNode* node = new MyListNode(val);
    node->next = prev->next;
    prev->next = node;

    ++size;
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    if (size <= index || index < 0) {
      return;
    }

    if (index == 0) {
      MyListNode* tmp = head;
      head = head->next;
      delete tmp;

      --size;

      return;
    }

    MyListNode* cur = head;
    MyListNode* prev = nullptr;

    while (index != 0) {
      prev = cur;
      cur = cur->next;
      --index;
    }

    prev->next = cur->next;
    if (tail == cur) {
      tail = prev;
    }
    delete cur;

    --size;
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
// 48ms

struct MyListNode {
  int val;
  MyListNode* next;
  MyListNode* prev;
  MyListNode(int val) : val{val}, next{nullptr}, prev{nullptr} {}
};

class MyLinkedList {
  MyListNode* head;
  MyListNode* tail;
  int size;

 public:
  /** Initialize your data structure here. */
  MyLinkedList() : head{nullptr}, tail{nullptr}, size{0} {}

  /** Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1. */
  int get(int index) {
    if (size <= index || index < 0) {
      return -1;
    }

    MyListNode* cur = head;

    while (index != 0) {
      cur = cur->next;
      --index;
    }

    return cur->val;
  }

  /** Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    MyListNode* node = new MyListNode(val);
    if (size == 0) {
      head = node;
      tail = head;
    } else {
      head->prev = node;
      node->next = head;
      head = node;
    }

    ++size;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    MyListNode* node = new MyListNode(val);
    if (size == 0) {
      head = node;
      tail = head;
    } else {
      node->prev = tail;
      tail->next = node;
      tail = tail->next;
    }

    ++size;
  }

  /** Add a node of value val before the index-th node in the linked list. If
   * index equals to the length of linked list, the node will be appended to the
   * end of linked list. If index is greater than the length, the node will not
   * be inserted. */
  void addAtIndex(int index, int val) {
    if (size < index) {
      return;
    }

    if (size == index) {
      addAtTail(val);
      return;
    }

    if (index <= 0) {
      addAtHead(val);
      return;
    }

    MyListNode* cur = head;
    MyListNode* prev = nullptr;

    while (index != 0) {
      prev = cur;
      cur = cur->next;
      --index;
    }

    MyListNode* node = new MyListNode(val);
    node->prev = prev;
    node->next = prev->next;
    prev->next = node;

    ++size;
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    if (size <= index || index < 0) {
      return;
    }

    if (index == 0) {
      MyListNode* tmp = head;
      head = head->next;
      delete tmp;

      --size;

      return;
    }

    MyListNode* cur = head;
    MyListNode* prev = nullptr;

    while (index != 0) {
      prev = cur;
      cur = cur->next;
      --index;
    }

    if (tail == cur) {
      tail = prev;
    } else {
      cur->next->prev = prev;
    }
    prev->next = cur->next;

    delete cur;

    --size;
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
// 48ms