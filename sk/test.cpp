#include <stdio.h>
#include <stdlib.h>

void dump_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int case_num, total_num, least_len, i, j, k, start, len, sum;
    int *arr, *summation;
    double min, current;

    scanf("%d", &case_num);

    for (i = 0; i < case_num; i++)
    {
        scanf("%d %d", &total_num, &least_len);
        arr = (int *)malloc(sizeof(int)* total_num);
        summation = (int *)malloc(sizeof(int)*( total_num + 1));
        summation[0] = 0;
        for (j = 0; j < total_num; j++)
        {
            scanf("%d", &arr[j]);
            summation[j + 1] = summation[j] + arr[j];
        }

    }
    for (int k = 0; k <= total_num; k++)
    {
        printf("%d\n", summation[k]);
    }
}