#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int count = 0 ;
void calculate(int n){
	if( n == 1 ){
		count++ ;
	}
	int i = 2 ;
	while ( i<=n ){
		if( n%i == 0) {
			calculate( n/i ) ;
		}
		i++;
	}
}
int main()
{
	int n ;
	printf("随机生成一个正整数:") ;
	srand((unsigned)time(NULL));
 	n=rand()%(2147483647-200000000+1)+200000000;
 	printf("%d\n",n); 
	calculate( n ) ;
	printf("式子个数:%d\n", count) ;
	return 0 ;
}

