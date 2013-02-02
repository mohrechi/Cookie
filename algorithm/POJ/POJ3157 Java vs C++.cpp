#include<stdio.h>
#include<string.h>
char cache[150];
int len;
bool isJava()
{
    int i;
    for(i=0;cache[i]!='\0';i++)
    {
        if(cache[i]=='_')
            return false;
    }
    return true;
}
bool isCpp()
{
    int i;
    if(cache[len-1]=='_')
        return false;
    for(i=0;i<len;i++)
    {
        if(cache[i]>='A' && cache[i]<='Z')
            return false;
    }
    for(i=0;i<len-1;i++)
    {
        if(cache[i]=='_'&&cache[i+1]=='_')
            return false;
    }
    return true;
}
void java_to_cpp()
{
    int i;
    for(i=0;i<len;i++)
    {
        if(cache[i]>='A' && cache[i]<='Z')
            printf("_"),cache[i]+=32;
        printf("%c",cache[i]);
    }
}
void cpp_to_java()
{
    int i;
    for(i=0;i<len;i++)
    {
        if(cache[i]=='_')
            cache[i+1]-=32;
        else
            printf("%c",cache[i]);
    }
}
int main()
{
    scanf("%s",cache);
    len=strlen(cache);
    if(!(cache[0]>='a' && cache[0]<='z'))
    {
        printf("Error!");
    }
    else if(isJava())
    {
        java_to_cpp();
    }
    else if(isCpp())
    {
        cpp_to_java();
    }
    else
    {
        printf("Error!");
    }
    return 0;
}
