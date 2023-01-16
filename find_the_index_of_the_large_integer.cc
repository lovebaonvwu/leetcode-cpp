/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y]
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
 public:
  int getIndex(ArrayReader& reader) {
    int n = reader.length();

    int l = 0, r = n / 2 - 1, x = r + 1 + n % 2, y = n - 1;

    while (l < y) {
      int result = reader.compareSub(l, r, x, y);
      if (result > 0) {
        int n = r - l + 1;
        y = r;
        r = l + n / 2 - 1;
        x = r + 1 + n % 2;
      } else if (result < 0) {
        int n = y - x + 1;
        l = x;
        r = l + n / 2 - 1;
        x = r + 1 + n % 2;
      } else {
        return r + 1;
      }
    }

    return l;
  }
};
// Runtime 165 ms
// Memory 39.5 MB
// 2023.1.16 at 奥盛大厦