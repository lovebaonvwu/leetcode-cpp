class Solution {
 public:
  vector<string> expand(string s) {
    vector<string> ans{""};
    stack<char> stk;

    for (int i = 0; i < s.size();) {
      vector<string> tmp;
      if (s[i] == '{') {
        int j = i + 1;
        while (s[j] != '}') {
          if (s[j] == ',') {
            ++j;
            continue;
          }

          stk.push(s[j]);
          ++j;
        }

        i = j + 1;
      } else {
        stk.push(s[i]);
        ++i;
      }

      while (!stk.empty()) {
        char c = stk.top();
        stk.pop();

        for (auto s : ans) {
          tmp.push_back(s + c);
        }
      }

      swap(tmp, ans);
    }

    sort(ans.begin(), ans.end());

    return ans;
  }
};
// Runtime 5 ms
// Memory 8.2 MB
// 2023.1.30 at 奥盛大厦