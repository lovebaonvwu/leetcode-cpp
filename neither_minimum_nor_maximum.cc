class Solution {
 public:
  int findNonMinOrMax(vector<int>& nums) {
    int max_n = *max_element(nums.begin(), nums.end());
    int min_n = *min_element(nums.begin(), nums.end());

    for (auto n : nums) {
      if (n != max_n && n != min_n) {
        return n;
      }
    }

    return -1;
  }
};
// Runtime 130 ms
// Memory 91.7 MB