#include "UI.h"
#include "Controller.h"
#include "Domain.h"
#include <stdio.h>
#include <string.h>


void menu()
{
	printf("MENU\n");
	printf("\t1. Show offers\n");
	printf("\t2. Add a real-estate\n");
	printf("\t3. Delete a real-estate\n");
	printf("\t4. Update a real-estate\n");
	printf("\t5. Display all offers whose address containing a given string\n");
	printf("\t6. All the offers by surface, ascending price\n");
	printf("\t7. All the offers by type, surface greater than a given value\n");
	printf("\t8. Undo\n");
	printf("\t9. Redo\n");
	printf("\t0. Exit\n");
}

void printOffers()
{
	if (offers->length == 0)
	{
		printf("There are no offers!\n");
		return;
	}

	int i;
	for (i = 0; i < offers->length; ++i)
		printf("%d. Type: %s ~ Address: %s ~ Surface: %d ~ Price: %d\n", i + 1, offers->elems[i].type, offers->elems[i].address, offers->elems[i].surface, offers->elems[i].price);

	printf("\n");
}


void run()
{
	int cmd;
	
	runCtrl();
	menu();
	cmd = 1;

	testValues();
	while (cmd != 0)
	{
		printf("\n\nEnter a command: ");
		scanf_s("%d", &cmd);

		if (cmd == 1)
			printOffers();
		else
			if (cmd == 2)
			{
				char type[20] = "", address[100] = "";
				int surface, price;
				printf("Type: ");
				scanf_s("%s", &type, 20);

				printf("Address: ");
				scanf_s("%s", &address, 100);

				printf("Surface: ");
				scanf_s("%d", &surface);

				printf("Price: ");
				scanf_s("%d", &price);

				if (addOffer(type, address, surface, price, 1) == 1)
					printf("Offer added successfully!");
				else
					printf("Offer could not be added!");
			}
			else
				if (cmd == 3)
				{
					char add[100];
					printf("Give the address: ");
					scanf_s("%s", &add, 100);

					if (removeOffer(add, 1) == 1)
						printf("Offer removed successfully!");
					else
						printf("Could not remove offer!");
				}
				else
					if (cmd == 4)
					{
						int cmd2;
						char add[100];
						printf("Give the address: ");
						scanf_s("%s", &add, 100);

						int find = ctrlFind(add);
						if (find == -1)
						{
							printf("Could't find the given address!");
							continue;
						}
							
						printf("\nChoose something to update: \n");
						printf("\t1. Type\n");
						printf("\t2. Surface\n");
						printf("\t3. Price\n");
						scanf_s("%d", &cmd2);
						
						if (cmd2 == 1)
						{
							char newt[20];
							printf("New type: ");
							scanf_s("%s", &newt, 20);
							if (updateType(find, newt, 1) == 1)
								printf("Updated!");
							else
								printf("Could not update!");
						}
						else
							if (cmd2 == 2)
							{
								int news;
								printf("New surface: ");
								scanf_s("%d", &news);
								if (updateSurface(find, news, 1) == 1)
									printf("Updated!");
								else
									printf("Could not update!");
							}
							else
								if (cmd2 == 3)
								{
									int newp;
									printf("New price: ");
									scanf_s("%d", &newp);
									if (updatePrice(find, newp, 1) == 1)
										printf("Updated!");
									else
										printf("Could not update!");
								}
								else
									printf("Invalid input!");
					}
					else
						if (cmd == 5)
						{
							int ok = 0;
							char string[100];
							printf("Give the string: ");
							scanf_s("%s", &string, 100);
							for (int i = 0; i < offers->length; i++)
								if (containString(i, string) == 1)
								{
									printf("%d. Type: %s ~ Address: %s ~ Surface: %d ~ Price: %d\n", i + 1, offers->elems[i].type, offers->elems[i].address, offers->elems[i].surface, offers->elems[i].price);
									ok = 1;
								}
							if (ok == 0)
								printf("Couldn't find anything!");
						}
						else
							if (cmd == 6)
							{
								int n, surf, arr[100];
								printf("Enter surface: ");
								scanf_s("%d", &surf);
								printf("\n");
								n = offersBySurface(surf, arr);
								if (n != -1)
									for (int i = 0; i < n; i++)
										printf("%d. Type: %s ~ Address: %s ~ Surface: %d ~ Price: %d\n", i + 1, offers->elems[arr[i]].type, offers->elems[arr[i]].address, offers->elems[arr[i]].surface, offers->elems[arr[i]].price);
								else
									printf("Invalid input!");
							}
							else
								if(cmd == 7)
								{
									int n, surf, arr[100];
									char type[20];
									printf("Enter type: ");
									scanf_s("%s", &type, 20);
									//printf("\n");


									printf("Enter surface: ");
									scanf_s("%d", &surf);
									printf("\n");

									n = offersByType(type, arr, surf);
									if (n != -1)
										for (int i = 0; i < n; i++)
											printf("%d. Type: %s ~ Address: %s ~ Surface: %d ~ Price: %d\n", i + 1, offers->elems[arr[i]].type, offers->elems[arr[i]].address, offers->elems[arr[i]].surface, offers->elems[arr[i]].price);
									else
										printf("Invalid input!");
								}
								else
									if (cmd == 8)
									{
										int result = undoOperation();
										if (result == -1)
											printf("Failed to undo last operation!");
										else
											printf("Success!");
									}
									else
										if (cmd == 9)
										{
											int result = redoOperation();
											if (result == -1)
												printf("Failed to redo last operation!");
											else
												printf("Success!");
										}
										else
											if(cmd != 0)
												printf("Invalid input!");
		
	}

}


