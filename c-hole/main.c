#include "apue.h"
#include "stdio.h"
#include <fcntl.h>
#include <unistd.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

void err(const char* x)
{
    perror(x);
    exit(1);
}

int main() {
    int fd;
    if ((fd = creat("file.hole", FILE_MODE)) < 0) {
        err("ошибка вызова creat");
    }

    if (write(fd, buf1, 10) != 10) {
        err("ошибка записи buf1");
    }
    /* теперь текущая позиция = 10 */

    if (lseek(fd, 16384, SEEK_SET) == -1) {
        err("ошибка вызова lseek");
    }
    /* теперь текущая позиция = 16384 */

    if (write(fd, buf2, 10) != 10) {
        err("ошибка записи buf2");
    }
    /* теперь текущая позиция = 16394 */

    exit(0);
}