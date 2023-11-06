#include <iostream>
#include <cstdlib>

using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : key(data), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return new TreeNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}

int getHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

bool isAVL(TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }

    return isAVL(root->left) && isAVL(root->right);
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        root = insert(root, key);
    }

    if (isAVL(root)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
