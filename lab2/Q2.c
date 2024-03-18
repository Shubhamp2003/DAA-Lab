/* To find out GCD (greatest common divisor) using the following three algorithms. 
a) Euclid’s algorithm 
b) Consecutive integer checking algorithm. 
c) Middle school procedure which makes use of common prime factors. For finding 
list of primes implement sieve of Eratosthenes algorithm*/

#include <stdio.h>
int count_gcd_ssp_2951=0;
int gcd_ssp_2951 (int a_ssp_2951,int b_ssp_2951){
    count_gcd_ssp_2951++;
    if (b_ssp_2951 == 0){
    return a_ssp_2951;
    }
    else{
    return gcd_ssp_2951(b_ssp_2951, a_ssp_2951%b_ssp_2951);
    }
}

int gcd2_ssp_2951(int a_ssp_2951,int b_ssp_2951){
    count_gcd_ssp_2951++;
    int gcd_ssp_2951=1;
    for(int i_ssp_2951=1;i_ssp_2951<=a_ssp_2951 && i_ssp_2951<=b_ssp_2951;i_ssp_2951++){
        if(a_ssp_2951%i_ssp_2951==0 && b_ssp_2951%i_ssp_2951==0){
            gcd_ssp_2951=i_ssp_2951;
        }
    }
    return gcd_ssp_2951;
}
//gcd using prime factors
void primefactors_ssp_2951(int n_ssp_2951,int primefactor_ssp_2951[])
{
    int index_ssp_2951=0;
	while (n_ssp_2951%2 == 0)
	{   
		primefactor_ssp_2951[index_ssp_2951]=2;
		n_ssp_2951 = n_ssp_2951/2;
        index_ssp_2951++;
	}
	for (int i_ssp_2951 = 3; i_ssp_2951*i_ssp_2951 <= n_ssp_2951; i_ssp_2951 = i_ssp_2951+2)
	{
		while (n_ssp_2951%i_ssp_2951 == 0)
		{
			primefactor_ssp_2951[index_ssp_2951]=i_ssp_2951;
			n_ssp_2951 = n_ssp_2951/i_ssp_2951;
            index_ssp_2951++;
		}
	}
	if (n_ssp_2951 > 2)
		primefactor_ssp_2951[index_ssp_2951]=n_ssp_2951;
}

int gcd3(int a_ssp_2951,int b_ssp_2951){
    int primefactor1[100];
    int primefactor2[100];
    for (int i_ssp_2951 = 0; i_ssp_2951 < 100; i_ssp_2951++)
    {
        primefactor1[i_ssp_2951]=1;
        primefactor2[i_ssp_2951]=1;
    }
    
    primefactors_ssp_2951(a_ssp_2951,primefactor1);
    primefactors_ssp_2951(b_ssp_2951,primefactor2);
    int gcd_ssp_2951=1;
    for(int i_ssp_2951=0;i_ssp_2951<100;i_ssp_2951++){
        for(int j=0;j<100;j++){
            count_gcd_ssp_2951++;
            if(primefactor1[i_ssp_2951]==primefactor2[j]){
                gcd_ssp_2951=gcd_ssp_2951*primefactor1[i_ssp_2951];
                primefactor1[i_ssp_2951]=1;
                primefactor2[j]=1;
            }
        }
    }
    return gcd_ssp_2951;
}
int main(){
    int a_ssp_2951,b_ssp_2951;
    printf("Enter two numbers: ");
    scanf("%d %d",&a_ssp_2951,&b_ssp_2951);
    printf("GCD of %d and %d is %d",a_ssp_2951,b_ssp_2951,gcd_ssp_2951(a_ssp_2951,b_ssp_2951));
    printf("\nCount is %d",count_gcd_ssp_2951);
    count_gcd_ssp_2951=0;
    printf("\nGCD of %d and %d is %d",a_ssp_2951,b_ssp_2951,gcd2_ssp_2951(a_ssp_2951,b_ssp_2951));
    printf("\nCount is %d\n",count_gcd_ssp_2951);
    count_gcd_ssp_2951=0;
    printf("\nGCD of %d and %d is %d",a_ssp_2951,b_ssp_2951,gcd3(a_ssp_2951,b_ssp_2951));
    printf("\nCount is %d\n",count_gcd_ssp_2951);
    return 0;
}