/*
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2

*/

#include<bits/stdc++.h>
class ans{
    public:
    int minimum;
    int maximum;
    bool isBST;
    int height;
};
bool isBst(BinaryTreeNode<int> *root,int minimum,int maximum){
    if(root==NULL){
        return true;
    }
    if(root->data>maximum||root->data<minimum){
        return false;
    }
    return isBst(root->left,minimum,maximum)&&isBst(root->right,minimum,maximum);
}
int minimum(BinaryTreeNode<int> *root){
    if(root==NULL){
        return -1;
    }
    //ab minimum hoga to left pe hi
    BinaryTreeNode<int> *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
   
}
int maximum(BinaryTreeNode<int> *root){
    if(root==NULL){
        return -1;
    }
    BinaryTreeNode<int> *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}
int height(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}

ans largestBSThelper(BinaryTreeNode<int> *root){
    if(root==NULL){
        ans finalAns;
        finalAns.minimum=INT_MAX;
        finalAns.maximum=INT_MIN;
        finalAns.isBST=true;
        finalAns.height=0;
        return finalAns;
    }
    ans leftAns=largestBSThelper(root->left);
    ans rightAns=largestBSThelper(root->right);
    
    ans finalAns;
    
    if(leftAns.isBST==true&&rightAns.isBST==true&&root->data>root->left->data&&root->data<root->right->data){
        
        finalAns.height=max(leftAns.height,rightAns.height)+1;
        finalAns.isBST=true;
        finalAns.minimum=minimum(root);
        finalAns.maximum=maximum(root);
         return finalAns;
    }
    else if(leftAns.isBST==true&&rightAns.isBST==true&&root->data<root->left->data||root->data>root->right->data){
         finalAns.height=max(leftAns.height,rightAns.height);
        finalAns.isBST=false;
        finalAns.minimum=minimum(root);
        finalAns.maximum=maximum(root);
         return finalAns;
        
    }
    else{
        if(leftAns.isBST==true&&rightAns.isBST==false){
            return leftAns;
        }
        else if(leftAns.isBST==false&&rightAns.isBST==true){
            return rightAns;
        }
        else{
            return leftAns;
        }
    }
    
    
   

    

    
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
 
    ans x=largestBSThelper(root);
    return x.height;
    
}
