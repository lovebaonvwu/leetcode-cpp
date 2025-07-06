class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        auto isBulky = [&]() -> bool
        {
            if (length >= 1e4 || height >= 1e4 || width >= 1e4)
            {
                return true;
            }

            if (1LL * length * width * height >= 1e9)
            {
                return true;
            }

            return false;
        };

        auto bulky = isBulky();
        if (bulky && mass >= 100)
        {
            return "Both";
        }
        else if (bulky)
        {
            return "Bulky";
        }
        else if (mass >= 100)
        {
            return "Heavy";
        }
        else
        {
            return "Neither";
        }
    }
};
// Time: O(1)
// Space: O(1)