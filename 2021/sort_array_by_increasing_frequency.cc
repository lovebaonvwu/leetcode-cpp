class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> mp;

    for (auto n : nums) {
      ++mp[n];
    }

    vector<pair<int, int>> vct;

    for (auto& m : mp) {
      vct.push_back({m.second, m.first});
    }

    sort(vct.begin(), vct.end(), [](auto& a, auto& b) {
      if (a.first == b.first) {
        return a.second > b.second;
      } else {
        return a.first < b.first;
      }
    });

    vector<int> ans;

    for (auto& [cnt, n] : vct) {
      while (cnt-- > 0) {
        ans.push_back(n);
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 97.11%
// Memory Usage: 11.8 MB, less than 6.69%

class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> mp;

    for (auto n : nums) {
      ++mp[n];
    }

    sort(nums.begin(), nums.end(), [&mp](auto a, auto b) {
      if (mp[a] == mp[b]) {
        return a > b;
      } else {
        return mp[a] < mp[b];
      }
    });

    return nums;
  }
};
// Runtime: 24 ms, faster than 29.01%
// Memory Usage: 11.5 MB, less than 6.69%