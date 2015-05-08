#include <stdio.h>
extern int etext,edata,end;

void printsegaddress()
{
	kprintf("\n\n Task 2 (printsegaddress)");
	kprintf("\n current: etext = 0x%08x, edata = 0x%08x, ebss = 0x%08x",&etext, &edata, &end);
	kprintf("\n before: etext=0x%08x, edata=0x%08x, ebss=0x%08x",*((int *)&etext - 1),*((int *)&edata - 1),*((int *)&end-1));
	kprintf("\n After: etext=0x%08x, edata=0x%08x, ebss=0x%08x", *((int *)&etext + 1),*((int *)&edata + 1),*((int *)&end + 1));
}
