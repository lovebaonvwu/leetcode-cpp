class Solution {
 public:
  vector<string> shortestSubstrings(vector<string>& arr) {
    int n = arr.size();
    function<vector<string>(const string&)> buildSubstrings =
        [](const string& s) -> vector<string> {
      vector<string> substrings;
      int n = s.size();
      for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
          substrings.push_back(s.substr(i, j - i + 1));
        }
      }

      sort(begin(substrings), end(substrings), [](auto a, auto b) {
        return a.size() < b.size() || (a.size() == b.size() && a < b);
      });

      return substrings;
    };

    vector<string> ans(n);
    for (int i = 0; i < n; ++i) {
      auto subs = buildSubstrings(arr[i]);

      for (auto sub : subs) {
        bool unique = true;
        for (int j = 0; j < n; ++j) {
          if (i == j)
            continue;
          if (arr[j].find(sub) != string::npos) {
            unique = false;
            break;
          }
        }

        if (unique) {
          ans[i] = sub;
          break;
        }
      }
    }

    return ans;
  }
};
// 402 ms
// 91.05 MB