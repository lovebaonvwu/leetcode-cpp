class Solution {
 public:
  vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string, int> mp;

    vector<string> ans;
    for (auto& name : names) {
      if (mp.find(name) != mp.end()) {
        int cnt = mp[name] + 1;

        string newName = name + "(" + to_string(cnt) + ")";

        while (mp.find(newName) != mp.end()) {
          ++cnt;
          newName = name + "(" + to_string(cnt) + ")";
        }

        ans.push_back(newName);

        mp[newName] = 0;
      } else {
        ans.push_back(name);
        mp[name] = 0;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string, int> mp;

    vector<string> ans;
    for (auto& name : names) {
      if (mp.find(name) != mp.end()) {
        ++mp[name];

        int cnt = mp[name];

        string newName = name + "(" + to_string(cnt) + ")";

        while (mp.find(newName) != mp.end()) {
          ++cnt;
          newName = name + "(" + to_string(cnt) + ")";
        }

        ans.push_back(newName);

        mp[newName] = 0;
      } else {
        ans.push_back(name);
        mp[name] = 0;
      }
    }

    return ans;
  }
};
// Runtime: 688 ms, faster than 31.82%
// Memory Usage: 66 MB, less than 100.00%

class Solution {
 public:
  vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string, int> mp;

    for (int i = 0; i < names.size(); ++i) {
      if (mp.count(names[i])) {
        int cnt = mp[names[i]];

        string tmp = names[i] + "(" + to_string(cnt++) + ")";
        while (mp.count(tmp)) {
          tmp = names[i] + "(" + to_string(cnt++) + ")";
        }

        mp[names[i]] = cnt;
        names[i] = tmp;
      }
      mp[names[i]]++;
    }

    return names;
  }
};
// Runtime: 384 ms, faster than 76.58%
// Memory Usage: 58.8 MB, less than 100.00%

class Solution {
 public:
  vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string, int> mp;

    vector<string> ans;

    for (auto& name : names) {
      if (mp.find(name) != mp.end()) {
        int cnt = mp[name];

        string newName = name + "(" + to_string(cnt++) + ")";

        while (mp.find(newName) != mp.end()) {
          newName = name + "(" + to_string(cnt++) + ")";
        }

        mp[name] = cnt;

        ans.push_back(newName);

        mp[newName]++;
      } else {
        ans.push_back(name);
        mp[name]++;
      }
    }

    return ans;
  }
};
// Runtime: 328 ms, faster than 92.16%
// Memory Usage: 66 MB, less than 100.00%