#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/utsname.h>
#include <math.h> 
#include <string>


int main (int argc, char *argv[]){
    struct utsname uts;
    if(uname(&uts) !=0 ) {
        return EXIT_FAILURE;
    }

	const char* short_options = "h, n, r, v, p:";

	const struct option long_options[] = {
		{"help", no_argument, NULL,'h'},
		{"name", no_argument, NULL,'n'},
		{"realise", no_argument, NULL,'r'},
		{"version", no_argument, NULL,'v'},
		{"power",	required_argument,	NULL,'p'},
		{NULL,		0,					NULL, 0},
	};

	int parse, option_index = -1;

	bool counter[5] = {false, false, false, false, false};

	while ((parse=getopt_long(argc, argv,
							short_options,
							long_options,
							&option_index))!=-1){
		switch(parse){
			case 'h': {
				if (!counter[0]){
					printf("Available commands:\n"
					       " -h (--help)     show available commands\n"
					       " -n (--name)     get operating system name\n"
					       " -r (--realise)  get operating system realise\n"
					       " -v (--version)  get operating system version\n"
					       " -p (--power)  	 to square the number\n"
					       );
					counter[0] = true;
				}
				break;
			}

			case 'n': {
            	if (!counter[1]){
                    printf("Operating system name: %s\n",uts.sysname);
                    counter[1] = true;
            	}
            	break;
            }

            case 'r': {
            	if (!counter[2]){
                    printf("Operating system release: %s\n",uts.release);
                    counter[2] = true;
            	}
            	break;
            }

            case 'v': {
            	if (!counter[3]){
                    printf("Operating system version: %s\n",uts.version);
                    counter[3] = true;
            	}
            	break;
            }

            case 'p': {
            	if (!counter[4]){
                    printf("Value = %f\n", pow(std::stof(optarg), 2.0));
                    counter[4] = true;
            	}
            	break;
            }

			case '?': default: {
				printf("Unknown option! Try again.\n");
				break;
			}
		}
		option_index = -1;
	}
	return 0;
}