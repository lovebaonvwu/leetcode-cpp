class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> pos, neg;

    for (auto n : nums) {
      if (n > 0) {
        pos.push_back(n);
      } else {
        neg.push_back(n);
      }
    }

    for (int i = 0; i < pos.size(); ++i) {
      nums[i * 2] = pos[i];
      nums[i * 2 + 1] = neg[i];
    }

    return nums;
  }
};
// Runtime: 196 ms, faster than 46.15%
// Memory Usage: 134.4 MB, less than 7.69%
// 2022.1.23 at 茗筑美嘉

class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(n);

    for (int i = 0, j = 1, k = 0; k < n; ++k) {
      if (nums[k] > 0) {
        ans[i] = nums[k];
        i += 2;
      } else {
        ans[j] = nums[k];
        j += 2;
      }
    }

    return ans;
  }
};
// Runtime: 184 ms, faster than 61.54%
// Memory Usage: 123.8 MB, less than 7.69%
// 2022.1.23 at 茗筑美嘉