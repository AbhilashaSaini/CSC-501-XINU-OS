#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <paging.h>

int get_bs(bsd_t bs_id, unsigned int npages) {

  /* requests a new mapping of npages with ID map_id */

    STATWORD ps;
    disable(ps);
    if((npages<1)||(npages > 128)||(bs_id>=MAX_ID)||(bs_id<0))
    	{
    	kprintf("Requested backing store or pages do not match conditions");
		return SYSERR;
    	}

	if(bsm_tab[bs_id].ispriv == 1)
		{
		kprintf("Requested backing store is used for private heap");
		return SYSERR;
		}
	
	if(bsm_tab[bs_id].bs_sem == 1)
		{
		kprintf("Requested backing store is being use by different process");
		return SYSERR;
		}
	
	bsm_tab[bs_id].bs_npages = npages;
	bsm_tab[bs_id].bs_pid = currpid;
	
	restore(ps);
    return npages;

}


