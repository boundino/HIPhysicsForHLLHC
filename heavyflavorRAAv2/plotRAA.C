#include "xjjrootuti.h"
#include "plotRAA.h"
#include "datapoints/RAA_CMS_Charged_0_100.h"
#include "datapoints/RAA_CMS_Charged_0_5.h"

Double_t errorD0lowpt = 0.30; // 30%
Double_t errorsystD0lowpt = 0.137405/0.722896; // lowest pt bin
Float_t trkerr = 0.025; //minimum tracking syst (4% => 2.5%)
Float_t muerr = 0.01; //mu TnP syst, 0.5%x2 

void plotRAA(Float_t lumiTG_D0_before, Float_t lumiMB_D0_before, Float_t lumiTG_Bp_before, Float_t lumiTG_Charged_before, Float_t lumiMB_Charged_before, 
             Float_t lumiTG_after, Float_t lumiMB_after)
{

  Float_t lumiTG_Bs_before = lumiTG_Bp_before;

  std::cout<<std::endl;
  std::cout<<"  -------------------- Before --------------------"<<std::endl;
  std::cout<<std::setiosflags(std::ios::left)<<std::setw(37)<<"   lumi (D0 trigger): "<<std::setw(7)<<lumiTG_D0_before<<" nb-1"<<std::endl;
  std::cout<<std::setiosflags(std::ios::left)<<std::setw(37)<<"   lumi (D0 MB): "<<std::setw(7)<<lumiMB_D0_before<<" nb-1"<<std::endl;
  std::cout<<std::setiosflags(std::ios::left)<<std::setw(37)<<"   lumi (B+ trigger): "<<std::setw(7)<<lumiTG_Bp_before<<" nb-1"<<std::endl;
  std::cout<<std::setiosflags(std::ios::left)<<std::setw(37)<<"   lumi (Bs trigger): "<<std::setw(7)<<lumiTG_Bs_before<<" nb-1"<<std::endl;
  std::cout<<std::setiosflags(std::ios::left)<<std::setw(37)<<"   lumi (charged hadron trigger): "<<std::setw(7)<<lumiTG_Charged_before<<" nb-1"<<std::endl;
  std::cout<<std::setiosflags(std::ios::left)<<std::setw(37)<<"   lumi (charged hadron MB): "<<std::setw(7)<<lumiMB_Charged_before<<" nb-1"<<std::endl;
  std::cout<<"  -------------------- after ---------------------"<<std::endl;
  std::cout<<std::setiosflags(std::ios::left)<<std::setw(37)<<"   lumi (trigger): "<<std::setw(7)<<lumiTG_after<<" nb-1"<<std::endl;
  std::cout<<std::setiosflags(std::ios::left)<<std::setw(37)<<"   lumi (MB): "<<std::setw(7)<<lumiMB_after<<" nb-1"<<std::endl;
  std::cout<<"  ------------------------------------------------"<<std::endl;
  std::cout<<std::endl;

  Float_t lumiweightTG_D0 = TMath::Sqrt(lumiTG_after/lumiTG_D0_before);
  Float_t lumiweightMB_D0 = TMath::Sqrt(lumiMB_after/lumiMB_D0_before);
  Float_t lumiweightTG_Bp = TMath::Sqrt(lumiTG_after/lumiTG_Bp_before);
  Float_t lumiweightTG_Bs = TMath::Sqrt(lumiTG_after/lumiTG_Bs_before);
  Float_t lumiweightTG_NPJpsi = TMath::Sqrt(lumiTG_after/lumiTG_Bp_before);
  Float_t lumiweightMB_Charged = TMath::Sqrt(lumiMB_after/lumiMB_Charged_before);
  Float_t lumiweightTG_Charged = TMath::Sqrt(lumiTG_after/lumiTG_Charged_before);

  TCanvas *c2, *c1;

  // Dzero

  const int nxD0 = 19;
  Double_t xD0[nxD0+1] = {0.,0.5,1.0,1.5,2.0,3.0,4.0,5.0,6.0,8.0,10.0,12.5,15.0,20.0,25.0,30.0,40.0,60.0,100.0,200.0};
  Double_t thresholdD0_theory = 4;
  Double_t thresholdD0_trigger = 12;
  TH1D* hRAA_D0_before = new TH1D("hRAA_D0_before","",nxD0,xD0);
  TH1D* hRAA_D0_after = new TH1D("hRAA_D0_after","",nxD0,xD0);
  Double_t axD0[nxD0],exD0[nxD0],ayD0before[nxD0],eyD0before[nxD0],ayD0after[nxD0],eyD0after[nxD0];
  std::ifstream getD0_theory("datapoints/RAA_PHSD_D0_0_10.dat");
  for(int i=0;i<thresholdD0_theory;i++)
    {
      Double_t centervalue,tem;
      Float_t errminimum = trkerr*2;
      Double_t lumiweight_D0 = (i<thresholdD0_trigger)?lumiweightMB_D0:lumiweightTG_D0;
      getD0_theory>>tem>>centervalue>>tem;
      hRAA_D0_before->SetBinContent(i+1,(i<2)?-1:centervalue);
      hRAA_D0_before->SetBinError(i+1,centervalue*errorD0lowpt);
      hRAA_D0_after->SetBinContent(i+1,centervalue);
      hRAA_D0_after->SetBinError(i+1,centervalue*errorD0lowpt/lumiweight_D0);
      axD0[i] = (xD0[i+1]+xD0[i])/2.;
      exD0[i] = (xD0[i+1]-xD0[i])/2.;
      ayD0before[i] = (i<2)?-1:centervalue;
      eyD0before[i] = centervalue*errorsystD0lowpt;
      ayD0after[i] = centervalue;
      eyD0after[i] = (centervalue*errorsystD0lowpt/lumiweight_D0)>(errminimum*centervalue)?(centervalue*errorsystD0lowpt/lumiweight_D0):(errminimum*centervalue);
    }
  getD0_theory.close();
  getD0_theory.clear();
  std::ifstream getD0_CMS("datapoints/RAA_CMS_D0_0_100.dat");
  for(int i=thresholdD0_theory;i<nxD0;i++)
    {
      Double_t centervalue,centervalueafter,staterror,systerror,tem;
      Float_t errminimum = trkerr*2;
      Double_t lumiweight_D0 = (i<thresholdD0_trigger)?lumiweightMB_D0:lumiweightTG_D0;
      getD0_CMS>>tem>>tem>>tem>>centervalue>>centervalueafter>>staterror>>systerror>>tem;
      hRAA_D0_before->SetBinContent(i+1,centervalue);
      hRAA_D0_before->SetBinError(i+1,staterror);
      hRAA_D0_after->SetBinContent(i+1,centervalueafter);
      hRAA_D0_after->SetBinError(i+1,staterror/lumiweight_D0);
      axD0[i] = (xD0[i+1]+xD0[i])/2.;
      exD0[i] = (xD0[i+1]-xD0[i])/2.;
      ayD0before[i] = centervalue;
      eyD0before[i] = systerror;
      ayD0after[i] = centervalueafter;
      eyD0after[i] = (systerror/lumiweight_D0)>(errminimum*centervalueafter)?(systerror/lumiweight_D0):(errminimum*centervalueafter);
    }
  getD0_CMS.close();
  getD0_CMS.clear();
  TGraphErrors* gRAA_D0_before = new TGraphErrors(nxD0,axD0,ayD0before,exD0,eyD0before);
  gRAA_D0_before->SetName("gRAA_D0_before");
  TGraphErrors* gRAA_D0_after = new TGraphErrors(nxD0,axD0,ayD0after,exD0,eyD0after);
  gRAA_D0_after->SetName("gRAA_D0_after");

  // Bplus

  const int nxBp = 7;
  Double_t xBp[nxBp+1] = {5.0,6.0,7.0,10.0,15.0,20.0,30.0,50.0};
  TH1D* hRAA_Bp_before = new TH1D("hRAA_Bp_before","",nxBp,xBp);
  TH1D* hRAA_Bp_after = new TH1D("hRAA_Bp_after","",nxBp,xBp);
  Double_t axBp[nxBp],exBp[nxBp],ayBpbefore[nxBp],eyBpbefore[nxBp],ayBpafter[nxBp],eyBpafter[nxBp];
  std::ifstream getBp_theory("datapoints/RAA_Magdalena_Bp_0_100.dat");
  for(int i=0;i<nxBp;i++)
    {
      Double_t centervalue,tem;
      // Float_t errminimum = trkerr*3;
      Float_t errminimum = TMath::Sqrt(trkerr*trkerr+muerr*muerr);
      getBp_theory>>tem>>centervalue;
      hRAA_Bp_before->SetBinContent(i+1,centervalue);
      hRAA_Bp_after->SetBinContent(i+1,centervalue);
      axBp[i] = (xBp[i+1]+xBp[i])/2.;
      exBp[i] = (xBp[i+1]-xBp[i])/2.;
      ayBpbefore[i] = centervalue;
      ayBpafter[i] = centervalue;
    }
  getBp_theory.close();
  getBp_theory.clear();
  std::ifstream getBp_CMS("datapoints/RAA_CMS_Bp_0_100.dat");
  for(int i=0;i<nxBp;i++)
    {
      Double_t centervalue,staterror,systerror,tem;
      // Float_t errminimum = trkerr*3;
      Float_t errminimum = TMath::Sqrt(trkerr*trkerr+muerr*muerr);
      getBp_CMS>>tem>>tem>>tem>>centervalue>>staterror>>systerror>>tem;
      hRAA_Bp_before->SetBinError(i+1,ayBpbefore[i]*staterror/centervalue);
      hRAA_Bp_after->SetBinError(i+1,(ayBpafter[i]*staterror/centervalue)/lumiweightTG_Bp);
      eyBpbefore[i] = ayBpbefore[i]*systerror/centervalue;
      eyBpafter[i] = ((ayBpafter[i]*systerror/centervalue)/lumiweightTG_Bp)>(errminimum*ayBpafter[i])?((ayBpafter[i]*systerror/centervalue)/lumiweightTG_Bp):(errminimum*ayBpafter[i]);
    }
  getBp_CMS.close();
  getBp_CMS.clear();
  TGraphErrors* gRAA_Bp_before = new TGraphErrors(nxBp,axBp,ayBpbefore,exBp,eyBpbefore);
  gRAA_Bp_before->SetName("gRAA_Bp_before");
  TGraphErrors* gRAA_Bp_after = new TGraphErrors(nxBp,axBp,ayBpafter,exBp,eyBpafter);
  gRAA_Bp_after->SetName("gRAA_Bp_after");

  // Bsubs

  const int nxBs = 3;
  Double_t xBs[nxBs+1] = {7.0,15.0,20.0,50.0};
  TH1D* hRAA_Bs_before = new TH1D("hRAA_Bs_before","",nxBs,xBs);
  TH1D* hRAA_Bs_after = new TH1D("hRAA_Bs_after","",nxBs,xBs);
  Double_t axBs[nxBs],exBs[nxBs],ayBsbefore[nxBs],eyBsbefore[nxBs],ayBsafter[nxBs],eyBsafter[nxBs];
  std::ifstream getBs("datapoints/RAA_CMS_Bs_0_100_theorycenter.dat");
  for(int i=0;i<nxBs;i++)
    {
      Double_t centervalue,staterror,systerror,tem;
      // Float_t errminimum = trkerr*4;
      Float_t errminimum = TMath::Sqrt(trkerr*2*trkerr*2+muerr*muerr);
      getBs>>tem>>tem>>tem>>centervalue>>staterror>>systerror;
      hRAA_Bs_before->SetBinContent(i+1,centervalue);
      hRAA_Bs_after->SetBinContent(i+1,centervalue);
      axBs[i] = (xBs[i+1]+xBs[i])/2.;
      // exBs[i] = (xBs[i+1]-xBs[i])/2.;
      exBs[i] = axBs[i]*0.08;
      ayBsbefore[i] = centervalue;
      ayBsafter[i] = centervalue;

      hRAA_Bs_before->SetBinError(i+1,staterror);
      hRAA_Bs_after->SetBinError(i+1,staterror/lumiweightTG_Bs);
      eyBsbefore[i] = systerror;
      eyBsafter[i] = (systerror/lumiweightTG_Bs)>(errminimum*ayBsafter[i])?(systerror/lumiweightTG_Bs):(errminimum*ayBsafter[i]);
    }
  getBs.close();
  getBs.clear();
  TGraphErrors* gRAA_Bs_before = new TGraphErrors(nxBs,axBs,ayBsbefore,exBs,eyBsbefore);
  gRAA_Bs_before->SetName("gRAA_Bs_before");
  TGraphErrors* gRAA_Bs_after = new TGraphErrors(nxBs,axBs,ayBsafter,exBs,eyBsafter);
  gRAA_Bs_after->SetName("gRAA_Bs_after");

  // NPJpsi

  const int nxNPJpsi = 15;
  Double_t axNPJpsi[nxNPJpsi] = {3.75, 5, 6, 7, 8, 9, 10.25, 12, 14, 16.25, 18.75, 22.5, 27.5, 32.5, 42.5};
  Double_t exstatNPJpsi[nxNPJpsi],exsystNPJpsi[nxNPJpsi],ayNPJpsibefore[nxNPJpsi],eystatNPJpsibefore[nxNPJpsi],eysystNPJpsibefore[nxNPJpsi],ayNPJpsiafter[nxNPJpsi],eystatNPJpsiafter[nxNPJpsi],eysystNPJpsiafter[nxNPJpsi];
  std::ifstream getNPJpsi_CMS("datapoints/RAA_CMS_NPJpsi_0_100.dat");
  for(int i=0;i<nxNPJpsi;i++)
    {
      Double_t xerror,centervalue,centervalueafter,staterror,systerror,tem;
      Float_t errminimum = muerr;
      getNPJpsi_CMS>>tem>>xerror>>centervalue>>centervalueafter>>systerror>>staterror;
      exstatNPJpsi[i] = xerror;
      exsystNPJpsi[i] = axNPJpsi[i]*0.08;
      ayNPJpsibefore[i] = centervalue;
      ayNPJpsiafter[i] = centervalueafter;
      eystatNPJpsibefore[i] = staterror;
      eysystNPJpsibefore[i] = systerror;
      // eystatNPJpsiafter[i] = staterror/lumiweightTG_NPJpsi;
      eysystNPJpsiafter[i] = (systerror/lumiweightTG_NPJpsi)>(errminimum*ayNPJpsiafter[i])?(systerror/lumiweightTG_NPJpsi):(errminimum*ayNPJpsiafter[i]);
      eysystNPJpsiafter[i] = systerror/lumiweightTG_NPJpsi;
    }
  getNPJpsi_CMS.close();
  getNPJpsi_CMS.clear();
  TGraphErrors* gRAA_NPJPsi_stat_before = new TGraphErrors(nxNPJpsi, axNPJpsi, ayNPJpsibefore, exstatNPJpsi, eystatNPJpsibefore);
  gRAA_NPJPsi_stat_before->SetName("gRAA_NPJPsi_stat_before");
  TGraphErrors* gRAA_NPJPsi_syst_before = new TGraphErrors(nxNPJpsi, axNPJpsi, ayNPJpsibefore, exsystNPJpsi, eysystNPJpsibefore);
  gRAA_NPJPsi_syst_before->SetName("gRAA_NPJPsi_syst_before");
  TGraphErrors* gRAA_NPJPsi_stat_after = new TGraphErrors(nxNPJpsi, axNPJpsi, ayNPJpsiafter, exstatNPJpsi, eystatNPJpsiafter);
  gRAA_NPJPsi_stat_after->SetName("gRAA_NPJPsi_stat_after");
  TGraphErrors* gRAA_NPJPsi_syst_after = new TGraphErrors(nxNPJpsi, axNPJpsi, ayNPJpsiafter, exsystNPJpsi, eysystNPJpsiafter);
  gRAA_NPJPsi_syst_after->SetName("gRAA_NPJPsi_syst_after");

  // Charged hadrons

  const int nxCharged = 37;
  Double_t xCharged[nxCharged+1] = {0.4, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400};
  const int nxChargedextend = 38;
  Double_t xChargedextend[nxChargedextend+1] = {0.4, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400, 600};
  TH1D* hRAA_Charged_before_cent0100 = new TH1D("hRAA_Charged_before_cent0100","",nxCharged,xCharged);
  TH1D* hRAA_Charged_after_cent0100 = new TH1D("hRAA_Charged_after_cent0100","",nxCharged,xCharged);
  TH1D* hRAA_Charged_before_cent010 = new TH1D("hRAA_Charged_before_cent010","",nxChargedextend,xChargedextend);
  TH1D* hRAA_Charged_after_cent010 = new TH1D("hRAA_Charged_after_cent010","",nxChargedextend,xChargedextend);
  RAA_CMS_Charged_0_100::setbincontentsCharged(hRAA_Charged_before_cent0100,1.);
  RAA_CMS_Charged_0_100::setbincontentsCharged(hRAA_Charged_after_cent0100, lumiweightTG_Charged ,lumiweightMB_Charged);
  RAA_CMS_Charged_0_5::setbincontentsCharged(hRAA_Charged_before_cent010,1.);
  RAA_CMS_Charged_0_5::setbincontentsCharged(hRAA_Charged_after_cent010, lumiweightTG_Charged ,lumiweightMB_Charged);
  TGraphErrors* gRAA_Charged_before_cent0100 = (TGraphErrors*)gRAA_Bp_before->Clone("gRAA_Charged_before_cent0100");
  TGraphErrors* gRAA_Charged_after_cent0100 = (TGraphErrors*)gRAA_Bp_after->Clone("gRAA_Charged_after_cent0100");
  TGraphErrors* gRAA_Charged_before_cent010 = (TGraphErrors*)gRAA_Bp_before->Clone("gRAA_Charged_before_cent010");
  TGraphErrors* gRAA_Charged_after_cent010 = (TGraphErrors*)gRAA_Bp_after->Clone("gRAA_Charged_after_cent010");
  
  // Dsubs

  const int nxDs = 5;
  Double_t xDs[nxDs+1] = {4.0,5.0,6.0,8.0,10.0,12.5};
  TH1D* hRAA_Ds_before = new TH1D("hRAA_Ds_before","",nxDs,xDs);
  TH1D* hRAA_Ds_after = new TH1D("hRAA_Ds_after","",nxDs,xDs);
  Double_t axDs[nxDs],exDs[nxDs],ayDsbefore[nxDs],eyDsbefore[nxDs],ayDsafter[nxDs],eyDsafter[nxDs];
  std::ifstream getDs_Theory("datapoints/RAA_PHSD_D0forDs_0_10.dat");
  for(int i=0;i<nxDs;i++)
    {
      Double_t centervalue,tem;
      getDs_Theory>>tem>>centervalue>>tem;
      hRAA_Ds_before->SetBinContent(i+1,centervalue);
      hRAA_Ds_after->SetBinContent(i+1,centervalue);
      axDs[i] = (xDs[i+1]+xDs[i])/2.;
      exDs[i] = (xDs[i+1]-xDs[i])/2.;
      ayDsbefore[i] = centervalue;
      ayDsafter[i] = centervalue;
    }
  getDs_Theory.close();
  getDs_Theory.clear();
  std::ifstream getDs_CMS("datapoints/RAA_CMS_D0forDs_0_100.dat");
  for(int i=0;i<nxDs;i++)
    {
      Double_t centervalue,staterror,systerror,tem;
      getDs_CMS>>tem>>tem>>tem>>centervalue>>staterror>>systerror>>tem;
      hRAA_Ds_before->SetBinError(i+1,ayDsbefore[i]*staterror/centervalue);
      hRAA_Ds_after->SetBinError(i+1,(ayDsafter[i]*staterror/centervalue)/lumiweightMB_D0);
      eyDsbefore[i] = ayDsbefore[i]*systerror/centervalue;
      eyDsafter[i] = (ayDsafter[i]*systerror/centervalue)/lumiweightMB_D0;
    }
  getDs_CMS.close();
  getDs_CMS.clear();
  std::ifstream getDs_Alice("datapoints/RAA_Alice_DsOverD0_30_50.dat");
  for(int i=0;i<nxDs;i++)
    {
      Float_t errminimum = trkerr*3;
      Double_t centervalue,centervalueafter,tem,centerPbPb,centerPbPbafter,centerPP;
      getDs_Alice>>tem>>centerPbPb>>centerPbPbafter>>tem>>centerPP;
      centervalue = centerPbPb/centerPP;
      centervalueafter = centerPbPbafter/centerPP;
      hRAA_Ds_before->SetBinContent(i+1,hRAA_Ds_before->GetBinContent(i+1)*centervalue);
      hRAA_Ds_before->SetBinError(i+1,hRAA_Ds_before->GetBinError(i+1)*centervalue);
      hRAA_Ds_after->SetBinContent(i+1,hRAA_Ds_after->GetBinContent(i+1)*centervalueafter);
      hRAA_Ds_after->SetBinError(i+1,hRAA_Ds_after->GetBinError(i+1)*centervalueafter);
      ayDsbefore[i] *= centervalue;
      ayDsafter[i] *= centervalueafter;
      eyDsbefore[i] *= centervalue;
      eyDsafter[i] = (eyDsafter[i]*centervalueafter)>(errminimum*ayDsafter[i])?(eyDsafter[i]*centervalueafter):(errminimum*ayDsafter[i]);
    }
  getDs_Alice.close();
  getDs_Alice.clear();
  TGraphErrors* gRAA_Ds_before = new TGraphErrors(nxDs,axDs,ayDsbefore,exDs,eyDsbefore);
  gRAA_Ds_before->SetName("gRAA_Ds_before");
  TGraphErrors* gRAA_Ds_after = new TGraphErrors(nxDs,axDs,ayDsafter,exDs,eyDsafter);
  gRAA_Ds_after->SetName("gRAA_Ds_after");

  // All graphs ready

  //

  SetPlotStyle(hRAA_D0_before, hRAA_Bp_before, hRAA_Charged_before_cent0100, hRAA_Ds_before, hRAA_Bs_before,
               gRAA_D0_before, gRAA_Bp_before, gRAA_Charged_before_cent0100, gRAA_Ds_before, gRAA_NPJPsi_stat_before, gRAA_NPJPsi_syst_before, gRAA_Bs_before);
  SetPlotStyle(hRAA_D0_after, hRAA_Bp_after, hRAA_Charged_after_cent0100, hRAA_Ds_after, hRAA_Bs_after,
               gRAA_D0_after, gRAA_Bp_after, gRAA_Charged_after_cent0100, gRAA_Ds_after, gRAA_NPJPsi_stat_after, gRAA_NPJPsi_syst_after, gRAA_Bs_after);

  SetPlotStyle(0, 0, hRAA_Charged_before_cent010, 0, 0, 0, 0, gRAA_Charged_before_cent010, 0, 0, 0, 0);
  SetPlotStyle(0, 0, hRAA_Charged_after_cent010, 0, 0, 0, 0, gRAA_Charged_after_cent010, 0, 0, 0, 0);

  //

  Float_t pti = 0.5;
  Float_t pte = 600;
  
  TH2F* hempty = new TH2F("hempty", ";p_{T} (GeV);R_{AA}", 50, pti, pte, 10., 0, 1.70);
  xjjroot::sethempty(hempty, -0.1, -0.2, 0.05, 0.04);
  TH2F* hemptyextend = new TH2F("hemptyextend", ";p_{T} (GeV);R_{AA}", 50, pti, 1000, 10., 0, 1.70);
  xjjroot::sethempty(hemptyextend, -0.1, -0.2, 0.05, 0.04);
  TH2F* hemptybonly = new TH2F("hemptybonly", ";p_{T} (GeV);R_{AA}", 50, 2, 100, 10., 0, 1.70);
  xjjroot::sethempty(hemptybonly, -0.1, -0.2, 0.05, 0.04);
  TLine* line = new TLine(pti, 1, pte, 1);
  xjjroot::setline(line, kBlack, 2, 2);
  TLine* lineextend = new TLine(pti, 1, 1000, 1);
  xjjroot::setline(lineextend, kBlack, 2, 2);
  TLine* linebonly = new TLine(2, 1, 100, 1);
  xjjroot::setline(linebonly, kBlack, 2, 2);
  TLatex* texcms = new TLatex(0.16, 0.90, "CMS");
  xjjroot::settex(texcms, 0.06, 13, 62);
  TLatex* texpre = new TLatex(0.15, 0.84, "Performance");
  xjjroot::settex(texpre, 0.05, 13, 52);
  TLatex* texpreafter = new TLatex(0.15, 0.84, "Projection");
  xjjroot::settex(texpreafter, 0.05, 13, 52);
  // TLatex* texdata = new TLatex(0.15, 0.78, "2015 Data");
  TLatex* texdata = new TLatex(0.15, 0.77, "2015 Data");
  xjjroot::settex(texdata, 0.04, 13);
  TLatex* texdata2 = new TLatex(0.15, 0.72, "Uncertainties");
  xjjroot::settex(texdata2, 0.04, 13);
  TLatex* texsnn = new TLatex(0.13, 0.955, "#lower[-0.2]{#sqrt{s_{NN}}} = 5.02 TeV");
  xjjroot::settex(texsnn, 0.038);
  TLatex* texlumi = new TLatex(0.965, 0.945, "pp 27.4 pb^{-1} + PbPb 0.4 nb^{-1}");
  xjjroot::settex(texlumi, 0.038, 31);
  TLatex* texlumibonly = new TLatex(0.965, 0.945, "pp 27.4 pb^{-1} + PbPb 0.35 nb^{-1}");
  xjjroot::settex(texlumibonly, 0.038, 31);
  TLatex* texlumiv2 = new TLatex(0.965, 0.945, "pp 27.4 pb^{-1} + PbPb");
  xjjroot::settex(texlumiv2, 0.038, 31);
  TLatex* texlumiaftersep = new TLatex(0.965, 0.945, "pp 650 pb^{-1} + PbPb");
  xjjroot::settex(texlumiaftersep, 0.038, 31);
  TLatex* texlumiafter = new TLatex(0.965, 0.945, "pp 650 pb^{-1} + PbPb 10 nb^{-1}");
  xjjroot::settex(texlumiafter, 0.038, 31);
  TLatex* texcent = new TLatex(0.60, 0.18, Form("Centrality 0-100%s", "%"));
  xjjroot::settex(texcent, 0.043);
  TLatex* texcent010 = new TLatex(0.63, 0.18, Form("Centrality 0-5%s", "%"));
  xjjroot::settex(texcent010, 0.043);

  //

  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(0);
  gStyle->SetMarkerStyle(20);
  gStyle->SetPadRightMargin(0.03);
  gStyle->SetPadLeftMargin(0.12);
  gStyle->SetPadTopMargin(0.075);
  gStyle->SetPadBottomMargin(0.12);

  //

  c2 = new TCanvas("c2", "", 1200, 600);
  c2->Divide(2, 1);

  c2->cd(1);
  gPad->SetLogx();
  hempty->Draw();
  line->Draw();
  RAA_CMS_Charged_0_100::drawsystCharged(1., 1., trkerr);
  hRAA_Charged_before_cent0100->Draw("plsame");
  gRAA_D0_before->Draw("5same");
  hRAA_D0_before->Draw("plsame");
  gRAA_Bp_before->Draw("5same");
  hRAA_Bp_before->Draw("plsame");
  gRAA_NPJPsi_syst_before->Draw("2same");
  gRAA_NPJPsi_stat_before->Draw("psame");
  // gRAA_Ds_before->Draw("5same");
  // hRAA_Ds_before->Draw("plsame");
  texcms->Draw();
  // texpre->Draw();
  texpreafter->Draw();
  texdata->Draw();
  texdata2->Draw();
  texsnn->Draw();
  texlumi->Draw();
  texcent->Draw();
  TLegend* legRAAbefore = new TLegend(0.45, 0.71, 0.92, 0.91);
  xjjroot::setleg(legRAAbefore, 0.035);
  legRAAbefore->AddEntry(gRAA_Charged_before_cent0100, "Charged hadrons", "pf");
  legRAAbefore->AddEntry(gRAA_D0_before, "D^{0}", "pf");
  legRAAbefore->AddEntry(gRAA_Bp_before, "B^{+}", "pf");
  legRAAbefore->AddEntry(gRAA_NPJPsi_syst_before, "Non-prompt J/#psi", "pf");
  // legRAAbefore->AddEntry(gRAA_Ds_before, "D_{s}", "pf");
  legRAAbefore->Draw();

  c2->cd(2);
  gPad->SetLogx();
  hempty->Draw();
  line->Draw();
  RAA_CMS_Charged_0_100::drawsystCharged(lumiweightTG_Charged, lumiweightMB_Charged, trkerr);
  hRAA_Charged_after_cent0100->Draw("plsame");
  gRAA_D0_after->Draw("5same");
  hRAA_D0_after->Draw("plsame");
  gRAA_Bp_after->Draw("5same");
  hRAA_Bp_after->Draw("plsame");
  gRAA_NPJPsi_syst_after->Draw("2same");
  gRAA_NPJPsi_stat_after->Draw("psame");
  // gRAA_Ds_after->Draw("5same");
  // hRAA_Ds_after->Draw("plsame");
  texcms->Draw();
  texpreafter->Draw();
  texsnn->Draw();
  texlumiaftersep->Draw();
  texcent->Draw();
  TLegend* legRAAafter = new TLegend(0.45, 0.60, 0.92, 0.92);
  xjjroot::setleg(legRAAafter, 0.035);
  legRAAafter->AddEntry(gRAA_Charged_after_cent0100, "Charged hadrons", "pf");
  legRAAafter->AddEntry((TObject*)0, Form("(p#scale[0.6]{#lower[0.6]{T}} < 50 GeV), %.1f nb^{-1}", lumiMB_after), NULL);
  legRAAafter->AddEntry((TObject*)0, Form("(p#scale[0.6]{#lower[0.6]{T}} > 50 GeV), %.0f nb^{-1}", lumiTG_after), NULL);
  legRAAafter->AddEntry(gRAA_D0_after, Form("D^{0} (p#scale[0.6]{#lower[0.6]{T}} < 20 GeV), %.1f nb^{-1}", lumiMB_after), "pf");
  legRAAafter->AddEntry((TObject*)0, Form("D^{0} (p#scale[0.6]{#lower[0.6]{T}} > 20 GeV), %.0f nb^{-1}", lumiTG_after), NULL);
  legRAAafter->AddEntry(gRAA_Bp_after, Form("B^{+}, %.0f nb^{-1}", lumiTG_after), "pf");
  legRAAafter->AddEntry(gRAA_NPJPsi_syst_after, Form("Non-prompt J/#psi, %.0f nb^{-1}", lumiTG_after), "pf");
  // legRAAafter->AddEntry(gRAA_Ds_after, Form("D_{s}, %.1f nb^{-1}", lumiMB_after), "pf");  
  legRAAafter->Draw();

  c2->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v1.pdf", lumiTG_after, lumiMB_after));

  c2->cd(1);
  gRAA_Bs_before->Draw("2same");
  hRAA_Bs_before->Draw("plsame");
  TLegend* legBsbefore = new TLegend(0.45, 0.66, 0.92, 0.71);
  xjjroot::setleg(legBsbefore, 0.035);
  legBsbefore->AddEntry(gRAA_Bs_before, "B_{s}", "pf");
  legBsbefore->Draw();
  c2->cd(2);
  gRAA_Bs_after->Draw("2same");
  hRAA_Bs_after->Draw("plsame");
  TLegend* legBsafter = new TLegend(0.15, 0.648, 0.57, 0.69);
  xjjroot::setleg(legBsafter, 0.035);
  legBsafter->AddEntry(gRAA_Bs_after, Form("B_{s}, %.0f nb^{-1}", lumiTG_after), "pf");
  legBsafter->Draw();

  c2->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v1_addBs.pdf", lumiTG_after, lumiMB_after));

  c1 = new TCanvas("c1left", "", 600, 600);
  gPad->SetLogx();
  hempty->Draw();
  line->Draw();
  RAA_CMS_Charged_0_100::drawsystCharged(1., 1., trkerr);
  hRAA_Charged_before_cent0100->Draw("plsame");
  gRAA_D0_before->Draw("5same");
  hRAA_D0_before->Draw("plsame");
  gRAA_Bp_before->Draw("5same");
  hRAA_Bp_before->Draw("plsame");
  gRAA_NPJPsi_syst_before->Draw("2same");
  gRAA_NPJPsi_stat_before->Draw("psame");
  // gRAA_Ds_before->Draw("5same");
  // hRAA_Ds_before->Draw("plsame");
  texcms->Draw();
  // texpre->Draw();
  texpreafter->Draw();
  texdata->Draw();
  texdata2->Draw();
  texsnn->Draw();
  texlumi->Draw();
  texcent->Draw();
  legRAAbefore->Draw();
  c1->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v1_left.pdf", lumiTG_after, lumiMB_after));

  gRAA_Bs_before->Draw("2same");
  hRAA_Bs_before->Draw("plsame");
  legBsbefore->Draw();
  c1->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v1_addBs_left.pdf", lumiTG_after, lumiMB_after));

  c1 = new TCanvas("c1right", "", 600, 600);
  gPad->SetLogx();
  hempty->Draw();
  line->Draw();
  RAA_CMS_Charged_0_100::drawsystCharged(lumiweightTG_Charged, lumiweightMB_Charged, trkerr);
  hRAA_Charged_after_cent0100->Draw("plsame");
  gRAA_D0_after->Draw("5same");
  hRAA_D0_after->Draw("plsame");
  gRAA_Bp_after->Draw("5same");
  hRAA_Bp_after->Draw("plsame");
  gRAA_NPJPsi_syst_after->Draw("2same");
  gRAA_NPJPsi_stat_after->Draw("psame");
  // gRAA_Ds_after->Draw("5same");
  // hRAA_Ds_after->Draw("plsame");
  texcms->Draw();
  texpreafter->Draw();
  texsnn->Draw();
  texlumiaftersep->Draw();
  texcent->Draw();
  legRAAafter->Draw();
  c1->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v1_right.pdf", lumiTG_after, lumiMB_after));

  gRAA_Bs_after->Draw("2same");
  hRAA_Bs_after->Draw("plsame");
  legBsafter->Draw();
  c1->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v1_addBs_right.pdf", lumiTG_after, lumiMB_after));


  //

  c2 = new TCanvas("c2v2", "", 1200, 600);
  c2->Divide(2, 1);

  c2->cd(1);
  gPad->SetLogx();
  hempty->Draw();
  line->Draw();
  RAA_CMS_Charged_0_100::drawsystCharged(1., 1., trkerr);
  hRAA_Charged_before_cent0100->Draw("plsame");
  gRAA_D0_before->Draw("5same");
  hRAA_D0_before->Draw("plsame");
  gRAA_Bp_before->Draw("5same");
  hRAA_Bp_before->Draw("plsame");
  // gRAA_Ds_before->Draw("5same");
  // hRAA_Ds_before->Draw("plsame");
  gRAA_NPJPsi_syst_before->Draw("2same");
  gRAA_NPJPsi_stat_before->Draw("psame");
  texcms->Draw();
  // texpre->Draw();
  texpreafter->Draw();
  texdata->Draw();
  texdata2->Draw();
  texsnn->Draw();
  texlumiv2->Draw();
  texcent->Draw();
  TLegend* legRAAbeforev2 = new TLegend(0.45, 0.60, 0.92, 0.92);
  xjjroot::setleg(legRAAbeforev2, 0.035);
  legRAAbeforev2->AddEntry(gRAA_Charged_before_cent0100, "Charged hadrons", "pf");
  legRAAbeforev2->AddEntry((TObject*)0, Form("(p#scale[0.6]{#lower[0.6]{T}} < 50 GeV), %.2f nb^{-1}", lumiMB_Charged_before), NULL);
  legRAAbeforev2->AddEntry((TObject*)0, Form("(p#scale[0.6]{#lower[0.6]{T}} > 50 GeV), %.1f nb^{-1}", lumiTG_Charged_before), NULL);
  legRAAbeforev2->AddEntry(gRAA_D0_before, Form("D^{0} (p#scale[0.6]{#lower[0.6]{T}} < 20 GeV), %.2f nb^{-1}", lumiMB_D0_before), "pf");
  legRAAbeforev2->AddEntry((TObject*)0, Form("D^{0} (p#scale[0.6]{#lower[0.6]{T}} > 20 GeV), %.1f nb^{-1}", lumiTG_D0_before), NULL);
  legRAAbeforev2->AddEntry(gRAA_Bp_before, Form("B^{+}, %.2f nb^{-1}", lumiTG_Bp_before), "pf");
  legRAAbeforev2->AddEntry(gRAA_NPJPsi_syst_before, Form("Non-prompt J/#psi, %.2f nb^{-1}", lumiTG_Bp_before), "pf");
  // legRAAbeforev2->AddEntry(gRAA_Ds_before, Form("D_{s}, %.2f nb^{-1}", lumiMB_D0_before), "pf");  
  legRAAbeforev2->Draw();

  c2->cd(2);
  gPad->SetLogx();
  hempty->Draw();
  line->Draw();
  RAA_CMS_Charged_0_100::drawsystCharged(lumiweightTG_Charged, lumiweightMB_Charged, trkerr);
  hRAA_Charged_after_cent0100->Draw("plsame");
  gRAA_D0_after->Draw("5same");
  hRAA_D0_after->Draw("plsame");
  gRAA_Bp_after->Draw("5same");
  hRAA_Bp_after->Draw("plsame");
  // gRAA_Ds_after->Draw("5same");
  // hRAA_Ds_after->Draw("plsame");
  gRAA_NPJPsi_syst_after->Draw("2same");
  gRAA_NPJPsi_stat_after->Draw("psame");
  texcms->Draw();
  texpreafter->Draw();
  texsnn->Draw();
  texlumiaftersep->Draw();
  texcent->Draw();
  legRAAafter->Draw();

  c2->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v2.pdf", lumiTG_after, lumiMB_after));

  c2->cd(1);
  gRAA_Bs_before->Draw("2same");
  hRAA_Bs_before->Draw("plsame");
  TLegend* legBsbeforev2 = new TLegend(0.15, 0.648, 0.57, 0.69);
  xjjroot::setleg(legBsbeforev2, 0.035);
  legBsbeforev2->AddEntry(gRAA_Bs_before, Form("B_{s}, %.2f nb^{-1}", lumiTG_Bs_before), "pf");
  legBsbeforev2->Draw();
  c2->cd(2);
  gRAA_Bs_after->Draw("2same");
  hRAA_Bs_after->Draw("plsame");
  legBsafter->Draw();
  c2->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v2_addBs.pdf", lumiTG_after, lumiMB_after));

  c1 = new TCanvas("c1v2left", "", 600, 600);
  gPad->SetLogx();
  hempty->Draw();
  line->Draw();
  RAA_CMS_Charged_0_100::drawsystCharged(1., 1., trkerr);
  hRAA_Charged_before_cent0100->Draw("plsame");
  gRAA_D0_before->Draw("5same");
  hRAA_D0_before->Draw("plsame");
  gRAA_Bp_before->Draw("5same");
  hRAA_Bp_before->Draw("plsame");
  // gRAA_Ds_before->Draw("5same");
  // hRAA_Ds_before->Draw("plsame");
  gRAA_NPJPsi_syst_before->Draw("2same");
  gRAA_NPJPsi_stat_before->Draw("psame");
  texcms->Draw();
  // texpre->Draw();
  texpreafter->Draw();
  texdata->Draw();
  texdata2->Draw();
  texsnn->Draw();
  texlumiv2->Draw();
  texcent->Draw();
  legRAAbeforev2->Draw();
  c1->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v2_left.pdf", lumiTG_after, lumiMB_after));

  gRAA_Bs_before->Draw("2same");
  hRAA_Bs_before->Draw("plsame");
  legBsbeforev2->Draw();
  c1->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v2_addBs_left.pdf", lumiTG_after, lumiMB_after));

  c1 = new TCanvas("c1v2right", "", 600, 600);
  gPad->SetLogx();
  hempty->Draw();
  line->Draw();
  RAA_CMS_Charged_0_100::drawsystCharged(lumiweightTG_Charged, lumiweightMB_Charged, trkerr);
  hRAA_Charged_after_cent0100->Draw("plsame");
  gRAA_D0_after->Draw("5same");
  hRAA_D0_after->Draw("plsame");
  gRAA_Bp_after->Draw("5same");
  hRAA_Bp_after->Draw("plsame");
  // gRAA_Ds_after->Draw("5same");
  // hRAA_Ds_after->Draw("plsame");
  gRAA_NPJPsi_syst_after->Draw("2same");
  gRAA_NPJPsi_stat_after->Draw("psame");
  texcms->Draw();
  texpreafter->Draw();
  texsnn->Draw();
  texlumiaftersep->Draw();
  texcent->Draw();
  legRAAafter->Draw();
  c1->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v2_right.pdf", lumiTG_after, lumiMB_after));

  gRAA_Bs_after->Draw("2same");
  hRAA_Bs_after->Draw("plsame");
  legBsafter->Draw();
  c1->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v2_addBs_right.pdf", lumiTG_after, lumiMB_after));

  // b only

  c2 = new TCanvas("c2bonly", "", 1200, 600);
  c2->Divide(2, 1);

  c2->cd(1);
  gPad->SetLogx();
  hemptybonly->Draw();
  linebonly->Draw();
  gRAA_Bp_before->Draw("5same");
  hRAA_Bp_before->Draw("plsame");
  gRAA_NPJPsi_syst_before->Draw("2same");
  gRAA_NPJPsi_stat_before->Draw("psame");
  gRAA_Bs_before->Draw("2same");
  hRAA_Bs_before->Draw("plsame");
  texcms->Draw();
  // texpre->Draw();
  texpreafter->Draw();
  texdata->Draw();
  texdata2->Draw();
  texsnn->Draw();
  texlumibonly->Draw();
  texcent->Draw();
  TLegend* legBonlybefore = new TLegend(0.45, 0.71, 0.92, 0.91);
  xjjroot::setleg(legBonlybefore, 0.035);
  legBonlybefore->AddEntry(gRAA_Bp_before, "B^{+}", "pf");
  legBonlybefore->AddEntry(gRAA_NPJPsi_syst_before, "Non-prompt J/#psi", "pf");
  legBonlybefore->AddEntry(gRAA_Bs_before, "B_{s}", "pf");
  legBonlybefore->Draw();

  c2->cd(2);
  gPad->SetLogx();
  hemptybonly->Draw();
  linebonly->Draw();
  gRAA_Bp_after->Draw("5same");
  hRAA_Bp_after->Draw("plsame");
  gRAA_NPJPsi_syst_after->Draw("2same");
  gRAA_NPJPsi_stat_after->Draw("psame");
  gRAA_Bs_after->Draw("2same");
  hRAA_Bs_after->Draw("plsame");
  texcms->Draw();
  texpreafter->Draw();
  texsnn->Draw();
  texlumiafter->Draw();
  texcent->Draw();
  TLegend* legBonlyafter = new TLegend(0.45, 0.71, 0.92, 0.91);
  xjjroot::setleg(legBonlyafter, 0.035);
  // legBonlyafter->AddEntry(gRAA_Bp_after, Form("B^{+}, %.0f nb^{-1}", lumiTG_after), "pf");
  // legBonlyafter->AddEntry(gRAA_NPJPsi_syst_after, Form("Non-prompt J/#psi, %.0f nb^{-1}", lumiTG_after), "pf");
  // legBonlyafter->AddEntry(gRAA_Bs_after, Form("B_{s}, %.0f nb^{-1}", lumiTG_after), "pf");
  legBonlyafter->AddEntry(gRAA_Bp_after, "B^{+}", "pf");
  legBonlyafter->AddEntry(gRAA_NPJPsi_syst_after, "Non-prompt J/#psi", "pf");
  legBonlyafter->AddEntry(gRAA_Bs_after, "B_{s}", "pf");
  legBonlyafter->Draw();

  c2->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v1_bOnly.pdf", lumiTG_after, lumiMB_after));

  c1 = new TCanvas("c1bonlyleft", "", 600, 600);
  gPad->SetLogx();
  hemptybonly->Draw();
  linebonly->Draw();
  gRAA_Bp_before->Draw("5same");
  hRAA_Bp_before->Draw("plsame");
  gRAA_NPJPsi_syst_before->Draw("2same");
  gRAA_NPJPsi_stat_before->Draw("psame");
  gRAA_Bs_before->Draw("2same");
  hRAA_Bs_before->Draw("plsame");
  texcms->Draw();
  // texpre->Draw();
  texpreafter->Draw();
  texdata->Draw();
  texdata2->Draw();
  texsnn->Draw();
  texlumi->Draw();
  texcent->Draw();
  legBonlybefore->Draw();
  c1->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v1_bOnly_left.pdf", lumiTG_after, lumiMB_after));

  c1 = new TCanvas("c1bonlyright", "", 600, 600);
  gPad->SetLogx();
  hemptybonly->Draw();
  linebonly->Draw();
  gRAA_Bp_after->Draw("5same");
  hRAA_Bp_after->Draw("plsame");
  gRAA_NPJPsi_syst_after->Draw("2same");
  gRAA_NPJPsi_stat_after->Draw("psame");
  gRAA_Bs_after->Draw("2same");
  hRAA_Bs_after->Draw("plsame");
  texcms->Draw();
  texpreafter->Draw();
  texsnn->Draw();
  texlumiafter->Draw();
  texcent->Draw();
  legBonlyafter->Draw();
  c1->SaveAs(Form("plots/cRAA_lumiTG_%.0f_lumiMB_%.0f_v1_bOnly_right.pdf", lumiTG_after, lumiMB_after));

  //

  c2 = new TCanvas("c2v2cent010", "", 1200, 600);
  c2->Divide(2, 1);

  c2->cd(1);
  gPad->SetLogx();
  hemptyextend->Draw();
  lineextend->Draw();
  RAA_CMS_Charged_0_5::drawsystCharged(1., 1., trkerr);
  hRAA_Charged_before_cent010->Draw("plsame");
  texcms->Draw();
  // texpre->Draw();
  texpreafter->Draw();
  texdata->Draw();
  texdata2->Draw();
  texsnn->Draw();
  texlumiv2->Draw();
  texcent010->Draw();
  legRAAbeforev2 = new TLegend(0.45, 0.70, 0.92, 0.87);
  xjjroot::setleg(legRAAbeforev2, 0.035);
  legRAAbeforev2->AddEntry(gRAA_Charged_before_cent0100, "Charged hadrons", "pf");
  legRAAbeforev2->AddEntry((TObject*)0, Form("(p#scale[0.6]{#lower[0.6]{T}} < 50 GeV), %.2f nb^{-1}", lumiMB_Charged_before), NULL);
  legRAAbeforev2->AddEntry((TObject*)0, Form("(p#scale[0.6]{#lower[0.6]{T}} > 50 GeV), %.1f nb^{-1}", lumiTG_Charged_before), NULL);
  legRAAbeforev2->Draw();

  c2->cd(2);
  gPad->SetLogx();
  hemptyextend->Draw();
  lineextend->Draw();
  RAA_CMS_Charged_0_5::drawsystCharged(lumiweightTG_Charged, lumiweightMB_Charged, trkerr);
  hRAA_Charged_after_cent010->Draw("plsame");
  texcms->Draw();
  texpreafter->Draw();
  texsnn->Draw();
  texlumiaftersep->Draw();
  texcent010->Draw();
  legRAAafter = new TLegend(0.45, 0.70, 0.92, 0.87);
  xjjroot::setleg(legRAAafter, 0.035);
  legRAAafter->AddEntry(gRAA_Charged_after_cent0100, "Charged hadrons", "pf");
  legRAAafter->AddEntry((TObject*)0, Form("(p#scale[0.6]{#lower[0.6]{T}} < 50 GeV), %.1f nb^{-1}", lumiMB_after), NULL);
  legRAAafter->AddEntry((TObject*)0, Form("(p#scale[0.6]{#lower[0.6]{T}} > 50 GeV), %.0f nb^{-1}", lumiTG_after), NULL);
  legRAAafter->Draw();

  c2->SaveAs(Form("plots/cRAA_cent05_lumiTG_%.0f_lumiMB_%.0f_v2.pdf", lumiTG_after, lumiMB_after));

  c1 = new TCanvas("c1v2cent010left", "", 600, 600);
  gPad->SetLogx();
  hemptyextend->Draw();
  lineextend->Draw();
  RAA_CMS_Charged_0_5::drawsystCharged(1., 1., trkerr);
  hRAA_Charged_before_cent010->Draw("plsame");
  TF1* f = new TF1("f", "(1./1820.)*TMath::Exp(10.5491-6.79267*log(x+6.92719))/TMath::Exp(3.77707-6.92871*log(x+3.41343))", 50, 1000);
  f->SetLineStyle(2);
  f->SetLineWidth(3);
  f->SetLineColor(kRed+3);
  // Float_t smoothx[] = {95, 112.2, 130.4, 152.5, 207.5, 325};
  // for(int i=0;i<sizeof(smoothx)/sizeof(smoothx[0]);i++) std::cout<<smoothx[i]<<" "<<f->Eval(smoothx[i])<<std::endl;
  // std::cout<<"500 "<<f->Eval(500)<<std::endl;
  // std::cout<<"800 "<<f->Eval(800)<<std::endl;
  f->Draw("same");
  texcms->Draw();
  // texpre->Draw();
  texpreafter->Draw();
  texdata->Draw();
  texdata2->Draw();
  texsnn->Draw();
  texlumiv2->Draw();
  texcent010->Draw();
  legRAAbeforev2->Draw();
  c1->SaveAs(Form("plots/cRAA_cent05_lumiTG_%.0f_lumiMB_%.0f_v2_left.pdf", lumiTG_after, lumiMB_after));

  c1 = new TCanvas("c1v2cent010right", "", 600, 600);
  gPad->SetLogx();
  hemptyextend->Draw();
  lineextend->Draw();
  RAA_CMS_Charged_0_5::drawsystCharged(lumiweightTG_Charged, lumiweightMB_Charged, trkerr);
  hRAA_Charged_after_cent010->Draw("plsame");
  texcms->Draw();
  texpreafter->Draw();
  texsnn->Draw();
  texlumiaftersep->Draw();
  texcent010->Draw();
  legRAAafter->Draw();
  c1->SaveAs(Form("plots/cRAA_cent05_lumiTG_%.0f_lumiMB_%.0f_v2_right.pdf", lumiTG_after, lumiMB_after));


}

int main(int argc, char* argv[])
{
  if(argc==8)
    {
      plotRAA(atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]), atof(argv[6]), atof(argv[7]));
      return 0;
    }
  return 1;
}
