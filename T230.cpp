#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
struct TreeNode
{
    int val;
    int idx;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, int i) : val(x), idx(i), left(NULL), right(NULL) {}
};

int kthSmallest(TreeNode* root, int k) {
    int cnt = 0;
    int res = -1;
    auto inOrder = [&](auto &&inOrder, TreeNode* root){
        if(root == nullptr){
            return;
        }
        inOrder(inOrder, root->left);
        cnt++;
        if(cnt == k){
            res = root->val;
            return;
        }
        inOrder(inOrder, root->right);
    };
    inOrder(inOrder, root);
    return res;
}

TreeNode* buildTree(vector<int> v, int i){
    if(i >= v.size() || v[i] == -1){
        return nullptr;
    }
    TreeNode* root = new TreeNode(v[i], i);
    root->left = buildTree(v, 2 * i + 1);
    root->right = buildTree(v, 2 * i + 2);
    return root;
}

int main(){
    // vector<int> v = {5,3,6,2,4,-1,-1,1}; // 层序遍历序列
    // int k = 3;
    vector<int> v = {3,1,4,-1,2}; // 层序遍历序列
    int k = 1;

    // TreeNode* root = new TreeNode(v[0], 0);
    // TreeNode* p = root;
    // queue<TreeNode*> q;
    // q.push(p);
    // unordered_map<TreeNode*, bool> inQueue;
    // inQueue[p] = true;
    // while(!q.empty()){
    //     p = q.front();
    //     q.pop();
    //     if(p->val == -1){
    //         continue;
    //     }
    //     int left = 2 * p->idx + 1;
    //     int right = 2 * p->idx + 2;
    //     if(left < v.size() && v[left] != -1){
    //         p->left = new TreeNode(v[left], left);
    //         q.push(p->left);
    //         inQueue[p->left] = true;
    //     }
    //     if(right < v.size() && v[right] != -1){
    //         p->right = new TreeNode(v[right], right);
    //         q.push(p->right);
    //         inQueue[p->right] = true;
    //     }
    // }
    // while(!q.empty()){
    //     p = q.front();
    //     q.pop();
    //     if(p->val == -1){
    //         continue;
    //     }
    //     int i = 2 * p->idx + 1;
    //     cout<<p->val<<", i = "<<i<<endl;
    //     if(i < v.size() && v[i] != -1){
    //         p->left = new TreeNode(v[i], i);
    //         q.push(p->left);
    //         inQueue[p->left] = true;
    //     }
    //     i++;
    //     if(i < v.size() && v[i] != -1){
    //         p->right = new TreeNode(v[i], i);
    //         q.push(p->right);
    //         inQueue[p->right] = true;
    //     }
    // }
    
    TreeNode* root = buildTree(v, 0);
    cout << kthSmallest(root, k) << endl;
    return 0;
}