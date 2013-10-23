#pragma once

#include "Event.hpp"
#include "MathUtils.hpp"

namespace Gambit {


  class Analysis {
  public:

    /// Constructor
    Analysis() : _ntot(0), _xsec(-1), _xsecerr(-1) { }

    /// Virtual destructor (needed for correct deletion of inherited classes)
    virtual ~Analysis() { init(); }


    /// @name Standard event loop functions
    //@{

    /// Initialize counters etc.
    /// @todo Call this automatically on first call to analyze() -- requires a bit of indirection
    virtual void init() {  }

    /// Analyze the event (accessed by reference)
    virtual void analyze(const Event& e) { analyze(&e); }

    /// Analyze the event (accessed by pointer)
    /// @todo Call init() automatically on first call to analyze()? -- requires a bit of indirection: not worth it?
    /// @todo Needs to be called from Derived::analyze()
    virtual void analyze(const Event* e) {
      _ntot += 1; //< @todo Event weight support needed?
    }

    /// Finalize: scale by number of input events, etc.
    /// @todo Necessary?
    virtual void finalize() {  }

    //@}




    /// @name Cross-section and event number info    //@{

    /// Return the total number of events seen so far
    double num_events() const { return _ntot; }
    /// Return the cross-section (in pb)
    double xsec() const { return _xsec; }
    /// Return the cross-section error (in pb)
    double xsec_err() const { return _xsec; }
    /// Return the cross-section relative error
    double xsec_relerr() const { return xsec() > 0 ? xsec_err()/xsec() : -1; }
    /// Return the cross-section per event seen (in pb)
    double xsec_per_event() const { return (xsec() > 0) ? xsec()/num_events() : -1; }
    /// Set the cross-section and its error
    void set_xsec(double xs, double xserr) { _xsec = xs; _xsecerr = xserr; }

    //@}


    /// @name Analysis combination operations
    //@{

    /// An operator to do xsec-weighted combination of analysis runs
    /// @note We don't use operator += because it's awkward with pointer l/rvalues
    /// @todo Put some real implementation in the base class, e.g. checking ana names
    virtual void add(const Analysis& a) { } //= 0;

    /// Add a cross-section and error
    void add_xsec(double xs, double xserr);

    /// Combine the provided cross-section with the existing one of the same type, assuming uncorrelated errors
    /// @todo Assumes equal stats at the moment: that breaks immediately. Include some 1/(rel)error weighting?
    void improve_xsec(double xs, double xserr);

    //@}


    /// @name Likelihood functions
    //@{
    /// Return the log_e likelihood (at the end of the run)
    virtual double loglikelihood() = 0;
    /// Return the likelihood (at the end of the run, via logLikelihood)
    virtual double likelihood() { return std::exp(loglikelihood()); }
    //@}


  private:

    /// Number of events and cross-section internal variables
    /// @note C++11 default value syntax
    double _ntot, _xsec, _xsecerr;

  };


  /// @brief Create a new analysis based on a name string
  ///
  /// The caller is responsible for deleting the returned analysis object.
  Analysis* mkAnalysis(const std::string& name);


}