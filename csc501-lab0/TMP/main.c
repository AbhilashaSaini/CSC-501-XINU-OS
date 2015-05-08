/* user.c - main */
#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

void halt();
 





/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */

int main()
{
	kprintf("\n\nHello World, Xinu lives\n\n%x",zfunction(0xaabbccdd));
	printsegaddress();
	printtos();
	printprocstks(50);
	syscallsummary_start();        
	getpid(3);
	gettime(6);
	sleep(1);
	kill(4);
	signal(4);
	
	syscallsummary_stop();
	printsyscalls();
	return 0;
}
