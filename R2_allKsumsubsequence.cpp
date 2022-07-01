#include <bits/stdc++.h>
using namespace std;
void printsub(int arr[], int k, int n, int ind, vector<int> &ans, int sum)
{
    if (ind == n)
    {
        if (k == sum)
        {
            for (auto &it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    sum += arr[ind];
    ans.push_back(arr[ind]);
    printsub(arr, k, n, ind + 1, ans, sum);
    sum -= arr[ind];
    ans.pop_back();
    printsub(arr, k, n, ind + 1, ans, sum);
}

int main()
{
    int arr[] = {1, 2, 1};
    int K = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    printsub(arr, K, n, 0, ans, 0);

    return 0;
}