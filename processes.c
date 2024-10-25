#include <stdio.h>
#include <stdlib.h>

void list_processes() {
    FILE *fp = popen("ps -eo pid,comm --sort=pid", "r");
    
    if (fp == NULL) {
        perror("Ошибка при выполнении команды ps");
        return;
    }

    char buffer[256];
    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    pclose(fp);
}
