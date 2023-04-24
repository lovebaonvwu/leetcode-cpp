class Solution {
 public:
  vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    multiset<int> mt;
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      mt.insert(nums[i]);

      if (i + 1 < k) {
        continue;
      }

      if (i >= k) {
        mt.erase(mt.lower_bound(nums[i - k]));
      }

      auto it = mt.begin();
      std::advance(it, x - 1);

      ans.push_back(min(*it, 0));
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    multiset<int> mt;
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < 0) {
        mt.insert(nums[i]);
      }

      if (i >= k - 1) {
        if (mt.size() < x) {
          ans.push_back(0);
        } else {
          auto it = mt.begin();
          std::advance(it, x - 1);
          ans.push_back(*it);
        }

        if (mt.find(nums[i - k + 1]) != mt.end()) {
          mt.erase(mt.find(nums[i - k + 1]));
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    multiset<int> mt;
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < 0) {
        mt.insert(nums[i]);
      }

      if (i >= k - 1) {
        if (mt.size() < x) {
          ans.push_back(0);
        } else {
          auto it = mt.begin();
          std::advance(it, x - 1);
          ans.push_back(*it);
        }

        if (nums[i - k + 1] < 0) {
          mt.erase(mt.find(nums[i - k + 1]));
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    multiset<int> mt;
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < 0) {
        mt.insert(nums[i]);
      }

      if (i >= k - 1) {
        if (mt.size() < x) {
          ans.push_back(0);
        } else {
          ans.push_back(*next(mt.begin(), x - 1));
        }

        if (nums[i - k + 1] < 0) {
          mt.erase(mt.find(nums[i - k + 1]));
        }
      }
    }

    return ans;
  }
};
// Runtime 2903 ms
// Memory 237.3 MB