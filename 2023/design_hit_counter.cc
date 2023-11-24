class HitCounter {
  deque<int> q;

 public:
  HitCounter() {}

  void hit(int timestamp) {
    q.push_back(timestamp);

    while (!q.empty()) {
      int head = q.front();
      int back = q.back();

      if (back - head <= 300) {
        break;
      }

      q.pop_front();
    }
  }

  int getHits(int timestamp) {
    while (!q.empty()) {
      int head = q.front();

      if (timestamp - head < 300) {
        break;
      }

      q.pop_front();
    }

    return q.size();
  }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
// Runtime 0 ms
// Memory 7.3 MB
// 2023.1.20 at 奥盛大厦