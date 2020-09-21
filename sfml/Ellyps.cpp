#include "Ellyps.h"

Ellyps::Ellyps(unsigned int n_width, unsigned int n_height, int Resolution) :
    shape(n_width, n_height)
{
    delete[] m_points;
    m_pointCount = Resolution;
    m_points = new sf::Vector2f[m_pointCount];
    for (int parametr = 0; parametr < Resolution; parametr += 1)
        m_points[parametr]={ (((m_Width-100) / 2)) * float(cos(2 * M_PI / Resolution * parametr)) + (((m_Width) / 2)),
                              (((m_Height-100) / 2)) * float(sin(2 * M_PI / Resolution * parametr)) + (((m_Height) / 2))
            };
    m_Shape.setPointCount(Resolution);
    refresh(m_points, REFRESH_CONVEX_ONLY);
    Ellyps::setLocalOrigin({ (float(m_Width) / 2),(float(m_Height) / 2) });
}
Ellyps::~Ellyps()
{
 }


