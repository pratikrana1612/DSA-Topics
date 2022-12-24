#include <stdio.h>

int number[20];

void merge(int low, int mid, int high)
{
    int merge[high + 1];
    int idx1 = low;
    int idx2 = mid + 1;
    int x = low;

    while (idx1 <= mid && idx2 <= high)
    {
        if (number[idx1] < number[idx2])
        {
            merge[x++] = number[idx1++];
            // x++;
            // idx1++;
        }
        else
        {
            merge[x++] = number[idx2++];
            // x++;
            // idx2++;
        }
    }
    while (idx1 <= mid)
    {
        merge[x++] = number[idx1++];
    }
    while (idx2 <= high)
    {
        merge[x++] = number[idx2++];
    }
    for(int i=low;i<=high;i++)
    {
        number[i]=merge[i];
    }
}
void mergeSort(int low, int high)
{
    int mid;
    if (low != high)
    {
        mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
    else
    {
        return;
    }
}
void main()
{
    int high,i;
    printf("How many elements in the array:");
    scanf("%d",&high);
    for(i=0;i<high;i++)
    {
        printf("%dth element:",i);
        scanf("%d",&number[i]);
    }
    mergeSort(0,high-1);
    printf("order elements is:");
    for (i = 0; i < high; i++)
    {
        printf("%d ", number[i]);
    }
}