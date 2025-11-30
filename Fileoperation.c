#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    printf("=== FILE OPERATIONS USING UNIX SYSTEM CALLS ===\n");

    int fd;
    char buffer1[100];

    fd = open("syscall.txt", O_CREAT | O_RDWR, 0644);
    if(fd < 0) {
        perror("open");
        exit(1);
    }
    printf("UNIX: File opened using open(), FD = %d\n", fd);

    char data1[] = "Data written using UNIX system calls.\n";
    write(fd, data1, strlen(data1));

    lseek(fd, 0, SEEK_SET);

    int r1 = read(fd, buffer1, sizeof(buffer1)-1);
    buffer1[r1] = '\0';
    printf("UNIX: Data read using read(): %s\n", buffer1);

    close(fd);
    printf("UNIX: File closed using close()\n");

    printf("\n=== FILE OPERATIONS USING C STANDARD LIBRARY ===\n");

    FILE *fp;
    char buffer2[200];

    fp = fopen("clib.txt", "w+");
    if(fp == NULL) {
        perror("fopen");
        exit(1);
    }
    printf("C LIB: File opened using fopen()\n");

    char data2[] = "Data written using C standard library.\n";
    fwrite(data2, sizeof(char), strlen(data2), fp);

    fseek(fp, 0, SEEK_SET);

    int r2 = fread(buffer2, sizeof(char), sizeof(buffer2)-1, fp);
    buffer2[r2] = '\0';
    printf("C LIB: Data read using fread(): %s\n", buffer2);

    fclose(fp);
    printf("C LIB: File closed using fclose()\n");

    return 0;
}
