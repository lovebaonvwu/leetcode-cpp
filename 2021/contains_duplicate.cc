class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        return true;
      }
    }

    return false;
  }
};  // 32ms

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> map;

    for (int& n : nums) {
      if (map[n]) {
        return true;
      }
      map[n] = 1;
    }

    return false;
  }
};  // 40ms

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> st;

    for (int& n : nums) {
      if (st.count(n)) {
        return true;
      }
      st.insert(n);
    }

    return false;
  }
};  // 44ms

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> st;

    for (int& n : nums) {
      st.insert(n);
    }

    return st.size() != nums.size();
  }
};  // 48ms