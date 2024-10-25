#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"
#include "processes.h"
#include "help.h"
#include "logging.h"
#include "error_handling.h"

void print_usage() {
    printf("Использование: my_console_util [OPTIONS]\n");
    printf("Опции:\n");
    printf("  -u, --users          Показать пользователей и их домашние директории\n");
    printf("  -p, --processes      Показать запущенные процессы\n");
    printf("  -h, --help           Показать это сообщение\n");
    printf("  -l PATH, --log PATH  Записать вывод в файл по указанному пути\n");
    printf("  -e PATH, --errors PATH Записать ошибки в файл по указанному пути\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--users") == 0) {
            list_users();
        } else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--processes") == 0) {
            list_processes();
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage();
            return EXIT_SUCCESS;
        } else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--log") == 0) {
            if (i + 1 < argc) {
                redirect_output_to_file(argv[++i]);
            } else {
                fprintf(stderr, "Ошибка: не указан путь для логирования.\n");
                return EXIT_FAILURE;
            }
        } else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--errors") == 0) {
            if (i + 1 < argc) {
                redirect_errors_to_file(argv[++i]);
            } else {
                fprintf(stderr, "Ошибка: не указан путь для ошибок.\n");
                return EXIT_FAILURE;
            }
        } else {
            fprintf(stderr, "Ошибка: неизвестный аргумент '%s'.\n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
