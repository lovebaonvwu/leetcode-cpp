class Solution {
 public:
  char findTheDifference(string s, string t) {
    string tmp = s + t;
    char ans = 0;

    for (char& c : tmp) {
      ans ^= c;
    }

    return ans;
  }
};