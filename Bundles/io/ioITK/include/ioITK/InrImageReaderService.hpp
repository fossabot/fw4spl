/* ***** BEGIN LICENSE BLOCK *****
 * FW4SPL - Copyright (C) IRCAD, 2009-2018.
 * Distributed under the terms of the GNU Lesser General Public License (LGPL) as
 * published by the Free Software Foundation.
 * ****** END LICENSE BLOCK ****** */

#pragma once

#include "ioITK/config.hpp"

#include <fwCore/macros.hpp>

#include <fwIO/IReader.hpp>

#include <boost/filesystem/path.hpp>

namespace fwData
{
class Image;
}

namespace ioITK
{

class IOITK_CLASS_API InrImageReaderService : public ::fwIO::IReader
{

public:
    fwCoreServiceClassDefinitionsMacro( (InrImageReaderService)( ::fwIO::IReader) );

    IOITK_API InrImageReaderService() noexcept;

    IOITK_API virtual ~InrImageReaderService() noexcept;

protected:

    /// Override
    virtual void starting() override
    {
    }

    /// Override
    virtual void stopping() override
    {
    }

    /// Override
    IOITK_API virtual void configuring() override;

    /// Override
    IOITK_API virtual void updating() override;

    /// Override
    IOITK_API void info(std::ostream& _sstream ) override;

    /// Override
    IOITK_API virtual void configureWithIHM() override;

    /// Return managed file type, here FILE
    IOITK_API ::fwIO::IOPathType getIOPathType() const override;

private:

    void notificationOfDBUpdate();

    bool createImage( const ::boost::filesystem::path& inrFileDir, const SPTR(::fwData::Image)& _pImg );
};

} // namespace ioITK
