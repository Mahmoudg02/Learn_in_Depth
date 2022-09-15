/*
 * main.c
 *
 *  Created on: 20 Aug 2022
 *      Author: MAshr
 */

/*
 * 5)c function to count number of ones in binary number?
 test case 1: input:5 ->output: 2 --->binary of 5 is 0101 so has 2 one's
    test case 2 : input:15 -> output:4
 */


#include <stdio.h>


int get_ones(int n);

int main(int argc, char **argv) {


	int test_n1 = 5 ;
	int test_n2 = 15 ;


	printf("%d\n",get_ones(test_n1));
	printf("%d\n",get_ones(test_n2));


}


int get_ones(int n){
	int ones =0 ;

	for (int i= 0 ;i<sizeof(int)*8 ;i++){
		if ((n&1)==1)
			ones++ ;
		n>>=1 ;
	}

	return ones;

}
