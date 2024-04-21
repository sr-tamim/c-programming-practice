#include<stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 2, 8, 7, 1};
    int n = 5, i;
    bubble_sort(arr, n);
    printf("Sorted array: \n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}