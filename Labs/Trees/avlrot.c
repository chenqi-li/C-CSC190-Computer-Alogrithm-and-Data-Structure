//
//  avlrot.c
//  Lab 3
//
//  Created by Chenqi Li on 2019/1/31.
//  Copyright © 2019 Chenqi Li. All rights reserved.
//

#include <stdio.h>




struct avlNode {
   int balance; /* -1 Left, 0 balanced, +1 Right */
   int val;
   struct avlNode *l;
   struct avlNode *r;
};
typedef struct avlNode avlNode;





int add_bst(avlNode **root,int val) {
   if (root == NULL) { return -1; }
   if (*root == NULL) {
      (*root) = (avlNode *) malloc(sizeof(avlNode));
      (**root).val = val;
      (**root).l = NULL;
      (**root).r = NULL;
      
   } else {
      if (val < ((**root).val)) {
         
         if ((**root).l == NULL) {
            ((**root).l) = (avlNode *)malloc(sizeof(avlNode));
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
            ((**root).r) = (avlNode *)malloc(sizeof(avlNode));
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





int printTreeInOrder(avlNode* root) {
   if (root==NULL) {
      return -1;
   }
   printTreeInOrder(root->l);
   printf("%d\n",root->val);
   printTreeInOrder(root->r);
   return 0;
}





int tdepth(avlNode *root) {
   if (root == NULL) {
      return 0;
   }
   else {
      int ldepth = tdepth(root->l);
      int rdepth = tdepth(root->r);
      
      if (ldepth > rdepth) {
         return(ldepth+1);
      }
      
      else {
         return(rdepth+1);
      }
   }
}
int isAVL(avlNode **root) {
   int ld = 0;
   int rd = 0;
   
   if (root == NULL) {
      return -1;
   }
   
   ld = tdepth((**root).l);
   rd = tdepth((**root).r);
   
   if ((rd - ld) > 1 || (rd-ld) < -1) {
      return -1;
   }
   else {
      return 0;
   }
}





int rotate(avlNode **root, unsigned int Left0_Right1) {
   
   if (root == NULL) {
      return -1;
   }
   
   if (Left0_Right1 == 1) {
      avlNode *temproot = *root;
      avlNode *rootr = (**root).r;
      avlNode *rootl = (**root).l;
      avlNode *rootlr = (**root).l->r;
      avlNode *rootll = (**root).l->l;
      
      
      *root = rootl;
      (**root).l = rootll;
      (**root).r = temproot;
      (**root).r->r = rootr;
      (**root).r->l = rootlr;
   }
   
   else if (Left0_Right1 == 0) {
      avlNode *temproot = *root;
      avlNode *rootr = (**root).r;
      avlNode *rootl = (**root).l;
      avlNode *rootrr = (**root).r->r;
      avlNode *rootrl = (**root).r->l;
      
      
      *root = rootr;
      (**root).l = temproot;
      (**root).r = rootrr;
      (**root).l->r = rootrl;
      (**root).l->l = rootl;
   }
   
   return 0;

}





int dblrotate(avlNode **root, unsigned int MajLMinR0_MajRMinL1) {
   
   if (root == NULL) {
      return -1;
   }
   
   if (MajLMinR0_MajRMinL1 == 1) {
      rotate(&((**root).r),1);
      rotate(root,0);
   }
   
   else if (MajLMinR0_MajRMinL1 == 0) {
      rotate(&((**root).l),0);
      rotate(root,1);
   }
   return 0;
}
