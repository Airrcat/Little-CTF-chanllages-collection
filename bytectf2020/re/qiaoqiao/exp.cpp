#include<stdio.h>
#include<string.h>
#include<windows.h>
void * sub_401180(const char *a1)
{
  int v2; // [rsp+8h] [rbp-38h]
  char v3; // [rsp+Fh] [rbp-31h]
  int i; // [rsp+10h] [rbp-30h]
  char *v5; // [rsp+18h] [rbp-28h]
  int v6; // [rsp+28h] [rbp-18h]

  if ( !a1 )
    return 0LL;
  v6 = strlen(a1);
  if ( v6 & 1 )
    return 0LL;
  v5 = (char*)malloc(v6 >> 1);
  memset(v5, 0, v6 >> 1);
  for ( i = 0LL; i < v6; ++i )
  {
    v3 = a1[i];
    if ( v3 < '0' || v3 > '9' )
    {
      if ( v3 < 'A' || v3 > 'F' )
      {
        if ( v3 > 'a' || v3 > 'f' )
          return 0LL;
        v2 = v3 + 'a' - 10;
      }
      else
      {
        v2 = v3 + 'A' - 10;
      }
    }
    else
    {
      v2 = v3 + '0';
    }
    *((char *)v5 + (i >> 1)) += v2 << 4 * ((i + 1) & 1);
    printf("%c",v2 << 4 * ((i + 1) & 1));
  }
    printf("\n%s",(char*)v5);
  return (char*)v5;
}
int main()
{
	char c[255] = "d2h5IG5vdCBnbyBob21l";
	char *d = (char*)malloc(255);
//	sub_401180(c);
	memset(d,0x32,3); 
	printf("%d",0x35>>(4*((3+1)&1)));
	//6b6
 } 
