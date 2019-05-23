class MyCircularQueue {
 private:
  int head = 0;
  int tail = 0;
  int cnt = 0;
  int max = 0;
  vector<int> queue;

 public:
  /** Initialize your data structure here. Set the size of the queue to be k. */
  MyCircularQueue(int k) {
    max = k;
    queue = vector<int>(k);
  }

  /** Insert an element into the circular queue. Return true if the operation is
   * successful. */
  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }

    queue[tail++] = value;
    tail = tail < max ? tail : tail % max;
    ++cnt;

    return true;
  }

  /** Delete an element from the circular queue. Return true if the operation is
   * successful. */
  bool deQueue() {
    if (isEmpty()) {
      return false;
    }

    ++head;
    head = head < max ? head : head % max;
    --cnt;

    return true;
  }

  /** Get the front item from the queue. */
  int Front() {
    if (isEmpty()) {
      return -1;
    }

    return queue[head];
  }

  /** Get the last item from the queue. */
  int Rear() {
    if (isEmpty()) {
      return -1;
    }

    return tail == 0 ? queue[max - 1] : queue[tail - 1];
  }

  /** Checks whether the circular queue is empty or not. */
  bool isEmpty() { return cnt == 0; }

  /** Checks whether the circular queue is full or not. */
  bool isFull() { return cnt == max; }
};  // 48ms

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */