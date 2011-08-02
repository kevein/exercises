#include <stdio.h>

int
main()
{
int i = 0;

scanf ("%d", i); /* should have used &i */
printf ("%d\n", i);
return 0;
}
