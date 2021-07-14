/*

A ajouter: promotion du pion
*/

#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <cstring> /* pour strcpy */
#include <cstdlib> /* pour atoi() pour convertir les char en int  */
#include <sstream>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <array>

/*#include "conio.c" // clrscr();
#include "stdlib.h" // system("cls");
*/
using namespace std;
using std::array;

/*
String QuelEstLeNomDeLaPieceDorigine(string type_piece,string couleur_piece,string case_actuelle)
{
string nom_piece_tmp="";
if (type_piece=="fou")&&(couleur=="blanc")
{
	if (couleur_case_echiquier(case_actuelle)=="blanc") //fou blanc de case blanche
	{
	nom_piece_tmp="f1";
	}
	if (couleur_case_echiquier(case_actuelle)=="noir") //fou blanc de case noir
	{
	nom_piece_tmp="c1";
	}
}//if

if (type_piece=="fou")&&(couleur=="noir")
{
	if (couleur_case_echiquier(case_actuelle)=="blanc") //fou noir de case blanche
	{
	nom_piece_tmp="c8";
	}
	if (couleur_case_echiquier(case_actuelle)=="noir") //fou noir de case noir
	{
	nom_piece_tmp="f8";
	}
}//if


if (type_piece=="dame")&&(couleur=="blanc")
{
nom_piece_tmp="d1";
}//if
if (type_piece=="dame")&&(couleur=="noir")
{
nom_piece_tmp="d8";
}//if

if (type_piece=="roi")&&(couleur=="blanc")
{
nom_piece_tmp="e1";
}//if
if (type_piece=="roi")&&(couleur=="noir")
{
nom_piece_tmp="e8";
}//if

return nom_piece_tmp;
}//string QuelEstLeNomDeLaPieceDorigine...
*/

string saisie("");
int num_etape_actuelle,num_derniere_etape=0;

void effacerEcran()
{
system("cls");
}//effacerEcran

void pause()
{
system("pause");
}

void precedent(){
	if(num_etape_actuelle>0)
	{
	num_etape_actuelle=num_etape_actuelle-1;
	}//if
	else
	{
	cout<<"\nVous etes deja a la derniere etape\n";
	}//else
}//void precedent()

void suivant(){
	if(num_etape_actuelle<num_derniere_etape)
	{
	num_etape_actuelle=num_etape_actuelle+1;
	}
    else
	{
	cout<<"\nVous etes deja a la derniere etape\n";
	}
//if
	}//void suivant

string contenu_caseEchiquierParEtapeColLig[150][10][10];/*soit vide soit nom_piece
contenu_caseEchiquierParEtapeColLig[num_etapetmp][num_col][num_lig]*/

string tab_cases_echiquier[64]{"a1","b1","c1","d1","e1","f1","g1","h1",
"a2","b2","c2","d2","e2","f2","g2","h2","a3","b3","c3","d3","e3","f3","g3","h3","a4","b4","c4","d4","e4","f4","g4","h4","a5","b5","c5","d5","e5","f5","g5","h5","a6","b6","c6","d6","e6","f6","g6","h6","a7","b7","c7","d7","e7","f7","g7","h7","a8","b8","c8","d8","e8","f8","g8","h8"};

string tab_nom_piecedorigine[32]={"a2","b2","c2","d2","e2","f2","g2","h2","a1","b1","c1","d1","e1","f1","g1","h1","a7","b7","c7","d7","e7","f7","g7","h7","a8","b8","c8","d8","e8","f8","g8","h8"};//tab_nom_piecedorigine[0]="a2"...

string tab_type_piecedorigine[32]={"pion","pion","pion","pion","pion","pion","pion","pion","tour","cavalier","fou","dame","roi","fou","cavalier","tour","pion","pion","pion","pion","pion","pion","pion","pion","tour","cavalier","fou","dame","roi","fou","cavalier","tour"};

string tab_couleur_piecedorigine[32]={"blanc","blanc","blanc","blanc","blanc","blanc","blanc","blanc","blanc","blanc","blanc","blanc","blanc","blanc","blanc","blanc","noir","noir","noir","noir","noir","noir","noir","noir","noir","noir","noir","noir","noir","noir","noir","noir"};




//string c_array[] = {"a","a","a","a","a","a","a","a"};

string tab_bord_Avd[]={"a8","b8","c8","d8","e8","f8","g8","h8","h7","h6","h5","h4","h3","h2","h1"};//liste des cases des bord ne pemettant le deplacement[Colonne+1][Ligne+1] ok

//================================ pour le deplacement de la tour





//===================================================================


/*
void print_array(std::array<string, 15>& array)
{
cout<<"\n fonction print_array";
}
*/

bool tab15ContientElm(string array[],string valAchercher)//si le tableau contient tel ou tel element pour tableau de detection des bords 15 elements par tableau
{
bool compar=false;
int taille=15;
/*
cout<<"\n fonction tab15ContientElm \n taille="<<taille<<" et vaudra toujours 15\n";*/

for(int i=0;i<taille;i++)
{
if(array[i]==valAchercher)
{compar=true;
//cout<<"\n true";
}
}//for
return compar;
}//bool tableauContientElement...

string  tab_hasardi[32];
bool estpresentTabHasardi(string piece)
{
bool	compar=false;
	for(int i=0;i<32;i++)
	{
		if (tab_hasardi[i]==piece)
		{
		compar=true;
		}
	}

return compar;
}//bool estpresentTabHasardi


bool tab8ContientElm(string array[],string valAchercher)//si le tableau contient tel ou tel element pour tableau de detection des bords pour les tabeaux contenant 8 elements
{
bool compar=false;
int taille=8;
/*
cout<<"\n fonction tab15ContientElm \n taille="<<taille<<" et vaudra toujours 8\n";*/

for(int i=0;i<taille;i++)
{
if(array[i]==valAchercher)
{compar=true;
//cout<<"\n true";
}
}//for
return compar;
}//bool tableauContientElement...

bool estPair(int i)
{
bool compar=false;
if((i%2)==0){compar=true;}
else{compar=false;}
return compar;
}
bool estImpair(int i)
{
bool compar=false;
if(estPair(i)){compar=false;}
else{compar=true;}

return compar;
}

bool NonbordAvd(string lacase)
{bool compar=true;if(tab15ContientElm(tab_bord_Avd,lacase))
{compar=false;}return compar;
}//bool NonbordAvd



//================================ pour le deplacement de la tour



string tab_bord_Haut[]={"a8","b8","c8","d8","e8","f8","g8","h8"};//pour le deplacement de la tour liste des cases des bord ne pemettant le deplacement[Ligne+1] pour la fonction NonbordHaut

bool NonbordHaut(string lacase)
{bool compar=true;if(tab8ContientElm(tab_bord_Haut,lacase))
{compar=false;}return compar;
}//bool NonbordHaut

/*
caseAVHaut,caseARBas,caseColExtrDroite,caseColExtrGauche
NonbordHaut(
NonbordBas(
NonbordDroit(
NonbordGauche(
*/
string tab_bord_Bas[]={"a1","b1","c1","d1","e1","f1","g1","h1"};//pour le deplacement de la tour liste des cases des bord ne pemettant le deplacement[Ligne-1] pour la fonction NonbordBas

bool NonbordBas(string lacase)
{bool compar=true;if(tab8ContientElm(tab_bord_Bas,lacase))
{compar=false;}return compar;
}//bool NonbordBas


string tab_bord_Droit[]={"h1","h2","h3","h4","h5","h6","h7","h8"};//pour le deplacement de la tour liste des cases des bord ne pemettant le deplacement[Col+1] pour la fonction NonbordDroit

bool NonbordDroit(string lacase)
{bool compar=true;if(tab8ContientElm(tab_bord_Droit,lacase))
{compar=false;}return compar;
}//bool NonbordDroit



string tab_bord_Gauche[]={"a8","a7","a6","a5","a4","a3","a2","a1"};//pour le deplacement de la tour liste des cases des bord ne pemettant le deplacement[col-1] pour la fonction NonbordGauche

bool NonbordGauche(string lacase)
{bool compar=true;if(tab8ContientElm(tab_bord_Gauche,lacase))
{compar=false;}return compar;
}//bool NonbordGauche



//===================================================================




string tab_bord_Avg[15]={"a8","b8","c8","d8","e8","f8","g8","h8","a7","a6","a5","a4","a3","a2","a1"};//liste des cases des bord ne pemettant le deplacement[Colonne-1][Ligne+1] ok

bool NonbordAvg(string lacase)
{bool compar=true;if(tab15ContientElm(tab_bord_Avg,lacase))
{compar=false;}return compar;
}//bool NonbordAvg


string tab_bord_Arg[15]={"a1","b1","c1","d1","e1","f1","g1","h1","a2","a3","a4","a5","a6","a7","a8"};//liste des cases des bord ne pemettant le deplacement[Colonne-1][Ligne-1]ok

bool NonbordARG(string lacase)
{bool compar=true;if(tab15ContientElm(tab_bord_Arg,lacase))
{compar=false;}
/*cout<<"\n TEST pour la fonction NonbordARG(lacase="<<lacase<<") compar vaut "<<compar<<"\n";*/
return compar;
}//bool NonbordARG

string tab_bord_Ard[15]={"a1","b1","c1","d1","e1","f1","g1","h8","h7","h6","h5","h4","h3","h2","h1"};//liste des cases des bord ne pemettant le deplacement[Colonne+1][Ligne-1]

bool NonbordARD(string lacase)
{bool compar=true;if(tab15ContientElm(tab_bord_Ard,lacase))
{compar=false;}
/*cout<<"\n TEST pour la fonction NonbordARD(lacase="<<lacase<<") compar vaut "<<compar<<"\n";*/
return compar;
}//bool NonbordARD

void clonnerEchiquierDuneEtapeVersAutreEtape(int num_etape_origine,int num_etape_destination)
{
	for(int c=0;c<10;c++)
	{
			for(int l=0;l<10;l++)
			{
			contenu_caseEchiquierParEtapeColLig[num_etape_destination][c][l]=contenu_caseEchiquierParEtapeColLig[num_etape_origine][c][l];
			}//for
	}//for

}//void clonnerEchiquierDuneEtapeVersAutreEtape(...)

string nom_piece(int numpiece)
{
string nom_piece="pieceinconnu";

nom_piece=tab_nom_piecedorigine[numpiece];

return nom_piece;
}//string nom_piece(int numpiece)



int numpiece(string nom_piece)
{
int num_piece=99;
 for (int i = 0; i < 32; i++)
{ //cout << tab_num_piecedorigine;
//cout<<"\n i="<<i;
if(tab_nom_piecedorigine[i]==nom_piece)
 {
/*
	cout<<"\n (tab_nom_piecedorigine[i]==nom_piece) \n";
	cout<<"\n match    i="<<i<<"\n tab_nom_piecedorigine[i]= "<< tab_nom_piecedorigine[i]<<" "<<"nom_piece"<<nom_piece<<"    et \n";
*/
	num_piece=i;

 }//if
}//for
/*
cout<<"\n fin de la fonction int numpiece(string nom_piece) : \n ---> au final num_piece= "<<num_piece<<" pour nom_piece = "<<nom_piece;*/
return num_piece;
}//int numpiece(string nom_piece)


string couleur_piecedorigineI(int numpiece)
{
return 	tab_couleur_piecedorigine[numpiece];
}//string couleur_piecedorigineI(int numpiece)

string couleur_piecedorigineS(string nompiece)
{
//int numpiecetmp=99;
int numpiecetmp=numpiece(nompiece);
return 	tab_couleur_piecedorigine[numpiecetmp];
}//string couleur_piecedorigineS(string nompiece)

bool estPieceBlanc(string nom_piece)
{
if(couleur_piecedorigineS(nom_piece)=="blanc")
{return true;}
else {return false;}
}//bool estPieceBlanc(string nom_piece)


bool estPieceNoir(string nom_piece)
{
if(couleur_piecedorigineS(nom_piece)=="noir")
{return true;}
else {return false;}
}//bool estPieceNoir(string nom_piece)

//=================  Pour la gestion du score
int nbre_de_test,score=0;
int tab_score[100][32];//A VERIFIER s'il faut modifier la taille
//tab_score[nbre_de_test][num_piecechoisie]=score;
void afficherScore()
{
string nompiecetmp="";
cout<<"\n ===================================================\n";
cout<<"\n       ========\nScore \n";cout<<"=======";
cout<<"\n il y a eu "<<nbre_de_test<<" tests\n";
cout<<"\n Rq. seuls les scores > 0 s'afficheront";
for(int i=1;i<=nbre_de_test;i++)
{
for(int j=0;j<32;j++)
{
nompiecetmp=nom_piece(j);
if(tab_score[i][j]>0)
{
 cout<<"\n"<<j<<" num_de_test : "<<i<<" la piece "<<nompiecetmp<<" score : "<<tab_score[i][j];
}//if tab_score
}//for j

cout<<"\n---------------------------------------------------\n";
}//for i

cout<<"\n       ===============";
cout<<"\n ===================================================\n";
}//void afficherScore
//================================


bool estPieceCouleurOpposee(string nompiecedorigine,string nompiecedecomparaison)
{
bool compar=false;
//cout<<"\n ====================================\n";
//cout<<"\n TEST 185 debut de la fonction estPieceCouleurOpposee(string nompiecedorigine,string nompiecedecomparaison)";
cout<<"\n fonction estPieceCouleurOpposee("<<nompiecedorigine<<","<< nompiecedecomparaison<<")";
if(
(estPieceNoir(nompiecedorigine))&&(estPieceBlanc(nompiecedecomparaison)))
{compar=true;}

else if(
 (estPieceBlanc(nompiecedorigine))&&(estPieceNoir(nompiecedecomparaison)))
{compar=true;}

cout<<"\n compar vaut "<<compar;
cout<<"\n fin de la fonction estPieceCouleurOpposee...";
cout<<"\n ====================================\n";
return compar;
}//bool estPieceCouleurOpposee(string nompiecedorigine,string nompiecedecomparaison)



string type_piecedorigineI(int numpiece)
{
return 	tab_type_piecedorigine[numpiece];
}

string type_piecedorigineS(string nompiece)
{
int numpiecetmp=numpiece(nompiece);
return 	tab_type_piecedorigine[numpiecetmp];
}


string convert_nbre_en_string(int nbre)
{
/**********************************************/
/*Comment convertir un nombre en une string ?
[haut]


auteur : Aurélien Regat-Barrel

L'utilisation d'un objet ostringstream permet de convertir un entier en une string :
*/


    // créer un flux de sortie
   ostringstream oss;
    // écrire un nombre dans le flux

	oss << nbre;  //oss << 10;
    // récupérer une chaîne de caractères
    string s = oss.str();
	return s;
}//string convert_nbre_en_string(int nbre)



/*********************************************      **************************/
//char vers string
string char_vers_string(char c)
{
    string s(1, c);
   // cout << "string s vaut "<<s << endl;
	return s;
}


//string vers int
int string_vers_int(string s)  /** attention un string avec un seul caractere "1" ou "2".....*/
{
	/*
	1) convert string to char_array
	2) convert char_array to int
	*/
/*
	1) convert string to char_array : */
   // string s = "geeksforgeeks";

    int n = s.length();

    // declaring character array
    char char_array[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str());

    for (int i = 0; i < n; i++)
	{ cout << char_array[i];}

/*2) convert char_array to int : */
//char char_array[] = "1235";
int nombre = atoi(char_array);

return nombre;
}///int string vers int(string s)


/*********************************************      **************************/

/*******************************************************************/

string positionEnString(int Col,int Lig)
{
/*	Col 1, Lig 2 donne a2 */
/*cout<<"\n fonction positionEnString avec comme entrees : Col= " <<Col<<" et Lig= "<<Lig<<"\n";*/
char tab_lettres[]="abcdefgh";
char colonne_c;
char ligne_c;

string colonne_s;
string ligne_s;
string position_s;
/*
for (int i=0; i<7; ++i)
{}//for*/

colonne_c=tab_lettres[Col-1];

colonne_s=char_vers_string(colonne_c);

ligne_s=convert_nbre_en_string(Lig);
position_s=colonne_s+ligne_s;
/*cout<<"\n resultat de positionEnString : La case dans la colonne "<< Col<<" et la ligne "<<Lig<<" est "<<position_s<<"\n";
*/
return position_s;
}//string positionEnString(int Col,int Lig)

/*********************************************      **************************/

/*********************************************      **************************/


int colonne(string position_depart)
{
/*C=colonne(string position_depart);*//*(a4 donne colonne numero 1)*/
string s;
char c_col;
int i_col;

s=position_depart;
	int n = s.length();

    // declaring character array
    char char_array[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str());

    for (int i = 0; i < n; i++)
	{ cout << char_array[i];}

c_col=char_array[0];
if (c_col=='a') {i_col=1;}
if (c_col=='b') {i_col=2;}
if (c_col=='c') {i_col=3;}
if (c_col=='d') {i_col=4;}
if (c_col=='e') {i_col=5;}
if (c_col=='f') {i_col=6;}
if (c_col=='g') {i_col=7;}
if (c_col=='h') {i_col=8;}


/*cout<< "le numéro de colonne "<< "de la case "<<position_depart<<" est "<<i_col <<endl;
*/

/*cout << "le numéro de colonne de la case  " << position_depart << endl;
cout << "est  " << i_col << endl;
*/
return i_col;
}// int colonne(string position_depart)


/*----------------------------------------------------------------*/

int ligne(string position_depart)
{
/*L=ligne(string position_depart);*//*(a4  donne line numéro 4)*/
string s;
char c_ligne;
//int i_ligne;

s=position_depart;
	int n = s.length();

    // declaring character array
   char char_array[n + 1];

    /*copying the contents of the
     string to char array*/
    strcpy(char_array, s.c_str());

   /*****for (int i = 0; i < n; i++)
	{ cout << char_array[i]<<" \n";}
    */
c_ligne=char_array[1];

    string s_ligne(1, c_ligne);
 //*****   cout << "s_ligne vaut "<<s_ligne << endl;

/*char caracteres[] = "1235";
int nombre = atoi(caracteres);*/

int ligne_i=string_vers_int(s_ligne);
/*
cout << "nombre ligne_i =" <<ligne_i<<endl;
***cout << " la ligne de la case  " << position_depart << endl;
cout <<"148 en char est  est  " << c_ligne << endl;
cout <<"149 en string est  est  " << s_ligne << endl;
cout <<" et en int est  est  " << ligne_i << endl;
*/

return ligne_i;
}

void AffecterCaseColLigAtelEtape(int etape,int c,int l,string nouvelle_valeur)
{
	//(nouvelle_valeur peux valoir "vd" ou nomdela piecedorigine "a2".....
contenu_caseEchiquierParEtapeColLig[etape][c][l]=nouvelle_valeur;

//string pos_str=positionEnString(c,l);

//string piece_tmp=QuelPieceAtelCaseColLigneAtelEtape(etape,c,l);
}//

//======================================

void AffecterCaseAtelEtape(int etape,string pieceAmettre,string caseDeDestination)
{
	//(nouvelle_valeur peux valoir "vd" ou nomdela piecedorigine "a2".....
	int c=colonne(caseDeDestination);
	int l=ligne(caseDeDestination);
contenu_caseEchiquierParEtapeColLig[etape][c][l]=pieceAmettre;

//string pos_str=positionEnString(c,l);

//string piece_tmp=QuelPieceAtelCaseColLigneAtelEtape(etape,c,l);
}//
void ViderCaseColLigAtelEtape(int etape,int c,int l)
{
	//(nouvelle_valeur peux valoir "vd" ou nomdela piecedorigine "a2".....
contenu_caseEchiquierParEtapeColLig[etape][c][l]="vd";
}//

void viderLaCaseAtelEtape(int etape, string position)//a voir si utiliser etape+1 ou etape *********************************************** ATTENTION tmp
{

cout<<"\n fonction void viderLaCaseAtelEtape(int etape, string position)";
cout<<"\n Avec comme paramettres: ";
cout<<"\netape= "<<etape;
cout<<"\nposition= "<<position;
int col=colonne(position);
int lig=ligne(position);
contenu_caseEchiquierParEtapeColLig[etape][col][lig]="vd";
cout<<"\n Fin de la fonction void viderLaCaseAtelEtape(";
cout<<etape;
cout<<",";
cout<<position;
cout<<")";
} //

string ouSeTrouveTelPieceATelEtape(int num_etape,string nom_piece)
{
cout<<"\n TEST pour la fonction  string ouSeTrouveTelPieceATelEtape(int num_etape,string nom_piece)\n";
cout<<"\nouSeTrouveTelPieceATelEtape("<<num_etape<<","<<nom_piece<<")\n";
string position_de_la_piece="null_part";
int col_position_de_la_piece=99;
int lig_position_de_la_piece=99;
for(int c=1;c<9;c++)
{
for(int l=1;l<9;l++)
{
	if (contenu_caseEchiquierParEtapeColLig[num_etape][c][l]==nom_piece)
	{
	col_position_de_la_piece=c;
	lig_position_de_la_piece=l;
	}//if
}//for

}//for

position_de_la_piece=positionEnString(col_position_de_la_piece,lig_position_de_la_piece);

cout<<"\nLa reponse de la fonction est "<<position_de_la_piece;
return position_de_la_piece;
}//string ouSeTrouveTelPieceATelEtape(int num_etape,string nom_piece)


string QuelPieceAtelCaseAtelEtape(int numero_etape,string lacase)
{
/*cout<<"\n467 fonction QuelPieceAtelCaseAtelEtape avec numero_etape="<<numero_etape<<"et 	lacase=="<<lacase<<"\n";
*/
string pieceAcetteCase="vd";

int c=99;
c=colonne(lacase);
int l=99;
l=ligne(lacase);
/*cout<<"\n toujours dans la fonction QuelPieceAtelCaseAtelEtape  c vaut"<<c<<" et l = "<<l;*/
pieceAcetteCase=contenu_caseEchiquierParEtapeColLig[numero_etape][c][l];
//cout<<"\n test la fonction QuelPieceAtelCaseAtelEtape pieceAcetteCase vaut "<<pieceAcetteCase<<" pour la case "<<lacase<<" a l etape "<<numero_etape<<"\n";
return 	pieceAcetteCase;
}

bool estCaseVideAlEtape(int numero_etape,string lacase)
{
bool compar=false;
if(QuelPieceAtelCaseAtelEtape(numero_etape,lacase)=="vd")
{
compar=true;
}//if QuelPieceAtelCaseAtelEtape...
return compar;
}//fonction estCaseVideAlEtape....

string QuelPieceAtelCaseColLigneAtelEtape(int numero_etape,int c,int l)
{

string pieceAcetteCase="vd";
pieceAcetteCase=contenu_caseEchiquierParEtapeColLig[numero_etape][c][l];
/*soit vide soit nom_piece
contenu_caseEchiquierParEtapeColLig[num_etapetmp][num_col][num_lig]*/

return 	pieceAcetteCase;
}
string queContientTelCaseALetapeActuelle(string nom_case)
{
	//return queContientTelCaseATelEtape(nom_case,num_etape_actuelle);
	return QuelPieceAtelCaseAtelEtape(num_etape_actuelle,nom_case);

}

bool estpriseParPieceCouleurOpposee(int numero_etape,string pieceActuelle,string nom_case_destination)
{
bool resultb=false;
string pieceDansCaseDestination="";
pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape(num_etape_actuelle,nom_case_destination)	;
resultb=estPieceCouleurOpposee(pieceActuelle,pieceDansCaseDestination);
return resultb;
}


bool estVideAlEtape(int etape,string nom_case)
{
bool compar=false;
if (QuelPieceAtelCaseAtelEtape(etape,nom_case)=="vd")
{compar=true;}

return compar;
}//bool estVideAlEtape(int etape,string nom_case)

bool estVideAlEtapeColLig(int etape,int col,int lig)
{
bool compar=false;/*
cout<<"\n ==============================";
cout<<"\n =====estVideAlEtapeColLig(int etape,int col,int lig)";
cout<<"\n =====estVideAlEtapeColLig("<<etape<<","<<col<<","<<lig<<")";

cout<<"\ contenu_caseEchiquierParEtapeColLig[etape][col][lig]=";
cout<<contenu_caseEchiquierParEtapeColLig[etape][col][lig];*/
if (contenu_caseEchiquierParEtapeColLig[etape][col][lig]=="vd")
{
//cout<<"\n VAUT vd";
compar=true;}
//cout<<"\ncompar vaut "<<compar;
//cout<<"\n ==============================";
return compar;
}//bool estVideAlEtapeColLig(int etape,string nom_case)


void AfficherListePiecesDorigineParCriteres(string typedepiece,string couleurdepiece)
{
cout<<"\nTEST  fonction AfficherListePiecesDorigineParCriteres \ncriteres demandes : type de piece : "<<typedepiece<<"\n couleur de piece : "<<couleurdepiece<<"\n";
//string tab_piecesCorrespCritere[32];
//int nombre elemCorrespondants=0;

for(int i=0;i<32;i++)
{

//cout<<"\n\n i="<<i;
string	nom_piece_tmp,type_piece_tmp,couleur_piece_tmp="";

nom_piece_tmp=nom_piece(i);

/*cout<<"\n nom_piece="<<nom_piece_tmp;*/

type_piece_tmp=type_piecedorigineI(i);
/*cout<<"\n type="<<type_piece_tmp;*/
couleur_piece_tmp=couleur_piecedorigineI(i);
/*cout<<"\n couleur="<<couleur_piece_tmp;	*/

if
(
((typedepiece==type_piece_tmp)||(typedepiece=="tous"))
&&
((couleurdepiece==couleur_piece_tmp)||(couleurdepiece=="tous"))
)//if
{
/*tab_piecesCorrespCritere[nbreElemCorrespondants]=i;
nbreElemCorrespondants=nbreElemCorrespondants+1;
*/
cout<<"\n "<<i;
cout<<" "<<nom_piece_tmp;
cout<<" "<<type_piece_tmp;
cout<<" "<<couleur_piece_tmp;

}

}//for i  0... 32

}//void AfficherListePiecesDorigineParCriteres(string typedepiece,string couleurdepiece)

void vider_Echiquier() ///A FINALISER
{
num_etape_actuelle=0;
for (int num_etapetmp = 0; num_etapetmp <=num_derniere_etape ; num_etapetmp++)//A REMETTRE : Au lieu de 2 mettre 150
	{

		for(int c=1;c<9;c++)
		{
			for(int l=1;l<9;l++)
			{

			ViderCaseColLigAtelEtape(num_etapetmp,c,l);

			//tabCL[i][j]="Vide";  //Vider tableau tabCL[C][L];
			}//for j
		}//for i
	}//for num_etapetmp


num_derniere_etape=0;



}//void vider_Echiquier()

//------------------------------------------------------

void specialViderEchiquierDeTelEtape(int num_etapetmp)//UTILISER DANS L EXO DEPLACEMNT D UNE PIECE SEULE LE RESTE : ECHIQUIER VIDE
{
		for(int c=1;c<9;c++)
		{
			for(int l=1;l<9;l++)
			{

			ViderCaseColLigAtelEtape(num_etapetmp,c,l);

			//tabCL[i][j]="Vide";  //Vider tableau tabCL[C][L];
			}//for j
		}//for i

}//void specialViderEchiquierATelEtape(int num_etapetmp)
//-------------------------------------------

void initEchiquierComplet()
{
cout<<"\n";
cout<<"\ninitEchiquierComplet\n";
vider_Echiquier();
num_etape_actuelle=0;

for(int c=1;c<9;c++)
{
for(int l=1;l<9;l++)
{
if((l>2)&&(l<7))
{
contenu_caseEchiquierParEtapeColLig[0][c][l]=positionEnString(c,l)="vd";
}//if
else
{
contenu_caseEchiquierParEtapeColLig[0][c][l]=positionEnString(c,l);
}//else
}//for l
}//for c
cout<<"\n";
}//void initEchiquierComplet

void AfficherEchiquierATelEtape(int num_etapetmp)
{
cout<<"\n\n ***** etape: "<<num_etapetmp<<" \n\n";

for(int l=8;l>0;l--)
//for(int c=8;c>0;c--)
{
cout<<"\n";
for(int c=1;c<9;c++)
//for(int l=0;l<8;l++)
{
//cout<<"\n c= "<<c<<" l= "<<l<<"  "<<tabCL[c][l]<<" ";
cout<<" "<<contenu_caseEchiquierParEtapeColLig[num_etapetmp][c][l]<<" ";
//cout<<"c= "<<c<<" l= "<<l<<" ";

}//for l

}//for c
cout<<"\n";
}

void AfficherEchiquierParEtape()
{
cout<<"\n";
string nomdepiece,positiondelapieceAtelEtape="";
	cout<<"\n ===============";
	cout<<"\n*******Fonction AfficherEchiquierParEtape()";
	cout<<"\nnum_etape_actuelle : "<<num_etape_actuelle;
	cout<<"\n ===============";
for (int num_etapetmp = 0; num_etapetmp <=num_derniere_etape ; num_etapetmp++)//A REMETTRE : Au lieu de 2 mettre 150
	{

   AfficherEchiquierATelEtape(num_etapetmp);
///////////////////////////////////////////

//vider_Echiquier();


///////////////////////////////////////////


}//for num_etapetmp

cout<<"\n";
}//void AfficherEchiquierParEtape()


//---------------------------------------------

//------------------------
void AfficherEchiquierParEtapeEnTexte()
{
/*
	cout<<"\n ===============";
	cout<<"\n*******Fonction AfficherEchiquierParEtapeEnTexte()";
	cout<<"\nnum_etape_actuelle : "<<num_etape_actuelle;
	cout<<"\n ===============";
for (int num_etapetmp = 0; num_etapetmp < 3; num_etapetmp++)//A REMETTRE : Au lieu de 3 mettre 150
	{
    cout<<"\n ***** etape: "<<num_etapetmp;
	for (int num_piecetmp = 0; num_piecetmp < 32; num_piecetmp++)//
	{
    cout<<"\n ---------------";
	cout<<"\n la piece "<< num_piecetmp <<" "<<nom_piece(num_piecetmp)<<" est a la position

	//tab_nom_piecedorigine[0]="a2"...
	cout<<"\n ---------------";
	}//for j
}//for i

*/

}//void AfficherEchiquierParEtapeEnTexte()
//-------------------------------------------------------

bool nombordPourCavalier(int numcas,int c,int l)
{
bool compar=false;
/*

CAS1 C+1 l+2            si c<=7 && l<=6
CAS2 C+2 l+1            si c<=6 && l<=7
CAS3 C+1 l-2            si c<=7 && l>=2
CAS4 C+2 l-1            si c<=6 && l>=1
CAS5 C-1 l+2            si c>=1 && l<=6
CAS6 C-2 l+1            si c>=2 && l<=7
CAS7 C-1 l-2            si c>=1 && l>=2
CAS8 C-2 l-1            si c>=2 && l>=1
*/

if((c>=0)&&((l>=0)&&(c<=8)&&((l<=8))))
{
if(numcas=1){if(c<=7 && l<=6){compar=true;}}
if(numcas=2){if(c<=6 && l<=7){compar=true;}}
if(numcas=3){if(c<=7 && l>=2){compar=true;}}
if(numcas=4){if(c<=6 && l>=1){compar=true;}}
if(numcas=5){if(c>=1 && l<=6){compar=true;}}
if(numcas=6){if(c>=2 && l<=7){compar=true;}}
if(numcas=7){if(c>=1 && l>=2){compar=true;}}
if(numcas=8){if(c>=2 && l>=1){compar=true;}}
}
//cout<<"\n=============================\n";
//cout<<"\n=============================\n";

//cout<<"\npour la fonction nombordPourCavalier(int numcas,int c,int l) \n"<<endl;
//cout<<"\ntest fonction nombordPourCavalier("<<numcas<<","<<c<<","<<l<<") \n compar vaut "<<compar;


//cout<<"\n=============================\n";
//cout<<"\n=============================\n";


return compar;
}//bool nombordPourCavalier(
///////////////////////////////////



bool deplacementAutorise(string nom_piece_a_deplacer,string type_piece,string couleur_piece,string position_depart,string position_arrivee)
/*, string couleur_piece,string position_depart,string position_arrivee */
{
bool autorisation_b=false;
int nbreDeCasesAutorisees=0;
int C,L=0;
int Ltmp,Ctmp=0;
string caseAVG,caseAVD,caseARG,caseARD="";//pour deplacement de pion en diagonale avant droit et avant gauche
string caseAVHaut,caseARBas,caseColExtrDroite,caseColExtrGauche="";//pour le deplacement de la tour et de la dame
string caseDeplCaval;//pour le deplacement du cavalier
string position_actuelle_tmp="";//pour deplacement du fou et de la dame notament
cout<<"\n"<<"nbreDeCasesAutorisees= "<<nbreDeCasesAutorisees;
string tab_str_pos_autorisees[64];

	cout<<"\n Fonction deplacement autorise "<< type_piece << " "<< couleur_piece << " "<< position_depart << " "<< position_arrivee << endl;

C=colonne(position_depart);/*(a4 donne colonne numero 1)*/
L=ligne(position_depart);/*(a4  donne line numéro 4)*//*
	pion  si posi depart : autorisé : si couleur B alors L+1 et L+2
	si non pos depart : L+1 si L<=7
*/

cout<<" C = " <<C<<endl;
cout<<" L = " <<L<<endl;

	if(type_piece=="pion")
	{
		if(couleur_piece=="blanc")
		{
/*		ATTENTION deplacement autorisé si destination vide ou occupée par adversaire*/



/*pion  si posi depart : autorisé : si couleur B alors C, L+1  et C, L+2*/
//string stmp=positionEnString(C,L);



//============================== pion blanc en position de depart
if (L==2) //pion blanc en position de depart
{
//tab_positions_autorisees   : 	C, L+1  et C, L+2  ****** a rajouter si adversaire diagonale autorise sur ligne suivante*/
cout<<"\n le pion blanc "<<position_depart<<" est en position de depart \n";


if((estVideAlEtapeColLig(num_etape_actuelle,C,L+1))&&(estVideAlEtapeColLig(num_etape_actuelle,C,L+2)))
{
Ltmp=L+2;

tab_str_pos_autorisees[nbreDeCasesAutorisees]=positionEnString(C,Ltmp);
nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;
cout<<"\n 758 nouvelle case autorisee : "<<positionEnString(C,Ltmp);//C,L+2
//cout<<"\n "<<"nbreDeCasesAutorisees= "<<nbreDeCasesAutorisees;
}//if est vide...

//=================================================================
}//if  pos de depart  (L==2)


	/* L+1 si L<=7*************/

	if(L<8)
	{
		//cout<<"\n TEST L<8 pion blanc";
		//pause();
Ltmp=L+1;
		if(estVideAlEtapeColLig(num_etape_actuelle,C,Ltmp))
		{

		tab_str_pos_autorisees[nbreDeCasesAutorisees]=positionEnString(C,Ltmp);
	nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;
cout<<"\n 774 nouvelle case autorisee (C,L++1): "<<positionEnString(C,Ltmp);
//pause();
	}//if estVide....

	if(C>1)
	{
	caseAVG=positionEnString(C-1,L+1);
	//:;lpieceAlacaseAVG=
//cout<<"\n TEST caseAVG="<<caseAVG<<"et position_depart="<<position_depart;
		if //(estPieceCouleurOpposee(position_depart,caseAVG))
//****	(estpriseParPieceCouleurOpposee(num_etape_actuelle,position_depart,caseAVG)	)
(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseAVG)	)

		{
	//	cout<<"\n TEST 	position_depart  "<<position_depart<<" et la piece dans la case caseAVG "<<caseAVG<<" sont de couleurs opposes";
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=positionEnString(C-1,L+1);
	    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;
		}//if estPieceCouleurOpposee....
		else
		{
	//	cout<<"\n TEST 	position_depart  "<<position_depart<<" et la piece dans la case caseAVG "<<caseAVG<<" Ne sont pas de couleurs opposees";
		}
	}//if((C>1)

	if(C<8)
	{
	caseAVD=positionEnString(C+1,L+1);
//cout<<"\n TEST caseAVD="<<caseAVD<<"et position_depart="<<position_depart;

		if //(estPieceCouleurOpposee(position_depart,caseAVD))
	//	(estpriseParPieceCouleurOpposee(num_etape_actuelle,position_depart,caseAVD)	)
	(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseAVD)	)
		{
		//cout<<"\n TEST 	position_depart  "<<position_depart<<" et la piece dans la case caseAVD "<<caseAVD<<" sont de couleurs opposes";
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=positionEnString(C+1,L+1);
	    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;
		}//if estPieceCouleurOpposee....
		else
		{
		//cout<<"\n TEST 	position_depart  "<<position_depart<<" et la piece dans la case caseAVD "<<caseAVD<<" Ne sont pas de couleurs opposees";
		}
	}//if((C>1)

	}//if(L<8)

		}//if(couleur_piece=="blanc") dans if(type_piece=="pion")

	}//if(type_piece=="pion")

    //=======================================================




//pour deplacement du fou et dame valable pour les 2 couleurs
if((type_piece=="fou")||(type_piece=="dame"))
{

//============= fou AVD

Ctmp=C;Ltmp=L;
//cout<<"\n TEST 840  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";
//position_actuelle_tmp=position_depart;
//position_actuelle_tmp=nom_piece_a_deplacer;
position_actuelle_tmp=position_depart;
if(NonbordAvd(position_actuelle_tmp))
	{
	Ctmp=Ctmp+1;Ltmp=Ltmp+1;
	//cout<<"\n TEST 845  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";
	caseAVD=positionEnString(Ctmp,Ltmp);
    //position_AVD_tmp=positionEnString(Ctmp,Ltmp);
	//cout<<"\n ************ TEST 851  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et caseAVD aut "<<caseAVD<<"\n";

	/*
	position_actuelle_tmp = e3 et caseAVD aut f4
	*/

while((estVideAlEtape(num_etape_actuelle,caseAVD))&&(NonbordAvd(position_actuelle_tmp)))
//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))//while((estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))&&(NonbordAvd(position_depart_tmp)))
	{

	//caseAVD=positionEnString(Ctmp,Ctmp);
	//position_depart_tmp=positionEnString(Ctmp,Ctmp);

	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseAVD;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

	//cout<<"\n TEST 860 dans le while estVideAlEtape(num_etape_actuelle,caseAVD)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseAVD= "<<caseAVD<<"\n";

    position_actuelle_tmp=caseAVD;
    Ctmp=Ctmp+1;Ltmp=Ltmp+1;
	caseAVD=positionEnString(Ctmp,Ltmp);

//cout<<"\n TEST 868  toujours dans le while vide************  Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et  caseAVD= "<<caseAVD<<"\n";


	}//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

/*	position_actuelle_tmp = e3 et caseAVD aut f4 */


//==============================

//cout<<"\n TEST 883 pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape(num_etape_actuelle,nom_case_destination) :";
cout<<"\n  pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape("<<num_etape_actuelle<<","<<caseAVD<<") :";
cout<<"\n ===";
cout<< QuelPieceAtelCaseAtelEtape(num_etape_actuelle,caseAVD);
cout<<"===\n";
cout<<"\n";

//====================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseAVD)	)//bool estpriseParPieceCouleurOpposee(int numero_etape,string pieceActuelle,string nom_case_destination)
		{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseAVD;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

		//	cout<<"\n ************ TEST 878 dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseAVD= \n  est "<<caseAVD<<"\n";

 position_actuelle_tmp=caseAVD;
    		}//if((estpriseParPieceCouleurOpposee(num_etape_actuelle,position_depart,caseAVD)	)

}//if(NonbordAvd(position_actuelle_tmp))



//============= fou Avg

//position_actuelle_tmp=nom_piece_a_deplacer;//recentrer sur la case choisi avant de calculer les cases autorisés
position_actuelle_tmp=position_depart;
Ctmp=C;Ltmp=L;//pour le calcul du prochain AVG

if(NonbordAvg(position_actuelle_tmp))
	{
	Ctmp=Ctmp-1;Ltmp=Ltmp+1;
//	cout<<"\n TEST 845  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";
	caseAVG=positionEnString(Ctmp,Ltmp);
    //position_Avg_tmp=positionEnString(Ctmp,Ltmp);
//	cout<<"\n ************ TEST 851avg - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et caseAVG aut "<<caseAVG<<"\n";

	/*
	position_actuelle_tmp = e3 et caseAVG aut f4
	*/

while((estVideAlEtape(num_etape_actuelle,caseAVG))&&(NonbordAvg(position_actuelle_tmp)))
//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))//while((estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))&&(NonbordAvg(position_depart_tmp)))
	{

	//caseAVG=positionEnString(Ctmp,Ctmp);
	//position_depart_tmp=positionEnString(Ctmp,Ctmp);

	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseAVG;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

//	cout<<"\n TEST 860avg dans le while estVideAlEtape(num_etape_actuelle,caseAVG)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseAVG= "<<caseAVG<<"\n";

    position_actuelle_tmp=caseAVG;
    Ctmp=Ctmp-1;Ltmp=Ltmp+1;
	caseAVG=positionEnString(Ctmp,Ltmp);

//cout<<"\n TEST 868avg toujours dans le while vide************  Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et  caseAVG= "<<caseAVG<<"\n";


	}//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

/*	position_actuelle_tmp = e3 et caseAVG aut f4 */


//==============================

//cout<<"\n TEST 883avg pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape(num_etape_actuelle,nom_case_destination) :";
cout<<"\n  pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape("<<num_etape_actuelle<<","<<caseAVG<<") :";
cout<<"\n ===";
cout<< QuelPieceAtelCaseAtelEtape(num_etape_actuelle,caseAVG);
cout<<"===\n";
cout<<"\n";

//====================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseAVG)	)//bool estpriseParPieceCouleurOpposee(int numero_etape,string pieceActuelle,string nom_case_destination)
		{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseAVG;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

		//	cout<<"\n ************ TEST 878avg dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuellere_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseAVG= \n  est "<<caseAVG<<"\n";

 position_actuelle_tmp=caseAVG;
    		}//if((estpriseParPieceCouleurOpposee(num_etape_actuelle,position_depart,caseAVG)	)

}//if(NonbordAvg(position_actuelle_tmp))


//============================
//============= fou ARG
//cout<<"\n=============================================";
//cout<<"\n================ debut de la partie  fou ARG ";
//position_actuelle_tmp=nom_piece_a_deplacer;//recentrer sur la case choisi avant de calculer les cases autorisés
position_actuelle_tmp=position_depart;
Ctmp=C;Ltmp=L;//pour le calcul du prochain ARG
cout<<"\n toujours dans la partie ARG position_actuelle_tmp = "<<position_actuelle_tmp<<" et Ctmp ="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";

if(NonbordARG(position_actuelle_tmp))
	{
	Ctmp=Ctmp-1;Ltmp=Ltmp-1;
	//cout<<"\n TEST 845  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";
	caseARG=positionEnString(Ctmp,Ltmp);
    //position_ARG_tmp=positionEnString(Ctmp,Ltmp);
//	cout<<"\n ************ TEST 851ARG - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et caseARG aut "<<caseARG<<"\n";

	/*
	position_actuelle_tmp = e3 et caseARG aut f4
	*/

while((estVideAlEtape(num_etape_actuelle,caseARG))&&(NonbordARG(position_actuelle_tmp)))
//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))//while((estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))&&(NonbordARG(position_depart_tmp)))
	{

	//caseARG=positionEnString(Ctmp,Ctmp);
	//position_depart_tmp=positionEnString(Ctmp,Ctmp);

	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseARG;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

	cout<<"\n TEST 860ARG dans le while estVideAlEtape(num_etape_actuelle,caseARG)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseARG= "<<caseARG<<"\n";

    position_actuelle_tmp=caseARG;
    Ctmp=Ctmp-1;Ltmp=Ltmp-1;
	caseARG=positionEnString(Ctmp,Ltmp);

//cout<<"\n TEST 868ARG toujours dans le while vide************  Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et  caseARG= "<<caseARG<<"\n";


	}//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

/*	position_actuelle_tmp = e3 et caseARG aut f4 */


//==============================

//cout<<"\n TEST 883ARG pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape(num_etape_actuelle,nom_case_destination) :";
cout<<"\n  pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape("<<num_etape_actuelle<<","<<caseARG<<") :";
cout<<"\n ===";
cout<< QuelPieceAtelCaseAtelEtape(num_etape_actuelle,caseARG);
cout<<"===\n";
cout<<"\n";

//====================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseARG)	)//bool estpriseParPieceCouleurOpposee(int numero_etape,string pieceActuelle,string nom_case_destination)
		{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseARG;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

		//	cout<<"\n ************ TEST 878ARG dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuellere_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseARG= \n  est "<<caseARG<<"\n";

 position_actuelle_tmp=caseARG;
    		}//if((estpriseParPieceCouleurOpposee(num_etape_actuelle,position_depart,caseARG)	)

}//if(NonbordARG(position_actuelle_tmp))
//=============== fin de fou dame ARG

//============= fou ARD
//cout<<"\n=============================================";
//cout<<"\n================ debut de la partie  fou ARD ";
position_actuelle_tmp=position_depart;;//recentrer sur la case choisi avant de calculer les cases autorisés
Ctmp=C;Ltmp=L;//pour le calcul du prochain ARD
cout<<"\n toujours dans la partie ARD position_actuelle_tmp = "<<position_actuelle_tmp<<" et Ctmp ="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";

if(NonbordARD(position_actuelle_tmp))
	{
	Ctmp=Ctmp+1;Ltmp=Ltmp-1;
	//cout<<"\n TEST 845  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";
	caseARD=positionEnString(Ctmp,Ltmp);
    //position_ARD_tmp=positionEnString(Ctmp,Ltmp);
//	cout<<"\n ************ TEST 851ARD - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et caseARD aut "<<caseARD<<"\n";

	/*
	position_actuelle_tmp = e3 et caseARD aut f4
	*/

while((estVideAlEtape(num_etape_actuelle,caseARD))&&(NonbordARD(position_actuelle_tmp)))
//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))//while((estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))&&(NonbordARD(position_depart_tmp)))
	{

	//caseARD=positionEnString(Ctmp,Ctmp);
	//position_depart_tmp=positionEnString(Ctmp,Ctmp);

	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseARD;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

	//cout<<"\n TEST 860ARD dans le while estVideAlEtape(num_etape_actuelle,caseARD)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseARD= "<<caseARD<<"\n";

    position_actuelle_tmp=caseARD;
    Ctmp=Ctmp+1;Ltmp=Ltmp-1;
	caseARD=positionEnString(Ctmp,Ltmp);

//cout<<"\n TEST 868ARD toujours dans le while vide************  Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et  caseARD= "<<caseARD<<"\n";


	}//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

/*	position_actuelle_tmp = e3 et caseARD aut f4 */


//==============================

//cout<<"\n TEST 883ARD pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape(num_etape_actuelle,nom_case_destination) :";
cout<<"\n  pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape("<<num_etape_actuelle<<","<<caseARD<<") :";
cout<<"\n ===";
cout<< QuelPieceAtelCaseAtelEtape(num_etape_actuelle,caseARD);
cout<<"===\n";
cout<<"\n";

//====================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseARD)	)//bool estpriseParPieceCouleurOpposee(int numero_etape,string pieceActuelle,string nom_case_destination)
		{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseARD;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

	//		cout<<"\n ************ TEST 878ARD dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuellere_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseARD= \n  est "<<caseARD<<"\n";

 position_actuelle_tmp=caseARD;
    		}//if((estpriseParPieceCouleurOpposee(num_etape_actuelle,position_depart,caseARD)	)

}//if(NonbordARD(position_actuelle_tmp))
//=============== fin de fou dame ARD


}//if type == fou ou dame


	//========================================================

//==================================================
if((type_piece=="tour")||(type_piece=="dame"))
{
Ctmp=C;Ltmp=L;
//cout<<"\n TEST tour devant 840  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";
//position_actuelle_tmp=position_depart;
//position_actuelle_tmp=nom_piece_a_deplacer;
position_actuelle_tmp=position_depart;
if(NonbordHaut(position_actuelle_tmp))
	{
	Ctmp=Ctmp;Ltmp=Ltmp+1;
	//cout<<"\n TEST tour devant 845  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";
	caseAVHaut=positionEnString(Ctmp,Ltmp);
  //  cout<<"\n ************ TEST tour devant 851  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et caseAVHaut vaut "<<caseAVHaut<<"\n";

	/*
	position_actuelle_tmp = e3 et caseAVHaut aut f4
	*/

while((estVideAlEtape(num_etape_actuelle,caseAVHaut))&&(NonbordHaut(position_actuelle_tmp)))
//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))//while((estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))&&(NonbordHaut(position_depart_tmp)))
	{

	//caseAVHaut=positionEnString(Ctmp,Ctmp);
	//position_depart_tmp=positionEnString(Ctmp,Ctmp);

	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseAVHaut;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

	//cout<<"\n TEST tour devant 860 avant haut dans le while estVideAlEtape(num_etape_actuelle,caseAVHaut)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseAVHaut= "<<caseAVHaut<<"\n";

    position_actuelle_tmp=caseAVHaut;
    Ctmp=Ctmp;Ltmp=Ltmp+1;
	caseAVHaut=positionEnString(Ctmp,Ltmp);

//cout<<"\n TEST tour devant 868  toujours dans le while vide************  Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et  caseAVHaut= "<<caseAVHaut<<"\n";


	}//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

/*	position_actuelle_tmp = e3 et caseAVHaut aut f4 */


//==============================

//cout<<"\n TEST tour devant 883 pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape(num_etape_actuelle,nom_case_destination) :";
cout<<"\n  pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape("<<num_etape_actuelle<<","<<caseAVHaut<<") :";
cout<<"\n ===";
cout<< QuelPieceAtelCaseAtelEtape(num_etape_actuelle,caseAVHaut);
cout<<"===\n";
cout<<"\n";

//====================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseAVHaut)	)//bool estpriseParPieceCouleurOpposee(int numero_etape,string pieceActuelle,string nom_case_destination)
		{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseAVHaut;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

			//cout<<"\n ************ TEST tour devant tour devant 878 dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseAVHaut= \n  est "<<caseAVHaut<<"\n";

 position_actuelle_tmp=caseAVHaut;
    		}//if((estpriseParPieceCouleurOpposee(num_etape_actuelle,position_depart,caseAVHaut)	)

}//if(NonbordHaut(position_actuelle_tmp))


//================== fin de  tour ou dame mouvement vertical vers le haut
//==================================================



//==========================================================

// tour ou dame mouvement verticale vers le bas
Ctmp=C;Ltmp=L;
//cout<<"\n TEST tour derriere 840  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";
//position_actuelle_tmp=position_depart;
//position_actuelle_tmp=nom_piece_a_deplacer;
position_actuelle_tmp=position_depart;
if(NonbordBas(position_actuelle_tmp))
	{
	Ctmp=Ctmp;Ltmp=Ltmp-1;
//	cout<<"\n TEST tour derriere 845  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";
	caseARBas=positionEnString(Ctmp,Ltmp);
//    cout<<"\n ************ TEST tour derriere 851  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et caseARBas vaut "<<caseARBas<<"\n";

	/*
	position_actuelle_tmp = e3 et caseARBas aut f4
	*/

while((estVideAlEtape(num_etape_actuelle,caseARBas))&&(NonbordBas(position_actuelle_tmp)))
//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))//while((estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))&&(NonbordBas(position_depart_tmp)))
	{

	//caseARBas=positionEnString(Ctmp,Ctmp);
	//position_depart_tmp=positionEnString(Ctmp,Ctmp);

	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseARBas;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

//	cout<<"\n TEST tour derriere 860 dans le while estVideAlEtape(num_etape_actuelle,caseARBas)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseARBas= "<<caseARBas<<"\n";

    position_actuelle_tmp=caseARBas;
    Ctmp=Ctmp;Ltmp=Ltmp-1;
	caseARBas=positionEnString(Ctmp,Ltmp);

//cout<<"\n TEST tour derriere 868  toujours dans le while vide************  Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et  caseARBas= "<<caseARBas<<"\n";


	}//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

/*	position_actuelle_tmp = e3 et caseARBas aut f4 */


//==============================

//cout<<"\n TEST tour derriere 883 pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape(num_etape_actuelle,nom_case_destination) :";
cout<<"\n  pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape("<<num_etape_actuelle<<","<<caseARBas<<") :";
cout<<"\n ===";
cout<< QuelPieceAtelCaseAtelEtape(num_etape_actuelle,caseARBas);
cout<<"===\n";
cout<<"\n";

//====================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseARBas)	)//bool estpriseParPieceCouleurOpposee(int numero_etape,string pieceActuelle,string nom_case_destination)
		{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseARBas;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

	//		cout<<"\n ************ TEST tour derriere tour derriere 878 dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseARBas= \n  est "<<caseARBas<<"\n";

 position_actuelle_tmp=caseARBas;
    		}//if((estpriseParPieceCouleurOpposee(num_etape_actuelle,position_depart,caseARBas)	)

}//if(NonbordBas(position_actuelle_tmp))

//================================================================


//====================================



//======================================
//Tour ou dame deplacement horizontal vers la droite
Ctmp=C;Ltmp=L;
//cout<<"\n TEST tour vers la droite  840  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";
//position_actuelle_tmp=position_depart;
//position_actuelle_tmp=nom_piece_a_deplacer;
position_actuelle_tmp=position_depart;
if(NonbordDroit(position_actuelle_tmp))
	{
	Ctmp=Ctmp+1;Ltmp=Ltmp;
//	cout<<"\n TEST tour vers la droite  845  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";
	caseColExtrDroite=positionEnString(Ctmp,Ltmp);
//    cout<<"\n ************ TEST tour vers la droite  851  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et caseColExtrDroite vaut "<<caseColExtrDroite<<"\n";

	/*
	position_actuelle_tmp = e3 et caseColExtrDroite aut f4
	*/

while((estVideAlEtape(num_etape_actuelle,caseColExtrDroite))&&(NonbordDroit(position_actuelle_tmp)))
//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))//while((estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))&&(NonbordDroit(position_depart_tmp)))
	{

	//caseColExtrDroite=positionEnString(Ctmp,Ctmp);
	//position_depart_tmp=positionEnString(Ctmp,Ctmp);

	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseColExtrDroite;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

//	cout<<"\n TEST tour vers la droite  860 avant haut dans le while estVideAlEtape(num_etape_actuelle,caseColExtrDroite)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseColExtrDroite= "<<caseColExtrDroite<<"\n";

    position_actuelle_tmp=caseColExtrDroite;
    Ctmp=Ctmp+1;Ltmp=Ltmp;
	caseColExtrDroite=positionEnString(Ctmp,Ltmp);

//cout<<"\n TEST tour vers la droite  868  toujours dans le while vide************  Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et  caseColExtrDroite= "<<caseColExtrDroite<<"\n";


	}//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

/*	position_actuelle_tmp = e3 et caseColExtrDroite aut f4 */


//==============================

//cout<<"\n TEST tour vers la droite  883 pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape(num_etape_actuelle,nom_case_destination) :";
cout<<"\n  pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape("<<num_etape_actuelle<<","<<caseColExtrDroite<<") :";
cout<<"\n ===";
cout<< QuelPieceAtelCaseAtelEtape(num_etape_actuelle,caseColExtrDroite);
cout<<"===\n";
cout<<"\n";

//====================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseColExtrDroite)	)//bool estpriseParPieceCouleurOpposee(int numero_etape,string pieceActuelle,string nom_case_destination)
		{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseColExtrDroite;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

		//	cout<<"\n ************ TEST tour vers la droite  tour vers la droite  878 dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseColExtrDroite= \n  est "<<caseColExtrDroite<<"\n";

 position_actuelle_tmp=caseColExtrDroite;
    		}//if((estpriseParPieceCouleurOpposee(num_etape_actuelle,position_depart,caseColExtrDroite)	)

}//if(NonbordDroit(position_actuelle_tmp))


//================== fin de  tour ou dame mouvement horizontal vers la droite
//==================================================



//==========================================================


//deplacement horzontal vers la gauche
//=================================


//=================================
Ctmp=C;Ltmp=L;
//cout<<"\n TEST 840  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";
//position_actuelle_tmp=position_depart;
//position_actuelle_tmp=nom_piece_a_deplacer;
position_actuelle_tmp=position_depart;
if(NonbordGauche(position_actuelle_tmp))
	{
	Ctmp=Ctmp-1;Ltmp=Ltmp;
	//cout<<"\n TEST 845  vers la Gauche horizontale  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<"\n";
	caseColExtrGauche=positionEnString(Ctmp,Ltmp);
    //position_AVD_tmp=positionEnString(Ctmp,Ltmp);
	//cout<<"\n ************ TEST 851  vers la Gauche horizontale - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et caseColExtrGauche aut "<<caseColExtrGauche<<"\n";

	/*
	position_actuelle_tmp = e3 et caseColExtrGauche aut f4
	*/

while((estVideAlEtape(num_etape_actuelle,caseColExtrGauche))&&(NonbordGauche(position_actuelle_tmp)))
//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))//while((estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))&&(NonbordGauche(position_depart_tmp)))
	{

	//caseColExtrGauche=positionEnString(Ctmp,Ctmp);
	//position_depart_tmp=positionEnString(Ctmp,Ctmp);

	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseColExtrGauche;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

	//cout<<"\n TEST 860 vers la Gauche horizontale  dans le while estVideAlEtape(num_etape_actuelle,caseColExtrGauche)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseColExtrGauche= "<<caseColExtrGauche<<"\n";

    position_actuelle_tmp=caseColExtrGauche;
    Ctmp=Ctmp-1;Ltmp=Ltmp;
	caseColExtrGauche=positionEnString(Ctmp,Ltmp);

//cout<<"\n TEST 868 vers la Gauche horizontale  toujours dans le while vide************  Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et  caseColExtrGauche= "<<caseColExtrGauche<<"\n";


	}//while(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

/*	position_actuelle_tmp = e3 et caseColExtrGauche aut f4 */


//==============================

//cout<<"\n TEST 883 vers la Gauche horizontale  pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape(num_etape_actuelle,nom_case_destination) :";
cout<<"\n  pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape("<<num_etape_actuelle<<","<<caseColExtrGauche<<") :";
cout<<"\n ===";
cout<< QuelPieceAtelCaseAtelEtape(num_etape_actuelle,caseColExtrGauche);
cout<<"===\n";
cout<<"\n";

//====================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseColExtrGauche)	)//bool estpriseParPieceCouleurOpposee(int numero_etape,string pieceActuelle,string nom_case_destination)
		{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseColExtrGauche;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

		//	cout<<"\n ************ TEST 878 vers la Gauche horizontale dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseColExtrGauche= \n  est "<<caseColExtrGauche<<"\n";

 position_actuelle_tmp=caseColExtrGauche;
    		}//if((estpriseParPieceCouleurOpposee(num_etape_actuelle,position_depart,caseColExtrGauche)	)

}//if(NonbordGauche(position_actuelle_tmp))

//fin de deplacement horzontal vers la gauche
//=================================


//=================================





}//if((type_piece=="tour")||(type_piece=="dame"))


//========================================================





//====
/*deplacement du roi
*/

if(type_piece=="roi")
{
//=============  roi AVD

Ctmp=C;Ltmp=L;
position_actuelle_tmp=position_depart;
if(NonbordAvd(position_actuelle_tmp))
	{
	Ctmp=Ctmp+1;Ltmp=Ltmp+1;
	caseAVD=positionEnString(Ctmp,Ltmp);
if((estVideAlEtape(num_etape_actuelle,caseAVD))&&(NonbordAvd(position_actuelle_tmp)))
//if
	{
	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseAVD;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

//	cout<<"\n TEST 860 roi dans le if estVideAlEtape(num_etape_actuelle,caseAVD)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseAVD= "<<caseAVD<<"\n";

    position_actuelle_tmp=caseAVD;
    Ctmp=Ctmp+1;Ltmp=Ltmp+1;
	caseAVD=positionEnString(Ctmp,Ltmp);
	}//if(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..
cout<<"\n  pieceDansCaseDestination=QuelPieceAtelCaseAtelEtape("<<num_etape_actuelle<<","<<caseAVD<<") :";
cout<<"\n ===";
cout<< QuelPieceAtelCaseAtelEtape(num_etape_actuelle,caseAVD);
cout<<"===\n";
cout<<"\n";

//====================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseAVD)	)
		{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseAVD;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

		//	cout<<"\n ************ TEST roi 878 dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseAVD= \n  est "<<caseAVD<<"\n";

 position_actuelle_tmp=caseAVD;
    		}//if((estpriseParPieceCouleurOpposee
}//if(NonbordAvd(position_actuelle_tmp))

//=============  Avg

position_actuelle_tmp=position_depart;
Ctmp=C;Ltmp=L;//pour le calcul du prochain AVG

if(NonbordAvg(position_actuelle_tmp))
	{
	Ctmp=Ctmp-1;Ltmp=Ltmp+1;
	caseAVG=positionEnString(Ctmp,Ltmp);
    //position_Avg_tmp=positionEnString(Ctmp,Ltmp);


if((estVideAlEtape(num_etape_actuelle,caseAVG))&&(NonbordAvg(position_actuelle_tmp)))
//if
	{
	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseAVG;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;
    position_actuelle_tmp=caseAVG;
    Ctmp=Ctmp-1;Ltmp=Ltmp+1;
	caseAVG=positionEnString(Ctmp,Ltmp);

	}//if(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

//==============================


//====================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseAVG)	)
	{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseAVG;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

		//	cout<<"\n ************ TEST roi 878avg dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuellere_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseAVG= \n  est "<<caseAVG<<"\n";

 position_actuelle_tmp=caseAVG;
    		}//if((estpriseParPieceCouleurOpposee(num_etape_actuelle,position_depart,caseAVG)	)

}//if(NonbordAvg(position_actuelle_tmp))


//============================
//============= roi ARG
position_actuelle_tmp=position_depart;
Ctmp=C;Ltmp=L;//pour le calcul du prochain ARG

if(NonbordARG(position_actuelle_tmp))
	{
	Ctmp=Ctmp-1;Ltmp=Ltmp-1;
	caseARG=positionEnString(Ctmp,Ltmp);

if((estVideAlEtape(num_etape_actuelle,caseARG))&&(NonbordARG(position_actuelle_tmp)))
//if
	{
	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseARG;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

	//cout<<"\n TEST 860 roi ARG dans le if estVideAlEtape(num_etape_actuelle,caseARG)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseARG= "<<caseARG<<"\n";

    position_actuelle_tmp=caseARG;
    Ctmp=Ctmp-1;Ltmp=Ltmp-1;
	caseARG=positionEnString(Ctmp,Ltmp);

	}//if(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseARG)	)
	{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseARG;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

		//	cout<<"\n ************ TEST roi 878ARG dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuellere_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseARG= \n  est "<<caseARG<<"\n";

 position_actuelle_tmp=caseARG;
    		}//if((estpriseParPieceCouleurOpposee

}//if(NonbordARG(position_actuelle_tmp))
//=============== fin de roi   ARG

//=============  roi ARD
position_actuelle_tmp=position_depart;;//recentrer sur la case choisi avant de calculer les cases autorisés
Ctmp=C;Ltmp=L;//pour le calcul du prochain ARD

if(NonbordARD(position_actuelle_tmp))
	{
	Ctmp=Ctmp+1;Ltmp=Ltmp-1;
	caseARD=positionEnString(Ctmp,Ltmp);

if((estVideAlEtape(num_etape_actuelle,caseARD))&&(NonbordARD(position_actuelle_tmp)))
	{

	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseARD;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

	//cout<<"\n TEST 860 roi ARD dans le if estVideAlEtape(num_etape_actuelle,caseARD)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseARD= "<<caseARD<<"\n";

    position_actuelle_tmp=caseARD;
    Ctmp=Ctmp+1;Ltmp=Ltmp-1;
	caseARD=positionEnString(Ctmp,Ltmp);
	}//if(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseARD)	)//bool estpriseParPieceCouleurOpposee
		{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseARD;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

		//	cout<<"\n ************ TEST roi 878ARD dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuellere_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseARD= \n  est "<<caseARD<<"\n";

 position_actuelle_tmp=caseARD;
    		}//if((estpriseParPieceCouleurOpposee
}//if(NonbordARD(position_actuelle_tmp))
//=============== fin de roi ARD

//==================================================
//==============roi Vertical Vers le haut
Ctmp=C;Ltmp=L;
position_actuelle_tmp=position_depart;
if(NonbordHaut(position_actuelle_tmp))
	{
	Ctmp=Ctmp;Ltmp=Ltmp+1;

	caseAVHaut=positionEnString(Ctmp,Ltmp);

if((estVideAlEtape(num_etape_actuelle,caseAVHaut))&&(NonbordHaut(position_actuelle_tmp)))//if(estVideAlEtapeColLig
	{
	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseAVHaut;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

	//cout<<"\n TEST roi devant 860 avant haut dans le if estVideAlEtape(num_etape_actuelle,caseAVHaut)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseAVHaut= "<<caseAVHaut<<"\n";

    position_actuelle_tmp=caseAVHaut;
    Ctmp=Ctmp;Ltmp=Ltmp+1;
	caseAVHaut=positionEnString(Ctmp,Ltmp);
	}//if(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..
//====================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseAVHaut)	)//bool estpriseParPieceCouleurOpposee
		{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseAVHaut;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

		//	cout<<"\n ************ TEST roi devant roi devant 878 dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseAVHaut= \n  est "<<caseAVHaut<<"\n";

 position_actuelle_tmp=caseAVHaut;
    		}//if((estpriseParPieceCouleurOpposee

}//if(NonbordHaut(position_actuelle_tmp))

//================== fin de  roi  mouvement vertical vers le haut
//==================================================

// roi mouvement verticale vers le bas
Ctmp=C;Ltmp=L;
position_actuelle_tmp=position_depart;
if(NonbordBas(position_actuelle_tmp))
	{
	Ctmp=Ctmp;Ltmp=Ltmp-1;
	//cout<<"\n TEST roi derriere 845  - Ctmp="<<C*tmp<<" et Ltmp ="<<Ltmp<<"\n";0
	caseARBas=positionEnString(Ctmp,Ltmp);

if((estVideAlEtape(num_etape_actuelle,caseARBas))&&(NonbordBas(position_actuelle_tmp)))
	{

	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseARBas;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

	//cout<<"\n TEST roi derriere 860 dans le if estVideAlEtape(num_etape_actuelle,caseARBas)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseARBas= "<<caseARBas<<"\n";

    position_actuelle_tmp=caseARBas;
    Ctmp=Ctmp;Ltmp=Ltmp-1;
	caseARBas=positionEnString(Ctmp,Ltmp);

	}//if(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

//==============================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseARBas)	){
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseARBas;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

		//	cout<<"\n ************ TEST roi derriere roi derriere 878 dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseARBas= \n  est "<<caseARBas<<"\n";

 position_actuelle_tmp=caseARBas;
    		}//if((estpriseParPieceCouleurOpposee(num_etape_actuelle,position_depart,caseARBas)	)

}//if(NonbordBas(position_actuelle_tmp))

//======================================
//roi  deplacement horizontal vers la droite
Ctmp=C;Ltmp=L;
position_actuelle_tmp=position_depart;
if(NonbordDroit(position_actuelle_tmp))
	{
	Ctmp=Ctmp+1;Ltmp=Ltmp;
	caseColExtrDroite=positionEnString(Ctmp,Ltmp);

if((estVideAlEtape(num_etape_actuelle,caseColExtrDroite))&&(NonbordDroit(position_actuelle_tmp)))
	{

	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseColExtrDroite;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

	//cout<<"\n TEST roi vers la droite  860 avant haut dans le if estVideAlEtape(num_etape_actuelle,caseColExtrDroite)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseColExtrDroite= "<<caseColExtrDroite<<"\n";

    position_actuelle_tmp=caseColExtrDroite;
    Ctmp=Ctmp+1;Ltmp=Ltmp;
	caseColExtrDroite=positionEnString(Ctmp,Ltmp);


	}//if(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

//==============================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseColExtrDroite)	)//bool estpriseParPieceCouleurOpposee(int numero_etape,string pieceActuelle,string nom_case_destination)
		{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseColExtrDroite;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

		//	cout<<"\n ************ TEST roi vers la droite  roi vers la droite  878 dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseColExtrDroite= \n  est "<<caseColExtrDroite<<"\n";

 position_actuelle_tmp=caseColExtrDroite;
    		}//if((estpriseParPieceCouleurOpposee
}//if(NonbordDroit(position_actuelle_tmp))

//================== fin de  roi mouvement horizontal vers la droite
//==========================================================

//deplacement horzontal vers la gauche

//=================================
Ctmp=C;Ltmp=L;
position_actuelle_tmp=position_depart;
if(NonbordGauche(position_actuelle_tmp))
	{
	Ctmp=Ctmp-1;Ltmp=Ltmp;
	caseColExtrGauche=positionEnString(Ctmp,Ltmp);
    //position_AVD_tmp=positionEnString(Ctmp,Ltmp);

if((estVideAlEtape(num_etape_actuelle,caseColExtrGauche))&&(NonbordGauche(position_actuelle_tmp)))
//if(estVideAlEtapeColLig
{

	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseColExtrGauche;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

	//cout<<"\n TEST 860 roi vers la Gauche horizontale  dans le if estVideAlEtape(num_etape_actuelle,caseColExtrGauche)************   - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" Autorisee :  caseColExtrGauche= "<<caseColExtrGauche<<"\n";

    position_actuelle_tmp=caseColExtrGauche;
    Ctmp=Ctmp-1;Ltmp=Ltmp;
	caseColExtrGauche=positionEnString(Ctmp,Ltmp);


	}//if(estVideAlEtapeColLig(num_etape_actuelle,Ctmp,Ltmp))..

//====================

    if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseColExtrGauche)	)//bool estpriseParPieceCouleurOpposee
	{
		tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseColExtrGauche;
		nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;

		//	cout<<"\n ************ TEST roi 878 vers la Gauche horizontale dans if est priseparpiecedecouleuroppose  - Ctmp="<<Ctmp<<" et Ltmp ="<<Ltmp<<" et position_actuelle_tmp = "<<position_actuelle_tmp<<" et nouvelle case AUTORISEE :  caseColExtrGauche= \n  est "<<caseColExtrGauche<<"\n";

 position_actuelle_tmp=caseColExtrGauche;
    		}//if((estpriseParPieceCouleurOpposee(num_etape_actuelle,position_depart,caseColExtrGauche)	)

}//if(NonbordGauche(position_actuelle_tmp))

//fin de deplacement horzontal vers la gauche
//=================================


//=================================

}//if piece = roi


//fin du deplacement du roi
//====================================================

//===================================/*--------------------*/

//=================================
// Deplacement du cavalier


if(type_piece=="cavalier")
{
for(int i=1;i<9;i++)
//for(int numcas=1;numcas<9;numcas++)//pour chacun des 8 deplacements possible du cavalier
{
//cout<<"\ni vaut "<<i<<endl;

Ctmp=C;Ltmp=L;
position_actuelle_tmp=position_depart;


if(i==1){Ctmp=Ctmp+1;Ltmp=Ltmp+2;}
if(i==2){Ctmp=Ctmp+2;Ltmp=Ltmp+1;}
if(i==3){Ctmp=Ctmp+1;Ltmp=Ltmp-2;}
if(i==4){Ctmp=Ctmp+2;Ltmp=Ltmp-1;}
if(i==5){Ctmp=Ctmp-1;Ltmp=Ltmp+2;}
if(i==6){Ctmp=Ctmp-2;Ltmp=Ltmp+1;}
if(i==7){Ctmp=Ctmp-1;Ltmp=Ltmp-2;}
if(i==8){Ctmp=Ctmp-2;Ltmp=Ltmp-1;}

if(nombordPourCavalier(i,Ctmp,Ltmp))//(numcas,Ctmp,Ltmp)
{
caseDeplCaval=positionEnString(Ctmp,Ltmp);
//cout<<"\n1954     i="<<i<<" Ctmp vaut "<<Ctmp<<" et Ltmp vaut "<<Ltmp<<" et caseDeplCaval vaut "<<caseDeplCaval<<endl;


if(estVideAlEtape(num_etape_actuelle,caseDeplCaval))
{
	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseDeplCaval;
    nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;
}//if(estVideAlEtapeColLig(num_etape_actuelle,,Lmp))..
else
{
cout<<"\n a l etape actuelle "<<num_etape_actuelle<< " << la case caseDeplCaval "<<caseDeplCaval<<" n est pas vide";
}
if(estpriseParPieceCouleurOpposee(num_etape_actuelle,nom_piece_a_deplacer,caseDeplCaval)	)//bool estpriseParPieceCouleurOpposee
	{
	tab_str_pos_autorisees[nbreDeCasesAutorisees]=caseDeplCaval;
	nbreDeCasesAutorisees=nbreDeCasesAutorisees+1;
}//if((estpriseParPieceCouleurOpposee
else
{
cout<<"\n la case caseDeplCaval "<<caseDeplCaval<<" n est pas prise par une case de couleur opposee"<<endl;
}//else


}//if(nombordPourCavalier)
}//for int i
}//if type_piece=="cavalier"




//fin de deplacement cavalier
//=====================================
	/*
	C colonne
	L ligne


	ATTENTION deplacement autorisé si destination vide ou occupée par adversaire

	pion  si posi depart : autorisé : si couleur B alors L+1 et L+2
	si non pos depart : L+1 si L<=7

	fou ou dame   for...  L+1 C+1 si L<=7 et C<=7 et
	              for...  L-1 C-1 si L>=1 et C>=1 (tant que non bords)
	              for...  L+1 C-1 si L<=7 et C>=1 e
			      for...L-1 C+1 si L>=1 et C<=7

	roi         	L+1 C+1 si L<=7 et C<=7
                    L+1 C-1 si L<=7 et C>=1

	tour ou dame  for... L+1 C
	                     L-1 C
						 L   C+1
						 L   C-1
    cavalier      L+1   C+2
				  L+1   C-2
				  L+2   C+1
				  L+2   C-1
				  L-1   C+2
				  L-1   C-2
				  L-2   C+1
				  L-2   C-1

	*/









cout<<"\n\n\n====================================================\n";
cout<<"\n il y a " <<	nbreDeCasesAutorisees<<" cases autorisees pour la piece "<<nom_piece_a_deplacer<<" qui est actuellement en "<<position_depart<<endl;
//cout<<"\n\n\n====================================================\n\n\n";
for(int i=0;i< nbreDeCasesAutorisees;i++)
{
	cout<<"\n "<<i<<" case autorisee : "<<tab_str_pos_autorisees[i];
	if (position_arrivee==tab_str_pos_autorisees[i])
	{autorisation_b=true;}
}//for
//cout<<"\nfin de la fonction bool deplacement autorise....===========================================";
cout<<"\n====================================================";
return autorisation_b;
}//bool  deplacementAutorise(type_piece,couleur_piece,position_depart,position_d'arrivee)


/*********************************************0 1   **************************/
//------------------------------------
void  DeplacerLaPiece(string nom_piece_origine,string position_actuelle,string position_arrivee)// ex.DeplacerLaPiece("a2","a2",saisie);
{
//Si cette fonction est appelée, c'est que le déplacement à été autorisé
//2 etapes: 1 incrementer l'etape actuelle et la derniere etape et y renseigner à la case de destination la piece en question, 2 vider la case ou etait cette piece

	cout<<"\n ===============";cout<<"\n ===============";
	cout<<"\n ===============";cout<<"\n ===============";
	cout<<"\n ===============";
/*
	cout<<"\n ====================================";
	cout<<"\n ====================================";
	cout<<"\n AVANT DEPLACEMENT  : \n";
	cout<<"\n ====================================";
	cout<<"\n ====================================";
	AfficherEchiquierParEtape();
*/
	cout<<"\n ===============";
	cout<<"\n FONCTION DeplacerLaPiece(nom de la piece d origine : "<<nom_piece_origine<<"\n position actuelle : "<<position_actuelle<<"\n position d'arrivee :"<< position_arrivee<<"         \n";

	cout<<" \n num_derniere_etape avant increment : "<<num_derniere_etape;
	num_derniere_etape=num_derniere_etape+1;
	cout<<" \n num_derniere_etape apres increment : "<<num_derniere_etape;

	//specialViderEchiquierDeTelEtape(num_derniere_etape);
	//num_piece=numpiece(nom_piece_origine);
	cout<<"\ntmp    nom_piece_origine="<<nom_piece_origine<<"\n";

clonnerEchiquierDuneEtapeVersAutreEtape(num_etape_actuelle,num_derniere_etape);
	AffecterCaseAtelEtape(num_derniere_etape,nom_piece_origine,position_arrivee);
    viderLaCaseAtelEtape(num_derniere_etape, position_actuelle);//vider la case ou etait cette piece

/*************************

Le deplacement a ete effectue, mise à jour de l'etape actuelle:
*/
num_etape_actuelle=num_derniere_etape;

/**************************/

	//void AffecterCaseAtelEtape(int etape,string pieceAmettre,string caseDeDestination)

	cout<<"\n ===============";

	string tmp="";

	tmp=ouSeTrouveTelPieceATelEtape(num_etape_actuelle,nom_piece_origine);
	//string ouSeTrouveTelPieceATelEtape(int num_etape,string nom_piece)

	cout<<"\nnum_etape_actuelle: "<<num_etape_actuelle<<"tmp = "<<tmp<<" \n";
   // viderLaCase(num_derniere_etape,position_actuelle); //A FINALISER
//	viderLaCaseAtelEtape(num_derniere_etape,position_actuelle);
	//****************AfficherEchiquierParEtape();

/*
	cout<<"\n ====================================";
	cout<<"\n ====================================";
	cout<<"\n ET APRES DEPLACEMENT  : \n";
	cout<<"\n ====================================";
	cout<<"\n ====================================";

AfficherEchiquierParEtape();
*/
	cout<<"\n FIN DE LA FONCTION DeplacerLaPiece("<<nom_piece_origine<<","<<position_actuelle<<","<< position_arrivee<<")\n";
	cout<<"\n ===============";
	cout<<"\n ===============";
}//DeplacerLaPiece(string nom_piece_origine,string position_actuelle,string position_arrivee)

/*********************************************0 1   **************************/
void deplacerUnePieceSeule(int choix){
string position_temporaire_piece="";

string couleur="";
string type="";
string piecechoisie="";

int num_piecechoisie;
string saisietmp="";//pour cin juste pour attendre un appui sur entrée (le temps de lire le message precedent)
//vider_Echiquier();


if(choix!=99)
{
	piecechoisie=nom_piece(choix);
	cout<<"\n\n La piece choisi est  "<<piecechoisie<<"\n\n";
}




/*
deplacerUnePieceSeule(99) :  Menu de depart du choix de la couleur de piece a deplacer av
deplacerUnePieceSeule(0) :  pion blanc a2
deplacerUnePieceSeule(1) :  pion blanc b2
deplacerUnePieceSeule(2) :  pion blanc c2
deplacerUnePieceSeule(3) :  pion blanc d2
deplacerUnePieceSeule(4) :  pion blanc e2
deplacerUnePieceSeule(5) :  pion blanc f2
deplacerUnePieceSeule(6) :  pion blanc g2
deplacerUnePieceSeule(7) :  pion blanc h2
...
*/
/*

/*--------------------------------------------------*/
/*--------------------------------------------------*/

if (choix==99)  // menu general de "deplacer une piece seule dans l'echiquier"
{
cout << "\n deplacer une piece seule dans l'echiquier" <<endl;
cout << "\nChoisissez la couleur de la piece et validez par ENTER\n1  blancs\n2  Noirs\nScore" <<endl;
cin >> saisie ;
cout << "\nVous avez saisie " << saisie << endl;

/*
string str = saisie; //"majuscules";
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    saisie=str;
    cout << "saisie en majuscule : " << saisie<<endl;
*/
while((saisie!="1")&&(saisie!="2")&&(saisie!="s"))
{
cout <<"\n "<<saisie <<" n ai pas une entree valide veuillez choisir soit  1 soit 2 ou s pour le score "<< endl;
cout << "\n deplacer une piece seule dans l'echiquier" <<endl;
cout << "\nChoisissez la couleur de la piece et validez par ENTER\n1  blancs\n2  Noirs\n" <<endl;
cin >>saisie ;
/*string str = saisie; //"majuscules";
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    saisie=str;
    cout << "saisie en majuscule : " << saisie<<endl;
*/
}
 if ((saisie=="1")||(saisie=="2")||(saisie=="s")) //1 choix pieces blanches et 2 pieces noires
 {
	 //==================== Reinit variables pour score



	 score=0;vider_Echiquier();




	 //================================================
	 if(saisie=="s")
{
afficherScore();

}

	if(saisie=="1")
	{
	cout << "\n\n deplacer une piece blanche seule dans l'echiquier";
	AfficherListePiecesDorigineParCriteres("tous","blanc");
	}


	if(saisie=="2")
	{
	cout << "\n\n deplacer une piece noir seule dans l'echiquier";
	AfficherListePiecesDorigineParCriteres("tous","noir");
	}
	//(type,couleur)
	/*
	cout << "0  pion blanc a2\n1  pion blanc b2\n2  pion blanc c2\n3  pion blanc d2\n4  pion blanc e2\n5  pion blanc f2\n6  pion blanc g2\n7  pion blanc h2\n8  tour blanche Rh1\n9 cavalier blanc  Ng1\n10 fou blanc Bf1 de cases blanches\n11 roi blanc Ke1\n12 dame blanche Qd1\n13 fou blanc Bc1 de cases noir\n14 cavalier blanc Nb1\n15 tour blanche Ra1\n" <<endl;
    */
	cout<<"\nsaisisez votre choix ex.  0 pour le pion blanc a2..." <<endl;


	cin >> saisie ;
	cout << "\nVous avez saisie " << saisie << endl;

int saisie_i=string_vers_int(saisie);
deplacerUnePieceSeule(saisie_i);/* if (saisie=="1") {deplacerUnePieceSeule(1);}*/

 }//if (saisie=="1")	choix : "pieces blanches"

}//if (choix==99) dans  void deplacerUnePieceSeule(int choix)



// fin de if (choix==99)
/*--------------------------------------------------*/
/*--------------------------------------------------*/
if(choix!=99)
{
cout<< "\n choix="<<choix;
type=type_piecedorigineI(choix);//string type_piecedorigineI(int numpiece)
couleur=couleur_piecedorigineI(choix);//couleur_piecedorigineI(int numpiece)
cout<< "\n donc type = "<<type<<" et couleur = "<<couleur ;

//if (choix==0)  //si choix deplacement d une piece blanche seule et piece choisi pion blanc a2
/*if (choix==0)  *///si choix deplacement d une piece blanche seule et piece choisi pion blanc a2
//{
cout << "\n\n1 deplacer une piece "<<couleur<<" seule dans l'echiquier \n "<<type<<" "<<couleur<< " "<<piecechoisie <<endl;
/*cout << "\n\n1 deplacer une piece blanche seule dans l'echiquier \n pion blanc a2" <<endl;	*/
cout << "\n" <<endl;


AffecterCaseAtelEtape(0,piecechoisie,piecechoisie);/*void AffecterCaseAtelEtape(int etape,string pieceAmettre,string caseDeDestination) ex  à l etape 0 mettre la piece a2 en a2 si a2 choisi
*/


/*if (saisie=="*")//grand menu d'accueil
{afficherAccueil();}*/
/*if (saisie=="p")//precedent
{deplacerUnePieceSeule(0);};//choisir la piece a deplacer en commençant par la couleur de la piece...
*/
//------------------------------------------------------
position_temporaire_piece=ouSeTrouveTelPieceATelEtape(num_etape_actuelle,piecechoisie);
//string ouSeTrouveTelPieceATelEtape(int num_etape,string nom_piece)
//cout<<"\n=====================================\n";
cout<<"\n\n\n  TMP le num_etape_actuelle est egal a "<<num_etape_actuelle;
cout<<"\n  TMP position_temporaire_piece de la piece ";
cout<<"  est "<<position_temporaire_piece;
effacerEcran();//A ENLEVER SI PHASES DE TESTS
cout<<"\nnous sommes a l'etape "<<num_etape_actuelle<<" en "<< position_temporaire_piece<<"\n";
//cout<<"\n=====================================\n";
//cout<<"\n=====================================\n";

//-------------------------------------------------------

cout << "\nchoisissez sa destination\n" <<endl;
cin >> saisie ;
//saisie=tolower(saisie);
cout << "\nVous avez saisie " << saisie << endl;
/*if(saisie=="0")
{
afficherAccueil();

}*/
if(saisie=="*")
{
	deplacerUnePieceSeule(99) ;//afficher le munu principale pour les deplacements d une piece seule dans un echiquier vide}//menu d accueil du choix de la piece a deplacer
}
cout << "\nVous avez saisie " << saisie << endl;
if(saisie=="s")
{
afficherScore();

}



type=type_piecedorigineI(choix);//string type_piecedorigineI(int numpiece)
couleur=couleur_piecedorigineI(choix);//couleur_piecedorigineI(int numpiece)
cout<< "\n donc type = "<<type<<" et couleur = "<<couleur ;


if(deplacementAutorise(piecechoisie,type,couleur,position_temporaire_piece,saisie))
//if(deplacementAutorise("pion","blanc","a2",saisie))
{
cout<<"\n Le deplacement du "<<type<<" "<<couleur<<" intialement en "<<piecechoisie<<" et actuellement en "<<position_temporaire_piece<<" vers "<<saisie<<" est autorisé ";
score=score+1;
cout<<"\nscore= "<<score;
/*cout<<"\n Le deplacement du pion blanc a2 vers "<<saisie<<" est autorisé ";*/
DeplacerLaPiece(piecechoisie,position_temporaire_piece,saisie);
//DeplacerLaPiece("a2",position_temporaire_piece,saisie);
//DeplacerLaPiece("a2","a2",saisie);
deplacerUnePieceSeule(choix);//continuer a deplacer la même piece seule

}//if
else
{
	cout<<"\n Le deplacement du "<<type<<" "<<couleur<<" intialement en "<<piecechoisie<<" et actuellement en "<<position_temporaire_piece<<" vers "<<saisie<<" n'est pas autorisé \n";

//pause();//cin>>saisietmp;//attendre appui sur entree
	/*
	cout<<"\n Le deplacement du pion blanc a2 vers "<<saisie<<" n est pas autorisé ";*/
nbre_de_test=nbre_de_test+1;
cout<<"\n2322 nbre_de_test="<<nbre_de_test<<" et score= "<<score;
num_piecechoisie=numpiece(piecechoisie);
cout<<"\n piecechoisie= "<<piecechoisie<<" et num_piecechoisie= "<<num_piecechoisie<<"\n";
//score=score+1;
tab_score[nbre_de_test][num_piecechoisie]=score;
score=0;

deplacerUnePieceSeule(99) ;//afficher le munu principale pour les deplacements d une piece seule dans un echiquier vide
}//	else
//}//if (i==1) dans  void deplacerUnePieceSeule(int i)

cout<<"\n\n";
}//if choix different de 99
}//void deplacerUnePieceSeule(int i)



void deplacerToutesLesPieces(){
cout << "2 2384 faire deplacer toutes les pieces dans un echiquier" <<endl;
pause();
}//void deplacerToutesLesPieces()

/*********************************************0 3   **************************/
void OuSeTrouveTelPiece(){
string pieceAtrouver,type_piece_tmp,couleur_piece_tmp="";
string pieceAdeplacer,postionDeDepart,destination="";
string ouSeTrouveLaPiece="";
string votreReponse="";
string saisi="";

int hasard_i,nbre_caseshasardDejaUtilises=0;
cout << "3 ou se trouve tel piece suite a tel mouvement sur des parties d 'exemple" <<endl;
//pause();
initEchiquierComplet();
AfficherEchiquierParEtape();

while(saisi!="q")
{
cout<<"\nchoissez la piece à deplacer ou q pour quitter\n";
cin>>pieceAdeplacer;
saisi=pieceAdeplacer;
cout<<"\nchoissez la position de depart\n";
cin>>postionDeDepart;
//===================================
//deplacement de la piece :

type_piece_tmp=type_piecedorigineS(pieceAdeplacer);
couleur_piece_tmp=couleur_piecedorigineS(pieceAdeplacer);
ouSeTrouveLaPiece=ouSeTrouveTelPieceATelEtape(num_etape_actuelle,pieceAdeplacer);
//cout<<"\n TEST postionDeDepart="<<postionDeDepart<<"et ouSeTrouveLaPiece="<<ouSeTrouveLaPiece;
if(postionDeDepart==ouSeTrouveLaPiece)
{
cout<<"\nchoissez la destination\n";
cin>>destination;

	if(deplacementAutorise(pieceAdeplacer,type_piece_tmp,couleur_piece_tmp,postionDeDepart,destination)
	)/*
	( deplacementAutorise(string nom_piece_a_deplacer,string type_piece,string couleur_piece,string position_depart,string position_arrivee)
	)*/
	{
	DeplacerLaPiece(pieceAdeplacer,postionDeDepart,destination);// ex.DeplacerLaPiece("a2","a2",saisie);
	}//if deplacementAutorise
	cout<<"\nsuite a deplacerlapiece num_etape_actuelle vaut"<<num_etape_actuelle<<"\n";


AfficherEchiquierParEtape();
//questionnement sur la position d'une piece au hasard:
//====================================
/*hasard_i = rand() % 31 + 1;//val entre 0 et 31
pieceAtrouver=tab_nom_piecedorigine[hasard_i];
cout<<"\n hasard_i= "<<hasard_i<<" et pieceAtrouver= "<<pieceAtrouver;
*/
/*
hasard_i = rand() % 31 + 1;//val entre 0 et 31
pieceAtrouver=tab_nom_piecedorigine[hasard_i];
cout<<"\n hasard_i= "<<hasard_i<<" et pieceAtrouver= "<<pieceAtrouver;

tab_hasardi[0]=pieceAtrouver;
//nbre_caseshasardDejaUtilises=nbre_caseshasardDejaUtilises+1;
cout<<"\n2500 bre_caseshasardDejaUtilises = "<<nbre_caseshasardDejaUtilises;
*/
//pause();
nbre_caseshasardDejaUtilises=0;//***************
for(int i=0;i<32;i++)
{
	tab_hasardi[i]="";//vider le tableau
}
while(nbre_caseshasardDejaUtilises<31)
{
/*	cout<<"\n tab_hasardi";
	for(int j=0;j<32;j++)
	{    cout<<"\n  tab_hasardi["<<j<<"] vaut "<<tab_hasardi[j] ;	
    }//for j
*/	
hasard_i = rand() % 31 + 1;//val entre 0 et 31
pieceAtrouver=tab_nom_piecedorigine[hasard_i];

if (estpresentTabHasardi(pieceAtrouver)==false)
{
tab_hasardi[nbre_caseshasardDejaUtilises]=pieceAtrouver;
nbre_caseshasardDejaUtilises=nbre_caseshasardDejaUtilises+1;
cout<<"\n2512 nbre_caseshasardDejaUtilises = "<<nbre_caseshasardDejaUtilises;
pieceAtrouver=tab_nom_piecedorigine[hasard_i];
cout<<"\nou se trouve la piece "<<pieceAtrouver<<"\n";
cin>>votreReponse;
cout<<"\nTest vous avez saisie"<<votreReponse;
cout<<"\nTest num_etape_actuelle="<<num_etape_actuelle;
//pause();
		ouSeTrouveLaPiece=ouSeTrouveTelPieceATelEtape(num_etape_actuelle,pieceAtrouver);
		//pause();
		//cout<<"\nTest votreReponse="<<votreReponse<<"et ouSeTrouveLaPiece vaut"<<ouSeTrouveLaPiece;
		//pause();
		if(votreReponse==ouSeTrouveLaPiece)
		{
		cout<<"\n====================================================";
		cout<<"\n\n effectivement la piece "<<pieceAtrouver<<"se trouve bien en "<<ouSeTrouveLaPiece<<"\n";
		cout<<"\n====================================================\n";
		score=score+1;
		}
		else
		{
		cout<<"\n\n Non la piece "<<pieceAtrouver<<"se trouve en "<<ouSeTrouveLaPiece<<"\n";

		}//else
}//if (estpresentTabHasardi(hasard_i)==false)
}//while(nbre_caseshasardDejaUtilises<32)
}//if positionDeDepart==
else
{
//cout<<"\n====================================================";
cout<<"\n====================================================";
cout<<"\n Deplacement impossible car la piece "<<pieceAdeplacer<<" ne se trouve pas en "<<postionDeDepart<<" mais en "<<ouSeTrouveTelPieceATelEtape(num_etape_actuelle,pieceAdeplacer);
cout<<"\n====================================================\n";
//cout<<"\n====================================================";

}//else
cout<<"\n";
//pause();
		}//while²
}//void OuSeTrouveTelPiece()

/*********************************************0 4   **************************/
void ExerciceSurPositionDepart(){
cout << "4 exercices sur la position de depart" <<endl;

}//void ExerciceSurPositionDepart()

/*********************************************0 5   **************************/
void ExerciceSurCouleurCasesEchiquier(){
string saisietmp,caseAuHasard,couleurSaisie="";
int col,lig,hasard_i=99;
string reponse="bug";

cout << "5 exercice sur les couleurs de cases de l'echiquier" <<endl;
cout<<"\npour chaque reponse il faudra saisir les lettre n ou b suivant la couleur choisie\n";
while(1)
{
hasard_i = rand() % 63 + 1;//val entre 0 et 63
//cout<<"\n TEST hasard_i vaut"<<hasard_i;
caseAuHasard=tab_cases_echiquier[hasard_i];
//cout<<"\n voici la case "<<caseAuHasard;
cout<<"\n"<<caseAuHasard<<"\n";
cin>>saisietmp;
	while((saisietmp!="b")&&(saisietmp!="n")&&(saisietmp!="*"))
	{
	cout<<"\nSaisissez b pour blanc ou n pour noir ou * pour revenir à l'accueil\n";
	cin>>saisietmp;
	}//while


	if(saisietmp=="*")
	{
	//afficherAccueil()
	;
	}

	if(saisietmp=="b"){couleurSaisie="blanche";}
	if(saisietmp=="n"){couleurSaisie="noire";}

col=colonne(caseAuHasard);
lig=ligne(caseAuHasard);

	if(((estPair(lig))&&(estPair(col)))||((estImpair(lig))&&(estImpair(col))))
	{
	reponse="noire";
	}//if
	else
	{
		if(((estPair(lig))&&(estImpair(col)))||((estImpair(lig))&&(estPair(col))))
		{
		reponse="blanche";
		}//if
	}//else


	if(couleurSaisie==reponse)
	{cout<<"\n.......................Exacte "<<caseAuHasard<<" est bien est une case de couleur "<<reponse;}
	else{
	cout<<"\n..............Non "<<caseAuHasard<<" est est une case de couleur "<<reponse;}
}//while(1);
}//void ExerciceSurCouleurCasesEchiquier()

/*********************************************0 6   **************************/
void QuellesSontCasesDesBords(){
cout << "6 quelles sont les cases des bords qui passent par cette piece (cases de dernieres ligne et ou derniere colonne)" <<endl;
bool bonneReponse=false;
string saisietmp,caseAuHasard="";
int col,lig,coltmp,ligtmp,hasard_i=99;
string reponse="bug";
int nbreEssais,nbreEssaisMax=0;
string tab_cases_liees[64];//pour enregistré les cases qui sont sur la meme ligne, colonne ou diagonale
int nbre_de_cases_liees=0;

cout << "6 exercice sur les bords ou arrivent les cases de l'echiquier" <<endl;
cout<<"\npour chaque reponse il faudra saisir un des bords possible\n";
cout<<"\choisissez le nombre d'essais par case \n";
cin>>saisietmp;
nbreEssaisMax=string_vers_int(saisietmp);
cout<<"\n2581 breEssais="<<nbreEssais;
while(1)
{
nbreEssais=0;


hasard_i = rand() % 63 + 1;//val entre 0 et 63
//cout<<"\n TEST hasard_i vaut"<<hasard_i;
caseAuHasard=tab_cases_echiquier[hasard_i];
//cout<<"\n voici la case "<<caseAuHasard;
//cout<<"\n"<<caseAuHasard<<"\n";
//cin>>saisietmp;

col=colonne(caseAuHasard);
lig=ligne(caseAuHasard);

cout<<"\n nbreEssaisMax= "<<nbreEssaisMax;
cout<<"\n nbreEssais= "<<nbreEssais;

while(nbreEssais<nbreEssaisMax)
{
cout<<"\n nbreEssaisMax= "<<nbreEssaisMax;
cout<<"\n nbreEssais= "<<nbreEssais;
nbreEssais=nbreEssais+1;

cout<<"\n"<<caseAuHasard<<"\n";
cin>>saisietmp;


//diag / vers hautDroit
coltmp=col;
ligtmp=lig;
while((coltmp<8)&&(ligtmp<8))
{

coltmp=coltmp+1;ligtmp=ligtmp+1;
	if((coltmp==8)||(ligtmp==8))
	{
	tab_cases_liees[nbre_de_cases_liees]= positionEnString(coltmp,ligtmp);
cout<<"\n diag // vers hautDroit "<<tab_cases_liees[nbre_de_cases_liees];
	nbre_de_cases_liees=nbre_de_cases_liees+1;

	}
}//while((coltmp=<8)&&(lig=<8))


//diag \ vers basDroit
coltmp=col;
ligtmp=lig;
while((coltmp<8)&&(ligtmp>1))
{

coltmp=coltmp+1;ligtmp=ligtmp-1;
	if((coltmp==8)||(ligtmp==1))
	{
	tab_cases_liees[nbre_de_cases_liees]= positionEnString(coltmp,ligtmp);
cout<<"\n diag \ vers basDroit "<<tab_cases_liees[nbre_de_cases_liees];
	nbre_de_cases_liees=nbre_de_cases_liees+1;

	}
}//while


//diag \ vers hautGauche
coltmp=col;
ligtmp=lig;
while((coltmp>1)&&(ligtmp<8))
{

coltmp=coltmp-1;ligtmp=ligtmp+1;
	if((coltmp==1)||(ligtmp==8))
	{
	tab_cases_liees[nbre_de_cases_liees]= positionEnString(coltmp,ligtmp);
cout<<"\n diag \ vers hautGauche "<<tab_cases_liees[nbre_de_cases_liees];
	nbre_de_cases_liees=nbre_de_cases_liees+1;

	}
}//while


//diag / vers basGauche
coltmp=col;
ligtmp=lig;
while((coltmp>1)&&(ligtmp>1))
{

coltmp=coltmp-1;ligtmp=ligtmp-1;
	if((coltmp==1)||(ligtmp==1))
	{
	tab_cases_liees[nbre_de_cases_liees]= positionEnString(coltmp,ligtmp);
	cout<<"\n diag / vers basGauche "<<tab_cases_liees[nbre_de_cases_liees];
	nbre_de_cases_liees=nbre_de_cases_liees+1;

	}
}//while


//case_ext_gauche
	coltmp=1;
	tab_cases_liees[nbre_de_cases_liees]= positionEnString(coltmp,lig);
cout<<"\n ---- case_ext_gauche coltmp = "<<coltmp<<" et lig = "<<lig<<" et tabcaseliee= "<<tab_cases_liees[nbre_de_cases_liees];
nbre_de_cases_liees=nbre_de_cases_liees+1;

//case_ext_droite
    coltmp=8;
	tab_cases_liees[nbre_de_cases_liees]= positionEnString(coltmp,lig);
cout<<"\n ---- case_ext_droite "<<tab_cases_liees[nbre_de_cases_liees];
nbre_de_cases_liees=nbre_de_cases_liees+1;

//case_ext_bas
	ligtmp=1;
	tab_cases_liees[nbre_de_cases_liees]= positionEnString(col,ligtmp);
cout<<"\n ---- case_ext_bas "<<tab_cases_liees[nbre_de_cases_liees];
nbre_de_cases_liees=nbre_de_cases_liees+1;

//case_ext_haut
	ligtmp=8;
	tab_cases_liees[nbre_de_cases_liees]= positionEnString(col,ligtmp);
cout<<"\n ---- case_ext_haut "<<tab_cases_liees[nbre_de_cases_liees];
nbre_de_cases_liees=nbre_de_cases_liees+1;

cout<<"\npour la case ,voici les cases liees: \n";
for(int i=0;i<nbre_de_cases_liees;i++)
{
	if(tab_cases_liees[i]!=caseAuHasard)
	{
cout<<"\n   "<<tab_cases_liees[i]<<"    \n";
		if(tab_cases_liees[i]==saisietmp)
		{
	bonneReponse=true;

		}//if tab_cases_liees
	}//if tab_cases_liees
}//for

if(bonneReponse)
{
cout<<"\nExacte "<<saisietmp<<" fait bien des cases de bord de la case "<<caseAuHasard;
}
else
{
cout<<"\n...réponse inexacte";
}//else
//pause();
}//while nbreEssais<nbreEssaisMax

}//while(1);
}//void QuellesSontCasesDesBords()

/*********************************************0 7   **************************/
void VoirLesScores(){
cout << "1 7 Voir les scores" <<endl;

}//void VoirLesScores()


/********************************** afficherAccueil() *************************/

void afficherAccueil()
{
cout << "INTERFACE D ACCUEIL\n1...deplacer une piece seule dans l'echiquier\n\n2...faire deplacer toutes les pieces dans un echiquier\n\n3...ou se trouve tel piece suite a tel mouvement sur des parties d 'exemple\n\n4...exercices sur la position de depart\n\n5...exercice sur les couleurs de cases de l'echiquier\n\n6... quelles sont les cases des bords qui passent par cette piece (cases de dernieres ligne et ou derniere colonne)\n\n...7 voir les scores\n\n..........a tout moment vous pouvez saisir * et validez pour revenir a l accueil	" << endl;

cin >> saisie ;
 cout << "Bonjour vous avez saisie " << saisie << endl;
//pause();
 //int nombre=2;

 if (saisie=="1") //choix 1 deplacer une piece seule dans l'echiquier
 {deplacerUnePieceSeule(99);/*menu du choix de la piece à deplacer seule*/
 }
 if (saisie=="2")
 {
	 cout<<"\n saisie=2deplacerToutesLesPieces \n";
	 pause();
	 deplacerToutesLesPieces();
 }
 if (saisie=="3")
 {OuSeTrouveTelPiece();
 }
 if (saisie=="4")
 {ExerciceSurPositionDepart();
 }
 if (saisie=="5")
 {ExerciceSurCouleurCasesEchiquier();
 }
 if (saisie=="6")
 {QuellesSontCasesDesBords();
 }
 if (saisie=="7")
 {VoirLesScores();
 }


}//void afficherAccueil()


/*********************************************0 2



/*************************************************************************************/



