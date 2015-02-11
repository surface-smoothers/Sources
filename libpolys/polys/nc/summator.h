#ifndef SUMMATOR_H
#define SUMMATOR_H
/****************************************
*  Computer Algebra System SINGULAR     *
****************************************/

// #include <polys/nc/summator.h> // for CPolynomialSummator class

#define HAVE_SUMMATOR 1

#ifdef HAVE_SUMMATOR

// struct snumber; typedef struct snumber *   number;

class  sBucket; typedef sBucket* sBucket_pt;
struct spolyrec; typedef struct spolyrec polyrec; typedef polyrec* poly;
struct ip_sring; typedef struct ip_sring* ring; typedef struct ip_sring const* const_ring;


class  kBucket; typedef kBucket* kBucket_pt;

// TODO: redesign into templates with no extra run-time cost!!!
// TODO: make several out of CPolynomialSummator with similar (?) usage
// pattern/interface!!!

// //////////////////////////////////////////////////////////////////////// //
/// CPolynomialSummator: unifies bucket and polynomial summation as the
/// later is brocken in buckets :(
class CPolynomialSummator
{
  private:
    const ring& m_basering;
    const bool m_bUsePolynomial;
    union
    {
      sBucket_pt m_bucket;
//      kBucket_pt m_kbucket;
      poly       m_poly;
    } m_temp;
  public:
    CPolynomialSummator(const ring& rBaseRing, bool bUsePolynomial = false);
//    CPolynomialSummator(ring rBaseRing, poly pInitialSum, int iLength = 0, bool bUsePolynomial = false);
    ~CPolynomialSummator();

    // adds and destroes the summand
    void AddAndDelete(poly pSummand, int iLength);
    void AddAndDelete(poly pSummand);

    inline void operator +=(poly pSummand){ AddAndDelete(pSummand); }

    // only adds and keeps the summand
    // please use AddAndDelete instead!
    void Add(poly pSummand, int iLength);
    void Add(poly pSummand);

    // get the final result and clear (set to zero) the summator
    poly AddUpAndClear();
    poly AddUpAndClear(int *piLength);

    inline operator poly() { return AddUpAndClear(); }

    /// Copy constructor
    CPolynomialSummator(const CPolynomialSummator&);
  private:

    /// no assignment operator yet
    CPolynomialSummator& operator= (const CPolynomialSummator&);
};

#endif // ifdef HAVE_SUMMATOR
#endif // ifndef  SUMMATOR_H

