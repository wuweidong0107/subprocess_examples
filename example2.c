#include <stdio.h>
#include "subprocess.h"

int main(int argc, char **argv)
{
    const char *command_line[] = {"/usr/bin/sleep", "3", NULL};
    struct subprocess process;
    int ret = -1;
    char line[512];

    if (0 != subprocess_create(command_line, 0,
                &process)) {
        fprintf(stderr, "fail to subprocess_create\n");
        return 1;
    }

    if (0 != subprocess_join(&process, &ret)) {
        fprintf(stderr, "fail to subprocess_join\n");
        return 1;
    }

    FILE* fp = subprocess_stdout(&process);
    while (fgets(line, 512, fp)) {
        printf("Got data: %s", line);
    }

    if (0 != subprocess_destroy(&process)) {
        fprintf(stderr, "fail to subprocess_destroy\n");
        return 1;
    }

    return ret;
}