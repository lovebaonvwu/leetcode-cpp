class Solution {
 public:
  vector<string> commonChars(vector<string>& A) {
    int shortest = 0;
    int len = INT_MAX;

    int arr[26]{0};

    for (int i = 0; i < A.size(); ++i) {
      if (A[i].size() < len) {
        len = A[i].size();
        shortest = i;
      }
    }

    for (char& c : A[shortest]) {
      arr[c - 'a']++;
    }

    for (string& s : A) {
      int tmp[26]{0};

      for (char& c : s) {
        if (arr[c - 'a']) {
          tmp[c - 'a']++;
        }
      }

      for (int i = 0; i < 26; ++i) {
        if (tmp[i] && tmp[i] < arr[i]) {
          arr[i] = tmp[i];
        } else if (!tmp[i] && arr[i]) {
          arr[i] = 0;
        }
      }
    }

    vector<string> ans;

    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < arr[i]; ++j) {
        char c = i + 'a';
        string s;
        s += c;
        ans.push_back(s);
      }
    }

    return ans;
  }
};