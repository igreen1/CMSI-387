#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
// #include <time.h>

// #define INPUT_SIZE 25

void displayStats(struct stat);


int main(int argc, char * argv[]){

  if(argc <= 1){
    printf("Error: no file name provided\n Please call this program and provide a file name after the call\n");
    return -1;
  } else if(argc > 2){
    printf("Warning: more than one CLI argument was given\n only the file in the first position will be used!\n");
  }

  struct stat stats;
  int returnFlag = stat(argv[1], &stats);
  if(returnFlag == 0)
    displayStats(stats);
  else
    printf("Unable to run stats on file provided. Does %s exist?", argv[1]);


}

/*
Print the stat struct :) 
*/
void displayStats(struct stat stats){
  printf("Stats -------------------------------\n");

  /*
  For reference (not for actual coding but because this is classwork)
  struct stat {
               dev_t     st_dev;         //ID of device containing file 
               ino_t     st_ino;         // Inode number 
               mode_t    st_mode;        // File type and mode 
               nlink_t   st_nlink;       // Number of hard links 
               uid_t     st_uid;         // User ID of owner 
               gid_t     st_gid;         // Group ID of owner 
               dev_t     st_rdev;        // Device ID (if special file) 
               off_t     st_size;        // Total size, in bytes 
               blksize_t st_blksize;     // Block size for filesystem I/O 
               blkcnt_t  st_blocks;      // Number of 512B blocks allocated 

               //Since Linux 2.6, the kernel supports nanosecond
                 // precision for the following timestamp fields.
                  //For the details before Linux 2.6, see NOTES. 

               struct timespec st_atim;  // Time of last access 
               struct timespec st_mtim;  // Time of last modification 
               struct timespec st_ctim;  // Time of last status change 

           #define st_atime st_atim.tv_sec      // Backward compatibility 
           #define st_mtime st_mtim.tv_sec
           #define st_ctime st_ctim.tv_sec
           };
  */
  //gracias stack overflow user 'caf'
  //printf("%lld.%.9ld", (long long)ts.tv_sec, ts.tv_nsec);
  printf("\nFile Size: %ld", stats.st_size);
  printf("\n%lld.%9ld", (long long)stats.st_mtim.tv_sec, stats.st_mtim.tv_nsec);

  printf("\n------------------------------------\n");
}