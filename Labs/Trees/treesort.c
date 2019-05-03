//
//  treesort.c
//  Lab 3
//
//  Created by Chenqi Li on 2019/1/29.
//  Copyright © 2019 Chenqi Li. All rights reserved.
//

#include <stdio.h>

struct bstNode {
   int val;
   struct bstNode *l;
   struct bstNode *r;
};
typedef struct bstNode bstNode;

int add_bst(bstNode **root,int val) {
   if (root == NULL) { return -1; }
   if (*root == NULL) {
      (*root) = (bstNode *)malloc(sizeof(bstNode));
      (**root).val = val;
      (**root).l = NULL;
      (**root).r = NULL;
      
   } else {
      if (val < ((**root).val)) {
         
         if ((**root).l == NULL) {
            ((**root).l) = (bstNode *)malloc(sizeof(bstNode));
            (((**root).l)->val) = val;
            ((**root).l)->l = NULL;
            ((**root).l)->r = NULL;
         }
         else {
            
            return add_bst(&((**root).l), val);
         }
      }
      else if (val > ((**root).val)) {
         if ((**root).r == NULL) {
            ((**root).r) = (bstNode *)malloc(sizeof(bstNode));
            (((**root).r)->val) = val;
            (**root).r->l = NULL;
            (**root).r->r = NULL;
         }
         else {
            return add_bst(&((**root).r), val);
         }
      }
   }
   return 0;
}




int printTreeInOrder(bstNode* root) {
   if (root==NULL) {
      return -1;
   }
   printTreeInOrder(root->l);
   printf("%d\n",root->val);
   printTreeInOrder(root->r);
   return 0;
}



int main(void) {

   int value = 0;
   bstNode *root=NULL;
   while (scanf("%d",&value) != EOF) {
      add_bst(&root, value);
   }
   printTreeInOrder(root);
   
   
   return 0;
}

