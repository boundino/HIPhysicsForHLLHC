#include "xjjrootuti.h"
#include "plotRpA.h"
#include "plotRpATheory.h"

Double_t errorD0lowpt = 0.30; // 30%
Double_t errorsystD0lowpt = 0.137405/0.722896; // lowest pt bin
Float_t trkerr = 0.025; //minimum tracking syst (4% => 2.5%)
Float_t muerr = 0.005*2; //minimum muon syst

void plotRpA(Float_t lumiTG_Bp_before, 
             Float_t lumiTG_after)
{

  std::cout<<std::endl;
  std::cout<<"  -------------------- Before --------------------"<<std::endl;
  std::cout<<std::setiosflags(std::ios::left)<<std::setw(37)<<"   lumi (B+ trigger): "<<std::setw(7)<<lumiTG_Bp_before<<" nb-1"<<std::endl;
  std::cout<<"  -------------------- after ---------------------"<<std::endl;
  std::cout<<std::setiosflags(std::ios::left)<<std::setw(37)<<"   lumi (trigger): "<<std::setw(7)<<lumiTG_after<<" nb-1"<<std::endl;
  std::cout<<"  ------------------------------------------------"<<std::endl;
  std::cout<<std::endl;

  Float_t lumiweightTG_Bp = TMath::Sqrt(lumiTG_after/lumiTG_Bp_before);
  TCanvas *c3, *c2, *c1;

  // Bp

  const int nxBp = 8;
  Double_t xBp[nxBp+1] = {10., 15., 20., 25. ,30., 35., 40., 50., 60.};
  TH1D* hRpA_Bp_before = new TH1D("hRpA_Bp_before","",nxBp,xBp);
  TH1D* hRpA_Bp_after = new TH1D("hRpA_Bp_after","",nxBp,xBp);
  Double_t axBp[nxBp],exBp[nxBp],ayBpbefore[nxBp],eyBpbefore[nxBp],ayBpafter[nxBp],eyBpafter[nxBp];
  std::ifstream getBp("datapoints/RpA_CMS_Bp_0_100.dat");
  for(int i=0;i<nxBp;i++)
    {
      // Double_t minierr = trkerr*3;
      Double_t minierr = TMath::Sqrt(trkerr*trkerr+muerr*muerr);
      Double_t centervalue,staterror,systerror,tem;
      getBp>>tem>>tem>>staterror>>systerror>>centervalue;
      hRpA_Bp_before->SetBinContent(i+1,centervalue);
      hRpA_Bp_after->SetBinContent(i+1,centervalue);
      axBp[i] = (xBp[i+1]+xBp[i])/2.;
      exBp[i] = (xBp[i+1]-xBp[i])/2.;
      // exBp[i] = axBp[i]*0.08;
      ayBpbefore[i] = centervalue;
      ayBpafter[i] = centervalue;

      hRpA_Bp_before->SetBinError(i+1,staterror);
      hRpA_Bp_after->SetBinError(i+1,staterror/lumiweightTG_Bp);
      eyBpbefore[i] = systerror;
      eyBpafter[i] = (systerror/lumiweightTG_Bp)<(minierr*centervalue)?(minierr*centervalue):(systerror/lumiweightTG_Bp); //
    }
  getBp.close();
  getBp.clear();
  TGraphErrors* gRpA_Bp_before = new TGraphErrors(nxBp,axBp,ayBpbefore,exBp,eyBpbefore);
  gRpA_Bp_before->SetName("gRpA_Bp_before");
  TGraphErrors* gRpA_Bp_after = new TGraphErrors(nxBp,axBp,ayBpafter,exBp,eyBpafter);
  gRpA_Bp_after->SetName("gRpA_Bp_after");

  const int nxBp_LHCb = 4;
  Double_t xBp_LHCb[nxBp_LHCb+1] = {2., 4., 7., 12., 20.};
  TH1D* hRpA_Bp_LHCb_forward = new TH1D("hRpA_Bp_LHCb_forward","",nxBp_LHCb,xBp_LHCb);
  TH1D* hRpA_Bp_LHCb_backward = new TH1D("hRpA_Bp_LHCb_backward","",nxBp_LHCb,xBp_LHCb);
  Double_t axBp_LHCb[nxBp_LHCb], exBp_LHCb[nxBp_LHCb], ayBp_LHCb_forward[nxBp_LHCb], eyBp_LHCb_forward[nxBp_LHCb], ayBp_LHCb_backward[nxBp_LHCb], eyBp_LHCb_backward[nxBp_LHCb];
  std::ifstream getBp_LHCb_forward("datapoints/LHCb_CMS_Bp_0_100_forward.dat");
  std::ifstream getBp_LHCb_backward("datapoints/LHCb_CMS_Bp_0_100_backward.dat");
  for(int i=0;i<nxBp_LHCb;i++)
    {
      axBp_LHCb[i] = (xBp_LHCb[i+1]+xBp_LHCb[i])/2.;
      exBp_LHCb[i] = (xBp_LHCb[i+1]-xBp_LHCb[i])/2.;
      // exBp_LHCb[i] = 0.6;

      Double_t tem;
      Double_t centervalue_forward, staterror_forward, systerror_forward;
      getBp_LHCb_forward>>tem>>tem>>centervalue_forward>>staterror_forward>>systerror_forward;
      hRpA_Bp_LHCb_forward->SetBinContent(i+1, centervalue_forward);
      hRpA_Bp_LHCb_forward->SetBinError(i+1,staterror_forward);
      ayBp_LHCb_forward[i] = centervalue_forward;
      eyBp_LHCb_forward[i] = systerror_forward;
      Double_t centervalue_backward, staterror_backward, systerror_backward;
      getBp_LHCb_backward>>tem>>tem>>centervalue_backward>>staterror_backward>>systerror_backward;
      hRpA_Bp_LHCb_backward->SetBinContent(i+1, centervalue_backward);
      hRpA_Bp_LHCb_backward->SetBinError(i+1,staterror_backward);
      ayBp_LHCb_backward[i] = centervalue_backward;
      eyBp_LHCb_backward[i] = systerror_backward;

    }
  getBp_LHCb_forward.close();
  getBp_LHCb_forward.clear();
  getBp_LHCb_backward.close();
  getBp_LHCb_backward.clear();
  TGraphErrors* gRpA_Bp_LHCb_forward = new TGraphErrors(nxBp_LHCb,axBp_LHCb,ayBp_LHCb_forward,exBp_LHCb,eyBp_LHCb_forward);
  gRpA_Bp_LHCb_forward->SetName("gRpA_Bp_LHCb_forward");
  TGraphErrors* gRpA_Bp_LHCb_backward = new TGraphErrors(nxBp_LHCb,axBp_LHCb,ayBp_LHCb_backward,exBp_LHCb,eyBp_LHCb_backward);
  gRpA_Bp_LHCb_backward->SetName("gRpA_Bp_LHCb_backward");


  // B0

  const int nxB0 = 8;
  Double_t xB0[nxB0+1] = {10., 15., 20., 25., 30., 35., 40., 50., 60.};
  TH1D* hRpA_B0_before = new TH1D("hRpA_B0_before","",nxB0,xB0);
  TH1D* hRpA_B0_after = new TH1D("hRpA_B0_after","",nxB0,xB0);
  Double_t axB0[nxB0],exB0[nxB0],ayB0before[nxB0],eyB0before[nxB0],ayB0after[nxB0],eyB0after[nxB0];
  std::ifstream getB0("datapoints/RpA_CMS_B0_0_100.dat");
  for(int i=0;i<nxB0;i++)
    {
      // Double_t minierr = trkerr*4;
      Double_t minierr = TMath::Sqrt(trkerr*2*trkerr*2+muerr*muerr);

      Double_t centervalue,staterror,systerror,tem;
      getB0>>tem>>tem>>staterror>>systerror>>centervalue;
      hRpA_B0_before->SetBinContent(i+1,centervalue);
      hRpA_B0_after->SetBinContent(i+1,centervalue);
      axB0[i] = (xB0[i+1]+xB0[i])/2.;
      exB0[i] = (xB0[i+1]-xB0[i])/2.;
      // exB0[i] = axB0[i]*0.08;
      ayB0before[i] = centervalue;
      ayB0after[i] = centervalue;

      hRpA_B0_before->SetBinError(i+1,staterror);
      hRpA_B0_after->SetBinError(i+1,staterror/lumiweightTG_Bp);
      eyB0before[i] = systerror;
      // eyB0after[i] = systerror/lumiweightTG_Bp;
      eyB0after[i] = (systerror/lumiweightTG_Bp)<(minierr*centervalue)?minierr*centervalue:(systerror/lumiweightTG_Bp); //
    }
  getB0.close();
  getB0.clear();
  TGraphErrors* gRpA_B0_before = new TGraphErrors(nxB0,axB0,ayB0before,exB0,eyB0before);
  gRpA_B0_before->SetName("gRpA_B0_before");
  TGraphErrors* gRpA_B0_after = new TGraphErrors(nxB0,axB0,ayB0after,exB0,eyB0after);
  gRpA_B0_after->SetName("gRpA_B0_after");


  // Bs

  const int nxBs = 6;
  Double_t xBs[nxBs+1] = {10., 15., 20., 25., 30., 40., 60.};
  TH1D* hRpA_Bs_before = new TH1D("hRpA_Bs_before","",nxBs,xBs);
  TH1D* hRpA_Bs_after = new TH1D("hRpA_Bs_after","",nxBs,xBs);
  Double_t axBs[nxBs],exBs[nxBs],ayBsbefore[nxBs],eyBsbefore[nxBs],ayBsafter[nxBs],eyBsafter[nxBs];
  std::ifstream getBs("datapoints/RpA_CMS_Bs_0_100.dat");
  for(int i=0;i<nxBs;i++)
    {
      // Double_t minierr = trkerr*4;
      Double_t minierr = TMath::Sqrt(trkerr*2*trkerr*2+muerr*muerr);

      Double_t centervalue,staterror,systerror,tem;
      getBs>>tem>>tem>>staterror>>systerror>>centervalue;
      hRpA_Bs_before->SetBinContent(i+1,centervalue);
      hRpA_Bs_after->SetBinContent(i+1,centervalue);
      axBs[i] = (xBs[i+1]+xBs[i])/2.;
      exBs[i] = (xBs[i+1]-xBs[i])/2.;
      // exBs[i] = axBs[i]*0.08;
      ayBsbefore[i] = centervalue;
      ayBsafter[i] = centervalue;

      hRpA_Bs_before->SetBinError(i+1,staterror);
      hRpA_Bs_after->SetBinError(i+1,staterror/lumiweightTG_Bp);
      eyBsbefore[i] = systerror;
      // eyBsafter[i] = systerror/lumiweightTG_Bp;
      eyBsafter[i] = (systerror/lumiweightTG_Bp)<(minierr*centervalue)?minierr*centervalue:(systerror/lumiweightTG_Bp); //
    }
  getBs.close();
  getBs.clear();
  TGraphErrors* gRpA_Bs_before = new TGraphErrors(nxBs,axBs,ayBsbefore,exBs,eyBsbefore);
  gRpA_Bs_before->SetName("gRpA_Bs_before");
  TGraphErrors* gRpA_Bs_after = new TGraphErrors(nxBs,axBs,ayBsafter,exBs,eyBsafter);
  gRpA_Bs_after->SetName("gRpA_Bs_after");


  // All graphs ready

  //
  SetPlotStyle(hRpA_Bp_before, gRpA_Bp_before);
  SetPlotStyle(hRpA_Bp_after, gRpA_Bp_after);
  SetPlotStyle(hRpA_B0_before, gRpA_B0_before);
  SetPlotStyle(hRpA_B0_after, gRpA_B0_after);
  SetPlotStyle(hRpA_Bs_before, gRpA_Bs_before);
  SetPlotStyle(hRpA_Bs_after, gRpA_Bs_after);

  SetPlotStyle_LHCb(hRpA_Bp_LHCb_forward, gRpA_Bp_LHCb_forward);
  SetPlotStyle_LHCb(hRpA_Bp_LHCb_backward, gRpA_Bp_LHCb_backward);
  //

  Float_t pti = 5;
  Float_t pte = 65;
  
  TH2F* hempty = new TH2F("hempty", ";p_{T} (GeV);R_{pA}", 50, pti, pte, 10., 0.2, 3.);
  xjjroot::sethempty(hempty, -0.1, -0.2, 0.05, 0.04);
  TLine* line = new TLine(pti, 1, pte, 1);
  // xjjroot::setline(line, kRed, 2, 2);
  xjjroot::setline(line, kGray+1, 2, 2);
  TLatex* texcms = new TLatex(0.16, 0.90, "CMS");
  xjjroot::settex(texcms, 0.06, 13, 62);
  TLatex* texpre = new TLatex(0.15, 0.84, "Performance");
  xjjroot::settex(texpre, 0.05, 13, 52);
  TLatex* texpreafter = new TLatex(0.15, 0.84, "Projection");
  xjjroot::settex(texpreafter, 0.05, 13, 52);
  TLatex* texdata = new TLatex(0.15, 0.78, "2013 Data");
  xjjroot::settex(texdata, 0.05, 13);
  TLatex* texlumi = new TLatex(0.965, 0.945, "34.6 nb^{-1} (pPb 5.02 TeV)");
  xjjroot::settex(texlumi, 0.045, 31);
  // TLatex* texlumiafter = new TLatex(0.965, 0.945, "650 pb^{-1} (pp 5.02 TeV) + 2 pb^{-1} (pPb 5.02 TeV)");
  TLatex* texlumiafter = new TLatex(0.965, 0.945, "pp 650 pb^{-1} + pPb 2 pb^{-1}");
  // xjjroot::settex(texlumiafter, 0.045, 31);
  xjjroot::settex(texlumiafter, 0.042, 31);
  TLatex* texsnn = new TLatex(0.13, 0.955, "#lower[-0.2]{#sqrt{s_{NN}}} = 5.02 TeV");
  xjjroot::settex(texsnn, 0.042);
  TLatex* texcent = new TLatex(0.60, 0.20, Form("Centrality 0-100%s", "%"));
  xjjroot::settex(texcent, 0.055);
  TLatex* texrap = new TLatex(0.67, 0.72, "|y_{lab}| < 2.4");
  xjjroot::settex(texrap, 0.055);

  //
  TH2F* hempty_LHCb = new TH2F("hempty_LHCb", ";p_{T} (GeV);R_{pA}", 50, 0, 65, 10., 0.5, 2.2);
  xjjroot::sethempty(hempty_LHCb, -0.1, -0.2, 0.05, 0.04);
  TLine* line_LHCb = new TLine(0, 1, 65, 1);
  // xjjroot::setline(line_LHCb, kRed, 2, 2);
  xjjroot::setline(line_LHCb, kGray+1, 2, 2);
  TLatex* texBp_LHCb = new TLatex(0.16, 0.90, "B^{+}");
  xjjroot::settex(texBp_LHCb, 0.06, 13, 62);


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

  c3 = new TCanvas("c3", "", 1800, 600);
  c3->Divide(3, 1);

  c3->cd(1);
  hempty->Draw();
  line->Draw();
  TLegend* legRpABp = new TLegend(0.65, 0.77, 0.95, 0.89);
  xjjroot::setleg(legRpABp, 0.055);
  legRpABp->AddEntry(hRpA_Bp_before, "B^{+}", "p");
  legRpABp->AddEntry(gRpA_Bp_before, "Syst.", "f");
  gRpA_Bp_before->Draw("5same");
  hRpA_Bp_before->Draw("plsame");
  drawPOWLANG();
  legRpABp->Draw();

  c3->cd(2);
  hempty->Draw();
  line->Draw();
  TLegend* legRpAB0 = new TLegend(0.65, 0.77, 0.95, 0.89);
  xjjroot::setleg(legRpAB0, 0.055);
  legRpAB0->AddEntry(hRpA_B0_before, "B^{0}", "p");
  legRpAB0->AddEntry(gRpA_B0_before, "Syst.", "f");
  gRpA_B0_before->Draw("5same");
  hRpA_B0_before->Draw("plsame");
  drawPOWLANG();
  legRpAB0->Draw();

  c3->cd(3);
  hempty->Draw();
  line->Draw();
  TLegend* legRpABs = new TLegend(0.65, 0.77, 0.95, 0.89);
  xjjroot::setleg(legRpABs, 0.055);
  legRpABs->AddEntry(hRpA_Bs_before, "B^{0}_{s}", "p");
  legRpABs->AddEntry(gRpA_Bs_before, "Syst.", "f");
  gRpA_Bs_before->Draw("5same");
  hRpA_Bs_before->Draw("plsame");
  drawPOWLANG();
  legRpABs->Draw();

  for(int i=0;i<3;i++)
    {
      c3->cd(i+1);
      texcms->Draw();
      texpre->Draw();
      texdata->Draw();
      texlumi->Draw();
      // texcent->Draw();
      texrap->Draw();
    }
  c3->SaveAs(Form("plots/cRpA_lumiTG_%.0f.pdf", lumiTG_Bp_before));


  //

  std::vector<TH1D*> hRpA = {hRpA_Bp_after, hRpA_B0_after, hRpA_Bs_after};
  std::vector<TGraphErrors*> gRpA = {gRpA_Bp_after, gRpA_B0_after, gRpA_Bs_after};
  std::vector<TGraphErrors*> gRpA_leg = {gRpA_Bp_before, gRpA_B0_before, gRpA_Bs_before};
  std::vector<TLegend*> legRpA = {legRpABp, legRpAB0, legRpABs};
  std::vector<std::string> tagname = {"Bp", "B0", "Bs"};

  c3 = new TCanvas("c3after", "", 1800, 600);
  c3->Divide(3, 1);

  for(int i=0;i<3;i++)
    {
      c3->cd(i+1);
      hempty->Draw();
      line->Draw();
      gRpA[i]->Draw("5same");
      hRpA[i]->Draw("plsame");
      drawPOWLANG();
      legRpA[i]->Draw();

      texcms->Draw();
      texpreafter->Draw();
      texsnn->Draw();
      texlumiafter->Draw();
      // texcent->Draw();
      texrap->Draw();
    }
  c3->SaveAs(Form("plots/cRpA_lumiTG_%.0f.pdf", lumiTG_after));

  gStyle->SetLineWidth(2); 
  gStyle->SetFrameLineWidth(2);
  setPOWLANGwidth(4);

  for(int i=0;i<3;i++)
    {
      TCanvas* c1 = new TCanvas("c1", "", 600, 600);
      hempty->Draw();
      line->SetLineWidth(4);
      line->Draw();
      gRpA[i]->SetLineWidth(4);
      gRpA_leg[i]->SetLineWidth(4);
      hRpA[i]->SetLineWidth(4);
      gRpA[i]->Draw("5same");
      hRpA[i]->Draw("plsame");
      drawPOWLANG();
      legRpA[i]->Draw();

      texcms->Draw();
      texpreafter->Draw();
      texsnn->Draw();
      texlumiafter->Draw();
      // texcent->Draw();
      texrap->Draw();
      c1->SaveAs(Form("plots/cRpA_lumiTG_%.0f_%s.pdf", lumiTG_after, tagname[i].c_str()));
      
      delete c1;
    }

  setPOWLANGwidth(3);
  TCanvas* clhcb = new TCanvas("clhcb", "", 600, 600);
  // clhcb->SetLogy();
  hempty_LHCb->Draw();
  line_LHCb->SetLineWidth(4);
  line_LHCb->Draw();
  gRpA_Bp_after->SetLineWidth(3);
  hRpA_Bp_after->SetLineWidth(3);
  gRpA_Bp_after->Draw("5same");
  hRpA_Bp_after->Draw("plsame");
  gRpA_Bp_LHCb_forward->Draw("5same");
  hRpA_Bp_LHCb_forward->Draw("plsame");
  gRpA_Bp_LHCb_backward->Draw("5same");
  hRpA_Bp_LHCb_backward->Draw("plsame");
  drawPOWLANG(0.035);
  TLegend* leg_LHCb = new TLegend(0.57, 0.81-0.048*6, 0.90, 0.81);
  xjjroot::setleg(leg_LHCb, 0.035);
  leg_LHCb->AddEntry(gRpA_Bp_after, "|y_{lab}| < 2.4", "pf");
  leg_LHCb->AddEntry((TObject*)0, "", NULL);
  leg_LHCb->AddEntry((TObject*)0, "", NULL);
  leg_LHCb->AddEntry((TObject*)0, "", NULL);
  leg_LHCb->AddEntry(gRpA_Bp_LHCb_forward, "2.5 < y* < 3.5", "pf");
  leg_LHCb->AddEntry(gRpA_Bp_LHCb_backward, "-3.5 < y* < -2.5", "pf");
  leg_LHCb->Draw();
  texBp_LHCb->Draw();
  texpreafter->Draw();
  xjjroot::drawtex(0.58, 0.88, "#bf{CMS}, 5.02 TeV", 0.035);
  xjjroot::drawtex(0.58, 0.88-0.048, "pp 650 pb^{-1} + pPb 2 pb^{-1}", 0.035);
  xjjroot::drawtex(0.58, 0.88-0.048*4, "#bf{LHCb}, 8.8 TeV", 0.035);
  xjjroot::drawtex(0.58, 0.88-0.048*5, "pp 104 pb^{-1} + pPb 250 nb^{-1}", 0.035);
  clhcb->SaveAs(Form("plots/cRpA_lumiTG_%.0f_Bp_LHCb.pdf", lumiTG_after));

}

int main(int argc, char* argv[])
{
  if(argc==3)
    {
      plotRpA(atof(argv[1]), atof(argv[2]));
      return 0;
    }
  std::cout<<"invalid argc"<<std::endl;
  return 1;
}
