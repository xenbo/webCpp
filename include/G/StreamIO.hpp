//
//  IO.hpp
//  GHTTPd
//
//  Created by JamesWatson on 16/4/13.
//  Copyright © 2016年 watsserve. All rights reserved.
//

#ifndef _G_IO_HPP_
#define _G_IO_HPP_

#include <string>
extern "C" {
    #include "aio.h"
}
#include "G/IOHandle.hpp"
#include "G/IOEvents.hpp"
#include "G/Input.hpp"
#include "G/Output.hpp"

namespace G {

    class IOEvents;

    class StreamIO : public Input, public Output, public IOHandle
    {
        std::string cache;
        int closed;
    protected:
        IOEvents *ioEvents;
        size_t len;
    public:
        static StreamIO* init(StreamIO *ioHandle, G::IOEvents *ioEvents, void* mem, size_t memLen);
        StreamIO();
        virtual ~StreamIO() {};

        virtual void setFd(int, HandleType);
        virtual int getFd();
        virtual void close();

        virtual void recvd();
        virtual void sent();
        virtual std::string gets();

        virtual void write(const char *, ssize_t, OutBack callback);
        virtual void write(std::string &, OutBack callback);
        virtual void sendfile(std::string &, OutBack callback);
    };

}

#endif /* _G_IO_HPP_ */
