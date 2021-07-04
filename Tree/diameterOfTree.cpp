//here we are not creating any tree . A tree is already created and given root we need to find the 
//diameter

//here we are using maxDepth concept to find the diameter of the tree

//Diameter of Tree : The path between two leaf nodes having maxium no.of nodes 
//Note : There is not manditory that the path having max no.of nodes is always pass through root node

int ans = 0;
 int maxDepth( TreeNode *root ){
        
        if( !root ) return 0;
        
        int l = maxDepth( root -> left );
        int r = maxDepth( root -> right );
        ans = max( ans , l+r );
        return max( l , r ) + 1;
        
 }
    
int diameterOfBinaryTree(TreeNode* root) {
        
        maxDepth( root );
        return ans;
        
        
}
