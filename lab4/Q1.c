/*Write a program to search an element x in an array of n integers using
binary search algorithm that uses divide and conquer technique. Find out the best case, worst
case and average case time complexities for different values of n and plot a graph of the time
taken versus n. The n integers can be generated randomly and x can be chosen randomly, or any
element of the array or middle or last element of the array depending on type of time complexity
analysis.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int count=0;
int binary_search(int arr[],int n,int x){
    int l=0;
    int r=n-1;
    while(l<=r){
        count++;
        int mid=(l+r)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]>x){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}
int main(){
    clock_t start,end;
    FILE* fptr,*farr;
    fptr = fopen("file.txt", "w");
    farr=fopen("file.txt","r");
    int n=5000;
    while (n<=50000)
    {
        printf("For n=%d",n);
        //writing in file
        for(int i=0;i<n;i++){
            fprintf(fptr,"%d ",i);
        }     
        int array[n];
        //reading from file
        for (int i = 0; i < n; i++)
        {
          fscanf(farr,"%d",&array[i]);
        }
        printf("\n");
        int s=array[0];
        int e=array[rand()%n];
        int m=array[(n-1)/2]; 
        //searching first element
        count=0;
        start=clock();
        binary_search(array,n,s);
        end=clock();
        double time_taken = ((double)end - start)/CLOCKS_PER_SEC;
        printf("Time taken for searching first element(worst case) is %f\n",time_taken);
        //searching random element
        count=0;
        start=clock();
        binary_search(array,n,e);
        end=clock();
        time_taken = ((double)end - start)/CLOCKS_PER_SEC;
        printf("Time taken for searching random element(average case) is %f \n",time_taken);
        count=0;
        //searching middle element
        start=clock();
        binary_search(array,n,m);
        end=clock();
        time_taken = ((double)end - start)/CLOCKS_PER_SEC;
        printf("Time taken for searching middle element(best case) is %f \n",time_taken);
        n+=5000;
    }
    return 0;
}