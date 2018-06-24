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

#ifndef _ApplicationPlotterTripleGraph_H
#define _ApplicationPlotterTripleGraph_H

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
#include "_GraphicsPath.h"
#include "_ViewsBorder.h"
#include "_ViewsLine.h"
#include "_ViewsStrokePath.h"

/* Forward declaration of the class Application::PlotterTripleGraph */
#ifndef _ApplicationPlotterTripleGraph_
  EW_DECLARE_CLASS( ApplicationPlotterTripleGraph )
#define _ApplicationPlotterTripleGraph_
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


/* Deklaration of class : 'Application::PlotterTripleGraph' */
EW_DEFINE_FIELDS( ApplicationPlotterTripleGraph, CoreGroup )
  EW_VTHISPTR()
  EW_OBJECT  ( VLine3,          ViewsLine )
  EW_OBJECT  ( VLine2,          ViewsLine )
  EW_OBJECT  ( VLine1,          ViewsLine )
  EW_OBJECT  ( HLine1,          ViewsLine )
  EW_OBJECT  ( HLine2,          ViewsLine )
  EW_OBJECT  ( HLine3,          ViewsLine )
  EW_OBJECT  ( HLine4,          ViewsLine )
  EW_OBJECT  ( HLine5,          ViewsLine )
  EW_OBJECT  ( Border,          ViewsBorder )
  EW_PROPERTY( VerticalRatio,   XFloat )
  EW_PROPERTY( StrokeColorR,    XColor )
  EW_PROPERTY( StrokeWidth,     XFloat )
  EW_PROPERTY( StrokeColorS,    XColor )
  EW_PROPERTY( StrokeColorT,    XColor )
  EW_OBJECT  ( PlotterPathR,    ViewsStrokePath )
  EW_OBJECT  ( PathDataR,       GraphicsPath )
  EW_OBJECT  ( PlotterPathS,    ViewsStrokePath )
  EW_OBJECT  ( PathDataS,       GraphicsPath )
  EW_OBJECT  ( PlotterPathT,    ViewsStrokePath )
  EW_OBJECT  ( PathDataT,       GraphicsPath )
EW_END_OF_FIELDS( ApplicationPlotterTripleGraph )

/* Virtual Method Table (VMT) for the class : 'Application::PlotterTripleGraph' */
EW_DEFINE_METHODS( ApplicationPlotterTripleGraph, CoreGroup )
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
  EW_METHOD( UpdateLayout,      void )( ApplicationPlotterTripleGraph _this, XPoint 
    aSize )
  EW_METHOD( UpdateViewState,   void )( ApplicationPlotterTripleGraph _this, XSet 
    aState )
  EW_METHOD( InvalidateArea,    void )( CoreGroup _this, XRect aArea )
  EW_METHOD( Restack,           void )( CoreGroup _this, CoreView aView, XInt32 
    aOrder )
  EW_METHOD( Add,               void )( CoreGroup _this, CoreView aView, XInt32 
    aOrder )
EW_END_OF_METHODS( ApplicationPlotterTripleGraph )

/* Variant Dispatch Method Table for the class : 'Application::PlotterTripleGraph' */
EW_DEFINE_DISPATCHER( ApplicationPlotterTripleGraph, CoreGroup )
  EW_METHOD( AddData,           void )( ApplicationPlotterTripleGraph _this, XFloat 
    dataPointR, XFloat dataPointS, XFloat dataPointT )
  EW_METHOD( OnSetVerticalRatio, void )( ApplicationPlotterTripleGraph _this, XFloat 
    value )
EW_END_OF_DISPATCHER( ApplicationPlotterTripleGraph )

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void ApplicationPlotterTripleGraph_UpdateLayout( ApplicationPlotterTripleGraph _this, 
  XPoint aSize );

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
void ApplicationPlotterTripleGraph_UpdateViewState( ApplicationPlotterTripleGraph _this, 
  XSet aState );

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationPlotterTripleGraph_Init( ApplicationPlotterTripleGraph _this, XHandle 
  aArg );

/* 'C' function for method : 'Application::PlotterTripleGraph.AddData()'
   Please note, this function serves as the dispatcher to the methods overriden 
   in the derived class variants. */
void ApplicationPlotterTripleGraph_AddData( ApplicationPlotterTripleGraph _this, 
  XFloat dataPointR, XFloat dataPointS, XFloat dataPointT );

/* Implementation of the method : 'Application::PlotterTripleGraph.AddData()'. The 
   implementation has been moved here, because the origin function ApplicationPlotterTripleGraph_AddData() 
   does serve as the dispatcher to the derived class variants only. */
void ApplicationPlotterTripleGraph___AddData( ApplicationPlotterTripleGraph _this, 
  XFloat dataPointR, XFloat dataPointS, XFloat dataPointT );

/* 'C' function for method : 'Application::PlotterTripleGraph.OnSetVerticalRatio()'
   Please note, this function serves as the dispatcher to the methods overriden 
   in the derived class variants. */
void ApplicationPlotterTripleGraph_OnSetVerticalRatio( ApplicationPlotterTripleGraph _this, 
  XFloat value );

/* Implementation of the method : 'Application::PlotterTripleGraph.OnSetVerticalRatio()'. 
   The implementation has been moved here, because the origin function ApplicationPlotterTripleGraph_OnSetVerticalRatio() 
   does serve as the dispatcher to the derived class variants only. */
void ApplicationPlotterTripleGraph___OnSetVerticalRatio( ApplicationPlotterTripleGraph _this, 
  XFloat value );

/* 'C' function for method : 'Application::PlotterTripleGraph.OnSetStrokeColorR()' */
void ApplicationPlotterTripleGraph_OnSetStrokeColorR( ApplicationPlotterTripleGraph _this, 
  XColor value );

/* 'C' function for method : 'Application::PlotterTripleGraph.OnSetStrokeWidth()' */
void ApplicationPlotterTripleGraph_OnSetStrokeWidth( ApplicationPlotterTripleGraph _this, 
  XFloat value );

/* 'C' function for method : 'Application::PlotterTripleGraph.OnSetStrokeColorS()' */
void ApplicationPlotterTripleGraph_OnSetStrokeColorS( ApplicationPlotterTripleGraph _this, 
  XColor value );

/* 'C' function for method : 'Application::PlotterTripleGraph.OnSetStrokeColorT()' */
void ApplicationPlotterTripleGraph_OnSetStrokeColorT( ApplicationPlotterTripleGraph _this, 
  XColor value );

/* 'C' function for method : 'Application::PlotterTripleGraph.ClearPath()' */
void ApplicationPlotterTripleGraph_ClearPath( ApplicationPlotterTripleGraph _this );

#ifdef __cplusplus
  }
#endif

#endif /* _ApplicationPlotterTripleGraph_H */

/* Embedded Wizard */
