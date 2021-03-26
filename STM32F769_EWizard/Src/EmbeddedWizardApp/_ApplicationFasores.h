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

#ifndef _ApplicationFasores_H
#define _ApplicationFasores_H

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

#include "_CoreGroup.h"
#include "_CoreTimer.h"
#include "_ViewsImage.h"
#include "_ViewsLine.h"
#include "_ViewsText.h"
#include "_ViewsWarpImage.h"

/* Forward declaration of the class Application::Classe */
#ifndef _ApplicationClasse_
  EW_DECLARE_CLASS( ApplicationClasse )
#define _ApplicationClasse_
#endif

/* Forward declaration of the class Application::Fasores */
#ifndef _ApplicationFasores_
  EW_DECLARE_CLASS( ApplicationFasores )
#define _ApplicationFasores_
#endif

/* Forward declaration of the class Core::DialogContext */
#ifndef _CoreDialogContext_
  EW_DECLARE_CLASS( CoreDialogContext )
#define _CoreDialogContext_
#endif

/* Forward declaration of the class Core::KeyPressHandler */
#ifndef _CoreKeyPressHandler_
  EW_DECLARE_CLASS( CoreKeyPressHandler )
#define _CoreKeyPressHandler_
#endif

/* Forward declaration of the class Core::LayoutContext */
#ifndef _CoreLayoutContext_
  EW_DECLARE_CLASS( CoreLayoutContext )
#define _CoreLayoutContext_
#endif

/* Forward declaration of the class Core::TaskQueue */
#ifndef _CoreTaskQueue_
  EW_DECLARE_CLASS( CoreTaskQueue )
#define _CoreTaskQueue_
#endif

/* Forward declaration of the class Core::View */
#ifndef _CoreView_
  EW_DECLARE_CLASS( CoreView )
#define _CoreView_
#endif

/* Forward declaration of the class Graphics::Canvas */
#ifndef _GraphicsCanvas_
  EW_DECLARE_CLASS( GraphicsCanvas )
#define _GraphicsCanvas_
#endif


/* Deklaration of class : 'Application::Fasores' */
EW_DEFINE_FIELDS( ApplicationFasores, CoreGroup )
  EW_VTHISPTR()
  EW_VARIABLE( angulo,          XFloat )
  EW_VARIABLE( amplitude,       XFloat )
  EW_VARIABLE( centro,          XPoint )
  EW_OBJECT  ( grid,            ViewsImage )
  EW_OBJECT  ( label0,          ViewsText )
  EW_OBJECT  ( label180,        ViewsText )
  EW_OBJECT  ( label90,         ViewsText )
  EW_OBJECT  ( label270,        ViewsText )
  EW_OBJECT  ( label300,        ViewsText )
  EW_OBJECT  ( label240,        ViewsText )
  EW_OBJECT  ( label210,        ViewsText )
  EW_OBJECT  ( label120,        ViewsText )
  EW_OBJECT  ( label60,         ViewsText )
  EW_OBJECT  ( label330,        ViewsText )
  EW_OBJECT  ( label30,         ViewsText )
  EW_OBJECT  ( label150,        ViewsText )
  EW_OBJECT  ( labelMag,        ViewsText )
  EW_OBJECT  ( labelAng,        ViewsText )
  EW_OBJECT  ( fTverm_mag,      ViewsText )
  EW_OBJECT  ( fTverm_ang,      ViewsText )
  EW_OBJECT  ( fSamarelo_mag,   ViewsText )
  EW_OBJECT  ( fSamarelo_ang,   ViewsText )
  EW_OBJECT  ( fRverde_mag,     ViewsText )
  EW_OBJECT  ( fRverde_ang,     ViewsText )
  EW_OBJECT  ( Line,            ViewsLine )
  EW_OBJECT  ( Timer,           CoreTimer )
  EW_OBJECT  ( fasor_T,         ViewsWarpImage )
  EW_OBJECT  ( fasor_S,         ViewsWarpImage )
  EW_OBJECT  ( fasor_R,         ViewsWarpImage )
  EW_VARIABLE( device,          ApplicationClasse )
EW_END_OF_FIELDS( ApplicationFasores )

/* Virtual Method Table (VMT) for the class : 'Application::Fasores' */
EW_DEFINE_METHODS( ApplicationFasores, CoreGroup )
  EW_METHOD( initLayoutContext, void )( CoreRectView _this, XRect aBounds, CoreOutline 
    aOutline )
  EW_METHOD( GetRoot,           CoreRoot )( CoreView _this )
  EW_METHOD( Draw,              void )( CoreGroup _this, GraphicsCanvas aCanvas, 
    XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
  EW_METHOD( HandleEvent,       XObject )( CoreView _this, CoreEvent aEvent )
  EW_METHOD( CursorHitTest,     CoreCursorHit )( CoreGroup _this, XRect aArea, XInt32 
    aFinger, XInt32 aStrikeCount, CoreView aDedicatedView, XSet aRetargetReason )
  EW_METHOD( ArrangeView,       XPoint )( CoreRectView _this, XRect aBounds, XEnum 
    aFormation )
  EW_METHOD( MoveView,          void )( CoreRectView _this, XPoint aOffset, XBool 
    aFastMove )
  EW_METHOD( GetExtent,         XRect )( CoreRectView _this )
  EW_METHOD( ChangeViewState,   void )( CoreGroup _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( CoreGroup _this, XRect value )
  EW_METHOD( OnSetFocus,        void )( CoreGroup _this, CoreView value )
  EW_METHOD( OnSetOpacity,      void )( CoreGroup _this, XInt32 value )
  EW_METHOD( DispatchEvent,     XObject )( CoreGroup _this, CoreEvent aEvent )
  EW_METHOD( BroadcastEvent,    XObject )( CoreGroup _this, CoreEvent aEvent, XSet 
    aFilter )
  EW_METHOD( UpdateLayout,      void )( ApplicationFasores _this, XPoint aSize )
  EW_METHOD( UpdateViewState,   void )( ApplicationFasores _this, XSet aState )
  EW_METHOD( InvalidateArea,    void )( CoreGroup _this, XRect aArea )
  EW_METHOD( Restack,           void )( CoreGroup _this, CoreView aView, XInt32 
    aOrder )
  EW_METHOD( Add,               void )( CoreGroup _this, CoreView aView, XInt32 
    aOrder )
EW_END_OF_METHODS( ApplicationFasores )

/* Variant Dispatch Method Table for the class : 'Application::Fasores' */
EW_DEFINE_DISPATCHER( ApplicationFasores, CoreGroup )
EW_END_OF_DISPATCHER( ApplicationFasores )

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void ApplicationFasores_UpdateLayout( ApplicationFasores _this, XPoint aSize );

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void ApplicationFasores_UpdateViewState( ApplicationFasores _this, XSet aState );

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationFasores_Init( ApplicationFasores _this, XHandle aArg );

/* 'C' function for method : 'Application::Fasores.roda()' */
void ApplicationFasores_roda( ApplicationFasores _this, XObject sender );

/* 'C' function for method : 'Application::Fasores.float2String()' */
XString ApplicationFasores_float2String( ApplicationFasores _this, XFloat arg1 );

#ifdef __cplusplus
  }
#endif

#endif /* _ApplicationFasores_H */

/* Embedded Wizard */
