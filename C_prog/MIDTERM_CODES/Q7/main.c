/*
 * main.c
 *
 *  Created on: 20 Aug 2022
 *      Author: MAshr
 */

/*
 * 7)c function to sum numbers from 1 to 100(without loop)?

 *
 */


#include <stdio.h>


int sum_numbers_to(int num );

int main(int argc, char **argv) {



	printf("%d\n",sum_numbers_to(100));


}


int sum_numbers_to(int num ){

	static int sum = 0 ;

	while (num){
		sum+=num ;
		sum_numbers_to(--num) ;
		break ;
	}

	return sum  ;

}







