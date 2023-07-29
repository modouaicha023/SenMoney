#include <stdio.h>
#include "fonctions.h"
#define N 5

void main()
{
    long code,numero,numero_benef;
    char choix2;
    int montant;
    printf("------------------------------------------------\n");
    printf("|################### Sen Money ################|\n");
    printf("------------------------------------------------\n");
    printf("Connexion a votre compte \n");
    printf("\n Veuiller saisir votre numero : ");
    scanf("%ld",&numero);
    printf("Saisissez votre code secret : ");
    scanf("%ld",&code);
    int indN=trouve(tabNumeros,numero);
do
{
        if (tabNumeros[indN] == numero & tabCodes[indN] == code )
        {
            switch (menu())
            {
                case 1:
                    afficherSolde(numero,code);
                    break;

                case 2:
                    printf("\n Bienvenue dans le service de transfert d'argent\n\n");
                    printf("Veuiller saisir le numero beneficiare : ");
                    scanf("%ld",&numero_benef);
                    printf("Veuiller entrer le montant a transferer au %ld : ",numero_benef);
                    scanf("%ld",&montant);
                    printf("Saisissez votre code secret : ");
                    scanf("%ld",&code);

                    transferArgent(numero,numero_benef,code,montant);
                    break;

                case 3:
                    printf("\n Ce service n'est pas disponible pour le moment\n ");
                    break;

                case 4:
                    printf("\n Ce service n'est pas disponible pour le moment\n ");
                    break;

                default:
                    printf("\n Choix indisponible \n");
                    break;
            }
        }
        else if(tabNumeros[indN] != numero)
        {
            printf("\n Le numero que vous avez saisi n'existe pas \n");
            break;
        }
        else if(tabCodes[indN] != code)
        {
            printf("\n Votre code secret est incorrect \n");
            break;
        }
        printf("\nVoulez-vous retourner au menu? (y = Oui) : ");
        scanf("%d",&choix2);

    }while(getchar()=='y');

}
