/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This file was generated automatically by Embedded Wizard Studio.
*
* Please do not make any modifications of this file! The modifications are lost
* when the file is generated again by Embedded Wizard Studio!
*
* The template of this heading text can be found in the file 'head.ewt' in the
* directory 'Platforms' of your Embedded Wizard installation directory. If you
* wish to adapt this text, please copy the template file 'head.ewt' into your
* project directory and edit the copy only. Please avoid any modifications of
* the original template file!
*
* Version  : 9.00
* Profile  : STM32F769
* Platform : STM.STM32.RGB565
*
*******************************************************************************/

#ifndef _ApplicationPDCButtonState_H
#define _ApplicationPDCButtonState_H

#ifdef __cplusplus
  extern "C"
  {
#endif

#include "ewrte.h"
#if EW_RTE_VERSION != 0x00090000
  #error Wrong version of Embedded Wizard Runtime Environment.
#endif

#include "ewgfx.h"
#if EW_GFX_VERSION != 0x00090000
  #error Wrong version of Embedded Wizard Graphics Engine.
#endif

/* Forward declaration of the class Application::PDCButtonState */
#ifndef _ApplicationPDCButtonState_
  EW_DECLARE_CLASS( ApplicationPDCButtonState )
#define _ApplicationPDCButtonState_
#endif


/* Deklaration of class : 'Application::PDCButtonState' */
EW_DEFINE_FIELDS( ApplicationPDCButtonState, XObject )
  EW_PROPERTY( Parar,           XBool )
  EW_PROPERTY( Iniciar,         XBool )
EW_END_OF_FIELDS( ApplicationPDCButtonState )

/* Virtual Method Table (VMT) for the class : 'Application::PDCButtonState' */
EW_DEFINE_METHODS( ApplicationPDCButtonState, XObject )
EW_END_OF_METHODS( ApplicationPDCButtonState )

/* 'C' function for method : 'Application::PDCButtonState.OnSetIniciar()' */
void ApplicationPDCButtonState_OnSetIniciar( ApplicationPDCButtonState _this, XBool 
  value );

/* 'C' function for method : 'Application::PDCButtonState.OnSetParar()' */
void ApplicationPDCButtonState_OnSetParar( ApplicationPDCButtonState _this, XBool 
  value );

#ifdef __cplusplus
  }
#endif

#endif /* _ApplicationPDCButtonState_H */

/* Embedded Wizard */
