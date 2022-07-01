#include <bits/stdc++.h>
using namespace std;
int c = 0;
int subsequence(int ind, int arr[], int n, int k, int sum)
{
    if (ind == n)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }

    sum += (arr[ind]);
    int l = (subsequence(ind + 1, arr, n, k, sum));

    sum -= (arr[ind]);
    int r = (subsequence(ind + 1, arr, n, k, sum));
    return l + r;
}


int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3, s = 0;
    cout << subsequence(0, arr, n, k, s);

    return 0;
}
