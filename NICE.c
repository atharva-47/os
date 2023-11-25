#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
   int pid;
   int nice_value;
   
   pid=fork();
   if(pid==0){
   nice_value=nice(-5);
   printf("Child Process gets higher CPU priority %d\n",nice_value);
   sleep(1);
   }else if(pid<0){
   printf("Failed to create Child Process\n");
   return 1;
   }else{
   nice_value=nice(4);
   printf("Parent Process gets lower CPU priority %d\n",nice_value);
   sleep(1);
   return 0;
   }
  }
   
