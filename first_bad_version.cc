// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    long i = 1;
    long v = n;

    while (i <= v) {
      long tmp = (i + v) >> 1;

      if (isBadVersion(tmp)) {
        v = tmp - 1;
        if (!isBadVersion(v)) {
          return tmp;
        }
      } else if (!isBadVersion(tmp)) {
        i = tmp + 1;
        if (isBadVersion(i)) {
          return i;
        }
      }
    }

    return -1;
  }
};