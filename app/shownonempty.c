#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static void shownonempty_line(int index, char* contents, int cursor, void* data);

void shownonempty(text txt)
{
    process_forward(txt, shownonempty_line, NULL);
}

static void shownonempty_line(int index, char* contents, int cursor, void* data)
{
    /* Функция обработчик всегда получает существующую строку*/
    //assert(contents != NULL);

    /* Декларируем неиспользуемые параметры*/
    UNUSED(data);
    UNUSED(index);


    if ((contents[0])!='\0') 
    { 
	
	int i; 
/* Посимвольная обработка строки */ 
	int length = strlen(contents); 
	for(i=0; i <= length ; i++){ 
	    if (i == cursor ){ 
		putchar('|');
	    
		if (cursor == length) 
		    putchar('\n');
	    }
	    putchar(contents[i]); 
	 
	} 
    }
}
