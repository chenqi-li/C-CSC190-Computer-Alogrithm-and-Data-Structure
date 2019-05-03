//
//  main.m
//  Lab 4
//
//  Created by Chenqi Li on 2019/2/7.
//  Copyright © 2019 Chenqi Li. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int *store;
   unsigned int size;
   unsigned int end;
} HeapType;





int initHeap (HeapType *pHeap,int size) {
   if (pHeap == NULL) {return -1;}
   
   ((*pHeap).store) = (int *)malloc(sizeof(int) * size);
   (*pHeap).size = size;
   (*pHeap).end = 0;
   return 0;
}






int inorderTrav(HeapType *pHeap, int i, int *cnt, int *arr) {
   /*printf("i is %d\n", i);*/
   if(2*i+1 < pHeap->end) {
      inorderTrav(pHeap, 2*i+1, cnt, arr) ;
   }
   /*printf("%d\n", pHeap->store[i]) ;
   printf("cnt %d\n", *cnt);*/
   
   arr[*cnt] = pHeap->store[i];
   /*printf("arr[i] is %d\n", pHeap->store[i]);*/
   *cnt += 1;
   
   if(2*i+2 < pHeap->end) {
      inorderTrav(pHeap, 2*i+2, cnt, arr) ;
   }
   return 0;
}


int inorder  (HeapType *pHeap, int **output, int *o_size){
   int i = 0;
   int *arr;
   int cnt = 0;
   
   if (output == NULL) {return -1;}
   
   if (*output == NULL){
      (*output) = (int *)malloc(sizeof(int) * (pHeap)->size);
   }
   
   arr = (int*)malloc(sizeof(int) * (pHeap)->size);
   
   inorderTrav(pHeap, 0, &cnt, arr);
   

   for (i=0;i<pHeap->size;i++) {
      (*output)[i] = arr[i];
   }
   *o_size = pHeap->size;
   return 0;
}






int preorderTrav(HeapType *pHeap, int i, int *cnt, int *arr) {
   arr[*cnt] = pHeap->store[i];
   *cnt += 1;
   /*printf("i is %d\n", i);*/
   if(2*i+1 < pHeap->end) {
      preorderTrav(pHeap, 2*i+1, cnt, arr);
   }
   /*printf("%d\n", pHeap->store[i]) ;
   printf("cnt %d\n", *cnt);*/
   if(2*i+2 < pHeap->end) {
      preorderTrav(pHeap, 2*i+2, cnt, arr);
   }

   return 0;
}
int preorder(HeapType *pHeap, int **output, int *o_size){
   int i = 0;
   int *arr;
   int cnt = 0;
   
   if (output == NULL) {return -1;}
   
   if (*output == NULL){
      (*output) = (int *)malloc(sizeof(int) * (pHeap)->size);
   }
   
   arr = (int*)malloc(sizeof(int) * (pHeap)->size);
   
   preorderTrav(pHeap, 0, &cnt, arr);
   
   for (i=0;i<pHeap->size;i++) {
      (*output)[i] = arr[i];
   }
   return 0;
}





int postorderTrav(HeapType *pHeap, int i, int *cnt, int *arr) {
   /*printf("i is %d\n", i);*/
   if(2*i+1 < pHeap->end){
      postorderTrav(pHeap, 2*i+1, cnt, arr);
   }
   /*printf("%d\n", pHeap->store[i]) ;
   printf("cnt %d\n", *cnt);*/
   
   if(2*i+2 < pHeap->end){
      postorderTrav(pHeap, 2*i+2, cnt, arr);
   }
   arr[*cnt] = pHeap->store[i];
   *cnt += 1;

   return 0;
}
int postorder  (HeapType *pHeap, int **output, int *o_size){
   int i = 0;
   int *arr;
   int cnt = 0;
   
   if (output == NULL) {return -1;}
   
   if (*output == NULL){
      (*output) = (int *)malloc(sizeof(int) * (pHeap)->size);
   }
   
   arr = (int*)malloc(sizeof(int) * (pHeap)->size);
   
   postorderTrav(pHeap, 0, &cnt, arr);
   
   for (i=0;i<pHeap->size;i++){
      (*output)[i] = arr[i];
   }
   return 0;
}





int heapUp(int root, int bottom, int *array) {
   int parent;
   int temp=0;
   int i;

   
   if (bottom > root){
      parent = (bottom-2)/2;;
      /*printf("array[Parent] %d\n", array[parent]);
      printf("array[end] %d\n", array[bottom-1]);*/
      if(array[parent] < array[bottom-1]){
         temp = array[parent];
         array[parent] = array[bottom-1];
         array[bottom-1] = temp;
         /*printf("bottom is %d\n", bottom);
         printf("root is %d\n", root);
         for(i=0;i<bottom;i++){
            printf("array[i] is %d\n", array[i]);
         }*/
         heapUp(0, parent+1, array);
      }
   }
   /*
   else if(end > 1 && end%2 != 0){
      parent = (end-2)/2;;
      printf("array[Parent] %d\n", array[parent]);
      printf("array[end] %d\n", array[end-1]);
      if(array[parent] < array[end-1]){
         temp = array[parent];
         array[parent] = array[end-1];
         array[end-1] = temp;
         return heapUp(parent, array);
      }
   }
   */
   return 0;
}
int addHeap(HeapType *pHeap, int key) {
   if (pHeap == NULL) {return -1;}
   pHeap->store[(pHeap->end)] = key;
   pHeap->end += 1;
   heapUp(0, pHeap->end, pHeap->store);
   return 0;
}
         




int findHeap(HeapType *pHeap, int key) {
   int i;
   
   if (pHeap == NULL) {return -1;}
   
   for(i=0;i<(pHeap->end);i++) {
      if((*pHeap).store[i] == key) {
         return 1;
      }
   }
   return 0;
}






int ReheapDown(int root, int bottom, int *array){
   int leftChild = 2*root+1;
   int rightChild = 2*root+2;
   int maxChild;
   int temp;
   
   if (leftChild <= bottom){
      if (leftChild == bottom){
         maxChild = leftChild;
      }
      else {
         if(array[leftChild] <= array[rightChild]) {
            maxChild = rightChild;
         }
         else
            maxChild = leftChild;
      }
      if(array[root] < array[maxChild]) {
         temp = array[root];
         array[root] = array[maxChild];
         array[maxChild] = temp;
         ReheapDown(maxChild, bottom, array);
      }
   }
   return 0;
}


int delHeap(HeapType *pHeap, int *key) {
   *key = (*pHeap).store[0];
   pHeap->end -= 1;
   pHeap->store[0] = pHeap->store[pHeap->end];
   ReheapDown(0,pHeap->end,pHeap->store);
   return 0;
}





















/*
 printf("pHeap->i 1 %d\n", pHeap->i);
 
 if(2*(pHeap->i)+1 < pHeap->size) {
 (pHeap->i) = 2*(pHeap->i)+1;
 inorder(pHeap, output, o_size);
 }
 printf("%d\n", pHeap->store[pHeap->i]) ;
 printf("pHeap->i 2 %d\n", pHeap->i);
 
 (*output)[pHeap->j] = pHeap->store[pHeap->i];
 (pHeap->j) += 1;
 *o_size += 1;
 
if(2*(pHeap->i)+2 < pHeap->size) {
   (pHeap->i) = 2*(pHeap->i)+2;
   inorder(pHeap, output, o_size) ;
}
*/
