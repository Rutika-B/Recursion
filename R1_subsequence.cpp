#include <bits/stdc++.h>
using namespace std;
void subsequence(int ind, int arr[], vector<int> v, int n,int sum)
{
    if (ind == n)
    {
        if (v.empty())
        {
            cout << "{ }";
        }
     
        // for (auto &i : v)//this is to print subseqeunce
        // {
        //     cout << i << " ";
           
        // }
        cout <<"sum " <<sum<< endl;// this is to print sum of subsequence without directly using loop
        return;
    }
    v.push_back(arr[ind]);
    subsequence(ind + 1, arr, v, n,sum+arr[ind]);
    v.pop_back();
    subsequence(ind + 1, arr, v, n,sum);
}
// time complexity-->O(n)^2*O(n);//to get subsequence
// time complexity-->O(n)^2*;//to get only sum of subsequence

// space-->O(n);
int main()
{
    int arr[] = {1, 2, 3};
    int sum=0;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    subsequence(0, arr, v, n,sum);

    return 0;
}
