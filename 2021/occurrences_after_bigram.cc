class Solution {
 public:
  vector<string> findOcurrences(string text, string first, string second) {
    string word = "";

    vector<string> words, ans;

    for (auto& c : text) {
      if (c == ' ' && word != "") {
        words.push_back(word);
        word = "";
      } else {
        word += c;
      }
    }

    if (word != "") {
      words.push_back(word);
    }

    for (int i = 0; i < words.size() - 2; ++i) {
      if (words[i] == first && words[i + 1] == second) {
        ans.push_back(words[i + 2]);
      }
    }

    return ans;
  }
};