#include "xjjrootuti.h"
#include "plotRpA.h"
#include "plotRpATheory.h"

Double_t errorD0lowpt = 0.30; // 30%
Double_t errorsystD0lowpt = 0.137405/0.722896; // lowest pt bin
Float_t trkerr = 0.04; //minimum tracking syst

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
      eyBpafter[i] = systerror;
    }
  getBp.close();
  getBp.clear();
  TGraphErrors* gRpA_Bp_before = new TGraphErrors(nxBp,axBp,ayBpbefore,exBp,eyBpbefore);
  gRpA_Bp_before->SetName("gRpA_Bp_before");
  TGraphErrors* gRpA_Bp_after = new TGraphErrors(nxBp,axBp,ayBpafter,exBp,eyBpafter);
  gRpA_Bp_after->SetName("gRpA_Bp_after");


  // B0

  const int nxB0 = 8;
  Double_t xB0[nxB0+1] = {10., 15., 20., 25., 30., 35., 40., 50., 60.};
  TH1D* hRpA_B0_before = new TH1D("hRpA_B0_before","",nxB0,xB0);
  TH1D* hRpA_B0_after = new TH1D("hRpA_B0_after","",nxB0,xB0);
  Double_t axB0[nxB0],exB0[nxB0],ayB0before[nxB0],eyB0before[nxB0],ayB0after[nxB0],eyB0after[nxB0];
  std::ifstream getB0("datapoints/RpA_CMS_B0_0_100.dat");
  for(int i=0;i<nxB0;i++)
    {
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
      eyB0after[i] = systerror;
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
      eyBsafter[i] = systerror;
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
  //

  Float_t pti = 5;
  Float_t pte = 65;
  
  TH2F* hempty = new TH2F("hempty", ";p_{T} (GeV);R_{pA}", 50, pti, pte, 10., 0, 3.);
  xjjroot::sethempty(hempty, -0.1, -0.2, 0.05, 0.04);
  TLine* line = new TLine(pti, 1, pte, 1);
  xjjroot::setline(line, kRed, 2, 2);
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
  TLatex* texlumiafter = new TLatex(0.965, 0.945, "2 pb^{-1} (pPb 5.02 TeV)");
  xjjroot::settex(texlumiafter, 0.045, 31);
  TLatex* texcent = new TLatex(0.60, 0.20, Form("Centrality 0-100%s", "%"));
  xjjroot::settex(texcent, 0.055);
  TLatex* texrap = new TLatex(0.67, 0.72, "|y_{lab}| < 2.4");
  xjjroot::settex(texrap, 0.055);

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

  c3 = new TCanvas("c3after", "", 1800, 600);
  c3->Divide(3, 1);

  c3->cd(1);
  hempty->Draw();
  line->Draw();
  gRpA_Bp_after->Draw("5same");
  hRpA_Bp_after->Draw("plsame");
  drawPOWLANG();
  legRpABp->Draw();

  c3->cd(2);
  hempty->Draw();
  line->Draw();
  gRpA_B0_after->Draw("5same");
  hRpA_B0_after->Draw("plsame");
  drawPOWLANG();
  legRpAB0->Draw();

  c3->cd(3);
  hempty->Draw();
  line->Draw();
  gRpA_Bs_after->Draw("5same");
  hRpA_Bs_after->Draw("plsame");
  drawPOWLANG();
  legRpABs->Draw();

  for(int i=0;i<3;i++)
    {
      c3->cd(i+1);
      texcms->Draw();
      texpreafter->Draw();
      texlumiafter->Draw();
      // texcent->Draw();
      texrap->Draw();
    }
  c3->SaveAs(Form("plots/cRpA_lumiTG_%.0f.pdf", lumiTG_after));

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
