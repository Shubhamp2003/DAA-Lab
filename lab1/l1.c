/*To store random numbers into an array of N integers 
and then find out the smallest and largest number in it.
N is the user input.*/
#include <stdio.h>

int main(){
    int max_ssp_2951;
    int min_ssp_2951;
    int n_ssp_2951;
    printf("Enter the number of elements : ");
    scanf("%d",&n_ssp_2951);
    int arr_ssp_2951[n_ssp_2951];
    printf("The random array elements are as follows: ");
    
    for(int i_ssp_2951=0;i_ssp_2951<n_ssp_2951;i_ssp_2951++){ 
        scanf("%d",&arr_ssp_2951[i_ssp_2951]);
    }
    max_ssp_2951=arr_ssp_2951[0];
    min_ssp_2951=arr_ssp_2951[0];

    for(int i_ssp_2951=0;i_ssp_2951<n_ssp_2951;i_ssp_2951++){
        if(arr_ssp_2951[i_ssp_2951] < min_ssp_2951){
            min_ssp_2951=arr_ssp_2951[i_ssp_2951];
        }
        if(arr_ssp_2951[i_ssp_2951] > max_ssp_2951){
            max_ssp_2951=arr_ssp_2951[i_ssp_2951];
        }
    }

    printf("\nAmong the random elements:");
    printf("\nMaximum = %d \nMinimum = %d",max_ssp_2951,min_ssp_2951);
}