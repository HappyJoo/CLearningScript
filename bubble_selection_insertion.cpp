#include <stdio.h>
int main()
{
    int a[10]={41,25,123,5213,21,24,52,1,4,1};
    int tem;
    printf("Original:       ");
    for(int q = 0; q < 10; q++) printf("%d ",a[q]);
    printf("\n");

    // Bubble sort
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10 - i; j++)
        {
            if(a[j] > a[j+1])
            {
                tem = a[j];
                a[j] = a[j+1];
                a[j+1] = tem;
            }
        }
    }
    printf("Bubble sort:    ");
    for(int q = 0; q < 10; q++) printf("%d ",a[q]);
    printf("\n");
  

    // Selection sort
    int b[10]={41,25,123,5213,21,24,52,1,4,1};

    for (int i = 0; i < 10; i++)
    {
        int minindex = i;
        for(int j = i; j < 10; j++)
        {
            if (b[j] < b[minindex])
            {
                minindex = j;
            }
        }
        if(minindex != i)
        {
            tem = b[minindex];
            b[minindex] = b[i];
            b[i] = tem;
        }
    }
    printf("Selection sort: ");
    for(int q = 0; q < 10; q++) printf("%d ",b[q]);
    printf("\n");


    // Insertion sort
    int c[10]={41,25,123,5213,21,24,52,1,4,1};

    for(int i = 0; i < 10; i++)
    {
        int value = c[i];
        int j = i - 1;
        for(;j>=0; j--)
        {
            if(c[j] > value)
            {
                c[j+1] = c[j];
            }
            else break;
        }
        c[j+1] = value;
    }
    printf("Insertion sort: ");
    for(int q = 0; q < 10; q++) printf("%d ",c[q]);
    printf("\n");

    return 0; 
}
