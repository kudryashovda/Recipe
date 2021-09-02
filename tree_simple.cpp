
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
};

bool SearchBinTree(Node* root, int item) {
    if (root == nullptr) {
        return false;
    }

    if (root->val == item) {
        return true;
    } else if (item < root->val) {
        SearchBinTree(root->left, item);
    } else {
        SearchBinTree(root->right, item);
    }
}

void PrintTreeCenter(Node* root) {
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr) {
        PrintTreeCenter(root->left);
    }

    cout << root->val << '\n';

    if (root->right != nullptr) {
        PrintTreeCenter(root->right);
    }
}

void PrintTreeLeftThenRight(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->val << '\n';

    if (root->left != nullptr) {
        PrintTreeLeftThenRight(root->left);
    }

    if (root->right != nullptr) {
        PrintTreeLeftThenRight(root->right);
    }
}

void PrintTreeBotTop(Node* root) {
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr) {
        PrintTreeBotTop(root->left);
    }

    if (root->right != nullptr) {
        PrintTreeBotTop(root->right);
    }

    cout << root->val << '\n';
}

int main() {

    Node* root = new Node{ 10, nullptr, nullptr };
    Node* node1 = new Node{ 9, nullptr, nullptr };
    Node* node2 = new Node{ 8, nullptr, nullptr };
    Node* node3 = new Node{ 7, nullptr, nullptr };
    Node* node4 = new Node{ 11, nullptr, nullptr };
    Node* node5 = new Node{ 12, nullptr, nullptr };
    Node* node6 = new Node{ 13, nullptr, nullptr };

    root->left = node2;
    root->right = node5;
    node2->left = node3;
    node2->right = node1;
    node5->left = node4;
    node5->right = node6;

    auto res = SearchBinTree(root, 110);
    cout << res << '\n';

    PrintTreeCenter(root);

    delete root;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;

    return 0;
}
