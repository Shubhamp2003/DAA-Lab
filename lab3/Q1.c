/* Write a menu driven program as given below, to sort an array of n integers in ascending order by 
insertion sort algorithm and determine the time required (in terms of step/frequency count) to sort the elements.
Repeat the experiment for different values of n and different nature of data (i.e.apply insertion sort algorithm
on the data of array that are already sorted, reversely sorted and random data). Finally plot a graph of the time 
taken versus n for each type of data. The elements can be read from a file or can be generated using the random number generator.
Depending on the nature of data what is your conclusion about the time taken by each set of data. Can you justify your conclusion.
0. Quit
1. n Random numbers=>Array
2. Display the Array
3. Sort the Array in Ascending Order by using Insertion Sort Algorithm
4. Sort the Array in Descending Order by using any sorting algorithm
5. Time Complexity to sort ascending of random data
6. Time Complexity to sort ascending of data already sorted in ascending order
7. Time Complexity to sort ascending of data already sorted in descending order
8. Time Complexity to sort ascending of data for all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void insertion_sort_ssp_2951(int arr[],int n_ssp_2951){
    for(int i=1;i<n_ssp_2951;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void display_ssp_2951(int arr[],int n_ssp_2951){
    for(int i=0;i<n_ssp_2951;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    printf("Enter the size of the array");
    int n_ssp_2951;
    scanf("%d",&n_ssp_2951);
    int arr[n_ssp_2951];
    printf("Enter the operation you want");
    printf("0. Quit\n1. n Random numbers=>Array\n2. Display the Array\n3. Sort the Array in Ascending Order by using Insertion Sort Algorithm\n4. Sort the Array in Descending Order by using any sorting algorithm\n5. Time Complexity to sort ascending of random data\n6. Time Complexity to sort ascending of data already sorted in ascending order\n7. Time Complexity to sort ascending of data already sorted in descending order\n8. Time Complexity to sort ascending of data for all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n_ssp_2951=5000 to 50000, step=5000");
    int p=100;

    while(p!=0){
        printf("\nEnter the operation you want\n");
        scanf("%d",&p);
        switch(p){
            case 0:
                break;
            case 1:
                for(int i=0;i<n_ssp_2951;i++){
                    arr[i]=rand()%100;
                }
                break;
            case 2:
                for(int i=0;i<n_ssp_2951;i++){
                    printf("%d ",arr[i]);
                }
                break;
            case 3: 
                insertion_sort_ssp_2951(arr,n_ssp_2951);
                display_ssp_2951(arr,n_ssp_2951);
                break;
            case 4: 
                for(int i=0;i<n_ssp_2951;i++){
                    for(int j=0;j<n_ssp_2951;j++){
                        if(arr[i]>arr[j]){
                            int temp=arr[i];
                            arr[i]=arr[j];
                            arr[j]=temp;
                        }
                    }
                }
            case 5: ;
                clock_t start,end;
               
                start=clock();
                insertion_sort_ssp_2951(arr,n_ssp_2951);
                end=clock();
                display_ssp_2951(arr,n_ssp_2951);
                printf("The time taken to sort random array is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                break;
                
            case 6: 

                insertion_sort_ssp_2951(arr,n_ssp_2951);
                start=clock();
                insertion_sort_ssp_2951(arr,n_ssp_2951);
                end=clock();
                display_ssp_2951(arr,n_ssp_2951);
                printf("The time taken for sortign already sorted array is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                break;
                
            case 7: 
                 for(int i=0;i<n_ssp_2951;i++){
                    for(int j=0;j<n_ssp_2951;j++){
                        if(arr[i]>arr[j]){
                            int temp=arr[i];
                            arr[i]=arr[j];
                            arr[j]=temp;
                        }
                    }
                }
                start=clock();
                insertion_sort_ssp_2951(arr,n_ssp_2951);
                end=clock();
                display_ssp_2951(arr,n_ssp_2951);
                printf("The time taken for sorting an array in decreasing order to ascending is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                break;
            case 8: ;
               int m = 5000;
               while(m<50001){

                printf("The size of the array is %d\n",m);
                int array[m];

                for(int i=0;i<m;i++){
                    array[i]=rand()%100;
                }
                start=clock();
                insertion_sort_ssp_2951(array,m);
                end=clock();
                printf("The time taken to sort random array is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                
                start=clock();
                insertion_sort_ssp_2951(array,m);
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
                insertion_sort_ssp_2951(array,m);
                end=clock();
                printf("The time taken for sorting an array in decreasing order to ascending is %f\n\n",(double)(end-start)/CLOCKS_PER_SEC);
                m+=5000;

               }
                break;

            default:
                printf("Enter a valid operation");
        
        }
    
    }

}