#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char **argv)
{
	
	int c = 0;
	const struct option longopts[] = {
		{ "debug", no_argument, NULL, 'd' },
		{ "help",  no_argument, NULL, 'h' },
		{ "list",  no_argument, NULL, 'l' },
		{ "network", no_argument, NULL, 'n' },
		{ "version", no_argument, NULL, 'v' },
		{ NULL, 0, NULL, 0}
	};
	
	while ((c = getopt_long(argc, argv, "dhlnv", longopts, NULL)) != -1) {
		switch (c) {
			case 'd':
				printf("debug....");
				break;
			case 'h':
				printf("help....");
			case 'l':
				printf("list....");
				break;
			case 'n':
				printf("network....");
				break;
			case 'v':
				printf("version....");
				break;
			default:
				printf(".......");
				break;
		}
	}
	argc -= optind;
	argv += optind;
	
	if (argc == 1) {
		printf("1111");
	} else if (argc == 0 && optind == 1) {
		printf("2222");
	}
	
	const char* udid = NULL;
	udid = argv[0];
	
	return 0;
}
