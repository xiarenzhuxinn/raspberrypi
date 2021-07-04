/*difine strcmp*/

int strcmp(char *source,char *dest)  
{  
    if((source == NULL) && (dest == NULL))  
    {  
        return 0;  
    }  
    while((*source != '\0') && (*dest != '\0'))  
    {  
        if(*source != *dest)  
        {  
            return 1;  
        }  
        else  
        {  
            source ++;  
            dest ++;  
        }  
    }  
    if((*source == '\0') && (*dest == '\0'))  
    {  
        return 0;  
    }  
    else  
    {  
        return 1;  
    }  
}  

