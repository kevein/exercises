#include <stdio.h>
#include </usr/include/elf.h>
void func32(Elf32_Ehdr*);
int main(int argc,char *argv[])
{
    char **p=argv;
    FILE *fp;
    Elf32_Ehdr elf_hdr;
    int i=1,j;
    printf("******************readelf*******************\n");
    /*循环读命令行中给出的文件*/
    while(i<argc)
   
    {
        printf("this is file \"%s\"!\n",p[i]);
        fp=fopen(p[i],"rb");
        if(!fp)
        {
            printf("cannot open file %s\n",p[i]);
            i++;
            continue;
        }
        fread(&elf_hdr,52,1,fp);
        /*读入完毕*/
        fclose(fp);
        /*一个ELF文件的第1 2 3 4个字符应该分别等于0x7f 0x45(E) 0x4c(L) 0x46(F)*/                                if(elf_hdr.e_ident[0]!=0x7f||elf_hdr.e_ident[1]!=0x45||elf_hdr.e_ident[2]!=0x4c||elf_hdr.e_ident[3]!=0x46)
        {
            printf("file %s is not a elf!\n",p[i]);
            i++;
            continue;/*如果不是，就分析下一个*/
        }
        if(elf_hdr.e_ident[4]==1)/*e_ident[4]为1说明是32位，为2是64位，对于64位不予考虑*/
        {
            printf("32位\n");
            func32(&elf_hdr);
        }
        i++;
        printf("the end!\n");
    }

    return 0;
}

void func32(Elf32_Ehdr *p)
{
    int i;
    if(p->e_type==1)
        printf("可从定位文件\n");
    else if(p->e_type==2)
        printf("可执行文件\n");
    else if(p->e_type==3)
        printf("动态连接文件\n");
    if(p->e_machine==3)
        printf("i386\n");
    else if(p->e_machine==62)
        printf("amd64\n");
    printf("version:%d\n",p->e_version);
    printf("entry:%x\n",p->e_entry);
    printf("progrem header table:%x size:%x num:%x\nsection header table:%x size:%x num:%x\n",p->e_phoff,p->e_phentsize,p->e_phnum,p->e_shoff,p->e_shentsize,p->e_shnum);
    printf("elf size:%x\n",p->e_ehsize);
    printf("str dx:%x\n",p->e_shstrndx);
   
    return;
}
