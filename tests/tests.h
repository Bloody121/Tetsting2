#pragma once

#include <limits.h>
#include <string.h>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C" {
    #include "../app/text/_text.h"
    #include "../app/text/text.h"
    #include "../app/common.h"
}

using namespace testing;

TEST(test1, tests)
{
    EXPECT_NE(create_text(), nullptr);
}

TEST(test2, tests)
{
    text txt = create_text();
    load(txt, "<filename>");

    EXPECT_EQ(txt->length, 0);
}

TEST(test3, tests)
{
    text txt = create_text();
    load(txt, "/etc/shadow");

    EXPECT_EQ(txt->length, 0);
}

TEST(test4, tests)
{
    text txt = create_text();
    load(txt, "input.txt");

    EXPECT_EQ(txt->cursor->position, 0); //5
}

TEST(test5, tests)
{
    text txt = create_text();
    show(txt);
    shownonempty(txt);

    EXPECT_EQ(txt->cursor->position, 0);
}

TEST(test6, tests)
{
    text txt = create_text();
    load(txt, "input.txt");

    //EXPECT_NE(txt->length, 0);
    save(txt, "test.txt");
    EXPECT_NE(fopen("test.txt", "r"), nullptr);
}

TEST(test7, tests)
{
    text txt = create_text();
    const char* contents = "TEST";
    load(txt, "input.txt");

    EXPECT_NO_FATAL_FAILURE(append_line(txt, contents););
    EXPECT_NE(txt->length, 0);
}

TEST(test8, tests)
{
    text txt = create_text();
    char contents[10000];
    load(txt, "input.txt");
    for (; strlen(contents) < 10000; strcat(contents, "TEST"));

    EXPECT_EXIT(append_line(txt, contents), ::testing::ExitedWithCode(EXIT_FAILURE), "");
}


TEST(test9, tests)
{
    text txt = create_text();
    load(txt, "long.txt");
    rc(txt);

    EXPECT_EQ(txt->length, 0); //2
}

TEST(test10, tests)
{
    text txt = create_text();
    rc(txt);

    EXPECT_EQ(txt->begin, nullptr);
    EXPECT_EQ(txt->end, nullptr);
}

TEST(test11, tests)
{
    text txt = create_text();
    load(txt, "input.txt");
    remove_all(txt);

    EXPECT_NE(txt, nullptr);
    EXPECT_EQ(txt->length, 0);
}

TEST(test12, tests)
{
    text txt = nullptr;
    remove_all(txt);

    EXPECT_EQ(txt, nullptr);
}

TEST(test13, tests)
{
    text txt = create_text();
    load(txt, "input.txt");
    m(txt, 0, 2);

    EXPECT_EQ(txt->cursor->position, 0);//5
}

TEST(test14, tests)
{
    text txt = create_text();
    load(txt, "input.txt");
    m(txt, -1, -1);

    EXPECT_EQ(txt->cursor->position, 0);
}

TEST(test15, editortests)
{
    text txt = create_text();
    load(txt, "input.txt");
    mwbb(txt);

    EXPECT_EQ(txt->cursor->position, 0);
}
