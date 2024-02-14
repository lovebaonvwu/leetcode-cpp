class Solution {
 public:
  string kthLuckyNumber(int k) {
    string ans;
    ++k;
    for (; k != 1; k /= 2) {
      ans.push_back(k & 1 ? '7' : '4');
    }

    reverse(begin(ans), end(ans));

    return ans;
  }
};
// 15 ms
// 10.01 MB