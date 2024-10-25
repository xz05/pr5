#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>

void list_users() {
    struct passwd *pw;
    FILE *output = stdout;

    while ((pw = getpwent()) != NULL) {
        printf("%s: %s\n", pw->pw_name, pw->pw_dir);
    }

    endpwent();
}
