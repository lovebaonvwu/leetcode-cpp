class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    vector<int> vect(26);
    int ans = 0;

    for (auto& c : chars) {
      vect[c - 'a']++;
    }

    for (auto& word : words) {
      bool good = true;

      vector<int> tmp(vect);

      for (auto& c : word) {
        if (!tmp[c - 'a']) {
          good = false;
          break;
        } else {
          tmp[c - 'a']--;
        }
      }

      if (good) {
        ans += word.size();
      }
    }

    return ans;
  }
};  // 68ms