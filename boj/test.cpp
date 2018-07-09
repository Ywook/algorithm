#include <stdio.h>

int data[] = {1, 2, 3, 4};

void powerset(int n)
{
    int i, j;
    int max = 1 << n;
    for (i = 0; i < max; i++)
    {
        printf("{");
        for (j = 0; j < n; j++)
        {
            if (i & (1 << j))
                printf("%d ", data[j]);
        }
        printf("}\n");
    }
}

int main()
{
    powerset(sizeof(data) / sizeof(int));
    return 0;
}
