/*
 * Descriptions:this function is about that calls the different function for question and run it properly
 * Author : Akash Gupta
 * Created at : 09-02-2026
 * Modified at : 10-02-2026
 */




#include <stdio.h>
#include <stdint.h>
#include "/home/akash/DR/170868_Akash_DR_module1_T006/include/header.h"
#include "/home/akash/DR/170868_Akash_DR_module2_T006/include/header.h"
int switch1() {
	int8_t choice1;
	printf("enter the module number ");
	scanf("%hhd",&choice1);
	switch (choice1) {
		case 1:
    int8_t choice;
    printf("Enter choice: ");
    scanf("%hhd", &choice);
    getchar();
    switch (choice) {
        case 1:
            print_hello() ;
            break;
        case 2:
            invalid_escape();
            break;
        case 3:
            f2c();
            break;
        case 4:
            c2f();
            break;
        case 5:
            reverse_order();
            break;
        case 6:
            is_eof();
            break;

	case 7:
	    print_eof();
	    break;
	case 8:
	    print_escape();
	    break;
	case 9:
	    print_singal_space();
	    break;
	case 10:
	    add_escape();
	    break;
	case 11:
	    word_count();
	    break;
	case 12:
	    newline();
	    break;
	case 13:
	    makehistogram();
	    break;
	case 15:
	     f2c_function();
	     break;
	case 16:
	     longest_line();
	     break;
	case 17:
	     longest_gt_80();
	     break;
	case 18:
	     remove_space();
	     break;
	case 19:
	     reverse_string();
	     break;
	case 20:
	     tab_space();
	     break;
	case 21:
	     entab();
	     break;
	case 22:
	     fold_line();
	     break;
	case 23:
	     remove_comments();
	     break;
	case 24:
	     syntax_checker();
	     break;

        default:
            printf("Invalid choice\n");

    }
		case 2:
    int8_t choice2;
    printf("Enter choice: ");
    scanf("%hhd", &choice2);
    getchar();
    switch (choice2) {
	    case 1:
		    print_ranges();
		    break;
	    case 2:
		     loop_eq();
		     break;
	    case 3:
		     hex_2_int();
		     break;
	    case 4:
		     deletec();
		     break;
	    case 5:
		     check_duplicate();
		     break;
	    case 6:
		     setbits_t();
		     break;
	    case 7:
		     invert_t();
		     break;
	    case 8:
		      rightRotate_t();
		     break;
	    case 9:
		     bitcount_t();
		     break;
	    case 10:
		     lower_t();
		     break;
    }

    break;
		default:
    printf("enter the valid module number ");
	}
    
    return 0;
}
