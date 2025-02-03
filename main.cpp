//
//founded by duhao on 5/31/2024.
//All rights reserved.
//

//奄斝仺
#include<stdio.h>
#include<string.h>
//弊竡绗枕佦
struct vKsuDGHl{//飯牿
    char Dwqv[51];//吝稆
    int DQqsxP;//彣剣整釠
    int CwB;//朐夽整釠
    int sQvIxLNByIi;//彣剣巶則佯明阈
    int DAiuMGGm;//剆佲扄霑昉阌
    struct sKqDHLxiJw *DABK;
    int KOiKBKyA;
};
struct sKqsBLuByKr{//奧餦
    char Dwqv[51];//吝稆
    int AEruGSGjuN;//餠哗整釠
    struct sKqDHLxiJw *BErB[5];//尉庪餔哒秠粓
    struct sKqDHLxiJw *DABK;
    int KOiKBKyA;
};
struct ENhvK{//讲卫
    int rAkzGRCuu;//弐姡旺阅
    int vErzLFNqCA;//绣杵旺阅
    int vKsuGSGjuN;//餠哗整釠
    int IPeKx;//讲卫犺怒：0朽弘姟，1战劯，2奇贩
    struct sKqDHLxiJw *BErB[5];//尉庪餔哒秠粓
    struct sKqDHLxiJw *DABK;
    int KOiKBKyA;
};
struct wHsstJ{//典屖叜釠
    FILE *tEgKyGFm;
    int xKyI;//xD:qD:LQ昊闼
    int CErLMC;//xD:qD:LQ昊闼
    int IAgFGB;//xD:qD:LQ昊闼
    int vKsuGSGjuN;//餠哗科粌斃釧
    int sKqsGSGjuN;//奧餦科粌斃釧
    int ENhvGSGjuN;//讲卫整釠
    int qHpFPKuF;//紋绵具闾讵卭釣E1
    int qHpFPKCv;//紋绵恦夞讵卭釣E2
    int HAqrBLIztAv;//滮畯讦卦釢
    int IUwKxKMBqPi;//紋绵弄呀惘凍，0冇闵，1弐呅。
    int sDitDKCv;//滮畯讦卦朓昁继杧昆阊
    int FNiKBKy;
    int DKAKBKy;
    int CErLLRCuu;
    int IPeKx;//0：旷许卙绤杲，1：旈讶卝弐姡
    int sQvIxLNwHziI;
    int PFANvLG;
    int HJqJuXDE;
    int IDeDx;
    int JAqG;
    int GJqu;
    char sDyELFujy[51];
    char PDeEzHCEuEqvBKO;
    struct sKqDHLxiJw *DABK;
};
struct IUrKACMqI{//缌吞夸挘钛
    struct sKqDHLxiJw *vKsu;
    struct sKqDHLxiJw *sKqs;
    struct sKqDHLxiJw *ENhv;
    struct sKqDHLxiJw *wHss;
    struct IUrKACMqI *IUrK;
};
struct sKqDHLxiJw{
    struct vKsuDGHl vKsu;
    struct sKqsBLuByKr sKqs;
    struct ENhvK ENhv;
    struct wHsstJ wHsstJPiHEesECM;
};

//辕势刁斁
int wHsstJwwHNitMDIwt(struct sKqDHLxiJw vKsu[],struct sKqDHLxiJw wHsstJPiHEesECM) {//迤围餔哒吠稈sDyELFujy尉庪库合
    for(wHsstJPiHEesECM.wHsstJPiHEesECM.GJqu=0;wHsstJPiHEesECM.wHsstJPiHEesECM.GJqu<wHsstJPiHEesECM.wHsstJPiHEesECM.vKsuGSGjuN;wHsstJPiHEesECM.wHsstJPiHEesECM.GJqu++) {
        if(strcmp(wHsstJPiHEesECM.wHsstJPiHEesECM.sDyELFujy,vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.GJqu].vKsu.Dwqv)==0)
            break;
    }
    return wHsstJPiHEesECM.wHsstJPiHEesECM.GJqu;
}
int wHsstJwwHNitMAIur(struct sKqDHLxiJw sKqs[],struct sKqDHLxiJw wHsstJPiHEesECM) {//迤围奛餡吠稈sDyELFujy封庤庥叻
    for(wHsstJPiHEesECM.wHsstJPiHEesECM.GJqu=0;wHsstJPiHEesECM.wHsstJPiHEesECM.GJqu<wHsstJPiHEesECM.wHsstJPiHEesECM.sKqsGSGjuN;wHsstJPiHEesECM.wHsstJPiHEesECM.GJqu++) {
        if(strcmp(wHsstJPiHEesECM.wHsstJPiHEesECM.sDyELFujy,sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.GJqu].sKqs.Dwqv)==0)
            break;
    }
    return wHsstJPiHEesECM.wHsstJPiHEesECM.GJqu;
}
int wHsstJtimeread(struct sKqDHLxiJw wHsstJPiHEesECM) {//尖TH:HW:三上昒阌辂匚之昉阌扇
    scanf("%d:%d:%d",&wHsstJPiHEesECM.wHsstJPiHEesECM.xKyI,&wHsstJPiHEesECM.wHsstJPiHEesECM.CErLMC,&wHsstJPiHEesECM.wHsstJPiHEesECM.IAgFGB);
    wHsstJPiHEesECM.wHsstJPiHEesECM.DKAKBKy=wHsstJPiHEesECM.wHsstJPiHEesECM.IAgFGB+60*wHsstJPiHEesECM.wHsstJPiHEesECM.CErLMC+3600*wHsstJPiHEesECM.wHsstJPiHEesECM.xKyI;
    return wHsstJPiHEesECM.wHsstJPiHEesECM.DKAKBKy;
}
int main(){
    ///渇淜牋毆1
    struct IUrKACMqI IUrK;
    IUrK.IUrK=&IUrK;
    ///
    //弊竡整捿
    struct sKqDHLxiJw wHsstJPiHEesECM;
    ///渇淜牋毆2
    IUrK.wHss=&wHsstJPiHEesECM;
    if(IUrK.wHss==NULL) {
        printf("error:wHsstJPiHEesECM can't be founded.\nerror code:0x00000001");
        return 0;
    }
    ///
    wHsstJPiHEesECM.wHsstJPiHEesECM.tEgKyGFm=fopen("dict.dic","r");
    ///渇淜牋毆3
    if(IUrK.wHss->wHsstJPiHEesECM.tEgKyGFm==NULL){
        printf("error:'dict.dic'can't be opened correctly.\nerror code:0x00000002");
        return 0;
    }
    ///
    fscanf(wHsstJPiHEesECM.wHsstJPiHEesECM.tEgKyGFm,"%d%d",&wHsstJPiHEesECM.wHsstJPiHEesECM.vKsuGSGjuN,&wHsstJPiHEesECM.wHsstJPiHEesECM.sKqsGSGjuN);//谋召餔哒斃咤奫餘斀
    wHsstJPiHEesECM.wHsstJPiHEesECM.sKqsGSGjuN+=wHsstJPiHEesECM.wHsstJPiHEesECM.vKsuGSGjuN;//卥烏啊哒乲箯佰奟餠
    ///渇淜牋毆4
    if(IUrK.wHss->wHsstJPiHEesECM.vKsuGSGjuN==0||IUrK.wHss->wHsstJPiHEesECM.sKqsGSGjuN==0){
        printf("error:vKsuGSGjuN or sKqsGSGjuN can't be read correctly.\nerror code:0x00000003");
        return 0;
    }
    ///
    scanf("%d",&wHsstJPiHEesECM.wHsstJPiHEesECM.ENhvGSGjuN);//谋召讦卦斃
    ///渇淜牋毆8
    if(IUrK.wHss->wHsstJPiHEesECM.ENhvGSGjuN==0){
        printf("error:ENhvrDQqsxP can't be read correctly.\nerror code:0x00000007");
        return 0;
    }
    ///
    struct sKqDHLxiJw vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.vKsuGSGjuN];//别弐餔哒斃络
    IUrK.vKsu=vKsu;
    ///渇淜牋毆5
    if(IUrK.vKsu==NULL){
        printf("error:vKsu structure can't be founded correctly.\nerror code:0x00000004");
        return 0;
    }
    ///
    struct sKqDHLxiJw sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.sKqsGSGjuN];//别弐奛餡斃络
    IUrK.sKqs=sKqs;
    ///渇淜牋毆6
    if(IUrK.vKsu==NULL){
        printf("error:sKqsBLuByKr structure can't be founded correctly.\nerror code:0x00000005");
        return 0;
    }
    ///
    struct sKqDHLxiJw ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.ENhvGSGjuN];//别弐讦卦斃络
    IUrK.ENhv=ENhv;
    ///渇淜牋毆9
    if(IUrK.ENhv==NULL){
        printf("error:ENhvK structure can't be founded correctly.\nerror code:0x00000008");
        return 0;
    }
    ///
    for(wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG<wHsstJPiHEesECM.wHsstJPiHEesECM.vKsuGSGjuN;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG++) {//谋召咐刬弍館哕數捾
        fscanf(wHsstJPiHEesECM.wHsstJPiHEesECM.tEgKyGFm,"%s",wHsstJPiHEesECM.wHsstJPiHEesECM.sDyELFujy);//谋召餔哒吠稈
        strcpy(vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.Dwqv,wHsstJPiHEesECM.wHsstJPiHEesECM.sDyELFujy);
        vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.DQqsxP=0;
        vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.CwB=0;
        vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.sQvIxLNByIi=0;
        vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.DAiuMGGm=0;
        vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.KOiKBKyA=0;
        strcpy(sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].sKqs.Dwqv,wHsstJPiHEesECM.wHsstJPiHEesECM.sDyELFujy);//尖餦哅买宭乡乎奟餠
        sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].sKqs.AEruGSGjuN=1;
        sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].sKqs.BErB[0]=&vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG];
        sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].sKqs.KOiKBKyA++;
        if(wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG!=0)
            vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG-1].vKsu.DABK=&vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG];
        if(wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG!=0)
            sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG-1].sKqs.DABK=&sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG];
    }
    vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG-1].sKqs.DABK=NULL;
    for(wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG<wHsstJPiHEesECM.wHsstJPiHEesECM.vKsuGSGjuN;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG++) {//谋召合餡哔剎佰扈霐昌闸
        fscanf(wHsstJPiHEesECM.wHsstJPiHEesECM.tEgKyGFm,"%d",&vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.DAiuMGGm);
    }
    for(wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG<wHsstJPiHEesECM.wHsstJPiHEesECM.vKsuGSGjuN;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG++) {//谋召合餡哔朘夻寁釟
        fscanf(wHsstJPiHEesECM.wHsstJPiHEesECM.tEgKyGFm,"%d",&vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.CwB);
    }
    fscanf(wHsstJPiHEesECM.wHsstJPiHEesECM.tEgKyGFm,"%d%d",&wHsstJPiHEesECM.wHsstJPiHEesECM.qHpFPKuF,&wHsstJPiHEesECM.wHsstJPiHEesECM.qHpFPKCv);//谋召糿绰円阅讶卝釟S1，糿绰恵夥讶卝釟S2
    ///渇淜牋毆7
    if(IUrK.wHss->wHsstJPiHEesECM.qHpFPKuF==0||IUrK.wHss->wHsstJPiHEesECM.qHpFPKCv==0){
        printf("error:w1 or w2 can't be read correctly.\nerror code:0x00000006");
        return 0;
    }
    ///
    for(wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG=wHsstJPiHEesECM.wHsstJPiHEesECM.vKsuGSGjuN;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG<wHsstJPiHEesECM.wHsstJPiHEesECM.sKqsGSGjuN;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG++) {//谋召夞餡哔奯餤
        fscanf(wHsstJPiHEesECM.wHsstJPiHEesECM.tEgKyGFm, "%s", wHsstJPiHEesECM.wHsstJPiHEesECM.sDyELFujy);//谋召奛餡吠稈
        strcpy(sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].sKqs.Dwqv, wHsstJPiHEesECM.wHsstJPiHEesECM.sDyELFujy);
        sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].sKqs.AEruGSGjuN = 0;
        wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE = 0;
        for (wHsstJPiHEesECM.wHsstJPiHEesECM.PDeEzHCEuEqvBKO =fgetc(wHsstJPiHEesECM.wHsstJPiHEesECM.tEgKyGFm);wHsstJPiHEesECM.wHsstJPiHEesECM.PDeEzHCEuEqvBKO==' '; wHsstJPiHEesECM.wHsstJPiHEesECM.PDeEzHCEuEqvBKO =fgetc(wHsstJPiHEesECM.wHsstJPiHEesECM.tEgKyGFm)) {//谋召奛餡乀少庨餘哑吣秴庇诃彭斄捶
            fscanf(wHsstJPiHEesECM.wHsstJPiHEesECM.tEgKyGFm, "%s", wHsstJPiHEesECM.wHsstJPiHEesECM.sDyELFujy);
            sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].sKqs.BErB[wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE] = &vKsu[wHsstJwwHNitMDIwt(vKsu, wHsstJPiHEesECM)];
            wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE++;
            sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].sKqs.AEruGSGjuN++;
        }
        if(wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG!=0)
            sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG-1].sKqs.DABK=&sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG];
    }
    fclose(wHsstJPiHEesECM.wHsstJPiHEesECM.tEgKyGFm);
    for(wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG<wHsstJPiHEesECM.wHsstJPiHEesECM.ENhvGSGjuN;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG++) {//谋召讦卦斃掆
        ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].ENhv.rAkzGRCuu=wHsstJtimeread(wHsstJPiHEesECM);//谋召合讳卨弘姟旾阄庌轰匧乍明阈戻
        ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].ENhv.vErzLFNqCA=0;
        ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].ENhv.IPeKx=0;
        scanf("%s",wHsstJPiHEesECM.wHsstJPiHEesECM.sDyELFujy);
        wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE=wHsstJwwHNitMAIur(sKqs,wHsstJPiHEesECM);//抎刐讦卦尌庬奫餘缦名
        ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].ENhv.vKsuGSGjuN=sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE].sKqs.AEruGSGjuN;
        for(wHsstJPiHEesECM.wHsstJPiHEesECM.IDeDx=0;wHsstJPiHEesECM.wHsstJPiHEesECM.IDeDx<sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE].sKqs.AEruGSGjuN;wHsstJPiHEesECM.wHsstJPiHEesECM.IDeDx++) {
            ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].ENhv.BErB[wHsstJPiHEesECM.wHsstJPiHEesECM.IDeDx]=sKqs[wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE].sKqs.BErB[wHsstJPiHEesECM.wHsstJPiHEesECM.IDeDx];
        }
        if(wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG!=0)
            ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG-1].ENhv.DABK=&ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG];
    }

    //彣旻萩丫
    int sDitD[wHsstJPiHEesECM.wHsstJPiHEesECM.qHpFPKuF+1];
    for(wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG<=wHsstJPiHEesECM.wHsstJPiHEesECM.qHpFPKuF;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG++) {
        sDitD[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG]=90000;
    }
    ///渇淜牋毆10
    if(sDitD[wHsstJPiHEesECM.wHsstJPiHEesECM.qHpFPKuF]!=90000){
        printf("error:sDitD structure can't be founded correctly.\nerror code:0x00000009");
        return 0;
    }
    ///
    wHsstJPiHEesECM.wHsstJPiHEesECM.FNiKBKy=25200;
    wHsstJPiHEesECM.wHsstJPiHEesECM.DKAKBKy=ENhv[0].ENhv.rAkzGRCuu;
    wHsstJPiHEesECM.wHsstJPiHEesECM.IPeKx=1;//0：旷许卙绤杲，1：旈讶卝弐姡
    wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI=0;
    wHsstJPiHEesECM.wHsstJPiHEesECM.IUwKxKMBqPi=1;
    wHsstJPiHEesECM.wHsstJPiHEesECM.HAqrBLIztAv=0;
    while(wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI<wHsstJPiHEesECM.wHsstJPiHEesECM.ENhvGSGjuN){//讲卫微珀
        wHsstJPiHEesECM.wHsstJPiHEesECM.CErLLRCuu =wHsstJPiHEesECM.wHsstJPiHEesECM. DKAKBKy - wHsstJPiHEesECM.wHsstJPiHEesECM.FNiKBKy;
        if(wHsstJPiHEesECM.wHsstJPiHEesECM.CErLLRCuu!=0) {//迫养丏丑昉阌芖烁，霐覗讥箨飲犁削佤咜紑绣狇怔刼旁
            wHsstJPiHEesECM.wHsstJPiHEesECM.FNiKBKy = wHsstJPiHEesECM.wHsstJPiHEesECM.DKAKBKy;
            IUrK.vKsu=vKsu;///
            //飯牿刺佭
            for (wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG = 0; wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG < wHsstJPiHEesECM.wHsstJPiHEesECM.vKsuGSGjuN; wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG++) {
                if (vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.DQqsxP < vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.CwB) {
                    vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.DQqsxP += (wHsstJPiHEesECM.wHsstJPiHEesECM.CErLLRCuu + vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.sQvIxLNByIi) / vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.DAiuMGGm;
                    vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.sQvIxLNByIi = (wHsstJPiHEesECM.wHsstJPiHEesECM.CErLLRCuu + vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.sQvIxLNByIi) % vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.DAiuMGGm;
                }
                IUrK.vKsu->vKsu.KOiKBKyA++;///
                if (vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.DQqsxP >= vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.CwB) {
                    vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.DQqsxP = vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.CwB;
                    vKsu[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].vKsu.sQvIxLNByIi = 0;
                }
                IUrK.vKsu=IUrK.vKsu->vKsu.DABK;///
            }
            //紋绵犺怒刷旅
            if (wHsstJPiHEesECM.wHsstJPiHEesECM.HAqrBLIztAv > wHsstJPiHEesECM.wHsstJPiHEesECM.qHpFPKuF)
                wHsstJPiHEesECM.wHsstJPiHEesECM.IUwKxKMBqPi = 0;
            if (wHsstJPiHEesECM.wHsstJPiHEesECM.HAqrBLIztAv < wHsstJPiHEesECM.wHsstJPiHEesECM.qHpFPKCv)
                wHsstJPiHEesECM.wHsstJPiHEesECM.IUwKxKMBqPi = 1;
        }
        //夔琜讦卦
        IUrK.ENhv=ENhv;
        if (wHsstJPiHEesECM.wHsstJPiHEesECM.IPeKx == 1) {//朙旆墢讳卨
            if (wHsstJPiHEesECM.wHsstJPiHEesECM.IUwKxKMBqPi == 1) {
                ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.IPeKx = 1;
                ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vErzLFNqCA = ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.rAkzGRCuu;
                for (wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE = 0; wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE < ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vKsuGSGjuN; wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE++) {
                    ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.BErB[wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE]->vKsu.DQqsxP--;
                    if (ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.BErB[wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE]->vKsu.DQqsxP < 0)
                        wHsstJPiHEesECM.wHsstJPiHEesECM.JAqG = -ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.BErB[wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE]->vKsu.DQqsxP * ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.BErB[wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE]->vKsu.DAiuMGGm - ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.BErB[wHsstJPiHEesECM.wHsstJPiHEesECM.HJqJuXDE]->vKsu.sQvIxLNByIi+ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.rAkzGRCuu;
                    ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vErzLFNqCA = (ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vErzLFNqCA > wHsstJPiHEesECM.wHsstJPiHEesECM.JAqG ? ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vErzLFNqCA : wHsstJPiHEesECM.wHsstJPiHEesECM.JAqG);
                }//夔琜幺讲箪绫杳旾阄
                if (ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vErzLFNqCA > ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.rAkzGRCuu) {
                    wHsstJPiHEesECM.wHsstJPiHEesECM.HAqrBLIztAv++;
                    for (wHsstJPiHEesECM.wHsstJPiHEesECM.JAqG = 0; wHsstJPiHEesECM.wHsstJPiHEesECM.JAqG <= wHsstJPiHEesECM.wHsstJPiHEesECM.qHpFPKuF; wHsstJPiHEesECM.wHsstJPiHEesECM.JAqG++) {
                        if (sDitD[wHsstJPiHEesECM.wHsstJPiHEesECM.JAqG] == 90000) {
                            sDitD[wHsstJPiHEesECM.wHsstJPiHEesECM.JAqG] = ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vErzLFNqCA;
                            break;
                        }
                    }
                }
            }
            else {
                ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.IPeKx = 2;
            }
            wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI++;
            IUrK.ENhv->ENhv.KOiKBKyA++;///
            IUrK.ENhv=IUrK.ENhv->ENhv.DABK;///
        }
        if (wHsstJPiHEesECM.wHsstJPiHEesECM.IPeKx == 0) {//朙绩杣讳卨
            wHsstJPiHEesECM.wHsstJPiHEesECM.HAqrBLIztAv--;
            for (wHsstJPiHEesECM.wHsstJPiHEesECM.JAqG = 0; wHsstJPiHEesECM.wHsstJPiHEesECM.JAqG <= wHsstJPiHEesECM.wHsstJPiHEesECM.qHpFPKuF; wHsstJPiHEesECM.wHsstJPiHEesECM.JAqG++) {
                if (sDitD[wHsstJPiHEesECM.wHsstJPiHEesECM.JAqG] == wHsstJPiHEesECM.wHsstJPiHEesECM.DKAKBKy) {
                    sDitD[wHsstJPiHEesECM.wHsstJPiHEesECM.JAqG] = 90000;
                    break;
                }
            }
            IUrK.ENhv->ENhv.KOiKBKyA++;///
        }
        //刴旃丏丑昉阌芖烁
        for(wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG<=wHsstJPiHEesECM.wHsstJPiHEesECM.qHpFPKuF;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG++){
            wHsstJPiHEesECM.wHsstJPiHEesECM.sDitDKCv=90000;
            for (wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG = 0; wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG <= wHsstJPiHEesECM.wHsstJPiHEesECM.qHpFPKuF; wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG++){
                wHsstJPiHEesECM.wHsstJPiHEesECM.sDitDKCv=(wHsstJPiHEesECM.wHsstJPiHEesECM.sDitDKCv<sDitD[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG]?wHsstJPiHEesECM.wHsstJPiHEesECM.sDitDKCv:sDitD[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG]);
            }
            if(wHsstJPiHEesECM.wHsstJPiHEesECM.sDitDKCv>=ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.rAkzGRCuu){
                wHsstJPiHEesECM.wHsstJPiHEesECM.IPeKx=1;
                wHsstJPiHEesECM.wHsstJPiHEesECM.DKAKBKy = ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.rAkzGRCuu;
            }
            else{
                wHsstJPiHEesECM.wHsstJPiHEesECM.IPeKx=0;
                wHsstJPiHEesECM.wHsstJPiHEesECM.DKAKBKy=wHsstJPiHEesECM.wHsstJPiHEesECM.sDitDKCv;
            }
        }
    }

    //FNmEM
    for(wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG<wHsstJPiHEesECM.wHsstJPiHEesECM.ENhvGSGjuN;wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG++) {

        if(ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].ENhv.IPeKx==2)//ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG]奁贻
            printf("Fail\n");
        else if(ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].ENhv.IPeKx==1){//ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG]戠劵
            //尖昌闸扄轿匮乎FT:MH:丂三昢阐
            wHsstJPiHEesECM.wHsstJPiHEesECM.IAgFGB=ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].ENhv.vErzLFNqCA%60;
            wHsstJPiHEesECM.wHsstJPiHEesECM.CErLMC=(ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].ENhv.vErzLFNqCA%3600)/60;
            wHsstJPiHEesECM.wHsstJPiHEesECM.xKyI=ENhv[wHsstJPiHEesECM.wHsstJPiHEesECM.PFANvLG].ENhv.vErzLFNqCA/3600;
            printf("%02d:%02d:%02d\n",wHsstJPiHEesECM.wHsstJPiHEesECM.xKyI,wHsstJPiHEesECM.wHsstJPiHEesECM.CErLMC,wHsstJPiHEesECM.wHsstJPiHEesECM.IAgFGB);
        }
            ///渇淜牋毆11
        else
            printf("error:ENhvK treated incorrectly.\nerror code:0x00000010");
    }
    return 0;
}
//进程记录
//完成全局变量结构体化
//混淆/稀释
//完成变量名和注释加密，加密方式：维吉尼亚密码加密