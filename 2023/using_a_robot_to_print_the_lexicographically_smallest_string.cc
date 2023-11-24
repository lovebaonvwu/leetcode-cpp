class Solution {
  char minchar(int* cnt) {
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] > 0) {
        return (i + 'a');
      }
    }

    return 'a';
  }

 public:
  string robotWithString(string s) {
    int cnt[26] = {0};
    for (auto c : s) {
      ++cnt[c - 'a'];
    }

    string ans;
    stack<char> stk;
    for (auto c : s) {
      stk.push(c);
      --cnt[c - 'a'];

      while (!stk.empty() && stk.top() <= minchar(cnt)) {
        ans += stk.top();
        stk.pop();
      }
    }

    while (!stk.empty()) {
      char c = stk.top();
      stk.pop();
      ans += c;
    }

    return ans;
  }
};
// Runtime 163 ms
// Memory 29.7 MB