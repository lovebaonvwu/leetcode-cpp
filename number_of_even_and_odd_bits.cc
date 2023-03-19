class Solution {
 public:
  vector<int> evenOddBit(int n) {
    vector<int> ans(2);

    bitset<32> bits(n);

    for (int i = 0; i < 32; ++i) {
      if (bits[i] == 1) {
        ans[i % 2] += 1;
      }
    }

    return ans;
  }
};
// Runtime 4 ms
// Memory 7.1 MB

class Solution {
 public:
  vector<int> evenOddBit(int n) {
    vector<int> ans(2);

    int i = 0;
    while (n > 0) {
      ans[i % 2] += n & 1;
      n >>= 1;
      ++i;
    }

    return ans;
  }
};
// Runtime 4 ms
// Memory 7.1 MB