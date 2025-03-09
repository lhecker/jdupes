/* libjodycode name length optimization backport for jdupes
 *
 * Copyright (C) 2014-2025 by Jody Bruchon <jody@jodybruchon.com>
 * Released under The MIT License
 */

#ifndef GET_D_NAMLEN_H
#define GET_D_NAMLEN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <dirent.h>
size_t get_d_namlen(const struct dirent * const restrict dirent);

#ifdef __cplusplus
}
#endif

#endif /* GET_D_NAMLEN_H */
