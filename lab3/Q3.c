/*To define an user defined function that is used to produce the rounded
matrix as described in the below example. Find out the time complexity of your
algorithm/function. Consider an n × n matrix A = (aij), each of whose elements aij is a non-
negative real number, and suppose that each row and column of A sums to an integer value. We
wish to replace each element aij with either ⌊a ij ⌋ or ⌈a ij ⌉ without disturbing the row and
column sums.*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int n_ssp_2951;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n_ssp_2951);

    double matrix_ssp_2951[n_ssp_2951][n_ssp_2951];
    int rounded_matrix_ssp_2951[n_ssp_2951][n_ssp_2951];

    // random matrix input

    for(int i=0; i<n_ssp_2951; i++){
        for(int j=0; j<n_ssp_2951; j++){
            matrix_ssp_2951[i][j]= (double) rand()/100;
        }
    }

    // Printing the matrix

    printf("\nmatrix:\n");
    for(int i=0; i<n_ssp_2951; i++){
        for(int j=0; j<n_ssp_2951; j++){
            printf("%lf ", matrix_ssp_2951[i][j]);
        }
        printf("\n");
    }

    // Rounding the matrix
    clock_t start,end;
    start=clock();
    for(int i=0; i<n_ssp_2951; i++){
        for(int j=0; j<n_ssp_2951; j++){
            double temp= matrix_ssp_2951[i][j] - (int) (matrix_ssp_2951[i][j]);
            if(temp>=0.5){
                rounded_matrix_ssp_2951[i][j]= (int) (matrix_ssp_2951[i][j]) + 1;
            }
            else{
                rounded_matrix_ssp_2951[i][j]= (int) (matrix_ssp_2951[i][j]);
            }
        }
    }
    end=clock();
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("The time taken to round the matrix is %f\n",time_taken);

    // Printing the rounded matrix

    printf("\nRounded matrix:\n");
    for(int i=0; i<n_ssp_2951; i++){
        for(int j=0; j<n_ssp_2951; j++){
            printf("%d ", rounded_matrix_ssp_2951[i][j]);
        }
        printf("\n");
    }
}