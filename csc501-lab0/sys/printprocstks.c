#include <stdio.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

static unsigned long *esp;

void printprocstks(int prior)
{

    int i;
    struct pentry *task;

    kprintf("\nTask 4 (printprocstks)\n# Processes below the corresponding priority: %d\n", prior);


    for(i = 0; i < NPROC; ++i)
            
   {
        
        task = &proctab[i];

        // Checking pid of each process
        if( (task->pstate) == PRFREE || (task->pprio >= prior) ) {
            continue;
        }
        else {
            kprintf("Process [%s]\n", task->pname);
            kprintf("\tpid: %d\n", i); 
            kprintf("\tpriority: %d\n",task->pprio);
            kprintf("\tbase: 0x%08x\n", task->pbase);
            kprintf("\tlimit: 0x%08x\n", task->plimit);
            kprintf("\tlen: %d\n", task->pstklen);
            if( i == currpid) {
                // current process
                asm("movl %esp,esp");
                kprintf("\pointer: 0x%08x\n", esp);
            }
            else
                kprintf("\pointer: 0x%08x\n", task->pesp);

        }

 
 }

}
