class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    int ans = 0;
    for (int i = 0, sum = 0, cur = 0; i < arr.size(); ++i) {
      sum += arr[i];
      cur += i;

      if (sum == cur) {
        ++ans;
        sum = 0;
        cur = 0;
      }
    }

    return ans;
  }
};
// Runtime 2 ms
// Memory 7.2 MB