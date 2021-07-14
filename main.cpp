
#include "fonctions.h"

/*#include "tmpDeplacementRoi.h"*/


//D:\PROG-PERSO\PROJETS\PROJET-EN-C\chessexov2

/*************************************** Liste des fonctions ***************
void vider_Echiquier()

string queContientTelCaseALetapeActuelle(string nom_case)
string queContientTelCaseATelEtape(string nom_case,int num_etape)

string nom_piece(int numpiece)
int numpiece(string nom_piece)

string convert_nbre_en_string(int nbre)
string char_vers_string(char c)
int string_vers_int(string s)  /** attention un string avec un seul caractere "1" ou "2".....ing position_depart)
boolean deplacementAutorise(string type_piece,string couleur_piece,string position_depart,string position_arrivee)

*/

///////////////////////////////////////////////////////////
void testFonctionTmp()
{
int reptmp=0;
while (reptmp<4)
{
cout<<"\n 28 \n";
cin>>saisie;
if (NonbordAvd(saisie))
//if(tab15ContientElm(tab_bord_Avd,saisie))
{
cout<<"\n "<<saisie<<" n'est pas dans bord avd";
}//if
else
{
cout<<"\n "<<saisie<<" est dans bord avd";
}//else
/*cout << "\n\n donnez le nom de la piece d'origine ex. a2" <<endl;
cout << "\n" <<endl;
cin>>saisie;
cout<<"\n======================================"<<endl;
cout << "\n =====>>>>>>>> le numéro de la colonne correspondante a "<<saisie<<" est "<<colonne(saisie)<<endl;	/*int colonne(string position_depart)*/
//colonne(string position_depart)
/*cout<<"\n======================================"<<endl;

*/
//cout<<"\nestpriseParPieceCouleurOpposee(int numero_etape=1,string pieceActuelle=b2,string nom_case_destination=c3) \n";
//cout<<"estpriseParPieceCouleurOpposee    "<<numero_etape<<"  "<<pieceActuelle<<"  "<<nom_case_destination;*/
//(
//cout<<"\nbonjour";
 //estpriseParPieceCouleurOpposee(1,"p1","p2");
//estpriseParPieceCouleurOpposee(0,"b2","c3");
//estpriseParPieceCouleurOpposee(0,"b2","c3");
//)
/*{
	cout<<"\nvaut true";
}
else
{
cout<<"\n vaut false";
}
*/
/*
cout<<"\nEntrez le nom de la piece d'origine dont vous voulez connaître la couleur\n";
cin>>saisie;
cout<<"\n TEST 84 couleur de la case  "<<saisie<<"  est   "<<couleur_piecedorigineS(saisie);
*/
reptmp=reptmp+1;
}//while


}//void testFonctionTmp()

///////////////////////////////////////////////////////////

int main(int argc, char** argv) {
vider_Echiquier();
afficherAccueil();
//cout<<"main";

///********** A EFFACER POUR TEST:
/*
contenu_caseEchiquierParEtapeColLig[0][1][3]="a7";//[num_etape][c][l]
contenu_caseEchiquierParEtapeColLig[0][3][3]="b7";
contenu_caseEchiquierParEtapeColLig[0][2][3]="c7";*/
//contenu_caseEchiquierParEtapeColLig[0][8][4]="h8";
AfficherEchiquierParEtape();

//print_array(tab_bord_Avd);

     //deplacerUnePieceSeule(99) ;//afficher le munu principale pour les deplacements d une piece seule dans un echiquier vide
	deplacerUnePieceSeule(1) ;//b2
//deplacerUnePieceSeule(10) ;//fou c1

	//AfficherEchiquierParEtape();
//ef  facerEcran();
	//deplacerUnePieceSeule(99) ;//afficher le munu principale pour les deplacements d une piece seule dans un echiquier vide
    //deplacerUnePieceSeule(14) ;//roi blanc e1
	AfficherEchiquierParEtape();
	//testFonctionTmp();
	return 0;
}

/*************************************************************************************/



