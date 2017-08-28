/*
 * libgit2 "rev-parse" example - shows how to parse revspecs
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
#include "git2/rev-parse.h"

#include <ctime>
#include <iostream>

#include <stdio.h>

/**
 * [parse_revision description]
 * @param  ps [description]
 * @return    [description]
 */
int parse_revision(struct parse_state *ps, char *spec)
{
    git_revspec rs;
    char str[GIT_OID_HEXSZ + 1];

    git_libgit2_init();

    if (!ps->repo) {
        if (!ps->repodir)
            ps->repodir = ".";
        check_lg2(git_repository_open_ext(&ps->repo, ps->repodir, 0, NULL),
            "Could not open repository from", ps->repodir);
    }

    ps->spec = spec;

    check_lg2(git_revparse(&rs, ps->repo, ps->spec), "Could not parse", ps->spec);

    if ((rs.flags & GIT_REVPARSE_SINGLE) != 0) {
        git_oid_tostr(str, sizeof(str), git_object_id(rs.from));
        printf("%s\n", str);
        git_object_free(rs.from);
    }
    else if ((rs.flags & GIT_REVPARSE_RANGE) != 0) {
        git_oid_tostr(str, sizeof(str), git_object_id(rs.to));
        printf("%s\n", str);
        git_object_free(rs.to);

        if ((rs.flags & GIT_REVPARSE_MERGE_BASE) != 0) {
            git_oid base;
            check_lg2(git_merge_base(&base, ps->repo,
                        git_object_id(rs.from), git_object_id(rs.to)),
                    "Could not find merge base", ps->spec);

            git_oid_tostr(str, sizeof(str), &base);
            printf("%s\n", str);
        }

        git_oid_tostr(str, sizeof(str), git_object_id(rs.from));
        printf("^%s\n", str);
        git_object_free(rs.from);
    }
    else {
        fatal("Invalid results from git_revparse", ps->spec);
    }

    return 0;
}
