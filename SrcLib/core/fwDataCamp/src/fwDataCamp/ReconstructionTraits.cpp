#include "fwDataCamp/Factory.hpp"
#include "fwDataCamp/ReconstructionTraits.hpp"

fwCampImplementDataMacro((fwData)(ReconstructionTraits))
{
    builder
        .tag("object_version", "1")
        .tag("lib_name", "fwData")
        .base< ::fwData::Object>()
        .property("name", &::fwData::ReconstructionTraits::m_identifier)
        .property("mesh_node", &::fwData::ReconstructionTraits::m_meshOpNode)
        .property("mask_node", &::fwData::ReconstructionTraits::m_maskOpNode)
        .property("traits", &::fwData::ReconstructionTraits::m_structureTraits)
        ;
}