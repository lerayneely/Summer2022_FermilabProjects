The first step is to source the setup file in this directory:

> source setup.sh

You should now have access to the Fermilab software stack, including ROOT (https://root.cern.ch/doc/v622/).

From here we can start analyzing some files. 

The first step is to analyze the complex files that come out of the experimental simulation. These files contain _way_ more information than we'll need for this summer so we'll try to condense them down to the relevant information. We do this by starting here:

* AnalyzingLArSoftFiles

This directory reads in our complex simulation (LArSoft) files and aims to produce a much sparser output file that aims to "flatten" these files. 

To run this all that is needed is:

> root AnalyzerStandard.C

This will create a file called "output.root" and it should contain a "TTree" which is a multidimensional representation of the data created inside "AnalyzerStandard.C" 

One thing that can be adjusted is this line:

>> 

This limits the number...