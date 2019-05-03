//
//  crpty.m
//  Lab 6
//
//  Created by Chenqi Li on 2019/3/11.
//  Copyright © 2019 Chenqi Li. All rights reserved.
//
#include<stdio.h>



unsigned char FSR(unsigned char x) {
   unsigned char oldbit0 = x & 0x1; /* extract bit 0 */
   
   unsigned char r = x >> 1;        /* shift right   */
   unsigned char newbit7 = oldbit0 << 7; /* move bit0 to the bit7 pos */
   r = r | newbit7; /* rotate the old value of bit 0 into the bit 7 pos */
   return r;
}

unsigned char prng(unsigned char x, unsigned char pattern) {
   printf("before: %d", x);
   
   unsigned char oldbit0 = x & 0x1; /* extract bit 0 */
   unsigned char r = x >> 1;        /* shift right   */
   unsigned char newbit7 = oldbit0 << 7; /* move bit0 to the bit7 pos */
   r = r | newbit7; /* rotate the old value of bit 0 into the bit 7 pos */
   printf("after: %d\n", r);
   r = r ^ pattern; /*XOR with pattern*/
   return r;
}


int crypt(char *data, unsigned int size, unsigned char password) {
   unsigned char prngVal = password;
   unsigned int i=0;
   
   if (password=='0') {
      return -1;
   }
   
   for (i=0;i<=size;i++){
      prngVal = prng(prngVal,0xb8);
      data[i]= data[i] ^ prngVal;
   }
   
   return 0;
}


int main(void) {
   unsigned char x = 'a';
   int i=0;
   char data[10] = "helloworld";
   
   
   
   for (i=0;i<100;i++){
      printf("%c\n", x);
      x = prng(x,0xb1);
   }
   
   
   printf("Crypt %s\n", data);
   cryp(data, 9, 'a');
   printf("AfterCrypt %s\n", data);

   
}


