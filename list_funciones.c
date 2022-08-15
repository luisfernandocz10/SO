int stat(const char *restrict pathname,struct stat *restrict statbuf);


pid_t getpid(void);
pid_t getppid(void);
	getpid devuelve el identificador de proceso del proceso actual. (Esto es usado normalmente
	por rutinas que generan nombres únicos  de  ficheros  temporales.)   getppid  devuelve  el
	identificador de proceso del padre del proceso actual.

pid_t fork(void);
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


int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
	La llamada al sistema open() abre el archivo especificado por pathname.

	O_CREAT
		Si el nombre de ruta no existe, créelo como un archivo normal.

		El propietario (ID de usuario) del nuevo archivo se establece en el
		ID de usuario efectivo del proceso.

	Los indicadores de argumento deben incluir uno de los siguientes accesos
	modos: O_RDONLY, O_WRONLY o O_RDWR. Estos solicitan la apertura del
	archivo de solo lectura, solo escritura o lectura/escritura, respectivamente.

ssize_t write(int fildes, const void *buf, size_t nbyte);
	La función de write() intentará escribir nbyte bytes desde el búfer al que 
	apunta buf en el archivo asociado con el descriptor de archivo abierto, fildes.

int pipe(int pipefd[2]);
int pipe2(int pipefd[2], int flags);



void exit(int status);
	llama a todas las funciones registradas con atexit y finaliza el programa. 
	Los búferes de archivos se vacían, las secuencias se cierran y los archivos temporales se eliminan
	
	Parámetros o Argumentos
	estado
		Indica si el programa terminó normalmente. Puede ser uno de los siguientes:

		Valor	        	Descripción
		EXIT_SUCCESS		Terminación exitosa
		0					Terminación	exitosa
		EXIT_FAILURE		Terminación fallida

continue
	para saltar el resto del cuerpo de una instrucción de repetición y continuar con la siguiente
	iteración del ciclo


pid_t wait(int *wstatus);
	Una llamada a wait() BLOQUEA el proceso de llamada hasta que uno de sus procesos secundarios 
	finaliza o se recibe una señal. Después de que finaliza el proceso hijo, el padre continúa su 
	ejecución después de esperar la instrucción de llamada al sistema. 
	El proceso secundario puede terminar debido a cualquiera de estos: 

	Llama a salir();
	Devuelve (un int) de main
	Recibe una señal (del sistema operativo o de otro proceso) cuya acción predeterminada es terminar