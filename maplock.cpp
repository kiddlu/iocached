#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "maplock.h" 
#define ARRAY_LENGTH(arr) ((sizeof(arr)/sizeof(arr[0])))

#define LOG_PATH "/var/log/iocached.log"

static int set_map_lock(struct map_struct *file)
{
    struct stat st;
    int ret = 0;
    int fd = 0;

    ret = stat(file->path, &st);
    if(ret != 0) {
        perror("stat fail\n");
        return -1;
    }

    file->length = st.st_size;

    fd = open(file->path, O_RDONLY);
    if(fd < 0) {
        perror("open fail\n");
        return -1;
    }

    file->addr = mmap(NULL, file->length, PROT_READ, MAP_SHARED|MAP_POPULATE|MAP_LOCKED, fd, 0);
    if(file->addr == MAP_FAILED) {
        perror("map fail");
        close(fd);
        return -1;
    }

    close(fd);

    //printf("%s mapped, size is %d kB\n", file->path, (file->length)/1024);
    return 0; 
}

int daemon_main(int argc, char **argv)
{
    unsigned int i;
    for (i=0; i<ARRAY_LENGTH(native_table); i++) {
        set_map_lock(&native_table[i]);
    }

    for (i=0; i<ARRAY_LENGTH(framework_table); i++) {
        set_map_lock(&framework_table[i]);
    }

    for (i=0; i<ARRAY_LENGTH(app_table); i++) {
        set_map_lock(&app_table[i]);
    }

    for (i=0; i<ARRAY_LENGTH(priv_app_table); i++) {
        set_map_lock(&priv_app_table[i]);
    }

    return 0;
}
