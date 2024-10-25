#include <stdio.h>

void redirect_output_to_file(const char *path) {
    FILE *file = fopen(path, "w");
    
    if (file == NULL) {
        perror("Ошибка открытия файла для записи");
        return;
    }

    dup2(fileno(file), STDOUT_FILENO);
}
