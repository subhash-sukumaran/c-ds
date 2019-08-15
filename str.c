#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<math.h>


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



int main()
{
	int d;
	char *str = "ohohihohohoellohowoho";

	//d = myatoi(str);
	//printf("%d\n",d);
	//mystrstr(str,"oho" );
	//rab_karp(str,"oho" );
	my_printf();
	printf("\n");
	return 0;
}
	
