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
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}
void InOrder(struct node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        cout << root->data << endl;
        InOrder(root->right);
    }
}
queue<int> LevelOrderTraversal(struct node *root)
{
    queue<node *> q;
    queue<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    q.push(root);
    while (!q.empty())
    {
        int a = root->data;
        ans.push(a);
        q.pop();
        if (root->left != NULL)
        {
            q.push(root->left);
        }
        if (root->right != NULL)
        {
            q.push(root->right);
        }
        root = q.front();
    }
    return ans;
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        cout << root->data << endl;
        postOrder(root->right);
    }
}
int main()
{
    struct node *root = new node(2);
    root->left = new node(3);
    root->right = new node(4);
    root->left->right = new node(5);
    root->left->left=new node(9);
    root->left->right->left=new node(6);
    queue<int> nw = LevelOrderTraversal(root);
    while (!nw.empty())
    {
        cout << nw.front() << " ";
        nw.pop();
    }

    return 0;
}