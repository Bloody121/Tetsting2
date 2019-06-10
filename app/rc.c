/**
 * rc.c -- реализует команду удаления текущей строки
 *
 * Copyright (c) 2017, Aleksey <trifonov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h> 
#include <assert.h> 
#include <ctype.h> 
#include <string.h> 
#include "common.h" 
#include "text/text.h"

static void delete_line(int index, char *contents, int cursor, void *data);

/** 
* Удаляет текущую строку 
*/
 void rc(text txt)
 {
     /* Применяем функцию к каждой строке */
     process_forward(txt, delete_line, txt);
 } 

 static void delete_line(int index, char *contents, int cursor, void *data) 
 { 
     assert(contents != NULL); 
     
     if (cursor >= 0)
     {
	 m(data,index,1);
     _delete(data, index+1);
     }
 }
