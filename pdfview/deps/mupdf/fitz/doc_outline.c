#include "fitz.h"

void
fz_free_outline(fz_outline *outline)
{
	while (outline)
	{
		fz_outline *next = outline->next;
		fz_free_outline(outline->down);
		fz_free(outline->title);
		fz_free(outline);
		outline = next;
	}
}

void
fz_debug_outline_xml(fz_outline *outline, int level)
{
	while (outline)
	{
		printf("<outline title=\"%s\" page=\"%d\"", outline->title, outline->page);
		if (outline->down)
		{
			printf(">\n");
			fz_debug_outline_xml(outline->down, level + 1);
			printf("</outline>\n");
		}
		else
		{
			printf(" />\n");
		}
		outline = outline->next;
	}
}

void
fz_debug_outline(fz_outline *outline, int level)
{
	int i;
	while (outline)
	{
		for (i = 0; i < level; i++)
			putchar('\t');
		printf("%s\t%d\n", outline->title, outline->page);
		if (outline->down)
			fz_debug_outline(outline->down, level + 1);
		outline = outline->next;
	}
}
