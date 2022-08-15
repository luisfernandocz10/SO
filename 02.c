/*
02.c
	fork(). Procesos padre, hijo, huérfano, zombie

	pid_t fork();

	- Crea un nuevo proceso ("hijo")
	- El proceso hijo es un duplicado del "padre"
	- Los dos procesos:
			- Tienen PIDs diferentes
			- Corren en espacios de memoria separados

	Retorno de dork()
		- Si todo va bien:
				- retorno al opadre: PID del hijo
				- retorno al hijo: 0
		- Si hay errores:
				- retorno al padre: -1
				 (el hijo no es creado)

	Para ver los procesos usar otra terminal y poner 
		ps lf
		kill -9 'pid'		// Mata al proceso
	
	Como Compilar
		gcc -Wall 02.c -o var
		./var

	Fuente
		https://www.youtube.com/watch?v=VwjP-KFuZCM
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int var = 21;

int main(int argc, char const *argv[]){
	
	pid_t pidC;
	int i = 1;

	printf("** proceso PID = %d comienza ** \n", getpid());

	pidC = fork();

	printf("** proceso PID = %d, pidC = %d ejecutandose ** \n", getpid(), pidC);

	if(pidC > 0)
		var	= 98;
	else if(pidC == 0)
		var = 77;
	else
		printf("%s\n", "Error!.");
	
	while(1){
		sleep(2);	// Tiempo de duracion de cada instruccion
		printf("%d ---> %s: proceso PID = %d, var = %d, direcion memoria de var: %p** \n", i++, pidC ? "Padre" : "Hijo", getpid(), var, &var);
		printf("\n");
	}
	return 0;
}