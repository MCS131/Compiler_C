/***** error.c  **************************/

#include "global_0.h"

/*** generates all error message ***/
int error(char *m)  
{
	fprintf(stderr, "line %d: %s\n", lineno, m);
	return 1;	/* unsucsessful termination */
}
