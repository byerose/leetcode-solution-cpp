#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> res;
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int i = 0, j = 0, d = 0;
        int len = matrix.size(), wid = matrix[0].size();
        vector<vector<int>> visited(len, vector<int>(wid, 0));
        cout << "OK" << endl;
        cout << len << " " << wid << endl;
        while (i >= 0 && j >= 0 && i < len && j < wid)
        {
            if (!visited[i][j])
            {
                res.push_back(matrix[i][j]);
                visited[i][j] = 1;
            }
            switch (d % 4)
            {
            case 0:
                if (j + 1 >= wid || visited[i][j + 1])
                {
                    d += 1;
                }
                else
                {
                    j += 1;
                }
                break;
            case 1:
                if (i + 1 >= len || visited[i + 1][j])
                {
                    d += 1;
                }
                else
                {
                    i += 1;
                }
                break;
            case 2:
                if (j - 1 < 0 || visited[i][j - 1])
                {
                    d += 1;
                }
                else
                {
                    j -= 1;
                }
                break;
            case 3:
                if (i - 1 < 0 || visited[i - 1][j])
                {
                    d += 1;
                }
                else
                {
                    i -= 1;
                }
                break;
            }

            if (res.size() == len * wid)
                break;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution so;
    cout << "OK" << endl;
    for (auto &x : so.spiralOrder(matrix))
    {

        cout << x << endl;
    }
}