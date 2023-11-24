static auto ___ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  return 0;
}();

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0;
    int max_cnt = 0;

    for (int& n : nums) {
      if (!n) {
        if (cnt > max_cnt) {
          max_cnt = cnt;
        }
        cnt = 0;
      } else {
        ++cnt;
      }
    }

    return max_cnt > cnt ? max_cnt : cnt;
  }
};  // 20ms

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0;
    int max_cnt = 0;

    for (int& n : nums) {
      if (!n) {
        if (cnt > max_cnt) {
          max_cnt = cnt;
        }
        cnt = 0;
      } else {
        ++cnt;
      }
    }

    return max_cnt > cnt ? max_cnt : cnt;
  }
};  // 48ms