#include <stdio.h>
#include "queue.h"
#include <stdlib.h>
int32_t patient_()
{
	struct queue* pq = createqueue();

	char choice;
	char name[50];
	int priority;

	while (1)
	{
		printQueue(pq);

		printf("N)ew, F)ront, U)pgrade, P)rocess, B)ulk, C)lear, Q)uit? ");
		scanf(" %c", &choice);

		switch(choice)
		{
			case 'N':
			case 'n':

				printf("Name? ");
				scanf(" %[^\n]", name);

				printf("Priority? ");
				scanf("%d", &priority);

				insertnode(pq, name, priority);
				break;

			case 'F':
			case 'f':

				if(is_empty(pq))
				{
					printf("Queue is empty\n");
				}
				else
				{
					printf("Front patient: \"%s\"\n",
							pq->front->name);

					printf("Priority: %d\n",
							pq->front->priority);
				}
				break;

			case 'U':
			case 'u':

				printf("Name? ");
				scanf(" %[^\n]", name);

				printf("New priority? ");
				scanf("%d", &priority);

				upgradequeue(pq, name, priority);
				break;

			case 'P':
			case 'p':
				{
					char* patient = processqueue(pq);

					if(patient == NULL)
					{
						printf("Queue is empty\n");
					}
					else
					{
						printf("Processing patient: \"%s\"\n",
								patient);

						free(patient);
					}

					break;
				}

			case 'B':
			case 'b':

				bulk(pq);
				break;

			case 'C':
			case 'c':

				clearnode(pq);
				printf("Queue cleared\n");
				break;

			case 'Q':
			case 'q':

				clearqueue(pq);
				printf("\nExiting.\n");
				return 0;

			default:

				printf("Invalid choice\n");
		}
	}

	return 0;
}
