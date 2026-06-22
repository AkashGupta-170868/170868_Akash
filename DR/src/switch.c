/*
 * Description: This function calls different module functions and runs them properly
 * Author : Akash Gupta
 * Created at : 09-02-2026
 * Modified at : 10-02-2026
 */

#include <stdio.h>
#include <stdint.h>
#include "/home/akash/DR/170868_Akash_DR_module1_T006/include/header.h"
#include "/home/akash/DR/170868_Akash_DR_module2_T006/include/header.h"
#include "/home/akash/DR/170868_Akash_DR_module3_T006/include/header.h"
#include "/home/akash/DR/170868_Akash_DR_module4_T006/include/header.h"
#include "/home/akash/DR/170868_Akash_DR_module5_T006/include/header.h"
#include "/home/akash/DR/170868_Akash_DR_module6_T006/include/header.h"
#include "/home/akash/DR/170868_Akash_DR_module7_T006/include/header.h"

/* ================= MODULE 1 ================= */
void module1() {
  int8_t choice;
  printf("\n--- MODULE 1 ---\nEnter choice: ");
  scanf("%hhd", &choice); getchar();

  switch (choice) {
  case 1: print_hello(); break;
  case 2: invalid_escape(); break;
  case 3: f2c(); break;
  case 4: c2f(); break;
  case 5: reverse_order(); break;
  case 6: is_eof(); break;
  case 7: print_eof(); break;
  case 8: print_escape(); break;
  case 9: print_singal_space(); break;
  case 10: add_escape(); break;
  case 11: word_count(); break;
  case 12: newline(); break;
  case 13: makehistogram(); break;
  case 15: f2c_function(); break;
  case 16: longest_line(); break;
  case 17: longest_gt_80(); break;
  case 18: remove_space(); break;
  case 19: reverse_string(); break;
  case 20: tab_space(); break;
  case 21: entab(); break;
  case 22: fold_line(); break;
  case 23: remove_comments(); break;
  default: printf("Invalid choice\n");
  }
  }

/* ================= MODULE 2 ================= */
void module2() {
	int8_t choice;
	printf("\n--- MODULE 2 ---\nEnter choice: ");
	scanf("%hhd", &choice); getchar();

	switch (choice) {
		case 1: print_ranges(); break;
		case 2: loop_eq(); break;
		case 3: hex_2_int(); break;
		case 4: deletec(); break;
		case 5: check_duplicate(); break;
		case 6: setbits_t(); break;
		case 7: invert_t(); break;
		case 8: rightRotate_t(); break;
		case 9: bitcount_t(); break;
		case 10: lower_t(); break;
		default: printf("Invalid choice\n");
	}
}

/* ================= MODULE 3 ================= */
void module3() {
	int8_t choice;
	printf("\n--- MODULE 3 ---\nEnter choice: ");
	scanf("%hhd", &choice); getchar();

	switch(choice) {
		case 1: binarySearchTest(); break;
		case 2: escape_t(); break;
		case 4: itoa_t(); break;
		case 5: itob_t(); break;
		case 6: itoa_width_t(); break;
		default: printf("Invalid choice\n");
	}
}

/* ================= MODULE 4 ================= */
void module4() {
	int8_t choice;
	printf("\n--- MODULE 4 ---\nEnter choice: ");
	scanf("%hhd", &choice); getchar();

	switch(choice) {
		case 1: mstrindex_main(); break;
		case 2: sci_main(); break;
		case 3: rev_rpn_main(); break;
		case 4: main4_4(); break;
		case 5: main4_5();break;
		case 6: main4_6();break;
		case 7: main4_7(); break;
		case 8: test_48(); break;
		case 9: test_49(); break;
		case 10: test_410(); break;
	        case 11: test_411(); break;
		case 12: int_to_string(); break;
		case 13: reverse_rec(); break;
		case 14: macro_swap(); break;
		default: printf("Invalid choice\n");
	}
}

/* ================= MODULE 5 ================= */
void module5() {
	int8_t choice;
	printf("\n--- MODULE 5 ---\nEnter choice: ");
	scanf("%hhd", &choice); getchar();

	switch(choice) {
		case 1: test_dr51(); break;
		case 2: test_dr52(); break;
		case 3: str_cat(); break;
		case 4: str_end_test(); break;
		case 5: str_test(); break;
		case 6: func_test(); break;
		case 7: readline_test(); break;
		case 8: test_cal(); break;
		case 9: test_cal2(); break;
		default: printf("Invalid choice\n");
	}
}

/* ================= MODULE 6 ================= */
void module6() {
	int8_t choice;
	printf("\n--- MODULE 6 ---\nEnter choice: ");
	if (scanf("%hhd", &choice) != 1) {
		printf("Invalid input\n");

		while (getchar() != '\n'); // clear buffer
		return;
	}
	switch(choice) {
		case 1: getword_main(); break;
		case 3: cross_main(); break;
		case 4 : freq_count_main(); break;
		case 5: hash_main(); break;
		case 6: define_main();break;
		default: printf("Invalid choice\n");
	}
}
/* ================= MODULE 7 ================= */
void module7() {
	int8_t choice;
	printf("\n--- MODULE 7 ---\nEnter choice: ");
	if (scanf("%hhd", &choice) != 1) {
		printf("Invalid input\n");

		while (getchar() != '\n'); // clear buffer
		return;
	}
	switch(choice) {
		case 2: { while (getchar() != '\n');nongraphical_main();break;}
		case 3: printf_main(); break;
		case 4: scanf_main(); break;
		case 5: RPN_main(); break;
		case 9: time_space_main(); break;
		default: printf("Invalid choice\n");
	}
}
void module8() {
	int8_t choice;
	printf("\n--- MODULE 8 ---\nEnter choice: ");
	if (scanf("%hhd", &choice) != 1) {
		printf("Invalid input\n");

		while (getchar() != '\n'); // clear buffer
		return;
	}
	switch(choice) {
		case 6: calloc_main(); break;
		case 7: malloc_main(); break;
		case 8: displaybfree(); break;
		default: printf("Invalid choice\n");
	}
}
/* ================= MAIN SWITCH ================= */
int switch1() {
	int8_t module;

	while (1) {
		printf("\n========= MAIN MENU =========\n");
		printf("1. Module 1\n");
		printf("2. Module 2\n");
		printf("3. Module 3\n");
		printf("4. Module 4\n");
		printf("5. Module 5\n");
		printf("6. Module 6\n");
		printf("7. Module 7\n");
		printf("8. module 8\n");
		printf("0. Exit\n");
		printf("Enter module number: ");

		if (scanf("%hhd", &module) != 1) {
			printf("Invalid input\n");

			while (getchar() != '\n');
			continue;
		}

		switch(module) {
			//        case 1: module1(); break;
			case 2: module2(); break;
			case 3: module3(); break;
				//  case 4: module4(); break;
			case 5: module5(); break;
			case 6: module6(); break;
			case 7: module7(); break;
			case 8: module8(); break;
			case 0: return 0;
			default: printf("Invalid module\n");
		}
	}
}
