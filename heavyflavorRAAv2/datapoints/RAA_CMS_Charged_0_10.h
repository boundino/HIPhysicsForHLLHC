namespace RAA_CMS_Charged_0_10
{
  void setbincontentsCharged(TH1D* RAA_0_10652, double lumiweightTG=1., double lumiweightMB=1.)
  {
    double lumiweight;
    // TH1D *RAA_0_10652 = new TH1D("RAA_0_10652","",37, xAxis415);
    RAA_0_10652->SetBinContent(1,-1);
    RAA_0_10652->SetBinContent(2,-1);
    /*
      RAA_0_10652->SetBinContent(1,0.2771282);
      RAA_0_10652->SetBinContent(2,0.3052039);
    */
    RAA_0_10652->SetBinContent(3,0.3122264);
    RAA_0_10652->SetBinContent(4,0.3347685);
    RAA_0_10652->SetBinContent(5,0.3657362);
    RAA_0_10652->SetBinContent(6,0.3862972);
    RAA_0_10652->SetBinContent(7,0.3968657);
    RAA_0_10652->SetBinContent(8,0.4211645);
    RAA_0_10652->SetBinContent(9,0.4366343);
    RAA_0_10652->SetBinContent(10,0.4525232);
    RAA_0_10652->SetBinContent(11,0.4500477);
    RAA_0_10652->SetBinContent(12,0.451296);
    RAA_0_10652->SetBinContent(13,0.4471952);
    RAA_0_10652->SetBinContent(14,0.4082864);
    RAA_0_10652->SetBinContent(15,0.3150872);
    RAA_0_10652->SetBinContent(16,0.2309568);
    RAA_0_10652->SetBinContent(17,0.1834603);
    RAA_0_10652->SetBinContent(18,0.1611591);
    RAA_0_10652->SetBinContent(19,0.1501392);
    RAA_0_10652->SetBinContent(20,0.1573041);
    RAA_0_10652->SetBinContent(21,0.1869755);
    RAA_0_10652->SetBinContent(22,0.2253094);
    RAA_0_10652->SetBinContent(23,0.2752406);
    RAA_0_10652->SetBinContent(24,0.3147697);
    RAA_0_10652->SetBinContent(25,0.3503461);
    RAA_0_10652->SetBinContent(26,0.3964676);
    RAA_0_10652->SetBinContent(27,0.4457038);
    RAA_0_10652->SetBinContent(28,0.5086377);
    RAA_0_10652->SetBinContent(29,0.569791);
    RAA_0_10652->SetBinContent(30,0.6007634);
    RAA_0_10652->SetBinContent(31,0.6709129);
    RAA_0_10652->SetBinContent(32,0.7433472);
    RAA_0_10652->SetBinContent(33,0.7586866);
    RAA_0_10652->SetBinContent(34,0.7391942);
    RAA_0_10652->SetBinContent(35,0.870546);
    RAA_0_10652->SetBinContent(36,0.9372227);
    RAA_0_10652->SetBinContent(37,0.7426298);

    lumiweight = lumiweightMB;
    RAA_0_10652->SetBinError(1,1.852048e-05/lumiweight);
    RAA_0_10652->SetBinError(2,1.781832e-05/lumiweight);
    RAA_0_10652->SetBinError(3,1.590585e-05/lumiweight);
    RAA_0_10652->SetBinError(4,1.806417e-05/lumiweight);
    RAA_0_10652->SetBinError(5,2.062184e-05/lumiweight);
    RAA_0_10652->SetBinError(6,2.311544e-05/lumiweight);
    RAA_0_10652->SetBinError(7,2.636835e-05/lumiweight);
    RAA_0_10652->SetBinError(8,2.296098e-05/lumiweight);
    RAA_0_10652->SetBinError(9,2.922176e-05/lumiweight);
    RAA_0_10652->SetBinError(10,3.656023e-05/lumiweight);
    RAA_0_10652->SetBinError(11,4.408691e-05/lumiweight);
    RAA_0_10652->SetBinError(12,5.292073e-05/lumiweight);
    RAA_0_10652->SetBinError(13,6.260601e-05/lumiweight);
    RAA_0_10652->SetBinError(14,4.208063e-05/lumiweight);
    RAA_0_10652->SetBinError(15,6.087311e-05/lumiweight);
    RAA_0_10652->SetBinError(16,7.816374e-05/lumiweight);
    RAA_0_10652->SetBinError(17,0.0001005092/lumiweight);
    RAA_0_10652->SetBinError(18,0.0001318889/lumiweight);
    RAA_0_10652->SetBinError(19,0.0001710099/lumiweight);
    RAA_0_10652->SetBinError(20,0.0001675139/lumiweight);
    RAA_0_10652->SetBinError(21,0.0003686715/lumiweight);
    RAA_0_10652->SetBinError(22,0.0007142326/lumiweight);
    RAA_0_10652->SetBinError(23,0.001041413/lumiweight);
    RAA_0_10652->SetBinError(24,0.002140439/lumiweight);
    RAA_0_10652->SetBinError(25,0.00360321/lumiweight);
    RAA_0_10652->SetBinError(26,0.005177473/lumiweight);
    RAA_0_10652->SetBinError(27,0.007527579/lumiweight);
    RAA_0_10652->SetBinError(28,0.009157896/lumiweight);
    lumiweight = lumiweightTG;
    RAA_0_10652->SetBinError(29,0.00802999/lumiweight);
    RAA_0_10652->SetBinError(30,0.01217806/lumiweight);
    RAA_0_10652->SetBinError(31,0.01313377/lumiweight);
    RAA_0_10652->SetBinError(32,0.02048009/lumiweight);
    RAA_0_10652->SetBinError(33,0.02996343/lumiweight);
    RAA_0_10652->SetBinError(34,0.03323364/lumiweight);
    RAA_0_10652->SetBinError(35,0.06843142/lumiweight);
    RAA_0_10652->SetBinError(36,0.06615173/lumiweight);
    RAA_0_10652->SetBinError(37,0.1936642/lumiweight);
  }
  // RAA_0_10652->SetLineWidth(2);
  // RAA_0_10652->SetLineColor(kRed);
  // RAA_0_10652->SetMarkerStyle(20);
  // RAA_0_10652->SetMarkerSize(1.0); // 0.8
  // RAA_0_10652->SetMarkerColor(kRed);

  void drawsystCharged(double lumiweightTG=1., double lumiweightMB=1., double errminimum=0.03)
  {
    double lumiweight;

    Int_t ci;      // for color index setting
    TColor *color; // for color definition with alpha
    ci = TColor::GetColor("#ffcc00");
    Float_t originY1,originY2,newYerr;

    lumiweight = lumiweightMB;

    TBox *box = new TBox(0.7,0.2877726,0.8,0.3366802);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(0.8,0.3086116,0.9,0.3609254);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(0.9,0.3370222,1,0.3944502);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(1,0.3536476,1.1,0.4189467);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(1.1,0.3635073,1.2,0.430224);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(1.2,0.3809891,1.4,0.4613399);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(1.4,0.3919529,1.6,0.4813157);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(1.6,0.3990729,1.8,0.5059734);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(1.8,0.3968999,2,0.5031955);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(2,0.390829,2.2,0.5117629);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(2.2,0.3872791,2.4,0.5071113);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(2.4,0.3456978,3.2,0.4708749);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(3.2,0.2596246,4,0.3705497);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(4,0.1907752,4.8,0.2711384);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(4.8,0.1560569,5.6,0.2108636);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(5.6,0.1408331,6.4,0.1814852);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(6.4,0.1360042,7.2,0.1642742);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(7.2,0.143132,9.6,0.1714763);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(9.6,0.1701252,12,0.2038258);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(12,0.2027024,14.4,0.2479165);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(14.4,0.2476198,19.2,0.3028613);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(19.2,0.2831853,24,0.3463541);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(24,0.3152349,28.8,0.3854572);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(28.8,0.356697,35.2,0.4362381);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(35.2,0.4009954,41.6,0.4904121);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(41.6,0.4585842,48,0.5586913);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    lumiweight = lumiweightTG;

    box = new TBox(48,0.5136403,60.8,0.6259418);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(60.8,0.5412306,73.6,0.6602962);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(73.6,0.6044208,86.4,0.7374051);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(86.4,0.6692803,103.6,0.8174141);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(103.6,0.6825923,120.8,0.8347809);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(120.8,0.6649543,140,0.8134341);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(140,0.7831733,165,0.9579187);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(165,0.8424182,250,1.032027);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    box = new TBox(250,0.6664159,400,0.8188436);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

  }

}
