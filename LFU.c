#include <stdio.h>
#define MAX_FRAMES 20
#define MAX_REFERENCES 50

int frames[MAX_FRAMES], ref[MAX_REFERENCES], faults=0, m,n;

void accept(){
 printf("Enter no of frames:");
 scanf("%d",&n);
 printf("Enter the no of references:");
 scanf("%d",&m);
 printf("Enter the references:\n");
 for (int i=0;i<m;i++) {
    printf("[%d]=",i);
    scanf("%d",&ref[i]);
    }
 }
void LFU() {
   int frequency[MAX_FRAMES]={0};
   for (int i=0;i<m;i++) {
       int found = 0, minFreq = frequency[0], minIndex=0;
       for (int j=0;j<n;j++) {
           if(frames[j] == ref[i]) {
           found =1;
           frequency[j]++;
           break;
       }
      if (frequency[j] < minFreq) {
           minFreq = frequency[j];
           minIndex=j;
       }
      }
      if(!found) {
          faults++;
          frames[minIndex]=ref[i];
          frequency[minIndex]=1;
      }
    }
  }
   int main() {
    accept();
    LFU();
    printf("\nEnter no of faults:%d\n",faults);
    return 0;
 }
     
