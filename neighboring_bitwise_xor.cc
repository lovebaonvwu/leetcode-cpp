class Solution {
 public:
  bool doesValidArrayExist(vector<int>& derived) {
    int prev = 0;
    int n = derived.size();
    for (int i = 0; i < n; ++i) {
      prev = derived[i] ^ prev;
      if (i == n - 1 && prev == 0) {
        return true;
      }
    }

    prev = 1;
    for (int i = 0; i < n; ++i) {
      prev = derived[i] ^ prev;
      if (i == n - 1 && prev == 1) {
        return true;
      }
    }

    return false;
  }
};
// Runtime 342 ms
// Memory 259.5 MB