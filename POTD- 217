

https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree

class Solution
{
public:

    int ans =INT_MIN, ml =0;
    void check (Node* root, int sum, int level)
    {
        if ( root == NULL) return ;
        sum += root->data;
        
        if ( level > ml) 
        {
            ans = sum;
            ml = level;
        }
        
        else if (level == ml)
        {
            ans = max (sum, ans);
        }
        
        
        check ( root->left, sum,level+1);
        check ( root->right, sum,level+1);
        
        
    }


    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
       check (root,0,1);
        return ans;
        
        
    }
};
