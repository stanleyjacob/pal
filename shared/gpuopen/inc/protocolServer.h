/*
 ***********************************************************************************************************************
 *
 *  Copyright (c) 2019-2021 Advanced Micro Devices, Inc. All Rights Reserved.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 **********************************************************************************************************************/
/**
***********************************************************************************************************************
* @file  protocolServer.h
* @brief Interface declaration for IProtocolServer.
***********************************************************************************************************************
*/

#pragma once

#include "gpuopen.h"
#include "protocolSession.h"

namespace DevDriver
{
    class IMsgChannel;
    class Session;

    class IProtocolServer : public IProtocolSession
    {
    public:
        virtual ~IProtocolServer() {}

        virtual void Finalize() = 0;

        virtual bool GetSupportedVersion(Version minVersion, Version maxVersion, Version *version) const = 0;
        virtual bool AcceptSession(const SharedPointer<ISession>& pSession) = 0;

        virtual void SessionEstablished(const SharedPointer<ISession> &pSession) = 0;
        virtual void UpdateSession(const SharedPointer<ISession> &pSession) = 0;
        virtual void SessionTerminated(const SharedPointer<ISession> &pSession, Result terminationReason) = 0;
    protected:
        IProtocolServer() {}
    };

} // DevDriver
