/**
 * Definition for BigArray.
 * class BigArray {
 * public:
 *     BigArray(vector<int> elements);
 *     int at(long long index);
 *     long long size();
 * };
 */
class Solution {
 public:
  int countBlocks(BigArray* nums) {
    long long l = 0;
    long long r = nums->size();
    int ans = 0;

    while (l < r) {
      long long curl = l;
      long long curr = r;
      long long target = nums->at(curl);
      while (curl < curr) {
        long long mid = curl + (curr - curl) / 2;
        if (nums->at(mid) == target)
          curl = mid + 1;
        else
          curr = mid;
      }

      ++ans;
      l = curr;
    }

    return ans;
  }
};
// 441 ms
// 95.64 MB