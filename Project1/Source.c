#include <stdio.h>

#define PAGE_SIZE 0xFF
#define MEM_PAGES 0xFF
#define TLB_SIZE 0x0F
#define pagedt char

char mem[MEM_PAGES][PAGE_SIZE];
pagedt pageLookUp[MEM_PAGES];
char  pageLookUpValid[MEM_PAGES];
pagedt TLB[TLB_SIZE];

void main(int argc, char **argv)
{
	FILE * addresses,  * bin;
	int 
	addresses = fopen("addresses.txt", "R");
	bin = fopen("BACKING_STORE.bin", "RB");




}