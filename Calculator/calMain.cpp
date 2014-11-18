#include "Calculate.h"
#include <errno.h>
int main(int argc ,char * argv[])
{
	CALC_ERR error = CALC_NO_ERR;

	if (argc != 2)
		{
			fprintf(stderr , "Enter 1 file\n");
			return COMAND_ERR;
		}

	FILE * file = fopen (argv[1] , "r");
	if (file == NULL) 
	{
		fprintf(stderr , "Error file\n");
		return FILE_ERR;
	}

	element_type answer = 0;
	error = calculator (file , &answer);
	if (error == CALC_NO_ERR)
		printf("%lg\n", answer);
	else
		writeErr(error);
	
	fclose (file);

	return 0;
}
