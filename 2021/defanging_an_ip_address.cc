class Solution {
 public:
  string defangIPaddr(string address) {
    string ans = "";

    for (auto& s : address) {
      if (s == '.') {
        ans += "[.]";
      } else {
        ans += s;
      }
    }

    return ans;
  }
};  // 4ms