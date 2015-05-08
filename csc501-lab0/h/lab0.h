extern long zfunction (long param);
extern void printsyscalls();
extern void printprocstks(int priority);
extern int syscallcnt[NPROC][5];
extern const char syscallname[5][16];
extern int syscalltrace;
extern int syscallused[NPROC];

