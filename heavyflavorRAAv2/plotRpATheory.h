#include <vector>
#include <string>
#include <fstream>

#include <TGraph.h>
#include <TLegend.h>

#include "xjjrootuti.h"

std::vector<TGraph*> gPOWLANG;
std::vector<std::string> vname = {"EPS09", "HTL0p2", "HTL0p4", "lQCD0p2", "lQCD0p4"};
std::vector<std::string> vleg = {"EPS09, no medium", "HTL, smear=0.2 fm", "HTL, smear=0.4 fm", "lQCD, smear=0.2 fm", "lQCD, smear=0.4 fm"};
std::vector<int> vlstyle = {2, 1, 3, 9, 8};
std::vector<Color_t> vlcolor = {kMagenta-6, kGreen-2, kGreen-2, kOrange+7, kOrange+7};
TLegend* legPOWLANG;

const int nmax = 100;
void drawPOWLANG()
{
  int N_ = vname.size();
  #ifndef create_gPOWLANG_
  legPOWLANG = new TLegend(0.15, 0.50, 0.50, 0.70);
  xjjroot::setleg(legPOWLANG, 0.040);
  for(int i=0;i<N_;i++)
    {
      std::ifstream getdata(std::string("datapoints/RpPb-Bhadrons-5TeV_"+vname[i]+".txt").c_str());
      float x[27], y[27]; int nx=0;
      while(true)
        {
          float temp;
          getdata>>temp;
          if(getdata.eof()) { break; }
          x[nx] = temp;
          getdata>>y[nx];
          nx++;
        }
      TGraph* gtemp = new TGraph(nx, x, y);
      gtemp->SetName(std::string("gr_"+vname[i]).c_str());
      gtemp->SetLineWidth(2);
      gtemp->SetLineStyle(vlstyle[i]);
      gtemp->SetLineColor(vlcolor[i]);
      gPOWLANG.push_back(gtemp);      
      legPOWLANG->AddEntry(gtemp, vleg[i].c_str(), "l");
    }
  #define create_gPOWLANG_
  #endif
  
  for(auto& it : gPOWLANG) { it->Draw("same lc"); }
  xjjroot::drawtex(0.16, 0.73, "POWLANG 0-20%", 0.04);
  legPOWLANG->Draw();

}
