class Solution {
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> window(nums.begin(), nums.begin() + k);
    auto mid = next(window.begin(), k / 2);

    vector<double> ans;
    for (int i = k;; ++i) {
      if (k % 2 == 0) {
        ans.push_back((1.0 * (*mid) + *prev(mid)) / 2);
      } else {
        ans.push_back(1.0 * (*mid));
      }

      if (i == nums.size()) {
        break;
      }

      window.insert(nums[i]);
      if (nums[i] < *mid) {
        --mid;
      }

      if (nums[i - k] <= *mid) {
        ++mid;
      }

      window.erase(window.lower_bound(nums[i - k]));
    }

    return ans;
  }
};
// 100ms
// 38.13MB