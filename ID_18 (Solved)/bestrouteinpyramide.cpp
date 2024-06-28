#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> stringToPyramid(string &input)
{
    vector<vector<int>> pyramid;
    stringstream ss(input);
    string line;
    int root{1}, counter{0};
    vector<int> row;
    while (getline(ss, line, ' '))
    {
        if (counter < root)
        {
            row.push_back(stoi(line));
            counter++;
        }
        if (counter >= root)
        {
            pyramid.push_back(row);
            row.clear();
            counter = 0;
            root++;
        }
    }
    return pyramid;
}
int main()
{
    string input = "75 95 64 17 47 82 18 35 87 10 20 04 82 47 65 19 01 23 75 03 34 88 02 77 73 07 63 67 99 65 04 28 06 16 70 92 41 41 26 56 83 40 80 70 33 41 48 72 33 47 32 37 16 94 29 53 71 44 65 25 43 91 52 97 51 14 70 11 33 28 77 73 17 78 39 68 17 57 91 71 52 38 17 14 91 43 58 50 27 29 48 63 66 04 68 89 53 67 30 73 16 69 87 40 31 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";
    vector<vector<int>> pyramid = stringToPyramid(input);
    const vector<vector<int>> pyramidCopy = pyramid;
    // print pyramid

    for (int i = 0; i < pyramid.size(); ++i)
    {
        for (int j = 0; j < pyramid[i].size(); ++j)
        {
            cout << pyramid[i][j] << "\t";
        }
        cout << endl;
    }

    vector<vector<int>> maxPath(pyramid.size() - 1, vector<int>(pyramid.size() - 1));
    vector<int> path{75};
    size_t belowRow = pyramid.size() - 1;
    for (int i = belowRow; i > 0; i--)
    {
        for (int j = 0; j < pyramid[i].size() - 1; j++)
        {
            int temp = max(pyramid[i][j], pyramid[i][j + 1]);
            pyramid[i - 1][j] += temp;
            maxPath[i - 1][j] = temp;
        }
    }
    // print maxPath
    cout << "\nMaxPath: " << endl;
    for (int i = 0; i < maxPath.size(); ++i)
    {
        for (int j = 0; j < maxPath[i].size(); ++j)
        {
            cout << maxPath[i][j] << "\t";
        }
        cout << endl;
    }
    // find path
    int index{0};
    for (int i = 0; i < maxPath.size() - 1; ++i)
    {

        if ((maxPath[i][index] - maxPath[i + 1][index]) == pyramidCopy[i + 1][index])
        {
            path.push_back(pyramidCopy[i+1][index]);
        }
        else if ((maxPath[i][index] - maxPath[i + 1][index + 1]) == pyramidCopy[i + 1][index + 1])
        {
            path.push_back(pyramidCopy[i+1][index + 1]);
            index++;
        }
        else
        {
            cout << "The number:" << pyramidCopy[i + 1][index] << "Not found" << endl;
        }
    }
    path.push_back(maxPath[maxPath.size() - 1][index] );

    // print pyramid
    cout << "\nPyramid: " << endl;
    for (int i = 0; i < pyramid.size(); ++i)
    {
        for (int j = 0; j < pyramid[i].size(); ++j)
        {
            cout << pyramid[i][j] << "\t";
        }
        cout << endl;
    }

    // print path
    cout << "\nPath: " << endl;
    cout << "The path has " << path.size() << " elements" << endl;
    for (int i = 0; i < path.size(); ++i)
    {
        cout << path[i] << "\t";
    }

    cout << "\nThe maximum path sum is: " << pyramid[0][0] << endl;

    return 0;
}