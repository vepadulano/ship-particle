#ifndef SHIPDATA_SHIPPARTICLE_H_
#define SHIPDATA_SHIPPARTICLE_H_

#include "Rtypes.h"         // for Double_t, Int_t, Double32_t, etc
#include "TLorentzVector.h" // for TLorentzVector
#include "TMath.h"          // for Sqrt
#include "TMatrixDSym.h"    //
#include "TParticle.h"      // for TParticle
#include "TVector3.h"       // for TVector3

#include <vector>

class TParticle;

class ShipParticle : public TParticle
{

public:
  /**  Default constructor  **/
  ShipParticle();
  ShipParticle(Int_t pdg,
               Int_t status,
               Int_t mother1,
               Int_t mother2,
               Int_t daughter1,
               Int_t daughter2,
               Double_t px,
               Double_t py,
               Double_t pz,
               Double_t etot,
               Double_t vx,
               Double_t vy,
               Double_t vz,
               Double_t time);
  ShipParticle(Int_t pdg,
               Int_t status,
               Int_t mother1,
               Int_t mother2,
               Int_t daughter1,
               Int_t daughter2,
               const TLorentzVector &p,
               const TLorentzVector &v);
  /**  Destructor  **/
  virtual ~ShipParticle();

  /**  Output to screen  **/
  void Print(Int_t iTrack = 0) const;

  /**  Accessors  **/
  void GetMomentum(TLorentzVector &momentum);
  Double_t GetMass();
  void GetVertex(TVector3 &vertex);
  TMatrixDSym *GetCovP();
  TMatrixDSym *GetCovV();
  void SetCovP(Double_t *x);
  void SetCovV(Double_t *x);
  Double_t GetDoca() const { return doca; }
  void SetDoca(Double_t x) { doca = x; }

private:
  TMatrixDSym fCovP;
  TMatrixDSym fCovV;
  Double_t doca;
  ClassDefOverride(ShipParticle, 2);
};

// ==========   Inline functions   ========================================

inline TMatrixDSym *ShipParticle::GetCovP()
{
  return &fCovP;
}

inline TMatrixDSym *ShipParticle::GetCovV()
{
  return &fCovV;
}

#endif // SHIPDATA_SHIPPARTICLE_H_
