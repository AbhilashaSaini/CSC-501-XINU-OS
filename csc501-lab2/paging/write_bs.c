#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <mark.h>
#include <bufpool.h>
#include <paging.h>

int write_bs(char *src, bsd_t bs_id, int page) {

  /* write one page of data from src
     to the backing store bs_id, page
     page.
  */
   char * phy_addr = BACKING_STORE_BASE + bs_id*BACKING_STORE_UNIT_SIZE + page*NBPG;
//   kprintf("write_bs : address is 0x%08x and data wrote is %c from frame addr 0x%08x\n", phy_addr, *phy_addr,src);
   bcopy((void*)src, phy_addr, NBPG);

}

