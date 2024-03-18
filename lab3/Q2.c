/*Rewrite the program for Experiment 1 (Insertion Sort) with the
following details.
i. Compare the best case, worst case and average case time complexity with the same data except
time complexity will be calculated by the count of the CPU clock time.
ii. Plot a graph showing the above comparison (n, the input data Vs. CPU times for best, worst &amp;
average case)
iii. Compare manually Experiment 1 graph vs Experiment 2 graph and draw your inference.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int count=0;
void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        count++;
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            count++;
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    printf("Enter the size of the array");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the operation you want");
    printf("0. Quit\n1. n Random numbers=>Array\n2. Display the Array\n3. Sort the Array in Ascending Order by using Insertion Sort Algorithm\n4. Sort the Array in Descending Order by using any sorting algorithm\n5. Time Complexity to sort ascending of random data\n6. Time Complexity to sort ascending of data already sorted in ascending order\n7. Time Complexity to sort ascending of data already sorted in descending order\n8. Time Complexity to sort ascending of data for all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000");
    int p=100;
    while(p!=0){
        printf("\nEnter the operation you want\n");
        scanf("%d",&p);
        switch(p){
            case 0:
                break;
            case 1:
                for(int i=0;i<n;i++){
                    arr[i]=rand()%100;
                }
                break;
            case 2:
                for(int i=0;i<n;i++){
                    printf("%d ",arr[i]);
                }
                break;
            case 3: 
                insertion_sort(arr,n);
                display(arr,n);
                break;
            case 4: 
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(arr[i]>arr[j]){
                            int temp=arr[i];
                            arr[i]=arr[j];
                            arr[j]=temp;
                        }
                    }
                }
                display(arr,n);
                break;
            case 5:
                for(int i=0;i<n;i++){
                    arr[i]=rand()%100;
                }
                clock_t start,end;
                start=clock();
                insertion_sort(arr,n);
                end=clock();
                printf("Time taken to sort random data is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                break;
            case 6:
                for(int i=0;i<n;i++){
                    arr[i]=i;
                }
                start=clock();
                insertion_sort(arr,n);
                end=clock();
                printf("Time taken to sort ascending data is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                break;
            case 7:
                for(int i=0;i<n;i++){
                    arr[i]=n-i;
                }
                start=clock();
                insertion_sort(arr,n);
                end=clock();
                printf("Time taken to sort descending data is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                break;
            case 8:
                int m=5000;
                while(m<50001){

                    printf("\nThe size of the array is %d",m);
                    int array[m];
                    for(int i=0;i<m;i++){
                        array[i]=rand()%100;
                    }
                    printf("\n");
                    count=0;
                    insertion_sort(array,m);
                    printf("The count to sort random array is %d\n",count);
                    count=0;
                    insertion_sort(array,m);
                    printf("The count to sort ascending array to ascending is %d\n",count);

                    for(int i=0;i<m;i++){
                        for(int j=0;j<m;j++){
                            if(array[i]>array[j]){
                                int temp=array[i];
                                array[i]=array[j];
                                array[j]=temp;
                            }
                        }
                    }
                    count=0;
                    insertion_sort(array,m);
                    printf("The count for sorting an array in decreasing order to ascending is %d\n",count);
                    m+=5000;
               }
                break;
            default:
                printf("Enter a valid option");
        }
    }
    return 0;
}