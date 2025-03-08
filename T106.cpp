#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};
vector<int> inorder_, postorder_;
TreeNode* build(int in_left, int in_right, int post_left, int post_right){
    if (in_left > in_right || post_left > post_right) return nullptr;
    int root_val = postorder_[post_right];
    int in_root = in_left;
    while(in_root <= in_right && inorder_[in_root] != root_val)
        in_root++;
    TreeNode* root = new TreeNode(root_val);
    int left_size = in_root - in_left;
    root->left = build(in_left, in_root - 1, post_left, post_left + left_size - 1);
    root->right = build(in_root + 1, in_right, post_left + left_size, post_right - 1);
    return root;
}
TreeNode* buildTree(vector<int> &inorder, vector<int>& postorder){
    inorder_ = inorder;
    postorder_ = postorder;
    return build(0, inorder.size() - 1, 0, postorder.size() - 1);
}

int main(){
    vector<int> inorder = {9, 3, 15, 20, 7}, postorder = {9, 15, 7, 20, 3};
    TreeNode* root = buildTree(inorder, postorder);
    cout<<root->val<<endl;
    return 0;
}