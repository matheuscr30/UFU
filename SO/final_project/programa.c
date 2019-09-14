#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int pid = atoi(argv[1]);
	long int x = syscall(335, pid);
	printf("Retorno da system call sys_projetopid: %ld\n", x);
	return 0;
}
