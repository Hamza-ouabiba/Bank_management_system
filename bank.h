
    //les structures:
	typedef struct{
	  int jour;
	  int mois;
	  int anne;
	}Date;
	typedef struct {
		 char now[256];
		 int numero;
		 char localisation[256];
		 int proprietaire;
		 float solde_actuel;
		 float ancien_solde;
		 char derniere_operation;
		 char mt_de_passe[256];
	} compteBancaire;
	typedef struct {
		  int cin;
		  char nom[20];
		  char prenom[20];
		  char ville[20];
	      int compte;//vaut 1 si le client a deja un compte:
		  Date naissance;
	} client;
	//la recherche d'un compte Par cin son cin dans le tableau des comptes et retourner son indice :
	int chercherCompteParCin(compteBancaire *n,int taille,int cin) {
		 int i;
		 for(i=0;i<taille;i++) {
		 	   if(cin == (n+i)->proprietaire) {
		 	   	   return i;
				}
		 }
		 return -1;
	}
	//la recherche d'un compte et retourner son indice :
	int chercherCompte(compteBancaire *n,int taille,int numero) {
		 int i;
		 for(i=0;i<taille;i++) {
		 	  if(numero == (n+i)->numero) {
		 	  	    return i;
			   }
		 }
		 return -1;
	}
	//la recherche d'un compte Par cin son cin dans le tableau des clients et retourner son indice :
	int rechercheClient(client *u,int taille,int cin)
	{
	    int i;
	    for(i=0;i<taille;i++) {
	         if(cin == (u+i)->cin) {
	             return i;
	         }
	    }
	    return -1;
	}
	//la recherche d'un numeor de compte et retourner le numero de cin :
	int chercherParNumeroParCin(compteBancaire *n,int taille,int numero) {
		  int i;
		  for(i=0;i<taille;i++) {
		  	  if(numero == (n+i)->numero) {
		  	  	    return (n+i)->proprietaire;
				}
		  }
		  return -1;
	}
	//permet de renvoyer l'adresse d'un client :
	compteBancaire* chercherNumero_co(compteBancaire *n,int taille,int numero) {
		  int i;
		  for(i=0;i<taille;i++) {
		  	    if(numero == (n+i)->numero) {
		  	    	   return (n+i);
				  }
		  }
	}
	///inserer les infos Les client dans File_client:
	void FILE_CLIENT(FILE *File_Client,client *clt ,int taille){
	       int i=taille;
			      fprintf(File_Client,"%d\t",(clt+i)->cin);
	              fprintf(File_Client,"%s\t",(clt+i)->nom);
		          fprintf(File_Client,"%s\t",(clt+i)->prenom);
		          fprintf(File_Client,"%s\t",(clt+i)->ville);
		          fprintf(File_Client,"%d/%d/%d\n",(clt+i)->naissance.jour,(clt+i)->naissance.mois,(clt+i)->naissance.anne);
	}
	void ajoutClient(client *user,int *taille,FILE *client)
	{
	    int i = *taille;
	       do {
	             printf("Donner le cin : ");
	             scanf("%d",&(user+i)->cin);
	         } while(rechercheClient(user,*taille,(user+i)->cin) != -1);
	         printf("Nom : ");
		     fflush(stdin);
	         gets((user+i)->nom);
		     printf("Prenom :");
		     fflush(stdin);
		     gets((user+i)->prenom);
		     printf("Ville : ");
		     fflush(stdin);
		     gets((user+i)->ville);
		     printf("Date de naissance : Jour : ");
		     scanf("%d",&(user+i)->naissance.jour);
	         printf("Date de naissance : Mois : ");
		     scanf("%d",&(user+i)->naissance.mois);
		     printf("Date de naissance : Annee : ");
		     scanf("%d",&(user+i)->naissance.anne);

			 FILE_CLIENT(client,user,*taille);

	         (*taille)++;
	}
	//afficher tous les clients :
	void listerClients(client *u,int taille)
	{
	    int i;

	    if(taille>0) {
	    	for(i=0;i<taille;i++) {
	         printf("\n---------------------------\n");
	         printf("cin : %d :\n",(u+i)->cin);
	         printf("Nom : %s \n",(u+i)->nom);
	         printf("Prenom : %s\n",(u+i)->prenom);
	         printf("Ville : %s\n",(u+i)->ville);
	         printf("Date de naissance : %d/%d/%d\n",(u+i)->naissance.jour,(u+i)->naissance.mois,(u+i)->naissance.anne);
	         if((u+i)->compte == 1) {
	             printf("Ce client dispose deja d'un compte Bancaire : \n");
	         } else {
	              printf("le client ne dispose pas d'un compte Bancaire : \n");
	          }
	    }
	    printf("\n");
		} else {
			 printf("Veuillez ajoutez des clients dans la base de donnee");
		}
	}
	//ajouter les comptes dans le fichier compte :
	void FileCompte(compteBancaire *n,int taille,FILE *compte) {
		  int i = taille;
		  fprintf(compte,"\n%d ",(n+i)->numero);
		  fprintf(compte,"%d\t",(n+i)->proprietaire);
		  fprintf(compte,"%s\t",(n+i)->localisation);
		  fprintf(compte,"%.2f\t",(n+i)->solde_actuel);
		  //fprintf(compte,"%s",(n+i)->now);
	}
	//la creation du compte :
	void creationCompte(compteBancaire *b,client *clt,int *taille,int cin,int taille_cl,FILE *compte)
	{
		 int i = *taille;
		 int test;
		 int c=0;
		 time_t maintenant;
		 int numero_co;
	     //chercher le cin dans le tableau des clients :
	      srand(time(NULL));
				do{
					numero_co=rand();
					//cherhcher si le numero deja existe dans le tableau des comptes bancaires
				}while(numero_co<9999 && chercherCompte(b,*taille,numero_co)!=-1 );
	     time(&maintenant);
	     //cherhcher si le numero deja existe dans le tableau des comptes bancaires  :
	     //tester :
		 	  	  (b+i)->proprietaire = cin;
		 	  	  (b+i)->numero = numero_co;
	           test = rechercheClient(clt,taille_cl,(b+i)->proprietaire);
	           //clt
		 	   (clt+test)->compte = 1;

		 	   printf("Donner la localisation : ");
		 	   fflush(stdin);
		 	   scanf("%s",(b+i)->localisation);
		 	   printf("Donner le montant a deposer initialement : ");
		 	   scanf("%f",&(b+i)->solde_actuel);
		 	   (b+i)->ancien_solde = (b+i)->solde_actuel;

		 	   //faire la mise a jour du solde actuelle :
		 	   (b+i)->derniere_operation = 'd';
                strcpy((b+i)->now,ctime(&maintenant));
		 	   //enregistrer la date actuelle :
		 	   do {
		 	   	     printf("Donner un mot de passe pour ce compte Bancaire : (12 CHAR Max ! )");
		 	   	     fflush(stdin);
		 	   	     gets((b+i)->mt_de_passe);
				} while(strlen((b+i)->mt_de_passe) > 13);

				FileCompte(b,*taille,compte);

		 	   (*taille)++;
		 	   printf("Creation Compte avec succes.......\n");
		 	   getch();
	}
	//afficher un seul compte :
	void afficherCompte(compteBancaire b) {
	         printf("\n---------------------------------\n");
		 	 printf("Numero de compte: %d\n",b.numero);
		 	 printf("Numero de cin : %d \n",b.proprietaire);
		 	 printf("Date de creation : %s\n",b.now);
		 	 printf("Solde actuelle  : %.2f\n",b.solde_actuel);
		 	 if(b.derniere_operation!='d' && b.derniere_operation!='v' && b.derniere_operation!='r') {
		 	 	   printf("Aucune operation effectuee pour le moment :\n ");
			  } else {
			  	  printf("Derniere operation : %c\n",b.derniere_operation);
			  }
			  printf("----------------------------------\n");
	}
	//afficher tous les comptes:
	void listerComptes(compteBancaire *b,int taille) {
		 int i;
		 if(taille > 0) {
		 	 for(i=0;i<taille;i++) {
	            afficherCompte(*(b+i));
		     }
		 } else {
		 	  printf("Pas de compte enregistre ");
		 }
	}
	//permet de faire le virement entre 2 clients  :
	void virementCompte(compteBancaire *n,int taille,int numero1) {
		 float montant=0;
		 int numero2;
		 compteBancaire *n1;
		 compteBancaire *n2;
		 //afficher les comptes pour l'utilisateur;
		 if(taille > 1) {
		 listerComptes(n,taille);
		 printf("\n");
				do {
							 printf("Donner le numero de compte de la personne a faire le virement : ");
							 scanf("%d",&numero2);
			   } while(chercherCompte(n,taille,numero2) == -1 || numero1 == numero2);
		 //l'utilisateur donne le montant  :
		 hna:
		 printf("Saisir le montant  : ");
		 scanf("%f",&montant);
		 //renvoyer l'adresse des deux clients :
		 n1 = chercherNumero_co(n,taille,numero1);
		 n2 = chercherNumero_co(n,taille,numero2);
					 	 if(montant <= n1->solde_actuel) {
								 	 n1->solde_actuel -= montant;
								 	 printf("le solde restant : %.2f \n",n1->solde_actuel);
								 	 n2->solde_actuel += montant;
								 	 printf("le solde du deuxieme compte:  %.2f \n",n2->solde_actuel);
								 	 n1->derniere_operation = 'v';
								 	 n2->derniere_operation = 'v';
								 	 printf("Virement avec succes : ");
								 	 listerComptes(n,taille);
								 	 getch();
					 } else {
					 	 printf("Le montant saisi est tres eleve de votre solde actuelle veuillez reessayer \n");
					 	 goto hna;
					 	 getch();
					 }
		 } else printf("Vous pouvez pas effectuer pour le moment a cause de manque des clients ");
	}
	//afficher un seul client :
	void detailsClient(client *user,int taille) {
		  int i;
		  int cin;
		  printf("Donner le cin d'un client a afficher : ");
		  scanf("%d",&cin);
		  for(i=0;i<taille;i++) {
		  	   if(cin == (user+i)->cin) {
		  	   	     printf("\n------Client Numero %d------\n",i+1);
		  	   	     printf("Cin : %d\n",(user+i)->cin);
		  	   	     printf("Nom : %s\n",(user+i)->nom);
		  	   	     printf("Prenom : %s\n",(user+i)->prenom);
		  	   	     printf("Ville : %s\n",(user+i)->ville);
		  	   	     printf("Date de Naissance: %d/%d/%d\n",(user+i)->naissance.jour,(user+i)->naissance.mois,(user+i)->naissance.anne);
				 } else {
				     printf("Ce client ne se trouve pas ! ");
				 }
		  }
	}
	//faire le depot de la monnaie:
	void depotCompte(compteBancaire *array,int numero_compte,int taille) {
		 float montant_depot;
		 compteBancaire *n;
		 //obtenir le compte actuelle :
		 n = chercherNumero_co(array,taille,numero_compte);
		 printf("Donner le montant a deposer dans votre compte : ");
		 scanf("%f",&montant_depot);
		 //mise a jour du solde:
		 n->solde_actuel += montant_depot;
		 n->derniere_operation = 'd';
	        //enregistrement des operations dans un fichier :
			   //a realiser apres :

	    afficherCompte(*n);
	    getch();
	}
	//retrait de la monnaie :
	void retraitCompte(compteBancaire *array,int numero_compte,int taille) {
		 float retrait;
		 compteBancaire *n;
		 n = chercherNumero_co(array,taille,numero_compte);
	     printf("Donner le montant de retraite :  ");
		 scanf("%f",&retrait);
		 //tester sur le solde du compte :
		 if(retrait > n->solde_actuel) {
			  printf("Vous pouvez pas faire la transaction pour le moment veuillez reessayer plus tard : ");
			  return;
		 } else {
			  //mise a jour du solde :
			  n->solde_actuel -= retrait;
			  n->derniere_operation = 'r';
		 }
		 afficherCompte(*n);
		 getch();
	}
	//faire afficher un client caracteriser par son numero de compte:
	void detailsCompte(compteBancaire *n,int taille,int numero) {
		 int i;
		 for(i=0;i<taille;i++) {
		 	    if(numero == (n+i)->numero) {
		 	    	   printf("\n------Compte Numero %d-------\n",i+1);
		 	    	   printf("Numero De Compte : %d \n",(n+i)->numero);
		 	    	   printf("Date de Creation du compte : %s\n",(n+i)->now);
		 	    	   printf("Localisation : %s\n",(n+i)->localisation);
		 	    	   printf("Cin : %d\n",(n+i)->proprietaire);
		 	    	   printf("Solde Actuelle : %.2f\n",(n+i)->solde_actuel);
		 	    	   printf("Ancien solde : %.2f\n",(n+i)->ancien_solde);
				 }
		 }
	}
	//fonction gotoxy pour l'affichage de la console:
	void gotoxy(int x, int y)
	{
	    printf("%c[%d;%df", 0x1B, y, x);
	}
	int menuProgramme() {
			int choix;
		                  gotoxy(25,2);printf("¦¦¦¦¦¦   ¦¦¦¦¦¦   ¦¦¦¦¦¦  ¦¦¦¦¦¦      ¦¦¦¦¦¦   ¦¦¦¦¦  ¦¦¦    ¦¦ ¦¦   ¦¦");
		                  gotoxy(25,3);printf("¦¦   ¦¦ ¦¦    ¦¦ ¦¦    ¦¦ ¦¦   ¦¦     ¦¦   ¦¦ ¦¦   ¦¦ ¦¦¦¦   ¦¦ ¦¦  ¦¦");
		                  gotoxy(25,4);printf("¦¦¦¦¦¦  ¦¦    ¦¦ ¦¦    ¦¦ ¦¦¦¦¦¦      ¦¦¦¦¦¦  ¦¦¦¦¦¦¦ ¦¦ ¦¦  ¦¦ ¦¦¦¦¦");
		                  gotoxy(25,5);printf("¦¦      ¦¦    ¦¦ ¦¦    ¦¦ ¦¦   ¦¦     ¦¦   ¦¦ ¦¦   ¦¦ ¦¦  ¦¦ ¦¦ ¦¦  ¦¦");
		                  gotoxy(25,6);printf("¦¦       ¦¦¦¦¦¦   ¦¦¦¦¦¦  ¦¦   ¦¦     ¦¦¦¦¦¦  ¦¦   ¦¦ ¦¦   ¦¦¦¦ ¦¦   ¦¦");
		                  gotoxy(28,8);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
		                  gotoxy(28,9);printf("³                   MENU DU Programme :                    ³ \n");
		                  gotoxy(28,10);printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
		                  gotoxy(27,11);printf(" ³       VEUILLEZ CONFIRMER VOTRE CHOIX PAR ENTREE          ³\n");
		                  gotoxy(27,12);printf(" ³           1-Ajouter Un client                            ³ \n");
		                  gotoxy(27,13);printf(" ³           2-Afficher les clients                         ³ \n");
		                  gotoxy(27,14);printf(" ³           3-Creer un compte                              ³\n");
		                  gotoxy(27,15);printf(" ³           4-Afficher les comptes                         ³\n");
		                  gotoxy(27,16);printf(" ³           5-Se connecter avec votre compte               ³\n");
		                  gotoxy(27,17);printf(" ³           6-afficher un compte Bancaire                  ³\n");
		                  gotoxy(27,18);printf(" ³           7-Supprimer un client                          ³\n");
		                  gotoxy(27,19);printf(" ³           8-Afficher un client                           ³\n");
		                  gotoxy(27,20);printf(" ³           9-Afficher les clients sur fichier             ³\n");
		                  gotoxy(27,21);printf(" ³           10-Afficher les comptes bancaires sur fichier  ³\n");
		                  gotoxy(27,22);printf(" ³           0-QUITTER                                      ³\n");
		                  gotoxy(28,23);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
			 	   	      gotoxy(28,24);
                          while(scanf("%d",&choix) != 1) {
                                gotoxy(28,27);printf("Choix errone");
                                delay(1000);gotoxy(28,27);printf("            ");
                                gotoxy(28,24);printf("       ");
                                rewind(stdin);
                          }
                          return choix;
		}
	int menuCompte(int numero_co) {
	    int choix;
	                  gotoxy(25,2);printf("¦¦¦¦¦¦   ¦¦¦¦¦¦   ¦¦¦¦¦¦  ¦¦¦¦¦¦      ¦¦¦¦¦¦   ¦¦¦¦¦  ¦¦¦    ¦¦ ¦¦   ¦¦");
	                  gotoxy(25,3);printf("¦¦   ¦¦ ¦¦    ¦¦ ¦¦    ¦¦ ¦¦   ¦¦     ¦¦   ¦¦ ¦¦   ¦¦ ¦¦¦¦   ¦¦ ¦¦  ¦¦");
	                  gotoxy(25,4);printf("¦¦¦¦¦¦  ¦¦    ¦¦ ¦¦    ¦¦ ¦¦¦¦¦¦      ¦¦¦¦¦¦  ¦¦¦¦¦¦¦ ¦¦ ¦¦  ¦¦ ¦¦¦¦¦");
	                  gotoxy(25,5);printf("¦¦      ¦¦    ¦¦ ¦¦    ¦¦ ¦¦   ¦¦     ¦¦   ¦¦ ¦¦   ¦¦ ¦¦  ¦¦ ¦¦ ¦¦  ¦¦");
	                  gotoxy(25,6);printf("¦¦       ¦¦¦¦¦¦   ¦¦¦¦¦¦  ¦¦   ¦¦     ¦¦¦¦¦¦  ¦¦   ¦¦ ¦¦   ¦¦¦¦ ¦¦   ¦¦");
	                  gotoxy(28,8);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
	                  gotoxy(28,9);printf("³                 MENU DU Compte  : %d                  ³\n",numero_co);
	                  gotoxy(28,10);printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
	                  gotoxy(27,11);printf(" ³       VEUILLEZ CONFIRMER VOTRE CHOIX PAR ENTREE          ³\n");
	                  gotoxy(27,12);printf(" ³           1-Depot D'argent                               ³\n");
	                  gotoxy(27,13);printf(" ³           2-Retrait d'argent                             ³\n");
	                  gotoxy(27,14);printf(" ³           3-Effectuer un virement                        ³\n");
	                  gotoxy(27,15);printf(" ³           4-Information de votre compte                  ³\n");
	                  gotoxy(27,16);printf(" ³           5-Se Deconnecter                               ³\n");
	                  gotoxy(27,17);printf(" ³           6-Cloturer Votre Compte                        ³\n");
	                  gotoxy(27,18);printf(" ³           0-QUITTER                                      ³\n");
	                  gotoxy(28,19);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		 	   	      gotoxy(28,20);
		 	   	      while(scanf("%d",&choix) != 1) {
                                gotoxy(28,27);printf("Choix errone");
                                delay(1000);gotoxy(28,27);printf("            ");
                                gotoxy(28,24);printf("       ");
                                rewind(stdin);
                          }
                          return choix;
		 	   	return choix;
	}
	//la suppression d'un compte:
	void ClotureCompte(client *clt , compteBancaire *C , int *taille ,int *taille2,int cin){
	  int i;
	  int test;
	  int numero;
	  int position;
	  position = chercherCompteParCin(C,*taille2,cin);

	     do{
			 system("cls");
			 printf("numero de compte : %d \n",(C+position)->numero);
			 printf("\n------------------------------------------------------------\n");
			 printf("Pour Supprimer votre compte saisir votre Numero De compte : ");
			 scanf("%d",&numero);
			 test=chercherCompte(C,*taille2,numero);
		   }while( test==-1 );

		     //Suppression de compt:
		    for(i=test ; i<*taille2-1;i++)
	             *(C+i)=*(C+i+1);
	        //ce client n'a pas un compte:
		    test=rechercheClient(clt , *taille , cin);
	        (clt+test)->compte=0;
		    (*taille2)--;

	}
	//la suppression d'un client :
	void SupprimerClient( client *clt,compteBancaire *C,int *taille,int *taille2){
	 int i;
	 int cin;
	 int test;
	      	       do{
					 system("cls");
					 printf("\n------------------------------------------------------------\n");
					 printf("Pour Supprime votre compte_client saisir votre CIN  : ");
					 scanf("%d",&cin);
					 test=rechercheClient(clt,*taille ,cin);
				   }while( test==-1 );
					do {
						     if((clt+test)->compte != 1)
								{
							     	//Si ce client n'a pas un compte_bancaire------>
									///Suppression de compte_client:
									for(i=test ; i<*(taille)-1 ;i++)
										*(clt+i)=*(clt+i+1);

									(*taille)--;
									break;
								}
								else
								{
								///Si ce client a un compte_bancaire
									printf("\n\t-Pour Suppprimer votre compt_client!!!");
									printf("\n\t-il faut d'abord cloture votre compte bancaire!!!");
									ClotureCompte(clt,C,taille , taille2 ,cin);
								}
					} while(1);
	}
	//

void delay(clock_t a)
{
    clock_t depart;
    depart  = clock();
    while(clock()-depart<a)
    {

    }
}

void intro()
{
    int i;
    char intro[]="   Bienvenue a Poor Bank";
     for(i=0;i<10;i++)
    {
        printf("\n");
    }
    for(i=0;i<40;i++)
    {
        printf(" ");
    }
    for(i=0;intro[i]!='\0';i++)
    {
        printf("%c",intro[i]);
        delay(60);
    }
    printf("\n");
    delay(1500);
    system("cls");
}
