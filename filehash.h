/* jdupes file hashing function
 * This file is part of jdupes; see jdupes.c for license information */

#ifndef JDUPES_FILEHASH_H
#define JDUPES_FILEHASH_H

#ifdef __cplusplus
extern "C" {
#endif

#define HASH_ALGO_COUNT 1
extern const char *hash_algo_list[HASH_ALGO_COUNT];
#define HASH_ALGO_XXH3 0

#include "jdupes.h"

jdupes_hash_t *get_filehash(const file_t * const restrict checkfile, const size_t max_read, int algo);

#ifdef __cplusplus
}
#endif

#endif /* JDUPES_FILEHASH_H */
