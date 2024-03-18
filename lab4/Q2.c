/*Write a program to sort a list of n elements using the merge sort
method and determine the time required to sort the elements. Repeat the experiment for different
values of n and different nature of data (random data, sorted data, reversely sorted data) in the
list. n is the user input and n integers can be generated randomly. Finally plot a graph of the time
taken versus n.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void merge(int arr[],int ,int,int);
void merge_sort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
void merge(int arr[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }
}
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
      clock_t start,end;
      int m=5000;
               while(m<50001){
                printf("\nThe size of the array is %d",m);
                int array[m];
                for(int i=0;i<m;i++){
                    array[i]=rand()%100;
                }
                printf("\n");
                start=clock();
                merge_sort(array,0,m-1);
                end=clock();
                printf("The time taken to sort random array is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                
                start=clock();
                merge_sort(array,0,m-1);
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
                merge_sort(array,0,m-1);
                end=clock();
                printf("The time taken for sorting an array in decreasing order to ascending is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
                m+=5000;
               }
}