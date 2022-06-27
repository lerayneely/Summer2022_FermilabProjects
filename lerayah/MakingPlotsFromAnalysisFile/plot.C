void plot(){ //Name of program

  gStyle->SetOptStat(0); // shuts off annyoing stats box
  TFile* def_f = new TFile("../AnalyzingNtuples/outfile.root"); //loads the file we want
  TTree* def_t = (TTree*)def_f->Get("FastTree"); //loads the TTree we just created
  
  //We'll create a plot now, either a 1D (TH1D) or a 2D (TH2D).
  // the numbers are the end are:
  // 1. the number of bins (25)
  // 2. the lower bound of the x-axis (0 MeV)
  // 3. the upper bound of the x-axis (10 MeV)
  // this is then repeated for the y-axis
  
  //Below are TTree developments for Undoped E-
  /* TH2D* def = new TH2D("def",";E_{dep} [MeV];FWHM;",25,0,10,100,0,5000); 

  TH1D* eng = new TH1D("eng","Undoped Low Energies;E_{dep} [MeV]; Count", 25, 0, 10);

  TH2D*eng_vs_hitq = new TH2D("eng_vs_hitq","True Energy vs HitQ; True Energy [MeV]; HitQ [MeV];",25,0,10,100,0,5000); 
  
  TH2D*eng_vs_wireq = new TH2D("eng_vs_wireq","True Energy vs Sum of Wire Charge; True Energy [MeV]; WireQ [FWHM];",25,0,10,100,0,5000); 
  
  TH1D* eng_vs_nhits = new TH1D("eng_vs_nhits","Undoped Low Energies Associated with # of Reconstructed Hits; E_{dep} [MeV]; Reconstructed Hits", 25, 0, 10);
  */


  TH2D* def = new TH2D("def","Doped Low Energies;E_{dep} [MeV];FWHM;",150,0,10,100,0,5000); 

  TH1D* eng = new TH1D("eng_doped","Doped Low Energies;E_{dep} [MeV]; Count", 150, 0, 10);

  TH2D*eng_vs_hitq = new TH2D("eng_vs_hitq","Doped True Energy vs HitQ; True Energy [MeV]; HitQ [MeV];",150,0,10,100,0,5000); 
  
  TH2D*eng_vs_wireq = new TH2D("eng_vs_wireq","Doped True Energy vs Sum of Wire Charge; True Energy [MeV]; WireQ [FWHM];",150,0,10,100,0,5000); 
  
  //TH1D* eng_vs_nhits = new TH1D("eng_vs_nhits","Doped Low Energies Associated with # of Reconstructed Hits; E_{dep} [MeV]; Reconstructed Hits", 150, 0, 100);

  TH2D* wireq = new TH2D("wireq","Reconstructed Wire Q vs True Wire Q Sum Charges; FWHM; FWHM", 150, 0, 5000, 0, 5000);
  
  // we then fill that histogram ("def") with the variables we are interested in 
  // using "<y-axis variable>:<x-axis variable>" 
  // you can also add any cuts you'd like to apply in the currently empty quotes.
  def_t->Project("def","correction*wireQ:Edep",""); // energy deposited into detector 
 
  def_t->Project("eng_doped", "Edep");

  def_t->Project("eng_vs_hitq","hitQ:trueE");

  def_t->Project("eng_vs_wireq","correction*wireQ:trueE"); //energy where e- were simulated at 

  //def_t->Project("eng_vs_nhits", "Nhits:Edep");

  def_t->Project("wireq", "reco_tot_wire_Q:correction*wireQ");



    
  // finally we draw it! 
  // "colz" means color brightness on the z-axis to designate density of events

  TCanvas *trial=new TCanvas("trial," "trial");
  def->Draw("colz");
  trial-> Print("/sbnd/app/users/lerayah/Summer2022_FermilabProjects/jzennamo/Plots_lerayah/EdepvsWireQ_doped2500.pdf");
  
  TCanvas *c2=new TCanvas("c2", "c2");
  eng->Draw();
  c2-> Print("/sbnd/app/users/lerayah/Summer2022_FermilabProjects/jzennamo/Plots_lerayah/EdepvsCount_doped2500.pdf");

  TCanvas *c3=new TCanvas("c3", "c3");
  eng_vs_hitq->Draw("colz");
  c3-> Print("/sbnd/app/users/lerayah/Summer2022_FermilabProjects/jzennamo/Plots_lerayah/Eng_HitQ_doped2500.pdf");

  TCanvas *c4=new TCanvas("c4", "c4");
  eng_vs_wireq->Draw("colz");
  c4-> Print("/sbnd/app/users/lerayah/Summer2022_FermilabProjects/jzennamo/Plots_lerayah/Eng_WireQ_doped2500.pdf");

  //TCanvas *c5=new TCanvas("c5", "c5");
  //eng_vs_nhits->Draw();
  //c5-> Print(".../Plots_lerayah/Eng_NHit_doped2500.pdf");

  TCanvas *c6=new TCanvas("c6", "c6");
  wireq->Draw("colz");
  c6-> Print("/sbnd/app/users/lerayah/Summer2022_FermilabProjects/jzennamo/Plots_lerayah/WireQComparison_doped2500.pdf");

}
