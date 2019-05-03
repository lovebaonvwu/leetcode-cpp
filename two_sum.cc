class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    vector<int> ans{-1, -1};

    for (int i = 0; i < nums.size(); i++) {
      int val = target - nums[i];

      if (m.find(val) != m.end()) {
        ans[0] = i;
        ans[1] = m[val];
        return ans;
      }

      m[nums[i]] = i;
    }

    return ans;
  }
};  // 8ms

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
      m.insert(pair<int, int>(nums[i], i));
    }

    map<int, int>::iterator it;
    for (int i = 0; i < nums.size(); i++) {
      it = m.find(target - nums[i]);
      if (it != m.end() && it->second != i) {
        return vector<int>{i, it->second};
      }
    }

    return vector<int>{-1, -1};
  }
};  // 16ms

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
      m.insert(pair<int, int>(nums[i], i));
    }

    for (int i = 0; i < nums.size(); i++) {
      int val = target - nums[i];

      if (m.find(val) != m.end() && m[val] != i) {
        return vector<int>{i, m[val]};
      }
    }

    return vector<int>{-1, -1};
  }
};  // 12ms

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
      int val = target - nums[i];

      if (m.find(val) != m.end()) {
        return vector<int>{i, m[val]};
      }

      m[nums[i]] = i;
    }

    return vector<int>{-1, -1};
  }
};  // 20ms