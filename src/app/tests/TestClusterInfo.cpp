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

/**
 *    @file
 *      This file implements unit tests for CommandPathParams
 *
 */

#include <app/ClusterInfo.h>
#include <app/util/mock/Constants.h>
#include <lib/support/UnitTestRegistration.h>
#include <nlunit-test.h>

using namespace chip::Test;

namespace chip {
namespace app {
namespace TestClusterInfo {
void TestAttributePathIncludedSameFieldId(nlTestSuite * apSuite, void * apContext)
{
    ClusterInfo clusterInfo1;
    ClusterInfo clusterInfo2;
    ClusterInfo clusterInfo3;
    clusterInfo1.mAttributeId = 1;
    clusterInfo2.mAttributeId = 1;
    clusterInfo3.mAttributeId = 1;
    NL_TEST_ASSERT(apSuite, clusterInfo1.IsAttributePathSupersetOf(clusterInfo2));
    clusterInfo2.mListIndex = 1;
    NL_TEST_ASSERT(apSuite, clusterInfo1.IsAttributePathSupersetOf(clusterInfo2));
    clusterInfo1.mListIndex = 0;
    NL_TEST_ASSERT(apSuite, !clusterInfo1.IsAttributePathSupersetOf(clusterInfo3));
    clusterInfo3.mListIndex = 0;
    NL_TEST_ASSERT(apSuite, clusterInfo1.IsAttributePathSupersetOf(clusterInfo3));
    clusterInfo3.mListIndex = 1;
    NL_TEST_ASSERT(apSuite, !clusterInfo1.IsAttributePathSupersetOf(clusterInfo3));
}

void TestAttributePathIncludedDifferentFieldId(nlTestSuite * apSuite, void * apContext)
{
    {
        ClusterInfo clusterInfo1;
        ClusterInfo clusterInfo2;
        clusterInfo1.mAttributeId = 1;
        clusterInfo2.mAttributeId = 2;
        NL_TEST_ASSERT(apSuite, !clusterInfo1.IsAttributePathSupersetOf(clusterInfo2));
    }
    {
        ClusterInfo clusterInfo1;
        ClusterInfo clusterInfo2;
        clusterInfo2.mAttributeId = 2;
        NL_TEST_ASSERT(apSuite, clusterInfo1.IsAttributePathSupersetOf(clusterInfo2));
    }
    {
        ClusterInfo clusterInfo1;
        ClusterInfo clusterInfo2;
        NL_TEST_ASSERT(apSuite, clusterInfo1.IsAttributePathSupersetOf(clusterInfo2));
    }
    {
        ClusterInfo clusterInfo1;
        ClusterInfo clusterInfo2;

        clusterInfo1.mAttributeId = 1;
        NL_TEST_ASSERT(apSuite, !clusterInfo1.IsAttributePathSupersetOf(clusterInfo2));
    }
}

void TestAttributePathIncludedDifferentEndpointId(nlTestSuite * apSuite, void * apContext)
{
    ClusterInfo clusterInfo1;
    ClusterInfo clusterInfo2;
    clusterInfo1.mEndpointId = 1;
    clusterInfo2.mEndpointId = 2;
    NL_TEST_ASSERT(apSuite, !clusterInfo1.IsAttributePathSupersetOf(clusterInfo2));
}

void TestAttributePathIncludedDifferentClusterId(nlTestSuite * apSuite, void * apContext)
{
    ClusterInfo clusterInfo1;
    ClusterInfo clusterInfo2;
    clusterInfo1.mClusterId = 1;
    clusterInfo2.mClusterId = 2;
    NL_TEST_ASSERT(apSuite, !clusterInfo1.IsAttributePathSupersetOf(clusterInfo2));
}

/*
{ClusterInfo::kInvalidEndpointId, ClusterInfo::kInvalidClusterId, ClusterInfo::kInvalidEventId},
{ClusterInfo::kInvalidEndpointId, MockClusterId(1), ClusterInfo::kInvalidEventId},
{ClusterInfo::kInvalidEndpointId, MockClusterId(1), MockEventId(1)},
{kMockEndpoint1, ClusterInfo::kInvalidClusterId, ClusterInfo::kInvalidEventId},
{kMockEndpoint1, MockClusterId(1), ClusterInfo::kInvalidEventId},
{kMockEndpoint1, MockClusterId(1), MockEventId(1)},
*/
chip::app::ClusterInfo validEventpaths[6];
void InitEventPaths()
{
    validEventpaths[1].mClusterId  = MockClusterId(1);
    validEventpaths[2].mClusterId  = MockClusterId(1);
    validEventpaths[2].mEventId    = MockEventId(1);
    validEventpaths[3].mEndpointId = kMockEndpoint1;
    validEventpaths[4].mEndpointId = kMockEndpoint1;
    validEventpaths[4].mClusterId  = MockClusterId(1);
    validEventpaths[5].mEndpointId = kMockEndpoint1;
    validEventpaths[5].mClusterId  = MockClusterId(1);
    validEventpaths[5].mEventId    = MockEventId(1);
}

void TestEventPathSameEventId(nlTestSuite * apSuite, void * apContext)
{
    ConcreteEventPath testPath(kMockEndpoint1, MockClusterId(1), MockEventId(1));
    for (auto & path : validEventpaths)
    {
        NL_TEST_ASSERT(apSuite, path.IsValidEventPath());
        NL_TEST_ASSERT(apSuite, path.IsEventPathSupersetOf(testPath));
    }
}

void TestEventPathDifferentEventId(nlTestSuite * apSuite, void * apContext)
{
    ConcreteEventPath testPath(kMockEndpoint1, MockClusterId(1), MockEventId(2));
    NL_TEST_ASSERT(apSuite, validEventpaths[0].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, validEventpaths[1].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, !validEventpaths[2].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, validEventpaths[3].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, validEventpaths[4].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, !validEventpaths[5].IsEventPathSupersetOf(testPath));
}

void TestEventPathDifferentClusterId(nlTestSuite * apSuite, void * apContext)
{
    ConcreteEventPath testPath(kMockEndpoint1, MockClusterId(2), MockEventId(1));
    NL_TEST_ASSERT(apSuite, validEventpaths[0].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, !validEventpaths[1].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, !validEventpaths[2].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, validEventpaths[3].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, !validEventpaths[4].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, !validEventpaths[5].IsEventPathSupersetOf(testPath));
}

void TestEventPathDifferentEndpointId(nlTestSuite * apSuite, void * apContext)
{
    ConcreteEventPath testPath(kMockEndpoint2, MockClusterId(1), MockEventId(1));
    NL_TEST_ASSERT(apSuite, validEventpaths[0].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, validEventpaths[1].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, validEventpaths[2].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, !validEventpaths[3].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, !validEventpaths[4].IsEventPathSupersetOf(testPath));
    NL_TEST_ASSERT(apSuite, !validEventpaths[5].IsEventPathSupersetOf(testPath));
}

} // namespace TestClusterInfo
} // namespace app
} // namespace chip

namespace {
const nlTest sTests[] = {
    NL_TEST_DEF("TestAttributePathIncludedSameFieldId", chip::app::TestClusterInfo::TestAttributePathIncludedSameFieldId),
    NL_TEST_DEF("TestAttributePathIncludedDifferentFieldId", chip::app::TestClusterInfo::TestAttributePathIncludedDifferentFieldId),
    NL_TEST_DEF("TestAttributePathIncludedDifferentEndpointId",
                chip::app::TestClusterInfo::TestAttributePathIncludedDifferentEndpointId),
    NL_TEST_DEF("TestAttributePathIncludedDifferentClusterId",
                chip::app::TestClusterInfo::TestAttributePathIncludedDifferentClusterId),
    NL_TEST_DEF("TestEventPathSameEventId", chip::app::TestClusterInfo::TestEventPathSameEventId),
    NL_TEST_DEF("TestEventPathDifferentEventId", chip::app::TestClusterInfo::TestEventPathDifferentEventId),
    NL_TEST_DEF("TestEventPathDifferentClusterId", chip::app::TestClusterInfo::TestEventPathDifferentClusterId),
    NL_TEST_DEF("TestEventPathDifferentEndpointId", chip::app::TestClusterInfo::TestEventPathDifferentEndpointId),
    NL_TEST_SENTINEL()
};
}

int TestClusterInfo()
{
    nlTestSuite theSuite = { "ClusterInfo", &sTests[0], nullptr, nullptr };
    chip::app::TestClusterInfo::InitEventPaths();
    nlTestRunner(&theSuite, nullptr);

    return (nlTestRunnerStats(&theSuite));
}

CHIP_REGISTER_TEST_SUITE(TestClusterInfo)
