class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    stack<char> s1;
    stack<char> s2;

    setupStack(s1, S);
    setupStack(s2, T);

    if (s1.size() != s2.size()) {
      return false;
    }

    while (!s1.empty()) {
      if (s1.top() != s2.top()) {
        return false;
      }

      s1.pop();
      s2.pop();
    }

    return true;
  }

  void setupStack(stack<char>& s, string str) {
    for (auto& c : str) {
      if (c == '#' && !s.empty()) {
        s.pop();
      } else if (c != '#') {
        s.push(c);
      }
    }
  }
};