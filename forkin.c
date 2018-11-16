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
	if(getpid()==fork()){
		if(getpid()==fork()){
		printf("hello");
		}
	}
	printf("%d\n",abs(randNum())%16);
	return 0;
}
