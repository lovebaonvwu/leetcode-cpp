/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> ans(m, vector<int>(n, -1));

    int i = 0, j = 0;
    int dirs[] = {0, 1, 0, -1, 0};
    int k = 0;
    int top = 1, bottom = m, left = 0, right = n;
    while (head) {
      ans[i][j] = head->val;
      head = head->next;

      int dx = i + dirs[k % 4];
      int dy = j + dirs[(k + 1) % 4];

      if ((k % 4 == 1) && dx == bottom) {
        ++k;
        bottom -= 1;
      } else if ((k % 4 == 3) && dx < top) {
        ++k;
        top += 1;
      } else if ((k % 4 == 0) && dy == right) {
        ++k;
        right -= 1;
      } else if ((k % 4 == 2) && dy < left) {
        ++k;
        left += 1;
      }

      i += dirs[k % 4];
      j += dirs[(k + 1) % 4];
    }

    return ans;
  }
};
// Runtime: 445 ms, faster than 33.33%
// Memory Usage: 128 MB, less than 33.33%
// 2022.7.4 at 奥盛大厦