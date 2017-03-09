#include <iostream>
#include <queue>

using std::queue;

class Solution
{
    public:
        int findBottomLeftValue(TreeNode* root)
        {
            queue<int> level;
            queue<TreeNode*> treeque;

            level.push(0);
            treeque.push(root);

            int maxlevel = 0;
            TreeNode *retp = root;

            while (treeque.size())
            {
                TreeNode *curp = treeque.front();
                treeque.pop();

                int curlevel = level.front();
                level.pop();

                if (curp -> left)
                {
                    treeque.push(curp -> left);
                    level.push(curlevel + 1);
                }

                if (curp -> right)
                {
                    treeque.push(curp -> right);
                    level.push(curlevel + 1);
                }

                if (curlevel > maxlevel)
                {
                    maxlevel = curlevel;
                    retp = curp;
                }
            }
            return retp -> val;
        }
};
