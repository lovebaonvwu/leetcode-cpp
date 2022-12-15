class Solution 
{
public:
    int numberOfDays(int year, int month) 
    {
        int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        bool leapYear = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);

        return (leapYear && month == 2) ? mon[month] + 1 : mon[month];
    }
};
// Runtime 0 ms
// Memory 5.9 MB
// 2022.12.15 at 奥盛大厦