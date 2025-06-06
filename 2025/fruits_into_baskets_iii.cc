class SegmentTree
{
public:
    SegmentTree(int n) : N(n)
    {
        tree.resize(4 * N);
    }

    void build(int idx, int left, int right, const vector<int> &arr)
    {
        if (left == right)
        {
            tree[idx] = arr[left];
        }
        else
        {
            int mid = left + (right - left) / 2;
            build(2 * idx, left, mid, arr);
            build(2 * idx + 1, mid + 1, right, arr);

            tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    void update(int idx, int left, int right, int arr_idx, int new_val)
    {
        if (left == right)
        {
            tree[idx] = new_val;
        }
        else
        {
            int mid = left + (right - left) / 2;
            if (arr_idx <= mid)
            {
                update(2 * idx, left, mid, arr_idx, new_val);
            }
            else
            {
                update(2 * idx + 1, mid + 1, right, arr_idx, new_val);
            }

            tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    int query(int idx, int left, int right, int start, int end)
    {
        if (end < left || start > right)
        {
            return 0;
        }

        if (start <= left && end >= right)
        {
            return tree[idx];
        }

        int mid = left + (right - left) / 2;
        int left_query = query(2 * idx, left, mid, start, end);
        int right_query = query(2 * idx + 1, mid + 1, right, start, end);

        return max(left_query, right_query);
    }

    void debug()
    {
        for (auto x : tree)
        {
            cout << x << " ";
        }

        cout << endl;
    }

private:
    vector<long long> tree;
    int N;
};

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = fruits.size();

        SegmentTree tree(n);
        tree.build(1, 0, n - 1, baskets);

        function<bool(int)> canBePlaced = [&](int weight) -> bool
        {
            int lo = 0;
            int hi = n - 1;

            while (lo < hi)
            {
                int md = (lo + hi) / 2;
                int capacity = tree.query(1, 0, n - 1, lo, md);

                if (weight <= capacity)
                {
                    hi = md;
                }
                else
                {
                    lo = md + 1;
                }
            }

            if (baskets[lo] >= weight)
            {
                tree.update(1, 0, n - 1, lo, 0);
                baskets[lo] = 0;
                return true;
            }

            return false;
        };

        int count = 0;

        for (auto f : fruits)
        {
            if (canBePlaced(f))
            {
                ++count;
            }
        }

        return n - count;
    }
};

// Time: nlog(n)
// Space: O(4n)