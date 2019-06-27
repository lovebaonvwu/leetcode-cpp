class Solution {
 public:
  void duplicateZeros(vector<int>& arr) {
    int cnt = count(arr.begin(), arr.end(), 0);
    int size = arr.size();

    for (int i = size - 1; i >= 0; --i) {
      if (i + cnt < size) {
        arr[i + cnt] = arr[i];
      }

      if (arr[i] == 0) {
        --cnt;

        if (i + cnt < size) {
          arr[i + cnt] = arr[i];
        }
      }
    }
  }
};  // 20ms

class Solution {
 public:
  void duplicateZeros(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
      if (arr[i] == 0) {
        for (int j = arr.size() - 1; j > i + 1; --j) {
          arr[j] = arr[j - 1];
        }
        arr[i + 1] = 0;
        ++i;
      }
    }
  }
};  // 60ms