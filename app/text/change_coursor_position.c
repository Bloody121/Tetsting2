
/**
 * change_cursor_position -- реализует перемещение курсора
 *
 * Copyright (c) 2018, Aleksey <trifonov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "_text.h"
#include "text.h"
#include <stdlib.h>
#include <ctype.h>

void change_cursor_position(text txt, int new_line, int new_position)
{
  new_line--;
  new_position--;
  if (new_line < 0 || (int)new_line > (int)txt->length || new_position < 0){
    return;
  }
  node *p;
  p = txt->begin;
  for (int i = 0; i < new_line; i++){
    p = p->next;
  }
  if ((int)new_position > (int)strlen(p->contents)){
      return;
  }
  txt->cursor->position = new_position;
  txt->cursor->line = p;
}
