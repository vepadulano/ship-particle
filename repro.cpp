#include <TFile.h>
#include <TTree.h>

#include <vector>

#include "ShipParticle.h"

int main()
{
    TFile outfile("particles.root", "RECREATE");
    TTree tree("Particles", "");
    std::vector<ShipParticle> particles{};
    tree.Branch("branchparticles", &particles);
}
