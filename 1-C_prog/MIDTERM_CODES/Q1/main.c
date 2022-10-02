/*
 * main.c
 *
 *  Created on: 20 Aug 2022
 *      Author: MAshr
 */

/*
 * 1)c function to take a number and sum all digits?
 *   test case 1: input:123 ->output:6
 *  test case 2: input:4565 ->output:20
 */


#include <stdio.h>


int sum_digits(int num) ;

int main(int argc, char **argv) {


	 int test_case1 =123 ;
	 int test_case2= 4565 ;

	 printf("%d\n",sum_digits(test_case1)) ;
	 printf("%d\n",sum_digits(test_case2)) ;


}


int sum_digits(int num) {

	int sum = 0 ;
	while (num){
		sum+=num%10 ;
		num/=10 ;
	}

	return sum ;

}
