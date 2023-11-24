/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
 public:
  int search(const ArrayReader& reader, int target) {
    int lo = 0, hi = 10000;

    while (lo <= hi) {
      int md = (lo + hi) / 2;
      int val = reader.get(md);
      if (val > 10000) {
        hi = md - 1;
      } else if (val > target) {
        hi = md - 1;
      } else if (val < target) {
        lo = md + 1;
      } else {
        return md;
      }
    }

    return -1;
  }
};
// Runtime 24 ms
// Memory 10.1 MB
// 2023.1.30 at 奥盛大厦