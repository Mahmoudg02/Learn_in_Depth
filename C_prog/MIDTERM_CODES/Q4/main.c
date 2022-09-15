/*
 * main.c
 *
 *  Created on: 20 Aug 2022
 *      Author: MAshr
 */

/*
 * 4)c function to reverse digits in number?
  test case 1: input:2457 -> output:7542 .
   test case 2: input:1057 -> output:7501.
 */


#include <stdio.h>


int reverse_digits(int n);

int main(int argc, char **argv) {


	int test_n1 = 2475 ;
	int test_n2 = 1057 ;


printf("%d\n",reverse_digits(test_n1));
printf("%d\n",reverse_digits(test_n2));


}


int reverse_digits(int n){
	int temp =0 ;
	while (n){
		temp*=10 ;
		temp+=n%10 ;
		n/=10 ;
	}
	return temp ;
}
