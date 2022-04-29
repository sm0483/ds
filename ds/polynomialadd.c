#include<stdio.h>

typedef struct p{

	int coeff;
	int power;

};

struct p a[20],b[20],r[20];

int main(){
	//term of a;
	int sizeA=0;
	printf("Enter the number of terms in first poly: ");
	scanf("%d",&sizeA);


	//term of b
	int sizeB=0;
	printf("Enter the number of terms in first poly: ");
	scanf("%d",&sizeB);

	//take first input


	for(int i=0;i<sizeA;i++){
		//input co
		int co=0;
		printf("Enter the coeff: ");
		scanf("%d",&co);
		a[i].coeff=co;
		//input pow
		int pow=0;
		printf("Enter the power: ");
		scanf("%d",&pow);
		a[i].power=pow;

	}

	printf("\n");

	for(int i=0;i<sizeB;i++){
		//input co
		int co=0;
		printf("Enter the coeff: ");
		scanf("%d",&co);
		b[i].coeff=co;
		//input pow
		int pow=0;
		printf("Enter the power: ");
		scanf("%d",&pow);
		b[i].power=pow;

	}


	//printA

	for(int i=0;i<sizeA;i++){
		printf("(%d - %d)",a[i].coeff,a[i].power);

	}
	printf("\n");
	//printB
	for(int i=0;i<sizeB;i++){
		printf("(%d - %d)",b[i].coeff,b[i].power);

	}
	printf("\n");

	int i=0,j=0,k=0;

	while(i<sizeA && j<sizeB){
		if(a[i].power==b[j].power){
			r[k].power=a[i].power;
			r[k].coeff=a[i].coeff+b[j].coeff;
			i++;
			k++;
			j++;
		}

		else if(a[i].power<b[j].power){
			r[k].power=b[j].power;
			r[k].coeff=b[j].coeff;
			k++;
			j++;
		}

		else if(a[i].power>b[j].power){
			r[k].power=a[i].power;
			r[k].coeff=a[i].coeff;
			k++;
			i++;
		}

	}

	while(i<sizeA){
		r[k].coeff=a[i].coeff;
		r[k].power=a[i].power;
		k++;
		i++;

	}

	while(j<sizeB){
		r[k].power=b[j].power;
		r[k].coeff=b[j].coeff;
		k++;
		j++;
	}
	for(int i=0;i<10;i++){
		printf("(%d - %d)",r[i].coeff,r[i].power);
	}



	return 0;


}
