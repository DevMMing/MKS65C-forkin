#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <wait.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

int randNum(){
  int c;
  int file = open("/dev/random",O_RDONLY);
  read(file,&c,sizeof(c));
  close(file);
  return c;
}
int main(){
	printf("out some initial message\n");
	int child1=fork();
	if(child1==0){
		printf("Hello, I am child1:%d\n. Let me take a quick nap.",getpid());
		sleep(abs(randNum()%16));
		printf("Ok. I am done sleeping.");
	}else{
	int child2=fork();
	if(child2==0){
		printf("Hello again. I am child2:%d\n. Let me take a quick nap",getpid());
		sleep(abs(randNum()%16));
		printf("Ok. I am done sleeping.");
	}
	}
	return 0;
}
