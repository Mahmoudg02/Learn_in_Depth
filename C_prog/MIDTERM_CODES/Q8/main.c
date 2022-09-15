/*
 * main.c
 *
 *  Created on: 20 Aug 2022
 *      Author: MAshr
 */

/*
 * 8)c function to take an array and reverse its elements?
 *  test case 1:
 * input:   int a[5]={1,2,3,4,5}; output:5 4 3 2 1
 *
 */


#include <stdio.h>


void reverse_array(int arr[] , int size );

int main(int argc, char **argv) {

	int case1[]={1,2,3,4,5} ;

	for(int i = 0 ; i < sizeof(case1)/sizeof(int) ; i++)
		printf("%d  ",case1[i]);


	printf("\n") ;
	reverse_array(case1, sizeof(case1)/sizeof(int)) ;

	for(int i = 0 ; i < sizeof(case1)/sizeof(int) ; i++)
		printf("%d  ",case1[i]);
}


void reverse_array(int arr[] ,int size ){

	for (int i= 0,j = size-1 ; i<j ; i++, j--) {

		arr[i]=arr[i]^arr[j] ;
		arr[j]=arr[i]^arr[j] ;
		arr[i]=arr[i]^arr[j] ;

	}

}







