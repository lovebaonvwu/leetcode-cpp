class Solution {
 public:
  vector<int> distinctNumbers(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      ++cnt[nums[i]];
      if (i >= k) {
        --cnt[nums[i - k]];
        if (cnt[nums[i - k]] == 0) {
          cnt.erase(nums[i - k]);
        }
      }

      if (i >= k - 1) {
        ans.push_back(cnt.size());
      }
    }

    return ans;
  }
};
// Runtime 413 ms
// Memory 140.4 MB
// 2023.1.30 at 奥盛大厦

class Solution {
 public:
  vector<int> distinctNumbers(vector<int>& nums, int k) {
    int cnt[100001] = {0};
    int cur = 0;
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      cur += ++cnt[nums[i]] == 1;
      if (i >= k) {
        cur -= --cnt[nums[i - k]] == 0;
      }

      if (i >= k - 1) {
        ans.push_back(cur);
      }
    }

    return ans;
  }
};
// Runtime 227 ms
// Memory 102.8 MB
// 2023.1.30 at 奥盛大厦