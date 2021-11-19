/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/* This file contains the declarations for the Matter OTA Requestor implementation and API.
 * Applications implementing the OTA Requestor functionality must include this file.
 */

#include "ota-requestor-driver.h"
#include "ota-requestor-interface.h"

#pragma once

// This class implements all of the core logic of the OTA Requestor
class OTARequestor : public OTARequestorInterface
{
public:
    // Application interface declarations -- start

    // Application directs the Requestor to start the Image Query process
    // and download the new image if available
    void TriggerImmediateQuery();

    // A setter for the delegate class pointer
    void setOtaRequestorDriver(OTARequestorDriver *driver) { otaRequestorDriver = driver; }

    // Application interface declarations end

    // Virtual functions from OTARequestorInterface start
    // Handler for the AnnounceOTAProvider command
    EmberAfStatus HandleAnnounceOTAProvider(
        chip::app::CommandHandler * commandObj, const chip::app::ConcreteCommandPath & commandPath,
        const chip::app::Clusters::OtaSoftwareUpdateRequestor::Commands::AnnounceOtaProvider::DecodableType & commandData);

    // Virtual functions from OTARequestorInterface -- end
    void ConnectToProvider();

private:

    // Variables
    OTARequestorDriver * otaRequestorDriver;
    chip::NodeId mProviderNodeId;
    chip::FabricIndex mProviderFabricIndex;
    uint32_t mOtaStartDelayMs;
    CASESessionManager * mCASESessionManager = nullptr;

    // Functions
    CHIP_ERROR  SetupCASESessionManager(chip::FabricIndex fabricIndex);

};
