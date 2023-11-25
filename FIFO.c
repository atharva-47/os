#include <stdio.h>
#define MAX 20

int frames[MAX], ref[MAX], faults=0, sp=0, m,n;

  void accept() {
  printf("Enter no of frames:");
  scanf("%d",&n);
  printf("Enter no of references:");
  scanf("%d",&m);
  printf("Enter references string:\n");
   for(int i=0;i<m;i++){
   printf("[%d]=",i);
   scanf("%d",&ref[i]);
  }
 }
  void fifo() {
  for(int i=0;i<m;i++) {
    int found=0;
   for(int j=0;j<n;j++) {
      if (frames[j] == ref[i]) {
      found =1;
      break;
      }
    }
   if(!found) {
   faults++;
   frames[sp]=ref[i];
   sp=(sp+1)%n;
   }
  }
 }
 int main() {
 accept();
 fifo();
 printf("\nEnter no of faults:%d\n",faults);
 return 0;
 }
     
