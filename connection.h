// Copyright 2010, Shuo Chen.  All rights reserved.
// http://github.com/chenshuo/evcpp
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//

#ifndef EVCPP_CONNECTION_H
#define EVCPP_CONNECTION_H

// this is an internal header file, you should include evcpp.h only.

namespace evcpp
{
class TcpConnection : public std::enable_shared_from_this<TcpConnection>,
                      private noncopyable
{
 public:
  TcpConnection(struct event_base* base, int fd)
    : conn_(::bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE))
  {
  }

  ~TcpConnection()
  {
    ::bufferevent_free(conn_);
  }

 private:
  struct bufferevent* const conn_;
};
}

#endif  // EVCPP_CONNECTION_H


