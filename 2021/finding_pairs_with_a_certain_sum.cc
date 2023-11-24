class FindSumPairs {
  unordered_map<int, int> cnt;
  vector<int> nums;

 public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums(nums2) {
    for (auto n : nums1) {
      ++cnt[n];
    }
  }

  void add(int index, int val) { nums[index] += val; }

  int count(int tot) {
    int ret = 0;

    for (auto n : nums) {
      if (cnt.find(tot - n) != cnt.end()) {
        ret += cnt[tot - n];
      }
    }

    return ret;
  }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
// Time Limit Exceeded

class FindSumPairs {
  unordered_map<int, int> mp;
  vector<int> n1, n2;

 public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) : n1(nums1), n2(nums2) {
    for (auto n : nums2) {
      ++mp[n];
    }
  }

  void add(int index, int val) {
    --mp[n2[index]];
    n2[index] += val;
    ++mp[n2[index]];
  }

  int count(int tot) {
    int ret = 0;

    for (auto n : n1) {
      if (mp.find(tot - n) != mp.end()) {
        ret += mp[tot - n];
      }
    }

    return ret;
  }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
// Runtime: 280 ms, faster than 92.14%
// Memory Usage: 73.6 MB, less than 92.06%