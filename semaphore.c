#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#define KEY 37

int main(int argc, char * argv[]) {

  int sem_id;
  if (argc==3) {
    if (!strcmp(argv[1],"-c")) {
      sem_id=semget(KEY,1,IPC_CREAT | IPC_EXCL | 0600);
      if (sem_id>=0) {
	int size=0;
	sscanf(argv[2],"%d",&size);
	printf("semaphore created: %d\n",sem_id);
	semctl(sem_id,0,SETVAL,size);
	printf("value set: %d\n", semctl(sem_id,0,GETVAL));
      } else {
	printf("semaphore already exists\n");
      }

    } else
      printf("improper input\n");
  } else if (argc==2) {
    if (!strcmp(argv[1],"-v")) {
      sem_id=semget(KEY,1,0600);
      printf("semaphore value: %d\n",semctl(sem_id,0,GETVAL));
    }
    else if (!strcmp(argv[1],"-r")) {
      sem_id=semget(KEY,1,0600);
      printf("semaphore removed: %d\n",semctl(sem_id,0,IPC_RMID));
    }
    else
      printf("improper input\n");
  }
  else
    printf("improper input.\n");

  
 
  return 0;
 

}
