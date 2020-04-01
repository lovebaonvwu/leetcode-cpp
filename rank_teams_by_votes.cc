class Solution {
 public:
  string rankTeams(vector<string>& votes) {
    vector<string> cnt(26);

    for (auto& s : votes) {
      for (int i = 0; i < s.size(); ++i) {
        cnt[s[i] - 'A'] += i + 'a';
      }
    }

    vector<pair<string, int>> vp;
    for (int i = 0; i < cnt.size(); ++i) {
      if (!cnt[i].empty()) {
        sort(cnt[i].begin(), cnt[i].end());
        vp.push_back({cnt[i], i});
      }
    }

    sort(vp.begin(), vp.end(), [](auto a, auto b) {
      if (a.first == b.first) {
        return a.second < b.second;
      } else {
        return a.first < b.first;
      }
    });

    string ans;

    for (auto p : vp) {
      if (!p.first.empty()) {
        ans.append(1, p.second + 'A');
      }
    }

    return ans;
  }
};
// Runtime: 68 ms, faster than 5.22%
// Memory Usage: 13.8 MB, less than 100.00%

class Solution {
 public:
  string rankTeams(vector<string>& votes) {
    vector<vector<int>> cnt(26, vector<int>(27));

    for (char ch : votes[0]) {
      cnt[ch - 'A'][26] = ch;
    }

    for (auto& s : votes) {
      for (int i = 0; i < s.size(); ++i) {
        --cnt[s[i] - 'A'][i];
      }
    }

    sort(cnt.begin(), cnt.end());

    string ans;

    for (int i = 0; i < votes[0].size(); ++i) {
      ans += cnt[i][26];
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 76.29%
// Memory Usage: 8.7 MB, less than 100.00%