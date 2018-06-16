namespace RAA_CMS_Charged_0_5
{
  void setbincontentsCharged(TH1D* RAA_0_10652, double lumiweightTG=1., double lumiweightMB=1.)
  {
    double lumiweight;
    RAA_0_10652->SetBinContent(1,-1);
    RAA_0_10652->SetBinContent(2,-1);
    RAA_0_10652->SetBinContent(3,0.312275);
    RAA_0_10652->SetBinContent(4,0.332891);
    RAA_0_10652->SetBinContent(5,0.361109);
    RAA_0_10652->SetBinContent(6,0.383584);
    RAA_0_10652->SetBinContent(7,0.393276);
    RAA_0_10652->SetBinContent(8,0.4171);
    RAA_0_10652->SetBinContent(9,0.432394);
    RAA_0_10652->SetBinContent(10,0.448111);
    RAA_0_10652->SetBinContent(11,0.445619);
    RAA_0_10652->SetBinContent(12,0.445238);
    RAA_0_10652->SetBinContent(13,0.440683);
    RAA_0_10652->SetBinContent(14,0.400942);
    RAA_0_10652->SetBinContent(15,0.304434);
    RAA_0_10652->SetBinContent(16,0.219952);
    RAA_0_10652->SetBinContent(17,0.172814);
    RAA_0_10652->SetBinContent(18,0.150769);
    RAA_0_10652->SetBinContent(19,0.140533);
    RAA_0_10652->SetBinContent(20,0.147339);
    RAA_0_10652->SetBinContent(21,0.177115);
    RAA_0_10652->SetBinContent(22,0.220968);
    RAA_0_10652->SetBinContent(23,0.272104);
    RAA_0_10652->SetBinContent(24,0.312697);
    RAA_0_10652->SetBinContent(25,0.349043);
    RAA_0_10652->SetBinContent(26,0.395736);
    RAA_0_10652->SetBinContent(27,0.44859);
    RAA_0_10652->SetBinContent(28,0.498734);
    RAA_0_10652->SetBinContent(29,0.558605);
    RAA_0_10652->SetBinContent(30,0.604546);
    RAA_0_10652->SetBinContent(31,0.66352);
    // RAA_0_10652->SetBinContent(32,0.753243);
    // RAA_0_10652->SetBinContent(33,0.742936);
    // RAA_0_10652->SetBinContent(34,0.724962);
    // RAA_0_10652->SetBinContent(35,0.921811);
    // RAA_0_10652->SetBinContent(36,0.902484);
    // RAA_0_10652->SetBinContent(37,0.855953);
    RAA_0_10652->SetBinContent(32,0.705713);
    RAA_0_10652->SetBinContent(33,0.746987);
    RAA_0_10652->SetBinContent(34,0.783085);
    RAA_0_10652->SetBinContent(35,0.819518);
    RAA_0_10652->SetBinContent(36,0.888001);
    RAA_0_10652->SetBinContent(37,0.981573);
    //
    RAA_0_10652->SetBinContent(38,1.06668);
    // RAA_0_10652->SetBinContent(39,1.15691);

    lumiweight = lumiweightMB;
    RAA_0_10652->SetBinError(1,0/lumiweight);
    RAA_0_10652->SetBinError(2,0/lumiweight);
    RAA_0_10652->SetBinError(3,1.93769e-05/lumiweight);
    RAA_0_10652->SetBinError(4,2.15816e-05/lumiweight);
    RAA_0_10652->SetBinError(5,2.37429e-05/lumiweight);
    RAA_0_10652->SetBinError(6,2.62471e-05/lumiweight);
    RAA_0_10652->SetBinError(7,2.97748e-05/lumiweight);
    RAA_0_10652->SetBinError(8,2.57913e-05/lumiweight);
    RAA_0_10652->SetBinError(9,3.267e-05/lumiweight);
    RAA_0_10652->SetBinError(10,4.07603e-05/lumiweight);
    RAA_0_10652->SetBinError(11,4.90874e-05/lumiweight);
    RAA_0_10652->SetBinError(12,5.87405e-05/lumiweight);
    RAA_0_10652->SetBinError(13,6.95257e-05/lumiweight);
    RAA_0_10652->SetBinError(14,4.69206e-05/lumiweight);
    RAA_0_10652->SetBinError(15,6.83702e-05/lumiweight);
    RAA_0_10652->SetBinError(16,8.89552e-05/lumiweight);
    RAA_0_10652->SetBinError(17,0.000115489/lumiweight);
    RAA_0_10652->SetBinError(18,0.000152109/lumiweight);
    RAA_0_10652->SetBinError(19,0.000197613/lumiweight);
    RAA_0_10652->SetBinError(20,0.00019266/lumiweight);
    RAA_0_10652->SetBinError(21,0.000421873/lumiweight);
    RAA_0_10652->SetBinError(22,0.00083667/lumiweight);
    RAA_0_10652->SetBinError(23,0.00121341/lumiweight);
    RAA_0_10652->SetBinError(24,0.00247651/lumiweight);
    RAA_0_10652->SetBinError(25,0.0041781/lumiweight);
    RAA_0_10652->SetBinError(26,0.00596212/lumiweight);
    RAA_0_10652->SetBinError(27,0.00885955/lumiweight);
    RAA_0_10652->SetBinError(28,0.01097/lumiweight);
    lumiweight = lumiweightTG;
    RAA_0_10652->SetBinError(29,0.0101202/lumiweight);
    RAA_0_10652->SetBinError(30,0.0164629/lumiweight);
    RAA_0_10652->SetBinError(31,0.0188594/lumiweight);
    // RAA_0_10652->SetBinError(32,0.0291023/lumiweight);
    // RAA_0_10652->SetBinError(33,0.0376846/lumiweight);
    // RAA_0_10652->SetBinError(34,0.0426188/lumiweight);
    // RAA_0_10652->SetBinError(35,0.105889/lumiweight);
    // RAA_0_10652->SetBinError(36,0.0833815/lumiweight);
    // RAA_0_10652->SetBinError(37,0.27088/lumiweight);
    RAA_0_10652->SetBinError(32,0.0272659/lumiweight);
    RAA_0_10652->SetBinError(33,0.0378901/lumiweight);
    RAA_0_10652->SetBinError(34,0.0460357/lumiweight);
    RAA_0_10652->SetBinError(35,0.0941385/lumiweight);
    RAA_0_10652->SetBinError(36,0.0820434/lumiweight);
    RAA_0_10652->SetBinError(37,0.3106345/lumiweight);
    //
    RAA_0_10652->SetBinError(38,1.2991390/lumiweight);
    // RAA_0_10652->SetBinError(39,4.3762716/lumiweight);
  }

  void drawsystCharged(double lumiweightTG=1., double lumiweightMB=1., double errminimum=0.03)
  {
    double lumiweight;
    
    Int_t ci;
    TColor *color;
    ci = TColor::GetColor("#ffcc00");
    Float_t originY1,originY2,newYerr;
    
    lumiweight = lumiweightMB;
    
    TBox *box;

    box = new TBox(0.7,0.287817,0.8,0.336733);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(0.8,0.306881,0.9,0.358901);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(0.9,0.332758,1,0.38946);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(1,0.351164,1.1,0.416004);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(1.1,0.360219,1.2,0.426333);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(1.2,0.377312,1.4,0.456888);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(1.4,0.388146,1.6,0.476642);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(1.6,0.395182,1.8,0.50104);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(1.8,0.392994,2,0.498244);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(2,0.385583,2.2,0.504893);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(2.2,0.381639,2.4,0.499727);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(2.4,0.339479,3.2,0.462405);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(3.2,0.250847,4,0.358021);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(4,0.181685,4.8,0.258219);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(4.8,0.147001,5.6,0.198627);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(5.6,0.131753,6.4,0.169785);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(6.4,0.127302,7.2,0.153764);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(7.2,0.134065,9.6,0.160613);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(9.6,0.161153,12,0.193077);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(12,0.198797,14.4,0.243139);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(14.4,0.244798,19.2,0.29941);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(19.2,0.281321,24,0.344073);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(24,0.314063,28.8,0.384024);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(28.8,0.356039,35.2,0.435433);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(35.2,0.403592,41.6,0.493588);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(41.6,0.449655,48,0.547813);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    

    lumiweight = lumiweightTG;

    box = new TBox(48,0.503557,60.8,0.613653);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(60.8,0.54464,73.6,0.664452);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    box = new TBox(73.6,0.597763,86.4,0.729277);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    // box = new TBox(86.4,0.678191,103.6,0.828295);
    box = new TBox(86.4,0.635397,103.6,0.776029);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    // box = new TBox(103.6,0.668421,120.8,0.817451);
    box = new TBox(103.6,0.672066,120.8,0.821908);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    // box = new TBox(120.8,0.652151,140,0.797773);
    box = new TBox(120.8,0.704436,140,0.861734);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    // box = new TBox(140,0.829299,165,1.01432);
    box = new TBox(140,0.737272,165,0.901761);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    // box = new TBox(165,0.811194,250,0.993774);
    box = new TBox(165,0.798176,250,0.977826);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();
    
    // box = new TBox(250,0.768109,400,0.943797);
    box = new TBox(250,0.880837,400,1.082309);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    //
    box = new TBox(400,0.645381,600,1.487979);
    originY1 = box->GetY1();
    originY2 = box->GetY2();
    newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    box->SetY1((originY2+originY1)/2.-newYerr);
    box->SetY2((originY2+originY1)/2.+newYerr);
    ci = TColor::GetColor("#ffcc00");
    box->SetFillColor(ci);
    box->Draw();

    // box = new TBox(600,-0.262276,1000,2.576096);
    // originY1 = box->GetY1();
    // originY2 = box->GetY2();
    // newYerr = ((1./lumiweight)*(originY2-originY1)/(originY2+originY1))>errminimum?((1./lumiweight)*(originY2-originY1)/2.):(errminimum*(originY2+originY1)/2.);
    // box->SetY1((originY2+originY1)/2.-newYerr);
    // box->SetY2((originY2+originY1)/2.+newYerr);
    // ci = TColor::GetColor("#ffcc00");
    // box->SetFillColor(ci);
    // box->Draw();
    
  }
}
