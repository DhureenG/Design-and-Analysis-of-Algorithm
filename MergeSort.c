#include <stdio.h>

void merge_sort(int arr[], int lb, int ub, int n);
void merge(int arr[], int lb, int mid, int ub, int n);

int main() {
    int arr[50];
    printf("Enter size of array: ");
    int n;
    scanf("%d", &n);
    printf("Enter %d Elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int lb = 0;
    int ub = n - 1;
    merge_sort(arr, lb, ub, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void merge_sort(int arr[], int lb, int ub, int n) {
    int mid = lb + (ub - lb) / 2;
    if (lb < ub) {
        merge_sort(arr, lb, mid, n);
        merge_sort(arr, mid + 1, ub, n);
        merge(arr, lb, mid, ub, n);
    }
}

void merge(int arr[], int lb, int mid, int ub, int n) {
    int b[50];
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while (i <= mid && j <= ub) {
        if (arr[i] < arr[j]) {
            b[k++] = arr[i++];
        } else {
            b[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        b[k++] = arr[i++];
    }
    while (j <= ub) {
        b[k++] = arr[j++];
    }
    for (int l = lb; l <= ub; l++) {
        arr[l] = b[l];
    }
}
