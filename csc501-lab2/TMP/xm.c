/* xm.c = xmmap xmunmap */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <paging.h>


/*-------------------------------------------------------------------------
 * xmmap - xmmap
 *-------------------------------------------------------------------------
 */
SYSCALL xmmap(int virtpage, bsd_t source, int npages)
{
  /* sanity check ! */
  STATWORD ps;
  disable(ps);
  if ( (virtpage < 4096) || ( source < 0 ) || ( source >= MAX_ID) ||(npages < 1) || ( npages >128)){
	kprintf("xmmap call error: parameter error! \n");
	disable(ps);
	return SYSERR;
  }

  bsm_map(currpid, virtpage, source, npages);
  
  restore(ps);
  return OK;
}



/*-------------------------------------------------------------------------
 * xmunmap - xmunmap
 *-------------------------------------------------------------------------
 */
SYSCALL xmunmap(int virtpage )
{
  /* sanity check ! */
  STATWORD ps;
  disable(ps);
 
  if ( (virtpage < 4096) ){ 
	kprintf("xmummap call error: virtpage (%d) invalid! \n", virtpage);
	return SYSERR;
  }

  bsm_unmap(currpid, virtpage);

  restore(ps);
  return OK;
}

