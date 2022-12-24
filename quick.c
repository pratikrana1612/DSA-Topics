#include <stdio.h>
void quickSort(int number[15], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
            {
                i++;
            }
            while (number[j] > number[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quickSort(number, first, j - 1);
        quickSort(number, j + 1, last);
    }
}
int main()
{
    int n[20], max, i;
    // clrscr();
    printf("How many elements you want to enter in the array:");
    scanf("%d", &max);
    for (i = 0; i < max; i++)
    {
        printf("%dth element:", i);
        scanf("%d", &n[i]);
    }
    quickSort(n, 0, max - 1);
    printf("order elements is:");
    for (i = 0; i < max; i++)
    {
        printf("%d ", n[i]);
    }
}