/* ***** BEGIN LICENSE BLOCK *****
 * FW4SPL - Copyright (C) IRCAD, 2009-2016.
 * Distributed under the terms of the GNU Lesser General Public License (LGPL) as
 * published by the Free Software Foundation.
 * ****** END LICENSE BLOCK ****** */

#include "fwGdcmIO/helper/DicomDataWriter.hxx"
#include "fwGdcmIO/writer/ie/Equipment.hpp"

#include <fwMedData/Equipment.hpp>
#include <fwRuntime/profile/Profile.hpp>

namespace fwGdcmIO
{
namespace writer
{
namespace ie
{

//------------------------------------------------------------------------------

Equipment::Equipment(const SPTR(::gdcm::Writer)& writer,
                     const SPTR(::fwGdcmIO::container::DicomInstance)& instance,
                     const ::fwMedData::Equipment::sptr& equipment,
                     const ::fwLog::Logger::sptr& logger,
                     ProgressCallback progress,
                     CancelRequestedCallback cancel) :
    ::fwGdcmIO::writer::ie::InformationEntity< ::fwMedData::Equipment >(writer, instance, equipment,
                                                                        logger, progress, cancel)
{
}

//------------------------------------------------------------------------------

Equipment::~Equipment()
{
}

//------------------------------------------------------------------------------

void Equipment::writeGeneralEquipmentModule()
{
    // Retrieve dataset
    ::gdcm::DataSet& dataset = m_writer->GetFile().GetDataSet();

    // Manufacturer - Type 2 (Type 1 for EnhancedGeneralEquipmentModule)
    ::fwGdcmIO::helper::DicomDataWriter::setTagValue< 0x0008, 0x0070 >("FW4SPL", dataset);

    // Institution Name - Type 3
    const std::string& institutName = m_object->getInstitutionName();
    ::fwGdcmIO::helper::DicomDataWriter::setTagValue< 0x0008, 0x0080 >(institutName, dataset);

    // Software Versions - Type 3 (Type 1 for EnhancedGeneralEquipmentModule)
    const auto profile = ::fwRuntime::profile::getCurrentProfile();
    const std::string softwareVersion = profile ? profile->getName() + " " + profile->getVersion() : "Unknown";

    // We do not use the DicomDataWriter helper as VM might be more than one
    ::gdcm::Attribute< 0x0018, 0x1020 > attribute;
    attribute.SetNumberOfValues(1);
    attribute.SetValue(softwareVersion);
    dataset.Insert(attribute.GetAsDataElement());
}

//------------------------------------------------------------------------------

void Equipment::writeEnhancedGeneralEquipmentModule()
{
    // Retrieve dataset
    ::gdcm::DataSet& dataset = m_writer->GetFile().GetDataSet();

    // Manufacturer's Model Name - Type 1
    ::fwGdcmIO::helper::DicomDataWriter::setTagValue< 0x0008, 0x1090 >("FW4SPL_FWGDCMIO", dataset);

    // Device Serial Number - Type 1
    std::string deviceSerialNumber = std::string(FWGDCMIO_VER);
    ::fwGdcmIO::helper::DicomDataWriter::setTagValue< 0x0018, 0x1000 >(deviceSerialNumber, dataset);
}

//------------------------------------------------------------------------------

} // namespace ie
} // namespace writer
} // namespace fwGdcmIO
