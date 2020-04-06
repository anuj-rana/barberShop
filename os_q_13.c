#include<stdio.h>
#include<stdbool.h>
void make_chairs_unoccupied_init(int arr[], int n);
int check_chair_status(int arr[], int n);
void fill_chairs(int arr[], int n, int c);
bool sleeping(int arr[], int n);
bool filled(int arr[], int n);
int main(){
	int n, c=0, current_free;
	printf("Enter number of chairs: ");
	scanf("%d",&n);

	int chairs[n];
	make_chairs_unoccupied_init(chairs, n);	
	current_free = check_chair_status(chairs, n);

	//printf("Enter initial number of customers: ");
	//scanf("%d", &c);
	//fill_chairs(chairs, n, c);
	//check_chair_status(chairs, n);
	

	while(c != -1){
		printf("\nEnter new number of customers: ");
		scanf("%d", &c);
		if(c==0 && sleeping(chairs,n)==false){continue;}
		else if(c==0 && sleeping(chairs,n)==true){
			printf("\nSleeping...!\n");
		}
		else if(sleeping(chairs, n)==true){
			printf("Barber was sleeping...........\nCustomer awakes barber...!\n");
			fill_chairs(chairs, n, c);
		}
		else{	
			if(filled(chairs, n)==true){
				printf("Barber is working... All Seats are filled...!");
				continue;
			}
			else{
				printf("Barber is working... Previous Vacant seats: %d\n", check_chair_status(chairs,n));
				fill_chairs(chairs, n, c);
				printf("\nVacant Seats count: %d\nStatus updated !!!\n",check_chair_status(chairs,n));
				continue;
			}
		}

	}
	return 0;
}
void fill_chairs(int chairs[], int n, int c){
	int count = 0;
	int leaving_cust=0;
	for(int i=0; i<n; i++){
		if(chairs[i] == 0 && count<c &&c>0){
			chairs[i] = 1;
			count++;
			printf("\nCustomer occupies seat...");
		}
	}
	if(c-count>0){
		printf("\n%d customers left",c-count);
	}
}
void make_chairs_unoccupied_init(int arr[], int n){
	for(int i=0; i<n; i++){
		arr[i] = 0;
	}
}
int check_chair_status(int arr[], int n){
	int free_count = 0;
	for(int i=0; i<n; i++){
		if(arr[i]==0){
			//printf("\nChair %d is Free", i+1);
			free_count++;
		}
		else{
			//printf("\nChair %d is occupied",i+1);
		}
	}
	return free_count;
}
bool sleeping(int arr[], int n){
	int free=0;
	for(int i=0; i<n; i++){
		if(arr[i]==0){free++;}
	}
	if(free==n){return true;}
	else{return false;}
}
bool filled(int arr[], int n){
	int free=0;
	for(int i=0; i<n; i++){
		if(arr[i]==0){free++;}
	}
	if(free==0){return true;}
	else{return false;}
}
