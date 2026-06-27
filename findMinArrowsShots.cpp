#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findMinarrowsShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end());
    int arrows = 1;
    long long end = points[0][1];
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] > end)
        {
            arrows++;
            end = points[i][1];
        }
        else
        {
            end = min(end, (long long)points[i][1]);
        }
    }
    return arrows;
}

int main(){
    int n;
    cout << "Enter the number of points : ";
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    cout << "Enter the points (start and end) : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    int result = findMinarrowsShots(points);
    cout << "Minimum number of arrows required: " << result << endl;

    return 0;
}