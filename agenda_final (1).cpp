#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<iostream>
#define localizar (struct nodo *)malloc(sizeof(struct nodo))


void insertar(struct nodo**);
void buscar_Codigo(struct nodo**);
void buscar_Nombre(struct nodo**);
void eliminar_Codigo(struct nodo**);
void imprimir(struct nodo*);

struct nodo{
	struct nodo *sig;
	struct nodo *ant;
	int codigo;
	char nombre[50];
	char telefono[20];
	char correo[50];
};
void imprimir(struct nodo *cab){
	if(cab!=NULL){
		printf("\nLa lista es: ");
		while(cab!=NULL){
			printf("\n\t Codigo: %d, Nombre: %s, Telefono: %s, Correo: %s ",cab->codigo,cab->nombre,cab->telefono,cab->correo);
			cab=cab->sig;
		}
	}
	
}

void insertar(struct nodo **cab){
	struct nodo *p;
	p = *cab;
	int ban = 0;
	int codigo;
	char nombre[50];
	char telefono[20];
	char correo[50];
	
	printf("digite el codigo : ");
	scanf("%d",&codigo);
	fflush(stdin);
	
	printf("Ingrese el nombre: ");
	scanf("%[^\n]",&nombre);
	fflush(stdin);
	
	printf("digite el numero de telefono: ");
	scanf("%[^\n]",&telefono);
	fflush(stdin);
	
	printf("Ingrese el correo: ");
	scanf("%[^\n]",&correo);
	fflush(stdin);
	
	if(p == NULL){
		struct nodo *p1;
		p1=localizar;
		p1->codigo = codigo;
		strcpy(p1->nombre ,nombre);
		strcpy(p1->telefono ,telefono);
		strcpy(p1->correo ,correo);
		p1->sig = NULL;	
		*cab = p1;
		imprimir(*cab);
	}else{
		int ban2 = 0;
		struct nodo *p2;
		p2 = *cab;
			while(p2->sig!= NULL && ban2 == 0){
					if(p2->codigo == codigo){
						ban2 = 1;
					}else{
						p2 = p2->sig;
					}
			}
		if(ban2 == 1){
			printf("\nEse codigo ya existente en la lista");
		}else{
			if(codigo < p->codigo){
				struct nodo *p1;
				p1 = localizar;
				
				p1->codigo = codigo;
				strcpy(p1->nombre ,nombre);
				strcpy(p1->telefono ,telefono);
				strcpy(p1->correo ,correo);
				
				p1->sig = p;
				p->ant = p1;
				*cab = p;
			}else{
				while(p->sig!= NULL && ban == 0){
					if(p->codigo < codigo){
						p = p->sig;
					}else{
						ban = 1;
					}
				}
					
				if(codigo < p->codigo){
					struct nodo *p1;
					p1 = localizar;
					
					p1->codigo = codigo;
					strcpy(p1->nombre ,nombre);
					strcpy(p1->telefono ,telefono);
					strcpy(p1->correo ,correo);
					
					p1->sig = p;
					p1->ant = p->ant;
					p->ant=p1;
					p1->ant->sig = p1;
				}else{
					struct nodo *p1;
					p1 = localizar;
					
					p1->codigo = codigo;
					strcpy(p1->nombre ,nombre);
					strcpy(p1->telefono ,telefono);
					strcpy(p1->correo ,correo);
					
					p1->ant = p;
					p->sig =p1;
					p1->sig = NULL;
				}
			}
			imprimir(*cab);
		}
	}
}

void buscar_Codigo(struct nodo **cab){
	if(*cab == NULL){
		printf("La lista esta vacia");
	}else{
		int codigo;
		int can = 0;
		printf("\nIngrese el codigo que quiere buscar en lista: ");
		scanf("%d",&codigo);
		fflush(stdin);
		
		struct nodo *p;
		p = *cab;
		
		if(p->sig == NULL){
			if(p->codigo == codigo){
				can++;
			}
		}else{
			while(p->sig != NULL){
				if(p->codigo == codigo){
					can++;
				}
				p = p->sig;
			
				if(p->sig == NULL){
					if(p->codigo == codigo){
						can++;
					}
				}
			}
		}
		if(can != 0){
			printf("\nEl codigo si esta en la lista");
		}else{
			printf("\nEl codigo no esta en la lista");
		}
		imprimir(*cab);
	}
	
}
void eliminar_Codigo(struct nodo **cab){
	if(*cab == NULL){
		printf("La lista esta vacia");
	}else{
		int codigo;
		printf("\nIngrese el codigo que desea eliminar: ");
		int ban = 0;
		scanf("%d",&codigo);
		fflush(stdin);
		
		struct nodo *p;
		p = *cab;
		
		if(p->sig == NULL){
			if(p->codigo == codigo){
				*cab = NULL;
				printf("\nCodigo eliminado ");
			}
		}else{
			if(p->codigo == codigo){
				*cab = p->sig;
				printf("\nCodigo eliminado ");
			}else{
				while(p->sig != NULL && ban == 0){
					if(p->codigo == codigo){
						p->ant->sig = p->sig;
						p->sig->ant = p->ant;
						printf("\nCodigo eliminado ");
						ban = 1;
					}
					p = p->sig;
			
					if(p->sig == NULL){
						if(p->codigo == codigo){
							p->ant->sig = NULL;
							printf("\nCodigo eliminado ");
							ban = 1;
						}
					}
				}
				if(ban == 0){
					printf("El codigo no esta en la lista");
				}
			}
		}
		imprimir(*cab);
	}
}


void buscar_Nombre(struct nodo **cab){
	if(*cab == NULL){
		printf("La lista esta vacia");
	}else{
		char nombre[50];
		int can = 0;
		printf("\nIngrese el nombre que quiere buscar en la lista: ");
		scanf("%[^\n]",&nombre);
		fflush(stdin);
		
		struct nodo *p;
		p = *cab;
		while(p->sig != NULL){
			if(strcmp(p->nombre,nombre)== 0){
				can++;
			}
			p = p->sig;
			if(p->sig == NULL){
				if(strcmp(p->nombre,nombre)== 0){
					can++;
				}
			}
		}
		if(can != 0){
			printf("\nEl nombre si esta en la lista");
		}else{
			printf("\nEl nombre no esta en la lista");
		}
		imprimir(*cab);
	}
}

main(){
	int opc;
	bool run = true;	
	struct nodo *cab;
	cab = NULL;
	while(run){
		printf("\n\t\tOPCIONES");
		printf("\n\n1. Insertar");
		printf("\n2. Buscar por codigo");
		printf("\n3. Buscar por nombre");
		printf("\n4. Eliminar por codigo");
		printf("\n5. Salir");
		printf("\n\n Digite el numero de la opcion que desea: ");
		scanf("%d", &opc);
		fflush(stdin);
		if(opc==1){
			insertar(&cab);
		}
		else if(opc==2){
			buscar_Codigo(&cab);
		}
		else if(opc==3){
			buscar_Nombre(&cab);
		}
		else if(opc==4){
			eliminar_Codigo(&cab);
		}
		else if(opc==5){
			int salir;
			printf("seguro que desea salir? 1(si) / 2(no): ");
			scanf("%d",&salir);
			fflush(stdin);
			if(salir == 1){
				run = false;
			}
		}else{
			printf("opcion no valida!!!");
		}
	}
	getchar();
}
