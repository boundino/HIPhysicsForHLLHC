#include <vector>

const int nPtBins = 2;
double ptBins[nPtBins+1] = {4, 20, 999};
const int nDrBins = 4;
double drBins[nDrBins+1] = {0, 0.05, 0.10, 0.30, 0.50};

std::vector<double> vax = {0.025, 0.075, 0.20, 0.40};
std::vector<double> vaex = {0.025, 0.025, 0.10, 0.10};
std::vector<std::vector<double>> vayPP = {{4.58721, 6.2627, 2.28752, 0.866374},
                             {15.7158, 3.19302, 0.2728, 0.054233}};
std::vector<std::vector<double>> vaeyPPstat = {{0.611494, 0.742641, 0.22082, 0.131943},
                                  {0.460443, 0.238237, 0.037262, 0.0136073}};
std::vector<std::vector<double>> vaeyPPsyst = {{0.724924, 1.02682, 0.251117, 0.112449},
                                  {0.952978, 0.526325, 0.0870874, 0.0193938}};
std::vector<std::vector<double>> vayPbPb = {{3.11764, 5.07733, 2.95126, 1.63724},
                               {15.1965, 3.37839, 0.356284, 0.043083}};
std::vector<std::vector<double>> vaeyPbPbstat = {{0.802339, 1.14027, 0.536871, 0.560304},
                                    {0.807137, 0.329854, 0.0753752, 0.0321213}};
std::vector<std::vector<double>> vaeyPbPbsyst = {{0.822814, 1.64012, 0.309249, 0.605575},
                                    {1.40426, 0.65389, 0.120126, 0.0226011}};
std::vector<std::vector<double>> vayRatio = {{0.679637, 0.810725, 1.29016, 1.88976},
                                {0.966957, 1.05805, 1.30603, 0.794406}};
std::vector<std::vector<double>> vaeyRatiostat = {{0.196979, 0.205896, 0.265693, 0.707869},
                                     {0.0586539, 0.130015, 0.328886, 0.624921}};
std::vector<std::vector<double>> vaeyRatiosyst = {{0.191738, 0.294587, 0.18236, 0.795579},
                                     {0.0471038, 0.111639, 0.238967, 0.371942}};
