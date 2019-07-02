#!/bin/tcsh
echo $home

source /afs/cern.ch/cms/LCG/LCG-2/UI/cms_ui_env.csh

#rfdir /castor/cern.ch/cms/store/data

setenv SCRAM_ARCH slc6_amd64_gcc700
cd /afs/cern.ch/user/d/dkotlins/public/CMSSW/CMSSW_10_2_0/src

#source /afs/cern.ch/cms/sw/cmsset_default.csh
source /afs/cern.ch/project/gd/apps/cms/cmsset_default.csh   # this works with gcc462

# must be run frm the release area
eval `scram runtime -csh`

#cd DPGAnalysis-SiPixelTools/HitAnalyzer/test
cd DPGAnalysis-SiPixelTools/HitAnalyzer/scripts
pwd

#  RAW
#cmsRun runRawToClus_cfg.py 
#cmsRun runRawToClus_325308.py 
cmsRun runRawToClus_323288.py 
#cmsRun runRawToTracks_cfg.py 
#cmsRun runHotPixels.py 
#cmsRun runRawDumper.py 
#cmsRun runRawDumperPilot.py 
#cmsRun runRawDumper_lumi.py 
# cmsRun runRawToDigi_cfg.py 
# cmsRun runFedErrorDumper.py

#cmsRun testPxdigi.py

#cmsRun PixClusterAna.py
#cmsRun PixClusterAna_277069.py
#cmsRun PixClusterTest.py
#cmsRun PixClusterAna_Lumi.py
#cmsRun testTracks.py

#ls 

 




