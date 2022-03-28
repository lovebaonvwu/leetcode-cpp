class Solution {
 public:
  int minDeletion(vector<int>& nums) {
    vector<int> beauty;

    for (auto n : nums) {
      if ((beauty.size() % 2 == 0) || n != beauty.back()) {
        beauty.push_back(n);
      }
    }

    return (nums.size() - (beauty.size() - beauty.size() % 2));
  }
};
// Runtime: 289 ms, faster than 14.29%
// Memory Usage: 128.9 MB, less than 57.14%
// 2022.3.28 at 奥盛大厦