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

void SetPlotStyle(TH1D* hBp,
                  TGraphErrors* gBp)
{
  if(hBp && gBp)
    {
      gBp->SetMarkerStyle(21);
      gBp->SetMarkerSize(1.2);
      gBp->SetMarkerColor(kBlack);
      gBp->SetFillColor(5);
      // gBp->SetFillColorAlpha(kAzure+7, 0.5);
      gBp->SetLineColor(kBlack);
      gBp->SetLineWidth(2);
      hBp->SetMarkerStyle(21);
      hBp->SetMarkerSize(1.2);
      hBp->SetMarkerColor(kBlack);
      hBp->SetLineWidth(2);
      hBp->SetLineColor(kBlack);
    }
}
