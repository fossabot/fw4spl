/* ***** BEGIN LICENSE BLOCK *****
 * FW4SPL - Copyright (C) IRCAD, 2009-2015.
 * Distributed under the terms of the GNU Lesser General Public License (LGPL) as
 * published by the Free Software Foundation.
 * ****** END LICENSE BLOCK ****** */

#include "fwData/registry/macros.hpp"
#include "fwData/Exception.hpp"
#include "fwData/Spline.hpp"

fwDataRegisterMacro( ::fwData::Spline );

namespace fwData
{

//------------------------------------------------------------------------------

Spline::Spline(::fwData::Object::Key key)
{
    SLM_TRACE_FUNC();
}

//------------------------------------------------------------------------------

Spline::~Spline()
{
    SLM_TRACE_FUNC();
    m_points.clear();
}

//------------------------------------------------------------------------------

Spline::Points &Spline::points()
{
    return m_points;
}

//------------------------------------------------------------------------------

void Spline::cachedDeepCopy(const Object::csptr &source, DeepCopyCacheType &cache)
{
    Spline::csptr other = Spline::dynamicConstCast(source);
    FW_RAISE_EXCEPTION_IF( ::fwData::Exception(
                               "Unable to copy" + (source ? source->getClassname() : std::string("<NULL>"))
                               + " to " + this->getClassname()), !bool(other) );
    this->fieldDeepCopy( source, cache );

    SLM_FATAL("Not implemented." );
}

//------------------------------------------------------------------------------

} // namespace fwData
