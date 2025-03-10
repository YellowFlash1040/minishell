/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 17:35:18 by akovtune      #+#    #+#                 */
/*   Updated: 2025/03/10 14:43:25 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdbool.h>
# include <stdlib.h>

typedef char*	t_string;

/**
 * @brief Computes the length of a string.
 *
 * This function calculates the number of characters in the string `str`,
 * excluding the null-terminator.
 *
 * @param str The string whose length is to be calculated.
 * @return The length of the string.
 */
int		ft_strlen(char *str);

/**
 * @brief Finds the first occurrence of a character in a string.
 *
 * This function returns the index of the first occurrence of the character `c`
 * in the string `str`. If the character is not found, it returns -1.
 *
 * @param c The character to search for.
 * @param str The string to search within.
 * @return The index of the first occurrence of `c` in `str`, or -1 if not found.
 */
int		index_of(char c, char *str);

/**
 * @brief Finds the last occurrence of a character in a string.
 *
 * This function returns the index of the last occurrence of the character `c`
 * in the string `str`. If the character is not found, it returns -1.
 *
 * @param c The character to search for.
 * @param str The string to search within.
 * @return The index of the last occurrence of `c` in `str`, or -1 if not found.
 */
int		last_index_of(char c, char *str);

/**
 * @brief Compares two strings.
 *
 * This function compares the strings `s1` and `s2`. It returns true if the
 * strings are equal, and false otherwise.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return True if the strings are equal, false otherwise.
 */
bool	ft_strcmp(char *s1, char *s2);

/**
 * @brief Duplicates a string.
 *
 * This function allocates memory for a new string and copies the content of
 * the string `str` into it. The returned string should be freed when no longer
 * needed.
 *
 * @param str The string to duplicate.
 * @return A pointer to the newly allocated string that is a copy of `str`.
 */
char	*ft_strdup(char *str);

/**
 * @brief Replaces all occurrences of a character in a string
 * with another character.
 *
 * This function iterates through the given string and replaces all instances
 * of the character `old` with the character `new`. The replacement is done
 * directly on the string passed as the argument, so no new string is returned.
 *
 * @param str The string in which the characters will be replaced.
 * It must be a null-terminated string.
 * @param old The character to be replaced.
 * @param new The character that will replace `old`.
 *
 * @note The input string `str` is modified in place.
 * @note Usage example:
 * @note ```c
 * char str[] = "hello world";
 * replace(str, 'o', 'a');
 * printf("%s\n", str);  // Output: "hella warld"
 * ```
 */
void	replace(char *str, char old, char new);

/**
 * @brief Concatenates two strings into a new dynamically allocated string.
 *
 * This function takes two input strings, allocates enough memory to hold
 * both strings plus a null-terminator, and concatenates them into a new string.
 * The function returns the newly created string
 * or `NULL` if the memory allocation fails.
 *
 * @param s1 The first string to be concatenated. It may be `NULL`.
 * @param s2 The second string to be concatenated. It may be `NULL`.
 *
 * @return A pointer to the newly created string containing the concatenation
 *         of `s1` and `s2`, or `NULL` if memory allocation fails.
 *
 * @note The caller is responsible for freeing the returned string,
 * and the given strings `s1`, `s2`.
 * @note Usage example:
 * @note ```c
 * char *result = ft_strjoin("Hello, ", "world!");
 * printf("%s\n", result);  // Output: "Hello, world!"
 * free(result);  // Don't forget to free the memory.
 * ```
 */
char	*ft_strjoin(char *s1, char *s2);

/**
 * @brief Creates a substring from a given string starting at a specified index.
 *
 * This function extracts a substring from the input string `s`,
 * starting from the index `start`
 * and with a maximum length of `len`.
 * If the `start` index is greater than or equal to the length of
 * the string, the function returns an empty string.
 * If `start + len` exceeds the length of the string,
 * the length of the substring is adjusted
 * to fit the remaining portion of the string.
 *
 * @param s The string from which to extract the substring.
 * It must be a null-terminated string.
 * @param start The starting index from which to begin the substring extraction.
 * @param len The maximum length of the substring to be extracted.
 *
 * @return A newly allocated string containing the extracted substring,
 * or NULL if memory allocation fails.
 *         The returned string is null-terminated.
 *
 * @note The caller is responsible for freeing the memory
 * of the returned substring.
 *
 * @example
 * char *str = "Hello, world!";
 * char *substr = ft_substr(str, 7, 5);
 * printf("%s\n", substr);  // Output: "world"
 * free(substr);  // Don't forget to free the memory!
 */
char	*ft_substr(char *s, unsigned int start, size_t len);

/**
 * @brief Splits a string into an array of substrings
 * based on a delimiter character.
 *
 * This function splits the input string `s` into an array of substrings,
 * each separated by the character `c`.
 * The function returns a dynamically allocated array of strings,
 * with each substring as an element in the array.
 * `The array is null-terminated`,
 * and the caller is responsible for freeing the memory
 * used by the array and its contents.
 *
 * @param s The string to be split. It must be a `null-terminated string`.
 * @param c The delimiter character used to split the string.
 *
 * @return A pointer to an array of strings (substrings),
 * or NULL if memory allocation fails or an error occurs.
 * The array is terminated with a NULL pointer.
 *
 * @note The caller is responsible for freeing the array of substrings
 * and each individual string.
 * @note Usage example:
 * @note ```c
 * char *s = "hello world how are you";
 * char **result = ft_split(s, ' ');
 * for (int i = 0; result[i] != NULL; i++)
 *     printf("%s\n", result[i]);
 * // Output:
 * // hello
 * // world
 * // how
 * // are
 * // you
 *
 * // Freeing the memory after use:
 * for (int i = 0; result[i] != NULL; i++)
 *     free(result[i]);
 * free(result);
 * ```
 */
char	**ft_split(char *s, char c);

/**
 * @brief Extracts a word from a string starting at the current index.
 *
 * This function extracts a word from the string `s` starting at the index
 * `i` and ending at the next occurrence of the delimiter character `c`.
 * The index `i` is updated to point to the character after the extracted word.
 *
 * @param s The string to extract the word from.
 * @param i The current index in the string,
 * which will be updated after the word extraction.
 * @param c The delimiter character used to separate words.
 * @return A newly allocated string containing the extracted word.
 */
char	*extract_word(char *s, int *i, char c);

/**
 * @brief Counts the number of words in a string separated by a delimiter.
 *
 * This function counts the number of words in the string `s`, where words are
 * delimited by the character `delimiter`. A word is defined as a sequence of
 * characters that are not the delimiter, and the function ignores leading and
 * trailing delimiters.
 *
 * @param s The string in which to count words.
 * @param delimiter The character that separates words in the string.
 * @return The number of words in the string.
 */
int		count_words(char *s, char delimiter);

int		is_whitespace(char c);

char	*ft_strchr(char *str, char c);

#endif
