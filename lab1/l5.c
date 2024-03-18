/*To take A an n*n square matrix array as an input and then WAP by
using appropriate user defined functions for the following:
a) Find the number of nonzero elements in A
b) Find the sum of the elements above the leading diagonal.
c) Display the elements below the minor diagonal.
d) Find the product of the diagonal elements.*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n_ssp_2951;
    printf("Enter the size of array: ");
    scanf("%d",&n_ssp_2951);
    int arr_ssp_2951[n_ssp_2951][n_ssp_2951];
    printf("Enter the elements of array: ");
    for(int i_ssp_2951=0;i_ssp_2951<n_ssp_2951;i_ssp_2951++)
    {
        for(int j_ssp_2951=0;j_ssp_2951<n_ssp_2951;j_ssp_2951++)
        {
            scanf("%d",&arr_ssp_2951[i_ssp_2951][j_ssp_2951]);
        }
    }
    int count_ssp_2951=0;
    for(int i_ssp_2951=0;i_ssp_2951<n_ssp_2951;i_ssp_2951++)
    {
        for(int j_ssp_2951=0;j_ssp_2951<n_ssp_2951;j_ssp_2951++)
        {
            if(arr_ssp_2951[i_ssp_2951][j_ssp_2951]!=0)
                count_ssp_2951++;
        }
    }
    printf("The number of non-zero elements in the matrix is %d\n",count_ssp_2951);
    int sum_ssp_2951=0;
    for(int i_ssp_2951=0;i_ssp_2951<n_ssp_2951;i_ssp_2951++)
    {
        for(int j_ssp_2951=0;j_ssp_2951<n_ssp_2951;j_ssp_2951++)
        {
            if(i_ssp_2951<j_ssp_2951)
                sum_ssp_2951+=arr_ssp_2951[i_ssp_2951][j_ssp_2951];
        }
    }
    printf("The sum of the elements above the leading diagonal is %d\n",sum_ssp_2951);
    printf("The elements below the minor diagonal are: ");
    for(int i_ssp_2951=0;i_ssp_2951<n_ssp_2951;i_ssp_2951++)
    {
        for(int j_ssp_2951=0;j_ssp_2951<n_ssp_2951;j_ssp_2951++)
        {
            if(i_ssp_2951+j_ssp_2951>n_ssp_2951-1)
                printf("%d ",arr_ssp_2951[i_ssp_2951][j_ssp_2951]);
        }
    }
    printf("\n");
    int product_ssp_2951=1;
    for(int i_ssp_2951=0;i_ssp_2951<n_ssp_2951;i_ssp_2951++)
    {
        for(int j_ssp_2951=0;j_ssp_2951<n_ssp_2951;j_ssp_2951++)
        {
            if(i_ssp_2951==j_ssp_2951)
                product_ssp_2951*=arr_ssp_2951[i_ssp_2951][j_ssp_2951];
        }
    }
    printf("The product of the diagonal elements is %d\n",product_ssp_2951);
    return 0;
}