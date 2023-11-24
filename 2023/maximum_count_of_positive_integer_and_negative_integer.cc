class Solution {
 public:
  int maximumCount(vector<int>& nums) {
    int pos = 0, neg = 0;
    for (auto n : nums) {
      pos += n > 0;
      neg += n < 0;
    }

    return max(pos, neg);
  }
};
// Runtime 20 ms
// Memory 17.6 MB

class Solution {
 public:
  int maximumCount(vector<int>& nums) {
    int pos = 0, neg = 0;
    for (auto n : nums) {
      if (n > 0) {
        ++pos;
      } else if (n < 0) {
        ++neg;
      }
    }

    return max(pos, neg);
  }
};
// Runtime 16 ms
// Memory 17.8 MB