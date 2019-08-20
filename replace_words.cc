class Solution {
 public:
  string replaceWords(vector<string>& dict, string sentence) {
    unordered_map<string, int> mp;

    for (auto& word : dict) {
      mp[word] = 1;
    }

    int size = sentence.size();

    string word = "";
    string ans = "";

    for (int i = 0; i < size; ++i) {
      if (sentence[i] == ' ') {
        if (word.size() > 0) {
          ans += word + ' ';
          word = "";
        }

      } else {
        word += sentence[i];
        if (mp[word]) {
          ans += word + ' ';
          word = "";

          while (i + 1 < size && sentence[i + 1] != ' ') {
            ++i;
          }
        }
      }
    }

    if (word.size() > 0) {
      ans += word + ' ';
    }

    if (ans.empty()) {
      return "";
    } else {
      return string(ans.begin(), ans.end() - 1);
    }
  }
};  // 580ms

class Solution {
 public:
  string replaceWords(vector<string>& dict, string sentence) {
    unordered_map<string, int> mp;

    for (auto& word : dict) {
      mp[word] = 1;
    }

    string word = "";
    string ans = "";

    bool skip = false;

    for (int i = 0; i < sentence.size(); ++i) {
      if (sentence[i] == ' ') {
        if (word.size() > 0) {
          ans += word + ' ';
        }

        word = "";
        skip = false;
        continue;
      }

      if (skip) {
        continue;
      }

      word += sentence[i];
      if (mp[word]) {
        ans += word + ' ';

        word = "";
        skip = true;
      }
    }

    if (word.size() > 0) {
      ans += word + ' ';
    }

    if (ans.empty()) {
      return "";
    } else {
      return string(ans.begin(), ans.end() - 1);
    }
  }
};  // 588ms

class Solution {
 public:
  string replaceWords(vector<string>& dict, string sentence) {
    unordered_map<string, int> mp;

    for (auto& word : dict) {
      mp[word] = 1;
    }

    string word = "";
    string ans = "";

    bool skip = false;

    for (int i = 0; i < sentence.size(); ++i) {
      if (sentence[i] == ' ') {
        if (word != "" && ans == "") {
          ans = word;
        } else if (word != "") {
          ans += ' ' + word;
        }

        word = "";
        skip = false;
        continue;
      }

      if (skip) {
        continue;
      }

      word += sentence[i];
      if (mp[word]) {
        if (ans == "") {
          ans = word;
        } else {
          ans += ' ' + word;
        }

        word = "";
        skip = true;
      }
    }

    if (word != "" && ans == "") {
      ans = word;
    } else if (word != "") {
      ans += ' ' + word;
    }

    return ans;
  }
};  // 596ms

class Solution {
 public:
  string replaceWords(vector<string>& dict, string sentence) {
    unordered_map<string, int> mp;

    for (auto& word : dict) {
      mp[word] = 1;
    }

    string word = "";
    string ans = "";

    for (int i = 0; i < sentence.size(); ++i) {
      if (sentence[i] == ' ') {
        if (word.size() > 0) {
          ans += word + ' ';
        }

        word = "";
      } else {
        word += sentence[i];
        if (mp[word]) {
          ans += word + ' ';
          word = "";

          while (i + 1 < sentence.size() && sentence[i + 1] != ' ') {
            ++i;
          }
        }
      }
    }

    if (word.size() > 0) {
      ans += word + ' ';
    }

    if (ans.empty()) {
      return "";
    } else {
      return string(ans.begin(), ans.end() - 1);
    }
  }
};  // 604ms