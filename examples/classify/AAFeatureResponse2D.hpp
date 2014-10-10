#ifndef _AAFEATRERESPONSE2D_HPP_
#define _AAFEATRERESPONSE2D_HPP_

#include "Abstract/AbstractFeatureResponse.hpp"
#include "PointSet2D.hpp"
#include "Randomizer.hpp"

// 2D axis-aligned feature response
class AAFeatureResponse2D : public Kaadugal::AbstractFeatureResponse
{
private:
    std::uniform_int_distribution<int> m_UniDist; // Both inclusive

    int SelectFeature(void)
    {
        return m_UniDist(Kaadugal::Randomizer::Get().GetRNG());
    };
    
public:
    AAFeatureResponse2D(void)
	: m_UniDist(0, 1) /* Both inclusive */
    {

    };

    virtual Kaadugal::VPFloat GetResponse(std::shared_ptr<Kaadugal::AbstractDataPoint> DataPoint) override
    {
	std::shared_ptr<Point2D> PointIn2D = std::dynamic_pointer_cast<Point2D>(DataPoint);

	return ( SelectFeature()==0?PointIn2D->m_x:PointIn2D->m_y );
    };

};

#endif // _AAFEATRERESPONSE2D_HPP_