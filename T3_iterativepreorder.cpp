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
vector<int> iterativePreorder(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<node *> s;
    s.push(root);
    while (!s.empty())
    {
        node *tmp = s.top();
        ans.push_back(tmp->data);
        s.pop();
        if (tmp->right != NULL)
        {
            s.push(tmp->right);
        }
        if (tmp->left != NULL)
        {
            s.push(tmp->left);
        }
    }
    return ans;
}
vector<int> iterativepost(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<node *> s;
    s.push(root);
    while (!s.empty())
    {
        node *tmp = s.top();
        s.pop();
        ans.push_back(tmp->data);
        if (tmp->left != NULL)
        {
            s.push(tmp->left);
        }
        if (tmp->right != NULL)
        {
            s.push(tmp->right);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> iterativeInorder(node *root)
{
    vector<int> ans;

    stack<node *> s;
    node *tmp = root;
    while (true)
    {
        if (tmp != NULL)
        {
            s.push(tmp);
            tmp = tmp->left;
        }
        else
        {
            if (s.empty())
            {
                break;
            }

            tmp = s.top();
            s.pop();
            ans.push_back(tmp->data);
            tmp = tmp->right;
        }
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
    vector<int> final_ans = iterativeInorder(root);
    for (auto &i : final_ans)
    {
        cout << i << " ";
    }

    return 0;
}