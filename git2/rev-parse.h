#ifndef GIT2_REV_PARSE_H_
#define GIT2_REV_PARSE_H_

#include <git2.h>

struct parse_state {
    git_repository *repo;
    const char *repodir;
    const char *spec;
};

/**
 * TODO
 */

int parse_revision(struct parse_state *ps, char *spec);

#endif
