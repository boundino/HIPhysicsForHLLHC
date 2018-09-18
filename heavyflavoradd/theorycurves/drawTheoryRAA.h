#ifndef _DRAWTHEORY_RAA_H_
#define _DRAWTHEORY_RAA_H_

#include <iostream>
#include <fstream>
#include <vector>

#include <TFile.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TH2F.h>
#include <TLatex.h>
#include <TLine.h>

#ifndef _XJJROOT_UTI_H_
#define _XJJROOT_UTI_H_
namespace xjjroot
{
  void drawtex(Double_t x, Double_t y, const char *text, Float_t tsize=0.04, Short_t align=12, Style_t font=42);
  void drawline(Double_t x1, Double_t y1, Double_t x2, Double_t y2, Color_t lcolor=kBlack, Style_t lstyle=1, Width_t lwidth=2);
  template <class T> void setthgrstyle(T* h, Color_t mcolor=-1, Style_t mstyle=-1, Size_t msize=-1, Color_t lcolor=-1, Style_t lstyle=-1, Width_t lwidth=-1, Color_t fcolor=-1, Float_t falpha=-1, Style_t fstyle=-1);
}
#endif

namespace drawTheoryRAA
{
  // RAA
  TCanvas* canvasRAA;
  TH2F* hemptyRAA;

  TGraphAsymmErrors* gCUJETD5TeV;
  TGraph* gShanshanD5TeV;
  TGraphErrors* gMagdalenaD5TeV;
  TGraphErrors* gPHSDWOShadowing;
  TGraphErrors* gPHSDWShadowing;
  TGraph* gIvanD5TeV;
  TGraphErrors* gADSCFT1D5TeV;
  TGraphErrors* gADSCFT2D5TeV;
  TGraph* gBAMPSlow;
  TGraph* gBAMPShigh;
  TGraph* gBAMPSradlow;
  TGraph* gBAMPSradhigh;
  TGraph* gEPOSlow;
  TGraph* gEPOShigh;
  TGraph* gPOWLANG;
  TGraph* gTAMUlow;
  TGraph* gTAMUhigh;

  TGraphErrors* fillgadscft(TString datfile);
  TGraph* fillalicecurve(TString datfile);
      
  void setupTheory010()
  {
    // CUJET
    TFile* infCUJETD5TeV = new TFile("TheoryPredictions/CUJET_D0_RAA_0_10.root");
    gCUJETD5TeV = (TGraphAsymmErrors*)infCUJETD5TeV->Get("gRAADmeson5TeV");
    xjjroot::setthgrstyle(gCUJETD5TeV, -1, -1, -1, 0, 0, 0, kAzure-2, 0.6, 3481);
    std::cout<<"--- Read... gCUJETD5TeV"<<std::endl;
    // Shanshan
    gShanshanD5TeV = new TGraph("TheoryPredictions/Shanshan-D-RAA_PbPb5020_00-10.dat");
    xjjroot::setthgrstyle(gShanshanD5TeV, -1, -1, -1, kRed+1, 1, 4);
    std::cout<<"--- Read... gShanshanD5TeV"<<std::endl;
    // Magdalena
    gMagdalenaD5TeV = new TGraphErrors("TheoryPredictions/Magdalena-5TeV-plot2.txt");
    xjjroot::setthgrstyle(gMagdalenaD5TeV, -1, -1, -1, kRed-7, 1, 2, kRed-4, 0.5, 3344);
    std::cout<<"--- Read... gMagdalenaD5TeV"<<std::endl;
    // PHSD w/o shadowing
    gPHSDWOShadowing = new TGraphErrors("TheoryPredictions/phsd502TeVWoShadowing.txt");
    xjjroot::setthgrstyle(gPHSDWOShadowing, -1, -1, -1, kAzure-6, 2, 4);
    std::cout<<"--- Read... gPHSDWOShadowing"<<std::endl;
    // PHSD w/ shadowing
    gPHSDWShadowing = new TGraphErrors("TheoryPredictions/phsd502TeVWShadowing.txt");
    xjjroot::setthgrstyle(gPHSDWShadowing, -1, -1, -1, kAzure-6, 1, 4);
    std::cout<<"--- Read... gPHSDWShadowing"<<std::endl;
    // Ivan 
    gIvanD5TeV = new TGraph("TheoryPredictions/D0cmsCENTPbPb.txt");
    xjjroot::setthgrstyle(gIvanD5TeV, -1, -1, -1, kViolet+1, 1, 2, kViolet+1, 0.5, 3358);
    std::cout<<"--- Read... gIvanD5TeV"<<std::endl;
    // ADSCFT 1
    gADSCFT1D5TeV = fillgadscft("TheoryPredictions/RAA_5TeV_0010_D0_DiffusionConstant_band.dat");
    gADSCFT1D5TeV->SetName("gADSCFT1D5TeV");
    xjjroot::setthgrstyle(gADSCFT1D5TeV, -1, -1, -1, 0, 0 ,0, kOrange+1, 0.6, 3325);
    std::cout<<"--- Read... gADSCFT1D5TeV"<<std::endl;
    // ADSCFT 2
    gADSCFT2D5TeV = fillgadscft("TheoryPredictions/RAA_5TeV_0010_D0_DiffusionDynamic_band.dat");
    gADSCFT2D5TeV->SetName("gADSCFT2D5TeV");
    xjjroot::setthgrstyle(gADSCFT2D5TeV, -1, -1, -1, 0, 0, 0, kPink-9, 0.6, 3352);
    std::cout<<"--- Read... gADSCFT2D5TeV"<<std::endl;
    // BAMPS
    gBAMPSlow = fillalicecurve("TheoryPredictions/RAA_BAMPS_low.dat");
    xjjroot::setthgrstyle(gBAMPSlow, -1, -1, -1, kGreen+4, 3, 4);
    gBAMPShigh = fillalicecurve("TheoryPredictions/RAA_BAMPS_high.dat");
    xjjroot::setthgrstyle(gBAMPShigh, -1, -1, -1, kGreen+4, 3, 4);
    std::cout<<"--- Read... gBAMPS"<<std::endl;
    // BAMPSrad
    gBAMPSradlow = fillalicecurve("TheoryPredictions/RAA_BAMPSrad_low.dat");
    xjjroot::setthgrstyle(gBAMPSradlow, -1, -1, -1, kSpring+5, 3, 4);
    gBAMPSradhigh = fillalicecurve("TheoryPredictions/RAA_BAMPSrad_high.dat");
    xjjroot::setthgrstyle(gBAMPSradhigh, -1, -1, -1, kSpring+5, 3, 4);
    std::cout<<"--- Read... gBAMPSrad"<<std::endl;
    // EPOS
    gEPOSlow = fillalicecurve("TheoryPredictions/RAA_EPOS_low.dat");
    xjjroot::setthgrstyle(gEPOSlow, -1, -1, -1, kAzure+5, 4, 4);
    gEPOShigh = fillalicecurve("TheoryPredictions/RAA_EPOS_high.dat");
    xjjroot::setthgrstyle(gEPOShigh, -1, -1, -1, kAzure+5, 4, 4);
    std::cout<<"--- Read... gEPOS"<<std::endl;
    // TAMU
    gTAMUlow = fillalicecurve("TheoryPredictions/RAA_TAMU_low.dat");
    xjjroot::setthgrstyle(gTAMUlow, -1, -1, -1, kOrange+7, 2, 4);
    gTAMUhigh = fillalicecurve("TheoryPredictions/RAA_TAMU_high.dat");
    xjjroot::setthgrstyle(gTAMUhigh, -1, -1, -1, kOrange+7, 2, 4);
    std::cout<<"--- Read... gTAMU"<<std::endl;
    // POWLANG
    gPOWLANG = fillalicecurve("TheoryPredictions/RAA_POWLANG.dat");
    xjjroot::setthgrstyle(gPOWLANG, -1, -1, -1, kMagenta-7, 10, 4);
    std::cout<<"--- Read... gPOWLANG"<<std::endl;
  }

  //
  void drawTheory010()
  {
    gStyle->SetHatchesLineWidth(2);

    gMagdalenaD5TeV->Draw("f same");
    gMagdalenaD5TeV->Draw("l same");
    gIvanD5TeV->Draw("f same");
    gIvanD5TeV->Draw("l same");
    gCUJETD5TeV->Draw("3 same");
    gADSCFT1D5TeV->Draw("4 same");
    gPHSDWShadowing->Draw("c same");
    gPHSDWOShadowing->Draw("c same");
    gShanshanD5TeV->Draw("c same");
    gADSCFT2D5TeV->Draw("4 same");
    
    gBAMPSradlow->Draw("l same");
    gBAMPSradhigh->Draw("l same");
    gBAMPSlow->Draw("l same");
    gBAMPShigh->Draw("l same");
    gTAMUlow->Draw("l same");
    gTAMUhigh->Draw("l same");
    gEPOSlow->Draw("l same");
    gEPOShigh->Draw("l same");
    gPOWLANG->Draw("l same");
  }

  //
  void setupNdrawTheory010() { setupTheory010(); drawTheory010(); }

  //
  TGraphErrors* fillgadscft(TString datfile)
  {
    const int n = 1000;
    Float_t bCx[n],bCy[n],bCye[n],bDummy[n];
    Int_t nbin=0;
    std::ifstream getadscft(datfile);
    if(!getadscft.is_open()) std::cout<<"Opening the file fails: ADS/CFT DiffusionConstant"<<std::endl;
    nbin=0;
    while(!getadscft.eof())
      {
        getadscft>>bCx[nbin]>>bCy[nbin]>>bDummy[nbin]>>bCye[nbin];
        nbin++;
      }
    bCx[nbin] = bCx[nbin-1];
    bCy[nbin] = bCy[nbin-1];
    bCye[nbin] = bCye[nbin-1];
    nbin++;
    Float_t* aADSCFTD5TeVx = new Float_t[nbin];
    Float_t* aADSCFTD5TeVxe = new Float_t[nbin];
    Float_t* aADSCFTD5TeVy = new Float_t[nbin];
    Float_t* aADSCFTD5TeVye = new Float_t[nbin];
    for(int i=0;i<nbin;i++)
      {
        aADSCFTD5TeVx[i] = bCx[i];
        aADSCFTD5TeVxe[i] = 0;
        aADSCFTD5TeVy[i] = bCy[i];
        aADSCFTD5TeVye[i] = bCye[i];
      }
    getadscft.close();
    getadscft.clear();

    TGraphErrors* gadscft = new TGraphErrors(nbin, aADSCFTD5TeVx, aADSCFTD5TeVy, aADSCFTD5TeVxe, aADSCFTD5TeVye);
    return gadscft;
  }

  TGraph* fillalicecurve(TString datfile)
  {
    std::ifstream getdata(datfile.Data());
    std::vector<float> vx, vy;
    while(true)
      {
        float x, y;
        getdata >> x;
        if(getdata.eof()) { break; }
        getdata >> y;
        vx.push_back(x);
        vy.push_back(y);
      }
    int nx = vx.size();
    TGraph* gr = new TGraph(nx, vx.data(), vy.data());
    gr->SetName(Form("gr_%s", datfile.Data()));
    return gr;
  }
  
  // Draw
  void drawcanvas()
  {
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);
    gStyle->SetEndErrorSize(0);
    gStyle->SetMarkerStyle(20);

    canvasRAA = new TCanvas("canvasRAA", "canvasRAA", 600, 600);
    canvasRAA->cd();
    canvasRAA->SetFillColor(0);
    canvasRAA->SetBorderMode(0);
    canvasRAA->SetBorderSize(2);
    canvasRAA->SetLeftMargin(0.17);
    canvasRAA->SetRightMargin(0.025);
    canvasRAA->SetTopMargin(0.080);
    canvasRAA->SetBottomMargin(0.11);
    canvasRAA->SetFrameBorderMode(0);
    canvasRAA->SetLogx();

    float xaxismin = 1.0, xaxismax = 150;

    hemptyRAA = new TH2F("hemptyRAA",";p_{T} (GeV/c);R_{AA}", 50, xaxismin, xaxismax, 10, 0, 2.2);
    hemptyRAA->GetXaxis()->SetLabelOffset(0.0);
    hemptyRAA->GetXaxis()->CenterTitle();
    hemptyRAA->GetYaxis()->CenterTitle();
    hemptyRAA->GetXaxis()->SetTitleFont(42);
    hemptyRAA->GetYaxis()->SetTitleFont(42);
    hemptyRAA->GetXaxis()->SetTitleOffset(1.10);
    hemptyRAA->GetYaxis()->SetTitleOffset(1.50);
    hemptyRAA->GetXaxis()->SetTitleSize(0.045);
    hemptyRAA->GetYaxis()->SetTitleSize(0.045);
    hemptyRAA->GetXaxis()->SetLabelSize(0.04);
    hemptyRAA->GetYaxis()->SetLabelSize(0.04);
    hemptyRAA->GetXaxis()->SetLabelFont(42);
    hemptyRAA->GetYaxis()->SetLabelFont(42);
    hemptyRAA->SetStats(0);    
    hemptyRAA->Draw();

    xjjroot::drawline(xaxismin, 1, xaxismax, 1, kBlack, 2, 2);
  }

  TLegend* legRAA;
  void drawlegends()
  {
    gADSCFT1D5TeV->SetLineColor(0);
    gADSCFT2D5TeV->SetLineColor(0);
    xjjroot::drawtex(0.965, 0.936, "(5.02 TeV PbPb, Centrality 0-10%)", 0.036, 31);
    legRAA = new TLegend(0.20, 0.54, 0.95, 0.87);
    legRAA->SetNColumns(2);
    legRAA->SetBorderSize(0);
    legRAA->SetFillStyle(0);
    legRAA->SetTextFont(42);
    legRAA->SetTextSize(0.031);
    legRAA->AddEntry(gMagdalenaD5TeV, "Djordjevic et al.", "bf");
    legRAA->AddEntry(gCUJETD5TeV, "CUJET 3.0", "f");
    legRAA->AddEntry(gIvanD5TeV, "Vitev et al. (g=1.9-2.0)", "bf");
    legRAA->AddEntry(gShanshanD5TeV, "LBT", "l");
    legRAA->AddEntry(gPHSDWShadowing, "PHSD w/ shadowing ", "l");
    legRAA->AddEntry(gADSCFT1D5TeV, "AdS/CFT HH D = const", "f");
    legRAA->AddEntry(gPHSDWOShadowing, "PHSD w/o shadowing ", "l");
    legRAA->AddEntry(gADSCFT2D5TeV, "AdS/CFT HH D(p)", "f");
    legRAA->AddEntry((TObject*)0, "", NULL);
    legRAA->AddEntry((TObject*)0, "", NULL);
    legRAA->AddEntry(gBAMPSradlow, "BAMPS el.+rad.", "l");
    legRAA->AddEntry(gPOWLANG, "POWLANG HLT", "l");
    legRAA->AddEntry(gBAMPSlow, "BAMPS el.", "l");
    legRAA->AddEntry(gTAMUlow, "TAMU", "l");
    legRAA->AddEntry((TObject*)0, "", NULL);
    legRAA->AddEntry(gEPOSlow, "MC@sHQ+EPOS2", "l");
    legRAA->Draw();
    xjjroot::drawtex(0.60, 0.88, "#bf{D#scale[0.6]{#lower[-0.7]{0}} + #bar{D}#scale[0.6]{#lower[-0.7]{0}}}, |y| < 1", 0.034, 21);
    xjjroot::drawtex(0.60, 0.675, "#bf{Average D#scale[0.6]{#lower[-0.7]{0}}, D#scale[0.6]{#lower[-1.0]{+}}, D#scale[0.6]{#lower[-0.1]{*}}#scale[0.6]{#lower[-0.9]{+}}}, |y| < 0.5", 0.034, 21);
  }

}

#ifndef _XJJROOT_UTI_H_DEF_
#define _XJJROOT_UTI_H_DEF_

void xjjroot::drawtex(Double_t x, Double_t y, const char* text, Float_t tsize/*=0.04*/, Short_t align/*=12*/, Style_t font/*=42*/)
{
  TLatex* tex = new TLatex(x, y, text);
  tex->SetNDC();
  tex->SetTextFont(font);
  tex->SetTextAlign(align);
  tex->SetTextSize(tsize);
  tex->Draw();
}

void xjjroot::drawline(Double_t x1, Double_t y1, Double_t x2, Double_t y2, Color_t lcolor/*=kBlack*/, Style_t lstyle/*=1*/, Width_t lwidth/*=2*/)
{
  TLine* l = new TLine(x1, y1, x2, y2);
  l->SetLineColor(lcolor);
  l->SetLineStyle(lstyle);
  l->SetLineWidth(lwidth);
  l->Draw();
}

template <class T>
void xjjroot::setthgrstyle(T* h, Color_t mcolor/*=-1*/, Style_t mstyle/*=-1*/, Size_t msize/*=-1*/, Color_t lcolor/*=-1*/, Style_t lstyle/*=-1*/, Width_t lwidth/*=-1*/, Color_t fcolor/*=-1*/, Float_t falpha/*=-1*/, Style_t fstyle/*=-1*/)
{
  if(mcolor>=0) h->SetMarkerColor(mcolor);
  if(mstyle>=0) h->SetMarkerStyle(mstyle);
  if(msize>=0)  h->SetMarkerSize(msize);
  if(lcolor>=0) h->SetLineColor(lcolor);
  if(lstyle>=0) h->SetLineStyle(lstyle);
  if(lwidth>=0) h->SetLineWidth(lwidth);
  if(fcolor>=0) h->SetFillColor(fcolor);
  if(falpha>=0) h->SetFillColorAlpha(fcolor, falpha);
  if(fstyle>=0) h->SetFillStyle(fstyle);
}

#endif

#endif
