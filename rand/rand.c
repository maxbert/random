//#include </dev/random>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int getrand(){
  void *o = open("/dev/random", O_RDWR);
  void *x;
  int err =1;
  err =read(o,x,4);
   if(err==-1){
     // printf("%s", strerror(errno));
  }
  err = close(o);
  if(err==-1){
    //  printf("%s", strerror(errno));
  }
  return &x;
}







int main(){
  int a[10];
  int i =0;
  for(; i<10;i++){
   a[i] = getrand();
   printf("%d:%d\n",i,a[i]);
  }
  void *stat;
  stat = open("output.txt", O_CREAT, O_RDWR);
  write(stat, a, sizeof(int) * 10);
  int *x;
  int o[10];
  int j = 0;
  x = read(stat,o, sizeof(int) * 10 );
  for(; j<10; j++){
    printf("%d\n", o[j]);
  }
  
  
  
}
