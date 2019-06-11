class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    int arr[256]{0};
    int cnt = 0;

    for (char& c : J) {
      arr[c] = 1;
    }

    for (char& c : S) {
      if (arr[c]) {
        ++cnt;
      }
    }

    return cnt;
  }
};