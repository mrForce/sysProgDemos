#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char** argv){

  if(argc == 2){
    int sort_to_awk[2];
    /*
      Fill in here
     */
    int pid = fork();

    if(pid == 0){
      /* Fill in here */      
      execlp("sort", "sort", "-k", "2", "-n", (char*) NULL);      
      exit(2);
    }else{
      /* Fill in here */
      execlp("awk", "awk", "{print($1)}", (char*) NULL);
      exit(2);
    }
  }
}
