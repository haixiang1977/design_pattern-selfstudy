/*****************************************************************************
*                                                                            *
*                     SOFTING Industrial Automation GmbH                     *
*                          Richard-Reitzner-Allee 6                          *
*                                D-85540 Haar                                *
*                        Phone: ++49-89-4 56 56-0                            *
*                          Fax: ++49-89-4 56 56-3 99                         *
*                                                                            *
*                            SOFTING CONFIDENTIAL                            *
*                                                                            *
*                     Copyright (C) SOFTING IA GmbH 2016                     *
*                             All Rights Reserved                            *
*                                                                            *
* NOTICE: All information contained herein is, and remains the property of   *
*   SOFTING Industrial Automation GmbH and its suppliers, if any. The intel- *
*   lectual and technical concepts contained herein are proprietary to       *
*   SOFTING Industrial Automation GmbH and its suppliers and may be covered  *
*   by German and Foreign Patents, patents in process, and are protected by  *
*   trade secret or copyright law. Dissemination of this information or      *
*   reproduction of this material is strictly forbidden unless prior         *
*   written permission is obtained from SOFTING Industrial Automation GmbH.  *
******************************************************************************
******************************************************************************
*                                                                            *
* PROJECT_NAME             OPC UA C++ Toolkit                                *
*                                                                            *
* VERSION                  5.52.0                                            *
*                                                                            *
* DATE                     26.09.2016                                        *
*                                                                            *
*****************************************************************************/

#ifndef SERVERFINITESTATEMACHINE_H
#define SERVERFINITESTATEMACHINE_H
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerStateMachine.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class FiniteStateVariable;
		class FiniteTransitionVariable;
		class State;
	}

	namespace Server
	{
		/*! The FiniteStateMachine is the base class for state machines that explicitly define the
		* possible states and transitions in the address space of a server. */
		class TBC_EXPORT FiniteStateMachine
			: public StateMachine
		{
		public:
			/*! Constructs a new FiniteStateMachine instance */
			static ObjectPointer<FiniteStateMachine> create();

			/*! @deprecated		Please use FiniteStateMachine::create() to construct an instance of this type.
			*					This constructor will be made 'protected' in future versions of this product.
			*
			* Default constructor */
			FiniteStateMachine();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			FiniteStateMachine(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			FiniteStateMachine(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~FiniteStateMachine();

			/*! Changes the state of this state machine. This method updates the CurrentState and LastTransition properties
			* to reflect the changed state. */
			EnumStatusCode changeState(Server::State* target);

			/*! Returns the "CurrentState" property that holds the current state
			* of the state machine.
			*
			* @note Please use changeState() use change the current state of the state machine. */
			ObjectPointer<Server::FiniteStateVariable> getCurrentStateVar();
			/*! @overload */
			ObjectPointer<const Server::FiniteStateVariable> getCurrentStateVar() const;

			/*! Returns the localized text that describes the current state.
			*
			* @note	Please use FiniteStateVariable::getId() to retrieve the current
			*		state (see getCurrentStateVar()). */
			LocalizedText getCurrentState() const;
			/*! @deprecated Do not call this method, use FiniteStateMachine::changeState() instead. */
			DEPRECATED(virtual EnumStatusCode setCurrentState(const ILocalizedText* currentState));
			/*! @overload */
			DEPRECATED(virtual EnumStatusCode setCurrentState(const ILocalizedText& currentState));

			/*! Returns the "LastTransition" property that stores the last transition
			* that occurred in the state machine. */
			ObjectPointer<Server::FiniteTransitionVariable> getLastTransitionVar();
			/*! @overload */
			ObjectPointer<const Server::FiniteTransitionVariable> getLastTransitionVar() const;

			/*! Returns the localized text that describes the last transition that
			* occurred in the state machine.
			*
			* @note	Please use FiniteTransitionVariable::getId() to retrieve a unique
			*		identifier for the last transition. */
			LocalizedText getLastTransition() const;
			/*! @deprecated Do not call this method, use FiniteStateMachine::changeState() instead. */
			DEPRECATED(virtual EnumStatusCode setLastTransition(const ILocalizedText* lastTransition));
			/*! @overload */
			DEPRECATED(virtual EnumStatusCode setLastTransition(const ILocalizedText& lastTransition));

		private:
			/*! Forbid use assignment operator */
			FiniteStateMachine& operator=(const FiniteStateMachine&);
			/*! Forbid use of copy constructor */
			FiniteStateMachine(const FiniteStateMachine&);
		};
		typedef ObjectPointer<FiniteStateMachine> FiniteStateMachinePtr;
		typedef ObjectPointer<const FiniteStateMachine> FiniteStateMachineConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERFINITESTATEMACHINE_H
