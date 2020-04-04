#include <stdio.h>
#include <stdlib.h>

void sonucgoster(char x[],long int y[][3],float z,int a,float b);
void sifirla(char partiler[]);
void turkiyesonuc(char a[],long int b[],int d,float e,int x,long int z[][2],float f,int g,int h[][1],int k[][1]);

int main()
{
    char x;
    char partiler[23]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','U','V','Y','Z'};
    int parti_sayisi,ilin_plakasi,ilin_milletvekili_kontenjani;
    int il_birincilik[10][1]={0,0,0,0,0,0,0,0,0,0};
    int mv_sifir[10][1]={0,0,0,0,0,0,0,0,0,0};
    int mv_sayisi[23]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int i=0,toplam_mv=0,a,b,j;
    int gecici;
    long int parti_oyu[23][3]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    long int gecici_prt_oyu[23]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    long int top_mv_parti[23][2]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    float toplam_oy=0,toplam_troy=0;
    float oy_yuzdesi=0;
    float mv_yuzdesi=0;


    printf("Secime katilan parti sayisini giriniz :");
    scanf("%d",&parti_sayisi);
    do
    {

        do
        {
            printf("Ilin plaka kodunu giriniz :");
            scanf("%d",&ilin_plakasi);
            if(ilin_plakasi>0 && ilin_plakasi<82)
                break;
        }
        while(ilin_plakasi>0 || ilin_plakasi<82);
        printf("Ilin milletvekili kontenjanini giriniz :");
        scanf("%d",&ilin_milletvekili_kontenjani);
        toplam_mv+=ilin_milletvekili_kontenjani;//Toplam mv bulmak için mv'lerini topluyoruz.
        for(i=0;i<parti_sayisi;i++)
        {
            printf("%c Partisi'nin oy sayisini giriniz :",partiler[i]);
            scanf("%ld",&parti_oyu[i][0]);//Kac adet parti varsa onların oylarını alıp parti_oyu[i][0]'a atıyoruz.
            toplam_oy+=parti_oyu[i][0];//Toplam oyu bulmak icin oyları toplatıyoruz.
            gecici_prt_oyu[i]+=parti_oyu[i][0];

        }
        toplam_troy+=toplam_oy;
        printf("\nIl Plaka Kodu : %d",ilin_plakasi);
        printf("\nMilletvekili Kontenjani : %d",ilin_milletvekili_kontenjani);
        printf("\nGecerli Oy Sayisi : %.0f",toplam_oy);
        for(i=0;i<parti_sayisi;i++)
        {
            parti_oyu[i][2]=i;//Parti numaralarını burada tutuyoruz.
            top_mv_parti[i][1]=i;//Hangi il sırasında kac mv var burada sıra belirliyoruz.
        }
        for(a=0;a<=parti_sayisi;a++)
        {
            for(b=0;b<=parti_sayisi;b++)
            {
                if(parti_oyu[a][0]>parti_oyu[b][0])
                {
                    gecici=parti_oyu[a][0];
                    parti_oyu[a][0]=parti_oyu[b][0];
                    parti_oyu[b][0]=gecici;//Parti oylarına göre sıralama yapıyoruz.

                    gecici=parti_oyu[a][2];
                    parti_oyu[a][2] = parti_oyu[b][2];
                    parti_oyu[b][2] = gecici;//Parti oyları ile beraber parti isimlerini de sıralıyoruz.
                }
            }
        }
        for(i=0;i<parti_sayisi;i++)
        {
             if(parti_oyu[0][2]==i)
             {
                 il_birincilik[i][0]++;
                 break;//Kac ile birinci olduklarını burada hesaplayıp atıyoruz.
             }
        }
        int partiayar[parti_sayisi][2];//Parti ayar diye gecici bir matris olusturuyoruz.
        for(i=0;i<parti_sayisi;i++)
        {
            partiayar[i][0] = parti_oyu[i][0];
            partiayar[i][1] = i;
        }
        do {
            for(i=0;i<parti_sayisi;i++)
            {
                for(j=0;j<parti_sayisi-1;j++)
                {
                    if(partiayar[j][0] < partiayar[j+1][0])
                    {
                        gecici = partiayar[j][0];
                        partiayar[j][0] = partiayar[j+1][0];
                        partiayar[j+1][0] = gecici;

                        gecici = partiayar[j][1];
                        partiayar[j][1] = partiayar[j+1][1];
                        partiayar[j+1][1] = gecici;
                    }
                }
            }
            ilin_milletvekili_kontenjani--;
            parti_oyu[partiayar[0][1]][1]++;
            partiayar[0][0] = partiayar[0][0]/2;
            //Bu kısımda gecici matrisi'imiz ile parti oylarını sıralayıp en yusek oyu alan partiyi 1.sıraya atıyoruz ve ona gore mv dagıtımı yapıyoruz.
        }while(ilin_milletvekili_kontenjani>0);
        for(i=0;i<parti_sayisi;i++)
        {
             if(parti_oyu[i][1]==0)
             {
                 mv_sifir[parti_oyu[i][2]][0]++;
             }
        }
        printf("\n\t\tOy Say \t\tOy Yuzde \tMV Say");
        printf("\n\t\t------\t\t------\t\t------");
        sonucgoster(partiler,parti_oyu,oy_yuzdesi,parti_sayisi,toplam_oy);//Fonksiyonumuzu ekrana yazdırıyoruz.
        for(i=0;i<parti_sayisi;i++)
        {
        	top_mv_parti[parti_oyu[i][2]][0]+=parti_oyu[i][1];
		}

        printf("\nDevam etmek istiyor musunuz (Evet/Hayir(e/E/H/h))?");
        scanf("%s",&x);
        if(x=='e'||x=='E')
        {   //Tekrar il girilmek isteniyorsa toplam oy,ilin mv ve parti oylarını sıfırlıyoruz.
            toplam_oy=0;
            ilin_milletvekili_kontenjani=0;
            for(i=0;i<parti_sayisi;i++)
            {
                parti_oyu[i][1]=0;
            }
        }
    }
    while(x=='e'||x=='E');
    printf("\n\t\t\t\t-----------TURKIYE GENELI-----------\t\t\n");
    printf("\nMilletvekili Kontenjani : %d",toplam_mv);
    printf("\nGecerli Oy Sayisi : %.0f",toplam_troy);
    printf("\n\t\tOy Say \t\tOy Yuzde \t MV Say \tMV Yuzde \t Il 1.lik Say. \t 0 MV Il Say.");
    printf("\n\t\t------\t\t------\t\t------\t\t------\t\t------\t\t------");
    turkiyesonuc(partiler,gecici_prt_oyu,parti_sayisi,oy_yuzdesi,toplam_troy,top_mv_parti,mv_yuzdesi,toplam_mv,il_birincilik,mv_sifir);
}

void sonucgoster(char x[],long int y[][3],float z,int a,float b)
{
    int c;
    for(c=0;c<a;c++)
    {
        z=(y[c][0]*100)/b;
        printf("\n%c Partisi \t%ld \t\t%.2f \t\t%ld",x[y[c][2]],y[c][0],z,y[c][1]);
    }
}

void sifirla(char partiler[])
{
    char partiler1[23]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','U','V','Y','Z'};
    int i;
    for(i=0;i<23;i++)
    {
        partiler[i]=partiler1[i];
    }
}

void turkiyesonuc(char a[],long int b[],int d,float e,int x,long int z[][2],float f,int g,int h[][1],int k[][1])
{
    long int mv_s[d][2];
    int i,j;
    for(i=0;i<d;i++)
    {
        mv_s[i][0] = z[i][0];
        mv_s[i][1] = i;
    }
    for(i=0;i<d;i++)
    {
        for(j=0;j<d-1;j++)
        {
            if(mv_s[j][0] < mv_s[j+1][0])
            {
                int gecici;
                gecici = mv_s[j][0];
                mv_s[j][0] = mv_s[j+1][0];
                mv_s[j+1][0] = gecici;

                gecici = mv_s[j][1];
                mv_s[j][1] = mv_s[j+1][1];
                mv_s[j+1][1] = gecici;
            }
        }
    }//Mvllerini kendi arasında sıralayıp en cok mv alan partiyi buluyoruz.
    for(i=0;i<d;i++)
    {
        f= (float)(z[i][0]*100)/g;
        e=(float)(b[i]*100)/x;
        printf("\n%c Partisi \t%ld \t\t%.2f\t\t%ld\t\t%.2f\t\t%d\t\t%d",a[i],b[i],e,z[i][0],f,h[i][0],k[i][0]);
    }
    printf("\nIktidar Partisi : %c\nAna Muhalefet Partisi:%c",a[mv_s[0][1]],a[mv_s[1][1]]);
}
