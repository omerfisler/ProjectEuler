// Used github copilot to generate the code cause the result is also findable by using 40!/(20!*20!) which is 137846528820
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<long long>> grid(21, vector<long long>(21, 0));
    for (int i = 0; i < 21; i++)
    {
        grid[i][0] = 1;
        grid[0][i] = 1;
    }
    for (int i = 1; i < 21; i++)
    {
        for (int j = 1; j < 21; j++)
        {
            grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
        }
    }
    cout << grid[20][20] << endl;
    return 0;
}