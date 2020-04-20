/*
 ============================================================================
 Name        : cccc.c
 Author      : dog
 Version     :
 Copyright   : gav
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
 float *a, *b, res;
 int size;
 char s, q;
 do {
 printf("Enter the size of the vectors: ");
 scanf("%i", &size);
 a = calloc(size,sizeof(float));
 for (int i=0; i<size; i++){
     printf("Enter the first vector: ");
     scanf("%f", &a[i]); }
 b = calloc(size,sizeof(float));
  for (int i=0; i<size; i++){
      printf("Enter the second vector: ");
      scanf("%f", &b[i]); }
 printf("Operation(+-*):");
 scanf(" %c%*c", &s);
 switch(s){
 case '+':
    for (int i = 0; i < size; i++){
    printf("Result: %f\n", a[i] + b[i]);}
    break;
 case '-':
    for (int i = 0; i < size; i++){
    printf("Result: %f\n", a[i] - b[i]);}
    break;
 case '*':
     for (int i = 0; i < size; i++){
     res = a[i] * b[i];}
     printf("Result: %f\n", res);
     break;
 default:
     printf("Unknown operation.\n");
} printf("Continue?(y/n): ");
  scanf(" %c", &q);
 }while(q=='y');
}
