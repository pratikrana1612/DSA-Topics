#include <stdio.h>
#include <conio.h>

void selectionSort(int numbers[20],int n)
{
    int min, temp, i, j;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (numbers[j] < numbers[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            temp = numbers[i];
            numbers[i] = numbers[min];
            numbers[min] = temp;
        }
    }
}
void main()
{
    int n[20], max, i;
    // clrscr();
    printf("How many elements in the array:");
    scanf("%d", &max);
    for (i = 0; i < max; i++)
    {
        printf("%dth element:", i);
        scanf("%d", &n[i]);
    }
    selectionSort(n,max);
    printf("order elements is:");
    for (i = 0; i < max; i++)
    {
        printf("%d ", n[i]);
    }
}