//d�claration de la Pile
typedef struct client{int Number;int Ntel;int etat;char nom[20],prenom[20],adress[30]}client;
typedef client Telm;
typedef struct EPile* Pile;
typedef struct EPile { Telm  Val; Pile Suiv;} CelluleP;

void Initpile(Pile *P)
{*P=NULL;}

void Empiler(Pile *P, Telm x)
{Pile V;
 V=malloc(sizeof(CelluleP));
 V->Val=x;
 V->Suiv=*P;
 *P=V;
}


void Depiler(Pile *P, Telm *x)
{Pile V;
 *x=(*P)->Val;
 V=*P;
 *P=(*P)->Suiv;
 free(V);
}


int Pilevide(Pile P)
{if (P==NULL) return 1;
 else return 0;
}

Telm SommetPile(Pile P)
{return P->Val;}
