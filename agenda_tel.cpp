//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

//estrutura de data
typedef struct data DATA;
struct data
{
	int dia;
	int mes;
	int ano;
};

//estrutura de contato
typedef struct contato CONTATO;
struct contato
{
	int num;
	char nome[30];
	char apelido[30];
	char sexo[30];
	char foneres[30];
	char endereco[30];
	char fonecomerc[30];
	char fonecelu[30];
	char ondeconheci[30];
	char relacao[30];
	char obs[30];
	DATA aniv;
	DATA encontro;	

};	

//protótipos
void cabecalho();
void inserir();
void listar();
void pesquisarnome();
void pesquisarelacao();
void pesquisaraniv();
void pesquisar_mes_relacao();
void excluir();
void alterar();

main()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	
	do
	{
		cabecalho();
		printf("1 - Inserir\n");
		printf("2 - Consultar por nome\n");
		printf("3 - Consultar pelo mês aniversário\n");
		printf("4 - Consultar pelo tipo de relação\n");
		printf("5 - Consultar pelo mês de aniversário e pelo tipo de relação\n");
		printf("6 - Alterar\n");
		printf("7 - Excluir\n");
		printf("8 - Listar\n");
		printf("9 - Finalizar\n");
		printf("Escolha uma opção: ");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:	
				inserir();
			break;
			
			case 2:	
				pesquisarnome();
			break;
			
			case 3:
				pesquisaraniv();
			break;
			
			case 4:
				pesquisarelacao();
			break;
			
			case 5:
				pesquisar_mes_relacao();
			break;
			
			case 6:	
				 alterar();
			break;
			
			case 7:
				excluir();
			break;
			
			case 8:	
				listar();
			break;
			
			case 9:
				printf("Obrigado por sua visita!\n");
				getch();
			break;
			
			default:
				printf("Opção inválida!");
				getch();
			break;
		}
	}while(opcao!=8);
}


void cabecalho()
{
	system("cls");
	printf("================================================\n");
	printf("AGENDA ELETRÔNICA\n");
	printf("================================================\n");
}


void inserir()
{
	FILE* arquivo;
	CONTATO ctt;
	
	arquivo = fopen("agenda.txt","ab");
	
	if (arquivo == NULL)
	{
		printf("PROBLEMAS NA ABERTURA DO ARQUIVO!\n");
	}
	else
	{
		do
		{
			cabecalho();
			fflush(stdin);
			printf("Digite o nome: ");	
			gets(ctt.nome);
			
			fflush(stdin);
			printf("Digite o apelido: ");	
			gets(ctt.apelido);
			
			fflush(stdin);
			printf("Digite o sexo [M/F]: ");	
			gets(ctt.sexo);
			
			fflush(stdin);
			printf("Digite o endereço: ");	
			gets(ctt.endereco);
			
			fflush(stdin);
			printf("Digite o telefone residencial: ");	
			gets(ctt.foneres);
			
			fflush(stdin);
			printf("Digite o telefone comercial: ");	
			gets(ctt.fonecomerc);
			
			fflush(stdin);
			printf("Digite o telefone celular: ");	
			gets(ctt.fonecelu);
			
			fflush(stdin);
			printf("Digite o local onde conheceu: ");	
			gets(ctt.ondeconheci);
			
			fflush(stdin);
			printf("Digite o tipo de relação: ");	
			gets(ctt.relacao);
			
			fflush(stdin);
			printf("Digite alguma observação: ");	
			gets(ctt.obs);
			
			fflush(stdin);
			printf("Digite o dia de aniversário: ");	
			scanf("%d",&ctt.aniv.dia);
			
			fflush(stdin);
			printf("Digite o mês de aniversário: ");	
			scanf("%d",&ctt.aniv.mes);
			
			fflush(stdin);
			printf("Digite o ano de aniversário: ");	
			scanf("%d",&ctt.aniv.ano);
			
			fflush(stdin);
			printf("Digite o  dia do primeiro encontro: ");	
			scanf("%d",&ctt.encontro.dia);
			
			fflush(stdin);
			printf("Digite o mês do primeiro encontro: ");	
			scanf("%d",&ctt.encontro.mes);
			
			fflush(stdin);
			printf("Digite o ano do primeiro encontro: ");	
			scanf("%d",&ctt.encontro.ano);
			
			fwrite(&ctt, sizeof(CONTATO),1,arquivo);
			
			printf("Deseja continuar (s/n)?");

		}while(getche() == 's');
		fclose(arquivo);
	}
}


void listar()
{
	FILE* arquivo;
	CONTATO ctt;
	
	cabecalho();
	arquivo = fopen("agenda.txt","rb");
	
	if (arquivo == NULL)
	{
		printf("PROBLEMAS NA ABERTURA DO ARQUIVO!\n");
	}
	else
	{
		while(fread(&ctt,sizeof(CONTATO),1,arquivo)  == 1)
		{
			printf("Nome: %s\n", ctt.nome);
			printf("Apelido: %s\n", ctt.apelido);
			printf("Telefone residencial: %s\n", ctt.foneres);
			printf("Telefone comercial: %s\n", ctt.fonecomerc);
			printf("Telefone celular: %s\n", ctt.fonecelu);
			printf("Endereço: %s\n",ctt.endereco);
			printf("Onde conheci: %s\n", ctt.ondeconheci);
			printf("Relação: %s\n", ctt.relacao);
			printf("Observação: %s\n", ctt.obs);
			printf("Aniversário: %d/%d/%d\n",ctt.aniv.dia,ctt.aniv.mes,ctt.aniv.ano);
			printf("Primeiro encontro: %d/%d/%d\n",ctt.encontro.dia,ctt.encontro.mes,ctt.encontro.ano);
			printf("---------------------------------------------------------------\n\n");
		}
	}
	fclose(arquivo);
	getch();	
}


void pesquisarnome()
{
	FILE* arquivo;
	CONTATO ctt;
	char nome[30];
	
	arquivo = fopen("agenda.txt","rb");
	
	cabecalho();
	if (arquivo == NULL)
	{
		printf("PROBLEMAS NA ABERTURA DO ARQUIVO!\n");
	}
	else
	{
		fflush(stdin);
		printf("Digite o nome a ser pesquisado: ");
		gets(nome);
		
		while(fread(&ctt, sizeof(CONTATO),1,arquivo) == 1)
		{
			if (strcmp(nome, ctt.nome) == 0)
			{
				printf("Nome: %s\n", ctt.nome);
				printf("Apelido: %s\n", ctt.apelido);
				printf("Sexo: %s\n", ctt.sexo);
				printf("Telefone residencial: %s\n", ctt.foneres);
				printf("Telefone comercial: %s\n", ctt.fonecomerc);
				printf("Telefone celular: %s\n", ctt.fonecelu);
				printf("Endereço: %s\n",ctt.endereco);
				printf("Onde conheci: %s\n", ctt.ondeconheci);
				printf("Relação: %s\n", ctt.relacao);
				printf("Observação: %s\n", ctt.obs);
				printf("Aniversário: %d/%d/%d\n",ctt.aniv.dia,ctt.aniv.mes,ctt.aniv.ano);
				printf("Primeiro encontro: %d/%d/%d\n",ctt.encontro.dia,ctt.encontro.mes,ctt.encontro.ano);
				printf("---------------------------------------------------------------\n\n");
			}
		}
	}
	fclose(arquivo);
	getch();
}


void pesquisarelacao()
{
	FILE* arquivo;
	CONTATO ctt;
	char relacao[30];
	
	arquivo = fopen("agenda.txt","rb");
	
	cabecalho();
	if (arquivo == NULL)
	{
		printf("PROBLEMAS NA ABERTURA DO ARQUIVO!\n");
	}
	else
	{
		fflush(stdin);
		printf("Informe o tipo de relação: ");
		gets(relacao);
	
		while(fread(&ctt, sizeof(CONTATO),1,arquivo) == 1)
		{
			if (strcmp(relacao, ctt.relacao) == 0)
			{
				printf("Nome: %s\n", ctt.nome);
				printf("Apelido: %s\n", ctt.apelido);
				printf("Sexo: %s\n", ctt.sexo);
				printf("Telefone residencial: %s\n", ctt.foneres);
				printf("Telefone comercial: %s\n", ctt.fonecomerc);
				printf("Telefone celular: %s\n", ctt.fonecelu);
				printf("Endereço: %s\n",ctt.endereco);
				printf("Onde conheci: %s\n", ctt.ondeconheci);
				printf("Relação: %s\n", ctt.relacao);
				printf("Observação: %s\n", ctt.obs);
				printf("Aniversário: %d/%d/%d\n",ctt.aniv.dia,ctt.aniv.mes,ctt.aniv.ano);
				printf("Primeiro encontro: %d/%d/%d\n",ctt.encontro.dia,ctt.encontro.mes,ctt.encontro.ano);
				printf("---------------------------------------------------------------\n\n");
			}
		}
		fclose(arquivo);
		getch();
	}
}


void pesquisaraniv()
{
	FILE* arquivo;
	CONTATO ctt;
	
	cabecalho();
	arquivo = fopen("agenda.txt","rb");
	
	if (arquivo == NULL)
	{
		printf("PROBLEMAS NA ABERTURA DO ARQUIVO!\n");
	}
	else
	{
		int mes;
		printf("Digite o mês: ");
		scanf("%d",&mes);
		
		while(fread(&ctt, sizeof(CONTATO), 1,arquivo) == 1)
		{
			if (mes == ctt.aniv.mes)
			{
				printf("Nome: %s\n", ctt.nome);
				printf("Telefone residencial: %s\n", ctt.foneres);
				printf("Telefone comercial: %s\n", ctt.fonecomerc);
				printf("Telefone celular: %s\n", ctt.fonecelu);
				printf("Aniversario: %d/%d/%d\n",ctt.aniv.dia,ctt.aniv.mes,ctt.aniv.ano);
				printf("---------------------------------------------------------------\n\n");
			}
		}
	}
	fclose(arquivo);
	getch();
}


void pesquisar_mes_relacao()
{
	FILE* arquivo;
	CONTATO ctt;
	char nome[30];
	
	cabecalho();
	arquivo = fopen("agenda.txt","rb");
	
	if (arquivo == NULL)
	{
		printf("PROBLEMAS NA ABERTURA DO ARQUIVO!\n");
	}
	else
	{
		fflush(stdin);
		printf("Digite o nome a ser pesquisado: ");
		gets(nome);
		
		int mes;
		printf("Digite o mês: ");
		scanf("%d",&mes);
		
		while(fread(&ctt, sizeof(CONTATO), 1,arquivo) == 1)
		{
			if (mes == ctt.aniv.mes && strcmp(nome,ctt.nome)==0)
			{
				printf("Nome: %s\n",ctt.nome);
				printf("Telefone residencial: %s\n", ctt.foneres);
				printf("Telefone comercial: %s\n", ctt.fonecomerc);
				printf("Telefone celular: %s\n", ctt.fonecelu);
				printf("Aniversario: %d/%d/%d\n",ctt.aniv.dia,ctt.aniv.mes,ctt.aniv.ano);
				printf("---------------------------------------------------------------\n\n");
			}
		}	
	}
	fclose(arquivo);
	getch();
}


void excluir()
{
	FILE *arquivo;
	FILE *temp;
	CONTATO ctt;
	char fonecelu[30];
	arquivo = fopen("agenda.txt","rb");
	temp = fopen("tmp.txt","wb");
	if (arquivo == NULL)
	{
		printf("PROBLEMAS NA ABERTURA DO ARQUIVO!\n");
	}
	else
	{
		cabecalho();
		fflush(stdin);
		printf("Digite o telefone celular do registro a ser deletado: ");
		gets(fonecelu);
		while(fread(&ctt,sizeof(CONTATO),1,arquivo)==1)
		{
			if(strcmp(fonecelu,ctt.fonecelu)==0)
			{
				printf("Nome: %s\n",ctt.nome);
				printf("Telefone residencial: %s\n", ctt.foneres);
				printf("Telefone comercial: %s\n", ctt.fonecomerc);
				printf("Telefone celular: %s\n", ctt.fonecelu);
				printf("Aniversário: %d/%d/%d\n",ctt.aniv.dia,ctt.aniv.mes,ctt.aniv.ano);
				printf("---------------------------------------------------------------\n\n");
			}
			else
			{
				fwrite(&ctt,sizeof(CONTATO),1,temp);
			}
		}	
	}
	fclose(arquivo);
	fclose(temp);
	fflush(stdin);
	printf("Deseja deletar (s/n)? ");
	if(getche()=='s')
	{
		if(remove("agenda.txt")==0 && rename("tmp.txt","agenda.txt") == 0)
		{
			 printf("\nOperação realizada com sucesso!");
		}
		else
		{
			remove("tmp.txt");
		}	
	}
	fclose(temp);
  	fclose(arquivo);
  	getch();
}

void alterar()
{
    	FILE *arq;
        CONTATO ctt;
        char novonome[20];
        int achei = 0;    
        
        arq = fopen("agenda.txt", "r+b");
        if (arq == NULL)
            printf ("Erro de abertura no arquivo: agenda.txt");
        else 
		{ 
				cabecalho();   
				int opcao;
				printf("================MENU ALTERAR====================");
				printf("\n1 - Telefone Celular ");
				printf("\n2 - Endereço");
				printf("\n3 - Telefone Residencial");
				printf("\nInforme o número do campo que deseja alterar: ");
				scanf("%d",&opcao);
				switch(opcao)
				{
					case 1:
						printf ("Digite o nome da pessoa a ser consultada: ");
                		fflush(stdin);
                		gets (novonome);
                		while (fread(&ctt, sizeof(CONTATO), 1, arq))
						{
							if ((strcmp(novonome, ctt.nome)==0))
							{
								printf("Digite o novo número de telefone celular: ");
                            	fflush(stdin);
                            	gets(ctt.fonecelu);
                           	 	achei = 1;
                            	fseek (arq, sizeof(CONTATO)*-1, SEEK_CUR);
                            	fwrite(&ctt, sizeof(CONTATO), 1, arq);
                            	fseek (arq, 0, SEEK_CUR);
							}
						} 
						if (!achei)
						{
                    		printf ("\nNome não encontrado");    
            				fclose(arq);  
    					}
    				case 2:
    					printf ("Digite o nome da pessoa a ser consultada: ");
                		fflush(stdin);
                		gets (novonome);
                		while (fread(&ctt, sizeof(CONTATO), 1, arq))
						{
							if ((strcmp(novonome, ctt.nome)==0))
							{
								printf("Digite o novo endereço: ");
                            	fflush(stdin);
                            	gets(ctt.endereco);
                           	 	achei = 1;
                            	fseek (arq, sizeof(CONTATO)*-1, SEEK_CUR);
                            	fwrite(&ctt, sizeof(CONTATO), 1, arq);
                            	fseek (arq, 0, SEEK_CUR);
							}
						} 
						if (!achei)
						{
                    		printf ("\nNome não encontrado");    
            				fclose(arq);  
    					}
    				case 3:
    					printf ("Digite o nome da pessoa a ser consultada: ");
                		fflush(stdin);
                		gets (novonome);
                		while (fread(&ctt, sizeof(CONTATO), 1, arq))
						{
							if ((strcmp(novonome, ctt.nome)==0))
							{
								printf("Digite o novo telefone residencial: ");
                            	fflush(stdin);
                            	gets(ctt.foneres);
                           	 	achei = 1;
                            	fseek (arq, sizeof(CONTATO)*-1, SEEK_CUR);
                            	fwrite(&ctt, sizeof(CONTATO), 1, arq);
                            	fseek (arq, 0, SEEK_CUR);
							}
						} 
						if (!achei)
						{
                    		printf ("\nNome não encontrado");    
            				fclose(arq);  
    					}	
				}

    	}
}
