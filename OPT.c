#include <stdio.h>
#define MAX_FRAMES 20
#define MAX_REFERENCES 50

int frames[MAX_FRAMES], ref[MAX_REFERENCES], faults=0, m, n;

void accept() {
printf("Enter no of frames:");
scanf("%d",&n);
printf("Enter no of references:");
scanf("%d",&m);
printf("Enter references string:\n");
  for (int i=0;i<m;i++) {
     printf("[%d]=",i);
     scanf("%d",&ref[i]);
     }
    }
   int findOptimal(int index) {
   int res=-1, farthest = index;
   for (int i=0;i<n;i++) 
     for (int j=index;j<m;j++) 
        if (frames[i]== ref[j] && j > farthest)farthest=j, res=i;
        return (res=-1)?0:res;
        }
        
    void Optimal() {
    for(int i=0;i<m;i++) {
       int found=0;
       for(int j=0;j<n && !found; j++)
        if (frames[j]==ref [i])found=1;
          if (!found) { 
              faults++;
               frames[findOptimal(i+1)]=ref[i];
           }
       }
     }
    int main() {
        accept();
        Optimal();
        printf("\nTotal page faults:%d\n",faults);
        return 0;
       }
     
     
     
     
     
     
    
