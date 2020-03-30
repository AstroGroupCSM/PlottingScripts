void elvesStyle(){

  // define names for colours
  Int_t black  = 1;
  Int_t red    = 2;
  Int_t green  = 3;
  Int_t blue   = 4;
  Int_t yellow = 5; 
  Int_t magenta= 6;
  Int_t cyan   = 7;
  Int_t purple = 9;
  

////////////////////////////////////////////////////////////////////
// PURPOSE:
//
// This macro defines a standard style for (black-and-white) 
// "publication quality" Elves ROOT plots. 
//
// USAGE:
//
// Include the lines
//   gROOT->ProcessLine(".L paperStyle.C");
//   paperStyle();
// at the beginning of your root macro.
//
// Example usage is given in myPlot.C
//
// COMMENTS:
//
// Font:
// 
// The font is chosen to be 132, this is Times New Roman (like the text of
//  your document) with precision 2.
//
// "Landscape histograms":
//
// The style here is designed for more or less square plots.
// For longer histograms, or canvas with many pads, adjustements are needed. 
// For instance, for a canvas with 1x5 histograms:
//  TCanvas* c1 = new TCanvas("c1", "L0 muons", 600, 800);
//  c1->Divide(1,5);
//  Adaptions like the following will be needed:
//  gStyle->SetTickLength(0.05,"x");
//  gStyle->SetTickLength(0.01,"y");
//  gStyle->SetLabelSize(0.15,"x");
//  gStyle->SetLabelSize(0.1,"y");
//  gStyle->SetStatW(0.15);
//  gStyle->SetStatH(0.5);
//
// Authors: Thomas Schietinger, Andrew Powell, Chris Parkes, Niels Tuning
// Maintained by Editorial board member (currently Niels)
///////////////////////////////////////////////////////////////////

  // Use times new roman, precision 2 
  Int_t elvesFont        = 42;  // Old Elves style: 62;
  // Line thickness
  Double_t elvesWidth    = 2.5; // Old Elves style: 3.00;
  // Text size
  Double_t elvesTSize    = 0.05; 
  
  // use plain black on white colors
  gROOT->SetStyle("Plain"); 
  TStyle *elvesStyle= new TStyle("elvesStyle","Elves plots style");
  
  //elvesStyle->SetErrorX(0); //  don't suppress the error bar along X

   elvesStyle->SetFillColor(0);      // 1
   elvesStyle->SetFillStyle(0);   // 1001 solid
   elvesStyle->SetFrameFillColor(0);
   elvesStyle->SetFrameBorderMode(0);
   elvesStyle->SetPadBorderMode(0);
   elvesStyle->SetPadColor(0);
   elvesStyle->SetCanvasBorderMode(0);
   elvesStyle->SetCanvasColor(0);
   elvesStyle->SetStatColor(0);
   elvesStyle->SetLegendBorderSize(0);

  // If you want the usual gradient palette (blue -> red)
  elvesStyle->SetPalette(1);
  // If you want colors that correspond to gray scale in black and white:
  int colors[8] = {0,5,7,3,6,2,4,1};
  elvesStyle->SetPalette(8,colors);
  //fancy color palette
  const int NRGBs = 5;
  const int MaxColours = 255;//roberto changed this to 127 in reconstruction
  int palette[MaxColours];
  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t redarr[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t greenarr[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t bluearr[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  Int_t FI = TColor::CreateGradientColorTable(NRGBs, stops, redarr, greenarr, bluearr, MaxColours);
  for (int i=0;i<MaxColours;i++) {
    palette[i] = FI+i;
  }
  cout << "Color Palette Start: "<<  palette[0] << endl;
  TColor::SetPalette(MaxColours,palette);
  gStyle->SetNumberContours(MaxColours);//only do the analysis if dealing with the run of choice.    

  // set the paper & margin sizes
  elvesStyle->SetPaperSize(20,26);
  elvesStyle->SetPadTopMargin(0.05); // (0.05);
  elvesStyle->SetPadRightMargin(0.15); // (0.05); // increase for colz plots
  elvesStyle->SetPadBottomMargin(0.1);
  //  elvesStyle->SetPadLeftMargin(0.1);
  elvesStyle->SetPadLeftMargin(0.15); // (0.15);


  // use large fonts
  elvesStyle->SetTextFont(elvesFont);
  elvesStyle->SetTextSize(elvesTSize);
  elvesStyle->SetLabelFont(elvesFont,"x");
  elvesStyle->SetLabelFont(elvesFont,"y");
  elvesStyle->SetLabelFont(elvesFont,"z");
  elvesStyle->SetLabelSize(elvesTSize,"x");
  elvesStyle->SetLabelSize(elvesTSize,"y");
  elvesStyle->SetLabelSize(elvesTSize,"z");
  elvesStyle->SetTitleFont(elvesFont);
  elvesStyle->SetTitleFont(elvesFont,"x");
  elvesStyle->SetTitleFont(elvesFont,"y");
  elvesStyle->SetTitleFont(elvesFont,"z");
  elvesStyle->SetTitleSize(1.*elvesTSize,"x");
  elvesStyle->SetTitleSize(1.*elvesTSize,"y");
  elvesStyle->SetTitleSize(1.*elvesTSize,"z");

  // use medium bold lines and thick markers
  elvesStyle->SetLineWidth(elvesWidth);
  elvesStyle->SetFrameLineWidth(elvesWidth);
  elvesStyle->SetHistLineWidth(elvesWidth);
  elvesStyle->SetFuncWidth(elvesWidth);
  elvesStyle->SetGridWidth(elvesWidth);
  elvesStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes
  elvesStyle->SetMarkerStyle(20);
  elvesStyle->SetMarkerSize(1.0);
  
  // label offsets
  elvesStyle->SetLabelOffset(0.005,"X");
  elvesStyle->SetLabelOffset(0.015,"Y");

  // by default, do not display histogram decorations:
  elvesStyle->SetOptStat(0);  
  //elvesStyle->SetOptStat("emr");  // show only nent -e , mean - m , rms -r
  // full opts at http://root.cern.ch/root/html/TStyle.html#TStyle:SetOptStat
  elvesStyle->SetStatFormat("6.3g"); // specified as c printf options
  elvesStyle->SetOptTitle(0);
  elvesStyle->SetOptFit(0);
  //elvesStyle->SetOptFit(1011); // order is probability, Chi2, errors, parameters
  //titles
  elvesStyle->SetTitleOffset(0.95,"X");
  elvesStyle->SetTitleOffset(1.4,"Y");
  elvesStyle->SetTitleOffset(1.2,"Z");
  elvesStyle->SetTitleFillColor(0);
  elvesStyle->SetTitleStyle(0);
  elvesStyle->SetTitleBorderSize(0);
  elvesStyle->SetTitleFont(elvesFont,"title");
  elvesStyle->SetTitleX(0.0);
  elvesStyle->SetTitleY(1.0); 
  elvesStyle->SetTitleW(1.0);
  elvesStyle->SetTitleH(0.05);
  
  // look of the statistics box:
  elvesStyle->SetStatBorderSize(0);
  elvesStyle->SetStatFont(elvesFont);
  elvesStyle->SetStatFontSize(0.05);
  elvesStyle->SetStatX(0.9);
  elvesStyle->SetStatY(0.9);
  elvesStyle->SetStatW(0.25);
  elvesStyle->SetStatH(0.15);

  // put tick marks on top and RHS of plots
  elvesStyle->SetPadTickX(1);
  elvesStyle->SetPadTickY(1);

  // histogram divisions: only 5 in x to avoid label overlaps
  elvesStyle->SetNdivisions(510,"x");
  elvesStyle->SetNdivisions(510,"y");
  
  gROOT->SetStyle("elvesStyle");
  //gROOT force style makes center of histogram blanc and not transparent  
  //gROOT->ForceStyle();

  // add Elves label
  TPaveText *elvesName = new TPaveText(gStyle->GetPadLeftMargin() + 0.05,
				      0.87 - gStyle->GetPadTopMargin(),
				      gStyle->GetPadLeftMargin() + 0.20,
				      0.95 - gStyle->GetPadTopMargin(),
				      "BRNDC");
  elvesName->AddText("Elves");
  elvesName->SetFillColor(0);
  elvesName->SetTextAlign(12);
  elvesName->SetBorderSize(0);

  TText *elvesLabel = new TText();
  elvesLabel->SetTextFont(elvesFont);
  elvesLabel->SetTextColor(1);
  elvesLabel->SetTextSize(elvesTSize);
  elvesLabel->SetTextAlign(12);

  TLatex *elvesLatex = new TLatex();
  elvesLatex->SetTextFont(elvesFont);
  elvesLatex->SetTextColor(1);
  elvesLatex->SetTextSize(elvesTSize);
  elvesLatex->SetTextAlign(12);

  cout << "--------------------------" << endl;  
  cout << "Set Elves Style - Oct 2017" << endl;
  cout << "--------------------------" << endl;  
  
}


