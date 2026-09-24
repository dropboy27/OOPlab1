#include "str_ops.h"
#include <iostream>

std::size_t str_len(const char *s)
{
	size_t len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return len;
}

void str_copy(char *dst, const char *src)
{
	std::size_t curr = 0;
	while (src[curr] != '\0')
	{
		dst[curr] = src[curr];
		curr++;
	}
	dst[curr] = src[curr];
}

char *str_alloc(const char *src)
{
	std::size_t length = str_len(src) + 1;
	char *new_str = new char[length];
	str_copy(new_str, src);
	return new_str;
}

void str_delete(char *&s)
{
	delete[] s;
	s = nullptr;
}

void str_print(const char *s)
{
	std::size_t curr = 0;
	while (s[curr] != '\0')
	{
		std::cout << s[curr];
		curr++;
	}
}

std::size_t str_count_words(const char *s)
{
	std::size_t len = str_len(s);
	if (len == 0)
	{
		return 0;
	}
	std::size_t count = 0;
	if (s[0] != ' ')
	{
		count++;
	}

	for (std::size_t i = 1; i < len; i++)
	{
		if (s[i - 1] == ' ' && s[i] != ' ')
		{
			count++;
		}
	}
	return count;
}

bool str_find_substr(const char *s, const char *sub, int &out_pos)
{
	if (sub[0] == '\0')
	{
		return false;
	}
	std::size_t curr = 0;
	std::size_t sub_size = str_len(sub);
	std::size_t s_size = str_len(s);
	if (sub_size > s_size)
	{
		return false;
	}
	for (std::size_t i = 0; i <= s_size - sub_size; i++)
	{
		std::size_t j = 0;
		while (j < sub_size && s[i + j] == sub[j])
		{
			j++;
		}
		if (j == sub_size)
		{
			out_pos = i;
			return true;
		}
	}
	return false;
}
