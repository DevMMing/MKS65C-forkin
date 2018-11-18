#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <wait.h>
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
	int sleeptime;
	int deadtime;
	if(child1==0){
		sleeptime=abs(randNum()%16)+5;
		deadtime=sleeptime;
		printf("Hello, I am child1:%d\n. Let me take a quick %d-second nap\n",getpid(),sleeptime);
		sleep(sleeptime);
		printf("Ok. I am done sleeping.\n");
		return deadtime;
	}else{
	int child2=fork();
	if(child2==0){
		sleeptime=abs(randNum()%16)+5;
		deadtime=sleeptime;
		printf("Hello again. I am child2:%d\n. Let me take a quick %d-second nap\n",getpid(),sleeptime);
		sleep(sleeptime);
		printf("Ok. I am done sleeping.\n");
		return deadtime;
	}
	else{
	int deadchild=wait(&deadtime);
	if (WIFEXITED(deadtime)){
        int ghost = WEXITSTATUS(deadtime);
	  	printf("So sad poor jimmy had died! %d\n",deadchild);
		printf("He only lived for %d seconds\n",ghost);
		printf("Father got sad and went to sleep\n");
		exit(0);
	}
	}
	}
	
}
