#ifndef __PKFS_H__
#define __PKFS_H__

#include <linux/types.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

#define STATUS int

enum {
	ERROR_MAX_LIMIT = INT_MIN,	

	FAILURE = -1,

	SUCCESS = 0
};

#if 0

/* TODO: Change the structure accordingly once the initial skeleton is ready */

/* Structure definition */

typedef struct pkfs_superblock {
	super_block sb;
} pkfs_superblock;

#endif

/* Function definition */

STATUS pkfs_register_fs(void);
void pkfs_unregister_fs(void);

#endif
