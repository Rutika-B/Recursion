#include <bits/stdc++.h>
using namespace std;
void combination(int ind, int target, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr)
{
    if (ind==arr.size())
    {
        return;
    }
    if (target == 0)
    {
        ans.push_back(ds);
        // for (auto &t:ds)
        // {
        //     cout<<t<<" ";
        // }cout<<endl;
        
        return;
    }
    if (target >= arr[ind])
    {
        ds.push_back(arr[ind]);
        combination(ind, target - arr[ind], ds, ans, arr);
        ds.pop_back();
        combination(ind + 1, target, ds, ans, arr);
    }
    
    return;
}
// https://leetcode.com/problems/combination-sum/
// https://leetcode.com/problems/combination-sum-ii/submissions/
// https://leetcode.com/problems/subsets-ii/submissions/
int main()
{
    vector<int> arr = {2,3,3,5};
    int target = 8;
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(),arr.end());
    combination(0, target, ds, ans, arr);
    for (auto &i : ans)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}