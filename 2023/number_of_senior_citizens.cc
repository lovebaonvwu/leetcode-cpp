class Solution {
 public:
  int countSeniors(vector<string>& details) {
    int ans = 0;
    for (auto& d : details) {
      int age = d[11] - '0';
      age = age * 10 + (d[12] - '0');

      ans += age > 60;
    }

    return ans;
  }
};
// Runtime 12 ms
// Memory 13.5 MB