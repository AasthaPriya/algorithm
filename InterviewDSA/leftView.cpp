/*
question link :https://leetcode.com/problems/find-bottom-left-tree-value/
Given the root of a binary tree, return the leftmost value in the last row of the tree.
Input: root = [2,1,3]
Output: 1

*/


class Solution {
public:
    int lvl = -1, val = -1;
    
    void preorder(TreeNode* root, int curLvl){
        if(!root)return;
        
        if(curLvl > lvl){
            val = root -> val;
            lvl = curLvl;
        }
        preorder(root -> left, curLvl + 1);
        preorder(root -> right, curLvl + 1);
    }
	
    int findBottomLeftValue(TreeNode* root) {
        preorder(root, 0);
        return val;
    }
};