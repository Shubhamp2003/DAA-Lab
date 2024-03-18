/* To write a program to implement the activity-selection problem. You are given n activities with their start and finish times.
Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input: Consider the following 6 activities ( 0, 1, 2, 3, 4, 5). start[] = {1, 3, 0, 5, 8, 5}; finish[] = {2, 4, 6, 7, 9, 9}
Output: The maximum set of activities that can be executed by a single person is {0, 1, 3, 4}.*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int activity[6] = {0, 1, 2, 3, 4, 5};
    int start[6] = {1, 3, 0, 5, 8, 5};
    int finish[6] = {2, 4, 6, 7, 9, 9};
    int n = 6;
    int ans[7]={0};

    //arrange on the basis of finish time 
    for(int i=0;i<6;i++){
        for(int j=i;j<6;j++){
            if(finish[i] > finish[j] ){
                int temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;

                temp = activity[i];
                activity[i] = activity[j];
                activity[j] = temp;
            }
        }
    }

    //display the table
    printf("Activity\tStart\tFinish\n");
    for(int i=0;i<6;i++){
        printf("%d\t\t%d\t%d\n", activity[i], start[i], finish[i]);
    }
    ans[0] = activity[0];
    int k=1;
    for(int i=1;i<7;i++){
        if(start[i] >= finish[k-1]){
            ans[k] = activity[i];
            k++;
        }
    }
    printf("The maximum set of activities that can be executed by a single person is:\n");
    for(int i=0;i<7;i++){
        printf("%d\t", ans[i]);
    }

}