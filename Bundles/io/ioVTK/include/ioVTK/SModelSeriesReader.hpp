/* ***** BEGIN LICENSE BLOCK *****
 * FW4SPL - Copyright (C) IRCAD, 2009-2018.
 * Distributed under the terms of the GNU Lesser General Public License (LGPL) as
 * published by the Free Software Foundation.
 * ****** END LICENSE BLOCK ****** */

#pragma once

#include "ioVTK/config.hpp"

#include <fwData/Mesh.hpp>

#include <fwIO/IReader.hpp>

#include <boost/filesystem/path.hpp>

#include <string>

namespace fwJobs
{
class IJob;
}

namespace ioVTK
{

/**
 * @brief   VTK Model series reader.
 *
 * Service reading a model series as .vtk files using the fwVtkIO lib.
 */
class IOVTK_CLASS_API SModelSeriesReader : public ::fwIO::IReader
{

public:
    fwCoreServiceClassDefinitionsMacro( (SModelSeriesReader)( ::fwIO::IReader) );

    typedef ::fwCom::Signal< void ( SPTR(::fwJobs::IJob) ) > JobCreatedSignalType;

    /**
     * @brief Constructor. Do nothing.
     */
    IOVTK_API SModelSeriesReader() noexcept;

    ~SModelSeriesReader() noexcept
    {
    }

    /**
     * @brief Configure the mesh path.
     *
     * This method is used to find the file path  using a file selector.
     */
    IOVTK_API virtual void configureWithIHM() override;

protected:

    IOVTK_API virtual ::fwIO::IOPathType getIOPathType() const override;

    /**
     * @brief Starting method.
     *
     * This method is used to initialize the service.
     */
    IOVTK_API virtual void starting() override;

    /**
     * @brief Stopping method.
     *
     * The stopping method is empty for this service.
     */
    IOVTK_API virtual void stopping() override;

    /**
     * @brief Configuring method.
     *
     * The configuring method only calls the configuring method from the base class
     */
    IOVTK_API virtual void configuring() override;

    /**
     * @brief Updating method.
     *
     * This method is used to update the service.
     * The mesh is read.
     */
    IOVTK_API void updating() override;

    /**
     * @brief Info method.
     *
     * This method is used to give
     * informations about the service.
     */
    IOVTK_API void info(std::ostream& _sstream ) override;

private:

    IOVTK_API void loadMesh( const ::boost::filesystem::path file, ::fwData::Mesh::sptr mesh );

    SPTR(JobCreatedSignalType) m_sigJobCreated;

};

} // namespace ioVTK
