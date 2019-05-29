class Solution {
 public:
  int firstUniqChar(string s) {
    int s_array[26]{0};

    for (int i = 0; i < s.size(); ++i) {
      s_array[s[i] - 'a'] = i;
    }

    for (int i = 0; i < s.size(); ++i) {
      if (s_array[s[i] - 'a'] == i) {
        return i;
      } else {
        s_array[s[i] - 'a'] = -1;
      }
    }

    return -1;
  }
};  // 36ms

class Solution {
 public:
  int firstUniqChar(string s) {
    int s_array[26]{0};

    for (int i = 0; i < s.size(); ++i) {
      s_array[s[i] - 'a']++;
    }

    for (int i = 0; i < s.size(); ++i) {
      if (s_array[s[i] - 'a'] == 1) {
        return i;
      }
    }

    return -1;
  }
};  // 40ms

class Solution {
 public:
  int firstUniqChar(string s) {
    int count[26]{0};
    unordered_map<char, int> mp;
    int index = INT_MAX;

    for (int i = 0; i < s.size(); ++i) {
      count[s[i] - 'a']++;
      if (mp.find(s[i]) == mp.end()) {
        mp[s[i]] = i;
      }
    }

    for (int i = 0; i < 26; ++i) {
      if (count[i] == 1) {
        index = mp[i + 'a'] < index ? mp[i + 'a'] : index;
      }
    }

    return index == INT_MAX ? -1 : index;
  }
};  // 48ms