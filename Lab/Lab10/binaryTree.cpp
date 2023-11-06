#include <iostream>

using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
TreeNode *insert(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }

    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

// Preorder traversal
void preorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Inorder traversal
void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    int N;
    cin >> N;

    TreeNode *root = nullptr;

    for (int i = 0; i < N; ++i)
    {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    return 0;
}
