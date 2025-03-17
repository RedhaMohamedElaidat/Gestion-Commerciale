//d�claration de la Pile
typedef struct date2{int jj,mm,yy;}date2;
typedef struct article{int code;float quen;char des[20];float prix;date2 exdate;date2 prdate;}article;
typedef article Telm2;
typedef struct EPile2* Pile2;
typedef struct EPile2 { Telm2  Val; Pile2 Suiv;} CelluleP2;

//primitives des Piles
//procedure Initpile
void Initpile2(Pile2 *P)
{*P=NULL;}

//procedure Empiler
void Empiler2(Pile2 *P, Telm2 x)
{Pile2 V;
 V=malloc(sizeof(CelluleP2));
 V->Val=x;
 V->Suiv=*P;
 *P=V;
}

//procedure Depiler
void Depiler2(Pile2 *P, Telm2 *x)
{Pile2 V;
 *x=(*P)->Val;
 V=*P;
 *P=(*P)->Suiv;
 free(V);
}

//Fonction Pile2vide
int Pilevide2(Pile2 P)
{if (P==NULL) return 1;
 else return 0;
}

//Fonction SommetPile2
Telm2 SommetPile2(Pile2 P)
{return P->Val;}

