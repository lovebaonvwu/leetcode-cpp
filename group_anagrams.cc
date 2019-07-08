class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;

    for (auto& str : strs) {
      auto key = str;
      sort(key.begin(), key.end());

      mp[key].push_back(str);
    }

    for (auto& v : mp) {
      ans.push_back(v.second);
    }

    return ans;
  }
};  // 40ms

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, int> mp;
    vector<vector<string>> ans;

    for (auto& str : strs) {
      int arr[26];
      memset(arr, 0, sizeof arr);

      for (auto& s : str) {
        ++arr[s - 'a'];
      }

      string key = "";

      for (auto& a : arr) {
        key += to_string(a);
      }

      auto item = mp.find(key);
      if (item != mp.end()) {
        ans[item->second].push_back(str);
      } else {
        vector<string> vec;
        vec.push_back(str);

        ans.push_back(vec);

        mp[key] = ans.size() - 1;
      }
    }

    return ans;
  }
};  // 96ms