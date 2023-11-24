class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end());

    deque<int> dq;

    dq.push_back(deck.back());
    deck.pop_back();

    while (!deck.empty()) {
      dq.push_front(dq.back());
      dq.pop_back();
      dq.push_front(deck.back());
      deck.pop_back();
    }

    vector<int> ans(dq.begin(), dq.end());

    return ans;
  }
};
// Runtime: 12 ms, faster than 72.30%
// Memory Usage: 9.2 MB, less than 85.71%

class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end());

    queue<int> q;

    while (!deck.empty()) {
      int d = deck.back();
      deck.pop_back();

      if (q.size() > 1) {
        int t = q.front();
        q.pop();

        q.push(t);
      }

      q.push(d);
    }

    vector<int> ans(q.size());

    for (int i = ans.size() - 1; !q.empty(); --i) {
      ans[i] = q.front();
      q.pop();
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 72.30%
// Memory Usage: 9.3 MB, less than 85.71%