class Solution {
 public:
  int minNumberOfHours(int initialEnergy,
                       int initialExperience,
                       vector<int>& energy,
                       vector<int>& experience) {
    int exp = 0, hp = 0;
    int n = energy.size();
    for (int i = 0; i < n; ++i) {
      hp += energy[i];
      if (experience[i] >= initialExperience) {
        exp += experience[i] - initialExperience + 1;
        initialExperience = experience[i] + 1;
      }
      initialExperience += experience[i];
    }

    return max(hp - initialEnergy + 1, 0) + exp;
  }
};
// Runtime: 7 ms, faster than 44.11%
// Memory Usage: 11.3 MB, less than 32.25%
// 2022.9.3 at 茗筑美嘉