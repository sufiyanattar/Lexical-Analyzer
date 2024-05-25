#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>


void lexical_analyser(char *arr);
int operator(char);
int keyword(char *str);
int integer (char);
int literals(char *token);
int directive(char);
int comment(char *token);

int main(int argc,char *argv[])
{
    if(argc > 1)
    {
	int i=0;
	char dup[100];
	if(strcmp(strstr(argv[1],"."),".c") == 0)
	{
	    FILE *fptr;
	    fptr=fopen(argv[1],"r");
	    if(fptr == NULL)
	    {
		printf("no data found\n");
		return 0;
	    }
	    else
	    {
		printf("Open     : text.c  : Success\n");
		printf("Parsing  : text.c  : Started\n");
	    }
	    while(fgets(dup,sizeof(dup),fptr) != NULL)
	    {
		lexical_analyser(dup);
	    }
	    fclose(fptr);
	}
	else
	{
	    printf("please pass the .c file format\n");
	}
    }
    else
    {
	printf("please pass the .c file\n");
    }
    return 0;
}


void lexical_analyser(char *arr)
{
    int i=0,j=0,flag =0;
    while(arr[j] != '\0')
    {
	char ch;
	char dup[100];
	ch = arr[j];
	if(operator(ch))
	{
	    printf("operator : %c\n",ch);
	    if(i>0)
	    {
		dup[i] = '\0';
		printf("identifiers is : %s\n",dup);
		i=0;
	    }
	}
	else if(directive(ch))
	{
	    printf("dircetive is : %c\n",ch);
	    if(i>0)
	    {
		dup[i] = '\0';
		printf("identifiers is : %s\n",dup);
		i=0;
	    }
	}
	else if(integer(ch))
	{
	    printf("integer is : %c\n",ch);
	    if(i>0)
	    {
		dup[i] = '\0';
		printf("identifiers is : %s\n",dup);
		i=0;
	    }
	}
	else if(ch == '/')
	{
	    if ((ch = arr[j+1]) == '/')
	    {
		int l=0;
		while(arr[j] != '\0')
		{
		    dup[l] =arr[j];
		    j++;
		    l++;
		}
		dup[l]='\0';
		printf("comments is  : %s",dup);
	    }
	    else
		printf("operator is : %c",ch);
	    i=0;
	}
	else if(ch == '"')
	{
	    int l=0;
	    dup[l]='"';
	    l=l+1;
	    j=j+1;
	    while(arr[j] != '"' && arr[j] != '\0')
	    {
		dup[l] = arr[j];
		j++;
		l++;
	    }
	    dup[l]='"';
	    l=l+1;
	    dup[l]='\0';
	    printf("literal is : %s\n",dup);
	    i=0;
	}
	else if( ch == ' ' || ispunct(ch))
	{
	    if(i>0)
	    {
		dup[i]= '\0';
		if(keyword(dup))
		{
		    printf("keyword is : %s\n",dup);
		}
		else
		{
		    printf("Identifiers is : %s\n",dup);
		}
		i=0;
	    }
	}
	else
	{
	    if(ch != ' ')
		dup[i++] = ch;
	}
	j++;
    }
}



int operator(char ch)
{
    if(ch == '+'|| ch == '-' || ch == '%' || ch == '*' || ch == '<'|| ch == '!' || ch == '=' || ch == '&' || ch == '~' ||
	    ch == '|' || ch == '^' || ch == '{' || ch == '}' || ch == '(' || ch == ')'|| ch == '>' || ch  == ';' || ch == ',' || ch == '.')
    {
	return 1;
    }
    else
    {
	return 0;
    }
}


int keyword(char *str)
{
    char *keyword[] ={"int","char","double","float" ,"auto" , "break" , "case" ,"continue","default","else", "extern" ,"return" ,"const" ,"static","long"
	,"unsigned" ,"signed", "while","typedef" ,"short" ,"struct","void","for" ,"goto" ,"register", "switch" , "union"};
    int numkeywords = sizeof(keyword) / sizeof(keyword[0]);
    for(int i=0;i<numkeywords;i++)
    {
	if(strcmp(str,keyword[i]) == 0)
	{
	    return 1;
	}
    }
    return 0;
}


int integer (char ch)
{
    if( ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
    {
	return 1;
    }
    else
    {
	return 0;
    }
}

int directive(char ch)
{
    if(ch == '#')
    {
	return 1;
    }
    return 0;
}





