/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: 2AHIF
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * A sorting algorithm
 *-----------------------------------------------------------------------------
*/
#include "bst.h"

struct Node{
  int root_value;
  Bst left;
  Bst right;
};

Bst new_bst(){
  return 0;
}

void delete_bst(Bst bst){
  if(bst==0)
  {
    return;
  }
  if(bst->left!=0)
  {
    delete_bst(bst->left);
  }
  if(bst->right!=0)
  {
    delete_bst(bst->right);
  }
  sfree(bst);
}

int get_depth(Bst bst){
  if (bst==0)return 0;
  int l = get_depth(bst->left);
  int r = get_depth(bst->right);
  if (l > r)return(l+1);
  else return(r+1);
}

void add(Bst* bst, int value){
  if(*bst == 0)
  {
    Bst new_bst = (Bst)malloc(sizeof(Node));
    new_bst->left = 0;
    new_bst->right = 0;
    new_bst->root_value = value;
    *bst = new_bst;
    return;
  }

  if(value > (*bst)->root_value)
  {
    add(&(*bst)->right, value);
  }
  else
  {
    add(&(*bst)->left, value);
  }
}

int root_value(Bst bst){
  if(bst==0)
  {
    return 0;
  }
  return bst->root_value;
}

Bst left_subtree(Bst root){
  if(root==0)return 0;
  return root->left;
}

Bst right_subtree(Bst root){
  if(root==0)return 0;
  return root->right;
}

int traverse_pre_order(Bst bst, int *elements, int start){
  if(bst==0)return 0;
  if(bst->left==0 && bst->right==0)
  {
    elements[start]=bst->root_value;
    return 1;
  }
  int count=0;
  elements[start++]=bst->root_value;
  count = traverse_pre_order(bst->left, elements, start);
  return count + traverse_pre_order(bst->right, elements, start + count ) + 1;
}

int traverse_in_order(Bst bst, int *elements, int start){
  if(bst==0)return 0;
  int count=0;
  count =  traverse_in_order(bst->left, elements, start);
  elements[start+count]=bst->root_value;
  return count + traverse_in_order(bst->right, elements, start + count +1)+1;
}

int traverse_post_order(Bst bst, int *elements, int start){
  if(bst==0)return 0;
  int count=0;
  count =  traverse_post_order(bst->left, elements, start);
  count += traverse_post_order(bst->right, elements, start + count);
  elements[start+count]=bst->root_value;
  return count+1;
}

bool are_equal(Bst bst1, Bst bst2){
  if(bst1 == 0 && bst2 == 0)
  {
    return true;
  }
  if(bst1 == 0 || bst2 == 0)
  {
    return false;
  }

  return are_equal(bst1->left, bst2->left) && are_equal(bst1->right, bst2->right) && bst1->root_value== bst2->root_value;
}

void most_left_longest_branch(Bst bst, Bst* branch){
  if(bst == 0) {
    return;
  }

  add(branch, bst->root_value);
  if(get_depth(bst->left) >= get_depth(bst->right))
  {
    most_left_longest_branch(bst->left, branch);
  }
  else
  {
    most_left_longest_branch(bst->right, branch);
  }
}

int get_number_of_subtrees(Bst bst){
  if(bst == 0)return -1;
  int count = get_number_of_subtrees(bst->left) + 1;
  return count + get_number_of_subtrees(bst->right) + 1;
}
