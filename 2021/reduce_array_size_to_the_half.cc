class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> mp;

    for (auto n : arr) {
      ++mp[n];
    }

    vector<int> v;
    for (auto m : mp) {
      v.push_back(m.second);
    }

    sort(v.rbegin(), v.rend());

    int target = arr.size() >> 1;
    int ans = 0;

    for (auto n : v) {
      ++ans;
      target -= n;

      if (target <= 0) {
        break;
      }
    }

    return ans;
  }
};
// Runtime: 240 ms, faster than 100.00%
// Memory Usage: 38.6 MB, less than 100.00%