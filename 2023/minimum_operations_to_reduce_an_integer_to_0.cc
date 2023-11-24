class Solution {
 public:
  int minOperations(int n) {
    int ans = 0;

    bitset<32> bits(n);
    for (int i = 0, cnt = 0; i < 32 && bits.any(); ++i) {
      if (bits.test(i)) {
        ++cnt;
      } else if (cnt > 0) {
        if (cnt > 1 && bits.test(i + 1)) {
          ans += 1;
          cnt = 1;
        } else {
          ans += cnt == 1 ? 1 : 2;
          cnt = 0;
        }
      }
    }

    return ans;
  }
};
// Runtime 0 ms
// Memory 6 MB
// 2023.2.28 at 奥盛大厦