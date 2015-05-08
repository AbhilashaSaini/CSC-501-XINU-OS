#include <stdio.h>


static unsigned int *ebp;
void printtos()
{      int i;
	asm("movl %ebp,ebp");
        kprintf("\nAddress before function Call: 0x%08x", ebp + 2);
	kprintf("\nAddress after function Call:0x%08x", ebp);

       for (i=0;i<=5;i++)
     
	 kprintf("\nStack Contents %d", *(ebp - i) );

}
