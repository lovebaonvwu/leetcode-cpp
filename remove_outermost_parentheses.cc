class Solution {
 public:
  string removeOuterParentheses(string S) {
    string s;
    string ans;
    int rp_cnt = -1;

    for (int i = S.size() - 1; i >= 0; --i) {
      if (S[i] == ')') {
        if (rp_cnt >= 0) {
          s = S[i] + s;
        }

        ++rp_cnt;
      } else {
        if (rp_cnt == 0) {
          ans = s + ans;
          s = "";
        } else {
          s = S[i] + s;
        }

        --rp_cnt;
      }
    }

    return ans;
  }
};  // 4ms

class Solution {
 public:
  string removeOuterParentheses(string S) {
    queue<char> s;
    string ans;
    int rp_cnt = -1;

    for (int i = S.size() - 1; i >= 0; --i) {
      if (S[i] == ')') {
        if (rp_cnt >= 0) {
          s.push(S[i]);
        }

        ++rp_cnt;
      } else {
        if (rp_cnt == 0) {
          while (!s.empty()) {
            ans = s.front() + ans;
            s.pop();
          }
        } else {
          s.push(S[i]);
        }

        --rp_cnt;
      }
    }

    return ans;
  }
};  // 16ms

class Solution {
 public:
  string removeOuterParentheses(string S) {
    queue<char> s;
    string ans;
    int rp_cnt = -1;

    for (int i = S.size() - 1; i >= 0; --i) {
      if (S[i] == ')' && rp_cnt < 0) {
        rp_cnt = 0;
      } else if (S[i] == ')') {
        s.push(S[i]);
        ++rp_cnt;
      } else if (S[i] == '(' && rp_cnt > 0) {
        s.push(S[i]);
        --rp_cnt;
      } else if (S[i] == '(') {
        rp_cnt = -1;

        while (!s.empty()) {
          ans = s.front() + ans;
          s.pop();
        }
      }
    }

    return ans;
  }
};  // 20ms