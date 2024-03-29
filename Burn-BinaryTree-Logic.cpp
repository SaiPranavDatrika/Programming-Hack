/*Note:Please do let me know, if my logic fails or there is any faluts..Thanks in advance!!

Problem Statement:
You have been given a binary tree of 'N' unique nodes and a Start node from where the tree will start to burn.
Given that the Start node will always exist in the tree, your task is to print the time (in minutes) that it will take to burn the whole tree.
It is given that it takes 1 minute for the fire to travel from the burning node to its adjacent node and burn down the adjacent node.

Time Complexity:O(Number Of Nodes),SpaceComplexity:Height(BinaryTree)

link to the problem statement:https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563*/

int height(Node* root){
  if(root==NULL)
     return 0;
  return max(height(root->left),height(root->right))+1;
}
void height_level(Node* root,int startnode,int &level,bool found){
if(root==NULL)
  return 0;
  
  if(root->data==startnode)
    {found=true;}
    
    if(found==true && root->left!=NULL){
    height_level(root->left,startnode,level+1,found);
    height_level(root->right,startnode,level,found);}
    else if(found==true && root->right!=NULL){
      height_level(root->left,startnode,level,found);
     height_level(root->right,startnode,level+1,found);}
     else{
     height_level(root->left,startnode,level,found);
     height_level(root->right,startnode,level,found);}
  }
  
  int findtime_burn(Node* root,int starnode){
  bool found=false;
  int level=0;
  height_level(root,startnode,level,found);
  int l=height(root->left)+1;
  int r=height(root->right)+1;
  int actualtime=l+r-level;
  
  return actualtime;
  }
