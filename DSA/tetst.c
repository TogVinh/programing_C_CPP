#include <stdio.h>
#include<stdlib.h>
#include <string.h>

char *get_file_name_by_download_url(char *url)
{
	if (url == NULL) {
		return NULL;
	}
	char *slash = strrchr(url, '/');
	if (slash == NULL)
			return NULL;
	return slash+1;
}

int main()
{
    char url[] = "http://192.167.12.2/gpon/ppon/";
    char *name = NULL;

    name = get_file_name_by_download_url(url);
    printf("name = |%s|\n", name);
    return 0;
}