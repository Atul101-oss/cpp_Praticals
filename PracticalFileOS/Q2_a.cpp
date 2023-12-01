#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    printf("process ID of newly created process usig fork: %d\n", getpid());
    return 0;
}
