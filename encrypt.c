#include <stdio.h>
#include <stdlib.h>

#define KEY 0xD8
int main(int argc, char **argv)
{
	char buf[1024]; 

	if (argc !=3) {
		fprintf(stderr, "missing argument\n"); 
		exit(1); 
	}

	FILE *fp, *fpw; 

	fp = fopen(argv[1], "r"); 
    fpw = fopen(argv[2], "w"); 

	if (fp && fpw) {
		while (!feof(fp)) {
			int count, i; 
			count = fread(buf, 1, 1024, fp); 
			for (i = 0; i<count; i++)
				buf[i] ^= KEY; 
			fwrite(buf, 1, count, fpw); 
		}
		fclose(fp); 
		fclose(fpw); 
	}
	exit(0); 	
}
