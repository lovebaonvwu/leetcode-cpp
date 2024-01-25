class Solution {
 public:
  int minimumArrayLength(vector<int>& nums) {
    int min = *min_element(begin(nums), end(nums));

    int cnt = 0;
    for (auto n : nums) {
      if (n == min) {
        ++cnt;
      }

      if (n % min > 0) {
        return 1;
      }
    }

    return (cnt + 1) / 2;
  }
};
// 97ms
// 92.51MB