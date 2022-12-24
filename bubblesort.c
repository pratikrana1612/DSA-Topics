#include <stdio.h>
#include <conio.h>

void bubbleSort(int numbers[15], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
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
    bubbleSort(n, max);
    printf("order elements is:");
    for (i = 0; i < max; i++)
    {
        printf("%d ", n[i]);
    }
}