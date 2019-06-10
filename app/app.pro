TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        editor.c \
        load.c \
        m.c \
        mwbb.c \
        rc.c \
        save.c \
        show.c \
        shownonempty.c \
        text/append_line.c \
        text/change_coursor_position.c \
        text/create_text.c \
        text/delete.c \
        text/delete_line.c \
        text/process_forward.c \
        text/remove_all.c

HEADERS += \
    common.h \
    text/_text.h \
    text/text.h


QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CFLAGS += -fprofile-arcs \
    -ftest-coverage
LIBS += -lgcov
