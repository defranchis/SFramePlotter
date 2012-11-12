#ifndef STEERPLOTTER__
#define STEERPLOTTER__

#include <TObjArray.h>
#include <TArrayI.h>
#include <TArrayF.h>
#include <TString.h>
#include "BaseSteer.h"


class SteerPlotter: public BaseSteer {

public:
    SteerPlotter();
    virtual ~SteerPlotter();
  
    virtual void Print(Option_t* option="") const;
  
    void SetShapeNorm(Bool_t flag);
    Bool_t GetShapeNorm();

    void SetLumiNorm(Bool_t flag);
    Bool_t GetLumiNorm();
   
    void SetRatioPlot(Bool_t flag);
    Bool_t GetRatioPlot();

    void SetPortrait(Bool_t flag);
    Bool_t GetPortrait();

    void SetFitPtBalanceHists(Bool_t flag);
    Bool_t GetFitPtBalanceHists();

    void SetJetShapesPerSlice(Bool_t flag);
    Bool_t GetJetShapesPerSlice();

    void SetDrawEntries(Bool_t flag);
    Bool_t GetDrawEntries();

    void SetSampleNames(const char* in);
    TObjArray* GetSampleNames();

    void SetInputFiles(const char* in);
    TObjArray* GetInputFiles();

    void SetOutputPsFile(const char* in);
    const char* GetOutputPsFile();

    void SetCycleName(const char* in);
    const char* GetCycleName();

    void SetLegStrings(const char* in);
    TObjArray* GetLegStrings();

    void SetHistColors(const char* in);
    TArrayI GetHistColors();
   
    void SetHistMarkers(const char* in);
    TArrayI GetHistMarkers();

    void SetSamplesToStack(const char* in);
    TObjArray* GetSamplesToStack();

    void SetSamplesWeight(const char* in);
    TArrayF GetSamplesWeight();
    
    void SetSubstractBkgd(Bool_t flag);
    Bool_t GetSubstractBkgd();

    void SetDrawLumi(Bool_t flag);
    Bool_t GetDrawLumi();

    void SetDrawLegend(Bool_t flag);
    Bool_t GetDrawLegend();

    void SetLumi(Float_t lumi);
    Float_t GetLumi();


private:

    Bool_t    bShapeNorm;         // Shape normalization?
    Bool_t    bLumiNorm;          // Lumi normalization?
    Bool_t    bRatioPlot;         // plot ratios?
    Bool_t    bPortrait;          // portrait or landscape 
    Bool_t    bDrawEntries;       // draw the number of entries?
    Bool_t    bDrawLumi;          // draw the lumi information?
    Bool_t    bDrawLegend;        // draw the legend everywhere?
    Bool_t    bFitPtBalanceHists; // fit Pt-balance histograms?
    Bool_t    bJetShapesPerSlice; // plot each slide of the jet shape histograms?
    Int_t     fNumOfSamples;      // how many analysis samples should be plotted
    Float_t   fLumi;              // integrated luminosity of sample
    TObjArray  fSampleNames;      // all sample name

    TObjArray fSamplesToStack;    // name of samples that should be stacked on top of each other
    Int_t     fNumOfSamplesToStack; // how many samples should be stacked
    Bool_t    bSubstractBkgd;     // substract all background samples?

    TArrayF   fSamplesWeight;     // weights for the different samples
    
    TObjArray fInputFiles;        // input filenames
    TString   fCycleName;         // name of the cycle, can be used as prefix for the filenames
    TString   fOutputPsFile;      // name of the resulting ps file

    TArrayI   fHistColors;        // the histogram colors
    TArrayI   fHistMarkers;       // the histogram markers

    TObjArray fLegStrings;        // legend entries
 
    ClassDef(SteerPlotter,0)      // steering class for the SFrame Plotter

};

#endif
