/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void bubble_sort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int arr[100], i, e;
  printf("Enter size of array: ");
  scanf("%d", &e);
  printf("Enter %d elements: ", e);
  for (i = 0; i < e; i++) {
    scanf("%d", &arr[i]);
  }
  bubble_sort(arr, e);
  printf("Sorted array: ");
  for (int i = 0; i < e; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
} 
