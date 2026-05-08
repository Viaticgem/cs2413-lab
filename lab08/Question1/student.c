#include <stdio.h>

/*
Question 1: Longest Common Prefix

Write a function to find the longest common prefix string
among an array of strings.

A prefix is the beginning part of a string.

Examples:
Input: ["flower", "flow", "flight"]
Output: "fl"

Input: ["dog", "racecar", "car"]
Output: ""

IMPORTANT:
- You ARE allowed to modify the first string (strs[0])
- You should store the result directly in strs[0]
- Return strs[0] as the result
*/

#include <stdio.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    int prefixLen = 0;

    while (strs[0][prefixLen] != '\0') {
        char currentChar = strs[0][prefixLen];

        for (int i = 1; i < strsSize; i++) {
            if (strs[i][prefixLen] == '\0' || strs[i][prefixLen] != currentChar) {
                strs[0][prefixLen] = '\0';
                return strs[0];
            }
        }

        prefixLen++;
    }

    return strs[0];
}
