#include <stdio.h>
#include <unistd.h>

int main(){
  int pid;
  
  pid=fork();
  if(pid==0){
  printf("I am Child Process");
  printf(" Child process ID: %d\n",getpid());  
  }else if(pid<0){
   printf("Failed to create Child Process\n");
   return 1;
   }else{
   printf("I am Parent Process");
  printf(" Parent process ID: %d\n",getpid());  
  return 0;
  }
 }
