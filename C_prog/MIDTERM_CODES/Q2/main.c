/*
 * main.c
 *
 *  Created on: 20 Aug 2022
 *      Author: MAshr
 */

/*
 * 2)c function to take an integer number and calculate it's square root?
 *   test case 1:  input:10 ->output:3.126
 *   test case 2: input:4 ->output:2.000
 */


#include <stdio.h>


double calc_sqr(int num) ;

int main(int argc, char **argv) {


	int test_case1 =10 ;
	int test_case2= 4 ;


	printf("%.3f\n",calc_sqr(test_case1)) ;
	printf("%.3f\n",calc_sqr(test_case2)) ;


}


double calc_sqr(int num) {


	if (num < 0)
	{
		printf("invalid number");
		return 0 ;
	}

	double lower_bound=0;
	double upper_bound=num;
	double temp=0;

	int nCount = 50;
	while(nCount != 0)
	{
		temp=(lower_bound+upper_bound)/2;
		if(temp*temp==num)
		{
			return temp;
		}
		else if(temp*temp > num)

		{
			upper_bound = temp;
		}
		else
		{
			lower_bound = temp;
		}
		nCount--;
	}
	return temp;

}
