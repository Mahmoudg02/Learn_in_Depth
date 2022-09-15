/*
 * main.c
 *
 *  Created on: 20 Aug 2022
 *      Author: MAshr
 */

/*
 * 10)c function to count the max number of ones between two zeros?
 * test case 1:input:14(01110) output:3
 * test case 2: input:110(0110 1110). output:3
 */


#include <stdio.h>


int max_ones(int );

int main(int argc, char **argv) {

	int	case1=14 ;
	int case2 =110 ;
	printf("%d\n",max_ones(case1));
	printf("%d\n",max_ones(case2));

}


int max_ones(int num ){
	int max =0 , count =0 ;
	int j =0 ;
	while ((num&(1<<j))==1)
	{
		j++ ;
	}
	for ( ;j<sizeof(int)*8 ;j++)
	{
		if ((num&(1<<j)))
		{
			count ++ ;
			max=(count>max)?count:max ;
		}
		else
			count =0 ;

	}

	return max ;

}







