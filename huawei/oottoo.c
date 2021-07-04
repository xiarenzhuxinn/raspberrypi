int fun(char *p)  
{  
    if(p == NULL)  
    {  
        return -1;  
    }  
    char *pBegin = p;  
    char *pEnd   = p;  
    while(*pEnd != '\0')  
    {  
        pEnd ++;  
    }  
    pEnd --;  
    while(pBegin < pEnd)  
    {  
        if(*pBegin != *pEnd)  
        {  
            return 0;  
        }  
        else  
        {  
            pBegin ++;  
            pEnd   --;  
        }  
    }  
    return 1;  
}  

