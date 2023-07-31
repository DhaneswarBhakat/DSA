#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Inorder Traversal (Left-Root-Right)
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal (Root-Left-Right)
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal (Left-Right-Root)
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Function to build the binary tree from user input
TreeNode* buildTree() {
    int val;
    cout << "Enter the value for the current node (or -1 to exit): ";
    cin >> val;

    if (val == -1)
        return nullptr;

    TreeNode* root = new TreeNode(val);
    cout << "Enter left child of " << val << ":" << endl;
    root->left = buildTree();
    cout << "Enter right child of " << val << ":" << endl;
    root->right = buildTree();

    return root;
}

int main() {
    // Create a binary tree from user input
    cout << "Enter values to build a binary tree (enter -1 to stop):\n";
    TreeNode* root = buildTree();

    // Inorder Traversal
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    // Preorder Traversal
    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    // Postorder Traversal
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    // Clean up - deallocate memory
    // (You can also create a separate function to delete the tree)
    delete root;

    return 0;
}
