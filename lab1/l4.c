/*To take three variable (a, b, c) as separate parameters and swap the
values stored so that value a goes to b, b to c and c to a by using a SWAP(x,y)
function that swaps/exchanges the numbers x & y.*/
 #include <stdio.h>

 void swap(int *p_ssp_2951,int *q_ssp_2951){
    int temp_ssp_2951 = *p_ssp_2951;
    *p_ssp_2951=*q_ssp_2951;
    *q_ssp_2951=temp_ssp_2951;
 }

 int main(){
    int x_ssp_2951,y_ssp_2951,z_ssp_2951;
    printf("Enter three numbers ");
    scanf("%d %d %d",&x_ssp_2951,&y_ssp_2951,&z_ssp_2951);

    printf("Before Swapping :\n %d,%d,%d\n",x_ssp_2951,y_ssp_2951,z_ssp_2951);
    

    swap(&z_ssp_2951,&x_ssp_2951);
    swap(&z_ssp_2951,&y_ssp_2951);

    printf("After Swapping :\n %d,%d,%d",x_ssp_2951,y_ssp_2951,z_ssp_2951);
 }