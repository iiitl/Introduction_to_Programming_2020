// readelf -h a.o
// usr/include/elf.h
// objdump --section=.data  a.o -s // content of data section
//
int same;
int arr[] = {2,3,10};

int main(){
  printf("%d\n",same);
}
