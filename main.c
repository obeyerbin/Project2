#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

void filestat1(void)
{
	stat("text1", &stat1);
}

void filestat2(void)
{
	stat("text2", &stat2);
}

void filetime1(void)
{
	time1 = localtime(&stat1.st_mtime);
}

void filetime2(void)
{
	time2 = localtime(&stat2.st_mtime);
}

void sizecmp(void)
{
	double fileSize1 = stat1.st_size;
	double fileSize2 = stat2.st_size;
	
	printf("size compare\n");

	if(fileSize1 > fileSize2)
	printf("text1 is bigger\n\n");
	else if(fileSize1 < fileSize2)
	printf("text2 is bigger\n\n");
	else
	printf("same size\n\n");
}

void blockcmp(void)
{
	double fileBlockNumber1 = stat1.st_blocks;
	double fileBlockNumber2 = stat2.st_blocks;

	printf("block compare\n");
	
	if(fileBlockNumber1 > fileBlockNumber2)
	printf("text1 is bigger\n\n");
	else if(fileBlockNumber1 < fileBlockNumber2)
	printf("text2 is bigger\n\n");
	else
	printf("same block\n\n");
}

void datecmp(void)
{
	
}

void timecmp(void)
{
	
}
