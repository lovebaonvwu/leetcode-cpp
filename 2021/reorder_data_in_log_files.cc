class Solution {
 public:
  vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> digit_logs;
    vector<string> letter_logs;

    for (auto& log : logs) {
      if (isalpha(log.back())) {
        letter_logs.push_back(log);
      } else {
        digit_logs.push_back(log);
      }
    }

    sort(letter_logs.begin(), letter_logs.end(), [](auto& a, auto& b) {
      string word_a = a.substr(a.find(' ') + 1);
      string word_b = b.substr(b.find(' ') + 1);

      if (word_a == word_b) {
        string id_a = a.substr(0, a.find(' '));
        string id_b = b.substr(0, b.find(' '));

        return id_a < id_b;
      }

      return word_a < word_b;
    });

    letter_logs.insert(letter_logs.end(), digit_logs.begin(), digit_logs.end());

    return letter_logs;
  }
};
// Runtime: 8 ms, faster than 96.22%
// Memory Usage: 11.9 MB, less than 56.11%