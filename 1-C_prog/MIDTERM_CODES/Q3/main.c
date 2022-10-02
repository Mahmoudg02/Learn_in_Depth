/*
 * main.c
 *
 *  Created on: 20 Aug 2022
 *      Author: MAshr
 */

/*
 * 3)c function to print all prime numbers between two numbers?
 *   test case : input:n1=1,n2=20 ->output:1 2 3 5 7 11 13 17 19
 */


#include <stdio.h>


void print_in_between(int n1 ,int n2);

int main(int argc, char **argv) {


	int test_n1 = 1 ;
	int test_n2 = 20 ;


	print_in_between(test_n1, test_n2);

}


void print_in_between(int n1 ,int n2){

	for (int i = n1 ; i<n2 ; i++){
		printf("%d   ",i);
	}
}
