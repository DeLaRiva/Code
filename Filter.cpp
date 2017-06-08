#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <oct.h>
#include <builtin-defun-decls.h>
#include <toplev.h>

#include <math.h> 
#include <TFile.h>
#include <TTree.h>
#include "TStyle.h"
#include "Riostream.h"
#include "TCanvas.h"
#include <TGraphErrors.h>
#include <TF1.h>
#include <TH1.h>
#include <TROOT.h> 
#include <TH1F.h>
#include <TLine.h>

using namespace std;

int main()
{

	const char *inFile="Filter_traces_array.root";
	const char *outputfile="raw_data.root";
	const char *outputfile_filter="Filter_result.root";

  	gStyle->SetPadGridX(kTRUE);
  	gStyle->SetPadGridY(kTRUE);

// get input file

	TFile *f = new TFile(inFile);												// get input file
	Char_t tmpstr[80];
	Double_t fraction;
	if(f->IsZombie())
	{   													// Check if TFile exists!
		cout<<"Input file " << inFile << " doesn't exist!" << endl;
		cout<<"Exit program" << endl;
		return 0;
	}
	cout << "Reading from file: " << inFile << endl;

	const char *inTree="tree/anaTree";
	TTree *anaTree=(TTree *) f->Get(inTree);
	if(anaTree==0)
	{  													// Check if TTree exists!
		cout << "Tree " << inTree << " doesn't exist!!!" << endl;
		cout <<"Exit program" << endl;
		return 0;
	}   

// Traces
	int TRACELEN = 500;

   	Float_t FADC_ev4_crystal_11[TRACELEN];
	anaTree->SetBranchAddress("tFADC_ev4_crystal_11", &FADC_ev4_crystal_11);
	for(int i = 0, N = anaTree->GetEntries(); i < N; ++i){anaTree->GetEntry(i);}

	Float_t FADC2_ev4_crystal_11[TRACELEN];
   	anaTree->SetBranchAddress("tFADC2_ev4_crystal_11", &FADC2_ev4_crystal_11);
	for(int i = 0, N = anaTree->GetEntries(); i < N; ++i){anaTree->GetEntry(i);}

   	Float_t FADC_ev4_crystal_12[TRACELEN];
   	anaTree->SetBranchAddress("tFADC_ev4_crystal_12", &FADC_ev4_crystal_12);
	for(int i = 0, N = anaTree->GetEntries(); i < N; ++i){anaTree->GetEntry(i);}

   	Float_t FADC2_ev4_crystal_12[TRACELEN];
   	anaTree->SetBranchAddress("tFADC2_ev4_crystal_12", &FADC2_ev4_crystal_12);
	for(int i = 0, N = anaTree->GetEntries(); i < N; ++i){anaTree->GetEntry(i);}

   	Float_t FADC_ev7_crystal_13[TRACELEN];
   	anaTree->SetBranchAddress("tFADC_ev7_crystal_13", &FADC_ev7_crystal_13);
	for(int i = 0, N = anaTree->GetEntries(); i < N; ++i){anaTree->GetEntry(i);}

   	Float_t FADC2_ev7_crystal_13[TRACELEN];
   	anaTree->SetBranchAddress("tFADC2_ev7_crystal_13", &FADC2_ev7_crystal_13);
	for(int i = 0, N = anaTree->GetEntries(); i < N; ++i){anaTree->GetEntry(i);}

   	Float_t FADC_ev10_crystal_12[TRACELEN];
   	anaTree->SetBranchAddress("tFADC_ev10_crystal_12", &FADC_ev10_crystal_12);
	for(int i = 0, N = anaTree->GetEntries(); i < N; ++i){anaTree->GetEntry(i);}

   	Float_t FADC2_ev10_crystal_12[TRACELEN];
   	anaTree->SetBranchAddress("tFADC2_ev10_crystal_12", &FADC2_ev10_crystal_12);
	for(int i = 0, N = anaTree->GetEntries(); i < N; ++i){anaTree->GetEntry(i);}

   	Float_t FADC_ev16_crystal_6[TRACELEN];
   	anaTree->SetBranchAddress("tFADC_ev16_crystal_6", &FADC_ev16_crystal_6);
	for(int i = 0, N = anaTree->GetEntries(); i < N; ++i){anaTree->GetEntry(i);}

   	Float_t FADC2_ev16_crystal_6[TRACELEN];
   	anaTree->SetBranchAddress("tFADC2_ev16_crystal_6", &FADC2_ev16_crystal_6);
	for(int i = 0, N = anaTree->GetEntries(); i < N; ++i){anaTree->GetEntry(i);}

   	Float_t FADC_ev18_crystal_12[TRACELEN];
   	anaTree->SetBranchAddress("tFADC_ev18_crystal_12", &FADC_ev18_crystal_12);
	for(int i = 0, N = anaTree->GetEntries(); i < N; ++i){anaTree->GetEntry(i);}

   	Float_t FADC2_ev18_crystal_12[TRACELEN];
   	anaTree->SetBranchAddress("tFADC2_ev18_crystal_12", &FADC2_ev18_crystal_12);
	for(int i = 0, N = anaTree->GetEntries(); i < N; ++i){anaTree->GetEntry(i);}

/*
	for(int n=0; n<TRACELEN; n++)
	{
		cout << "FADC["<<n<<"]: " << FADC2_ev4_crystal_11[n] << endl;
	}
*/

	int ncrystals = 25;
	int BINS = 50;
  	char name[100];

	TFile *Outputfile=new TFile(outputfile, "RECREATE");   							// Outputfile
	TCanvas* c1=new TCanvas("c1","Raw data",1400,1000);
	//gROOT->SetStyle("Plain");
	gStyle->SetOptStat("ouMe"); 
	c1->Divide(2,3);

//Event 4
  	TH1D *pFADC_ev4_crystal_11;
    	sprintf(name,"Event 4 : Crystal 11 : APD 1");					
    	pFADC_ev4_crystal_11=new TH1D(name,name,TRACELEN,0,TRACELEN); 
	//pFADC_ev4_crystal_11->Sumw2();	

  	TH1D *pFADC2_ev4_crystal_11;
    	sprintf(name,"Event 4 : Crystal 11 : APD 2");									
    	pFADC2_ev4_crystal_11=new TH1D(name,name,TRACELEN,0,TRACELEN); 

  	TH1D *pFADC_ev4_crystal_12;
    	sprintf(name,"Event 4 : Crystal 12 : APD 1");						
    	pFADC_ev4_crystal_12=new TH1D(name,name,TRACELEN,0,TRACELEN); 

  	TH1D *pFADC2_ev4_crystal_12;
    	sprintf(name,"Event 4 : Crystal 12 : APD 2");						
    	pFADC2_ev4_crystal_12=new TH1D(name,name,TRACELEN,0,TRACELEN); 

//Event 7
  	TH1D *pFADC_ev7_crystal_13;
    	sprintf(name,"Event 7 : Crystal 13 : APD 1");								
    	pFADC_ev7_crystal_13=new TH1D(name,name,TRACELEN,0,TRACELEN);

  	TH1D *pFADC2_ev7_crystal_13;
    	sprintf(name,"Event 7 : Crystal 13 : APD 2");									
    	pFADC2_ev7_crystal_13=new TH1D(name,name,TRACELEN,0,TRACELEN); 

// Get Entries
	for(int i=0; i<TRACELEN; i++)
	{
		pFADC_ev4_crystal_11->Fill(i, FADC_ev4_crystal_11[i]);
		pFADC2_ev4_crystal_11->Fill(i, FADC2_ev4_crystal_11[i]);
		pFADC_ev4_crystal_12->Fill(i, FADC_ev4_crystal_12[i]);
		pFADC2_ev4_crystal_12->Fill(i, FADC2_ev4_crystal_12[i]);
		pFADC_ev7_crystal_13->Fill(i, FADC_ev7_crystal_13[i]);
		pFADC2_ev7_crystal_13->Fill(i, FADC2_ev7_crystal_13[i]);
	}


	c1->cd(1);
	pFADC_ev4_crystal_11->Draw("HIST");

	c1->cd(2);
	pFADC2_ev4_crystal_11->Draw("HIST");

	c1->cd(3);
	pFADC_ev4_crystal_12->Draw("HIST");

	c1->cd(4);
	pFADC2_ev4_crystal_12->Draw("HIST");

	c1->cd(5);
	pFADC_ev7_crystal_13->Draw("HIST");

	c1->cd(6);
	pFADC2_ev7_crystal_13->Draw("HIST");


// Canvas2
	TCanvas* c2=new TCanvas("c2","Filter2",1400,1000);
	//gROOT->SetStyle("Plain");
	gStyle->SetOptStat("ouMe"); 
	c2->Divide(2,3);


//Event 10
  	TH1D *pFADC_ev10_crystal_12;
    	sprintf(name,"Event 10 : Crystal 12 : APD 1");								
    	pFADC_ev10_crystal_12=new TH1D(name,name,TRACELEN,0,TRACELEN); 

  	TH1D *pFADC2_ev10_crystal_12;
    	sprintf(name,"Event 10 : Crystal 12 : APD 2");									
    	pFADC2_ev10_crystal_12=new TH1D(name,name,TRACELEN,0,TRACELEN); 

//Event 16
  	TH1D *pFADC_ev16_crystal_6;
    	sprintf(name,"Event 16 : Crystal 6 : APD 1");								
    	pFADC_ev16_crystal_6=new TH1D(name,name,TRACELEN,0,TRACELEN); 

  	TH1D *pFADC2_ev16_crystal_6;
  	sprintf(name,"Event 16 : Crystal 6 : APD 2");									
  	pFADC2_ev16_crystal_6=new TH1D(name,name,TRACELEN,0,TRACELEN); 

//Event 18
  	TH1D *pFADC_ev18_crystal_12;
    	sprintf(name,"Event 18 : Crystal 12 : APD 1");								
    	pFADC_ev18_crystal_12=new TH1D(name,name,TRACELEN,0,TRACELEN); 

  	TH1D *pFADC2_ev18_crystal_12;
  	sprintf(name,"Event 18 : Crystal 12 : APD 2");									
  	pFADC2_ev18_crystal_12=new TH1D(name,name,TRACELEN,0,TRACELEN); 

	c2->cd(1);
	pFADC_ev10_crystal_12->Draw("HIST");

	c2->cd(2);
	pFADC2_ev10_crystal_12->Draw("HIST");

	c2->cd(3);
	pFADC_ev16_crystal_6->Draw("HIST");

	c2->cd(4);
	pFADC2_ev16_crystal_6->Draw("HIST");

	c2->cd(5);
	pFADC_ev18_crystal_12->Draw("HIST");

	c2->cd(6);
	pFADC2_ev18_crystal_12->Draw("HIST");

// Get Entries
	for(int i=0; i<TRACELEN; i++)
	{
		pFADC_ev10_crystal_12->Fill(i, FADC_ev10_crystal_12[i]);
		pFADC2_ev10_crystal_12->Fill(i, FADC2_ev10_crystal_12[i]);
		pFADC_ev16_crystal_6->Fill(i, FADC_ev16_crystal_6[i]);
		pFADC2_ev16_crystal_6->Fill(i, FADC2_ev16_crystal_6[i]);
		pFADC_ev18_crystal_12->Fill(i, FADC_ev18_crystal_12[i]);
		pFADC2_ev18_crystal_12->Fill(i, FADC2_ev18_crystal_12[i]);
	}

// Close file
	c1->Update();
	c1->Write();
	c2->Update();
	c2->Write();

	Outputfile->Write(); 										// Saving Histograms
	cout << "Histograms for raw data saved in File: " << outputfile << endl;


// Filtering data

	TFile *Outputfile_filtered=new TFile(outputfile_filter, "RECREATE");   							// Outputfile
	TCanvas* c3=new TCanvas("c3","Filtered data",1400,1000);
	//gROOT->SetStyle("Plain");
	gStyle->SetOptStat("ouMe"); 
	c3->Divide(2,3);

//Event 4
  	TH1D *pFADC_ev4_crystal_11_filtered;
    	sprintf(name,"Event 4 : Crystal 11 : APD 1");					
    	pFADC_ev4_crystal_11_filtered=new TH1D(name,name,TRACELEN,0,TRACELEN); 	

  	TH1D *pFADC2_ev4_crystal_11_filtered;
    	sprintf(name,"Event 4 : Crystal 11 : APD 2");									
    	pFADC2_ev4_crystal_11_filtered=new TH1D(name,name,TRACELEN,0,TRACELEN); 

  	TH1D *pFADC_ev4_crystal_12_filtered;
    	sprintf(name,"Event 4 : Crystal 12 : APD 1");						
    	pFADC_ev4_crystal_12_filtered=new TH1D(name,name,TRACELEN,0,TRACELEN); 

  	TH1D *pFADC2_ev4_crystal_12_filtered;
    	sprintf(name,"Event 4 : Crystal 12 : APD 2");						
    	pFADC2_ev4_crystal_12_filtered=new TH1D(name,name,TRACELEN,0,TRACELEN); 

//Event 7
  	TH1D *pFADC_ev7_crystal_13_filtered;
    	sprintf(name,"Event 7 : Crystal 13 : APD 1");								
    	pFADC_ev7_crystal_13_filtered=new TH1D(name,name,TRACELEN,0,TRACELEN);

  	TH1D *pFADC2_ev7_crystal_13_filtered;
    	sprintf(name,"Event 7 : Crystal 13 : APD 2");									
    	pFADC2_ev7_crystal_13_filtered=new TH1D(name,name,TRACELEN,0,TRACELEN); 



// Filter
	for(int i=0; i<TRACELEN; i++)
	{
//		Matrix a_matrix = Matrix (2,2);
//		a_matrix(0,0) = FADC2_ev4_crystal_11[0];
/*
		for (octave_idx_type i = 0; i < n; i++)
		for (octave_idx_type j = 0; j < n; j++)
		a_matrix(i,j) = (i + 1) * 10 + (j + 1);
*/
		// first canvas
		//use octave:
	  	//FADC_ev4_crystal_11[TRACELEN] = fft(FADC_ev4_crystal_11[TRACELEN]);
		FADC2_ev4_crystal_11[TRACELEN];

	   	FADC_ev4_crystal_12[TRACELEN];
	   	FADC2_ev4_crystal_12[TRACELEN];

	   	FADC_ev7_crystal_13[TRACELEN];
	   	FADC2_ev7_crystal_13[TRACELEN];

		// second canvas
	   	FADC_ev10_crystal_12[TRACELEN];
	   	FADC2_ev10_crystal_12[TRACELEN];
	  
	 	FADC_ev16_crystal_6[TRACELEN];
	   	FADC2_ev16_crystal_6[TRACELEN];
	 
	   	FADC_ev18_crystal_12[TRACELEN];
	    	FADC2_ev18_crystal_12[TRACELEN];

//		cout << "Matrix: " << a_matrix << endl;

	}



// Get Entries
	for(int i=0; i<TRACELEN; i++)
	{
		pFADC_ev4_crystal_11_filtered->Fill(i, FADC_ev4_crystal_11[i]);
		pFADC2_ev4_crystal_11_filtered->Fill(i, FADC2_ev4_crystal_11[i]);
		pFADC_ev4_crystal_12_filtered->Fill(i, FADC_ev4_crystal_12[i]);
		pFADC2_ev4_crystal_12_filtered->Fill(i, FADC2_ev4_crystal_12[i]);
		pFADC_ev7_crystal_13_filtered->Fill(i, FADC_ev7_crystal_13[i]);
		pFADC2_ev7_crystal_13_filtered->Fill(i, FADC2_ev7_crystal_13[i]);
	}

	c3->cd(1);
	pFADC_ev4_crystal_11_filtered->Draw("hist");

	c3->cd(2);
	pFADC2_ev4_crystal_11_filtered->Draw("hist");

	c3->cd(3);
	pFADC_ev4_crystal_12_filtered->Draw("hist");

	c3->cd(4);
	pFADC2_ev4_crystal_12_filtered->Draw("hist");

	c3->cd(5);
	pFADC_ev7_crystal_13_filtered->Draw("hist");

	c3->cd(6);
	pFADC2_ev7_crystal_13_filtered->Draw("hist");


// Canvas2
	TCanvas* c4=new TCanvas("c4","Filtered data 2",1400,1000);
	//gROOT->SetStyle("Plain");
	gStyle->SetOptStat("ouMe"); 
	c4->Divide(2,3);

//Event 10
  	TH1D *pFADC_ev10_crystal_12_filtered;
    	sprintf(name,"Event 10 : Crystal 12 : APD 1");								
    	pFADC_ev10_crystal_12_filtered=new TH1D(name,name,TRACELEN,0,TRACELEN); 

  	TH1D *pFADC2_ev10_crystal_12_filtered;
    	sprintf(name,"Event 10 : Crystal 12 : APD 2");									
    	pFADC2_ev10_crystal_12_filtered=new TH1D(name,name,TRACELEN,0,TRACELEN); 

//Event 16
  	TH1D *pFADC_ev16_crystal_6_filtered;
    	sprintf(name,"Event 16 : Crystal 6 : APD 1");								
    	pFADC_ev16_crystal_6_filtered=new TH1D(name,name,TRACELEN,0,TRACELEN); 

  	TH1D *pFADC2_ev16_crystal_6_filtered;
  	sprintf(name,"Event 16 : Crystal 6 : APD 2");									
  	pFADC2_ev16_crystal_6_filtered=new TH1D(name,name,TRACELEN,0,TRACELEN); 

//Event 18
  	TH1D *pFADC_ev18_crystal_12_filtered;
    	sprintf(name,"Event 18 : Crystal 12 : APD 1");								
    	pFADC_ev18_crystal_12_filtered=new TH1D(name,name,TRACELEN,0,TRACELEN); 

  	TH1D *pFADC2_ev18_crystal_12_filtered;
  	sprintf(name,"Event 18 : Crystal 12 : APD 2");									
  	pFADC2_ev18_crystal_12_filtered=new TH1D(name,name,TRACELEN,0,TRACELEN); 

	c4->cd(1);
	pFADC_ev10_crystal_12_filtered->Draw("hist");

	c4->cd(2);
	pFADC2_ev10_crystal_12_filtered->Draw("hist");

	c4->cd(3);
	pFADC_ev16_crystal_6_filtered->Draw("hist");

	c4->cd(4);
	pFADC2_ev16_crystal_6_filtered->Draw("hist");

	c4->cd(5);
	pFADC_ev18_crystal_12_filtered->Draw("hist");

	c4->cd(6);
	pFADC2_ev18_crystal_12_filtered->Draw("hist");

// Get Entries
	for(int i=0; i<TRACELEN; i++)
	{
		pFADC_ev10_crystal_12_filtered->Fill(i, FADC_ev10_crystal_12[i]);
		pFADC2_ev10_crystal_12_filtered->Fill(i, FADC2_ev10_crystal_12[i]);
		pFADC_ev16_crystal_6_filtered->Fill(i, FADC_ev16_crystal_6[i]);
		pFADC2_ev16_crystal_6_filtered->Fill(i, FADC2_ev16_crystal_6[i]);
		pFADC_ev18_crystal_12_filtered->Fill(i, FADC_ev18_crystal_12[i]);
		pFADC2_ev18_crystal_12_filtered->Fill(i, FADC2_ev18_crystal_12[i]);
	}


// Close file
	c3->Update();
	c3->Write();
	c4->Update();
	c4->Write();

	Outputfile_filtered->Write(); 										// Saving Histograms
	cout << "Histograms for filtered data saved in File: " << outputfile_filter << endl;
//	Outputfile->Close(); 				

	f->Close();	
	return 1;
}






