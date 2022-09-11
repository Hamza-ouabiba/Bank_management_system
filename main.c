#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include"bank.c"
int main()
{
    int cfc = 0;//compter les informations du fichier client :
    int cfcom = 0;//compter les informations du fichier compte :
    int c = 0;//compter le nombre de caractere dans le mot de passe :
    int cin_co;//pour que le client lorsqu'il se connecte a son compte on recupere son cin :
    int taille = 0;//la taille du tableau du client :
    int taille2=0;//la taille du tableau du compte :
    int numero_co2;//le numero de compte du deuxieme compte bancaire (Virement)
    int numero_co;//le numero de compte du premier compte bancaire (Virement)
    client *u;//tableau des clients :
    FILE *clt = NULL;//fichier pour les clients :
    FILE *compte = NULL;//fichier pour les comptes :
    char mt_passe[256];//mot de passe :
    client l;//client pour affichage du fichier
    compteBancaire *n;//tableau des comptes :
    compteBancaire cpt; //ce compte est pour le fichier et non pas un pointeur
    int cin;//cin pour la creation des clients :
    int choix;//choix du menu :
    int choix2;
    // u = tableau des clients :
    u = (client *)malloc(sizeof(client)*taille);
    //n = tableau des comptes :
    n = (compteBancaire *)malloc(sizeof(compteBancaire)*taille2);
    //creation du fichier
    system("COLOR 02");
    intro();
    clt = fopen("client.txt","a+");
    compte = fopen("compte.txt","a+");
    if(u && n && clt && compte) {
		   do {
			      Menu :
			      system("cls");
			      choix = menuProgramme();
			       switch(choix) {
				       case 1:{
					      system("cls");
					      clt = fopen("client.txt","a");
					      u = (client *)realloc(u,sizeof(client)*(taille+1));
					      ajoutClient(u,&taille,clt);
					      fclose(clt);
								};break;

				       case 2: system("cls");listerClients(u,taille);break;
				       case 3: {
					system("cls");
						printf("Donner un cin : ");
						scanf("%d",&cin);
						if(rechercheClient(u,taille,cin) != -1 && chercherCompteParCin(n,taille2,cin) == -1) {
							compte = fopen("compte.txt","a");
								    n = (compteBancaire *)realloc(n,sizeof(compteBancaire)*(taille2+1));
								    creationCompte(n,u,&taille2,cin,taille,compte);
								    } else if(rechercheClient(u,taille,cin) == -1) {
												    printf("Vous devez deja creer un client pour pouvoir creer un compte ");
								} else if( chercherCompteParCin(n,taille2,cin) != -1) {
												    printf("Vous avez deja un compte Bancaire voulez vous connectez a votre compte ? \n");
												    puts("1-Oui");
												    puts("2-Revenir au Menu principal ");
												    scanf("%d",&choix2);
									     if(choix2 == 1) {
									  goto hna;
									  }
									}
									    fclose(compte);
									break;
								  }
							case 4: {
								system("cls");
								  listerComptes(n,taille2);
								break;
							}
							case 5: {
							   if(taille2 > 0) {
											   hna :
											   system("cls");
												do {
												 listerComptes(n,taille2);
												 printf("Pour se connecter avec votre compte veuillez saisir votre numero de compte: ");
												 scanf("%d",&numero_co);
											    } while(chercherCompte(n,taille2,numero_co) == -1);
											    do {
												 printf("Mot De passe Du compte : ");
												 while(1) {
													fflush(stdin);
													mt_passe[c] = getch();
																    if(mt_passe[c] == 13)
																   break;
																else if(mt_passe[c] == '\b') {

																		}
															       else
								 printf("*");
															c++;
													 }
													 mt_passe[c] = '\0';
													 if(strcmp(mt_passe,(n+chercherCompte(n,taille2,numero_co))->mt_de_passe)  != 0) {
														   printf("\nReesayer svp\n");
														   c = 0;
													 }
												} while(strcmp(mt_passe,(n+chercherCompte(n,taille2,numero_co))->mt_de_passe)  != 0);
												printf("\nConnexion Avec succes !!\n");
												getch();
											    do {
												system("cls");
											 choix = menuCompte(numero_co);
												 switch(choix) {
													   case 1: depotCompte(n,numero_co,taille2) ;break;
													   case 2: retraitCompte(n,numero_co,taille2);break;
													   case 3: virementCompte(n,taille2,numero_co);break;
														   case 4: detailsCompte(n,taille2,numero_co);break;
														   case 5: {
															   numero_co = 0;
															   goto Menu;
																break;
														   }
														   case 6: {
															     cin_co =  chercherParNumeroParCin(n,taille2,numero_co);
															     getch();
															 ClotureCompte(u,n,&taille,&taille2,cin_co);
															 listerComptes(n,taille2);
															 goto Menu;
															break;
														   }
														   case 0: exit(0);
													 }
													 getch();
												} while(choix != 0);
								 ///rechercher du numero dans le tabelau des comptes:
								} else  printf("Pas de compte enregistre pour le moment !!!!!");
								break;
							}
							case 6: {
					   printf("Donner le numero du compte a afficher : ");
				       scanf("%d",&numero_co);
				       if(chercherCompte(n,taille,numero_co) == -1) {
						 printf("Ce compte n'existe pas\n ");
						 break;
						}
				       detailsCompte(n,taille2,numero_co);
							};break;
							case 7: {
								     //suppression d'un client dans le tableau des clients :
								 if(taille > 0) {
										    SupprimerClient(u,n,&taille,&taille2);
											if(taille!= 0 && taille2!=0){
												u = (client *)realloc(u, sizeof(client)*taille);
												n = (compteBancaire *)realloc(n , sizeof(compteBancaire)*taille2);
						       ///Supprimer le dernierclien ou compte Bancaire:
										    }else if(taille == 0 && taille2 == 0 ) {
												u = (client *)malloc(sizeof(client)*taille);
												n = (compteBancaire *)malloc(taille2*sizeof(compteBancaire));
											}else if(taille == 0) {
												u = (client *)malloc(sizeof(client)*taille);
											}else if(taille2 == 0) {
												n = (compteBancaire *)malloc(taille2*sizeof(compteBancaire));
											}
							getch();
									 } else printf("Pas de client enregistrer ");
								break;
							}
							case 8: detailsClient(u,taille);break;
							case 9: {
								system("cls");
									clt = fopen("client.txt","r");
								if(clt) {
									    printf("\n\t\t\t\t---------Affichage sur fichier---------\n");
				rewind(clt);
												 while(fscanf(clt,"%d%s%s%s%d/%d/%d",&l.cin,l.nom,l.prenom,l.ville,&l.naissance.jour,&l.naissance.mois,&l.naissance.anne) == 7){
													cfc++;
														 printf("\n-----------------------\n");
															 printf("-CIN : %d ",l.cin);
														     printf("\n-Nom : %s ",l.nom);
														     printf("\n-Prenom : %s ",l.prenom);
														     printf("\n-Ville : %s ",l.ville);
														     printf("\n-Date de naissance : (%d/%d/%d) ",l.naissance.jour,l.naissance.mois,l.naissance.anne);
													}
													if(cfc == 0) {
														 printf("rien a afficher pour le momet : ");
													}
								} else {
									 printf("erreur");
								}fclose(clt);
								break;
							}
							case 10 : {
								system("cls");
								compte = fopen("compte.txt","r");
								if(compte) {
									rewind(compte);
									  while(fscanf(compte,"%d%d%s%f",&cpt.numero,&cpt.proprietaire,cpt.localisation,&cpt.solde_actuel) == 4) {
										    printf("\n\t\t\t\t---------Affichage sur fichier---------\n");
										    printf("\n--------------------------------\n");
										    printf("Numero de compte : %d\n",cpt.numero);
										    printf("Cin : %d\n",cpt.proprietaire);
										    printf("Localisation : %s\n",cpt.localisation);
										    printf("Solde actuelle : %.2f\n",cpt.solde_actuel);
										    //printf("Date de creation de compteBancaire: %s",cpt.now);
										    cfcom++;
									  }
									  if(cfcom == 0) {
										 printf("rien a afficher pour le moment : ");
									  }

								} else printf("Erreur ");
								fclose(compte);
								break;
							}
					   }
					getch();
			} while(choix!=0);//choix == 0 && isdigit(choix)
    }

	free(n);
	free(u);
    return 0;
}

