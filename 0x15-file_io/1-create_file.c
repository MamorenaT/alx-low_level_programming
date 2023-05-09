#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
* create_file - Makes a file.
* @filename: The name given to a file
* @text_content: What should be written in the file.
* Return: 1 if successful, -1 if unsuccessful.
*/

int create_file(const char *filename, char *text_content)
{
	int ef, wr, len = 0;

	if (filename == NULL)
	return (-1);

	if (text_content != NULL)
	{
	for (len = 0; text_content[len];)
	len++;
	}

	ef  = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(ef, text_content, len);

	if (ef == -1 || wr == -1)
	return (-1);

	close(ef);

	return (1);
}
