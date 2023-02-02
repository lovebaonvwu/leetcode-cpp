class Solution {
 public:
  int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
    int n = sensor1.size();

    int i = 0;

    while (i < n && sensor1[i] == sensor2[i]) {
      ++i;
    }

    while (i + 1 < n && sensor1[i + 1] == sensor2[i] &&
           sensor1[i] == sensor2[i + 1]) {
      ++i;
    }

    return i >= n - 1 ? -1 : sensor1[i] == sensor2[i + 1] ? 1 : 2;
  }
};
// Runtime 7 ms
// Memory 11.2 MB
// 2023.2.2 at 聊城滦河路汉庭优佳