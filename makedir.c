#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc,char *argv[]) {
	if(argc !=2){
		printf("Usage: %s <foldername>\n",argv[0]);
		return 1;
	}

    char *dir_name = argv[1];
    int result = mkdir(dir_name,0777);
    if (result == 0) {
        printf("Directory '%s' created successfully.\n",dir_name);
    } else {
        perror("Directory creation failed");
	return 1;
    }

    return 0;
}

