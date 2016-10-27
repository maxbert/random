#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


int getrand(){
  int o = open("/dev/random", O_RDWR);
  int *x = (int *)malloc(sizeof(int));
  int err = read(o,x,4);
   if(err<0){
     printf("%d-%s\n",errno, strerror(errno));
  }
  err = close(o);
  if(err<0){
    printf("%d-%s\n",errno, strerror(errno));    
  }
  int w = *x;
  free(x);
  return w;
}







int main(){
  printf("adding nums to array----------\n");
  int i =0;
  int a[10];
  for(; i<10;i++){
    a[i] = getrand();
    
   printf("%d:%d\n",i,a[i]);
  }

  int red = open("random.txt",O_CREAT | O_WRONLY, 0644);
  int error = write(red,a,sizeof(int)*10);
  if (error <0){
       printf("error %d -%s",errno,strerror(errno));
      }
  
  int closing = close(red);
  if (closing <0){
    printf("error %d -%s",errno,strerror(errno));
  }
  printf("reading from file---------------\n");
  int b[10];
  int red2 = open("random.txt",O_RDONLY);
  if (red2<0){
    printf("error %d -%s",errno,strerror(errno));
  }
  int error2 = read(red2,b,10*sizeof(int));
  if (error<0){
    printf("error %d -%s",errno,strerror(errno));
  }
  int k =0;
  while(k<10){
    printf("%d -- %d\n",k, b[k]);
    k++;
  }  
return 0; 
}
