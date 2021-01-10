class Solution {
  bool diffByOneChar(const string& a, const string& b) {
    int cnt = 0;

    for (int i = 0; i < a.size() && cnt < 2; ++i) {
      if (a[i] != b[i]) {
        ++cnt;
      }
    }

    return cnt == 1;
  }

 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, vector<string>> mp;

    wordList.push_back(beginWord);

    for (int i = 0; i < wordList.size(); ++i) {
      for (int j = 0; j < wordList.size(); ++j) {
        if (i != j) {
          if (diffByOneChar(wordList[i], wordList[j])) {
            mp[wordList[i]].push_back(wordList[j]);
          }
        }
      }
    }

    queue<string> q;
    q.push(beginWord);

    int ans = 0;
    while (!q.empty()) {
      ++ans;

      int cnt = q.size();

      while (cnt-- > 0) {
        auto word = q.front();
        q.pop();

        if (word == endWord) {
          return ans;
        }

        if (mp.find(word) != mp.end()) {
          for (auto w : mp[word]) {
            q.push(w);
          }

          mp.erase(word);
        }
      }
    }

    return 0;
  }
};
// Runtime: 1804 ms, faster than 5.05%
// Memory Usage: 28.4 MB, less than 19.16%

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());

    queue<string> q;
    q.push(beginWord);

    int ans = 0;
    while (!q.empty()) {
      ++ans;

      int cnt = q.size();

      while (cnt-- > 0) {
        auto word = q.front();
        q.pop();

        if (word == endWord) {
          return ans;
        }

        st.erase(word);

        for (int i = 0; i < word.size(); ++i) {
          char tmp = word[i];

          for (int j = 0; j < 26; ++j) {
            word[i] = j + 'a';

            if (st.find(word) != st.end()) {
              q.push(word);
            }
          }

          word[i] = tmp;
        }
      }
    }

    return 0;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());

    queue<string> q;
    q.push(beginWord);

    int ans = 0;
    while (!q.empty()) {
      ++ans;

      int cnt = q.size();

      while (cnt-- > 0) {
        auto word = q.front();
        q.pop();

        if (word == endWord) {
          return ans;
        }

        st.erase(word);

        for (int i = 0; i < word.size(); ++i) {
          char tmp = word[i];

          for (int j = 0; j < 26; ++j) {
            word[i] = j + 'a';

            if (st.find(word) != st.end()) {
              q.push(word);
              st.erase(word);
            }
          }

          word[i] = tmp;
        }
      }
    }

    return 0;
  }
};
// Runtime: 192 ms, faster than 50.20%
// Memory Usage: 13.4 MB, less than 71.40%

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());

    queue<string> q;
    q.push(beginWord);

    int ans = 0;
    while (!q.empty()) {
      ++ans;

      int cnt = q.size();

      while (cnt-- > 0) {
        auto word = q.front();
        q.pop();

        if (word == endWord) {
          return ans;
        }

        for (int i = 0; i < word.size(); ++i) {
          char tmp = word[i];

          for (int j = 0; j < 26; ++j) {
            word[i] = j + 'a';

            if (st.find(word) != st.end()) {
              q.push(word);
              st.erase(word);
            }
          }

          word[i] = tmp;
        }
      }
    }

    return 0;
  }
};
// Runtime: 144 ms, faster than 70.64%
// Memory Usage: 13.5 MB, less than 71.40%

class Solution {
  bool diffByOneChar(const string& a, const string& b) {
    int cnt = 0;

    for (int i = 0; i < a.size() && cnt < 2; ++i) {
      if (a[i] != b[i]) {
        ++cnt;
      }
    }

    return cnt == 1;
  }

 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, vector<string>> mp;

    wordList.push_back(beginWord);

    for (int i = 0; i < wordList.size() - 1; ++i) {
      for (int j = i + 1; j < wordList.size(); ++j) {
        if (diffByOneChar(wordList[i], wordList[j])) {
          mp[wordList[i]].push_back(wordList[j]);
          mp[wordList[j]].push_back(wordList[i]);
        }
      }
    }

    queue<string> q;
    q.push(beginWord);

    int ans = 0;
    while (!q.empty()) {
      ++ans;

      int cnt = q.size();

      while (cnt-- > 0) {
        auto word = q.front();
        q.pop();

        if (word == endWord) {
          return ans;
        }

        if (mp.find(word) != mp.end()) {
          for (auto w : mp[word]) {
            q.push(w);
          }

          mp.erase(word);
        }
      }
    }

    return 0;
  }
};
// Runtime: 524 ms, faster than 29.33%
// Memory Usage: 28.3 MB, less than 19.00%