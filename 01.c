#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	int fd;

	char buf[10];
	ssize_t nr_bytes;

	fd = open("01.txt", O_RDONLY);

	if(fd == -1)
		printf("%s\n", "Error al abrir el archivo!. \n");
	else{
		nr_bytes = read(fd, buf, 5);
		close(fd);

		if(nr_bytes == 0)
			printf("%s\n", "archivo vacio!. \n");
		else
			printf("El numero de caracteres es %d, contenido: %s \n", (int)nr_bytes, buf);
	}

	return 0;
}