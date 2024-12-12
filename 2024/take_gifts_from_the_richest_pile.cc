class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(begin(gifts), end(gifts));

        while (k-- > 0) {
            int g = pq.top();
            pq.pop();
            pq.push(sqrt(g));
        }

        long long ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};
// 3 ms
// 13.39 MB

