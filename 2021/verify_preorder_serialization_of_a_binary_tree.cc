class Solution {
 public:
  bool isValidSerialization(string preorder) {
    preorder += ',';

    vector<char> stk;

    for (int i = 0; i < preorder.size(); ++i) {
      if (preorder[i] != ',') {
        continue;
      }

      stk.push_back(preorder[i - 1]);

      while (stk.size() > 2 && stk[stk.size() - 1] == '#' &&
             stk[stk.size() - 2] == '#' && stk[stk.size() - 3] != '#') {
        stk.pop_back();
        stk.pop_back();
        stk.pop_back();
        stk.push_back('#');
      }
    }

    return stk.size() == 1 && stk[0] == '#';
  }
};
// Runtime: 6 ms, faster than 26.64%
// Memory Usage: 7 MB, less than 40.38%
// 2021.8.26 at 奥盛大厦