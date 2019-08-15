#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<math.h>
#include<stdarg.h>


int myatoi(char *str)
{
	int i=0;

	while(*str) {
		i = i*10 + (*str - '0');	
		str++;
	}	
	return i;	
}

void mystrstr(char *str, char *s)
{
	while(*str)
	{
		char *s1 = str;
		char *s2 = s;
		while(*s1++ == *s2++);
	
		s2--;	
		if(*s2 == '\0') {
			printf("string found\n");
		}
 
		str++;	
	}	
}

void rab_karp(char *text, char *pat)
{
	int i,j,m,n,h,p,t;
	int prime = 101;
	int d = 256;
	char *start = text;
	
	n = strlen(text);
	m = strlen(pat);

	//find h= pow(d,m-1)
	h=1;
	p=t=0;
	
	for(i=0;i<m-1;i++)
		h = (h*d)%prime;

	//hash of txt window and pat

	for(i=0; i<m; i++)
	{
		p = ((p*d) + pat[i]) % prime;
		t = ((t*d) + text[i]) % prime;

		//printf("hash p: %d t: %d\n",p,t);
	}

	while(n-m)
	{
		if(p == t) {
			char *s1,*s2;
			s1 = text;
			s2 = pat;

			//printf("hash matched\n");

			while(*s1++ == *s2++);
			s2--;
			s1--;
			if(*s2 == '\0') {
				printf("string found at index %ld\n",s1-start);
			}
		}
		//rehash
		t = ( (d*(t - (*(text) * h))) + *(text+m)) % prime;

		if(t<0)
			t = t+ prime;

		//printf("re hash t: %d\n",t);
		text++;
		n--;
	} 
	
}


void myitoa(int i, char *buf, int base)
{
	char *str = "0123456789abcdef";

	int size = 64;
	buf[--size] = '\0';
	
	while(i)
	{
		buf[--size] = str[i%base];
		i = i/base;		
	}

	puts(buf+size);	
}

void my_printf(char *fmt,... )
{
	va_list argp;
	int d;
	char c, *s;
	char buf[64];

	va_start(argp, fmt);

	while(*fmt)
	{
		if(*fmt != '%') {
			putc(*fmt, stderr);
			fmt++;
			continue;
		}
		fmt++;
			
		switch(*fmt++)
		{
			case 'o':
				d = va_arg(argp,int);
				myitoa(d,buf,8); 
				//puts(buf);
				break;
			case 'x':
				d = va_arg(argp,int);
				myitoa(d,buf,16); 
				//puts(buf);
				break;
			case 'd':
				d = va_arg(argp,int);
				myitoa(d,buf,10); 
				//puts(buf);
				break;
			case 'c':
				c = (char)va_arg(argp,int);
				putc(c,stderr);
				break;
			case 's':
				s = va_arg(argp, char*);
				puts(s);
				break;
		}
	}	
	va_end(argp);	
}

int main()
{
	int d;
	char *str = "ohohihohohoellohowoho";

	//d = myatoi(str);
	//printf("%d\n",d);
	//mystrstr(str,"oho" );
	//rab_karp(str,"oho" );
	d=256;
	my_printf("str %s int %d 0x%x %o\n",str,d,d,d);
	printf("\n");
	return 0;
}
	
