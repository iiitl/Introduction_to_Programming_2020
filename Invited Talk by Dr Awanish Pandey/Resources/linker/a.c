#include <stdio.h>
extern void foo();
int  crash = 1;

int main(){
  foo();
  printf("%d\n",crash);
}
