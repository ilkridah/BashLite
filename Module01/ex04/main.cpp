
#include<iostream>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    return 0;
}