/*
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.
Output Format :
Print each pair in a new line, as described in the task. 
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
*/
#include<bits/stdc++.h>

void cnvtArray(BinaryTreeNode<int> *root,vector<int> &v){
    if(root==NULL){
        return;
    }
    v.push_back(root->data);
    cnvtArray(root->left,v);
    cnvtArray(root->right,v);
    
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    //convert into array
    vector<int> v;
    cnvtArray(root,v);
    sort(v.begin(),v.end());
    
    int i=0,j=v.size()-1;
    while(i<j){
        
         if(v[i]+v[j]==sum){
            cout<<v[i]<<" "<<v[j]<<endl;
            i++;
            j--;
        }
        
        else if(v[i]+v[j]<sum){
            j--;
        }
        else {
            i++;
        }
       
    }
}
