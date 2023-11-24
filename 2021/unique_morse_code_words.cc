class Solution {
 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    unordered_set<string> st;

    vector<string> v{".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                     "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                     "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                     "...-", ".--",  "-..-", "-.--", "--.."};

    for (auto& word : words) {
      string code = "";

      for (auto& ch : word) {
        code += v[ch - 'a'];
      }

      st.insert(code);
    }

    return st.size();
  }
};  // 0ms