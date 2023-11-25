#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
pid_t pid;

printf("Parent Process ID: %d\n",getpid());

pid=fork();
if (pid==0){
printf("Child Process ID: %d,Parent Process ID: %d\n",getpid(),getppid());
sleep(5);
printf("Child Process is still executing...");
}else{
printf("Parent Process is terminating...");
exit(0);
}
return 0;
}
