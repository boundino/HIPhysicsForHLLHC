#include "datapoints/Djet_datatable.h"
#include <TH1D.h>
#include <TGraphErrors.h>
#include <TMath.h>
#include <TH2F.h>
#include <TPad.h>
#include <TCanvas.h>
#include <TLegend.h>
#include "xjjrootuti.h"
#include "xjjcuti.h"

TH1D* ahSignalRsubMePP_before[nPtBins];
TH1D* ahSignalRsubMePbPb_before[nPtBins];
TH1D* ahSignalRsubMeRatio_before[nPtBins];

TH1D* ahSignalRsubMePP_after[nPtBins];
TH1D* ahSignalRsubMePbPb_after[nPtBins];
TH1D* ahSignalRsubMeRatio_after[nPtBins];

TGraphErrors* agSignalRsubMePP_before[nPtBins];
TGraphErrors* agSignalRsubMePbPb_before[nPtBins];
TGraphErrors* agSignalRsubMeRatio_before[nPtBins];
TGraphErrors* agSignalRsubMeSumPP_before[nPtBins];
TGraphErrors* agSignalRsubMeSumPbPb_before[nPtBins];
TGraphErrors* agSignalRsubMeSumRatio_before[nPtBins];

TGraphErrors* agSignalRsubMePP_after[nPtBins];
TGraphErrors* agSignalRsubMePbPb_after[nPtBins];
TGraphErrors* agSignalRsubMeRatio_after[nPtBins];
TGraphErrors* agSignalRsubMeSumPP_after[nPtBins];
TGraphErrors* agSignalRsubMeSumPbPb_after[nPtBins];
TGraphErrors* agSignalRsubMeSumRatio_after[nPtBins];

namespace nsplotDjet
{
  int inithist(float lumi_before_pp, float lumi_before_PbPb, float lumi_after_pp, float lumi_after_PbPb)
  {
    Double_t lumi_weight_pp = TMath::Sqrt(lumi_after_pp/lumi_before_pp);
    Double_t lumi_weight_PbPb = TMath::Sqrt(lumi_after_PbPb/lumi_before_PbPb);

    Double_t ax[nDrBins], aex[nDrBins];
    for(int j=0;j<nDrBins;j++) { ax[j] = vax[j]; aex[j] = vaex[j]; };
    for(int i=0;i<nPtBins;i++)
      {
        ahSignalRsubMePP_before[i] = new TH1D(Form("ahSignalRsubMePP_before_%d",i), "", nDrBins, drBins);
        ahSignalRsubMePbPb_before[i] = new TH1D(Form("ahSignalRsubMePbPb_before_%d",i), "", nDrBins, drBins);
        ahSignalRsubMeRatio_before[i] = new TH1D(Form("ahSignalRsubMeRatio_before_%d",i), "", nDrBins, drBins);

        ahSignalRsubMePP_after[i] = new TH1D(Form("ahSignalRsubMePP_after_%d",i), "", nDrBins, drBins);
        ahSignalRsubMePbPb_after[i] = new TH1D(Form("ahSignalRsubMePbPb_after_%d",i), "", nDrBins, drBins);
        ahSignalRsubMeRatio_after[i] = new TH1D(Form("ahSignalRsubMeRatio_after_%d",i), "", nDrBins, drBins);

        Double_t ayPP[nDrBins], aeyPPsyst_before[nDrBins], aeyPPsyst_after[nDrBins], aeyPPall_before[nDrBins], aeyPPall_after[nDrBins];
        Double_t ayPbPb[nDrBins], aeyPbPbsyst_before[nDrBins], aeyPbPbsyst_after[nDrBins], aeyPbPball_before[nDrBins], aeyPbPball_after[nDrBins];
        Double_t ayRatio[nDrBins], aeyRatiosyst_before[nDrBins], aeyRatiosyst_after[nDrBins], aeyRatioall_before[nDrBins], aeyRatioall_after[nDrBins];

        for(int j=0;j<nDrBins;j++)
          {
            ahSignalRsubMePP_before[i]->SetBinContent(j+1, vayPP.at(i).at(j));
            ahSignalRsubMePP_before[i]->SetBinError(j+1, vaeyPPstat.at(i).at(j));
            ahSignalRsubMePbPb_before[i]->SetBinContent(j+1, vayPbPb.at(i).at(j));
            ahSignalRsubMePbPb_before[i]->SetBinError(j+1, vaeyPbPbstat.at(i).at(j));
            ahSignalRsubMeRatio_before[i]->SetBinContent(j+1, vayRatio.at(i).at(j));
            ahSignalRsubMeRatio_before[i]->SetBinError(j+1, vaeyRatiostat.at(i).at(j));

            ahSignalRsubMePP_after[i]->SetBinContent(j+1, vayPP.at(i).at(j));
            ahSignalRsubMePP_after[i]->SetBinError(j+1, vaeyPPstat.at(i).at(j)/lumi_weight_pp);
            ahSignalRsubMePbPb_after[i]->SetBinContent(j+1, vayPbPb.at(i).at(j));
            ahSignalRsubMePbPb_after[i]->SetBinError(j+1, vaeyPbPbstat.at(i).at(j)/lumi_weight_PbPb);
            ahSignalRsubMeRatio_after[i]->SetBinContent(j+1, vayRatio.at(i).at(j));
            ahSignalRsubMeRatio_after[i]->SetBinError(j+1, vaeyRatiostat.at(i).at(j)/lumi_weight_PbPb);

            ayPP[j] = vayPP.at(i).at(j);
            aeyPPsyst_before[j] = vaeyPPsyst.at(i).at(j) * vayPP.at(i).at(j);
            aeyPPsyst_after[j] = vaeyPPsyst_scale.at(i).at(j) * vayPP.at(i).at(j);
            ayPbPb[j] = vayPbPb.at(i).at(j);
            aeyPbPbsyst_before[j] = vaeyPbPbsyst.at(i).at(j) * vayPbPb.at(i).at(j);
            aeyPbPbsyst_after[j] = vaeyPbPbsyst_scale.at(i).at(j) * vayPbPb.at(i).at(j);
            ayRatio[j] = vayRatio.at(i).at(j);
            aeyRatiosyst_before[j] = vaeyRatiosyst.at(i).at(j) * vayRatio.at(i).at(j);
            aeyRatiosyst_after[j] = vaeyRatiosyst_scale.at(i).at(j) * vayRatio.at(i).at(j);

            aeyPPall_before[j] = TMath::Sqrt(ahSignalRsubMePP_before[i]->GetBinError(j+1)*ahSignalRsubMePP_before[i]->GetBinError(j+1) + aeyPPsyst_before[j]*aeyPPsyst_before[j]);
            aeyPPall_after[j] = TMath::Sqrt(ahSignalRsubMePP_after[i]->GetBinError(j+1)*ahSignalRsubMePP_after[i]->GetBinError(j+1) + aeyPPsyst_after[j]*aeyPPsyst_after[j]);
            aeyPbPball_before[j] = TMath::Sqrt(ahSignalRsubMePbPb_before[i]->GetBinError(j+1)*ahSignalRsubMePbPb_before[i]->GetBinError(j+1) + aeyPbPbsyst_before[j]*aeyPbPbsyst_before[j]);
            aeyPbPball_after[j] = TMath::Sqrt(ahSignalRsubMePbPb_after[i]->GetBinError(j+1)*ahSignalRsubMePbPb_after[i]->GetBinError(j+1) + aeyPbPbsyst_after[j]*aeyPbPbsyst_after[j]);
            aeyRatioall_before[j] = TMath::Sqrt(ahSignalRsubMeRatio_before[i]->GetBinError(j+1)*ahSignalRsubMeRatio_before[i]->GetBinError(j+1) + aeyRatiosyst_before[j]*aeyRatiosyst_before[j]);
            aeyRatioall_after[j] = TMath::Sqrt(ahSignalRsubMeRatio_after[i]->GetBinError(j+1)*ahSignalRsubMeRatio_after[i]->GetBinError(j+1) + aeyRatiosyst_after[j]*aeyRatiosyst_after[j]);
          }
        agSignalRsubMePP_before[i] = new TGraphErrors(nDrBins, ax, ayPP, aex, aeyPPsyst_before);
        agSignalRsubMePP_before[i]->SetName(Form("agSignalRsubMePP_before_%d",i));
        agSignalRsubMePbPb_before[i] = new TGraphErrors(nDrBins, ax, ayPbPb, aex, aeyPbPbsyst_before);
        agSignalRsubMePbPb_before[i]->SetName(Form("agSignalRsubMePbPb_before_%d",i));
        agSignalRsubMeRatio_before[i] = new TGraphErrors(nDrBins, ax, ayRatio, aex, aeyRatiosyst_before);
        agSignalRsubMeRatio_before[i]->SetName(Form("agSignalRsubMeRatio_before_%d",i));

        agSignalRsubMePP_after[i] = new TGraphErrors(nDrBins, ax, ayPP, aex, aeyPPsyst_after);
        agSignalRsubMePP_after[i]->SetName(Form("agSignalRsubMePP_after_%d",i));
        agSignalRsubMePbPb_after[i] = new TGraphErrors(nDrBins, ax, ayPbPb, aex, aeyPbPbsyst_after);
        agSignalRsubMePbPb_after[i]->SetName(Form("agSignalRsubMePbPb_after_%d",i));
        agSignalRsubMeRatio_after[i] = new TGraphErrors(nDrBins, ax, ayRatio, aex, aeyRatiosyst_after);
        agSignalRsubMeRatio_after[i]->SetName(Form("agSignalRsubMeRatio_after_%d",i));

        agSignalRsubMeSumPP_before[i] = new TGraphErrors(nDrBins, ax, ayPP, aex, aeyPPall_before);
        agSignalRsubMeSumPP_before[i]->SetName(Form("agSignalRsubMeSumPP_before_%d",i));
        agSignalRsubMeSumPbPb_before[i] = new TGraphErrors(nDrBins, ax, ayPbPb, aex, aeyPbPball_before);
        agSignalRsubMeSumPbPb_before[i]->SetName(Form("agSignalRsubMeSumPbPb_before_%d",i));
        agSignalRsubMeSumRatio_before[i] = new TGraphErrors(nDrBins, ax, ayRatio, aex, aeyRatioall_before);
        agSignalRsubMeSumRatio_before[i]->SetName(Form("agSignalRsubMeSumRatio_before_%d",i));

        agSignalRsubMeSumPP_after[i] = new TGraphErrors(nDrBins, ax, ayPP, aex, aeyPPall_after);
        agSignalRsubMeSumPP_after[i]->SetName(Form("agSignalRsubMeSumPP_after_%d",i));
        agSignalRsubMeSumPbPb_after[i] = new TGraphErrors(nDrBins, ax, ayPbPb, aex, aeyPbPball_after);
        agSignalRsubMeSumPbPb_after[i]->SetName(Form("agSignalRsubMeSumPbPb_after_%d",i));
        agSignalRsubMeSumRatio_after[i] = new TGraphErrors(nDrBins, ax, ayRatio, aex, aeyRatioall_after);
        agSignalRsubMeSumRatio_after[i]->SetName(Form("agSignalRsubMeSumRatio_after_%d",i));
      }

    return 0;
    
  }

  int setupstyle()
  {
    for(int i=0;i<nPtBins;i++)
      {
        // xjjroot::setthgrstyle(ahSignalRsubMePP_before[i], kAzure+3, 20, 1.3, kAzure+3, 1, 2, -1, -1, -1);
        // xjjroot::setthgrstyle(agSignalRsubMePP_before[i], kAzure+3, 20, 1.3, 0, 1, 1, kAzure-8, 0.8, 1001);
        // xjjroot::setthgrstyle(ahSignalRsubMePbPb_before[i], kRed+3, 21, 1.3, kRed+3, 1, 2, -1, -1, -1);
        // xjjroot::setthgrstyle(agSignalRsubMePbPb_before[i], kRed+3, 21, 1.3, 0, 1, 1, kRed-8, 0.8, 1001);
        // xjjroot::setthgrstyle(ahSignalRsubMeRatio_before[i], kBlack, 21, 1.3, kBlack, 1, 2, -1, -1, -1);
        // xjjroot::setthgrstyle(agSignalRsubMeRatio_before[i], kBlack, 21, 1.3, 0, 1, 1, kGray+1, 0.8, 1001);

        xjjroot::setthgrstyle(ahSignalRsubMePP_before[i], kBlack, 20, 1.3, kBlack, 1, 2, -1, -1, -1);
        xjjroot::setthgrstyle(agSignalRsubMePP_before[i], kBlack, 20, 1.3, 0, 1, 1, kAzure-8, 0.8, 1001);
        xjjroot::setthgrstyle(ahSignalRsubMePbPb_before[i], kBlack, 21, 1.3, kBlack, 1, 2, -1, -1, -1);
        xjjroot::setthgrstyle(agSignalRsubMePbPb_before[i], kBlack, 21, 1.3, 0, 1, 1, kRed-8, 0.8, 1001);
        xjjroot::setthgrstyle(ahSignalRsubMeRatio_before[i], kBlack, 21, 1.3, kBlack, 1, 2, -1, -1, -1);
        xjjroot::setthgrstyle(agSignalRsubMeRatio_before[i], kBlack, 21, 1.3, 0, 1, 1, kGray+1, 0.8, 1001);

        // xjjroot::setthgrstyle(ahSignalRsubMePP_after[i], kAzure+3, 20, 1.3, kAzure+3, 1, 2, -1, -1, -1);
        // xjjroot::setthgrstyle(agSignalRsubMePP_after[i], kAzure+3, 20, 1.3, 0, 1, 1, kAzure-8, 0.8, 1001);
        // xjjroot::setthgrstyle(ahSignalRsubMePbPb_after[i], kRed+3, 21, 1.3, kRed+3, 1, 2, -1, -1, -1);
        // xjjroot::setthgrstyle(agSignalRsubMePbPb_after[i], kRed+3, 21, 1.3, 0, 1, 1, kRed-8, 0.8, 1001);
        // xjjroot::setthgrstyle(ahSignalRsubMeRatio_after[i], kBlack, 21, 1.3, kBlack, 1, 2, -1, -1, -1);
        // xjjroot::setthgrstyle(agSignalRsubMeRatio_after[i], kBlack, 21, 1.3, 0, 1, 1, kGray+1, 0.8, 1001);

        xjjroot::setthgrstyle(ahSignalRsubMePP_after[i], kBlack, 20, 1.3, kBlack, 1, 2, -1, -1, -1);
        xjjroot::setthgrstyle(agSignalRsubMePP_after[i], kBlack, 20, 1.3, 0, 1, 1, kAzure-8, 0.8, 1001);
        xjjroot::setthgrstyle(ahSignalRsubMePbPb_after[i], kBlack, 21, 1.3, kBlack, 1, 2, -1, -1, -1);
        xjjroot::setthgrstyle(agSignalRsubMePbPb_after[i], kBlack, 21, 1.3, 0, 1, 1, kRed-8, 0.8, 1001);
        xjjroot::setthgrstyle(ahSignalRsubMeRatio_after[i], kOrange+5, 21, 1.3, kBlack, 1, 2, -1, -1, -1);
        xjjroot::setthgrstyle(agSignalRsubMeRatio_after[i], kOrange+5, 21, 1.3, 0, 1, 1, kOrange, 0.8, 1001);

        xjjroot::setthgrstyle(agSignalRsubMeSumPP_after[i], kBlack, 20, 1.3, 0, 1, 1, kAzure-8, 0.8, 1001);
        xjjroot::setthgrstyle(agSignalRsubMeSumPP_before[i], kBlack, 20, 1.3, 0, 1, 1, kViolet-8, 0.8, 1001);
        xjjroot::setthgrstyle(agSignalRsubMeSumPbPb_after[i], kBlack, 21, 1.3, 0, 1, 1, kRed-8, 0.8, 1001);
        xjjroot::setthgrstyle(agSignalRsubMeSumPbPb_before[i], kBlack, 21, 1.3, 0, 1, 1, kOrange-9, 0.8, 1001);
        xjjroot::setthgrstyle(agSignalRsubMeSumRatio_before[i], kBlack, 21, 1.3, 0, 1, 1, kGray+1, 0.8, 1001);
        xjjroot::setthgrstyle(agSignalRsubMeSumRatio_after[i], kOrange+5, 21, 1.3, 0, 1, 1, kOrange, 0.8, 1001);
      }
    return 0;
  }

  int setuphempty(TH2F* hemptysep)
  {
    hemptysep->GetXaxis()->SetNdivisions(505);
    xjjroot::sethempty(hemptysep, 0, 0.2);
    hemptysep->GetXaxis()->SetTitleOffset(hemptysep->GetXaxis()->GetTitleOffset()*0.7);
    hemptysep->GetYaxis()->SetTitleOffset(hemptysep->GetYaxis()->GetTitleOffset()*0.9);

    return 0;
  }

}
