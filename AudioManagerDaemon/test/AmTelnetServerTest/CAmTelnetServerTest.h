/**
 * Copyright (C) 2012, BMW AG
 *
 * This file is part of GENIVI Project AudioManager.
 *
 * Contributions are licensed to the GENIVI Alliance under one or more
 * Contribution License Agreements.
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 *
 * \author Christian Linke, christian.linke@bmw.de BMW 2011,2012
 * \author Frank Herchet, frank.fh.herchet@bmw.de BMW 2012
 *
 * For further information see http://www.genivi.org/.
 *
 */

#ifndef CAMTELNETSERVERTEST_H_
#define CAMTELNETSERVERTEST_H_

#include "gtest/gtest.h"
#include "CAmTelnetServer.h"
#include "CAmRoutingSender.h"
#include "CAmCommandSender.h"
#include "CAmControlSender.h"
#include "CAmRouter.h"
#include "config.h"
#include "CAmDatabaseHandlerMap.h"





namespace am
{

class CAmSocketHandler;
class CAmRoutingSender;
class CAmCommandSender;
class CAmControlSender;
class CAmRouter;
class CAmCommandReceiver;
class CAmRoutingReceiver;
class CAmControlReceiver;
class CAmTelnetServer;


class CAmEnvironment : public ::testing::Environment
{
 public:
  CAmEnvironment();

  ~CAmEnvironment();
  // Override this to define how to set up the environment.
  void SetUp();
  // Override this to define how to tear down the environment.
  void TearDown();

  void setSocketHandler(CAmSocketHandler* pSocketHandler);

  void stopSocketHandler();

  std::vector<std::string> mlistRoutingPluginDirs;
  std::vector<std::string> mlistCommandPluginDirs;

  CAmSocketHandler     mSocketHandler;
  CAmDatabaseHandlerMap		 mDatabasehandler;
  CAmRoutingSender     mRoutingSender;
  CAmCommandSender     mCommandSender;
  CAmControlSender     mControlSender;
  CAmRouter            mRouter;

  CAmCommandReceiver*  mpCommandReceiver;
  CAmRoutingReceiver*  mpRoutingReceiver;
  CAmControlReceiver*  mpControlReceiver;

  CAmTelnetServer*     mpTelnetServer;

  pthread_t         mSocketHandlerThread;
};

class CAmTelnetServerTest : public ::testing::Test
{
   public:
      CAmTelnetServerTest();
      ~CAmTelnetServerTest();


   void SetUp() ;

   void TearDown() ;
   void sendCmd(std::string & command );
   //int              mSocket;
};

}




#endif /* CAMTELNETSERVERTEST_H_ */
