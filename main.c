
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L);
    free(R);
}

void mergeSort(int* arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


void interleave(int* result, int* small, int* large,
                int sIdx, int lIdx, int pos, int n) {
    while (pos < n) {
        result[pos] = small[sIdx++];
        if (pos + 1 < n)
            result[pos + 1] = large[lIdx++];
        pos += 2;
    }
}

void wiggleSort(int* nums, int n) {
    int* sorted = (int*)malloc(n * sizeof(int));
    memcpy(sorted, nums, n * sizeof(int));
    mergeSort(sorted, 0, n - 1);
    int mid = (n - 1) / 2;
    int smallSize = mid + 1;
    int largeSize = n - smallSize;
    int* small = (int*)malloc(smallSize * sizeof(int));
    int* large = (int*)malloc(largeSize * sizeof(int));
    for (int i = 0; i < smallSize; i++)
        small[i] = sorted[mid - i];
    for (int i = 0; i < largeSize; i++)
        large[i] = sorted[n - 1 - i];
    interleave(nums, small, large, 0, 0, 0, n);
    free(sorted);
    free(small);
    free(large);
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int* nums = (int*)malloc(n * sizeof(int));
    if (nums == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter the array: ");
    for(int i=0;i<n;i++){
       scanf("%d",&nums[i]);
    }
    printf("Input:  "); printArray(nums,n);
    wiggleSort(nums, n);
    printf("Output: "); printArray(nums,n);
    printf("\n");
    return 0;
}
