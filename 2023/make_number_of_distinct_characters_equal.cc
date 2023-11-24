class Solution {
 public:
  bool isItPossible(string word1, string word2) {
    int cnt1[26] = {0}, cnt2[26] = {0};

    for (auto c : word1) {
      ++cnt1[c - 'a'];
    }

    for (auto c : word2) {
      ++cnt2[c - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
      if (cnt1[i] == 0) {
        continue;
      }

      for (int j = 0; j < 26; ++j) {
        if (cnt2[j] == 0) {
          continue;
        }

        int t1[26] = {0};
        memcpy(t1, cnt1, sizeof(cnt1));
        int t2[26] = {0};
        memcpy(t2, cnt2, sizeof(cnt2));

        ++t1[j], --t1[i];
        ++t2[i], --t2[j];

        int dist1 = 0;
        for (int k = 0; k < 26; ++k) {
          dist1 += t1[k] > 0;
        }

        int dist2 = 0;
        for (int k = 0; k < 26; ++k) {
          dist2 += t2[k] > 0;
        }

        if (dist1 == dist2) {
          return true;
        }
      }
    }

    return false;
  }
};
// Runtime 53 ms
// Memory 16.8 MB