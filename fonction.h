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
int chercherCompteParCin(compteBancaire *n,int taille,int cin);
//la recherche d'un compte et retourner son indice :
int chercherCompte(compteBancaire *n,int taille,int numero);
//la recherche d'un compte Par cin son cin dans le tableau des clients et retourner son indice :
int rechercheClient(client *u,int taille,int cin);
//la recherche d'un numeor de compte et retourner le numero de cin :
int chercherParNumeroParCin(compteBancaire *n,int taille,int numero);
//permet de renvoyer l'adresse d'un client :
compteBancaire* chercherNumero_co(compteBancaire *n,int taille,int numero);
//inserer les infos Les client dans File_client:
void FILE_CLIENT(FILE *File_Client,client *clt ,int taille);
void ajoutClient(client *user,int *taille,FILE *client);
//afficher tous les clients :
void listerClients(client *u,int taille);
//ajouter les comptes dans le fichier compte :
void FileCompte(compteBancaire *n,int taille,FILE *compte);
//la creation du compte :
void creationCompte(compteBancaire *b,client *clt,int *taille,int cin,int taille_cl,FILE *compte);
//afficher un seul compte :
void afficherCompte(compteBancaire b) ;
//afficher tous les comptes:
void listerComptes(compteBancaire *b,int taille);
//permet de faire le virement entre 2 clients  :
void virementCompte(compteBancaire *n,int taille,int numero1);
//afficher un seul client :
void detailsClient(client *user,int taille);
//faire le depot de la monnaie:
void depotCompte(compteBancaire *array,int numero_compte,int taille);
//retrait de la monnaie :
void retraitCompte(compteBancaire *array,int numero_compte,int taille) ;
//faire afficher un client caracteriser par son numero de compte:
void detailsCompte(compteBancaire *n,int taille,int numero);
//fonction gotoxy pour l'affichage de la console:
void gotoxy(int x, int y);
int menuProgramme();
int menuCompte(int numero_co);
//la suppression d'un compte:
void ClotureCompte(client *clt , compteBancaire *C , int *taille ,int *taille2,int cin);
void delay(clock_t a);
void intro();

