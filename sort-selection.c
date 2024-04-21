#include<stdio.h>

void selection_sort(int arr[], int n) {
    int i, j, min, temp;
    for(i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {
    int arr[] = {5, 2, 8, 7, 1};
    int n = 5, i;
    selection_sort(arr, n);
    printf("Sorted array: \n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}