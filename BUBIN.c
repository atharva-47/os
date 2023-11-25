#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void bubblesort(int arr[], int n) {
  int i, j, temp;

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void insertionsort(int arr[], int n) {
  int i, key, j;

  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
  }

  arr[j + 1] = key;
}

int main() {
  int n, i, status;
  pid_t pid;

  printf("Enter the no of integers: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the integers: ");

  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  pid = fork();

  if (pid == 0) {
    printf("Child Process using insertion sort...\n");
    insertionsort(arr, n);
    printf("Sorted array using insertion sort:");

    for (i = 0; i < n; i++) {
      printf("%d", arr[i]);
    }

    printf("\n");
    exit(EXIT_SUCCESS);
  } else {
    printf("Parent Process using bubble sort...\n");
    bubblesort(arr, n);
    printf("Sorted array using bubble sort:");

    for (i = 0; i < n; i++) {
      printf("%d", arr[i]);
    }

    printf("\n");
    wait(&status);
    printf("Child Process finished with status %d\n", status);
  }

  return 0;
}

