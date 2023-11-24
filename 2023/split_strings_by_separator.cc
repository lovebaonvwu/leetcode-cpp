class Solution {
 public:
  vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    vector<string> ans;
    for (auto& word : words) {
      stringstream ss(word);
      string w;
      while (std::getline(ss, w, separator)) {
        if (!w.empty()) {
          ans.push_back(w);
        }
      }
    }

    return ans;
  }
};
// 45ms
// 44.76MB