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

#include "git2/common.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

void check_lg2(int error, const char *message, const char *extra)
{
    const git_error *lg2err;
    const char *lg2msg = "", *lg2spacer = "";

    if (!error)
        return;

    if ((lg2err = giterr_last()) != NULL && lg2err->message != NULL) {
        lg2msg = lg2err->message;
        lg2spacer = " - ";
    }

    if (extra)
        fprintf(stderr, "%s '%s' [%d]%s%s\n",
            message, extra, error, lg2spacer, lg2msg);
    else
        fprintf(stderr, "%s [%d]%s%s\n",
            message, error, lg2spacer, lg2msg);

    exit(1);
}

void fatal(const char *message, const char *extra)
{
    if (extra)
        fprintf(stderr, "%s %s\n", message, extra);
    else
        fprintf(stderr, "%s\n", message);

    exit(1);
}
