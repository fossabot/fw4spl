/* ***** BEGIN LICENSE BLOCK *****
 * FW4SPL - Copyright (C) IRCAD, 2009-2010.
 * Distributed under the terms of the GNU Lesser General Public License (LGPL) as
 * published by the Free Software Foundation.
 * ****** END LICENSE BLOCK ****** */


#include "fwGui/IMessageDialog.hpp"

namespace fwGui
{

const IMessageDialog::FactoryRegistryKeyType
IMessageDialog::REGISTRY_KEY =  "an unique key for all IMessageDialog (factories are exclusives)";

IMessageDialog::IMessageDialog()
{}


IMessageDialog::~IMessageDialog()
{}


} // namespace fwGui



