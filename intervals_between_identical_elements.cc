class Solution {
 public:
  vector<long long> getDistances(vector<int>& arr) {
    unordered_map<int, vector<int>> mp;

    int n = arr.size();
    for (int i = 0; i < n; ++i) {
      mp[arr[i]].push_back(i);
    }

    vector<long long> ans(n);

    for (int i = 0; i < n; ++i) {
      for (auto index : mp[arr[i]]) {
        ans[i] += abs(index - i);
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<long long> getDistances(vector<int>& arr) {
    unordered_map<int, vector<int>> mp;

    int n = arr.size();
    for (int i = 0; i < n; ++i) {
      mp[arr[i]].push_back(i);
    }

    vector<long long> ans(n);

    for (auto& [_, indexs] : mp) {
      for (int i = 1; i < indexs.size(); ++i) {
        ans[indexs[0]] += indexs[i] - indexs[0];
      }

      for (int i = 1; i < indexs.size(); ++i) {
        ans[indexs[i]] = ans[indexs[i - 1]] -
                         (indexs[i] - indexs[i - 1]) * (indexs.size() - i) +
                         (indexs[i] - indexs[i - 1]) * i;
      }
    }

    return ans;
  }
};
// Runtime: 324 ms, faster than 97.64%
// Memory Usage: 118.7 MB, less than 90.28%
// 2021.12.28 at 奥盛大厦