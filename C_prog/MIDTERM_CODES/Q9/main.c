/*
 * main.c
 *
 *  Created on: 20 Aug 2022
 *      Author: MAshr
 */

/*
 * 9)c function to reverse words in string?
   test case :   input: mohamed gamal. output:gamal mohamed.
 *
 */


#include <stdio.h>


void max_ones(char arr[] );

int main(int argc, char **argv) {

	char case1[100] = " mahmoud ashraf farouk" ;

	max_ones(case1);

}


void max_ones(char arr[] ){

	int size=0  ;
	char temp[50];


	while (arr[size])
		size++ ;
	size -- ;

	int i , j, k=0;

	for (i = size ;i>=0; i--)
	{
		if (arr[i]==' ')
		{
			for (j=i ;j<size ;j++){

				temp[k]=arr[j+1];
				k++ ;
			}
			temp[k]=' '; k++ ;
			size=i ;

		}

	}
	temp[k]=0 ;
	printf("%s",temp);

}







