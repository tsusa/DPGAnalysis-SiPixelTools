#ifndef SiPixelDynamicInefficiencyDBReader_H
#define SiPixelDynamicInefficiencyDBReader_H

// system include files
//#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

//
//
// class decleration
//
class SiPixelDynamicInefficiencyDBReader : public edm::EDAnalyzer {
  
public:
  explicit SiPixelDynamicInefficiencyDBReader( const edm::ParameterSet& );
  ~SiPixelDynamicInefficiencyDBReader();
  
  void analyze( const edm::Event&, const edm::EventSetup& );

private:
  const int Phase_;
  int nBarrelLayers_, nForwardDisks_;
  double thePixelEfficiency[20];     // Single pixel effciency
  double thePixelColEfficiency[20];  // Column effciency
  double thePixelChipEfficiency[20]; // ROC efficiency
  std::vector<double> theLadderEfficiency_BPix[20]; // Ladder efficiency
  std::vector<double> theModuleEfficiency_BPix[20]; // Module efficiency
  std::vector<double> thePUEfficiency[20]; // Instlumi dependent efficiency
  double theInnerEfficiency_FPix[20]; // Fpix inner module efficiency
  double theOuterEfficiency_FPix[20]; // Fpix outer module efficiency
  double theInstLumiScaleFactor;

  
  double getMatchingGeomFactor_(const DetId&, const std::map<unsigned int, double>&, const std::vector<uint32_t>&);
  std::vector<double> getMatchingPUFactors_(const DetId&, const std::map<unsigned int, std::vector<double> >&, const std::vector<uint32_t>&);
};

#endif
