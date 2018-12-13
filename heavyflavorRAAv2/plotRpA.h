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
#include <TString.h>

void SetPlotStyle(TH1D* hBp,
                  TGraphErrors* gBp)
{
  if(hBp && gBp)
    {
      gBp->SetMarkerStyle(21);
      gBp->SetMarkerSize(1.);
      gBp->SetMarkerColor(kBlack);
      gBp->SetFillColor(5);
      gBp->SetLineColor(kAzure-4);
      // gBp->SetLineColor(kBlack);
      gBp->SetLineStyle(1);
      gBp->SetLineWidth(2);
      hBp->SetMarkerStyle(21);
      hBp->SetMarkerSize(1.);
      hBp->SetMarkerColor(kBlack);
      hBp->SetLineWidth(2);
      hBp->SetLineColor(kBlack);
    }
}

void SetPlotStyle_LHCb(TH1D* hBp,
                       TGraphErrors* gBp)
{
  if(hBp && gBp)
    {
      TString hname(hBp->GetName());
      Style_t markerstyle = hname.Contains("forward")?34:47;
      gBp->SetMarkerStyle(markerstyle);
      gBp->SetMarkerSize(1.3);
      gBp->SetMarkerColor(kAzure-6);
      gBp->SetFillColor(kAzure-9);
      gBp->SetFillColorAlpha(kAzure-9, 0.3);
      // gBp->SetLineColor(kAzure-6);
      // gBp->SetLineStyle(1);
      // gBp->SetLineWidth(4);
      gBp->SetLineColor(0);
      gBp->SetLineStyle(0);
      gBp->SetLineWidth(0);
      hBp->SetMarkerStyle(markerstyle);
      hBp->SetMarkerSize(1.3);
      hBp->SetMarkerColor(kAzure-6);
      hBp->SetLineWidth(3);
      hBp->SetLineColor(kAzure-6);
    }
}
