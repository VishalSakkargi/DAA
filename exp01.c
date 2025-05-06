#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) 
{
    while (low <= high) 
	{
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) 
		{
            return mid;
        }

        if (arr[low] <= arr[mid]) 
		{
            if (arr[low] <= target && target < arr[mid]) 
			{
                high = mid - 1;
            } 
			else 
			{
                low = mid + 1;
            }
        }
        else {
            if (arr[mid] < target && target <= arr[high]) 
			{
                low = mid + 1;
            } else 
			{
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
	int n,i;
	printf("Enter the size of array");
	scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements :");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
	}
    int target;
	printf("Enter the target Element");
	scanf("%d",&target);
    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) 
	{
        printf("Element found at index: %d\n", result);
    } 
	else 
	{
        printf("Element not found\n");
    }

    return 0;
}

