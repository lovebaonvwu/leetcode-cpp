class Solution {
 public:
  int bitwiseComplement(int N) {
    if (!N) {
      return 1;
    }

    vector<int> bits;

    while (N > 0) {
      bits.push_back(!(N % 2));
      N >>= 1;
    }

    reverse(bits.begin(), bits.end());

    int i = 0;
    while (i < bits.size() && bits[i] == 0) {
      ++i;
    }

    int ans = 0;
    for (; i < bits.size(); ++i) {
      ans <<= 1;
      ans |= bits[i];
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 100.00%

class Solution {
 public:
  int bitwiseComplement(int N) {
    int x = 1;
    while (x < N) {
      x = (x << 1) | 1;
    }

    return x ^ N;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.8 MB, less than 100.00%