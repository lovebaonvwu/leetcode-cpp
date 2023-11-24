class Solution {
 public:
  bool threeConsecutiveOdds(vector<int>& arr) {
    for (int i = 0, cnt = 0; i < arr.size(); ++i) {
      cnt = arr[i] & 1 ? cnt + 1 : 0;

      if (cnt == 3) {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 8 ms, faster than 74.97%
// Memory Usage: 8.3 MB, less than 88.60%

class Solution {
 public:
  bool threeConsecutiveOdds(vector<int>& arr) {
    int odd = 0;

    for (int i = 0; i < arr.size() && odd < 3; ++i) {
      odd = arr[i] & 1 ? odd + 1 : 0;
    }

    return odd == 3;
  }
};
// Runtime: 8 ms, faster than 74.97%
// Memory Usage: 8.3 MB, less than 83.59%