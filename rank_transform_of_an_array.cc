class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> tmp(arr);
    sort(tmp.begin(), tmp.end());

    unordered_map<int, int> mp;
    for (auto t : tmp) {
      mp.emplace(t, mp.size() + 1);
    }

    for (auto& a : arr) {
      a = mp[a];
    }

    return arr;
  }
};
// Runtime: 212 ms, faster than 86.23%
// Memory Usage: 27.8 MB, less than 100.00%

class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    unordered_map<int, vector<int>> mp;
    unordered_set<int> st(arr.begin(), arr.end());
    vector<int> v(st.begin(), st.end());
    sort(v.begin(), v.end());

    for (int i = 0; i < arr.size(); ++i) {
      if (mp.find(arr[i]) != mp.end()) {
        mp[arr[i]].push_back(i);
      } else {
        mp[arr[i]] = {i};
      }
    }

    for (int i = 0, rank = 1; i < v.size(); ++i, ++rank) {
      for (auto p : mp[v[i]]) {
        arr[p] = rank;
      }
    }

    return arr;
  }
};
// Runtime: 272 ms, faster than 58.53%
// Memory Usage: 39 MB, less than 100.00%

class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    unordered_map<int, vector<int>> mp;
    set<int> st;

    for (int i = 0; i < arr.size(); ++i) {
      if (mp.find(arr[i]) != mp.end()) {
        mp[arr[i]].push_back(i);
      } else {
        mp[arr[i]] = {i};
      }

      st.insert(arr[i]);
    }

    int rank = 1;
    for (auto it = st.begin(); it != st.end(); ++it, ++rank) {
      auto v = mp[*it];

      for (auto i : v) {
        arr[i] = rank;
      }
    }

    return arr;
  }
};
// Runtime: 328 ms, faster than 39.79%
// Memory Usage: 44.7 MB, less than 100.00%