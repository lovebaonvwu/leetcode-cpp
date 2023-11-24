class MyCircularDeque {
 public:
  int cnt = 0;
  int head;
  int tail = 0;
  int size;

  vector<int> buffer;

  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int k) {
    size = k;
    head = k - 1;

    buffer = vector<int>(k);
  }

  /** Adds an item at the front of Deque. Return true if the operation is
   * successful. */
  bool insertFront(int value) {
    if (isFull()) {
      return false;
    }

    buffer[head--] = value;
    ++cnt;

    if (head < 0) {
      head = size - 1;
    }

    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is
   * successful. */
  bool insertLast(int value) {
    if (isFull()) {
      return false;
    }

    buffer[tail++] = value;
    ++cnt;

    if (tail == size) {
      tail = 0;
    }

    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is
   * successful. */
  bool deleteFront() {
    if (isEmpty()) {
      return false;
    }

    --cnt;
    ++head;

    if (head == size) {
      head = 0;
    }

    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is
   * successful. */
  bool deleteLast() {
    if (isEmpty()) {
      return false;
    }

    --cnt;
    --tail;

    if (tail < 0) {
      tail = size - 1;
    }

    return true;
  }

  /** Get the front item from the deque. */
  int getFront() {
    if (isEmpty()) {
      return -1;
    }

    return head + 1 == size ? buffer[0] : buffer[head + 1];
  }

  /** Get the last item from the deque. */
  int getRear() {
    if (isEmpty()) {
      return -1;
    }

    return tail - 1 < 0 ? buffer[size - 1] : buffer[tail - 1];
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty() {
    if (!cnt) {
      return true;
    }

    return false;
  }

  /** Checks whether the circular deque is full or not. */
  bool isFull() {
    if (cnt == size) {
      return true;
    }

    return false;
  }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// 36ms