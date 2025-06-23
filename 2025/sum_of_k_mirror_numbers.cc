class Solution
{
    int tmp[100];

    long long build(long long head, bool odd)
    {
        long long tmp = head;
        long long tail = 0;
        int cnt = 0;

        while (tmp > 0)
        {
            tail = tail * 10 + tmp % 10;
            tmp /= 10;
            ++cnt;
        }

        if (odd)
        {
            head /= 10;
        }

        for (int i = 0; i < cnt; ++i)
        {
            head *= 10;
        }

        return head + tail;
    }

    bool check(long long x, int k)
    {
        int t = 0;
        while (x > 0)
        {
            tmp[t] = x % k;
            x /= k;
            t++;
        }

        int i = 0;
        int j = t - 1;

        while (i < j)
        {
            if (tmp[i++] != tmp[j--])
            {
                return false;
            }
        }

        return true;
    }

public:
    long long kMirror(int k, int n)
    {
        long long ans = 0;

        int len = 1;

        int count = 0;

        while (true)
        {
            for (long long i = pow(10, len - 1); i < pow(10, len); ++i)
            {
                long long cand = build(i, true);
                if (check(cand, k))
                {
                    ans += cand;
                    ++count;
                }
                if (count == n)
                {
                    return ans;
                }
            }

            for (long long i = pow(10, len - 1); i < pow(10, len); ++i)
            {
                long long cand = build(i, false);
                if (check(cand, k))
                {
                    ans += cand;
                    ++count;
                }
                if (count == n)
                {
                    return ans;
                }
            }

            ++len;
        }

        return -1;
    }
};
// Time: O(n * m), where n is the number of k-mirror numbers and m is the maximum length of the k-mirror numbers generated.
// Space: O(1), where n is the number of k-mirror numbers and m