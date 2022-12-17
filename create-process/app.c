#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main ()
{
  pid_t retornoFork ;

  printf ("Ola, sou o processo Pai inicial %5d\n", getpid()) ;

  printf("antes do fork () \n");

  retornoFork = fork () ; // retorna: valor<0 para erro; 0 para processo filho e valor>0 para processo pai
  printf("Após fork()  \n");

  printf ("[retornoFork=%5d] sou o processo ID=%5d, filho de ID=%5d\n", retornoFork, getpid(), getppid()) ;


  if ( retornoFork < 0 )
  {
    perror ("Erro") ;
    exit (1) ;
  }
  else
    if ( retornoFork > 0 ) {
        wait(0);
        printf("Sou o processo pai executando -- ");
        printf ("resultado do PRODUTO: %d ***",3*3);

        }
    else {
        sleep (5) ;
        printf("Sou o processo filho executando -- ");
        printf ("resultado da SOMA: %d ***",2+2) ;

        }

  printf ("Término do processo ID=%5d!\n", getpid()) ;
  exit (0) ;
}
