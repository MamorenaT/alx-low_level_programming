#include "main.h"

/**
* append_text_to_file - Appends text at the end of a file.
* @filename: name of file
* @text_content: content addedd
* Return: 1 if file is present and -1 if file fails.
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int a;
	int len;
	int wr;

	if (!filename)
	return (-1);

	a = open(filename, O_WRONLY | O_APPEND);

	if (a == -1)
	return (-1);

	if (text_content)
	{
	for (len = 0; text_content[len]; len++)
	;

	wr = write(a, text_content, len);

	if (wr == -1)
	return (-1);
	}

	close(a);

	return (1);
}
