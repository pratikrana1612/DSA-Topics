#include<stdio.h>
#include<conio.h>

void insertionSort(int numbers[20],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp=numbers[i];
        j=i-1;
        while(j>=0 && numbers[j]>temp)
        {
            numbers[j+1]=numbers[j];
            j--;
        }
        numbers[j+1]=temp;
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
    insertionSort(n,max);
    printf("order elements is:");
    for (i = 0; i < max; i++)
    {
        printf("%d ", n[i]);
    }
}