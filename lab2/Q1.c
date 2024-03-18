/*To test whether a number n_ssp_2951, entered through keyboard is prime or not
by using different algorithms you know for at-least 10 inputs and note 
down the time complexity by step/frequency count_ssp_2951 method for each 
algorithm & for each input. Finally make a comparison of time 
complexities found for different inputs, plot an appropriate graph &amp; 
decide which algorithm is faster.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void method1_ssp_2951(int n_ssp_2951){
    int count_ssp_2951=0;
    printf("Algorithm 1\n");
    int flag_ssp_2951=0;
    for(int i_ssp_2951=2 ; i_ssp_2951<n_ssp_2951 ; i_ssp_2951++){
        count_ssp_2951++;
        if(n_ssp_2951 % i_ssp_2951==0){
            flag_ssp_2951=1;
            break;
        }

    }
    if(flag_ssp_2951==0){
        printf("Prime\n");
    }
    else{
        printf("Not Prime\n");
    }
  printf("the count is :%d\n",count_ssp_2951);
}

void method2_ssp_2951(int n_ssp_2951){
    printf("Algorithm 2\n");
    int count_ssp_2951=0;
    int flag_ssp_2951=0;
    for(int i_ssp_2951=2 ; i_ssp_2951<n_ssp_2951/2 ; i_ssp_2951++){
        count_ssp_2951++;
        if(n_ssp_2951%i_ssp_2951 == 0){
            flag_ssp_2951=1;
            break;
        }
    }
   if(flag_ssp_2951 == 0){
        printf("Prime\n");
    }
    else{
        printf("Not Prime\n");
    }
   printf("the count is :%d\n",count_ssp_2951);
}

void method3_ssp_2951(int n_ssp_2951){
    printf("Algorithm 3\n");
        int count_ssp_2951=0;
        int flag_ssp_2951=0;
        for(int j=2 ; j<=sqrt(n_ssp_2951) ; j++){
        count_ssp_2951++;
        if(n_ssp_2951%j==0){
            flag_ssp_2951=1;
            break;
        }
    }
    if(flag_ssp_2951==0){
        printf("Prime\n");
    }
    else{
        printf("Not Prime\n");
    }
    printf("the count is :%d\n",count_ssp_2951);
}

int main(){
    int n_ssp_2951;
    printf("Enter the number\n");
    scanf("%d",&n_ssp_2951);
    printf("\n");
    method1_ssp_2951(n_ssp_2951);
    method2_ssp_2951(n_ssp_2951);
    method3_ssp_2951(n_ssp_2951);
   
}