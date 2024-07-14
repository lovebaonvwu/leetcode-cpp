class Solution {
 public:
  string countOfAtoms(string formula) {
    function<unordered_map<string, int>(const string&)> dfs =
        [&](const string& s) -> unordered_map<string, int> {
      int n = s.size();
      unordered_map<string, int> mp;

      string ele;
      int cnt = 0;

      for (int i = 0; i < n; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
          if (i > 0) {
            mp[ele] += cnt == 0 ? 1 : cnt;
            ele.clear();
            cnt = 0;
          }

          ele += s[i];
        } else if (s[i] >= 'a' && s[i] <= 'z') {
          ele += s[i];
        } else if (s[i] >= '0' && s[i] <= '9') {
          cnt = cnt * 10 + (s[i] - '0');
        } else if (s[i] == '(') {
          if (i > 0) {
            mp[ele] += cnt == 0 ? 1 : cnt;
            ele.clear();
            cnt = 0;
          }

          string t;
          int j = i + 1;
          int pcnt = 1;
          while (j < n && pcnt > 0) {
            if (s[j] == '(') {
              ++pcnt;
            } else if (s[j] == ')') {
              --pcnt;
            }

            t += s[j++];
          }

          unordered_map<string, int> submp = dfs(t.substr(0, t.size() - 1));
          int mul = 0;
          while (j < n && isdigit(s[j])) {
            mul = mul * 10 + (s[j++] - '0');
          }

          i = j - 1;

          for (auto [subele, subcnt] : submp) {
            mp[subele] += (subcnt == 0 ? 1 : subcnt) * (mul == 0 ? 1 : mul);
          }
        }
      }

      mp[ele] += cnt == 0 ? 1 : cnt;

      return mp;
    };

    unordered_map<string, int> mp = dfs(formula);
    vector<pair<string, int>> tmp;
    for (auto [ele, cnt] : mp) {
      tmp.push_back({ele, cnt});
    }

    sort(begin(tmp), end(tmp));
    string ans;
    for (auto [ele, cnt] : tmp) {
      if (ele.empty())
        continue;
      ans += ele;
      if (cnt > 1) {
        ans += to_string(cnt);
      }
    }

    return ans;
  }
};
// 0 ms
// 10.01 MB
