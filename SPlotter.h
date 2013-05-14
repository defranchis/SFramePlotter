#ifndef SPLOTTER_H
#define SPLOTTER_H

#include <cstdlib>
#include <TH1.h>
#include <THStack.h>
#include <TH2.h>
#include <TString.h>
#include <TObject.h>
#include <TCanvas.h>
#include <TPostScript.h>
#include "SHist.h"

class SPlotter
{

 public:
  
  SPlotter();
  ~SPlotter();

  // main functions
  void ProcessAndPlot(std::vector<TObjArray*> hists);
  std::vector<SHist*> GetPlottableHists(std::vector<TObjArray*> histarr, int index);
  std::vector<SHist*> GetHistsAtIndex(std::vector<TObjArray*> histarr, int index);
  void PlotHists(std::vector<SHist*> hists, int ipad);
  void DrawNormError(SHist* stack);
  void PlotRatios(std::vector<SHist*> hists, int ipad);
  void PlotLumiYield(SHist* hist, int ipad);

  // collect all histograms
  void DoStacking(std::vector<TObjArray*>& hists, TObjArray* StackNames);
  TObjArray* GetStacks(std::vector<TObjArray*>& hists, int index=-1);

  // utilities
  void Cleanup();
  void SetupGlobalStyle();
  void SetupCanvas();
  void SetupCanvasForEPS();
  void OpenPostscript(TString dir, TString hname="");
  void ClosePostscript();
  int GetCurrentPad(int);
  void DrawPageNum();
  std::vector<SHist*> CalcRatios(std::vector<SHist*> hists);
  void ShapeNormalise(std::vector<SHist*> hists);
  void DrawLegend(std::vector<SHist*> hists);
  void DrawLumi();
  double CalcNormErrorForBin(SHist* stack, int i);
  
  // cosmetics
  void DoCosmetics(std::vector<SHist*> hists);
  void GeneralCosmetics(TH1* hist);
  void PortraitCosmetics(TH1* hist);
  void LandscapeCosmetics(TH1* hist);
  void YieldCosmetics(TH1* hist);
  void RatioCosmetics(TH1* hist);
  void SingleEPSCosmetics(TH1* hist);
  void SingleEPSRatioCosmetics(TH1* hist);
  void CopyStyle(TH1& h1, TH1* h2);
  bool SetMinMax(std::vector<SHist*> hists);
  void SetLogAxes(std::vector<SHist*> hists);
  
  // select a few histograms
  SHist* SelStack(std::vector<SHist*> hists);
  SHist* SelData(std::vector<SHist*> hists);

  // setters
  void SetDebug(bool flag=true){debug=flag;}
  void SetShapeNorm(Bool_t flag = true){bShapeNorm = flag;}
  void SetPortraitMode(Bool_t flag = true){bPortrait = flag;}
  void SetSingleEPSMode(Bool_t flag = true){bSingleEPS = flag;}
  void SetDrawEntries(Bool_t flag = true){bDrawEntries = flag;}
  void SetPlotRatio(Bool_t flag=true){bPlotRatio = flag;}
  void SetDrawLumi(Bool_t flag=true){bDrawLumi = flag;}
  void SetLumi(float lumi){m_lumi = lumi;}
  void SetNormError(float err){m_syserr = err;}
  void SetDrawLegend(Bool_t flag=true){bDrawLegend = flag;}
  void SetPsFilename(TString name);

 private:

  // do the stacking
  void StackHists(std::vector<TObjArray*>& hists, int index);

  TCanvas* m_can; 
  TPostScript* m_ps; 
  TString m_ps_name;

  TPad* m_pad1;
  TPad* m_pad2;

  TPad* m_rp1_top;
  TPad* m_rp1;
  TPad* m_rp2_top;
  TPad* m_rp2;
  
  int   m_page;             // page number in ps file  
  bool  debug;              // output of debugging information
  bool  bShapeNorm;         // use shape normalization
  bool  bPortrait;          // portrait or landscape mode
  bool  bSingleEPS;         // single eps file for each plot
  bool  bDrawEntries;       // display the number of entries 
  bool  bDrawLumi;          // display the lumi information 
  float m_lumi;             // total integrated luminosity
  float m_syserr;           // systematic error on normalisation uncertainty
  bool  bDrawLegend;        // display legend?
  bool  bPlotRatio;         // should a ratio be plotted?
  bool  need_update;        // should the canvas get an update?
  

};

#endif
