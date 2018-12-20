/****************************************************************
 * * Name: demo.c
 * * Version: v2.0 
 * * Author: zhufeiyu
 * * Date: 2018-12-20 
 * * Description: Main function for Analysis and Calling method
 * **************************************************************/

#include "command.h"

static void usage_exit(int status)
{
        if(status != 0)
        {
                fprintf(stderr, "Try '%s -h' for more infomation\n",program_name);
        }

        exit(status);
}

int main(int argc,char *argv[])
{
	int x;
	exit_status = 0 ;
	static struct option const long_options[]=
	{
		{"help", 0 , NULL , 'h'},
		{"cp"  , 0 , NULL , 'p'},
		{"list", 0 , NULL , 'q'},
		{"delete",0, NULL , 'd'},
		{"content",0,NULL , 'r'},
		{"mkdir",0 , NULL , 'c'},
		{"ll",   0 , NULL , 'L'},
		{"link", 0 , NULL , 's'},
		{"file", 0 , NULL , 'f'},
		{ NULL , 0 , NULL , 0  }
	};

	program_name = argv[0] ;
	while( ( x = getopt_long(argc,argv,"QqRrCcF:f:DdSsPpHhLo:l:",long_options,NULL) ) !=-1 )
	{
		switch(x)
		{
			case 'h':
			case 'H':
				if(argc==2)
				{
				 	exit_status = help_main();
				}				
			break;
			
			case 'p':
			case 'P':
				if(argc-optind!=2)
				{
					usage_exit(1);
				}
				else
				{
					exit_status = copy_main(argv[optind],argv[optind+1] );
				}
			break ;

			case 'q':
			case 'Q':
				if(argc-optind!=1)
                                {
                                        usage_exit(1);
                                }
                                else
                                {
                                        exit_status = list_main(argv[optind]);
                                }
			break ;
		
			case 'd':
			case 'D':
				if(argc-optind!=1)
                                {
                                        usage_exit(1);
                                }
                                else
                                {
                                        exit_status = del_main(argv[optind]);
                                }
			break ;

			case 'r':
			case 'R':
				if( argc-optind >5)
                                {
                                        usage_exit(1);
                                }
                                else if(argc-optind==1)
                                {
					//printf("no  o  l !");
                                        exit_status = content_main(1,NULL,NULL,argv[optind]);
                                }
			case 'o':
			case 'l':
				if(argc-optind==5 && strcmp(argv[optind],"-o") == 0 && strcmp(argv[optind+2],"-l") == 0 )
				{
					//printf("have o l");
					//printf("o:%s l:%s  file:%s\n",argv[optind+1],argv[optind+3],argv[optind+4]);
					exit_status =content_main(argc,argv[optind+1],argv[optind+3],argv[optind+4]);
				}
			break ;



			case 'c':
			case 'C':
				//printf("%d\n",x);
				if(argc-optind>2)
                                {
                                        usage_exit(1);
                                }
                                else if(argc-optind == 1)
				{
                                        exit_status = mkdir_main(argv[optind],argc);
                                }
				else{
				//	printf("%d\n",x);
					//x='f';
				}
			
			case 'f':
				//printf("success to case f!");
				if(argc-optind!=2)
				{
					usage_exit(1);
				}
				else if(strcmp(argv[optind],"-f") == 0)
				{
					exit_status = mkfile_main(argv[optind+1],argc);	
				}
			break ;


			case 'L':
				if(argc-optind!=0)
                                {
                                        usage_exit(1);
                                }
                                else
                                {
                                        exit_status = ll_main(argc,argv[optind]);
                                }

                        break ;
			
			case 's':
                        case 'S':
                                if(argc-optind!=2)
                                {
                                        usage_exit(1);
                                }
                                else
                                {
                                        exit_status = create_softlink( argv[optind],argv[optind+1] );
                                }

                        break ;


				
			default:
				usage_exit(EXIT_FAILURE);
			break;



		}
	}
	exit(exit_status);

}
