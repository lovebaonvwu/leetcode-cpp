class Solution {
 public:
  int addMinimum(string word) {
    int ans = 0;
    stack<char> stk;

    for (int i = 0; i < word.size(); ++i) {
      if (word[i] == 'a') {
        if (!stk.empty()) {
          ans += 3 - stk.size();
        }

        while (!stk.empty()) {
          stk.pop();
        }

        stk.push(word[i]);
      } else if (word[i] == 'b') {
        if (!stk.empty() && stk.top() == 'b') {
          ++ans;
          stk.pop();
          stk.pop();
        }

        if (stk.empty()) {
          ++ans;
          stk.push('a');
        }

        stk.push(word[i]);
      } else {
        if (stk.empty()) {
          ans += 2;
        } else if (stk.size() == 1) {
          ++ans;
        }

        while (!stk.empty()) {
          stk.pop();
        }
      }
    }

    if (word.back() == 'a') {
      ans += 2;
    } else if (word.back() == 'b') {
      ++ans;
    }

    return ans;
  }
};
// Runtime 5 ms
// Memory 7.4 MB

class Solution {
 public:
  int addMinimum(string word) {
    char prev = 'z', cnt = 0;

    for (auto c : word) {
      if (c <= prev) {
        ++cnt;
      }

      prev = c;
    }

    return cnt * 3 - word.size();
  }
};
// Runtime 0 ms
// Memory 6.3 MB