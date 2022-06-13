# c_memory_struct_example

/********************************************************************************* 
  *Copyright(C), Matthew Hakin  2022
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
