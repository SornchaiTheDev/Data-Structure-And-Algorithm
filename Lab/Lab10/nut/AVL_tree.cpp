#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

int height(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

bool isAVL(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }

    return isAVL(root->left) && isAVL(root->right);
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    if (isAVL(root)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
