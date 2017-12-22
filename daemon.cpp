//http://www.netzmafia.de/skripten/unix/linux-daemon-howto.html

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

#include <string>

#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

extern int daemon_main(int argc, char **argv);

std::string get_self_name()
{
    char buf[PATH_MAX] = {'\0'};

    int ret = readlink("/proc/self/exe", buf, PATH_MAX);
    if (ret < 0 || ret >= PATH_MAX) {
        return "";
    }

    std::string path(buf);
    int pos = path.find_last_of("/");
    if (pos == -1) {
        return "";
    }

    path = path.substr(pos + 1, path.size() - 1);

    return path;
}

bool run_single_instance()
{
    std::string process_name = get_self_name();
    if (process_name.empty()){
        exit(1);
    }

    std::string lock_path = std::string("/var/run/") + process_name + ".pid";
    int fd = open(lock_path.c_str(), O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        printf("open file failed, error : %s", strerror(errno));
        exit(1);
    }

    int ret = flock(fd, LOCK_EX|LOCK_NB);
    if (ret != 0) {
        if (errno == EWOULDBLOCK) {
            printf("%s already locked, error: %s\n", lock_path.c_str(), strerror(errno));
            close(fd);
            return false;
        }
    }

    char buf[16] = {'\0'};
    sprintf(buf, "%d", getpid());
    ftruncate(fd, 0);
    ret = write(fd, buf, strlen(buf));
    if (ret < 0) {
        printf("write file failed, file: %s, error: %s\n", lock_path.c_str(), strerror(errno));
        close(fd);
        exit(1);
    }

    return true;
}

int main(int argc, char **argv)
{
    if (!run_single_instance()) {
        //printf("Process is already running\n");
        return 1;
    }
        /* Our process ID and Session ID */
        pid_t pid, sid;

        /* Fork off the parent process */
        pid = fork();
        if (pid < 0) {
                exit(EXIT_FAILURE);
        }
        /* If we got a good PID, then
           we can exit the parent process. */
        if (pid > 0) {
                //print();
                exit(EXIT_SUCCESS);
        }

        /* Change the file mode mask */
        umask(0);

        /* Open any logs here */

        /* Create a new SID for the child process */
        sid = setsid();
        if (sid < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }

        /* Change the current working directory */
        if ((chdir("/")) < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }

        /* Daemon-specific initialization goes here */
        daemon_main(argc, argv);
        
        /* Close out the standard file descriptors */
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        /* The Big Loop */
        while (1) {
           /* Do some task here ... */
           sleep(30); /* wait 30 seconds */
        }
   exit(EXIT_SUCCESS);
}
