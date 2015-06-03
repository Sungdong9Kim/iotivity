//******************************************************************
//
// Copyright 2015 Samsung Electronics All Rights Reserved.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#ifndef RESOURCEBROKER_H_
#define RESOURCEBROKER_H_

#include <functional>
#include <list>
#include <string>
#include <algorithm>
#include <mutex>
#include <condition_variable>

#include "BrokerTypes.h"
#include "DevicePresence.h"

class ResourceBroker
{
public:
    ResourceBroker * getInstance();

    OCStackResult hostResource(PrimitiveResource & pResource, BrokerCB cb);

    OCStackResult cancelHostResource(PrimitiveResource & pResource);

    OCStackResult getResourceState(PrimitiveResource & pResource);

private:
    ResourceBroker();
    ~ResourceBroker();

    static ResourceBroker * s_instance;
    static std::mutex s_mutexForCreation;
    static std::list< DevicePresence * >  s_presenceList;

    ResourcePresence * findResourcePresence(PrimitiveResource& pResource, BrokerCB cb);
    DevicePresence * findDevicePresence(PrimitiveResource& pResource, BrokerCB cb);
};

#endif /* RESOURCEBROKER_H_ */
