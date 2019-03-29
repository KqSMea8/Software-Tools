/*
 * example.cc
 */

#include <stdio.h>
#include <stdlib.h>
#include "example.h"

int main(int argc, char** argv){

	/*
	 * Provided main test program
	 */
	MySparseMatrix a(1000000,1000000);

	MySparseMatrix b;

	MySparseMatrix c;

	*a(1,1) = 27.0; *a(2,2) = 27.0; *a(3,3) = 27.0;

	b = a;
	c = a + b;
	
//	c.debug(stdout);
	c.debug();
	c.resize(10,10);
	*c(1,1) = -1.0;
	*c(10,10) = -1.0;
//	c.debug(stdout);
	c.debug();

	return 0;

}
