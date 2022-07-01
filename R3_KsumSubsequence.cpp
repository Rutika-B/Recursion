#include <bits/stdc++.h>
using namespace std;
bool subsequence(int ind, int arr[], vector<int> v, int n, int k, int sum)
{
    if (ind == n)
    {
        if (sum == k)
        {
            for (auto &i : v)
            {
                cout << i << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    v.push_back(arr[ind]);
    sum += (arr[ind]);
    if (subsequence(ind + 1, arr, v, n, k, sum) == true)
        return true;

    v.pop_back();
    sum -= (arr[ind]);
    if (subsequence(ind + 1, arr, v, n, k, sum) == true)
        return true;
    return false;
}
// we use boolean function to stop future recursive calls once our condition gets satisfied
// (to get only one subsequence having k==sum)

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    int k = 3, s = 0;
    subsequence(0, arr, v, n, k, s);

    return 0;
}
