/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
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

// THIS FILE IS GENERATED BY ZAP

#include "CHIPClusters.h"

#include <cstdint>

#include <app-common/zap-generated/cluster-objects.h>
#include <app-common/zap-generated/ids/Attributes.h>
#include <app/CommandSender.h>
#include <app/InteractionModelEngine.h>
#include <app/chip-zcl-zpro-codec.h>
#include <app/util/basic-types.h>
#include <controller/CommandSenderAllocator.h>
#include <lib/core/CHIPSafeCasts.h>
#include <lib/support/BufferWriter.h>
#include <lib/support/CHIPMem.h>
#include <lib/support/CodeUtils.h>
#include <lib/support/SafeInt.h>
#include <lib/support/logging/CHIPLogging.h>
#include <system/SystemPacketBuffer.h>
#include <zap-generated/CHIPClientCallbacks.h>

namespace chip {

using namespace app::Clusters;
using namespace System;
using namespace Encoding::LittleEndian;

namespace Controller {

// TODO(#4502): onCompletion is not used by IM for now.
// TODO(#4503): length should be passed to commands when byte string is in argument list.
// TODO(#4503): Commands should take group id as an argument.

// FlowMeasurement Cluster Commands
// FlowMeasurement Cluster Attributes
CHIP_ERROR FlowMeasurementCluster::ReadAttributeMeasuredValue(Callback::Cancelable * onSuccessCallback,
                                                              Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000000;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16sAttributeCallback>);
}

CHIP_ERROR FlowMeasurementCluster::SubscribeAttributeMeasuredValue(Callback::Cancelable * onSuccessCallback,
                                                                   Callback::Cancelable * onFailureCallback, uint16_t minInterval,
                                                                   uint16_t maxInterval)
{
    chip::app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = FlowMeasurement::Attributes::MeasuredValue::Id;
    attributePath.mFlags.Set(chip::app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendSubscribeAttributeRequest(attributePath, minInterval, maxInterval, onSuccessCallback, onFailureCallback);
}

CHIP_ERROR FlowMeasurementCluster::ReportAttributeMeasuredValue(Callback::Cancelable * onReportCallback)
{
    return RequestAttributeReporting(FlowMeasurement::Attributes::MeasuredValue::Id, onReportCallback,
                                     BasicAttributeFilter<Int16sAttributeCallback>);
}

CHIP_ERROR FlowMeasurementCluster::ReadAttributeMinMeasuredValue(Callback::Cancelable * onSuccessCallback,
                                                                 Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000001;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16sAttributeCallback>);
}

CHIP_ERROR FlowMeasurementCluster::ReadAttributeMaxMeasuredValue(Callback::Cancelable * onSuccessCallback,
                                                                 Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000002;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16sAttributeCallback>);
}

CHIP_ERROR FlowMeasurementCluster::ReadAttributeClusterRevision(Callback::Cancelable * onSuccessCallback,
                                                                Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x0000FFFD;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16uAttributeCallback>);
}

// PressureMeasurement Cluster Commands
// PressureMeasurement Cluster Attributes
CHIP_ERROR PressureMeasurementCluster::ReadAttributeMeasuredValue(Callback::Cancelable * onSuccessCallback,
                                                                  Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000000;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16sAttributeCallback>);
}

CHIP_ERROR PressureMeasurementCluster::SubscribeAttributeMeasuredValue(Callback::Cancelable * onSuccessCallback,
                                                                       Callback::Cancelable * onFailureCallback,
                                                                       uint16_t minInterval, uint16_t maxInterval)
{
    chip::app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = PressureMeasurement::Attributes::MeasuredValue::Id;
    attributePath.mFlags.Set(chip::app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendSubscribeAttributeRequest(attributePath, minInterval, maxInterval, onSuccessCallback, onFailureCallback);
}

CHIP_ERROR PressureMeasurementCluster::ReportAttributeMeasuredValue(Callback::Cancelable * onReportCallback)
{
    return RequestAttributeReporting(PressureMeasurement::Attributes::MeasuredValue::Id, onReportCallback,
                                     BasicAttributeFilter<Int16sAttributeCallback>);
}

CHIP_ERROR PressureMeasurementCluster::ReadAttributeMinMeasuredValue(Callback::Cancelable * onSuccessCallback,
                                                                     Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000001;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16sAttributeCallback>);
}

CHIP_ERROR PressureMeasurementCluster::ReadAttributeMaxMeasuredValue(Callback::Cancelable * onSuccessCallback,
                                                                     Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000002;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16sAttributeCallback>);
}

CHIP_ERROR PressureMeasurementCluster::ReadAttributeClusterRevision(Callback::Cancelable * onSuccessCallback,
                                                                    Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x0000FFFD;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16uAttributeCallback>);
}

// TemperatureMeasurement Cluster Commands
// TemperatureMeasurement Cluster Attributes
CHIP_ERROR TemperatureMeasurementCluster::ReadAttributeMeasuredValue(Callback::Cancelable * onSuccessCallback,
                                                                     Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000000;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16sAttributeCallback>);
}

CHIP_ERROR TemperatureMeasurementCluster::SubscribeAttributeMeasuredValue(Callback::Cancelable * onSuccessCallback,
                                                                          Callback::Cancelable * onFailureCallback,
                                                                          uint16_t minInterval, uint16_t maxInterval)
{
    chip::app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = TemperatureMeasurement::Attributes::MeasuredValue::Id;
    attributePath.mFlags.Set(chip::app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendSubscribeAttributeRequest(attributePath, minInterval, maxInterval, onSuccessCallback, onFailureCallback);
}

CHIP_ERROR TemperatureMeasurementCluster::ReportAttributeMeasuredValue(Callback::Cancelable * onReportCallback)
{
    return RequestAttributeReporting(TemperatureMeasurement::Attributes::MeasuredValue::Id, onReportCallback,
                                     BasicAttributeFilter<Int16sAttributeCallback>);
}

CHIP_ERROR TemperatureMeasurementCluster::ReadAttributeMinMeasuredValue(Callback::Cancelable * onSuccessCallback,
                                                                        Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000001;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16sAttributeCallback>);
}

CHIP_ERROR TemperatureMeasurementCluster::ReadAttributeMaxMeasuredValue(Callback::Cancelable * onSuccessCallback,
                                                                        Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x00000002;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16sAttributeCallback>);
}

CHIP_ERROR TemperatureMeasurementCluster::ReadAttributeClusterRevision(Callback::Cancelable * onSuccessCallback,
                                                                       Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x0000FFFD;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16uAttributeCallback>);
}

template <typename RequestDataT, typename ResponseDataT>
CHIP_ERROR ClusterBase::InvokeCommand(const RequestDataT & requestData, void * context,
                                      CommandResponseSuccessCallback<ResponseDataT> successCb,
                                      CommandResponseFailureCallback failureCb)
{
    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);
    ReturnErrorOnFailure(mDevice->LoadSecureSessionParametersIfNeeded());

    auto onSuccessCb = [context, successCb](const app::ConcreteCommandPath & commandPath, const ResponseDataT & responseData) {
        successCb(context, responseData);
    };

    auto onFailureCb = [context, failureCb](Protocols::InteractionModel::Status aIMStatus, CHIP_ERROR aError) {
        failureCb(context, app::ToEmberAfStatus(aIMStatus));
    };

    return InvokeCommandRequest<ResponseDataT>(mDevice->GetExchangeManager(), mDevice->GetSecureSession().Value(), mEndpoint,
                                               requestData, onSuccessCb, onFailureCb);
};

template <typename AttributeInfo>
CHIP_ERROR ClusterBase::WriteAttribute(const typename AttributeInfo::Type & requestData, void * context,
                                       WriteResponseSuccessCallback successCb, WriteResponseFailureCallback failureCb)
{
    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);
    ReturnErrorOnFailure(mDevice->LoadSecureSessionParametersIfNeeded());

    auto onSuccessCb = [context, successCb](const app::ConcreteAttributePath & commandPath) {
        if (successCb != nullptr)
        {
            successCb(context);
        }
    };

    auto onFailureCb = [context, failureCb](const app::ConcreteAttributePath * commandPath, app::StatusIB status,
                                            CHIP_ERROR aError) {
        if (failureCb != nullptr)
        {
            failureCb(context, app::ToEmberAfStatus(status.mStatus));
        }
    };

    return chip::Controller::WriteAttribute<AttributeInfo>(mDevice->GetExchangeManager(), mDevice->GetSecureSession().Value(),
                                                           mEndpoint, requestData, onSuccessCb, onFailureCb);
}

} // namespace Controller
} // namespace chip
