#include <stdio.h> 
#include <assert.h> 
#include "common.h" 
#include "text/text.h" 
#include <ctype.h> 
#include <stdlib.h> 

static void move_cursor_left(int index, char (*contents), int cursor, void*data); 

 void mwbb(text txt) 
 {
     /*Применяем функцию к каждой строке */
 process_forward(txt, move_cursor_left, txt); 
 } 
 static void move_cursor_left(int index, char (*contents), int cursor, void*data) 
 { 
     assert(contents != NULL); 

     UNUSED(data); 

     if (cursor > 0)
     { 
/* Пока непробельный символ или не начало строки двигаем курсор влево */ 
	 while(cursor > -1 && !isspace(contents[cursor])){ 
	     cursor--; 
     } 
	 cursor++;
/* Переставляем курсор на новую позицию */ 
     m(data, index + 1, cursor + 1); 

     } 
} 
