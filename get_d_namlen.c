/* libjodycode name length optimization backport for jdupes
 *
 * Copyright (C) 2014-2025 by Jody Bruchon <jody@jodybruchon.com>
 * Released under The MIT License
 */

#include <dirent.h>
#include <stddef.h>
#include <string.h>
#include "libjodycode.h"

#if LIBJODYCODE_API_VERSION < 4
/* Extract d_namlen from struct dirent */
size_t get_d_namlen(const struct dirent * const restrict dirent)
{
#ifdef _DIRENT_HAVE_D_NAMLEN
	return dirent->d_namlen;
#elif defined _DIRENT_HAVE_D_RECLEN
	const size_t base = (sizeof(struct dirent) - sizeof(((struct dirent *)0)->d_name)) - offsetof(struct dirent, d_name) - 1;
	size_t skip;

	skip = dirent->d_reclen - (sizeof(struct dirent) - sizeof(((struct dirent *)0)->d_name));
	if (skip > 0) skip -= base;
	return skip + strlen(dirent->d_name + skip);
#else
	return strlen(dirent->d_name);
#endif
}
#else
 #define get_d_namlen(a) jc_get_d_namlen(a)
#endif  /* LIBJODYCODE_API_VERSION < 4 */
