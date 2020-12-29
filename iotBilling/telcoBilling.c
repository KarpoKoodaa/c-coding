#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Device {
	char serialNumber[20];
	char model[100];
	char manufacturer[100];
	char deviceClass[100];
	char description[100];
	char firmwareVersion[100];
	char hwVersion[100];
	char location[100];
	};

int printMenu()
{
	int choose=0;
	int value;
	system("clear");
	printf("\t\t********** IOT BILLING SYSTEM ***********\n\n");
	printf("\t\t\t 1. Add new device\n");
	printf("\t\t\t 2. Search or list\n");
	printf("\t\t\t 3. Remove a device\n");
	printf("\t\t\t 4. Create billing rules\n");
	printf("\t\t\t 5. Quit\n");
	printf("\t\t\t Choose: \n");
	choose = getchar();
	value = putchar(choose);
	while((choose=getchar()) != EOF && choose != '\n');	
	return value;


}

void addDevice() {

	int n;
	int i;
	struct Device *ptr;
	FILE *fp;
	char *filename = "user_data.txt";


	printf("\nEnter number of devices: \n");
	scanf("%d", &n);
	ptr = (struct Device*) malloc(n*sizeof(struct Device));

	for (i = 0; i < n; i++) {
		printf("Id and model (%d/%d):\n", i+1, n);
		scanf("%s %s", (ptr+i)->serialNumber, (ptr+i)->model); 

	}
	fp = fopen(filename,"a");
	printf("\n\t Adding \n");
	for (i=0; i<n;i++){
	
		printf("Name: %s %s \n", (ptr+i)->serialNumber, (ptr+i)->model);
		fprintf(fp,"%s %s\n", (ptr+i)->serialNumber, (ptr+i)->model);
	}
	fclose(fp);
	printf("Press any key to continue");
	getchar();
	getchar();

}

void search() {

	FILE *fp;
	char *filename = "user_data.txt"; //Create a GLOBAL variable!
	int size;
	int i;
	int n;
	struct Device *ptr;

	ptr = (struct Device*) malloc(n*sizeof(struct Device));

	if ((fp = fopen (filename, "r")) == NULL){
		printf("File not found");
		
	}else {
		fscanf(fp, "%d", &size);
		for (i=0; i < size; i++){
			fscanf(fp, "%s%s", (ptr+i)->serialNumber, (ptr+i)->model);
		}
		fclose(fp);
		printf("\nSerial Number \t Model\n");
		for(i=0; i < size; i++){
			printf("%s \t\t %s\n", (ptr+i)->serialNumber, (ptr+i)->model);
		}
	}
	

	printf("Press any key to continue");
	getchar();
	getchar();
}

void removeDevice() {
	printf("\nDELETE\n");
	getchar();
	getchar();
}
void createBillingRules() {
	printf("\nRULES\n");
	getchar();
	getchar();
}


int main ()
{
	int option;
	
	do
	{
		option = printMenu();
		switch(option)
		{
			case '1':
				addDevice();
				break;
			case '2':
				search();
				break;
			case '3':
				removeDevice();
				break;
			case '4':
				createBillingRules();
				break;
			case '5':
				printf("\nBye Bye\n");
				system("clear");
				break;
			default:
				printf("\t\t\tBad choice\n");
				//printMenu();
				break;
		}
	} while (option != '5');
	
	return 0;


}
