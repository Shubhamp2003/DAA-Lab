/*Write a program to sort a list of n elements using the quick sort method
and determine the time required to sort the elements. Repeat the experiment for different values
of n and different nature of data (random data, sorted data, reversely sorted data, all same
elements data) in the list. n is the user input and n integers can be generated randomly. Finally
plot a graph of the time taken versus n.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void quick_sort(int arr[],int l,int r){
    if(l<r){
        int pivot=partition(arr,l,r);
        quick_sort(arr,l,pivot-1);
        quick_sort(arr,pivot+1,r);
    }
}
int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;
    return i+1; 
}
 int main(){
      clock_t start,end;
      int m=5000;
               while(m<50000){
                printf("\nThe size of the array is %d",m);
                int array[m];
                for(int i=0;i<m;i++){
                    array[i]=rand()%100;
                }
                printf("\n");
                start=clock();
                quick_sort(array,0,m-1);
                end=clock();
                printf("The time taken to sort random array is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                
                start=clock();
                quick_sort(array,0,m-1);
                end=clock();
                printf("The time taken to sort ascending array to ascending is %f\n",(double)(end-start)/CLOCKS_PER_SEC);

                for(int i=0;i<m;i++){
                    for(int j=0;j<m;j++){
                        if(array[i]>array[j]){
                            int temp=array[i];
                            array[i]=array[j];
                            array[j]=temp;
                        }
                    }
                }
                start=clock();
                quick_sort(array,0,m-1);
                end=clock();
                printf("The time taken for sorting an array in decreasing order to ascending is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                m+=5000;
               }
}