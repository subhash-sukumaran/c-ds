#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<math.h>


void rev_s(char *str, char * ptr)
{
	char c;

	while(str < ptr) 
	{
		c= *ptr;
		*ptr = *str;
		*str = c;

		str++;
		ptr--;	
	}
	
}



void rev(char *str)
{
	char *ptr;
	int l = strlen(str);

	rev_s(str,str+l-1);
	printf("%s\n",str);

	while(*str) 
	{
		ptr = str;

		while( (*ptr != '\0') && (*ptr != ' ') )
		{
			ptr++;
		} 	

		ptr--;
		rev_s(str,ptr);	

		str = ptr;

		str++;
		
		while( (*str != '\0') && (*str == ' ') )
		{
			str++;
		} 	
	}
}





void check_palindrome( char *str)
{
	char *ptr;
	
	ptr = str + strlen(str)-1;
	while(str < ptr)
	{
		if(*str != *ptr) {
			printf("not a palindrome\n");
			return;
		}
		str++;
		ptr--;
						
	}

	printf("palindrome\n");

	return;
}


void comp(char *str)
{
	char *ptr = str;
	
	while(*str)
	{
		if(*str != ' ') {
			*ptr++ = *str;
			
		}

		str++;
	}

	*ptr = '\0';	
}





int main()
{
#if 0
	char buf[] = "how are you";

	printf("%s\n",buf);

	rev(buf);
	
	printf("%s\n",buf);
	check_palindrome("maliayalam");
#endif 
	char str[] = "ha ha ha";

	comp(str);

	printf("%s\n",str);
	
	return 0;
}
	
