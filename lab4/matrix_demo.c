#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
void print_matrix(int* matrix, size_t m, size_t n){
  /* only handles small matrices, with at most 3 characters in each number */
  //+---- for each column, plus a + at the end, and the null terminator
  char *line = (char*) malloc((n*5 + 2)*sizeof(char));
  line[0] = '\0';
  //probably not the most efficient way, but it works.
  for(size_t i = 0; i < n; i++){
    strcat(line, "+----"); 
  }
  strcat(line, "+");
  printf("%s\n", line);
  for(size_t i = 0; i < m; i++){
    printf("|");
    for(size_t j = 0; j < n; j++){
      char number_string[5];      
      assert(sprintf(number_string, "%d", matrix[i*n + j]) > 0);
      assert(strlen(number_string) <= 3);
      for(int k = 0; k < 4 - strlen(number_string); k++){
	printf("%c", ' ');
      }
      printf("%s", number_string);
      printf("%s" ," |");
    }
    printf("\n%s\n", line);
  }
  free(line);
}

void fill_one(int* matrix, size_t m, size_t n){
  size_t k = 0;
  for(size_t i = 0; i < m; i++){
    for(size_t j = 0; j < n; j++){
      matrix[i*n + j] = k;
      k++;
    }
  }
}

void fill_two(int* matrix, size_t m, size_t n){
  size_t k = 0;
  for(size_t i = 0; i < n; i++){
    for(size_t j = 0; j < m; j++){
      matrix[j*n + i] = k;
      k++;
    }
  }
}




int main(int argc, char** argv){
  size_t m = 5;
  size_t n = 5;
  int* matrix = (int*) malloc(sizeof(int)*m*n);
  for(size_t i = 0; i < m*n; i++){
    matrix[i] = 0;
  }
  /*
    matrix looks like this:

    <----- n columns ------->
    +----+----+----+----+----+ ^
    |  0 |  1 |  2 |  3 |  4 | |
    +----+----+----+----+----+ |
    |  5 |  6 |  7 |  8 |  9 | m
    +----+----+----+----+----+ 
    | 10 | 11 | 12 | 13 | 14 | r
    +----+----+----+----+----+ o
    | 15 | 16 | 17 | 18 | 19 | w
    +----+----+----+----+----+ s 
    | 20 | 21 | 22 | 23 | 24 | |
    +----+----+----+----+----+ ^


   */
  print_matrix(matrix, m, n);
  printf("%s", "\n\nfill_one access pattern\n\n");
  fill_one(matrix, m, n);  
  print_matrix(matrix, m, n);
  printf("%s", "\n\nfill_two access pattern\n\n");
  fill_two(matrix, m, n);
  print_matrix(matrix, m, n);
  /*printf("check the size");
  char c;
  scanf("%c", &c);
  */
  free(matrix);
}
