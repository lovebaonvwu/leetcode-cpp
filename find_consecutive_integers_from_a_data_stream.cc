class DataStream {
  int value;
  int k;
  int cnt;

 public:
  DataStream(int value, int k) : value(value), k(k), cnt(0) {}

  bool consec(int num) {
    cnt = num == value ? cnt + 1 : 0;

    return cnt >= k;
  }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
// Runtime 317 ms
// Memory 122.7 MB