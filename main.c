#include <stdio.h>
#include <stdlib.h>

void insertionSort(long long arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        long long key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void wiggleSort(long long nums[], int n)
{
    insertionSort(nums, n);
    long long *temp = (long long *)malloc(n * sizeof(long long));
    int left = (n - 1) / 2;
    int right = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            temp[i] = nums[left--];
        else
            temp[i] = nums[right--];
    }

    for (int i = 0; i < n; i++)
        nums[i] = temp[i];
    free(temp);
}

int main()
{
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    long long *nums = (long long *)malloc(n * sizeof(long long));
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &nums[i]);
    }
    wiggleSort(nums, n);
    printf("Wiggle Sorted Array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%lld ", nums[i]);
    }
    free(nums);
    return 0;
}
