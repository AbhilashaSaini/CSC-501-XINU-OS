#include <stdio.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

int syscalltrace = 0;
int syscallcnt[NPROC][5];
int syscallused[NPROC];
const char syscallname[5][16]={"getpid","gettime", "kill","signal","sleep","wait"};


void syscallsummary_start()
{
    int i=0, j=0;
    
    // trace start
    syscalltrace = 1;

    // init values
	while(i<NPROC)
	{

	syscallused[i] = 0;
	while(j<6) 
{
 	     syscallcnt[i][j] = 0;
    	++j;    
         
	}
++i;	}

}

void syscallsummary_stop()
{
    syscalltrace = 0;
}

void printsyscalls()
{
    int i, j;

    kprintf("\nTask 5 (printsyscalls)\n");
    
    // iterate for all processes
   for(i = 0; i < NPROC; ++i)
	 {

        //  only for valid pid
        if( syscallused[i] == 0 ) {
            continue;
        }
        else {
	
	    kprintf("Process [pid:%d]\n", i);
	}
	
            
            //iterate all syscalls
           for(j = 0; j < 6; ++j)
	 {
                
                if(syscallcnt[i][j] > 0) {
		    
             	    kprintf("\tSyscall: %s, count: %d\n", syscallname[j], syscallcnt[i][j]);

                }
                
           }
	}
}

