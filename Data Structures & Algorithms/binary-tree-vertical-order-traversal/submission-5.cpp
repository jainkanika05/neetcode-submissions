/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root){
            return vector<vector<int>>();
        }
        vector<vector<int>> res(202);
        int mxdx= 0;
        int mndx= 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            res[p.second+100].push_back(p.first->val);
            mxdx=max(mxdx,p.second);
            mndx=min(mndx,p.second);
            if(p.first->left){
                q.push({p.first->left,p.second-1});
            }
            if(p.first->right){
                q.push({p.first->right,p.second+1});
            }
        }
        vector<vector<int>> ans;
        for(int i=mndx;i<=mxdx;i++){
            vector<int> v=res[i+100];
            ans.push_back(v);
        }
        return ans;
    }
};