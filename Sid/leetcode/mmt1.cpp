<!-- Auto suggest
Given a dictionary consisting of N words and a query word S. You need to auto-suggest the best word from the dictionary that is closest to S.

Two words are first compared by their Levenshtein distance to the word S. If two words have the same Levenshtein distance, then the lexicographically smaller word is given priority.

Notes

Levenshtein distance between two strings is defined as the minimum number of edits required to obtain one string from the other. An “edit” is defined by either an insertion of a character, a deletion of a character, or a replacement of a character.
Levenshtein distance between "abc" with "ac" is 1 (deletion of c),  with "abd" is 1 (replacement of c to d) and with "abcd" is 1 (insertion of d).
All the words and the query word S consist of lowercase alphabets only.
 

Function description

Complete the function solve. This function takes the following 3 parameters and returns the required answer:

N: Represents the number of words in the dictionary
words: Represents the dictionary
S: Represents the query word
Input format for custom testing

Note: Use this input format if you are testing against custom input or writing code in a language where we don’t provide boilerplate code.

The first line contains a single integer N denoting the value of N.
The second line contains N space-separated strings denoting the words in the dictionary.
The third line contains a single string denoting the query word S.
Output format

Return a single line containing the answer.

Constraints




Sample input

5
tocor torect tocfrrec tocorre tocofecd
tocorrect
Sample output

tocfrrec -->