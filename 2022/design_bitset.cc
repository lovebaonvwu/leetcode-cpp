class Bitset {
  string bitset;
  string fliped;
  int cnt;

 public:
  Bitset(int size) {
    bitset.resize(size, '0');
    fliped.resize(size, '1');
    cnt = 0;
  }

  void fix(int idx) {
    cnt += bitset[idx] == '0';
    bitset[idx] = '1';
    fliped[idx] = '0';
  }

  void unfix(int idx) {
    cnt -= bitset[idx] == '1';
    bitset[idx] = '0';
    fliped[idx] = '1';
  }

  void flip() {
    swap(bitset, fliped);
    cnt = bitset.size() - cnt;
  }

  bool all() { return cnt == bitset.size(); }

  bool one() { return cnt > 0; }

  int count() { return cnt; }

  string toString() { return bitset; }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
// Runtime: 789 ms, faster than 31.91%
// Memory Usage: 195.8 MB, less than 88.22%
// 2022.2.9 at 奥盛大厦