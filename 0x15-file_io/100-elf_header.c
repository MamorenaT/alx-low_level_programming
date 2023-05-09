#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_addr - This program displays the address.
 * @ptr: an illusions
 * Return: if unsuccessful return nothing.
 */

void print_addr(char *ptr)
{
	int begin;
	int a;
	char sys;

	printf("  Entry point address:               0x");

	sys = ptr[4] + '0';
	if (sys == '1')
	{
	begin = 26;
	printf("80");
	for (a = begin; a >= 22; a--)
	{
	if (ptr[a] > 0)
	printf("%x", ptr[a]);
	else if (ptr[a] < 0)
	printf("%x", 256 + ptr[a]);
	}
	if (ptr[7] == 6)
	printf("00");
	}

	if (sys == '2')
	{
	begin = 26;
	for (a = begin; a > 23; a--)
	{
	if (ptr[a] >= 0)
	printf("%02x", ptr[a]);

	else if (ptr[a] < 0)
	printf("%02x", 256 + ptr[a]);

	}
	}
	printf("\n");
}

/**
 * print_type - This program displays the category.
 * @ptr: an illusions
 * Return: if unsuccessful return nothing.
 */

void print_type(char *ptr)
{
	char type = ptr[16];

	if (ptr[5] == 1)
	type = ptr[16];
	else
	type = ptr[17];

	printf("  Type:                              ");
	if (type == 0)
	printf("NONE (No file type)\n");
	else if (type == 1)
	printf("REL (Relocatable file)\n");
	else if (type == 2)
	printf("EXEC (Executable file)\n");
	else if (type == 3)
	printf("DYN (Shared object file)\n");
	else if (type == 4)
	printf("CORE (Core file)\n");
	else
	printf("<unknown: %x>\n", type);
}

/**
 * print_osabi - This program displays osabi.
 * @ptr: an illusion
 * Return: if unsuccessful return nothing.
 */

void print_osabi(char *ptr)
{
	char osabi = ptr[7];

	printf("  OS/ABI:                            ");
	if (osabi == 0)
	printf("UNIX - System V\n");
	else if (osabi == 2)
	printf("UNIX - NetBSD\n");
	else if (osabi == 6)
	printf("UNIX - Solaris\n");
	else
	printf("<unknown: %x>\n", osabi);

	printf("  ABI Version:                       %d\n", ptr[8]);
}


/**
 * print_version - This program displays version.
 * @ptr: an illusion
 * Return: if unsuccessful return nothing.
 */

void print_version(char *ptr)
{
	int version = ptr[6];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
	printf(" (current)");

	printf("\n");
}

/**
 * print_data - This program displays data.
 * @ptr: an illusion
 * Return: if unsuccessful return nothing.
 */

void print_data(char *ptr)
{
	char data = ptr[5];

	printf("  Data:                              2's complement");
	if (data == 1)
	printf(", little endian\n");

	if (data == 2)
	printf(", big endian\n");
}

/**
 * print_magic - This program displays magic information.
 * @ptr: an illusion
 * Return: if unsuccessful return nothing.
 */

void print_magic(char *ptr)
{
	int bytes;

	printf("  Magic:  ");

	for (bytes = 0; bytes < 16; bytes++)
	printf(" %02x", ptr[bytes]);

	printf("\n");

}

/**
 * check_sys - The program checks which
 * version is being used.
 * @ptr: an illusion
 * Return: if unsuccessful return nothing.
 */

void check_sys(char *ptr)
{
	char sys = ptr[4] + '0';

	if (sys == '0')
	exit(98);

	printf("ELF Header:\n");
	print_magic(ptr);

	if (sys == '1')
	printf("  Class:                             ELF32\n");

	if (sys == '2')
	printf("  Class:                             ELF64\n");

	print_data(ptr);
	print_version(ptr);
	print_osabi(ptr);
	print_type(ptr);
	print_addr(ptr);
}

/**
 * check_elf - The program checks if the file is an elf.
 * @ptr: an illusion
 * Return: 1 if successful, 0 if if unsuccessful return nothing.
 */

int check_elf(char *ptr)
{
	int addr = (int)ptr[0];
	char E = ptr[1];
	char L = ptr[2];
	char F = ptr[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
	return (1);

	return (0);
}

/**
 * main - The program checks the code for students.
 * @argc: the amount of arguments.
 * @argv: The arguments vector is a list of information
 * passed to a computer program.
 * Return: 0 if successful
 */

int main(int argc, char *argv[])
{
	int ef, ret_read;
	char ptr[27];

	if (argc != 2)
	{
	dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
	exit(98);
	}

	ef = open(argv[1], O_RDONLY);

	if (ef < 0)
	{
	dprintf(STDERR_FILENO, "Err: file can not be open\n");
	exit(98);
	}

	lseek(ef, 0, SEEK_SET);
	ret_read = read(ef, ptr, 27);

	if (ret_read == -1)
	{
	dprintf(STDERR_FILENO, "Err: The file can not be read\n");
	exit(98);
	}

	if (!check_elf(ptr))
	{
	dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
	exit(98);
	}

	check_sys(ptr);
	close(ef);

	return (0);
}
