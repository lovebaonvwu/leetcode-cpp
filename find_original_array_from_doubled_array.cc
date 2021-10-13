class Solution {
 public:
  vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();

    if (n & 1) {
      return {};
    }

    vector<int> ans;
    map<int, int> mp;

    for (auto num : changed) {
      if (num & 1) {
        ans.push_back(num);
      } else {
        ++mp[num];
      }
    }

    for (auto num : ans) {
      int target = num * 2;

      if (mp.find(target) == mp.end() || mp[target] <= 0) {
        return {};
      }

      --mp[target];
    }

    for (auto [k, v] : mp) {
      if (v == 0) {
        continue;
      }

      if (k == 0 && (v & 1)) {
        return {};
      } else if (k == 0) {
        for (int i = 0; i < v / 2; ++i) {
          ans.push_back(0);
        }

        mp[0] = 0;

        continue;
      }

      int target = k * 2;

      if (mp.find(target) == mp.end() || mp[target] < v) {
        return {};
      }

      for (int i = 0; i < v; ++i) {
        ans.push_back(k);
      }

      mp[k] -= v;
      mp[target] -= v;
    }

    return ans;
  }
};
// Runtime: 438 ms, faster than 57.35%
// Memory Usage: 136.1 MB, less than 87.41%
// 2021.10.13 at 奥盛大厦

class Solution {
 public:
  vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();

    if (n & 1) {
      return {};
    }

    vector<int> ans;
    map<int, int> mp;

    for (auto num : changed) {
      if (num & 1) {
        ans.push_back(num);
      } else {
        ++mp[num];
      }
    }

    for (auto num : ans) {
      int target = num * 2;

      if (mp.find(target) == mp.end() || mp[target] <= 0) {
        return {};
      }

      --mp[target];
    }

    if (mp[0] > 0 && (mp[0] & 1)) {
      return {};
    }

    for (int i = 0; i < mp[0] / 2; ++i) {
      ans.push_back(0);
    }

    mp[0] = 0;

    for (auto [k, v] : mp) {
      if (v == 0) {
        continue;
      }

      int target = k * 2;

      if (mp.find(target) == mp.end() || mp[target] < v) {
        return {};
      }

      for (int i = 0; i < v; ++i) {
        ans.push_back(k);
      }

      mp[k] -= v;
      mp[target] -= v;
    }

    return ans;
  }
};
// Runtime: 704 ms, faster than 21.35%
// Memory Usage: 136.3 MB, less than 87.03%
// 2021.10.13 at 奥盛大厦

class Solution {
 public:
  vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();

    if (n & 1) {
      return {};
    }

    map<int, int> mp;

    for (auto c : changed) {
      ++mp[c];
    }

    if (mp[0] > 0 && (mp[0] & 1)) {
      return {};
    }

    vector<int> ans;

    for (int i = 0; i < mp[0] / 2; ++i) {
      ans.push_back(0);
    }

    mp[0] = 0;

    for (auto [k, v] : mp) {
      if (v == 0) {
        continue;
      }

      int target = k * 2;

      if (mp.find(target) == mp.end() || mp[target] < v) {
        return {};
      }

      for (int i = 0; i < v; ++i) {
        ans.push_back(k);
      }

      mp[k] -= v;
      mp[target] -= v;
    }

    return ans;
  }
};
// Runtime: 593 ms, faster than 34.99%
// Memory Usage: 144.1 MB, less than 55.67%
// 2021.10.13 at 奥盛大厦