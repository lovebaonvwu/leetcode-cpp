class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    auto it = upper_bound(letters.begin(), letters.end(), target);

    return it == letters.end() ? letters[0] : *it;
  }
};  // 12ms

class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    if (target >= letters[letters.size() - 1] || target < letters[0]) {
      return letters[0];
    }

    int i = 0;
    int j = letters.size() - 1;

    while (i <= j) {
      int mid = (i + j) >> 1;

      if (letters[mid] == target) {
        if (letters[mid + 1] > target) {
          return letters[mid + 1];
        } else {
          i = mid + 1;
        }
      } else if (letters[mid] < target) {
        i = mid + 1;
      } else if (letters[mid] > target) {
        if (letters[mid - 1] <= target) {
          return letters[mid];
        } else {
          j = mid - 1;
        }
      }
    }

    return 'n';
  }
};  // 16ms

class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    int i = 0;
    int j = letters.size() - 1;

    while (i <= j) {
      int mid = (i + j) >> 1;

      if (letters[mid] <= target) {
        i = mid + 1;
      } else if (letters[mid] > target) {
        j = mid - 1;
      }
    }

    if (i == letters.size()) {
      return letters[0];
    } else {
      return letters[i];
    }
  }
};  // 16ms