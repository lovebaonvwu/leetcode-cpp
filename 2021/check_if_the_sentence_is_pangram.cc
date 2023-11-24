class Solution {
 public:
  bool checkIfPangram(string sentence) {
    bitset<26> b;

    for (auto c : sentence) {
      b[c - 'a'] = 1;
    }

    return b.to_string() == string(26, '1');
  }
};
// Runtime: 4 ms, faster than 69.98%
// Memory Usage: 6.5 MB, less than 55.46%

class Solution {
 public:
  bool checkIfPangram(string sentence) {
    bitset<26> b;

    for (auto c : sentence) {
      b[c - 'a'] = 1;
    }

    return b.all();
  }
};
// Runtime: 4 ms, faster than 69.98%
// Memory Usage: 6.3 MB, less than 83.14%