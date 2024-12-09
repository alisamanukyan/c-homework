#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024  

typedef struct _File {
    int fd;             
    char *buf;          
    int buf_size;       
    int buf_count;      
    int buf_index;      
    int flags;          
} FILE_CUSTOM;

#define WRITE_MODE 1
#define READ_MODE  2
#define ERR_FLAG   4

FILE_CUSTOM *open_file(const char *filename, int flags, int buf_size) {
    FILE_CUSTOM *fp = malloc(sizeof(FILE_CUSTOM));
    if (!fp) return NULL;

    fp->fd = open(filename, flags, 0644); // Ֆայլի թույլտվությունները
    if (fp->fd == -1) {
        free(fp);
        return NULL;
    }

    fp->buf = malloc(buf_size);
    if (!fp->buf) {
        close(fp->fd);
        free(fp);
        return NULL;
    }

    fp->buf_size = buf_size;
    fp->buf_count = 0;
    fp->buf_index = 0;
    fp->flags = WRITE_MODE;

    return fp;
}

int _flushbuf(int c, FILE_CUSTOM *fp) {
    if (!fp || !(fp->flags & WRITE_MODE)) return EOF;

    int written = write(fp->fd, fp->buf, fp->buf_count);
    if (written == -1) {
        fp->flags |= ERR_FLAG;
        return EOF;
    }

    fp->buf_count = 0;
    fp->buf_index = 0;

    if (c != EOF) {
        fp->buf[fp->buf_index++] = c;
        fp->buf_count++;
    }

    return c;
}

int custom_fflush(FILE_CUSTOM *fp) {
    if (!fp || !(fp->flags & WRITE_MODE)) return EOF;

    return _flushbuf(EOF, fp);
}

int custom_fclose(FILE_CUSTOM *fp) {
    if (!fp) return EOF;

    if (custom_fflush(fp) == EOF) {
        free(fp->buf);
        free(fp);
        return EOF;
    }

    if (close(fp->fd) == -1) {
        free(fp->buf);
        free(fp);
        return EOF;
    }

    free(fp->buf);
    free(fp);

    return 0;
}
