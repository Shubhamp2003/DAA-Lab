/*To write a program to implementation of Fractional Knapsack algorithm.
Input: 
Weight: <10, 5, 15, 7, 6 ,18, 3>   Value: <2, 3, 5, 7, 1, 4, 1>
Capacity of Knapsack: 5 * Your Roll MOD 10*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    float weight[7]= {10, 5, 15, 7, 6 ,18, 3};
    float value[7]= {2, 3, 5, 7, 1, 4, 1};
    float capacity = 5 * 4;
    float valuePerWeight[7];
    for(int i=0;i<7;i++){
        valuePerWeight[i] = value[i]/weight[i];
    }   
    printf("The capacity of knapsack is :%.2f\n", capacity);
    //sort on decreasing order of weight/value
    for(int i=0;i<7;i++){
        for(int j=i+1;j<7;j++){
            if(valuePerWeight[i]<valuePerWeight[j]){
                float temp = valuePerWeight[i];
                valuePerWeight[i] = valuePerWeight[j];
                valuePerWeight[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = value[i];
                value[i] = value[j];
                value[j] = temp;
            }
        }
    }
    //display as a table all the array
    printf("Weight\t\tValue\t\tValue/Weight\n");
    for(int i=0;i<7;i++){
        printf("%f\t%f\t%f\n", weight[i], value[i], valuePerWeight[i]);
    }


    float ans[7]={0};
    int i=0;
    while(capacity>0){
        if(weight[i]<=capacity){
            ans[i] = 1;
            capacity -= weight[i];
        }
        else{
            ans[i] = capacity/weight[i];
            capacity = 0;
            break;
        }
        i++;
    }
    printf("Fraction of item to be taken according to value/weight is:\n");
    for(int i=0;i<7;i++){
        printf("%f\t", ans[i]);
    }

}