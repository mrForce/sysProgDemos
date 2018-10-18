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
    pipe(sort_to_awk);    
    int pid = fork();

    if(pid == 0){
      close(sort_to_awk[0]);
      int scores_fd = open(argv[1], O_RDONLY);
      dup2(scores_fd, 0);
      close(scores_fd);
      dup2(sort_to_awk[1], 1);
      close(sort_to_awk[1]);
      execlp("sort", "sort", "-k", "2", "-n", (char*) NULL);      
      exit(2);
    }else{
      int status;
      close(sort_to_awk[1]);
      dup2(sort_to_awk[0], 0);
      close(sort_to_awk[0]);
      execlp("awk", "awk", "{print($1)}", (char*) NULL);
      exit(2);
    }
  }
}
