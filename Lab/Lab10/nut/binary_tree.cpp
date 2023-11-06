#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }
    if (value < root->data) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        insert(root, x);
    }

    preorderTraversal(root);
    cout << "\n";

    postorderTraversal(root);
    cout << "\n";

    inorderTraversal(root);
    cout << "\n";
    return 0;
}
