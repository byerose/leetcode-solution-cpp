#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int comp(int n)
    {
        int res = 0;
        while (n)
        {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n)
    {
        unordered_set<int> s;
        int res = comp(n);
        while (res != 1)
        {
            cout << res << endl;
            if (s.count(res))
            {
                break;
            }
            else
            {
                s.insert(res);
            }
            res = comp(res);
        }
        return res == 1;
    }
};

int main()
{
    Solution so;
    cout << so.isHappy(2);
}