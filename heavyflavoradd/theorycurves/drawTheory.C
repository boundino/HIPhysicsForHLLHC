#include "drawTheoryRAA.h"
#include "drawTheoryV2.h"

void drawTheory()
{
  // RAA
  drawTheoryRAA::drawcanvas();
  drawTheoryRAA::setupNdrawTheory010();
  drawTheoryRAA::drawlegends();
  drawTheoryRAA::canvasRAA->SaveAs("plots/cRAA_theorycurves.pdf");

  // V2
  drawTheoryV2::drawcanvas();
  drawTheoryV2::setupNdrawTheory3050();
  drawTheoryV2::drawlegends();
  drawTheoryV2::canvasV2->SaveAs("plots/cV2_theorycurves.pdf");
}

int main() 
{ 
  drawTheory();
  return 0;
}
