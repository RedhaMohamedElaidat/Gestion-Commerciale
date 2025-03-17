//d�claration de la Pile
typedef struct date{int jj,mm,yy;}date;
typedef struct achat{int type,Ncomm_foct,Narti;float monHT,monTTC;date temp;Pile2 arti;}achat;
typedef achat Telm3;
typedef struct EPile3* Pile3;
typedef struct EPile3 { Telm3  Val; Pile3 Suiv;} CelluleP3;

//primitives des Piles
//procedure Initpile
void Initpile3(Pile3 *P)
{*P=NULL;}

//procedure Empiler
void Empiler3(Pile3 *P, Telm3 x)
{Pile3 V;
 V=malloc(sizeof(CelluleP3));
 V->Val=x;
 V->Suiv=*P;
 *P=V;
}

//procedure Depiler
void Depiler3(Pile3 *P, Telm3 *x)
{Pile3 V;
 *x=(*P)->Val;
 V=*P;
 *P=(*P)->Suiv;
 free(V);
}

//Fonction Pile2vide
int Pilevide3(Pile3 P)
{if (P==NULL) return 1;
 else return 0;
}

//Fonction SommetPile2
Telm3 SommetPile3(Pile3 P)
{return P->Val;}

