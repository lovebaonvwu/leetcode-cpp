class Solution {
  bool isVowel(const char& ch) {
    switch (ch) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        return true;
      default:
        return false;
    }
  }

 public:
  string toGoatLatin(string S) {
    string ans = "";

    if (S.empty()) {
      return ans;
    }

    string word = "";

    bool vowel = true;
    bool start = false;
    char head = 0;
    int cnt = 0;

    S += ' ';

    for (int i = 0; i < S.size(); ++i) {
      if (isspace(S[i]) && (!word.empty() || head)) {
        ++cnt;

        if (vowel) {
          word += "ma";
        } else {
          word = word + head + "ma";
        }

        word.append(cnt, 'a');
        ans += word + ' ';

        word = "";
        head = 0;
        start = false;
      } else {
        if (word.empty() && !start) {
          if (!isVowel(S[i])) {
            head = S[i];
            vowel = false;
          } else {
            word += S[i];
            vowel = true;
          }

          start = true;
        } else {
          word += S[i];
        }
      }
    }

    return string(ans.begin(), ans.end() - 1);
  }
};  // 4ms

class Solution {
 public:
  string toGoatLatin(string S) {
    if (S.empty()) {
      return "";
    }

    vector<string> words;

    string word = "";

    for (const char& ch : S) {
      if (isalpha(ch)) {
        word.push_back(ch);
      } else {
        words.push_back(word);
        word.clear();
      }
    }

    if (word.size()) {
      words.push_back(word);
    }

    string ans = "";

    for (int i = 0; i < words.size(); ++i) {
      if (words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' ||
          words[i][0] == 'o' || words[i][0] == 'u' || words[i][0] == 'A' ||
          words[i][0] == 'E' || words[i][0] == 'I' || words[i][0] == 'O' ||
          words[i][0] == 'U') {
        ans += words[i].append("ma").append(i + 1, 'a');
      } else {
        ans += words[i]
                   .substr(1, words[i].size() - 1)
                   .append(1, words[i][0])
                   .append("ma")
                   .append(i + 1, 'a');
      }

      ans.append(1, ' ');
    }

    return string(ans.begin(), ans.end() - 1);
  }
};  // 4ms