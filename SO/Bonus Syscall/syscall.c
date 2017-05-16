#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main(int argc, char *argv[]){
	char buffer[1111111];
	int i;
	
	int bits = atoi(argv[1]);
	
	i = read(0,&buffer,bits);

	while (i>0){
		write(1,&buffer,bits);
		i = read(0,&buffer,bits);
	}
}
