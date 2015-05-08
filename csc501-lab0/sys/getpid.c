/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
 if(syscalltrace == 1) {
		syscallused[currpid] = 1;
		syscallcnt[currpid][0]++;

	}
return(currpid);
}
