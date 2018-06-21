#include <iostream>
#include <iomanip>
#include <fstream>
#include <TH1D.h>
#include <TH2F.h>
#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TLine.h>
#include <TStyle.h>
#include <TMath.h>
#include <TColor.h>
#include <TF1.h>

void SetPlotStyle(TH1D* hD0, TH1D* hBp, TH1D* hCharged, TH1D* hDs, TH1D* hBs,
                  TGraphErrors* gD0, TGraphErrors* gBp, TGraphErrors* gCharged, TGraphErrors* gDs, TGraphErrors* gstatNj, TGraphErrors* gsystNj, TGraphErrors* gBs)
{
  if(hD0 && gD0)
    {
      gD0->SetMarkerStyle(21);
      gD0->SetMarkerSize(1.2);
      gD0->SetMarkerColor(kGreen+3);
      gD0->SetFillColor(kGreen-9);
      gD0->SetFillColorAlpha(kGreen-9, 0.5);
      gD0->SetLineColor(kBlack);
      hD0->SetLineWidth(3);
      hD0->SetLineColor(kBlack);
      hD0->SetMarkerStyle(21);
      hD0->SetMarkerSize(1.2);
      hD0->SetMarkerColor(kGreen+3);
    }
  if(hBp && gBp)
    {
      gBp->SetMarkerStyle(21);
      gBp->SetMarkerSize(1.2);
      gBp->SetMarkerColor(kAzure-1);
      gBp->SetFillColor(kAzure+7);
      gBp->SetFillColorAlpha(kAzure+7, 0.5);
      gBp->SetLineColor(kAzure+7);
      hBp->SetMarkerStyle(21);
      hBp->SetMarkerSize(1.2);
      hBp->SetMarkerColor(kAzure-1);
      hBp->SetLineWidth(3);
      hBp->SetLineColor(kAzure-1);
    }
  if(hBs && gBs)
    {
      gBs->SetMarkerStyle(33);
      gBs->SetMarkerSize(1.4);
      gBs->SetMarkerColor(kMagenta-3);
      gBs->SetFillColor(kMagenta+2);
      gBs->SetFillColorAlpha(kMagenta+2, 0.3);
      gBs->SetLineColor(0);
      hBs->SetMarkerStyle(33);
      hBs->SetMarkerSize(1.4);
      hBs->SetMarkerColor(kMagenta-3);
      hBs->SetLineWidth(2);
      hBs->SetLineColor(kMagenta-3);
    }
  if(gsystNj && gstatNj)
    {
      gsystNj->SetFillColor(kRed-9);
      gsystNj->SetFillColorAlpha(kRed-9, 0.5);
      gsystNj->SetMarkerColor(kRed+2);
      gsystNj->SetMarkerStyle(29);
      gsystNj->SetMarkerSize(2);
      gsystNj->SetLineColor(0);
      gstatNj->SetLineColor(kRed+2);
      gstatNj->SetLineWidth(2);
      gstatNj->SetMarkerColor(kRed+2);
      gstatNj->SetMarkerStyle(29);
      gstatNj->SetMarkerSize(2);
    }
  if(hCharged && gCharged)
    {
      gCharged->SetMarkerStyle(20);
      gCharged->SetMarkerSize(1.3);
      gCharged->SetMarkerColor(kBlack);
      gCharged->SetFillColor(TColor::GetColor("#ffcc00"));
      gCharged->SetLineWidth(0);
      gCharged->SetLineColor(0);
      hCharged->SetLineWidth(2);
      hCharged->SetLineColor(kBlack);
      hCharged->SetMarkerStyle(20);
      hCharged->SetMarkerSize(1.3);
      hCharged->SetMarkerColor(kBlack);
    }
  if(hDs && gDs)
    {
      gDs->SetMarkerStyle(34);
      gDs->SetMarkerSize(1.3);
      gDs->SetMarkerColor(kRed+1);
      gDs->SetFillColor(kRed-7);
      gDs->SetFillColorAlpha(kRed-7, 0.5);
      gDs->SetLineColor(kRed+1);
      hDs->SetLineWidth(3);
      hDs->SetMarkerStyle(34);
      hDs->SetMarkerSize(1.3);
      hDs->SetMarkerColor(kRed+1);
    }
}
