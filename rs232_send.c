/* rs232_send.c*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>  
#include <string.h>
#include <unistd.h>
#include <errno.h>    
#include <stdlib.h>
#define   BAUDRATE 	B9600     //9600
#define   MODEMDEVICE    "/dev/ttyS0"
int main()
{
    int     fd,c=0,res;
    struct termios oldtio,newtio;
    int    ch;
    static char s1[20],buf[19];
    printf("start ...\n");
    /*打开PC的COM1口*/
    fd = open(MODEMDEVICE,O_RDWR|O_NOCTTY);
    if (fd<0)
    {
       perror(MODEMDEVICE);
       exit(1);
    }
    printf("open...\n");
    /*将旧的通讯参数存入oldtio结构*/
    tcgetattr(fd,&oldtio);
    /*初始化新的newtio */
    bzero(&newtio,sizeof(newtio));
    /*8N1*/
    newtio.c_cflag = BAUDRATE|CS8|CLOCAL|CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
   
    /*正常模式*/
    /*newtio.c_lflag = ICANON;*/
      
    /*非正常模式*/
    newtio.c_lflag = 0;
    newtio.c_cc[VTIME] = 0;
    newtio.c_cc[VMIN] = 10;
       
    tcflush(fd,TCIFLUSH);
    /*新的temios作为通讯端口参数*/
    tcsetattr(fd,TCSANOW,&newtio);
    printf("writing...\n");
    printf("%d\n", '\r');
   
    while(1)
    {
 //    res = read(fd,buf,10);
       res = read(STDIN_FILENO,buf,10);
       printf("%d\n", '\n');
       res = write(fd,buf,7);
       if(buf[0]==10) break;
    }
   
    printf("close...\n");
    close(fd);
    close(STDIN_FILENO);
    /*还原旧参数*/
    tcsetattr(fd,TCSANOW,&oldtio);
    return 0;
} 
