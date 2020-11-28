class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;

    map<int, int> mp;

    int i = 0;
    for (; i < k; ++i) {
      ++mp[nums[i]];
    }

    auto it = mp.rbegin();
    ans.push_back(it->first);

    for (; i < nums.size(); ++i) {
      ++mp[nums[i]];

      --mp[nums[i - k]];
      if (mp[nums[i - k]] == 0) {
        mp.erase(nums[i - k]);
      }

      it = mp.rbegin();
      ans.push_back(it->first);
    }

    return ans;
  }
};
// Runtime: 1184 ms, faster than 5.10%
// Memory Usage: 144.4 MB, less than 13.65%

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;

    deque<int> dq;

    for (int i = 0, n = nums.size(); i < n; ++i) {
      if (dq.front() == i - k) {
        dq.pop_front();
      }

      while (!dq.empty() && nums[dq.back()] < nums[i]) {
        dq.pop_back();
      }

      dq.push_back(i);

      if (i >= k - 1) {
        ans.push_back(nums[dq.front()]);
      }
    }

    return ans;
  }
};
// Runtime: 464 ms, faster than 28.71%
// Memory Usage: 107.2 MB, less than 43.83%

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> left(n);
    vector<int> right(n);

    left[0] = nums[0];
    right[n - 1] = nums[n - 1];

    for (int i = 1, j = n - 1 - i; i < n; ++i, j = n - 1 - i) {
      if (i % k == 0) {
        left[i] = nums[i];
      } else {
        left[i] = max(left[i - 1], nums[i]);
      }

      if (j % k == k - 1) {
        right[j] = nums[j];
      } else {
        right[j] = max(right[j + 1], nums[j]);
      }
    }

    vector<int> ans;

    for (int i = 0, j = i + k - 1; j < n; ++i, ++j) {
      ans.push_back(max(left[j], right[i]));
    }

    return ans;
  }
};
// Runtime: 308 ms, faster than 98.82%
// Memory Usage: 112.4 MB, less than 26.12%