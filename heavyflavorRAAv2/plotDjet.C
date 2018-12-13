#include "plotDjet.h"

void plotDjet(float lumi_before_pp, float lumi_before_PbPb, float lumi_after_pp, float lumi_after_PbPb)
{
  xjjroot::setgstyle(1);
  gStyle->SetLineWidth(2);

  if(nsplotDjet::inithist(lumi_before_pp, lumi_before_PbPb, lumi_after_pp, lumi_after_PbPb)) return;
  if(nsplotDjet::setupstyle()) return;

  Float_t jetptmin = 60, jetptmax = 999, jetetamin = 0, jetetamax = 1.6;
  TString texjetpt = jetptmax<999?Form("%s < |p_{T}^{jet}| < %s GeV/c",xjjc::number_remove_zero(jetptmin).c_str(),xjjc::number_remove_zero(jetptmax).c_str()):Form("|p_{T}^{jet}| > %s GeV/c",xjjc::number_remove_zero(jetptmin).c_str());
  std::vector<TString> vectex =
    {
      "|y^{D}| < 2",
      texjetpt,
      jetetamin<=0?Form("|#eta^{jet}| < %s",xjjc::number_remove_zero(jetetamax).c_str()):Form("%s < |#eta^{jet}| < %s",xjjc::number_remove_zero(jetetamin).c_str(),xjjc::number_remove_zero(jetetamax).c_str()),
    };

  for(int i=0;i<nPtBins;i++)
    {
      Float_t yaxismin = i==0?8.e-2:2.e-3;
      Float_t yaxismax = i==0?1.e+2:5.e+2;
      TH2F* hemptysep = new TH2F("hemptysep", ";r;#frac{1}{N_{JD}} #frac{dN_{JD}}{dr}", 5, drBins[0], drBins[nDrBins], 10, yaxismin, yaxismax);
      nsplotDjet::setuphempty(hemptysep);
      TH2F* hemptyPullsep = new TH2F("hemptyPullsep", ";r;#frac{1}{N_{JD}} #frac{dN_{JD}}{dr} (PbPb / pp)", 5, drBins[0], drBins[nDrBins], 10, 0, 3.5);
      nsplotDjet::setuphempty(hemptyPullsep);
      TH2F* hemptyPull = new TH2F("hemptyPull", ";r;#frac{1}{N_{JD}} #frac{dN_{JD}}{dr} (PbPb / pp)", 5, drBins[0], drBins[nDrBins], 10, 0, 4.);
      nsplotDjet::setuphempty(hemptyPull);

      TString texpt = ptBins[i+1]>900?Form("p_{T}^{D} > %s GeV/c",xjjc::number_remove_zero(ptBins[i]).c_str()):Form("%s < p_{T}^{D} < %s GeV/c",xjjc::number_remove_zero(ptBins[i]).c_str(),xjjc::number_remove_zero(ptBins[i+1]).c_str());
      vectex.insert(vectex.begin(),texpt);
      std::vector<TString> vectexD = {texpt, "|y^{D}| < 2"};
      std::vector<TString> vectexJ = {texjetpt, jetetamin<=0?Form("|#eta^{jet}| < %s",xjjc::number_remove_zero(jetetamax).c_str()):Form("%s < |#eta^{jet}| < %s",xjjc::number_remove_zero(jetetamin).c_str(),xjjc::number_remove_zero(jetetamax).c_str())};

      TCanvas *c1, *c2;

      //
      c2 = new TCanvas("c2", "", 1200, 600);
      c2->Divide(2, 1);
      c2->cd(1);
      TPad* pbefore = new TPad("pbefore", "", 0, 0, 1, 1);
      pbefore->SetMargin(xjjroot::margin_pad_left, xjjroot::margin_pad_right, xjjroot::margin_pad_bottom*0.7, xjjroot::margin_pad_top);
      pbefore->SetLogy();
      pbefore->Draw();
      pbefore->cd();
      hemptysep->Draw();
      TLegend* legonly = new TLegend(0.24, 0.30-2*0.065, 0.70, 0.30);
      xjjroot::setleg(legonly, 0.045);
      agSignalRsubMePbPb_before[i]->Draw("2 same");
      ahSignalRsubMePbPb_before[i]->Draw("pe same");
      legonly->AddEntry(agSignalRsubMePbPb_before[i], "PbPb", "pf");
      agSignalRsubMePP_before[i]->Draw("2 same");
      ahSignalRsubMePP_before[i]->Draw("pe same");
      legonly->AddEntry(agSignalRsubMePP_before[i], "pp", "pf");

      xjjroot::drawtex(0.22, 0.827, "CMS", 0.062, 11, 62);
      // xjjroot::drawtex(0.35, 0.827, "Preliminary", 0.042, 11, 52);
      // xjjroot::drawtex(0.22, 0.785, "Supplementary", 0.042, 11, 52);
      xjjroot::drawtex(0.22, 0.785, "Performance", 0.042, 11, 52);
      xjjroot::drawtex(0.22, 0.83-0.07-0.046, "D^{0} + jet", 0.062, 11, 62);
      xjjroot::drawtex(0.96, 0.92, "pp 27.4 pb^{-1} + PbPb 0.4 nb^{-1}", 0.037, 31);
      xjjroot::drawtex(0.19, 0.92, "#sqrt{s_{NN}} = 5.02 TeV", 0.037, 11);
      Float_t texxpos = 0.62, texypos = 0.84, texdypos = 0.070; texypos += texdypos;
      for(std::vector<TString>::const_iterator it=vectex.begin(); it!=vectex.end(); it++)
        xjjroot::drawtex(texxpos, texypos=(texypos-texdypos), *it, 0.043);
      legonly->Draw();
      gPad->RedrawAxis();

      c2->cd(2);
      TPad* pafter = new TPad("pafter", "", 0, 0, 1, 1);
      pafter->SetMargin(xjjroot::margin_pad_left, xjjroot::margin_pad_right, xjjroot::margin_pad_bottom*0.7, xjjroot::margin_pad_top);
      pafter->SetLogy();
      pafter->Draw();
      pafter->cd();
      hemptysep->Draw();
      agSignalRsubMePbPb_after[i]->Draw("2 same");
      ahSignalRsubMePbPb_after[i]->Draw("pe same");
      agSignalRsubMePP_after[i]->Draw("2 same");
      ahSignalRsubMePP_after[i]->Draw("pe same");

      xjjroot::drawtex(0.22, 0.827, "CMS", 0.062, 11, 62);
      // xjjroot::drawtex(0.35, 0.827, "Preliminary", 0.042, 11, 52);
      // xjjroot::drawtex(0.22, 0.785, "Supplementary", 0.042, 11, 52);
      xjjroot::drawtex(0.22, 0.785, "Projection", 0.042, 11, 52);
      xjjroot::drawtex(0.22, 0.83-0.07-0.046, "D^{0} + jet", 0.062, 11, 62);
      xjjroot::drawtex(0.96, 0.92, "pp 650 pb^{-1} + PbPb 10 nb^{-1}", 0.037, 31);
      xjjroot::drawtex(0.19, 0.92, "#sqrt{s_{NN}} = 5.02 TeV", 0.037, 11);
      texxpos = 0.62; texypos = 0.84; texdypos = 0.070; texypos += texdypos;
      for(std::vector<TString>::const_iterator it=vectex.begin(); it!=vectex.end(); it++)
        xjjroot::drawtex(texxpos, texypos=(texypos-texdypos), *it, 0.043);
      legonly->Draw();
      gPad->RedrawAxis();

      c2->SaveAs(Form("plots/cDjet_dNdr_%d_v1.pdf",i));
      delete pafter;
      delete pbefore;
      delete c2;


      //
      c2 = new TCanvas("c2", "", 1200, 600);
      c2->Divide(2, 1);
      c2->cd(1);
      pbefore = new TPad("pbeforev2", "", 0, 0, 1, 1);
      pbefore->SetMargin(xjjroot::margin_pad_left, xjjroot::margin_pad_right, xjjroot::margin_pad_bottom*0.7, xjjroot::margin_pad_top);
      pbefore->SetLogy();
      pbefore->Draw();
      pbefore->cd();
      hemptysep->Draw();
      agSignalRsubMePbPb_after[i]->Draw("2 same");
      ahSignalRsubMePbPb_after[i]->Draw("pe same");
      agSignalRsubMePP_after[i]->Draw("2 same");
      ahSignalRsubMePP_after[i]->Draw("pe same");

      xjjroot::drawtex(0.22, 0.827, "CMS", 0.062, 11, 62);
      xjjroot::drawtex(0.22, 0.785, "Projection", 0.042, 11, 52);
      xjjroot::drawtex(0.22, 0.83-0.07-0.046, "D^{0} + jet", 0.062, 11, 62);
      xjjroot::drawtex(0.96, 0.92, "pp 650 pb^{-1} + PbPb 10 nb^{-1}", 0.037, 31);
      xjjroot::drawtex(0.19, 0.92, "#sqrt{s_{NN}} = 5.02 TeV", 0.037, 11);
      texxpos = 0.62; texypos = 0.84; texdypos = 0.070; texypos += texdypos;
      for(std::vector<TString>::const_iterator it=vectex.begin(); it!=vectex.end(); it++)
        xjjroot::drawtex(texxpos, texypos=(texypos-texdypos), *it, 0.043);
      legonly->Draw();
      gPad->RedrawAxis();

      TLegend* legonlyv2 = new TLegend(0.22, 0.15, 0.70, 0.15+0.044*2);
      xjjroot::setleg(legonlyv2, 0.042);
      legonlyv2->SetNColumns(2);
      legonlyv2->AddEntry(agSignalRsubMeSumPP_before[i], " ", "pf");
      legonlyv2->AddEntry(agSignalRsubMeSumPbPb_before[i], "Current Unc.", "pf");
      legonlyv2->AddEntry(agSignalRsubMeSumPP_after[i], " ", "pf");
      legonlyv2->AddEntry(agSignalRsubMeSumPbPb_after[i], "Projected Unc.", "pf");
      c2->cd(2);
      pafter = new TPad("pafterv2", "", 0, 0, 1, 1);
      pafter->SetMargin(xjjroot::margin_pad_left, xjjroot::margin_pad_right, xjjroot::margin_pad_bottom*0.7, xjjroot::margin_pad_top);
      pafter->SetLogy();
      pafter->Draw();
      pafter->cd();
      hemptysep->Draw();
      agSignalRsubMeSumPbPb_before[i]->Draw("2 same");
      agSignalRsubMeSumPbPb_after[i]->Draw("2p same");
      agSignalRsubMeSumPP_before[i]->Draw("2 same");
      agSignalRsubMeSumPP_after[i]->Draw("2p same");

      xjjroot::drawtex(0.22, 0.827, "CMS", 0.062, 11, 62);
      xjjroot::drawtex(0.22, 0.785, "Projection", 0.042, 11, 52);
      xjjroot::drawtex(0.22, 0.83-0.07-0.046, "D^{0} + jet", 0.062, 11, 62);
      xjjroot::drawtex(0.96, 0.92, "pp 650 pb^{-1} + PbPb 10 nb^{-1}", 0.037, 31);
      xjjroot::drawtex(0.19, 0.92, "#sqrt{s_{NN}} = 5.02 TeV", 0.037, 11);
      texxpos = 0.62; texypos = 0.84; texdypos = 0.070; texypos += texdypos;
      for(std::vector<TString>::const_iterator it=vectex.begin(); it!=vectex.end(); it++)
        xjjroot::drawtex(texxpos, texypos=(texypos-texdypos), *it, 0.043);
      legonlyv2->Draw();
      xjjroot::drawtex(0.23, 0.25, "pp", 0.042, 11);
      xjjroot::drawtex(0.30, 0.25, "PbPb", 0.042, 11);
      gPad->RedrawAxis();

      c2->SaveAs(Form("plots/cDjet_dNdr_%d_v2.pdf",i));
      delete pafter;
      delete pbefore;
      delete c2;

      //
      c2 = new TCanvas("c2", "", 1200, 600);
      c2->Divide(2, 1);
      c2->cd(1);
      pbefore = new TPad("pbeforePull", "", 0, 0, 1, 1);
      pbefore->SetMargin(xjjroot::margin_pad_left, xjjroot::margin_pad_right, xjjroot::margin_pad_bottom*0.7, xjjroot::margin_pad_top);
      pbefore->Draw();
      pbefore->cd();
      hemptyPullsep->Draw();
      xjjroot::drawline(drBins[0], 1, drBins[nDrBins], 1, kGray+3, 2, 2);
      agSignalRsubMeRatio_before[i]->Draw("2 same");
      ahSignalRsubMeRatio_before[i]->Draw("pe same");

      xjjroot::drawtex(0.22, 0.827, "CMS", 0.062, 11, 62);
      xjjroot::drawtex(0.22, 0.785, "Performance", 0.042, 11, 52);
      xjjroot::drawtex(0.22, 0.83-0.07-0.046, "D^{0} + jet", 0.062, 11, 62);
      xjjroot::drawtex(0.96, 0.92, "pp 27.4 pb^{-1} + PbPb 0.4 nb^{-1}", 0.037, 31);
      xjjroot::drawtex(0.19, 0.92, "#sqrt{s_{NN}} = 5.02 TeV", 0.037, 11);
      texxpos = 0.62, texypos = 0.84, texdypos = 0.070;
      texypos += texdypos;
      for(std::vector<TString>::const_iterator it=vectexD.begin(); it!=vectexD.end(); it++)
        xjjroot::drawtex(texxpos, texypos=(texypos-texdypos), *it, 0.043);
      texxpos = 0.22, texypos = 0.64, texdypos = 0.070;
      texypos += texdypos;
      for(std::vector<TString>::const_iterator it=vectexJ.begin(); it!=vectexJ.end(); it++)
        xjjroot::drawtex(texxpos, texypos=(texypos-texdypos), *it, 0.043);
      gPad->RedrawAxis();

      c2->cd(2);
      pafter = new TPad("pafterPull", "", 0, 0, 1, 1);
      pafter->SetMargin(xjjroot::margin_pad_left, xjjroot::margin_pad_right, xjjroot::margin_pad_bottom*0.7, xjjroot::margin_pad_top);
      pafter->Draw();
      pafter->cd();
      hemptyPullsep->Draw();
      xjjroot::drawline(drBins[0], 1, drBins[nDrBins], 1, kGray+3, 2, 2);
      agSignalRsubMeRatio_after[i]->Draw("2 same");
      ahSignalRsubMeRatio_after[i]->Draw("pe same");
      xjjroot::drawtex(0.22, 0.827, "CMS", 0.062, 11, 62);
      // xjjroot::drawtex(0.35, 0.827, "Preliminary", 0.042, 11, 52);
      // xjjroot::drawtex(0.22, 0.785, "Supplementary", 0.042, 11, 52);
      xjjroot::drawtex(0.22, 0.785, "Projection", 0.042, 11, 52);
      xjjroot::drawtex(0.22, 0.83-0.07-0.046, "D^{0} + jet", 0.062, 11, 62);
      xjjroot::drawtex(0.96, 0.92, "pp 650 pb^{-1} + PbPb 10 nb^{-1}", 0.037, 31);
      xjjroot::drawtex(0.19, 0.92, "#sqrt{s_{NN}} = 5.02 TeV", 0.037, 11);
      texxpos = 0.62, texypos = 0.84, texdypos = 0.070;
      texypos += texdypos;
      for(std::vector<TString>::const_iterator it=vectexD.begin(); it!=vectexD.end(); it++)
        xjjroot::drawtex(texxpos, texypos=(texypos-texdypos), *it, 0.043);
      texxpos = 0.22, texypos = 0.64, texdypos = 0.070;
      texypos += texdypos;
      for(std::vector<TString>::const_iterator it=vectexJ.begin(); it!=vectexJ.end(); it++)
        xjjroot::drawtex(texxpos, texypos=(texypos-texdypos), *it, 0.043);
      gPad->RedrawAxis();

      c2->SaveAs(Form("plots/cDjet_Ratio_%d_v1.pdf",i));
      delete pafter;
      delete pbefore;
      delete c2;

      c2 = new TCanvas("c2", "", 1200, 600);
      c2->Divide(2, 1);
      TLegend* legv2 = new TLegend((!i?0.21:0.60), (!i?0.53:0.71)-2*0.042, (!i?0.21+0.3:0.60+0.3), (!i?0.53:0.71));
      xjjroot::setleg(legv2, 0.04);
      legv2->AddEntry(agSignalRsubMeSumRatio_before[i], "Current Unc.", "f");
      legv2->AddEntry(agSignalRsubMeSumRatio_after[i], "Projected Unc.", "f");

      c2->cd(1);
      pbefore = new TPad("pbeforePull", "", 0, 0, 1, 1);
      pbefore->SetMargin(xjjroot::margin_pad_left, xjjroot::margin_pad_right, xjjroot::margin_pad_bottom*0.7, xjjroot::margin_pad_top);
      pbefore->Draw();
      pbefore->cd();
      hemptyPull->Draw();
      // xjjroot::drawline(drBins[0], 1, drBins[nDrBins], 1, kGray+3, 2, 2);
      agSignalRsubMeRatio_after[i]->Draw("2 same");
      ahSignalRsubMeRatio_after[i]->Draw("pe same");
      xjjroot::drawline(drBins[0], 1, drBins[nDrBins], 1, kGray+3, 2, 2);
      xjjroot::drawtex(0.22, 0.827, "CMS", 0.062, 11, 62);
      xjjroot::drawtex(0.22, 0.785, "Projection", 0.042, 11, 52);
      xjjroot::drawtex(0.22, 0.83-0.07-0.046, "D^{0} + jet", 0.062, 11, 62);
      xjjroot::drawtex(0.96, 0.92, "pp 650 pb^{-1} + PbPb 10 nb^{-1}", 0.037, 31);
      xjjroot::drawtex(0.19, 0.92, "#sqrt{s_{NN}} = 5.02 TeV", 0.037, 11);
      texxpos = 0.62, texypos = 0.84, texdypos = 0.070;
      texypos += texdypos;
      for(std::vector<TString>::const_iterator it=vectexD.begin(); it!=vectexD.end(); it++)
        xjjroot::drawtex(texxpos, texypos=(texypos-texdypos), *it, 0.043);
      texxpos = 0.22, texypos = 0.65, texdypos = 0.070; //
      texypos += texdypos;
      for(std::vector<TString>::const_iterator it=vectexJ.begin(); it!=vectexJ.end(); it++)
        xjjroot::drawtex(texxpos, texypos=(texypos-texdypos), *it, 0.043);
      gPad->RedrawAxis();

      c2->cd(2);
      pafter = new TPad("pafterPull", "", 0, 0, 1, 1);
      pafter->SetMargin(xjjroot::margin_pad_left, xjjroot::margin_pad_right, xjjroot::margin_pad_bottom*0.7, xjjroot::margin_pad_top);
      pafter->Draw();
      pafter->cd();
      hemptyPull->Draw();
      // xjjroot::drawline(drBins[0], 1, drBins[nDrBins], 1, kGray+3, 2, 2);
      agSignalRsubMeSumRatio_before[i]->Draw("2 same");
      agSignalRsubMeSumRatio_after[i]->Draw("2p same");
      xjjroot::drawline(drBins[0], 1, drBins[nDrBins], 1, kGray+3, 2, 2);
      xjjroot::drawtex(0.22, 0.827, "CMS", 0.062, 11, 62);
      xjjroot::drawtex(0.22, 0.785, "Projection", 0.042, 11, 52);
      xjjroot::drawtex(0.22, 0.83-0.07-0.046, "D^{0} + jet", 0.062, 11, 62);
      xjjroot::drawtex(0.96, 0.92, "pp 650 pb^{-1} + PbPb 10 nb^{-1}", 0.037, 31);
      xjjroot::drawtex(0.19, 0.92, "#sqrt{s_{NN}} = 5.02 TeV", 0.037, 11);
      texxpos = 0.62, texypos = 0.84, texdypos = 0.070;
      texypos += texdypos;
      for(std::vector<TString>::const_iterator it=vectexD.begin(); it!=vectexD.end(); it++)
        xjjroot::drawtex(texxpos, texypos=(texypos-texdypos), *it, 0.043);
      texxpos = 0.22, texypos = 0.65, texdypos = 0.070; //
      texypos += texdypos;
      for(std::vector<TString>::const_iterator it=vectexJ.begin(); it!=vectexJ.end(); it++)
        xjjroot::drawtex(texxpos, texypos=(texypos-texdypos), *it, 0.043);
      legv2->Draw();
      gPad->RedrawAxis();

      c2->SaveAs(Form("plots/cDjet_Ratio_%d_v2.pdf",i));
      delete pafter;
      delete pbefore;
      delete c2;

      delete hemptysep;
      delete hemptyPullsep;
      delete hemptyPull;
      vectex.erase(vectex.begin());
    }
}

int main(int argc, char* argv[])
{
  if(argc==5) { plotDjet(atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4])); return 0; }
  return 1;
}
