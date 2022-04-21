#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Les structures /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


typedef struct date{
    int Jour , Mois , Annee;
}date;

typedef struct Voiture{
    int  idVoiture ;
    char marque[15] ;
    char nomVoiture[15] ;
    char couleur[7] ;
    int  nbplaces ;
    int  prixJour ;
    char EnLocation[4] ;
}voiture;

typedef struct Client{
    int  idClient ;
    char nom[20] ;
    char prenom[20] ;
    int  cin ;
    char adresse[15] ;
    int  telephone ;
}client;

typedef struct contratLocation{
    float numContrat ;
    int   idVoiture ;
    int   idClient ;
    date  debut ;
    date  fin ;
    int   cout ;
}contrat;


// Les prototypes des menus /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Menu_Principale();
void Gestion_Voitures();
void Gestion_Clients();
void Location();


// Les fonctions du gestions des voitures /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Liste_des_voitures(){
    voiture v;
    int stat = 0 ;
    FILE *f = NULL;
    f = fopen("Voitures.txt","rb");
    if(!f)
        printf("Impossible d'ouvrir le fichier .");
    else{
        while(fread(&v,sizeof(v),1,f)){
            stat = 1 ;
            printf("| idVoiture : %d | marque : %s | nomVoiture : %s | couleur : %s | nbplaces : %d | prixJour : %d | EnLocation : %s | \n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
        }
        if(!stat)
            printf("Pas de voiture .");
        fclose(f);
    }
}


void Ajouter_voiture(){
    voiture v ;
    FILE *f = NULL;
    f = fopen("Voitures.txt","ab");
    if(!f)
        printf("Impossible d'ouvrire le fichier .");
    else{
        printf("idVoiture : ");
        scanf("%d",&v.idVoiture);
        printf("marque : ");
        scanf("%s",v.marque);
        printf("nomVoiture : ");
        scanf("%s",v.nomVoiture);
        printf("couleur : ");
        scanf("%s",v.couleur);
        printf("nbplaces : ");
        scanf("%d",&v.nbplaces);
        printf("prixJour : ");
        scanf("%d",&v.prixJour);
        printf("EnLocation : ");
        scanf("%s",v.EnLocation);
        fwrite(&v,sizeof(v),1,f);
        fclose(f);
        printf("---> La voiture a ete ajouter . ");
        sleep(2);
    }
}


void Modifier_voiture(){
    voiture v ;
    int id , choix;
    FILE *f = NULL;
    f = fopen("Voitures.txt","rb");
    if(!f)
        printf("Impossible d'ouvrire le fichier .");
    else{
        printf("Entrer l'id : ");
        scanf("%d",&id);
        FILE *f1 = NULL;
        f1 = fopen("f1.txt","ab");
        while(fread(&v,sizeof(v),1,f)){
            if(v.idVoiture == id){
                printf("1 | Pour modifier l'id du voiture  \n");
                printf("2 | Pour modifier la marque du voiture  \n");
                printf("3 | Pour modifier le nom du voiture  \n");
                printf("4 | Pour modifier la couleur du voiture  \n");
                printf("5 | Pour modifier le nombres de places du voiture  \n");
                printf("6 | Pour modifier le prix par jour du voiture  \n");
                printf("7 | Pour modifier l'enlocation du voiture  \n");
                printf("Votre choix : ");
                scanf("%d",&choix);
                do{
                    if(choix == 1){
                        printf("Entrez le nouveau id du voiture : ");
                        scanf("%d",&v.idVoiture);
                    }
                    if(choix == 2){
                        printf("Entrer la nouvelle marque du voiture : ");
                        scanf("%s",v.marque);
                    }
                    if(choix == 3){
                        printf("Entrer le nouveau nom du voiture : ");
                        scanf("%s",v.nomVoiture);
                    }
                    if(choix == 4){
                        printf("couleur : ");
                        scanf("%s",v.couleur);
                    }
                    if(choix == 5){
                        printf("Entrer le nouveau nombres de places du voiture : ");
                        scanf("%d",&v.nbplaces);
                    }
                    if(choix == 6){
                        printf("Entrer le nouveau prix du voiture : ");
                        scanf("%s",&v.prixJour);
                    }
                    if(choix == 7){
                        printf("Entrer la nouvelle enLocation du voiture: ");
                        scanf("%s",v.EnLocation);
                    }
                }while( choix < 1 && choix > 7 );
            }
            fwrite(&v,sizeof(v),1,f1);
        }
        fclose(f);
        fclose(f1);
        remove("Voitures.txt");
        rename("f1.txt","Voitures.txt");
        printf("--->La voiture a ete modifier . ");
    }
}


void Supprimer_voiture(){
    voiture v ;
    int stat = 0 ;
    int id ;
    FILE *f = NULL;
    f = fopen("Voitures.txt","rb");
    if(!f)
        printf("Impossible d'ouvrire le fichier .");
    else{
        printf("Entrer l'id : ");
        scanf("%d",&id);
        FILE *f1 = NULL;
        f1 = fopen("f1.txt","ab");
        while(fread(&v,sizeof(v),1,f) == 1){
            if(v.idVoiture == id)
                stat = 1 ;
            if(v.idVoiture != id)
                fwrite(&v,sizeof(v),1,f1);
        }
        if(!stat){
            printf("L'id du voiture n'existe pas");
            sleep(2);
        }
        else{
            fclose(f);
            fclose(f1);
            remove("Voitures.txt");
            rename("f1.txt","Voitures.txt");
            printf("--->La voiture a ete supprimee ");
            sleep(2);
        }
    }
}


// Les fonctions du gestions des clients  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void Liste_des_clients(){
    client v;
    int stat = 0 ;
    FILE *f = NULL;
    f = fopen("Clients.txt","rb");
    if(!f)
        printf("Impossible d'ouvrir le fichier .");
    else{
        while(fread(&v,sizeof(v),1,f)){
            stat = 1 ;
            printf("|idClient : %d | nom : %s | prenom : %s | cin : %d | adresse : %s | telephone : %d | \n",v.idClient,v.nom,v.prenom,v.cin,v.adresse,v.telephone);
        }
        if(!stat)
            printf("Pas de clients");
        fclose(f);
    }
}


void Ajouter_client(){
    client c ;
    FILE *f = NULL;
    f = fopen("Clients.txt","ab");
    if(!f)
        printf("Impossible d'ouvrire le fichier .");
    else{
        printf("idClient : ");
        scanf("%d",&c.idClient);
        printf("nom : ");
        scanf("%s",c.nom);
        printf("prenom : ");
        scanf("%s",c.prenom);
        printf("cin : ");
        scanf("%d",&c.cin);
        printf("adresse : ");
        scanf("%s",c.adresse);
        printf("telephone : ");
        scanf("%d",&c.telephone);
        fwrite(&c,sizeof(c),1,f);
        fclose(f);
        printf("--->Le client  a ete ajouter .");
        sleep(2);
    }
}


void Modifier_client(){
    client v ;
    int id , choix;
    FILE *f = NULL;
    f = fopen("Clients.txt","rb");
    if(!f)
        printf("Impossible d'ouvrire le fichier .");
    else{
        printf("Entrer l'id : ");
        scanf("%d",&id);
        FILE *f1 = NULL;
        f1 = fopen("f1.txt","ab");
        while(fread(&v,sizeof(v),1,f)){
            if(v.idClient == id){
                printf("1 | Pour modifier l'id du client  \n");
                printf("2 | Pour modifier le nom du client  \n");
                printf("3 | Pour modifier le prenom du client   \n");
                printf("4 | Pour modifier la cin du client  \n");
                printf("5 | Pour modifier l'adresse du client  \n");
                printf("6 | Pour modifier le telephone du client  \n");
                printf("Votre choix : ");
                scanf("%d",&choix);
                do{
                    if(choix == 1){
                        printf("Entrez le nouveau id du client : ");
                        scanf("%d",&v.idClient);
                    }
                    if(choix == 2){
                        printf("Entrez le nouveau nom du client : ");
                        scanf("%s",v.nom);
                    }
                    if(choix == 3){
                        printf("Entrez le nouveau prenom du client : ");
                        scanf("%s",v.prenom);
                    }
                    if(choix == 4){
                        printf("Entrez le nouveau cin du client : ");
                        scanf("%d",&v.cin);
                    }
                    if(choix == 5){
                        printf("Entrer la nouvelle adresse du client  : ");
                        scanf("%s",v.adresse);
                    }
                    if(choix == 6){
                        printf("Entrer le nouveau telephone du client : ");
                        scanf("%d",&v.telephone);
                    }
                }while( choix < 1 && choix > 6 );
            }
            fwrite(&v,sizeof(v),1,f1);
        }
        fclose(f);
        fclose(f1);
        remove("Clients.txt");
        rename("f1.txt","Clients.txt");
        printf("--->Le client a ete modifier .");
        sleep(2);
    }
}


void Supprimer_client(){
    client v ;
    int id  ;
    printf("Entrer l'id : ");
    scanf("%d",&id);
    FILE *f = NULL;
    f = fopen("Clients.txt","rb");
    if(!f)
        printf("Impossible d'ouvrire le fichier .");
    else{
        FILE *f1 = NULL;
        f1 = fopen("f1.txt","ab");
        while(fread(&v,sizeof(v),1,f)){
            if(v.idClient != id)
                fwrite(&v,sizeof(v),1,f1);

        }
        fclose(f);
        fclose(f1);
        remove("Clients.txt");
        rename("f1.txt","Clients.txt");
        printf("--->Le client a ete supprimer .");
        sleep(2);
    }
}


// Les fonctions de la location des voitures  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Visualiser_contrat(){
    FILE* fl = NULL;
    fl = fopen("contratsLocations.txt","rb");
    if(!fl)
        printf("Impossible d'ouvrire le fichier .");
    else{
        contrat v;
        float num , stat = 0;
        printf("Entrer le numero du contrat que vous voulez visualiser :");
        scanf("%f",&num);
        while(fread(&v,sizeof(v),1,fl)){
            if(v.numContrat == num){
                printf("|numContrat : %f | idVoiture : %d | idClient : %d | date de debut : %d/%d/%d | date de fin : %d/%d/%d | cout : %d | \n",v.numContrat,v.idVoiture,v.idClient,v.debut.Jour,v.debut.Mois,v.debut.Annee,v.fin.Jour,v.fin.Mois,v.fin.Annee,v.cout);
                stat = 1;
                break ;
            }
        }
        if(!stat)
            printf("Le contract que vous voulez visualiser n'existe pas .");
        fclose(fl);
    }
}


void Louer_voiture(){
    int stat = 0;
    /*verification du client*/
    FILE *fc = NULL;
    client  c1 , c2;
    printf("Entrer votre nom : ");
    scanf("%s",c1.nom);
    printf("Entrer votre prenom :");
    scanf("%s",c1.prenom);
    fc = fopen("Clients.txt","rb");
    if(!fc){
        printf("Impossible d'ouvrire le fichier .");
        sleep(2);
        Location();
    }
    while(fread(&c2,sizeof(c2),1,fc)){
            if( (strcmp(c1.nom,c2.nom) == 0 ) && ( strcmp(c1.prenom,c2.prenom) == 0)){
                stat = 1 ;
                break ;
            }
    }
    fclose(fc);
    if(!stat){
        printf("Entrer votres propres informations : \n");
        sleep(2);
        Gestion_Clients();
    }
    /*verification du voiture.*/
    stat = 0;
    FILE *fv = NULL;
    voiture v1 , v2;
    printf("Entrer la marque de le voiture : ");
    scanf("%s",v1.marque);
    printf("Entrer le nom de la voiture : ");
    scanf("%s",v1.nomVoiture);
    printf("Entrer la couleur de la voiture : ");
    scanf("%s",v1.couleur);
    printf("Entrer le nombre de place de la voiture : ");
    scanf("%d",&v1.nbplaces);
    fv = fopen("Voitures.txt","rb");
    if(!fv){
        printf("Impossible d'ouvrire le fichier .");
        sleep(2);
        Location();
    }
    while(fread(&v2,sizeof(v2),1,fv)){
            if(( strcmp(v1.marque,v2.marque)==0 ) && ( strcmp(v1.nomVoiture,v2.nomVoiture)==0 ) && ( strcmp(v1.couleur,v2.couleur)==0 ) && (v1.nbplaces == v2.nbplaces)){
                stat = 1;
                break ;
            }
    }
    if(!stat){
        printf("la voiture demandée n'existe pas. ");
        sleep(1);
        Location();
    }
    /*disponibilite du voiture */
    if(strcmp(v2.EnLocation,"oui") == 0){
        printf("La voiture n’est pas disponible .");
        sleep(1);
        Location();
    }
    FILE* fcopy = NULL;
    fcopy = fopen("fcopy.txt","ab");
    fseek(fv,0,SEEK_SET);
    while(fread(&v1,sizeof(v1),1,fv)){
        if(v1.idVoiture == v2.idVoiture)
            strcpy(v1.EnLocation,"oui");
        fwrite(&v1,sizeof(v1),1,fcopy);
    }
    fclose(fv);
    fclose(fcopy);
    remove("Voitures.txt");
    rename("fcopy.txt","Voitures.txt");
    printf("-->La voiture sera louer \n");
    /*Creer un nouveau contrat */
    contrat l;
    FILE *fl = NULL;
    fl = fopen("contratsLocations.txt","ab");
    if(!fl){
        printf("Impossible d'ouvrire le fichier .");
        sleep(2);
        Location();
    }
    printf("numContrat : ");
    scanf("%f",&l.numContrat);
    l.idVoiture = v2.idVoiture;
    l.idClient  = c2.idClient ;
    printf("date de debut (jj/mm/yyyy) : ");
    scanf("%d",&l.debut.Jour);
    fflush(stdin);
    scanf("%d",&l.debut.Mois);
    fflush(stdin);
    scanf("%d",&l.debut.Annee);
    printf("date de fin (jj/mm/yyyy) : ");
    scanf("%d",&l.fin.Jour);
    fflush(stdin);
    scanf("%d",&l.fin.Mois);
    fflush(stdin);
    scanf("%d",&l.fin.Annee);
    int d = (l.debut.Annee*365)+(l.debut.Mois*30)+(l.debut.Jour) ;
    int f = (l.fin.Annee*365)+(l.fin.Mois*30)+(l.fin.Jour) ;
    l.cout = v2.prixJour*(f-d);
    fwrite(&l,sizeof(l),1,fl);
    fclose(fl);
    printf("--->Le contrat a ete creer");
    sleep(2);
    Location();
}


void Retourner_voiture(){
    int id , idv , stat=0 ;
    voiture v;
    contrat l;
    FILE *fv = NULL;
    fv = fopen("Voitures.txt","rb");
    if(!fv){
        printf("Impossible d'ouvrir le fichier .");
        sleep(2);
        Retourner_voiture();
    }
    FILE *fcopy = NULL;
    fcopy = fopen("fcopy.txt","ab");
    printf("Saisir l'id du voiture que vous voulez retourner :");
    scanf("%d",&id);
    /*changer le champs enlocation par non */
    while(fread(&v,sizeof(v),1,fv)){
        if(v.idVoiture == id){
            stat = 1;
            strcpy(v.EnLocation,"non");
        }
        fwrite(&v,sizeof(v),1,fcopy);
    }
    fclose(fv);
    fclose(fcopy);
    remove("Voitures.txt");
    rename("fcopy.txt","Voitures.txt");
    if(!stat){
        printf("La voiture n'exite pas .");
        sleep(2);
        Location();
    }
    /* Supprimer contrat */
    stat = 0;
    FILE *fl = NULL;
    fl = fopen("contratsLocations.txt","rb");
    if(!fl)
        printf("Impossible d'ouvrir le fichier .");
    else{
        FILE *fcopy;
        fcopy = fopen("fcopy.txt","ab");
        while(fread(&l,sizeof(l),1,fl)){
            if(l.idVoiture == id)
                stat = 1;
            else
                fwrite(&l,sizeof(l),1,fcopy);
        }
        if(!stat){
            printf("la voiture que vous voulez retournez n'est pas encore louer .");
            sleep(2);
            Location();
        }
        fclose(fl);
        fclose(fcopy);
        remove("contratsLocations.txt");
        rename("fcopy.txt","contratsLocations.txt");
        printf("-->La voiture a ete retournee .");
        sleep(2);
        Location();
    }
}


void Modifier_contrat(){
    contrat l ;
    voiture v ;
    float n = 0 ;
    int choix , stat = 0 , d , f , prix ;
    FILE *fl = NULL;
    fl = fopen("contratsLocations.txt","rb");
    if(!fl)
        printf("Impossible d'ouvrir le fichier .");
    else{
        printf("Entrer le numero du contrat :");
        scanf("%f",&n);
        FILE *fcopy = NULL;
        fcopy = fopen("fcopy.txt","ab");
        FILE *fv = NULL;
        fv = fopen("Voitures.txt","rb");
        if(!fv)
            printf("Impossible d'ouvrir le fichier .");
        else{
            while(fread(&l,sizeof(l),1,fl)){
                if(l.numContrat == n){
                    stat = 1;
                    /* modifier les dates */
                    printf("|1 pour modifier la date de debut . \n");
                    printf("|2 pour modifier la date de fin . \n");
                    printf("Votre choix : ");
                    scanf("%d",&choix);
                    do{
                        if(choix == 1){
                            printf("Entrer la nouvelle date de debut (jj/mm/yyyy) :");
                            scanf("%d",&l.debut.Jour);
                            fflush(stdin);
                            scanf("%d",&l.debut.Mois);
                            fflush(stdin);
                            scanf("%d",&l.debut.Annee);
                            d = (l.debut.Annee*365)+(l.debut.Mois*30)+(l.debut.Jour) ;
                            f = (l.fin.Annee*365)+(l.fin.Mois*30)+(l.fin.Jour) ;
                        }
                        else if(choix == 2){
                            printf("Entrer la nouvelle date de fin (jj/mm/yyyy) :");
                            scanf("%d",&l.fin.Jour);
                            fflush(stdin);
                            scanf("%d",&l.fin.Mois);
                            fflush(stdin);
                            scanf("%d",&l.fin.Annee);
                            d = (l.debut.Annee*365)+(l.debut.Mois*30)+(l.debut.Jour) ;
                            f = (l.fin.Annee*365)+(l.fin.Mois*30)+(l.fin.Jour) ;
                        }
                        if(f<=d)
                            printf("--->Il faut que la date de debut soit inferieur a celle de fin .\n");
                    }while( ((choix != 1) && (choix != 2)) || (f<=d));
                    /* modifier le cout */
                    while(fread(&v,sizeof(v),1,fv))
                        if(v.idVoiture == l.idVoiture)
                            l.cout = v.prixJour*(f-d);
                }
                fwrite(&l,sizeof(l),1,fcopy);
            }
            if(!stat){
                printf("Le numero du contrat n'existe pas .");
                sleep(2);
            }
            fclose(fv);
            fclose(fl);
            fclose(fcopy);
            remove("contratsLocations.txt");
            rename("fcopy.txt","contratsLocations.txt");
            printf("-->La voiture a ete modifier .");
            sleep(2);
        }
    }
}


void Supprimer_contrat(){
    int stat = 0 , idv = 0 , s = 0;
    float num ;
    contrat l ;
    voiture v ;
    FILE *fl = NULL;
    fl = fopen("contratsLocations.txt","rb");
    if(!fl)
        printf("Impossible d'ouvrir le fichier .");
    else{
        printf("Entrer le numero du contrat : ");
        scanf("%f",&num);
        /*recuperer l'id du voiture*/
        while(fread(&l,sizeof(l),1,fl)){
            if(l.numContrat == num){
                stat = 1 ;
                idv = l.idVoiture;
            }
        }
        if(!stat){
            printf("Le numero du contrat n'exite pas .");
            sleep(2);
            Location();
        }
        /*mettre non dans le champs EnLocation*/
        FILE *fv = NULL;
        fv = fopen("Voitures.txt","rb");
        if(!fv)
            printf("Impossible d'ouvrir le fichier .");
        FILE *fcopy = NULL;
        fcopy = fopen("fcopy.txt","ab");
        if(!fcopy)
            printf("Impossible d'ouvrir le fichier .");
        while(fread(&v,sizeof(v),1,fv)){
            if(v.idVoiture == idv){
                strcpy(v.EnLocation,"non");
            }
            fwrite(&v,sizeof(v),1,fcopy);
        }
        fclose(fv);
        fclose(fcopy);
        remove("Voitures.txt");
        rename("fcopy.txt","Voitures.txt");
        /*Supprimer contrat */
        FILE *fcopy1 = NULL;
        fcopy1 = fopen("fcopy1.txt","ab");
        while(fread(&l,sizeof(l),1,fl))
            if(l.numContrat == num)
                s = 0;
            else
                fwrite(&l,sizeof(l),1,fcopy1);
        fclose(fl);
        fclose(fcopy1);
        remove("contratsLocations.txt");
        rename("fcopy1.txt","contratsLocations.txt");
        printf("-->Le contrat a ete supprimee");
        sleep(2);
        Location();
    }
}


// Les menus //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Menu_Principale(){
    system("cls");
    int n=0;
    printf("\t\t\t\t\t       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    printf("\t\t\t\t\t       %c Menu Principal %c\n",179,179);
    printf("\t\t\t\t\t       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t\t\t%c\t\t\t\t\t\t\t     %c\n",186,186);
    printf("\t\t\t%c   Location.............................................1   %c\n",186,186);
    printf("\t\t\t%c   Gestion voitures.....................................2   %c\n",186,186);
    printf("\t\t\t%c   Gestion clients......................................3   %c\n",186,186);
    printf("\t\t\t%c   Quitter..............................................4   %c\n",186,186);
    printf("\t\t\t%c\t\t\t\t\t\t\t     %c\n",186,186);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printf("\n\n\t\t\t\t\t\t Votre choix  :  ");
    scanf("%d",&n);
    switch(n){
        case 1 :
                Location();
                break;
        case 2 :
                Gestion_Voitures();
                break ;
        case 3 :
                Gestion_Clients();
                break ;
        case 4 :
                exit (0);
                break ;
        default:
                Menu_Principale();
                break ;
    }
}


void Gestion_Voitures(){
    system("cls");
    int n=0;
    printf("\t\t\t\t\t     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    printf("\t\t\t\t\t     %c Gestion des Voitures %c\n",179,179);
    printf("\t\t\t\t\t     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t\t\t%c\t\t\t\t\t\t\t     %c\n",186,186);
    printf("\t\t\t%c   Liste des voitures...................................1   %c\n",186,186);
    printf("\t\t\t%c   Ajouter voiture......................................2   %c\n",186,186);
    printf("\t\t\t%c   Modifier voiture.....................................3   %c\n",186,186);
    printf("\t\t\t%c   Supprimer voiture....................................4   %c\n",186,186);
    printf("\t\t\t%c   Retour...............................................5   %c\n",186,186);
    printf("\t\t\t%c\t\t\t\t\t\t\t     %c\n",186,186);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printf("\n\n\t\t\t\t\t\t Votre choix  :  ");
    scanf("%d",&n);
    switch(n){
        case 1 :
                Liste_des_voitures();
                sleep(3);
                Gestion_Voitures();
                break ;
        case 2 :
                Ajouter_voiture();
                Gestion_Voitures();
                break ;
        case 3 :
                Modifier_voiture();
                Gestion_Voitures();
                break ;
        case 4 :
                Supprimer_voiture();
                Gestion_Voitures();
                break ;
        case 5 :
                Menu_Principale();
                break;
        default:
                Gestion_Voitures();
                break ;
    }
}


void Gestion_Clients(){
    system("cls");
    int n=0;
    printf("\t\t\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    printf("\t\t\t\t\t   %c Gestion des Clients %c\n",179,179);
    printf("\t\t\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t\t\t%c\t\t\t\t\t\t\t     %c\n",186,186);
    printf("\t\t\t%c   Liste des clients....................................1   %c\n",186,186);
    printf("\t\t\t%c   Ajouter client.......................................2   %c\n",186,186);
    printf("\t\t\t%c   Modifier client......................................3   %c\n",186,186);
    printf("\t\t\t%c   Supprimer client.....................................4   %c\n",186,186);
    printf("\t\t\t%c   Retour...............................................5   %c\n",186,186);
    printf("\t\t\t%c\t\t\t\t\t\t\t     %c\n",186,186);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printf("\n\n\t\t\t\t\t\t Votre choix  :  ");
    scanf("%d",&n);
    switch(n){
        case 1 :
            Liste_des_clients();
            sleep(3);
            Gestion_Clients();
            break ;
        case 2 :
            Ajouter_client();
            Gestion_Clients();
            break ;
        case 3 :
            Modifier_client();
            Gestion_Clients();
            break ;
        case 4 :
            Supprimer_client();
            Gestion_Clients();
            break ;
        case 5 :
            Menu_Principale();
            break ;
        default:
            Gestion_Clients();
            break ;
    }
}


void Location(){
    system("cls");
    int n=0;
    printf("\t\t\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    printf("\t\t\t\t\t   %c Location d'une Voiture %c\n",179,179);
    printf("\t\t\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t\t\t%c\t\t\t\t\t\t\t     %c\n",186,186);
    printf("\t\t\t%c   Visualiser contrat...................................1   %c\n",186,186);
    printf("\t\t\t%c   Louer voiture........................................2   %c\n",186,186);
    printf("\t\t\t%c   Retourner voiture....................................3   %c\n",186,186);
    printf("\t\t\t%c   Modifier contrat.....................................4   %c\n",186,186);
    printf("\t\t\t%c   Supprimer contrat....................................5   %c\n",186,186);
    printf("\t\t\t%c   Retour...............................................6   %c\n",186,186);
    printf("\t\t\t%c\t\t\t\t\t\t\t     %c\n",186,186);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printf("\n\n\t\t\t\t\t\t Votre choix  :  ");
    scanf("%d",&n);
    switch(n){
        case 1 :
            Visualiser_contrat();
            sleep(3);
            Location();
            break ;
        case 2 :
            Louer_voiture();
            break ;
        case 3 :
            Retourner_voiture();
            break ;
        case 4 :
            Modifier_contrat();
            Location();
            break ;
        case 5 :
            Supprimer_contrat();
            break ;
        case 6 :
            Menu_Principale();
            break ;
        default:
            Location();
            break ;
    }
}


// Le programme principale //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(){
    Menu_Principale();
    system("PAUSE");
}
