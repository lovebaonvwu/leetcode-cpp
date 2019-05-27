class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    unordered_map<int, int>::iterator it;

    for (int i = 0; i < nums.size(); ++i) {
      it = mp.find(nums[i]);
      if (it == mp.end()) {
        mp[nums[i]] = i;
      } else {
        if (i - mp[nums[i]] <= k) {
          return true;
        } else {
          mp[nums[i]] = i;
        }
      }
    }

    return false;
  }
};  // 32ms

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); ++i) {
      if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k) {
        return true;
      } else {
        mp[nums[i]] = i;
      }
    }

    return false;
  }
};  // 36ms