#!/bin/bash

DO_PLOTRAA=${1:-0}
DO_PLOTV2=${2:-0}
DO_PLOTDJET=${3:-0}

##

LUMIPbPbTGafter=10 # nb-1
LUMIPbPbMBafter=0.2217 # nb-1
LUMIPPafter=650 # pb-1

##

# nb-1
LUMIPbPbTG_D0_before=0.531 # GJ + TO (no prescale)
LUMIPbPbMB_D0_before=0.0433 # GJ + TO (MinBias)
LUMIPbPbTG_Bp_before=0.351 # GJ (dimuon)
LUMIPbPbTG_Charged_before=0.404  # GJ (no prescale)
LUMIPbPbMB_Charged_before=0.0219 # GJ (MinBias)
LUMIPbPbMB_D0V2_before=0.1115 # including 151MB centrality trigger events ((151/148.297)*0.0219*5)

LUMIPPbefore=27.4 # pb-1
#

FOLDERS=("plots")
for i in ${FOLDERS[@]}
do
    if [ ! -d $i ]; then
        mkdir $i
    fi
done

#
g++ plotRAA.C $(root-config --cflags --libs) -g -o plotRAA.exe
g++ plotV2.C $(root-config --cflags --libs) -g -o plotV2.exe
g++ plotDjet.C $(root-config --cflags --libs) -g -o plotDjet.exe

#
[[ $DO_PLOTRAA -eq 1 ]] && { ./plotRAA.exe ${LUMIPbPbTG_D0_before} ${LUMIPbPbMB_D0_before} ${LUMIPbPbTG_Bp_before} ${LUMIPbPbTG_Charged_before} ${LUMIPbPbMB_Charged_before} ${LUMIPbPbTGafter} ${LUMIPbPbMBafter} ; }
[[ $DO_PLOTV2 -eq 1 ]] && { ./plotV2.exe ${LUMIPbPbMB_D0V2_before} ${LUMIPbPbMB_Charged_before} ${LUMIPbPbMBafter} ; }
[[ $DO_PLOTDJET -eq 1 ]] && { ./plotDjet.exe ${LUMIPPbefore} ${LUMIPbPbTG_Charged_before} ${LUMIPPafter} ${LUMIPbPbTGafter} ; }

rm plotDjet.exe
rm plotV2.exe
rm plotRAA.exe
