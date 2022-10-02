/*
 * main.c
 *
 *  Created on: 20 Aug 2022
 *      Author: MAshr
 */

/*
 * 6)c function to return unique number in array with one loop?
 *  test case 1:input:  int a[7]={4,2,5,2,5,7,4}; output:7.
 *  test case 2:input: int a[3]={4,2,4};    output:2.
 *
 */


#include <stdio.h>


int get_unique(int arr[], int size );

int main(int argc, char **argv) {


	int case1[]={4,2,5,2,5,7,4} ;
	int case2[]={4,2,4} ;


	printf("%d\n",get_unique(case1,sizeof(case1)/sizeof(int)));
	printf("%d\n",get_unique(case2,sizeof(case2)/sizeof(int)));


}


int get_unique(int arr[],int size){

	int unique_val=0 ;

	for (int i =0 ;i<size;i++)
	{
		unique_val^=arr[i];
	}

	return unique_val ;

}







