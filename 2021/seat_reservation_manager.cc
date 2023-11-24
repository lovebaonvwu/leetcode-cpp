class SeatManager {
  priority_queue<int, vector<int>, greater<int>> pq;

 public:
  SeatManager(int n) {
    for (int i = 1; i <= n; ++i) {
      pq.push(i);
    }
  }

  int reserve() {
    int ret = pq.top();
    pq.pop();

    return ret;
  }

  void unreserve(int seatNumber) { pq.push(seatNumber); }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
// Runtime: 364 ms, faster than 80.04%
// Memory Usage: 147.7 MB, less than 57.48%