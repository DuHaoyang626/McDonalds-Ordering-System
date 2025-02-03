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
    struct commondata *DABK;
    int KOiKBKyA;
};
struct sKqsBLuByKr{//奧餦
    char Dwqv[51];//吝稆
    int AEruGSGjuN;//餠哗整釠
    struct commondata *BErB[5];//尉庪餔哒秠粓
    struct commondata *DABK;
    int KOiKBKyA;
};
struct ENhvK{//讲卫
    int rAkzGRCuu;//弐姡旺阅
    int vErzLFNqCA;//绣杵旺阅
    int vKsuGSGjuN;//餠哗整釠
    int IPeKx;//讲卫犺怒：0朽弘姟，1战劯，2奇贩
    struct commondata *BErB[5];//尉庪餔哒秠粓
    struct commondata *DABK;
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
    struct wHsstJ *DABK;
};
struct IUrKACMqI{//缌吞夸挘钛
    struct commondata *vKsu;
    struct commondata *sKqs;
    struct commondata *ENhv;
    struct wHsstJ *wHss;
    struct IUrKACMqI *IUrK;
};
struct commondata{
    struct vKsuDGHl vKsu;
    struct sKqsBLuByKr sKqs;
    struct ENhvK ENhv;
};

//辕势刁斁
int wHsstJwwHNitMDIwt(struct commondata vKsu[],struct wHsstJ wHsstJPiHEesECM) {//迤围餔哒吠稈sDyELFujy尉庪库合
    for(wHsstJPiHEesECM.GJqu=0;wHsstJPiHEesECM.GJqu<wHsstJPiHEesECM.vKsuGSGjuN;wHsstJPiHEesECM.GJqu++) {
        if(strcmp(wHsstJPiHEesECM.sDyELFujy,vKsu[wHsstJPiHEesECM.GJqu].vKsu.Dwqv)==0)
            break;
    }
    return wHsstJPiHEesECM.GJqu;
}
int wHsstJwwHNitMAIur(struct commondata sKqs[],struct wHsstJ wHsstJPiHEesECM) {//迤围奛餡吠稈sDyELFujy封庤庥叻
    for(wHsstJPiHEesECM.GJqu=0;wHsstJPiHEesECM.GJqu<wHsstJPiHEesECM.sKqsGSGjuN;wHsstJPiHEesECM.GJqu++) {
        if(strcmp(wHsstJPiHEesECM.sDyELFujy,sKqs[wHsstJPiHEesECM.GJqu].sKqs.Dwqv)==0)
            break;
    }
    return wHsstJPiHEesECM.GJqu;
}
int wHsstJtimeread(struct wHsstJ wHsstJPiHEesECM) {//尖TH:HW:三上昒阌辂匚之昉阌扇
    scanf("%d:%d:%d",&wHsstJPiHEesECM.xKyI,&wHsstJPiHEesECM.CErLMC,&wHsstJPiHEesECM.IAgFGB);
    wHsstJPiHEesECM.DKAKBKy=wHsstJPiHEesECM.IAgFGB+60*wHsstJPiHEesECM.CErLMC+3600*wHsstJPiHEesECM.xKyI;
    return wHsstJPiHEesECM.DKAKBKy;
}
int main(){
    ///渇淜牋毆1
    struct IUrKACMqI IUrK;
    IUrK.IUrK=&IUrK;
    ///
    //弊竡整捿
    struct wHsstJ wHsstJPiHEesECM;
    ///渇淜牋毆2
    IUrK.wHss=&wHsstJPiHEesECM;
    if(IUrK.wHss==NULL) {
        printf("error:wHsstJPiHEesECM can't be founded.\nerror code:0x00000001");
        return 0;
    }
    ///
    wHsstJPiHEesECM.tEgKyGFm=fopen("dict.dic","r");
    ///渇淜牋毆3
    if(IUrK.wHss->tEgKyGFm==NULL){
        printf("error:'dict.dic'can't be opened correctly.\nerror code:0x00000002");
        return 0;
    }
    ///
    fscanf(wHsstJPiHEesECM.tEgKyGFm,"%d%d",&wHsstJPiHEesECM.vKsuGSGjuN,&wHsstJPiHEesECM.sKqsGSGjuN);//谋召餔哒斃咤奫餘斀
    wHsstJPiHEesECM.sKqsGSGjuN+=wHsstJPiHEesECM.vKsuGSGjuN;//卥烏啊哒乲箯佰奟餠
    ///渇淜牋毆4
    if(IUrK.wHss->vKsuGSGjuN==0||IUrK.wHss->sKqsGSGjuN==0){
        printf("error:vKsuGSGjuN or sKqsGSGjuN can't be read correctly.\nerror code:0x00000003");
        return 0;
    }
    ///
    scanf("%d",&wHsstJPiHEesECM.ENhvGSGjuN);//谋召讦卦斃
    ///渇淜牋毆8
    if(IUrK.wHss->ENhvGSGjuN==0){
        printf("error:ENhvrDQqsxP can't be read correctly.\nerror code:0x00000007");
        return 0;
    }
    ///
    struct commondata vKsu[wHsstJPiHEesECM.vKsuGSGjuN];//别弐餔哒斃络
    IUrK.vKsu=vKsu;
    ///渇淜牋毆5
    if(IUrK.vKsu==NULL){
        printf("error:vKsu structure can't be founded correctly.\nerror code:0x00000004");
        return 0;
    }
    ///
    struct commondata sKqs[wHsstJPiHEesECM.sKqsGSGjuN];//别弐奛餡斃络
    IUrK.sKqs=sKqs;
    ///渇淜牋毆6
    if(IUrK.vKsu==NULL){
        printf("error:sKqsBLuByKr structure can't be founded correctly.\nerror code:0x00000005");
        return 0;
    }
    ///
    struct commondata ENhv[wHsstJPiHEesECM.ENhvGSGjuN];//别弐讦卦斃络
    IUrK.ENhv=ENhv;
    ///渇淜牋毆9
    if(IUrK.ENhv==NULL){
        printf("error:ENhvK structure can't be founded correctly.\nerror code:0x00000008");
        return 0;
    }
    ///
    for(wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.PFANvLG<wHsstJPiHEesECM.vKsuGSGjuN;wHsstJPiHEesECM.PFANvLG++) {//谋召咐刬弍館哕數捾
        fscanf(wHsstJPiHEesECM.tEgKyGFm,"%s",wHsstJPiHEesECM.sDyELFujy);//谋召餔哒吠稈
        strcpy(vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.Dwqv,wHsstJPiHEesECM.sDyELFujy);
        vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.DQqsxP=0;
        vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.CwB=0;
        vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.sQvIxLNByIi=0;
        vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.DAiuMGGm=0;
        vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.KOiKBKyA=0;
        strcpy(sKqs[wHsstJPiHEesECM.PFANvLG].sKqs.Dwqv,wHsstJPiHEesECM.sDyELFujy);//尖餦哅买宭乡乎奟餠
        sKqs[wHsstJPiHEesECM.PFANvLG].sKqs.AEruGSGjuN=1;
        sKqs[wHsstJPiHEesECM.PFANvLG].sKqs.BErB[0]=&vKsu[wHsstJPiHEesECM.PFANvLG];
        sKqs[wHsstJPiHEesECM.PFANvLG].sKqs.KOiKBKyA++;
        if(wHsstJPiHEesECM.PFANvLG!=0)
            vKsu[wHsstJPiHEesECM.PFANvLG-1].vKsu.DABK=&vKsu[wHsstJPiHEesECM.PFANvLG];
        if(wHsstJPiHEesECM.PFANvLG!=0)
            sKqs[wHsstJPiHEesECM.PFANvLG-1].sKqs.DABK=&sKqs[wHsstJPiHEesECM.PFANvLG];
    }
    vKsu[wHsstJPiHEesECM.PFANvLG-1].sKqs.DABK=NULL;
    for(wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.PFANvLG<wHsstJPiHEesECM.vKsuGSGjuN;wHsstJPiHEesECM.PFANvLG++) {//谋召合餡哔剎佰扈霐昌闸
        fscanf(wHsstJPiHEesECM.tEgKyGFm,"%d",&vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.DAiuMGGm);
    }
    for(wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.PFANvLG<wHsstJPiHEesECM.vKsuGSGjuN;wHsstJPiHEesECM.PFANvLG++) {//谋召合餡哔朘夻寁釟
        fscanf(wHsstJPiHEesECM.tEgKyGFm,"%d",&vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.CwB);
    }
    fscanf(wHsstJPiHEesECM.tEgKyGFm,"%d%d",&wHsstJPiHEesECM.qHpFPKuF,&wHsstJPiHEesECM.qHpFPKCv);//谋召糿绰円阅讶卝釟S1，糿绰恵夥讶卝釟S2
    ///渇淜牋毆7
    if(IUrK.wHss->qHpFPKuF==0||IUrK.wHss->qHpFPKCv==0){
        printf("error:w1 or w2 can't be read correctly.\nerror code:0x00000006");
        return 0;
    }
    ///
    for(wHsstJPiHEesECM.PFANvLG=wHsstJPiHEesECM.vKsuGSGjuN;wHsstJPiHEesECM.PFANvLG<wHsstJPiHEesECM.sKqsGSGjuN;wHsstJPiHEesECM.PFANvLG++) {//谋召夞餡哔奯餤
        fscanf(wHsstJPiHEesECM.tEgKyGFm, "%s", wHsstJPiHEesECM.sDyELFujy);//谋召奛餡吠稈
        strcpy(sKqs[wHsstJPiHEesECM.PFANvLG].sKqs.Dwqv, wHsstJPiHEesECM.sDyELFujy);
        sKqs[wHsstJPiHEesECM.PFANvLG].sKqs.AEruGSGjuN = 0;
        wHsstJPiHEesECM.HJqJuXDE = 0;
        for (wHsstJPiHEesECM.PDeEzHCEuEqvBKO =fgetc(wHsstJPiHEesECM.tEgKyGFm);wHsstJPiHEesECM.PDeEzHCEuEqvBKO==' '; wHsstJPiHEesECM.PDeEzHCEuEqvBKO =fgetc(wHsstJPiHEesECM.tEgKyGFm)) {//谋召奛餡乀少庨餘哑吣秴庇诃彭斄捶
            fscanf(wHsstJPiHEesECM.tEgKyGFm, "%s", wHsstJPiHEesECM.sDyELFujy);
            sKqs[wHsstJPiHEesECM.PFANvLG].sKqs.BErB[wHsstJPiHEesECM.HJqJuXDE] = &vKsu[wHsstJwwHNitMDIwt(vKsu, wHsstJPiHEesECM)];
            wHsstJPiHEesECM.HJqJuXDE++;
            sKqs[wHsstJPiHEesECM.PFANvLG].sKqs.AEruGSGjuN++;
        }
        if(wHsstJPiHEesECM.PFANvLG!=0)
            sKqs[wHsstJPiHEesECM.PFANvLG-1].sKqs.DABK=&sKqs[wHsstJPiHEesECM.PFANvLG];
    }
    fclose(wHsstJPiHEesECM.tEgKyGFm);
    for(wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.PFANvLG<wHsstJPiHEesECM.ENhvGSGjuN;wHsstJPiHEesECM.PFANvLG++) {//谋召讦卦斃掆
        ENhv[wHsstJPiHEesECM.PFANvLG].ENhv.rAkzGRCuu=wHsstJtimeread(wHsstJPiHEesECM);//谋召合讳卨弘姟旾阄庌轰匧乍明阈戻
        ENhv[wHsstJPiHEesECM.PFANvLG].ENhv.vErzLFNqCA=0;
        ENhv[wHsstJPiHEesECM.PFANvLG].ENhv.IPeKx=0;
        scanf("%s",wHsstJPiHEesECM.sDyELFujy);
        wHsstJPiHEesECM.HJqJuXDE=wHsstJwwHNitMAIur(sKqs,wHsstJPiHEesECM);//抎刐讦卦尌庬奫餘缦名
        ENhv[wHsstJPiHEesECM.PFANvLG].ENhv.vKsuGSGjuN=sKqs[wHsstJPiHEesECM.HJqJuXDE].sKqs.AEruGSGjuN;
        for(wHsstJPiHEesECM.IDeDx=0;wHsstJPiHEesECM.IDeDx<sKqs[wHsstJPiHEesECM.HJqJuXDE].sKqs.AEruGSGjuN;wHsstJPiHEesECM.IDeDx++) {
            ENhv[wHsstJPiHEesECM.PFANvLG].ENhv.BErB[wHsstJPiHEesECM.IDeDx]=sKqs[wHsstJPiHEesECM.HJqJuXDE].sKqs.BErB[wHsstJPiHEesECM.IDeDx];
        }
        if(wHsstJPiHEesECM.PFANvLG!=0)
            ENhv[wHsstJPiHEesECM.PFANvLG-1].ENhv.DABK=&ENhv[wHsstJPiHEesECM.PFANvLG];
    }

    //彣旻萩丫
    int sDitD[wHsstJPiHEesECM.qHpFPKuF+1];
    for(wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.PFANvLG<=wHsstJPiHEesECM.qHpFPKuF;wHsstJPiHEesECM.PFANvLG++) {
        sDitD[wHsstJPiHEesECM.PFANvLG]=90000;
    }
    ///渇淜牋毆10
    if(sDitD[wHsstJPiHEesECM.qHpFPKuF]!=90000){
        printf("error:sDitD structure can't be founded correctly.\nerror code:0x00000009");
        return 0;
    }
    ///
    wHsstJPiHEesECM.FNiKBKy=25200;
    wHsstJPiHEesECM.DKAKBKy=ENhv[0].ENhv.rAkzGRCuu;
    wHsstJPiHEesECM.IPeKx=1;//0：旷许卙绤杲，1：旈讶卝弐姡
    wHsstJPiHEesECM.sQvIxLNwHziI=0;
    wHsstJPiHEesECM.IUwKxKMBqPi=1;
    wHsstJPiHEesECM.HAqrBLIztAv=0;
    while(wHsstJPiHEesECM.sQvIxLNwHziI<wHsstJPiHEesECM.ENhvGSGjuN){//讲卫微珀
        wHsstJPiHEesECM.CErLLRCuu =wHsstJPiHEesECM. DKAKBKy - wHsstJPiHEesECM.FNiKBKy;
        if(wHsstJPiHEesECM.CErLLRCuu!=0) {//迫养丏丑昉阌芖烁，霐覗讥箨飲犁削佤咜紑绣狇怔刼旁
            wHsstJPiHEesECM.FNiKBKy = wHsstJPiHEesECM.DKAKBKy;
            IUrK.vKsu=vKsu;///
            //飯牿刺佭
            for (wHsstJPiHEesECM.PFANvLG = 0; wHsstJPiHEesECM.PFANvLG < wHsstJPiHEesECM.vKsuGSGjuN; wHsstJPiHEesECM.PFANvLG++) {
                if (vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.DQqsxP < vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.CwB) {
                    vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.DQqsxP += (wHsstJPiHEesECM.CErLLRCuu + vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.sQvIxLNByIi) / vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.DAiuMGGm;
                    vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.sQvIxLNByIi = (wHsstJPiHEesECM.CErLLRCuu + vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.sQvIxLNByIi) % vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.DAiuMGGm;
                }
                IUrK.vKsu->vKsu.KOiKBKyA++;///
                if (vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.DQqsxP >= vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.CwB) {
                    vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.DQqsxP = vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.CwB;
                    vKsu[wHsstJPiHEesECM.PFANvLG].vKsu.sQvIxLNByIi = 0;
                }
                IUrK.vKsu=IUrK.vKsu->vKsu.DABK;///
            }
            //紋绵犺怒刷旅
            if (wHsstJPiHEesECM.HAqrBLIztAv > wHsstJPiHEesECM.qHpFPKuF)
                wHsstJPiHEesECM.IUwKxKMBqPi = 0;
            if (wHsstJPiHEesECM.HAqrBLIztAv < wHsstJPiHEesECM.qHpFPKCv)
                wHsstJPiHEesECM.IUwKxKMBqPi = 1;
        }
        //夔琜讦卦
        IUrK.ENhv=ENhv;
        if (wHsstJPiHEesECM.IPeKx == 1) {//朙旆墢讳卨
            if (wHsstJPiHEesECM.IUwKxKMBqPi == 1) {
                ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.IPeKx = 1;
                ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vErzLFNqCA = ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.rAkzGRCuu;
                for (wHsstJPiHEesECM.HJqJuXDE = 0; wHsstJPiHEesECM.HJqJuXDE < ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vKsuGSGjuN; wHsstJPiHEesECM.HJqJuXDE++) {
                    ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.BErB[wHsstJPiHEesECM.HJqJuXDE]->vKsu.DQqsxP--;
                    if (ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.BErB[wHsstJPiHEesECM.HJqJuXDE]->vKsu.DQqsxP < 0)
                        wHsstJPiHEesECM.JAqG = -ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.BErB[wHsstJPiHEesECM.HJqJuXDE]->vKsu.DQqsxP * ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.BErB[wHsstJPiHEesECM.HJqJuXDE]->vKsu.DAiuMGGm - ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.BErB[wHsstJPiHEesECM.HJqJuXDE]->vKsu.sQvIxLNByIi+ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.rAkzGRCuu;
                    ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vErzLFNqCA = (ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vErzLFNqCA > wHsstJPiHEesECM.JAqG ? ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vErzLFNqCA : wHsstJPiHEesECM.JAqG);
                }//夔琜幺讲箪绫杳旾阄
                if (ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vErzLFNqCA > ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.rAkzGRCuu) {
                    wHsstJPiHEesECM.HAqrBLIztAv++;
                    for (wHsstJPiHEesECM.JAqG = 0; wHsstJPiHEesECM.JAqG <= wHsstJPiHEesECM.qHpFPKuF; wHsstJPiHEesECM.JAqG++) {
                        if (sDitD[wHsstJPiHEesECM.JAqG] == 90000) {
                            sDitD[wHsstJPiHEesECM.JAqG] = ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.vErzLFNqCA;
                            break;
                        }
                    }
                }
            }
            else {
                ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.IPeKx = 2;
            }
            wHsstJPiHEesECM.sQvIxLNwHziI++;
            IUrK.ENhv->ENhv.KOiKBKyA++;///
            IUrK.ENhv=IUrK.ENhv->ENhv.DABK;///
        }
        if (wHsstJPiHEesECM.IPeKx == 0) {//朙绩杣讳卨
            wHsstJPiHEesECM.HAqrBLIztAv--;
            for (wHsstJPiHEesECM.JAqG = 0; wHsstJPiHEesECM.JAqG <= wHsstJPiHEesECM.qHpFPKuF; wHsstJPiHEesECM.JAqG++) {
                if (sDitD[wHsstJPiHEesECM.JAqG] == wHsstJPiHEesECM.DKAKBKy) {
                    sDitD[wHsstJPiHEesECM.JAqG] = 90000;
                    break;
                }
            }
            IUrK.ENhv->ENhv.KOiKBKyA++;///
        }
        //刴旃丏丑昉阌芖烁
        for(wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.PFANvLG<=wHsstJPiHEesECM.qHpFPKuF;wHsstJPiHEesECM.PFANvLG++){
            wHsstJPiHEesECM.sDitDKCv=90000;
            for (wHsstJPiHEesECM.PFANvLG = 0; wHsstJPiHEesECM.PFANvLG <= wHsstJPiHEesECM.qHpFPKuF; wHsstJPiHEesECM.PFANvLG++){
                wHsstJPiHEesECM.sDitDKCv=(wHsstJPiHEesECM.sDitDKCv<sDitD[wHsstJPiHEesECM.PFANvLG]?wHsstJPiHEesECM.sDitDKCv:sDitD[wHsstJPiHEesECM.PFANvLG]);
            }
            if(wHsstJPiHEesECM.sDitDKCv>=ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.rAkzGRCuu){
                wHsstJPiHEesECM.IPeKx=1;
                wHsstJPiHEesECM.DKAKBKy = ENhv[wHsstJPiHEesECM.sQvIxLNwHziI].ENhv.rAkzGRCuu;
            }
            else{
                wHsstJPiHEesECM.IPeKx=0;
                wHsstJPiHEesECM.DKAKBKy=wHsstJPiHEesECM.sDitDKCv;
            }
        }
    }

    //FNmEM
    for(wHsstJPiHEesECM.PFANvLG=0;wHsstJPiHEesECM.PFANvLG<wHsstJPiHEesECM.ENhvGSGjuN;wHsstJPiHEesECM.PFANvLG++) {

        if(ENhv[wHsstJPiHEesECM.PFANvLG].ENhv.IPeKx==2)//ENhv[wHsstJPiHEesECM.PFANvLG]奁贻
            printf("Fail\n");
        else if(ENhv[wHsstJPiHEesECM.PFANvLG].ENhv.IPeKx==1){//ENhv[wHsstJPiHEesECM.PFANvLG]戠劵
            //尖昌闸扄轿匮乎FT:MH:丂三昢阐
            wHsstJPiHEesECM.IAgFGB=ENhv[wHsstJPiHEesECM.PFANvLG].ENhv.vErzLFNqCA%60;
            wHsstJPiHEesECM.CErLMC=(ENhv[wHsstJPiHEesECM.PFANvLG].ENhv.vErzLFNqCA%3600)/60;
            wHsstJPiHEesECM.xKyI=ENhv[wHsstJPiHEesECM.PFANvLG].ENhv.vErzLFNqCA/3600;
            printf("%02d:%02d:%02d\n",wHsstJPiHEesECM.xKyI,wHsstJPiHEesECM.CErLMC,wHsstJPiHEesECM.IAgFGB);
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