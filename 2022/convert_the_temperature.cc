class Solution {
 public:
  vector<double> convertTemperature(double celsius) {
    return {celsius + 273.15, celsius * 1.80 + 32.00};
  }
};
// Runtime 0 ms
// Memory 6.1 MB
// 2022.11.13 at 茗筑美嘉