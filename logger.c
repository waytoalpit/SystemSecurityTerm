#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main (int argc, char* argv[])
{

 int fd, msgcnt;
 char* msg = argv[1];
 struct flock mlock;

 time_t ltime;
 struct tm result;
 char stime[32];

 ltime = time(NULL);
 localtime_r(&ltime, &result);
 asctime_r(&result, stime);
 //printf("%s", stime);

 printf ("opening log.txt to log\n");

 //Open a file to append log message
 fd = open ("log.txt", O_WRONLY|O_APPEND);

 printf ("lock acquired\n");

 //init the flock struct
 memset (&mlock, 0, sizeof(mlock));
 mlock.l_type = F_WRLCK;

 //acquire write lock to the file
 fcntl (fd, F_SETLKW, &mlock);

 // append message to the file
 strcat(msg, "\n");
  msgcnt= write(fd, "\nNew thread arrived- scanning completed\n", 40);
 msgcnt= write(fd, stime, strlen(stime));
 msgcnt= write(fd, msg, strlen(msg));
 
  //printf ("locked; hit Enter to unlock... ");
 // hit enter to unlock the file
 //getchar ();

 printf ("unlocking\n");

 //lock released
 mlock.l_type = F_UNLCK;
 fcntl (fd, F_SETLKW, &mlock);

 close (fd);
 return 0;
}
