#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main(int argc, char *argv[]){
	char buffer[1111111];
	int i;
	
	int bits = atoi(argv[1]);
	
	i = fread(&buffer, bits, 1, stdin);

	while (i>0){
		fwrite(&buffer, bits, 1, stdout);
		i = fread(&buffer, bits, 1, stdin);
	}
}
