#include "header.h"
unsigned int cmp(const char *p,const char *q)
{
   signed  int i;
    for(i=0;p[i];i++)
	{
    if(p[i]!=q[i])
    
        break;
    }
    
    if(p[i]>q[i])
    return 1;
    else if(p[i]<q[i])
    return -1;
    else
    return 0;
}
    
    

    
