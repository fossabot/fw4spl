/* ***** BEGIN LICENSE BLOCK *****
 * FW4SPL - Copyright (C) IRCAD, 2015-2017.
 * Distributed under the terms of the GNU Lesser General Public License (LGPL) as
 * published by the Free Software Foundation.
 * ****** END LICENSE BLOCK ****** */

#include "ctrlSelection/updater/SObjFromSlot.hpp"

#include <fwCom/Slot.hxx>
#include <fwCom/Slots.hxx>

#include <fwServices/macros.hpp>

namespace ctrlSelection
{

namespace updater
{

const ::fwCom::Slots::SlotKeyType SObjFromSlot::s_ADD_OR_SWAP_SLOT       = "addOrSwap";
const ::fwCom::Slots::SlotKeyType SObjFromSlot::s_ADD_SLOT               = "add";
const ::fwCom::Slots::SlotKeyType SObjFromSlot::s_SWAP_OBJ_SLOT          = "swapObj";
const ::fwCom::Slots::SlotKeyType SObjFromSlot::s_REMOVE_SLOT            = "remove";
const ::fwCom::Slots::SlotKeyType SObjFromSlot::s_REMOVE_IF_PRESENT_SLOT = "removeIfPresent";

static const std::string s_OBJECT = "object";

//-----------------------------------------------------------------------------

fwServicesRegisterMacro( ::ctrlSelection::IUpdaterSrv, ::ctrlSelection::updater::SObjFromSlot, ::fwData::Composite );

//-----------------------------------------------------------------------------

SObjFromSlot::SObjFromSlot() noexcept
{
    m_slots(s_ADD_OR_SWAP_SLOT, &SObjFromSlot::addOrSwap, this)
        (s_ADD_SLOT, &SObjFromSlot::add, this)
        (s_SWAP_OBJ_SLOT, &SObjFromSlot::swap, this)
        (s_REMOVE_SLOT, &SObjFromSlot::remove, this)
        (s_REMOVE_IF_PRESENT_SLOT, &SObjFromSlot::removeIfPresent, this);

    m_slots.setWorker(m_associatedWorker);
}

//-----------------------------------------------------------------------------

SObjFromSlot::~SObjFromSlot() noexcept
{
}

//-----------------------------------------------------------------------------

void SObjFromSlot::configuring()
{
}

//-----------------------------------------------------------------------------

void SObjFromSlot::starting()
{
}

//-----------------------------------------------------------------------------

void SObjFromSlot::stopping()
{
}

//-----------------------------------------------------------------------------

void SObjFromSlot::updating()
{
}

//-----------------------------------------------------------------------------

void SObjFromSlot::info( std::ostream& _sstream )
{
}

//-----------------------------------------------------------------------------

void SObjFromSlot::add(::fwData::Object::sptr obj)
{
    this->setOutput(s_OBJECT, obj);
}

//-----------------------------------------------------------------------------

void SObjFromSlot::addOrSwap(::fwData::Object::sptr obj)
{
    this->setOutput(s_OBJECT, obj);
}

//-----------------------------------------------------------------------------

void SObjFromSlot::swap(::fwData::Object::sptr obj)
{
    this->setOutput(s_OBJECT, obj);
}

//-----------------------------------------------------------------------------

void SObjFromSlot::remove()
{
    this->setOutput(s_OBJECT, nullptr);
}

//-----------------------------------------------------------------------------

void SObjFromSlot::removeIfPresent()
{
    this->setOutput(s_OBJECT, nullptr);
}

//-----------------------------------------------------------------------------

} // updater
} // ctrlSelection
