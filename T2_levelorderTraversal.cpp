#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
vector<vector<int>> levelorderTraversal(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> sub_ans;
        for (int i = 0; i < n; i++)
        {
            node *a = q.front();
            q.pop();
            if (a->left != NULL)
            {
                q.push(a->left);
            }
            if (a->right != NULL)
            {
                q.push(a->right);
            }
            sub_ans.push_back(a->data);
        }
        ans.push_back(sub_ans);
    }
    return ans;
}
int main()
{
    struct node *root = new node(2);
    root->left = new node(3);
    root->right = new node(4);
    root->left->right = new node(5);
    root->left->left = new node(9);
    root->left->right->left = new node(6);
    vector<vector<int>> final_ans = levelorderTraversal(root);
    for (auto &i : final_ans)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}