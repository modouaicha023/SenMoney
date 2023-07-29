#include <stdio.h>
#define N 5

long tabNumeros[N]={776158283,778765456,778932567,781606189,785642134};
long tabSoldes[N]={15000,30000,45000,90000,50000};
long tabCodes[N]={2345,9943,2697,2301,7834};


int trouve(long tab[],int val)
{
    int i;
    for (i=0;i<N;i++){
        if(tab[i]==val)
        {
            return i;
        }

        }
     return -1;
}

int menu()
{
    int choix;
    printf("\n Saisir le numero du service a utuliser :\n");
    printf("1. Solde de votre compte\n");
    printf("2. Transfert d'argent\n");
    printf("3. Paiement de facture\n");
    printf("4. Options\n");
    printf("Votre choix : ");
    scanf("%d",&choix);
    return choix;
}


void afficherSolde(long numero,long code)
{
    int indN=trouve(tabNumeros,numero);
    if (tabNumeros[indN] == numero & tabCodes[indN]== code )
    {
        printf("Le solde de votre compte est de : %ld\n\n",tabSoldes[indN]);
    }
    else if(tabNumeros[indN]!=numero)
    {
        printf("\nCe numero n'existe pas\n");

    }
    else if(tabCodes[indN]!=code)
    {
        printf("\n Votre code secret est incorrect \n");
    }
}

void transferArgent(int numero,int numero_benef,int code,int montant)
{
    int indN=trouve(tabNumeros,numero);
    int indB=trouve(tabNumeros,numero_benef);
    float taux_frais=(float) 5/100;
    int frais;

    if (indN!= -1 & indB!= -1 & tabCodes[indN]== code & tabSoldes[indN]>=montant & numero != numero_benef )
    {
        frais=taux_frais*montant;
        tabSoldes[indN]-=(montant + frais);
        tabSoldes[indB]+=(montant +frais);
        printf("\nVotre Transfert de %ld avec %d de frais de transaction Au %ld a ete un Succes  !!!\n",montant,frais,numero_benef);
        printf("Le Solde de Votre Compte est de : %ld\n",tabSoldes[indN]);
        printf("Le Solde du Compte du Beneficiare est de : %ld\n",tabSoldes[indB]);
    }
    else if(indB == -1)
    {
        printf("\n Le numero du beneficiaire n'existe pas\n");
    }
    else if(tabCodes[indN]!= code)
    {
        printf("\n Votre code secret est incorrect\n");
    }
    else if (tabSoldes[indN]<montant)
    {
        printf("\n Le Solde de Votre Compte est Insuffisant \n");
    }
    else if(numero == numero_benef)
    {
        printf(" Erreur!!! : Impossible d'effectuer cette operation \n");
    }
}
