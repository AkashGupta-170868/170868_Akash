/*
 * Description: This function calls different module functions and runs them properly
 * Author : Akash Gupta
 */

#include <stdio.h>
#include <stdint.h>

#include "/home/akash/DR/170868_Akash_DR_module1_T006/include/header.h"
#include "/home/akash/DR/170868_Akash_DR_module2_T006/include/header.h"
#include "/home/akash/Yashwant_Kanetkar/170868_Akash_YPK_module3_T010/include/header.h"
#include "/home/akash/Yashwant_Kanetkar/170868_Akash_YPK_module4_T010/include/header.h"
int switch1()
{
    int8_t moduleChoice;

    printf("Select Module (1, 2, 3): ");
    scanf("%hhd", &moduleChoice);
    getchar();

    switch (moduleChoice)
    {
        /* ================= MODULE 1 ================= */
        case 1:
        {
            int8_t choice;
            printf("Enter choice: ");
            scanf("%hhd", &choice);
            getchar();

            switch (choice)
            {
                case 1: test_1(); break;
                case 2: test_2(); break;
                case 3: test_3(); break;
                case 4: ; break;
                case 5: test_5(); break;
                default: printf("Invalid choice (Module 1)\n");
            }
            break;
        }

        /* ================= MODULE 2 ================= */
        case 2:
        {
            int8_t choice;
            printf("Enter choice: ");
            scanf("%hhd", &choice);
            getchar();

            switch (choice)
            {
                case 1:displayDeterminant(); break;
		case 2:displayInfo();break;
		case 3:listDirectory();break;
                default: printf("Invalid choice (Module 2)\n");
            }
            break;
        }

        default:
            printf("Invalid Module Selection\n");
    }

    return 0;
}
