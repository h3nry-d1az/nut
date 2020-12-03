/* This kernel uses FAT-32 by now.
More information at wiki.osdev.org/FAT */
#ifndef __NUT_FILESYSTEM_H__
#define __NUT_FILESYSTEM_H__


typedef struct __FAT_32_Disk_Sector__ {
	u32		table_size_32;
	u16		extended_flags;
	u16		fat_version;
	u32		root_cluster;
	u16		fat_info;
	u16		backup_BS_sector;
	u8 		reserved_0[12];
	u8		drive_number;
	u8 		reserved_1;
	u8		boot_signature;
	u32		volume_id;
	u8		volume_label[11];
	u8		fat_type_label[8];
} __attribute__((packed)) FAT32_Sector;


FAT32_Sector InitFAT32(u32 size, u16 fversion,
					   u32 rcluster, u16 info,
					   u16 backup, u8 number,
					   u32 id) {
	return (FAT32_Sector){
		size,
		NULL,
		fversion,
		rcluster,
		info,
		backup,
		NULL,
		number,
		NULL,
		NULL,
		id,
		NULL,
		NULL
	};
}
//FAT32 sector constructor

#endif //nut disk module