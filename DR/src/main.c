/*
 * Descriptions:this function is about entry point of the entire code and called the switch function
 * Author : Akash Gupta
 * Created at : 09-02-2026
 * Modified at : 10-02-2026
 */

#include <stdio.h>
#include "/home/akash/DR/include/header.h"
#include "/home/akash/DR/170868_Akash_DR_module5_T006/include/header.h"

#define MAXLINES 100

char *lineptr[MAXLINES];
int fold = 0;
int dir = 0;

int main(int argc, char *argv[]) {
	if (argc < 2) {
		switch1();
		return 0;
	}
	if (strcmp(argv[1] , "lower" ) == 0){
		Lower(argc,argv);
	}else if (strcmp(argv[1] , "upper" ) == 0){
		upper(argc,argv);
	}else if (strcmp(argv[1] , "variableCount" ) == 0){
		variableCount(argc, argv);
	}else if (strcmp(argv[1] , "filecompare" ) == 0){
		filecompare(argc,argv);
	}else if (strcmp(argv[1] , "search_main" ) == 0){
		search_main(argc,argv);
	}else if (strcmp(argv[1] , "print_main" ) == 0){
		print_main(argc,argv);
	}else if (strcmp(argv[1] , "cat_main" ) == 0){
		cat_main(argc,argv);
	}else if (strcmp(argv[1] , "getc_main" ) == 0){
		getc_main(argc,argv);
	}else if (strcmp(argv[1] , "io_main" ) == 0){
		io_main(argc,argv);
	}else if (strcmp(argv[1] , "fseek_main" ) == 0){
		fseek_main(argc,argv);
	}else if (strcmp(argv[1] , "stat_main" ) == 0){
		stat_main(argc,argv);
	}

	if (strcmp(argv[1], "en") == 0) {
		entabCLI(argc, argv);
	}
	else if (strcmp(argv[1], "de") == 0) {
		detabCLI(argc, argv);
	}
	else if (strcmp(argv[1], "expr") == 0) {
		expr(argc, argv);
	}else if (strcmp(argv[1],"test_entab") == 0){
		test_entab(argc , argv);
	}else if (strcmp(argv[1],"test_detab") == 0) {
		test_detab(argc , argv);
	}else if (strcmp(argv[1],"tail_n") == 0){
		tail_n(argc , argv);
	}else if (strcmp(argv[1],"nr") == 0){
		nr(argc , argv);
	}else if (strcmp(argv[1],"fold_main") == 0){
		fold_main(argc , argv);
	}else if (strcmp(argv[1],"dir_main") == 0){
		dir_main(argc , argv);
	}else if (strcmp(argv[1],"calling") == 0){
		calling(argc , argv);
	}else if (strcmp(argv[1],"undcl") == 0){
		undcl(argc , argv);
	}else if (strcmp(argv[1],"parse_declaration") == 0){
		parse_declaration(argc , argv);
	}

	return 0;
}

