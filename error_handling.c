#include <stdio.h>

void redirect_errors_to_file(const char *path) {
    FILE *file = fopen(path, "w");

    if (file == NULL) {
        perror("Ошибка открытия файла для записи ошибок");
        return;
    }

    dup2(fileno(file), STDERR_FILENO);
}
