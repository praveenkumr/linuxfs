#include "linuxfs.h"
MODULE_LICENSE("GPL v2");

typedef struct pkfs_inode {
	struct inode _inode;
	/* Add file system specific */
} pkfs_inode;

typedef struct pkfs_super_block {
	struct super_block _sb;
	/* Add file system specific */
} pkfs_sb;

static int pkfs_fill_super(struct super_block *sb, void *data, int silent)
{
	/* Need to add code to read from the disc and fill the super block */

	return 0;
}

static struct dentry *pkfs_mount(struct file_system_type *fs_type,
				int flags,
				const char *dev_name,
				void *data)
{
	return mount_bdev(fs_type, flags, dev_name, data, pkfs_fill_super);
}

static struct file_system_type pkfs_fs_type = {
	.owner		= THIS_MODULE,
	.name		= "pkfs",
	.mount		= pkfs_mount,
	.kill_sb	= kill_block_super,
	.fs_flags	= FS_REQUIRES_DEV,
};

STATUS pkfs_register_fs(void)
{
	STATUS status = SUCCESS;
	status = register_filesystem(&pkfs_fs_type);

	if (status != SUCCESS) {
		printk(KERN_ALERT "pkfs register filesystem failed with error code %d", status);
	}
	return status;
}

void pkfs_unregister_fs(void)
{
	unregister_filesystem(&pkfs_fs_type);
}

static int pkfs_init(void)
{
	pkfs_register_fs();
	return 0;
}

static void pkfs_exit(void)
{
	pkfs_unregister_fs();
}

module_init(pkfs_init);
module_exit(pkfs_exit);

