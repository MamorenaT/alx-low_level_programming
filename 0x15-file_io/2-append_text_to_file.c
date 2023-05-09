#include "main.h"

/**
* append_text_to_file - This adds words to the end of a file.
* @filename: the file name.
* @text_content: Additions to the content.
* Return: 1 if sucsessful, -1 if unsucsessful.
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int c;
	int len;
	int wr;

	if (!filename)
	return (-1);

	c = open(filename, O_WRONLY | O_APPEND);

	if (c == -1)
	return (-1);

	if (text_content)
	{
	for (len = 0; text_content[len]; len++)
	;

	wr = write(c, text_content, len);

	if (wr == -1)
	return (-1);
	}

	close(c);

	return (1);
}
