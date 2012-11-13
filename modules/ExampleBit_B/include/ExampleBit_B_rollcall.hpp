//  GAMBIT: Global and Modular BSM Inference Tool
//  *********************************************
//
//  Rollcall header for module ExampleBit_B
//
//  Compile-time registration of available obser-
//  vables and likelihoods, as well as their
//  dependencies.
//
//  Add to this if you want to add a observable
//  or likelihood to this module.
//
//  *********************************************
//
//  Authors
//  =======
//
//  (add name and date if you modify)
//
//  Pat Scott
//  Nov 10 2012
//
//  *********************************************


#include"observable.hpp"

// CREATE_OBS_OR_LIKE(module, like_or_obs_name, LaTeX_label, return_type)
// SET_DEPENDENCY(module, like_or_obs_name, dependency_name, dependency_type)

// Observable: cross-section for some hypothetical process 
CREATE_OBS_OR_LIKE(ExampleBit_B, xsection, $\sigma_{\rm gambit}$, double)

// Observable: number of events in some hypothetical process after cuts
CREATE_OBS_OR_LIKE(ExampleBit_B, nevents_postcuts, $\N_{\rm events,\,post-cut}$ double)
// Dependency: post-cut number of events requires pre-cut number of events
SET_DEPENDENCY(ExampleBit_B, nevents_postcuts, nevents, double)

// Observable: name of the author of ExampleBitB's dog
CREATE_OBS_OR_LIKE(ExampleBit_B, authors_dogs_name, Dog, std::string)
// Dog is independent.
