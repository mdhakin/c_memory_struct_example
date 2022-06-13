
/********************************************************************************* 
  *Copyright(C), Matthew Hakin 
  *FileName: // mem.c
     *Author: // Matthew Hakin
     *Version: // 1.0 
     *Date: // Feb 22 2019
     *Description: // This is a little program I use to refresh some of my c knowledge 
                   // It shows how to make a struct, Pull a void pointer to a block of memory 
                   // It them demonstrates how to cast that void pointer to the custom struct
                   // Sets all custom struct pointers to null then releases the memory
     
     *Function List: // int loop(fsobj* myobj);
                     // void printmem(fsobj* myobj);
                     // void* map_mem(size_t size);
                     // void printbyte(uint8_t thebyte);
     1.………… 
     2.………… 
     *History: //Modification history record list, each modification record should include the modification date, modification person and modification content introduction 
     1.Date: 
       Author: Matthew Hakin
       Modification: Added notes
     2.………… 
**********************************************************************************/



// Do not remove
/*
mhakin@thinkpad:/mnt/c/Users/mhaki/OneDrive/code/c$ gcc -g mem.c
mhakin@thinkpad:/mnt/c/Users/mhaki/OneDrive/code/c$ gdb a.out

(gdb) b 28
Breakpoint 1 at 0x116a: file mem.c, line 28.
(gdb) run
Starting program: /mnt/c/Users/mhaki/OneDrive/code/c/a.out

Breakpoint 1, main () at mem.c:28
28          munmap(mem1, 100);
(gdb) p fs1->magic
$1 = 255 '\377'
(gdb) quit
A debugging session is active.

        Inferior 1 [process 50] will be killed.

Quit anyway? (y or n) y 

*/


#include <stdint.h>
#include <stddef.h>
#include <sys/mman.h>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

// example od typedef
typedef struct {
    uint8_t magic;
    char name[16];
    uint16_t blocksize;
} fsobj;

typedef struct {
    uint8_t magic;
     char name[8];
    uint8_t blocksize;
} fsobj2;

int loop(fsobj* myobj);
void printmem(fsobj* myobj);
void* map_mem(size_t size);
// This is a global handle to the master headder
fsobj* masterheader;
void printbyte(uint8_t thebyte);

int main(int argc, char *argv[])
{
    int loopcontrol = 0;
    void* mem1 = map_mem(100);
    
    fsobj* fs1 = (fsobj *)mem1;
    masterheader = (fsobj *)fs1;
    fs1->magic = 255;
    strcpy(fs1->name, "Matthew\n");
    fs1->blocksize = 100;
    printmem(fs1);
    // loop(fs1);
    masterheader = NULL;
    fs1 = NULL;

    munmap(mem1, 100);
    
    return 0;
}

// helper function to pull memory from the heap
void* map_mem(size_t size)
{
	void* ptr = mmap(0, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	return ptr;
}

void printmem(fsobj* myobj)
{
    printf("\n");
    printf("The object is named ");
    printf(myobj->name);
    printf("**********\n");
    printf("The objects size is %d bytes \n", myobj->blocksize);
    printf("The whole size of the memory block is %d bytes\n", myobj->blocksize);
    printf("The beginning address of the headder is %u\n", &myobj);
    printf("The size of the header is %d bytes\n", sizeof(fsobj2));
}

void printbyte(uint8_t thebyte)
{
    printf("The address is %u \n", &thebyte);
    printf("the contents are %d\n",thebyte);
}

int loop(fsobj* myobj)
{
    printf("%d\n",myobj->magic);
    printf(myobj->name);
    char bQuit = 'n';

    while (bQuit == 'n')
    {
        char str[1];
        int i;

        printf( "Enter a value :");
        scanf("%s %d", str, &i);

        printf( "\nYou entered: %s %d \n", str, i);
        bQuit = str[0];
    }
    return 0;
}



