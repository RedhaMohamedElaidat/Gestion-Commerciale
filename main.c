#include <stdio.h>
#include <stdlib.h>
#include "LibPileFileInt.c" //BUB CLIENT
#include "LibPileF.c"  // BUB ARTI
#include "LibPile.c"  // BUB ACHAT

int N=0,N2=0,N3=0;
Pile P;
Pile2 P2;
Pile3 P3;

void affclient (client x) {
    printf(" \t etat \t nomber   \t nom    \t prenom  \t NOMTEL    \t adress \n");
    printf(" \t %d \t %d \t %s \t %s \t %d \t %s \n___________________________________________",x.etat,x.Number,x.nom,x.prenom,x.Ntel,x.adress);

}

void CreerPile(Pile *P)   //le paramètre P est en E/S (donc déclaré avec  avec *)
{
    client x;
    printf(" etat : ");
    scanf("%d",&x.etat);
    printf(" nom : ");
    scanf("%s",&x.nom);
    printf(" telephon : ");
    scanf("%d",&x.Ntel);
    printf(" adress : ");
    scanf("%s",&x.adress);
    printf(" number : ");
    scanf("%d",&x.Number);
    printf(" prenom : ");
    scanf("%s",&x.prenom);
    Empiler(&(*P),x);
    printf("done !..");
    N++;

}

void AffichePile(Pile *P ,int s)  //le paramètre P est en E/S
{
    Pile T;  //pile intermédiaire pour reconstruire P
    client x;
    int n;
    n=N;
    if (Pilevide(*P)) printf("\nPile Vide...\n");   //le paramètre de Pilevide est E/, donc on ne met pas & à l'appel
    else
    {
        printf(" \t etat \t nomber   \t nom    \t prenom  \t NOMTEL    \t adress \n");
        Initpile(&T);
        while (n > 0)
        {
            Depiler(&(*P),&x);
            Empiler(&T,x);
            if (x.etat == s){
            printf(" \t %d \t %d \t %s \t %s \t %d \t %s \n___________________________________________\n",x.etat,x.Number,x.nom,x.prenom,x.Ntel,x.adress);
            }
            n--;
        }

        while (!Pilevide(T))
        {
            Depiler(&T,&x);
            Empiler(&(*P),x);
        }
    }
}

void RECH_client(){
    client x,y;
    Pile T;
    int r,n,E=0;
    n=N;
    Initpile(&T);
    printf("entre info \n etat : ");
    scanf("%d",&x.etat);
    printf(" number : ");
    scanf("%d",&x.Number);
    while( n>0 && E == 0 ){
            printf("hi");
            Depiler(&P,&y);
            Empiler(&T,y);
            n--;
        if(x.Number == y.Number && x.etat == 0 ){
                E=1;
                printf("le clinet est existe \n ");
                printf("what do u wanna do \n 1- afficher info de %s \n 2- remove %s  \n 3- modefier %s \n  : \n ",y.nom);
                scanf("%d",&r);
                if( r == 1 ){ affclient(y); }
                if( r == 2 ){Depiler(&T,&y);printf("removed \n"); }
                if( r == 3 ){
                    printf(" etat : ");
                    scanf("%d",&x.etat);
                    printf(" nom : ");
                    scanf("%s",&x.nom);
                    printf(" telephon : ");
                    scanf("%d",&x.Ntel);
                    printf(" adress : ");
                    scanf("%s",&x.adress);
                    printf(" number : ");
                    scanf("%d",&x.Number);
                    printf(" prenom : ");
                    scanf("%s",&x.prenom);
                    Depiler(&T,&y);
                    Empiler(&T,x);
                    printf("modified \n");
                }
        }
        if(x.Number == y.Number && x.etat == 1 ){
                E=1;
                printf("le fornisser est existe \n");
                printf("what do u wanna do \n 1- afficher info de %s \n 2- remove %s  \n 3- modefier %s \n  : \n ",y.nom);
                scanf("%d",&r);
                if( r == 1 ){ affclient(y); }
                if( r == 2 ){Depiler(&T,&y);printf("removed \n"); }
                if( r == 3 ){
                    printf(" etat : ");
                    scanf("%d",&x.etat);
                    printf(" nom : ");
                    scanf("%s",&x.nom);
                    printf(" telephon : ");
                    scanf("%d",&x.Ntel);
                    printf(" adress : ");
                    scanf("%s",&x.adress);
                    printf(" number : ");
                    scanf("%d",&x.Number);
                    printf(" prenom : ");
                    scanf("%s",&x.prenom);
                    Depiler(&T,&y);
                    Empiler(&T,x);
                    printf("modified \n");
                }
    }
        if(x.Number == y.Number && x.etat == 2 ){
                E=1;
                printf("le driver est existe \n");
                printf("what do u wanna do \n 1- afficher info de %s \n 2- remove %s  \n 3- modefier %s \n  : \n ",y.nom);
                scanf("%d",&r);
                if( r == 1 ){ affclient(y); }
                if( r == 2 ){Depiler(&T,&y);printf("removed \n"); }
                if( r == 3 ){
                    printf(" etat : ");
                    scanf("%d",&x.etat);
                    printf(" nom : ");
                    scanf("%s",&x.nom);
                    printf(" telephon : ");
                    scanf("%d",&x.Ntel);
                    printf(" adress : ");
                    scanf("%s",&x.adress);
                    printf(" number : ");
                    scanf("%d",&x.Number);
                    printf(" prenom : ");
                    scanf("%s",&x.prenom);
                    Depiler(&T,&y);
                    Empiler(&T,x);
                    printf("modified \n");

                }
    }
}
        while (!Pilevide(T))
        {
            Depiler(&T,&x);
            Empiler(&P,x);
        }
}


//

//procedure de creation
void affarti (article x){
    printf(" \t CODE \t DES   \t QUEN    \t PRIX  \t EXdate \t PRdate \n");
    printf(" \t %d \t %s \t %d \t %.3f \t %d/%d/%d \t %d/%d/%d \n ___________________________________________\n",x.code,x.des,x.quen,x.prix,x.exdate.jj,x.exdate.mm,x.exdate.yy,x.prdate.jj,x.prdate.mm,x.prdate.yy);

}

void CreerPile2(Pile2 *P)   //le paramètre P est en E/S (donc déclaré avec  avec *)
{
    article x;
        printf(" code : ");
        scanf("%d",&x.code);
        printf(" des : ");
        scanf("%s",&x.des);
        printf(" quen : ");
        scanf("%f",&x.quen);
        printf(" prix : ");
        scanf("%f",&x.prix);
        printf(" date ex jj : ");
        scanf("%d",&x.exdate.jj);
        printf("      mm : ");
        scanf("%d",&x.exdate.mm);
        printf("      aa : ");
        scanf("%d",&x.exdate.yy);
        printf(" date pre jj : ");
        scanf("%d",&x.prdate.jj);
        printf("      mm : ");
        scanf("%d",&x.prdate.mm);
        printf("      aa : ");
        scanf("%d",&x.prdate.yy);
        Empiler2(&(*P),x);
        N2++;

}

//procedure AffichePile
void AffichePile2(Pile2 *P)  //le paramètre P est en E/S
{
    Pile2 T;  //pile intermédiaire pour reconstruire P
    article x;
    if (Pilevide2(*P)) printf("\nPile Vide...\n");   //le paramètre de Pilevide est E/, donc on ne met pas & à l'appel
    else
    {
    printf(" \t CODE \t DES   \t QUEN    \t PRIX  \t EXdate \t PRdate \n");
        Initpile2(&T);   //ici T est une variable locale, donc l'appel se fait fait avec &T et non pas &(*T)
        while (!Pilevide2(*P))
        {
            Depiler2(&(*P),&x);
            Empiler2(&T,x);
    printf(" \t %d \t %s \t %.2f \t %.3f \t      %d/%d/%d    \t     %d/%d/%d    \n ___________________________________________\n",x.code,x.des,x.quen,x.prix,x.exdate.jj,x.exdate.mm,x.exdate.yy,x.prdate.jj,x.prdate.mm,x.prdate.yy);

        }
        //reconstruire P à partir de T
        while (!Pilevide2(T))
        {
            Depiler2(&T,&x);
            Empiler2(&(*P),x);
        }
    }
}

float sommm(Pile2 *P )  //le paramètre P est en E/S
{
    Pile2 T;
    float I=0;  //pile intermédiaire pour reconstruire P
    article x;
    if (Pilevide2(*P)) printf("\nPile Vide...\n");   //le paramètre de Pilevide est E/, donc on ne met pas & à l'appel
    else
    {
        Initpile2(&T);   //ici T est une variable locale, donc l'appel se fait fait avec &T et non pas &(*T)
        while (!Pilevide2(*P))
        {
            Depiler2(&(*P),&x);
            Empiler2(&T,x);
            I = I +(x.prix * x.quen);
        }
        //reconstruire P à partir de T
        while (!Pilevide2(T))
        {
            Depiler2(&T,&x);
            Empiler2(&(*P),x);
        }
    }
    return I;

}

void RECH_ARTI(){
    article x,y;
    Pile2 T;
    int r,n,E=0;
    Initpile2(&T);
    printf("recherch par 1 - COD \t 2 - DES \n");
    scanf("%d",&r);
    n=N2;
    if( r == 1 ){
        printf("entre info \n CODE : ");
        scanf("%d",&x.code);
    }
    if( r == 2 ){
        printf("entre info \n DES : ");
        scanf("%s",&x.des);
    }

    while( n>0 && E == 0 ){
            printf("hi");
            Depiler2(&P2,&y);
            Empiler2(&T,y);
            n--;
        if(x.code == y.code ){
                E=1;
                printf("le ARTI est existe \n ");
                printf("what do u wanna do \n 1- afficher info de %s \n 2- remove %s  \n 3- modefier %s \n  : \n ",y.des);
                scanf("%d",&r);
                if( r == 1 ){ affarti(y); }
                if( r == 2 ){Depiler2(&T,&y);printf("removed \n"); }
                if( r == 3 ){
                    Depiler2(&T,&y);
                    printf(" quen : ");
                    scanf("%d",&y.quen);
                    printf(" prix : ");
                    scanf("%f",&y.prix);
                    Empiler2(&T,y);
                    printf("modified \n");
                }
        }

     }

    while (!Pilevide2(T))
        {
            Depiler2(&T,&x);
            Empiler2(&P2,x);
        }

}

//

void affchat (achat x){

            printf("\t type : %d \t",x.type);
            if(x.type==0){printf("\t Ncomm : %d \n",x.Ncomm_foct);}
            else if(x.type==1){ printf("\t Nfact : %d \n",x.Ncomm_foct);}
            printf("\t\t Narti : %d \n",x.Narti);
            AffichePile2(&x.arti);
            printf("\t\t monHT %.2f \t\n \t\t monTTC %.3f \t\n ",x.monHT,x.monTTC);
            printf( "  date %d / %d / %d \n\n " ,x.temp.jj,x.temp.mm ,x.temp.yy);

}


void CreerPile3(Pile3 *P)   //le paramètre P est en E/S (donc déclaré avec  avec *)
{
    int i;
    achat x;
    do{
    printf(" type : ");
    scanf("%d",&x.type);
    }while (x.type!=0 && x.type!=1);

    if (x.type==0){
    printf(" Ncomm : ");
    scanf("%d",&x.Ncomm_foct);
    }
    else if ( x.type==1){
    printf(" Nfact : ");
    scanf("%d",&x.Ncomm_foct);
    }
    printf(" Narti : ");
    scanf("%d",&x.Narti);
    Initpile2(&x.arti);
    for (i=1;i<=x.Narti;i++){CreerPile2(&x.arti);}
    printf(" date jj : ");
    scanf("%d",&x.temp.jj);
    printf("      mm : ");
    scanf("%d",&x.temp.mm);
    printf("      aa : ");
    scanf("%d",&x.temp.yy);
    x.monHT=sommm(&x.arti);
    x.monTTC= x.monHT * 0.19 + x.monHT;
    Empiler3(&(*P),x);

}
   // copy les article fron achat to stockage
void copy (Pile3 *P) {
    achat x;
    article i;
    Pile2 Z;
    Pile3 T;
    while(!Pilevide3(*P)){
            Depiler3(&(*P),&x);
            Empiler3(&T,x);
            while (!Pilevide2(x.arti))
        {
            Depiler2(&x.arti,&i);
            Empiler2(&P2,i);
            Empiler2(&Z,i);
        }
            while (!Pilevide2(x.arti))
        {
            Depiler2(&Z,&i);
            Empiler2(&x.arti,i);
        }

     }


        while (!Pilevide3(T))
        {
            Depiler3(&T,&x);
            Empiler3(&(*P),x);
        }
}

//procedure AffichePile
void AffichePile3(Pile3 *P,int s)  //le paramètre P est en E/S
{
    Pile3 T;  //pile intermédiaire pour reconstruire P
    achat x;
    if (Pilevide3(*P)) printf("\nPile Vide...\n");   //le paramètre de Pilevide est E/, donc on ne met pas & à l'appel
    else
    {
        //depiler P dans T pour afficher
        Initpile3(&T);   //ici T est une variable locale, donc l'appel se fait fait avec &T et non pas &(*T)
        while (!Pilevide3(*P))
        {
            Depiler3(&(*P),&x);
            Empiler3(&T,x);
            if(x.type == s){affchat(x);}

        }
        //reconstruire P à partir de T
        while (!Pilevide3(T))
        {
            Depiler3(&T,&x);
            Empiler3(&(*P),x);
        }
    }
}


void RECH_achat(){
    achat x,y;
    Pile3 T;
    int r,n,E=0;
    Initpile3(&T);
    n=N3;


    while( n>0 && E == 0 ){
            Depiler3(&P3,&y);
            Empiler3(&T,y);
            n--;
            printf("entre le NUMBER \t :");
            scanf("%d",&x.Ncomm_foct);
        if(x.Ncomm_foct == y.Ncomm_foct ){
                E=1;
                printf("existe___ \n ");
                printf("what do u wanna do \n 1- afficher info de %s \n 2- remove %s  \n 3- modefier %s \n  : \n ",y.Ncomm_foct);
                scanf("%d",&r);
                if( r == 1 ){ affchat(y); }
                if( r == 2 ){Depiler3(&T,&y);printf("removed \n"); }
                if( r == 3 ){
                    Depiler3(&T,&y);
                    printf(" NUMBER : ");
                    scanf("%d",&y.Ncomm_foct);
                    Empiler3(&T,y);
                    printf("modified \n");
                }
        }

     }

    while (!Pilevide3(T))
        {
            Depiler3(&T,&x);
            Empiler3(&P3,x);
        }

}


void netfi () {
    Pile2 T;  //pile intermédiaire pour reconstruire P
    article x;
    if (Pilevide2(P2)) printf("");   //le paramètre de Pilevide est E/, donc on ne met pas & à l'appel
    else
    {
       Initpile2(&T);
        while (!Pilevide2(P2))
        {
            Depiler2(&P2,&x);
            Empiler2(&T,x);
            if(x.quen<10.0){
                    printf(" <<<<<<<<<<the %s less than 10 there QUEN is %.1f >>>>>>>>>>\n \n ",x.des,x.quen);
            }
        }
        //reconstruire P à partir de T
        while (!Pilevide2(T))
        {
            Depiler2(&T,&x);
            Empiler2(&P2,x);
        }
    }
}


void winn () {
    Pile3 T;  //pile intermédiaire pour reconstruire P
    achat x;
    float som1,som2;
    if (Pilevide3(P)) printf("\nPile Vide...\n");   //le paramètre de Pilevide est E/, donc on ne met pas & à l'appel
    else
    {
        //depiler P dans T pour afficher
        Initpile3(&T);   //ici T est une variable locale, donc l'appel se fait fait avec &T et non pas &(*T)
        while (!Pilevide3(P))
        {
            Depiler3(&(*P),&x);
            Empiler3(&T,x);
            if(x.type == 0){som1=som1 + x.monHT;}
            if(x.type == 1) {som2 = som2 + x.monHT;}

        }
        //reconstruire P à partir de T
        while (!Pilevide3(T))
        {
            Depiler3(&T,&x);
            Empiler3(&(P),x);
        }
        if(som1 > som2){printf (" u r losing ur money ur %.3f ",som1-som2); }
        if(som1 < som2){printf ("u r win the money ur %.3f ", som2 - som1); }

    }
}

void MENU (){
    int chois;
    printf("\t=================HOME=================\n\t|| 1-  ADD                           ||\n\t|| 2-  ALL_OPERATION                          ||\n\t|| 3-  AFF                           ||\n\t|| 3-  UR BUDGET                           ||\n\t|| 0-  FIIN                          ||\n\t=====================================\n ");

    do{
            printf("your choice : ");
            scanf("%d",&chois);
            if(chois == 1){
                    printf("\t=================ADD==================\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  articl                        ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");
                    do{
                        printf("your choice : ");
                       scanf("%d",&chois);
                       if(chois == 1){printf ("\t=================ADD CLIENT==================\n");CreerPile(&P);printf ("\t dome !! \n") ;printf("\t=================ADD==================\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       else if (chois == 2){printf ("\t=================ADD ACHAT==================\n");CreerPile3(&P3) ;printf("\t=================ADD==================\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  articl                        ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       else if (chois == 3){printf ("\t=================ADD FORN==================\n");CreerPile (&P) ;printf("\t=================ADD==================\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  articl                        ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       else if (chois == 4){printf ("\t=================ADD VONT==================\n");CreerPile3(&P3) ;printf("\t=================ADD==================\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  articl                        ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       else if (chois == 5){printf ("\t=================ADD ARTI==================\n");CreerPile2(&P2) ;printf("\t=================ADD==================\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  articl                        ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       else if (chois == 6){printf("<< back \n\t=================HOME=================\n\t|| 1-  ADD                           ||\n\t|| 2-  ALL_OPERATION                          ||\n\t|| 3-  AFF                           ||\n\t|| 3-  UR BUDGET                           ||\n\t|| 0-  FIIN                          ||\n\t=====================================\n ");}

                    }while(chois != 6);
                    netfi ();


            }
            else if(chois == 2){
                printf("\t=================ALL OPIRATION================\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  ARTI                         ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");

                    do{
                       printf("your choice : ");
                       scanf("%d",&chois);
                       if(chois == 1){RECH_client();printf("\t=================ALL OPIRATION================\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  ARTI                         ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       else if (chois == 2){RECH_achat();printf("\t=================ALL OPIRATION================\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  ARTI                         ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       else if (chois == 3){RECH_client();printf("\t=================ALL OPIRATION================\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  ARTI                         ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       else if (chois == 4){RECH_achat();printf("\t=================ALL OPIRATION================\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  ARTI                         ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       else if (chois == 5){RECH_ARTI();printf("\t=================ALL OPIRATION================\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  ARTI                         ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       else if (chois == 6){printf("<< back \n\t=================HOME=================\n\t|| 1-  ADD                           ||\n\t|| 2-  ALL_OPERATION                          ||\n\t|| 3-  AFF                           ||\n\t|| 3-  UR BUDGET                           ||\n\t|| 0-  FIIN                          ||\n\t=====================================\n ");}

                    }while(chois != 6);
                    netfi ();
            }
            else if(chois == 3){
                    printf("\t=================AFF_TOUS=============\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  articl                        ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");

                    do{
                       printf("your choice : ");
                       scanf("%d",&chois);
                       if(chois == 1){printf ("\t=================AFF CLIENT==================\n");AffichePile(&P,0);printf("\t=================AFF_TOUS=============\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  articl                        ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       else if (chois == 2){printf ("\t=================AFF ACHAT==================\n");{AffichePile3(&P3,0);printf("\t=================AFF_TOUS=============\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  articl                        ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       }else if (chois == 3){printf ("\t=================AFF FORN==================\n");{AffichePile(&P,1);printf("\t=================AFF_TOUS=============\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  articl                        ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       }else if (chois == 4){printf ("\t=================AFF VONT==================\n");AffichePile3(&P3,1);printf("\t=================AFF_TOUS=============\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  articl                        ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       else if (chois == 5){printf ("\t=================AFF ARTICL==================\n");AffichePile2(&P2);;printf("\t=================AFF_TOUS=============\n\t|| 1-  CLIENT                        ||\n\t|| 2-  ACHAT                         ||\n\t|| 3-  FORN                          ||\n\t|| 4-  VONT                          ||\n\t|| 5-  articl                        ||\n\t|| 6-  BACK                          ||\n\t=====================================\n ");}
                       else if (chois == 6){printf("<< back \n\t=================HOME=================\n\t|| 1-  ADD                           ||\n\t|| 2-  ALL_OPERATION                          ||\n\t|| 3-  AFF                           ||\n\t|| 3-  UR BUDGET                           ||\n\t|| 0-  FIIN                          ||\n\t=====================================\n ");}

                    }while(chois != 6);
                    netfi ();
            }
            else if(chois == 4){
                    printf("\t=================UR BUDGET===================\n");
                    winn();
                    do{
                       printf("press 6 to back home  : ");
                       scanf("%d",&chois);
                    if (chois == 6){printf("<< back \n\t=================HOME=================\n\t|| 1-  ADD                           ||\n\t|| 2-  ALL_OPERATION                          ||\n\t|| 3-  AFF                           ||\n\t|| 3-  UR BUDGET                           ||\n\t|| 0-  FIIN                          ||\n\t=====================================\n ");}

                    }while(chois != 6);
            }
            else if(chois == 0){ printf("HAVE A NICE DAY  \n "); }
            else{ printf("u r choise dosen't existe \n ");    printf("\t=================HOME=================\n\t|| 1-  ADD                           ||\n\t|| 2-  ALL_OPERATION                          ||\n\t|| 3-  AFF                           ||\n\t|| 3-  UR BUDGET                           ||\n\t|| 0-  FIIN                          ||\n\t=====================================\n ");
 }
    }while(chois != 0);

}


main(){
    Initpile(&P);
    Initpile2(&P2);
    Initpile3(&P3);

   MENU ();
    //        CreerPile3(&P3);
     //       AffichePile3(&P3);

}










