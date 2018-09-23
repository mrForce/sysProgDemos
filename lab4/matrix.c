#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

void fill_element(int* element){
  *element = 2;
}
void fill_one(int* matrix, size_t m, size_t n){
  for(size_t i = 0; i < m; i++){
    for(size_t j = 0; j < n; j++){
      matrix[i*n + j] = 2;
    }
  }
}


void fill_two(int* matrix, size_t m, size_t n){
  for(size_t i = 0; i < n; i++){
    for(size_t j = 0; j < m; j++){
      matrix[j*n + i] = 2;
    }
  }
}




int main(int argc, char** argv){
  size_t m = 10000;
  size_t n = 10000;
  int* matrix = (int*) malloc(sizeof(int)*m*n);
  for(size_t i = 0; i < m*n; i++){
    matrix[i] = 0;
  }
  fill_one(matrix, m, n);  
  fill_two(matrix, m, n);
  
  printf("%s", "Matrix size:\n");
  printf("%s %f %s\n", "With 2^20 definition of megabytes:", sizeof(int)*m*n/pow(2.0, 20), " megabytes");
  printf("%s %f %s\n", "With 10^6 definition of megabytes:", sizeof(int)*m*n/pow(10.0, 6), " megabytes");
  char c;
  //  scanf("%c", &c);
  
  free(matrix);
}
