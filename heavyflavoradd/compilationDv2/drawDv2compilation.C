#include <fstream>
#include <vector>

#include <TGraphAsymmErrors.h>
#include <TH2F.h>
#include <TCanvas.h>

#include "xjjrootuti.h"

void drawDv2compilation()
{
  //
  std::ifstream getALICE("datapoints/v2_D_ALICEcent3050.dat");
  int nxALICE = 0;
  std::vector<float> xALICE, yALICE, xstatALICElow, xstatALICEhigh, xsystALICE, xfeedALICE, ystatALICE, ysystALICE, yfeedALICElow, yfeedALICEhigh;
  while(true)
    {
      float temp, x, y, exlow, exhigh, exsyst, exfeed, eystat, eysyst, eyfeedlow, eyfeedhigh;
      getALICE >> x;
      if(getALICE.eof()) { break; }
      getALICE >> y 
               >> exlow >> temp >> exhigh >> temp >> exsyst >> temp 
               >> temp >> eystat >> temp >> eysyst >> temp >> eyfeedhigh >> temp >> eyfeedlow;
      xALICE.push_back(x);
      yALICE.push_back(y);
      xstatALICElow.push_back(x - exlow);
      xstatALICEhigh.push_back(exhigh - x);
      xsystALICE.push_back(x - exsyst);
      xfeedALICE.push_back(0.4); //
      ystatALICE.push_back(eystat - y);
      ysystALICE.push_back(eysyst - y);
      yfeedALICElow.push_back(y - eyfeedlow);
      yfeedALICEhigh.push_back(eyfeedhigh - y);
      nxALICE++;
    }
  TGraphAsymmErrors* grALICEstat = new TGraphAsymmErrors(nxALICE, xALICE.data(), yALICE.data(), xstatALICElow.data(), xstatALICEhigh.data(), ystatALICE.data(), ystatALICE.data());
  grALICEstat->SetName("grALICEstat");
  xjjroot::setthgrstyle(grALICEstat, kBlack, 20, 1, kBlack, 1, 2, 0., 0., 0);
  TGraphAsymmErrors* grALICEsyst = new TGraphAsymmErrors(nxALICE, xALICE.data(), yALICE.data(), xsystALICE.data(), xsystALICE.data(), ysystALICE.data(), ysystALICE.data());
  grALICEsyst->SetName("grALICEsyst");
  xjjroot::setthgrstyle(grALICEsyst, 0, 20, 0, kBlack, 1, 2, 0, 0., 0);
  TGraphAsymmErrors* grALICEfeed = new TGraphAsymmErrors(nxALICE, xALICE.data(), yALICE.data(), xfeedALICE.data(), xfeedALICE.data(), yfeedALICElow.data(), yfeedALICEhigh.data());
  grALICEfeed->SetName("grALICEfeed");
  xjjroot::setthgrstyle(grALICEfeed, kBlack, 20, 1, 0, 0, 0, kGray, 0.9, 1001);
  
  //
  std::ifstream getSTAR("datapoints/v2_Dzero_STARcent1040.dat");
  int nxSTAR = 0;
  std::vector<float> xSTAR, ySTAR, xstatSTAR, xsystSTAR, xfeedSTAR, ystatSTAR, ysystSTAR, yfeedSTARlow, yfeedSTARhigh;
  while(true)
    {
      float temp, x, y, eystat, eysyst, eyfeed;
      getSTAR >> x;
      if(getSTAR.eof()) { break; }
      getSTAR >> y
              >> temp >> eystat >> temp >> eysyst >> temp >> eyfeed;
      xSTAR.push_back(x);
      ySTAR.push_back(y);
      xstatSTAR.push_back(0);
      xsystSTAR.push_back(0.4);
      xfeedSTAR.push_back(0.4);
      ystatSTAR.push_back(eystat - y);
      ysystSTAR.push_back(eysyst - y);
      yfeedSTARlow.push_back(y - eyfeed);
      yfeedSTARhigh.push_back(0);
      nxSTAR++;
    }
  TGraphAsymmErrors* grSTARstat = new TGraphAsymmErrors(nxSTAR, xSTAR.data(), ySTAR.data(), xstatSTAR.data(), xstatSTAR.data(), ystatSTAR.data(), ystatSTAR.data());
  grSTARstat->SetName("grSTARstat");
  xjjroot::setthgrstyle(grSTARstat, kAzure-1, 20, 1, kAzure-1, 1, 2, 0., 0., 0);
  TGraphAsymmErrors* grSTARsyst = new TGraphAsymmErrors(nxSTAR, xSTAR.data(), ySTAR.data(), xsystSTAR.data(), xsystSTAR.data(), ysystSTAR.data(), ysystSTAR.data());
  grSTARsyst->SetName("grSTARsyst");
  xjjroot::setthgrstyle(grSTARsyst, 0, 20, 0, kAzure-1, 1, 2, 0, 0., 0);
  TGraphAsymmErrors* grSTARfeed = new TGraphAsymmErrors(nxSTAR, xSTAR.data(), ySTAR.data(), xfeedSTAR.data(), xfeedSTAR.data(), yfeedSTARlow.data(), yfeedSTARhigh.data());
  grSTARfeed->SetName("grSTARfeed");
  xjjroot::setthgrstyle(grSTARfeed, kAzure-1, 20, 1, 0, 0, 0, kAzure-9, 0.8, 1001);
  
  //
  std::ifstream getCMS("datapoints/v2_D_CMScent3050.dat");
  int nxCMS = 0;
  std::vector<float> xCMS, yCMS, xstatCMS, xsystCMS, xfeedCMS, ystatCMS, ysystCMS, yfeedCMS;
  while(true)
    {
      float x, y, exlow, exhigh, eystat, eysyst, eyfeed;
      getCMS >> exhigh;
      if(getCMS.eof()) { break; }
      getCMS >> exlow >> eystat >> eysyst >> eyfeed >> y;
      xCMS.push_back((exlow + exhigh) / 2.);
      yCMS.push_back(y);
      xstatCMS.push_back((exhigh - exlow) / 2.);
      xsystCMS.push_back(0.5);
      xfeedCMS.push_back(0.5);
      ystatCMS.push_back(eystat);
      ysystCMS.push_back(eysyst);
      yfeedCMS.push_back(eyfeed);
      nxCMS++;
    }
  TGraphAsymmErrors* grCMSstat = new TGraphAsymmErrors(nxCMS, xCMS.data(), yCMS.data(), xstatCMS.data(), xstatCMS.data(), ystatCMS.data(), ystatCMS.data());
  grCMSstat->SetName("grCMSstat");
  xjjroot::setthgrstyle(grCMSstat, kRed+1, 20, 1, kRed+1, 1, 2, 0., 0., 0);
  TGraphAsymmErrors* grCMSsyst = new TGraphAsymmErrors(nxCMS, xCMS.data(), yCMS.data(), xsystCMS.data(), xsystCMS.data(), ysystCMS.data(), ysystCMS.data());
  grCMSsyst->SetName("grCMSsyst");
  xjjroot::setthgrstyle(grCMSsyst, 0, 20, 0, kRed+1, 1, 2, 0, 0., 0);
  TGraphAsymmErrors* grCMSfeed = new TGraphAsymmErrors(nxCMS, xCMS.data(), yCMS.data(), xfeedCMS.data(), xfeedCMS.data(), yfeedCMS.data(), yfeedCMS.data());
  grCMSfeed->SetName("grCMSfeed");
  xjjroot::setthgrstyle(grCMSfeed, kRed+1, 20, 1, 0, 0, 0, kRed-9, 0.9, 1001);
  
  //
  
  xjjroot::setgstyle(2);
  TH2F* hempty = new TH2F("hempty", ";p_{T} (GeV/c);v_{2}", 10, 0, 40, 10, -0.07, 0.27);
  xjjroot::sethempty(hempty, 0, 0);
  TLegend* leg = new TLegend(0.4, 0.65, 0.8, 0.80);
  xjjroot::setleg(leg, 0.035);
  leg->AddEntry(grALICEfeed, "ALICE D^{0}, D^{+}, D*^{+} |y| < 0.8", "p");
  leg->AddEntry(grCMSfeed, "CMS D^{0} |y| < 1", "p");
  leg->AddEntry((TObject*)0, "", NULL);
  leg->AddEntry(grSTARfeed, "STAR D^{0} |y| < 1", "p");  
  TCanvas* c = new TCanvas("c", "", 600, 600);
  hempty->Draw();
  xjjroot::drawline(0, 0, 40, 0, kBlack, 2, 2);
  grALICEfeed->Draw("2 same");
  grALICEsyst->Draw("5 same");
  grALICEstat->Draw("pe same");
  grCMSfeed->Draw("2 same");
  grCMSsyst->Draw("5 same");
  grCMSstat->Draw("pe same");
  grSTARfeed->Draw("2 same");
  grSTARsyst->Draw("5 same");
  grSTARstat->Draw("pe same");
  leg->Draw();
  xjjroot::drawtex(0.43, 0.83, "PbPb 5.02 TeV, Cent. 30-50%", 0.035);
  xjjroot::drawtex(0.43, 0.71, "AuAu 200 GeV, Cent. 10-40%", 0.035);
  c->SaveAs("plots/cv2_Dmeson_compilation.pdf");
}

int main() { drawDv2compilation(); return 0; }
