class Solution {
 public:
  bool checkStrings(string s1, string s2) {
    vector<char> odd_s1, even_s1, odd_s2, even_s2;
    for (int i = 0; i < s1.size(); ++i) {
      if (i & 1) {
        odd_s1.push_back(s1[i]);
        odd_s2.push_back(s2[i]);
      } else {
        even_s1.push_back(s1[i]);
        even_s2.push_back(s2[i]);
      }
    }

    sort(odd_s1.begin(), odd_s1.end());
    sort(odd_s2.begin(), odd_s2.end());
    sort(even_s1.begin(), even_s1.end());
    sort(even_s2.begin(), even_s2.end());

    return odd_s1 == odd_s2 && even_s1 == even_s2;
  }
};
// 113ms
// 21.18MB