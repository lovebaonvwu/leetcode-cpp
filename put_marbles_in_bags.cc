class Solution {
 public:
  long long putMarbles(vector<int>& weights, int k) {
    vector<long long> score;

    for (int i = 0, n = weights.size(); i < n - 1; ++i) {
      score.push_back(weights[i] + weights[i + 1]);
    }

    sort(score.begin(), score.end());

    long long maxscore = 0, minscore = 0;
    int n = score.size();

    for (int i = 0; i < k - 1; ++i) {
      minscore += score[i];
      maxscore += score[n - 1 - i];
    }

    return maxscore - minscore;
  }
};
// Runtime 191 ms
// Memory 69.3 MB