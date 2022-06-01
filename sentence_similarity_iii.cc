class Solution {
 public:
  bool areSentencesSimilar(string sentence1, string sentence2) {
    deque<string> w1;
    stringstream ss1(sentence1);
    string t1;
    while (ss1 >> t1) {
      w1.push_back(t1);
    }

    deque<string> w2;
    stringstream ss2(sentence2);
    string t2;
    while (ss2 >> t2) {
      w2.push_back(t2);
    }

    while (!w1.empty() && !w2.empty() && w1.front() == w2.front()) {
      w1.pop_front();
      w2.pop_front();
    }

    while (!w1.empty() && !w2.empty() && w1.back() == w2.back()) {
      w1.pop_back();
      w2.pop_back();
    }

    return w1.empty() || w2.empty();
  }
};
// Runtime: 4 ms, faster than 37.32%
// Memory Usage: 6.7 MB, less than 35.21%
// 2022.6.1 at 奥盛大厦