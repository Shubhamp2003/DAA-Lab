/*To rearrange the elements of an array of N integers 
such that all even numbers are followed by all odd numbers*/
#include <stdio.h>

int main()
{
    int n_ssp_2951, i_ssp_2951, j_ssp_2951, temp_ssp_2951;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n_ssp_2951);
    int arr_ssp_2951[n_ssp_2951];
    printf("Enter the elements of the array: ");
    for (i_ssp_2951 = 0; i_ssp_2951 < n_ssp_2951; i_ssp_2951++)
        scanf("%d", &arr_ssp_2951[i_ssp_2951]);
    for (i_ssp_2951 = 0; i_ssp_2951 < n_ssp_2951; i_ssp_2951++)
    {
        if (arr_ssp_2951[i_ssp_2951] % 2 != 0)
        {
            for (j_ssp_2951 = i_ssp_2951 + 1; j_ssp_2951 < n_ssp_2951; j_ssp_2951++)
            {
                if (arr_ssp_2951[j_ssp_2951] % 2 == 0)
                {
                    temp_ssp_2951 = arr_ssp_2951[i_ssp_2951];
                    arr_ssp_2951[i_ssp_2951] = arr_ssp_2951[j_ssp_2951];
                    arr_ssp_2951[j_ssp_2951] = temp_ssp_2951;
                    break;
                }
            }
        }
    }
    printf("The rearranged array is: ");
    for (i_ssp_2951 = 0; i_ssp_2951 < n_ssp_2951; i_ssp_2951++)
        printf("%d ", arr_ssp_2951[i_ssp_2951]);
    return 0;
}