#include <stdio.h>
#include <syslog.h>


int main(int argc, char **argv)
{


    //start syslog
    openlog(NULL, 0, LOG_USER);
    //check command line arguments
    if (argc < 3)
    {
        printf("Insufficient arguments, syntax writer FILE STRING\n");
    	syslog(LOG_ERR, "Invalid Number of arguments: %d\n", argc);
	return 1;
    }

    const char *filepath = argv[1];
    const char *string = argv[2];
    FILE *fd;
    int fr;
    syslog(LOG_DEBUG, "Writing %s to %s\n", string, filepath);

    //open file
    fd = fopen(filepath, "w");
    //error check on file open and log message
    if(fd == NULL)//error check
    {
    	syslog(LOG_ERR, "fopen failure\n");
    	printf("Error on file open\n");
	return 1;
    }
    //write file
    fr = fprintf(fd, "%s", string); 
    if(fr<0)
    {
    	syslog(LOG_ERR, "Writing failure\n");
    	printf("Error on writing to file\n");
	return 1;

    }
    //close file
    fclose(fd);
    return 0;

}
