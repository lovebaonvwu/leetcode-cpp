class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int arr[26]{0};

    for (char& c : magazine) {
      arr[c - 'a']++;
    }

    for (char& c : ransomNote) {
      arr[c - 'a']--;
      if (arr[c - 'a'] < 0) {
        return false;
      }
    }

    return true;
  }
};  // 20ms

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int arr[26]{0};

    for (char& c : magazine) {
      arr[c - 'a']++;
    }

    for (char& c : ransomNote) {
      arr[c - 'a']--;
    }

    for (int i = 0; i < 26; ++i) {
      if (arr[i] < 0) {
        return false;
      }
    }

    return true;
  }
};  // 20ms