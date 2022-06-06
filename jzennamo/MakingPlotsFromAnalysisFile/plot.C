void plot(){

  gStyle->SetOptStat(0);
  TFile* def_f = new TFile("../AnalyzingNtuples/outfile.root");
  TTree* def_t = (TTree*)def_f->Get("FastTree");
  
  TH2D* def = new TH2D("def",";E_{dep} [MeV];FWHM;",25,0,10,100,0,5000);
  
  def_t->Project("def","correction*wireQ:Edep","");

  def->Draw("colz");

}
