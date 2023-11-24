class Solution {
 public:
  string findReplaceString(string S,
                           vector<int>& indexes,
                           vector<string>& sources,
                           vector<string>& targets) {
    vector<pair<int, int>> sorted;

    for (int i = 0; i < indexes.size(); ++i) {
      sorted.push_back({indexes[i], i});
    }

    sort(sorted.rbegin(), sorted.rend());

    for (auto& [pos, idx] : sorted) {
      if (!S.compare(pos, sources[idx].size(), sources[idx])) {
        S.replace(pos, sources[idx].size(), targets[idx]);
      }
    }

    return S;
  }
};
// Runtime: 8 ms, faster than 44.39%
// Memory Usage: 10.4 MB, less than 22.22%

class Solution {
 public:
  string findReplaceString(string S,
                           vector<int>& indexes,
                           vector<string>& sources,
                           vector<string>& targets) {
    unordered_map<int, pair<int, string>> mp;

    for (int i = 0; i < indexes.size(); ++i) {
      if (!S.compare(indexes[i], sources[i].size(), sources[i])) {
        mp[indexes[i]] = {sources[i].size(), targets[i]};
      }
    }

    string ans;
    for (int i = 0; i < S.size();) {
      if (mp.find(i) != mp.end()) {
        ans += mp[i].second;
        i += mp[i].first;
      } else {
        ans += S[i++];
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 44.39%
// Memory Usage: 10.7 MB, less than 22.22%