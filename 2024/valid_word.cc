class Solution {
 public:
  bool isValid(string word) {
    if (word.size() < 3)
      return false;

    unordered_set<char> vowels(
        {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
    bool vowel = false;
    bool constant = false;
    for (auto c : word) {
      if (!isdigit(c) && !isalpha(c))
        return false;
      if (vowels.find(c) != vowels.end())
        vowel = true;
      else if (isalpha(c))
        constant = true;
    }

    cout << vowel << " " << constant << endl;

    return vowel && constant;
  }
};
// 3 ms
// 8.64 MB