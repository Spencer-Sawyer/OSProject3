#include <stdio.h>

#define PAGE_SIZE 0xFF
#define MEM_PAGES 0xFF
#define LOG_PAGES 0xFF
#define TLB_SIZE 0x0F
#define pagedt unsigned char
#define offsett unsigned char

unsigned char mem[MEM_PAGES+1][PAGE_SIZE+1];
pagedt pageLookUp[LOG_PAGES+1];
unsigned char  pageLookUpValid[LOG_PAGES+1];
pagedt TLB[TLB_SIZE+1];

void main(int argc, char **argv)
{
	FILE * addresses,  * bin;
	unsigned int logicAddress, logicPage, offset;
	pagedt pageCount=0;
	pagedt pageLookUpValue;
	signed char value = 0;
	addresses = fopen("addresses.txt", "R");
	bin = fopen("BACKING_STORE.bin", "RB");
	while (!feof(addresses))
	{
		fscanf(addresses, "%u", &logicAddress);

		logicPage = ((logicAddress) >> 8*sizeof(offsett))&LOG_PAGES;
		offset = logicAddress & PAGE_SIZE;

		if (!pageLookUpValid[logicPage])
		{
		//if it's not valid make it valid before getting the value			
			fseek(bin, logicPage*(PAGE_SIZE+1),0);
			fread(mem[pageCount], sizeof(char), PAGE_SIZE + 1, bin);
			pageLookUp[logicPage] = pageCount;
			pageLookUpValid[logicPage] = 1;
			pageCount++; //because we have the same physical addressing space as logical, I'm not going to check if this overflows as this code shouldn't be reached if all logical pages are in memeory


		}
		pageLookUpValue = pageLookUp[logicPage];
		value = mem[pageLookUpValue][offset];
		printf("Logic Address:%d real address:%d,value: %d",
			(unsigned int)((logicPage<< (8 * sizeof(offsett)))+offset),
			(unsigned int)((pageLookUpValue<< (8 * sizeof(offsett))) +offset),
			(int)value);

	}
	





}