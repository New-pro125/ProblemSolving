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
void buildingDFS(TreeNode*&root,int start,const unordered_map<int,vector<pair<int,bool>>>&a){
    if(a.find(start)==a.end()) return;
    for(auto &child:a.at(start)){
        if(child.second){
            root ->left = new TreeNode(child.first);
        }
        else {
            root->right = new TreeNode(child.first);
        }
        buildingDFS((child.second ? root->left : root->right),child.first,a);
    }
    return;
}
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int,int>inorder ;
        unordered_map<int,vector<pair<int,bool>>>nodes;
        for(int i = 0;i<n;i++){
            nodes[descriptions[i][0]].push_back({descriptions[i][1],descriptions[i][2]});
            if(inorder.find(descriptions[i][0])==inorder.end())
                inorder[descriptions[i][0]]=0;
            inorder[descriptions[i][1]]++;
        }
        int start = 0;
        for(auto &[key,value]:inorder){
            if(value==0) start = key;
        }
        TreeNode * root = new TreeNode(start);
        buildingDFS(root,start,nodes);
        return root;
    }

};