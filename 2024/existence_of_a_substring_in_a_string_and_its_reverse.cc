class Solution {
 public:
  bool isSubstringPresent(string s) {
    string t = s;
    reverse(begin(t), end(t));

    for (int i = 0; i < s.size() - 1; ++i) {
      if (t.find(s.substr(i, 2)) != string::npos) {
        return true;
      }
    }

    return false;
  }
};
// 0 ms
// 8.04 MB