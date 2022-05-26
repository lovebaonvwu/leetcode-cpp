class Solution {
 public:
  int countPrimeSetBits(int left, int right) {
    int ans = 0;

    unordered_set<int> p{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    for (int i = left; i <= right; ++i) {
      int cnt = bitset<32>(i).count();

      ans += p.count(cnt) > 0;
    }

    return ans;
  }
};
// Runtime: 27 ms, faster than 42.40%
// Memory Usage: 6.2 MB, less than 9.34%
// 2022.5.26 at 奥盛大厦