/*
 * Utilities library for libgit2 examples
 *
 * Written by the libgit2 contributors
 *
 * To the extent possible under law, the author(s) have dedicated all copyright
 * and related and neighboring rights to this software to the public domain
 * worldwide. This software is distributed without any warranty.
 *
 * You should have received a copy of the CC0 Public Domain Dedication along
 * with this software. If not, see
 * <http://creativecommons.org/publicdomain/zero/1.0/>.
 */
#ifndef GIT2_COMMON_H_
#define GIT2_COMMON_H_

/**
 * Check libgit2 error code, printing error to stderr on failure and
 * exiting the program.
 */
extern void check_lg2(int error, const char *message, const char *extra);

/**
 * Exit the program, printing error to stderr
 */
extern void fatal(const char *message, const char *extra);

#endif
