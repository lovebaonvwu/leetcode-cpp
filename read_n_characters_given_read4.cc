/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
 public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char* buf, int n) {
    int offset = 0;
    while (offset < n) {
      int len = read4(buf + offset);
      offset += len;
      if (len < 4) {
        break;
      }
    }

    return min(offset, n);
  }
};
// Runtime 0 ms
// Memory 6.2 MB
// 2022.11.22 at 茗筑美嘉