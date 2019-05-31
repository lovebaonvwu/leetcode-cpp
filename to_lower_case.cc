class Solution {
 public:
  string toLowerCase(string str) {
    for (char& c : str) {
      if (isupper(c)) {
        c += 32;
      }
    }

    return str;
  }
};  // 4ms