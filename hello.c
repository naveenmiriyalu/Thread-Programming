/*
Author:      Naveen
Date:        Jan-16-2015
Description: Program that reads a command line argument n and 
             then creates and reaps n joinable threads 

Notes:       1. In this system compile using gcc/cc/g++ -pthread *.c
             2. Investigate why gcc/cc/g++ -lpthread is not working
			 Ans. New versions of gcc have -pthread as an option
			      Old versions of the compiler had to explicitly specify the -l option
*/

/*Header files */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//Thread function prototype
void* thread_print(void *arg)
{
  int *thread_no =(int*) (arg);
  printf("\n Thread %d created",*thread_no);
}

int main(int argc, char **argv)
{
  unsigned int n =0; //Threads to be created
  unsigned int i =0; //loop index
  pthread_t tid =0;

  if(argc != 2)
  {
  	printf("\n Calling convention...");
	printf("\n ./a.out #threads");
	printf("\n Program terminated \n");
	exit(0);
  }

  //Convert the command-line input to an integer
  n = atoi(argv[1]);

  for(i = 0; i < n; i++)
  {
    pthread_create(&tid,NULL,thread_print,&i);
	pthread_join(tid,NULL);
  }
}
