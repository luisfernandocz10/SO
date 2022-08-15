/*
03.c
	for(), wait y multiples procesos hijo
	
	pid_t fork();
	
	pid_t wait(int *wstatus);
	WEXITSTATUS(wstatus)

	Fuente:
		https://www.youtube.com/watch?v=Dt9z_ohQWHI


	Creacion de varios hijos y usamos la funcion wait()
	¿Que es lo que paso?
		cunando llamamos al fork() se crea un hijo, se imprime la informacion del padre
		y continua el for() (perpectiva padre). Cuando llega al 2do for() ingresa a la
		funcion wait(), de ahi continua con la ejecucion del ULTIMO hijo creado hasta que 
		finalice el proceso de este hijo. Sigue continuando con el ANTIPENULTIMO hasta que 
		todos los hijos hallan terminado sus procesos.
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#define NUM_CHILD 5


int doSomething(void){
	 int ret;

	 srand(getpid());

	 ret = (rand() % 256);
	 printf("HIJO: PID: %d, valor aleatorio calculado %d \n", getpid(), ret);

	 return ret;
}

int main(void){
	pid_t pidC;
	int status;

	for(int i = 0; i < NUM_CHILD; i++){
		pidC = fork();
		
		printf("** proceso %s PID = %d, HIJO: %d --> pidC = %d ejecutandose ** \n", pidC ? "PADRE" : "HIJO", getpid(), i, pidC);


		if(pidC > 0){
			continue;	// Al ser el padre no hace nada
		}
		else if(pidC == 0){
			printf("HIJO: %d, PID = %d --> pidC = %d \n", i, getpid(), pidC);
			exit(doSomething());
			
		}
		else
			printf("%s\n", "error!.");
	}

	for(int i = 0; i < NUM_CHILD; i++){
		printf("\n************\n");

		pidC = wait(&status);

		printf("PADRE de PID = %d, hijo de PID = %d terminado, st = %d \n", getpid(), pidC, WEXITSTATUS(status));
	}

	// while(1){
	// 	sleep(10);
	// }
}
