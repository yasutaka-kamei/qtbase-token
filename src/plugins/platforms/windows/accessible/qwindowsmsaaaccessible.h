begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSMSAAACCESSIBLE_H
end_ifndef
begin_define
DECL|macro|QWINDOWSMSAAACCESSIBLE_H
define|#
directive|define
name|QWINDOWSMSAAACCESSIBLE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QtConfig>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|"../qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qaccessible.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_CC_MINGW
end_ifndef
begin_include
include|#
directive|include
file|<oleacc.h>
end_include
begin_include
include|#
directive|include
file|"Accessible2.h"
end_include
begin_comment
comment|// IAccessible2 inherits from IAccessible
end_comment
begin_else
else|#
directive|else
end_else
begin_comment
comment|// MinGW
end_comment
begin_include
include|#
directive|include
file|<basetyps.h>
end_include
begin_include
include|#
directive|include
file|<oleacc.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG_OUTPUT
argument_list|)
name|bool
name|debug_accessibility
parameter_list|()
function_decl|;
end_function_decl
begin_define
DECL|macro|accessibleDebug
define|#
directive|define
name|accessibleDebug
value|!debug_accessibility() ? (void)0 : qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|accessibleDebug
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_OUTPUT
end_ifndef
begin_define
DECL|macro|DEBUG_SHOW_ATCLIENT_COMMANDS
define|#
directive|define
name|DEBUG_SHOW_ATCLIENT_COMMANDS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_SHOW_ATCLIENT_COMMANDS
argument_list|)
end_if
begin_function_decl
name|void
name|accessibleDebugClientCalls_helper
parameter_list|(
specifier|const
name|char
modifier|*
name|funcName
parameter_list|,
specifier|const
name|QAccessibleInterface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|accessibleDebugClientCalls
define|#
directive|define
name|accessibleDebugClientCalls
parameter_list|(
name|iface
parameter_list|)
value|accessibleDebugClientCalls_helper(Q_FUNC_INFO, iface)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|accessibleDebugClientCalls
define|#
directive|define
name|accessibleDebugClientCalls
parameter_list|(
name|iface
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|QWindow
modifier|*
name|window_helper
parameter_list|(
specifier|const
name|QAccessibleInterface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**************************************************************\  *                     QWindowsAccessible                     *  **************************************************************/
end_comment
begin_decl_stmt
name|class
name|QWindowsMsaaAccessible
range|:
name|public
ifdef|#
directive|ifdef
name|Q_CC_MINGW
DECL|variable|IAccessible
name|IAccessible
else|#
directive|else
name|IAccessible2
endif|#
directive|endif
decl_stmt|,
name|public
name|IOleWindow
block|{
name|public
label|:
name|QWindowsMsaaAccessible
argument_list|(
name|QAccessibleInterface
operator|*
name|a
argument_list|)
operator|:
name|ref
argument_list|(
literal|0
argument_list|)
block|{
name|id
operator|=
name|QAccessible
operator|::
name|uniqueId
argument_list|(
name|a
argument_list|)
block|;     }
name|virtual
operator|~
name|QWindowsMsaaAccessible
argument_list|()
block|{     }
comment|/* IUnknown */
name|HRESULT
name|STDMETHODCALLTYPE
name|QueryInterface
argument_list|(
name|REFIID
argument_list|,
name|LPVOID
operator|*
argument_list|)
expr_stmt|;
name|ULONG
name|STDMETHODCALLTYPE
name|AddRef
parameter_list|()
function_decl|;
name|ULONG
name|STDMETHODCALLTYPE
name|Release
parameter_list|()
function_decl|;
comment|/* IDispatch */
name|HRESULT
name|STDMETHODCALLTYPE
name|GetTypeInfoCount
parameter_list|(
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|GetTypeInfo
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|ITypeInfo
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|GetIDsOfNames
parameter_list|(
specifier|const
name|_GUID
modifier|&
parameter_list|,
name|wchar_t
modifier|*
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|long
modifier|*
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|Invoke
parameter_list|(
name|long
parameter_list|,
specifier|const
name|_GUID
modifier|&
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|short
parameter_list|,
name|tagDISPPARAMS
modifier|*
parameter_list|,
name|tagVARIANT
modifier|*
parameter_list|,
name|tagEXCEPINFO
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
comment|/* IAccessible */
name|HRESULT
name|STDMETHODCALLTYPE
name|accHitTest
parameter_list|(
name|long
name|xLeft
parameter_list|,
name|long
name|yTop
parameter_list|,
name|VARIANT
modifier|*
name|pvarID
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|accLocation
parameter_list|(
name|long
modifier|*
name|pxLeft
parameter_list|,
name|long
modifier|*
name|pyTop
parameter_list|,
name|long
modifier|*
name|pcxWidth
parameter_list|,
name|long
modifier|*
name|pcyHeight
parameter_list|,
name|VARIANT
name|varID
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|accNavigate
parameter_list|(
name|long
name|navDir
parameter_list|,
name|VARIANT
name|varStart
parameter_list|,
name|VARIANT
modifier|*
name|pvarEnd
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accChild
parameter_list|(
name|VARIANT
name|varChildID
parameter_list|,
name|IDispatch
modifier|*
modifier|*
name|ppdispChild
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accChildCount
parameter_list|(
name|long
modifier|*
name|pcountChildren
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accParent
parameter_list|(
name|IDispatch
modifier|*
modifier|*
name|ppdispParent
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|accDoDefaultAction
parameter_list|(
name|VARIANT
name|varID
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accDefaultAction
parameter_list|(
name|VARIANT
name|varID
parameter_list|,
name|BSTR
modifier|*
name|pszDefaultAction
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accDescription
parameter_list|(
name|VARIANT
name|varID
parameter_list|,
name|BSTR
modifier|*
name|pszDescription
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accHelp
parameter_list|(
name|VARIANT
name|varID
parameter_list|,
name|BSTR
modifier|*
name|pszHelp
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accHelpTopic
parameter_list|(
name|BSTR
modifier|*
name|pszHelpFile
parameter_list|,
name|VARIANT
name|varChild
parameter_list|,
name|long
modifier|*
name|pidTopic
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accKeyboardShortcut
parameter_list|(
name|VARIANT
name|varID
parameter_list|,
name|BSTR
modifier|*
name|pszKeyboardShortcut
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accName
parameter_list|(
name|VARIANT
name|varID
parameter_list|,
name|BSTR
modifier|*
name|pszName
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|put_accName
parameter_list|(
name|VARIANT
name|varChild
parameter_list|,
name|BSTR
name|szName
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accRole
parameter_list|(
name|VARIANT
name|varID
parameter_list|,
name|VARIANT
modifier|*
name|pvarRole
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accState
parameter_list|(
name|VARIANT
name|varID
parameter_list|,
name|VARIANT
modifier|*
name|pvarState
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accValue
parameter_list|(
name|VARIANT
name|varID
parameter_list|,
name|BSTR
modifier|*
name|pszValue
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|put_accValue
parameter_list|(
name|VARIANT
name|varChild
parameter_list|,
name|BSTR
name|szValue
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|accSelect
parameter_list|(
name|long
name|flagsSelect
parameter_list|,
name|VARIANT
name|varID
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accFocus
parameter_list|(
name|VARIANT
modifier|*
name|pvarID
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|get_accSelection
parameter_list|(
name|VARIANT
modifier|*
name|pvarChildren
parameter_list|)
function_decl|;
comment|/* IOleWindow */
name|HRESULT
name|STDMETHODCALLTYPE
name|GetWindow
parameter_list|(
name|HWND
modifier|*
name|phwnd
parameter_list|)
function_decl|;
name|HRESULT
name|STDMETHODCALLTYPE
name|ContextSensitiveHelp
parameter_list|(
name|BOOL
name|fEnterMode
parameter_list|)
function_decl|;
name|protected
label|:
name|virtual
name|QByteArray
name|IIDToString
parameter_list|(
name|REFIID
name|id
parameter_list|)
function_decl|;
name|QAccessible
operator|::
name|Id
name|id
expr_stmt|;
name|QAccessibleInterface
operator|*
name|accessibleInterface
argument_list|()
specifier|const
block|{
name|QAccessibleInterface
operator|*
name|iface
operator|=
name|QAccessible
operator|::
name|accessibleInterface
argument_list|(
name|id
argument_list|)
block|;
if|if
condition|(
name|iface
operator|&&
name|iface
operator|->
name|isValid
argument_list|()
condition|)
return|return
name|iface
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt
begin_function
name|QAccessibleInterface
modifier|*
name|childPointer
parameter_list|(
name|VARIANT
name|varID
parameter_list|)
block|{
comment|// -1 since windows API always uses 1 for the first child
name|QAccessibleInterface
modifier|*
name|iface
init|=
name|accessibleInterface
argument_list|()
decl_stmt|;
if|if
condition|(
name|iface
condition|)
return|return
name|accessibleInterface
argument_list|()
operator|->
name|child
argument_list|(
name|varID
operator|.
name|lVal
operator|-
literal|1
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|ULONG
name|ref
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ACCESSIBILITY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSMSAAACCESSIBLE_H
end_comment
end_unit
