/**
 * save.c -- реализует команду сохранения текста
 *
 * Copyright (c) 2018, Aleksey <trifonov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <stdlib.h>

static void save_line(int index, char *contents, int cursor, void *data);

/**
 * Сохраняет текст в указанный файл
 */
void save(text txt, char* filename)
{
    FILE* f;
    /* Открываем файл для записи, контролируя ошибки */
    if ((f = fopen(filename, "w")) == NULL) {
        printf("The file %s cannot be opened\n", filename);
        return;
    }
    process_forward(txt, save_line, f);
}

/**
 * Сохраняет текст в указанный файл
 */
static void save_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);

    /* Записываем строку в файл */
    fprintf((FILE*) data, "%s", contents);
    fflush((FILE*) data);
}

