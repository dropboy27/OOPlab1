#include <gtest/gtest.h>
#include "str_ops.h"

TEST(StrLen, EmptyString)
{
    EXPECT_EQ(str_len(""), 0);
}

TEST(StrLen, RegularString)
{
    EXPECT_EQ(str_len("hello"), 5);
}

TEST(StrLen, StringWithSpaces)
{
    EXPECT_EQ(str_len("hello world"), 11);
}

TEST(StrLen, OneLetter)
{
    EXPECT_EQ(str_len("h"), 1);
}

TEST(CountWords, EmptyString)
{
    EXPECT_EQ(str_count_words(""), 0);
}

TEST(CountWords, OneWord)
{
    EXPECT_EQ(str_count_words("hello"), 1);
}

TEST(CountWords, RegularString)
{
    EXPECT_EQ(str_count_words("hello world"), 2);
}

TEST(CountWords, Space)
{
    EXPECT_EQ(str_count_words(" "), 0);
}

TEST(FindSub, ReularString)
{
    int pos;
    EXPECT_TRUE(str_find_substr("hello world", "rld", pos));
    EXPECT_EQ(pos, 8);
}

TEST(FindSub, EmptySub)
{
    int pos;
    EXPECT_FALSE(str_find_substr("hello world", "", pos));
}

TEST(FindSub, EmptyString)
{
    int pos;
    EXPECT_FALSE(str_find_substr("", "rld", pos));
}

TEST(Allocate, RegularString)
{
    char *result = str_alloc("hello world");
    EXPECT_STREQ(result, "hello world");
    str_delete(result);
}

TEST(Allocate, EmptyString)
{
    char *result = str_alloc("");
    EXPECT_STREQ(result, "");
    str_delete(result);
}

TEST(Copy, RegularString)
{
    const char *src = "hello world";
    char *dst = new char[str_len(src) + 1];
    str_copy(dst, src);
    EXPECT_STREQ(dst, "hello world");
    delete[] dst;
}

TEST(Copy, EmptyString)
{
    const char *src = "";
    char *dst = new char[str_len(src) + 1];
    str_copy(dst, src);
    EXPECT_STREQ(dst, "");
    delete[] dst;
}

TEST(StrAlloc, CopiesContent)
{
    char *copy = str_alloc("hello");
    EXPECT_STREQ(copy, "hello");
    str_delete(copy);
    EXPECT_EQ(copy, nullptr);
}