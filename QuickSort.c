#include <stdio.h>
#include <stdlib.h>
void quicksortFirst(int arr[],int low, int high){
    if (low<high){
        int pivot=arr[low];
        int i=low;
		int j=high;
		int temp;
		while(i<=j){
			while(arr[i]<pivot)i++;
			while(arr[j]>pivot)j--;
			if(i<=j){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				i++;
				j--;
			}
		}
		if(low<j)
		quicksortFirst(arr,low,j);
		if(i<high)
		quicksortFirst(arr,i,high);
	}
}
void printArr(int arr[],int size){
	for(int i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
int main(){
	int n;
	printf("Enter No. of elements in array: ");
	scanf("%d",&n);
	int array1[n];
	printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&array1[i]);
    }
    printf("Original Array: \n");
    printArr(array1,n);
    quicksortFirst(array1,0,n-1);
    printf("Sorted array: \n");
    printArr(array1,n);
    return 0;
}
