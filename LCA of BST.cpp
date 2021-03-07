int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    if(root==NULL){
        return -1;
    }
    if(val1==root->data||val2==root->data){
        return root->data;
    }
    int ans;
    if(val1<root->data&&val2<root->data){
         ans=getLCA(root->left,val1,val2);
    }
    else if(val1>root->data&&val2>root->data){
         ans=getLCA(root->right,val1,val2);
    }
    else{
        return root->data;
    }
    return ans;
}
