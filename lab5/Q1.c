/* Write a menu driven program as given below, to sort an array of n integers in ascending order by 
heapify sort algorithm and determine the time required (in terms of step/frequency count) to sort the elements.
Repeat the experiment for different values of n and different nature of data (i.e.apply heapify sort algorithm
on the data of array that are already sorted, reversely sorted and random data). Finally plot a graph of the time 
taken versus n for each type of data. The elements can be read from a file or can be generated using the random number generator.
Depending on the nature of data what is your conclusion about the time taken by each set of data. Can you justify your conclusion.
0. Quit
1. n Random numbers=>Array
2. Display the Array
3. Sort the Array in Ascending Order by using Max-Heap Sort technique
4. Sort the Array in Descending Order by using any algorithm
5. Time Complexity to sort ascending of random data
6. Time Complexity to sort ascending of data already sorted in ascending order
7. Time Complexity to sort ascending of data already sorted in descending order
8. Time Complexity to sort ascending all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000
9. Extract largest element
10. Replace value at a node with new value
11. Insert a new element
12. Delete an element
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr_2951[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr_2951[l]>arr_2951[largest]){
        largest=l;
    }
    if(r<n && arr_2951[r]>arr_2951[largest]){
        largest=r;
    }
    if(largest!=i){
        int temp=arr_2951[i];
        arr_2951[i]=arr_2951[largest];
        arr_2951[largest]=temp;
        heapify(arr_2951,n,largest);
    }
}

void heap_sort(int arr_2951[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr_2951,n,i);
    }
    for(int i=n-1;i>=0;i--){
        int temp=arr_2951[0];
        arr_2951[0]=arr_2951[i];
        arr_2951[i]=temp;
        heapify(arr_2951,i,0);
    }
}



void display(int arr_2951[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr_2951[i]);
    }
}
int main(){
    printf("Enter the size of the array : ");
    int n;
    scanf("%d",&n);
    int arr_2951[n];
    printf("Enter the operation you want\n");
    printf("0. Quit\n1. n Random numbers=>Array\n2. Display the Array\n3. Sort the Array in Ascending Order by using heap Sort Algorithm\n4. Sort the Array in Descending Order by using any sorting algorithm\n5. Time Complexity to sort ascending of random data\n6. Time Complexity to sort ascending of data already sorted in ascending order\n7. Time Complexity to sort ascending of data already sorted in descending order\n8. Time Complexity to sort ascending of data for all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000");
    printf("\n9. Extract largest element\n10. Replace value at a node with new value\n11. Insert a new element\n12. Delete an element\n");
    int p=100;
    while(p!=0){
        printf("\nEnter the operation you want\n");
        scanf("%d",&p);
        switch(p){
            case 0:
                break;
            case 1:
                for(int i=0;i<n;i++){
                    arr_2951[i]=rand()%100;
                }
                break;
            case 2:
                for(int i=0;i<n;i++){
                    printf("%d ",arr_2951[i]);
                }
                break;
            case 3: 
                heap_sort(arr_2951,n);
                display(arr_2951,n);
                break;
            case 4: 
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(arr_2951[i]>arr_2951[j]){
                            int temp_2951=arr_2951[i];
                            arr_2951[i]=arr_2951[j];
                            arr_2951[j]=temp_2951;
                        }
                    }
                }
            case 5: ;
                clock_t start,end;
                start=clock();
                heap_sort(arr_2951,n);
                end=clock();
                display(arr_2951,n);
                printf("The time taken to sort random array is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                break;
                
            case 6: 

                heap_sort(arr_2951,n);
                start=clock();
                heap_sort(arr_2951,n);
                end=clock();
                display(arr_2951,n);
                printf("The time taken for sortign already sorted array is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                break;
                
            case 7: 
                 for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(arr_2951[i]>arr_2951[j]){
                            int temp=arr_2951[i];
                            arr_2951[i]=arr_2951[j];
                            arr_2951[j]=temp;
                        }
                    }
                }
                start=clock();
                heap_sort(arr_2951,n);
                end=clock();
                display(arr_2951,n);
                printf("The time taken for sorting an array in decreasing order to ascending is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                break;
            case 8: ;
               int m=5000;
               while(m<50001){
                printf("\nThe size of the array is %d",m);
                int array[m];
                for(int i=0;i<m;i++){
                    array[i]=rand()%100;
                }
                printf("\n");
                start=clock();
                heap_sort(array,m);
                end=clock();
                printf("The time taken to sort random array is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                
                start=clock();
                heap_sort(array,m);
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
                heap_sort(array,m);
                end=clock();
                printf("The time taken for sorting an array in decreasing order to ascending is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                m+=5000;
               }
                break;
            case 9:
                heap_sort(arr_2951,n);
                printf("The largest element is %d",arr_2951[n-1]);
                break;
            
            case 10:
                printf("Enter the node you want to replace : ");
                int node;
                scanf("%d",&node);
                printf("Enter the new value : ");
                int new_value;
                scanf("%d",&new_value);
                arr_2951[node]=new_value;
                break;

            case 11:
                printf("Enter the new element you want to insert : ");
                int new_element;
                scanf("%d",&new_element);
                arr_2951[n]=new_element;
                n++;
                break;
            case 12:
                printf("Enter the element you want to delete : ");
                int delete_element;
                scanf("%d",&delete_element);
                for(int i=0;i<n;i++){
                    if(arr_2951[i]==delete_element){
                        for(int j=i;j<n;j++){
                            arr_2951[j]=arr_2951[j+1];
                        }
                        n--;
                    }
                }
                break;
            default:
                printf("Enter a valid operation");
        
        }
    
    }

}