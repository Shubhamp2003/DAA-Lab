/*To store random numbers into an array of N integer.
where the array must contains some duplicates
and then do the following:
a) Find the total number of duplicate elements
b) Find out the most repeating element in the array.*/

#include <stdio.h>

int main()
{
    int count_arr_ssp_2951[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int repeated = 0;
    int n, max_repeat = 0, max = 0;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int arr_ssp_2951[n];

    printf("Enter the number in the array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr_ssp_2951[i]);
    }

    for (int i = 0; i < n; i++)
    {
        count_arr_ssp_2951[arr_ssp_2951[i]]++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (count_arr_ssp_2951[i] > 1)
        {
            repeated++;
        }
        if (count_arr_ssp_2951[i] > max)
        {
            max_repeat = i;
            max = count_arr_ssp_2951[i];
        }
    }
    printf("The arrray is \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr_ssp_2951[i]);
    }
    printf("\nThe number of elements repeated is :%d \nThe number max repeated is: %d", repeated, max_repeat);
}