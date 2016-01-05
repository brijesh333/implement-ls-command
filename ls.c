#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main()
{
	char b[20];
	getcwd(b,sizeof(b));
	printf("%s",b);
	
	struct dirent *dp;
	DIR *dr;	
	if((dr=opendir(b))==NULL)
	{
		printf("No directory found");
		return 0;
	}
	while((dp=readdir(dr))!=NULL)
	{
		printf("%s %s",b,dp->d_name);
		printf("\n");
	}
	closedir(dr);
	return 0;
}
