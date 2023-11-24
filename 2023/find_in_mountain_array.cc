/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
 public:
  int findInMountainArray(int target, MountainArray& mountainArr) {
    int n = mountainArr.length();
    int lo = 0, hi = n - 1;
    while (lo < hi) {
      int md = (lo + hi) / 2;
      if (mountainArr.get(md) > mountainArr.get(md + 1)) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }

    int peak = lo;
    lo = 0, hi = peak;
    while (lo < hi) {
      int md = (lo + hi + 1) / 2;
      if (mountainArr.get(md) > target) {
        hi = md - 1;
      } else {
        lo = md;
      }
    }

    if (mountainArr.get(lo) == target) {
      return lo;
    }

    lo = peak, hi = n - 1;
    while (lo < hi) {
      int md = (lo + hi) / 2;
      if (mountainArr.get(md) > target) {
        lo = md + 1;
      } else {
        hi = md;
      }
    }

    return mountainArr.get(lo) == target ? lo : -1;
  }
};
// 3ms
// 7.39MB