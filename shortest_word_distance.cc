class Solution {
 public:
  int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
    vector<int> w1, w2;
    for (int i = 0; i < wordsDict.size(); ++i) {
      if (wordsDict[i] == word1) {
        w1.push_back(i);
      } else if (wordsDict[i] == word2) {
        w2.push_back(i);
      }
    }

    int ans = INT_MAX;
    for (auto p1 : w1) {
      for (auto p2 : w2) {
        ans = min(ans, abs(p1 - p2));
      }
    }

    return ans;
  }
};
// Runtime 17 ms
// Memory 11.7 MB
// 2022.12.4 at 茗筑美嘉

class Solution {
 public:
  int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
    int p1 = -1, p2 = -1;
    int ans = INT_MAX;
    for (int i = 0; i < wordsDict.size(); ++i) {
      if (wordsDict[i] == word1) {
        p1 = i;
        if (p2 != -1) {
          ans = min(ans, abs(p1 - p2));
        }
      } else if (wordsDict[i] == word2) {
        p2 = i;
        if (p1 != -1) {
          ans = min(ans, abs(p1 - p2));
        }
      }
    }

    return ans;
  }
};
// Runtime 29 ms
// Memory 11.5 MB
// 2022.12.4 at 茗筑美嘉