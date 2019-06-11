class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    string word = "";
    vector<string> words;
    unordered_map<char, string> mp;
    unordered_map<string, char> mp2;

    for (char& c : str) {
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

    if (words.size() != pattern.size()) {
      return false;
    }

    for (int i = 0; i < pattern.size(); ++i) {
      if (mp[pattern[i]] != "" && mp[pattern[i]] != words[i]) {
        return false;
      } else if (mp[pattern[i]] == "" && mp2[words[i]]) {
        return false;
      } else {
        mp[pattern[i]] = words[i];
        mp2[words[i]] = pattern[i];
      }
    }

    return true;
  }
};